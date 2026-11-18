# C-Calculator task

## Assignment

5 separate programs:

- calc
- add
- sub
- mul
- negate

all apps shown above are child of the calc app process

## What to know

1. program vs process
2. relation between parent and child processes
3. man command
4. create a child process using `fork`
5. replace a child process with another program using exec-functions
6. make a parent wait for a child process to exit
7. retrieve child exit status
8. pass command-line-args
9. how multiple independent programs cooperate to finish a task
10. don't do  تجود من عندك

## Prerequisites

- C
- Functions and argc & argv
- Linux basics
- Basics of processes
- fork, exec adn waitpid

---

## The Explanation

let's start by the basic parts, how do we read the input, the input has a fixed structure:

```text
calc> <command> <arg1> <arg2>
```

we we can read it as a single string, then we basically parse it into 3 different pieces using a special variant of `scanf`, `sscanf`, this variants just like `scanf` takes a formatted string, that is your template, but instead of reading from `stdin` it reads them from a string, so:

```c
// reading input from user
char line[100]; //the line entered
char command[7] = {0}; //the command part
int arg1 = 0, arg2 = 0; // arg1 and arg2 parts

fgets(line, sizeof(line), stdin); //reads a line directly from stdin
sscanf(line, "%6s %d %d", command, &arg1, &arg2); // splits the string and converts
```

didn't use `scanf` because it will not stop scanning till all required options are provided, which is not ideal since `negate` requires only **ONE** argument

now to the juicy sections, the core of the task:

### fork()

`fork` is part of `unistd.h`, it basically copies the current working process into a child of its own, basically a new copy of this app, but its a child of the original process.

the parent -original process- gets the `pid` of the child, the child however when it reads the return of `fork` it gets `0` so it knows it's the child, so check for the return of `fork` if it's zero this is the child process, if it's `< 0` the fork failed, if it's `> 0` then it's the pid of the child process.

now when `pid` is `0`, this is the child process, we can replace what it does by using `exec` functions, these functions do the same thing, with varying arguments for your needs:

- l -> takes `n` number of string args, separated by `,` and engin with `null`
- v -> takes an array of string args, ending in `NULL` as well
- p -> first argument is a string path to the target executable

> [!TIP] the first argument of a C-app (arg0) is its own name

```c
// p -> path to executable, l -> takes arguments directly and doesn't need an array
execlp("./.build/sub", "sub", arg1_str, arg2_str, NULL);
//arg0 -> sub, arg1 arg1_str (argument 1 turned into a string), arg2 arg2_str (argument 2 turned into a string)
```

yes i could have just kept both numbers a string but its too late to do anything :)

lastly we have to wait, for that we use `waitpid`, it's a variant of `wait` but it differs slightly

|wait(int* status)  |waitpid(pid_t pid, int* status, int option)  |
|:---------:|:---------:|
|waits for any child process  |  waits for a specific child/group process, group or any child process like `wait`|
|always blocks     |  can block, and can be made not to       |
|not flexible     |      very flexible   |

- `pid` controls what process to wait for:
  - `> 0` waits for a specific process
  - `0` wait for any child of the same group as the caller
  - `-1` wait for any child
- `status` info about the exit of the child, don't read as regular int, use macros like:
  - WIFEXITED(status) returns non-zero (true) if child exited properly
  - WIFSIGNALED(status) returns non-zero (true) if child was killed by an un-handled signal like segmentation fault
- `option` they can be combined using `|`
  - `WNOHANG` no freezing
  - `WUNTRACED` returns if child was paused or terminated
  
---

## Sub-commands readings

ok, how does a sub command read the data, simple use `argc` and `argv`.

the `main` function can take these two, `argc` is an int, holds how many arguments were passed to this app, `argv` is an array of strings, holding the options passed to the app, `argv[0]` is `arg0` which is almost alway the program name, so your own arguments start at index `1` if you pass any.
a
this is easy to understand the last part is converting string arguments back to numbers, this is easily done using `atoi` function, pass it the string, it returns the `int`