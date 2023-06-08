import java.util.Scanner;
class Demo {
   
    public static void main(String[] args)
    {
        double fahrenheit;
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter temperature in fahrenheit: ");
        fahrenheit = sc.nextInt();

        double celsius = (fahrenheit - 32) / 1.8;
 
        // print the celsius temperature
        System.out.println("Value of temperature in celsius:" + celsius);
        sc.close();
    }
}