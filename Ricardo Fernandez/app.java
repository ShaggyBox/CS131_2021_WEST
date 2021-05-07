//Author: Ricardo Fernandez
//CS 131 Project

import java.util.Scanner;


public class app{

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        
        constant(input);
        
    }


    /**
     * This is a methode that runs in Constant Time;
     */
    public static int constant(Scanner input){

        int x,y,z;

        System.out.println("the Following Code is demonstrates Constant Growth.");
        System.out.println("Enter 2 number that will be added together. ");

        System.out.print("Enter the first number: ");
        x = input.nextInt();
        System.out.print("Enter the second number: ");
        y = input.nextInt();

        z= x*y;

        System.out.println("The result is: " + z);

        return z;
    }
}