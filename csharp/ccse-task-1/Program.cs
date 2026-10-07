using System;
using System.Collections;

public class Program
{
    public static void Main(string[] args)
    {
        // task-1 sum 3 numbers

        Console.Write("Enter 1st number: ");
        int.TryParse(Console.ReadLine(), out int n1);

        Console.Write("Enter 2nd number: ");
        int.TryParse(Console.ReadLine(), out int n2);

        Console.Write("Enter 3rd number: ");
        int.TryParse(Console.ReadLine(), out int n3);

        Console.WriteLine("Sum of {0} + {1} + {2} = {3}", n1, n2, n3, n1 + n2 + n3);

        /// padding between tasks
        Console.WriteLine("\n-----------------\n");

        //-----------------
        // task-2 radius, circumference and area
        Console.Write("Enter radius r: ");
        double.TryParse(Console.ReadLine(), out double r);

        Console.WriteLine("Circumference of circle = {0}", 2 * Math.PI * r);
        Console.WriteLine("Area of circle = {0}", Math.PI * r * r);

        /// padding between tasks
        Console.WriteLine("\n-----------------\n");

        //-----------------
        // task-3 company and manager info
        Console.Write("Enter company name: ");
        //if input is null, use an empty string
        string companyName = Console.ReadLine() ?? "";

        Console.Write("\nEnter company address: ");
        string companyAddress = Console.ReadLine() ?? "";

        Console.Write("\nEnter company phone number: ");
        string companyPhone = Console.ReadLine() ?? "";

        Console.Write("\nEnter company fax number: ");
        string companyFax = Console.ReadLine() ?? "";

        Console.Write("\nEnter company website: ");
        string companyWebsite = Console.ReadLine() ?? "";

        Console.Write("\nEnter manager first name: ");
        string managerFirstName = Console.ReadLine() ?? "";

        Console.Write("\nEnter manager surname: ");
        //if input is null, use an empty string
        string managerSurname = Console.ReadLine() ?? "";

        Console.Write("\nEnter manager phone number: ");
        //if input is null, use an empty string
        string managerPhone = Console.ReadLine() ?? "";

        Console.WriteLine("\nCompany Information:");
        Console.WriteLine(
            "Name: {0}\nAddress: {1}\nPhone: {2}\nFax: {3}\nWebsite: {4}",
            companyName,
            companyAddress,
            companyPhone,
            companyFax,
            companyWebsite
        );
        Console.WriteLine("Manager Information:");
        Console.WriteLine(
            "Name: {0} {1}\nPhone: {2}",
            managerFirstName,
            managerSurname,
            managerPhone
        );
    }
}
