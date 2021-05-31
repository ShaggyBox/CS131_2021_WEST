/* 
This program demonstrates the Generalized Pigeonhole principle by taking a list of the most popular male names in the United States
from each first letter, forming a list of 26 names, and then randomly sorting these names into five distinct lists, named List1 - List5.
By the Generalized Pigeonhole principle, one of these lists must contain ⌈26/5⌉ = 6 names in it. The program's output confirms this by
displaying the names contained within each list and then displaying the lists with at least 6 names, as well as the exact amount of names
those lists contain.

If one were to run this program infinitely many times, it would never return a blank output (meaning that there were no lists containing
6 or more names). This can also be proven through the Generalized Pigeonhole principle because we are sorting 26 random names into 
5 lists (ordered 1-5), so at least one lists must have 6 or more names in it.
*/

import java.util.*;
import java.math.*;

public class genPigeon
{
  public static void main (String[] args)
  { 
    //initializes String array containing the 26 names, num variable for randomization, len for names.length, and the 5 ArrayLists
    String names[] = {"Alexander", "Benjamin", "Carter", "Daniel", "Elijah", "Finn", "Grayson", "Henry", "Isaac", 
    "James", "Kayden", "Liam", "Mason", "Noah", "Oliver", "Parker", "Quinn", "Ryan", "Sebastian", "Theodore", 
    "Uriel", "Vincent", "William", "Xavier", "Yusuf", "Zachary"};
    int num;
    int len = names.length;
    ArrayList<String> List1 = new ArrayList<String>();
    ArrayList<String> List2 = new ArrayList<String>();
    ArrayList<String> List3 = new ArrayList<String>();
    ArrayList<String> List4 = new ArrayList<String>();
    ArrayList<String> List5 = new ArrayList<String>();

    //loops through all names in names[] and sorts them into the 5 ArrayLists
    for (int i = 0; i < len; i++)
    {
        num = (int)Math.ceil(Math.random() * 5);
        if (num == 1)
        {
            List1.add(names[i]);
        } else if (num == 2)
        {
            List2.add(names[i]);
        } else if (num == 3)
        {
            List3.add(names[i]);
        } else if (num == 4)
        {
            List4.add(names[i]);
        } else
        {
            List5.add(names[i]);
        }
    }

    //welcome message
    System.out.println("\nWelcome to the Generalized Pigeonhole Principle Demonstration!\n");

    //prints the contents of each list
    System.out.print("List 1 names: ");
    for (String name : List1)
    {
        System.out.print(name + " ");
    }
    System.out.print("\nList 2 names: ");
    for (String name : List2)
    {
        System.out.print(name + " ");
    }
    System.out.print("\nList 3 names: ");
    for (String name : List3)
    {
        System.out.print(name + " ");
    }
    System.out.print("\nList 4 names: ");
    for (String name : List4)
    {
        System.out.print(name + " ");
    }
    System.out.print("\nList 5 names: ");
    for (String name : List5)
    {
        System.out.print(name + " ");
    }

    //finds lists with over 5 names and prints the list number and quantity of names
    System.out.println("\n\nLists with more than 5 names: ");
    if (List1.size() > 5)
    {
        System.out.print("List 1 (" + List1.size() + ")  ");
    }
    if (List2.size() > 5)
    {
        System.out.print("List 2 (" + List2.size() + ")  ");
    }
    if (List3.size() > 5)
    {
        System.out.print("List 3 (" + List3.size() + ")  ");
    }
    if (List4.size() > 5)
    {
        System.out.print("List 4 (" + List4.size() + ")  ");
    }
    if (List5.size() > 5)
    {
        System.out.print("List 5 (" + List5.size() + ")  ");
    }

    //thank you message
    System.out.println("\n\nThank you for coming to this demonstration!\n");
  }
}
