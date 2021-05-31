/* 
This program demonstrates the Pigeonhole principle by generating a list of 11 random one-digit integers [0, 9], then showing that 
there exists at least one such integer that is repeated at least twice. The program's output shows all of the repeated numbers and
the frequency by which they were repeated, in the form [number] ([frequency]x). Each number is separated by a double space.

If one were to run this program infinitely many times, it would never return a blank output (meaning that there were no repeats). This 
can be proven through the pigeonhole principle because we are sorting 11 random integers into 10 boxes (ordered 0-9), so at least one
box must have 2 or more objects (randomly chosen integers) inside of it.
*/

import java.util.*;
import java.math.*;

public class Pigeon
{
  public static void main (String[] args)
  {
    //welcome message
    System.out.println("\nWelcome to the Pigeonhole Principle Demonstration!\n");

    //initializes an array that will contain the random integers
    int[] nums = new int[11];

    //adds random numbers to the array nums and prints out the array's contents
    System.out.print("Test Numbers: ");
    for (int i = 0; i < 10; i++)
    {
        nums[i] = (int)Math.floor(Math.random() * 10);
        System.out.print(nums[i] + ", ");
    }
    System.out.println(nums[10]);

    //creates instance of Pigeon class and uses it to print out repeated numbers
    Pigeon tester = new Pigeon();
    tester.printRepeats(nums);

    //thank you message
    System.out.println("\n\nThank you for coming to this demonstration!\n");
  }

  public void printRepeats(int[] numbers)
  {
        //initializes a variable to store the length of the original array, then initializes an array to store repeat counts
        int len = numbers.length;
        int[] repeats = new int[10];
        
        //loops through the original array's numbers and adds 1 to repeats for each occurrence of an integer at that integer's index
        for (int i = 0; i < len; i++)
        {
            repeats[numbers[i]]++;
        }

        //loops through both arrays to output which numbers were repeated and their frequencies
        System.out.print("Repeated numbers: ");
        for (int j = 0; j < 10; j++)
        {
            if (repeats[numbers[j]] > 1)
            {
                System.out.print(numbers[j] + " (" + repeats[numbers[j]] + "x)  ");
                repeats[numbers[j]] = 1;
            }
        }
  }
}
