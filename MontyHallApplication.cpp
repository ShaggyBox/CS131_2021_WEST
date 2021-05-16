// MontyHallApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* Author: Danessa Yip
   Title:  The Monty Hall Challenge
Objective: This problem allows you to play the Monty Hall game, and gives you the probability that you will choose a door that does contain the prize.
*/

#include <iostream> // Include iostream
using namespace std; // include namespace

/* rightdoor - This function selects a random door to be the winner and
   returns an integer that is the name of the door.*/
int rightdoor(int doors) {
    int correctdoor;
    // Generate a random number.
    correctdoor = (rand() %
        doors);
    return correctdoor;
}
/* losingdoor - This is the door that is opened by the host.
   It returns an integer that is correlated with the door opened.*/
int losingdoor(int correctdoor, int doors) {
    int wrongdoor = (rand() % doors);
    /* Select wrong door number.  If it is the same as the correct door
       Then begin while loop.  */
    while (wrongdoor == correctdoor) {
        wrongdoor = (rand() % doors);
        // Once it is different, then break.
        if (wrongdoor != correctdoor) {
            break;
            return wrongdoor;
            cout << wrongdoor;
        }
    }
}
// MAIN PROGRAM - Handles all messages and selections, and later gives the probability.

int main()
{
    cout << "Welcome to the Monty Hall Game!" << endl; // Welcome message.
    cout << "Enter the number of doors you would like to try." << endl;
    int doors; // Number of doors.
    cin >> doors; // Door chosen.
    // While loop in case the number of doors is 3 or less.
    while (doors < 3) {
        // Once it is at least 3, then break.
        if (doors >= 3) {
            break;
        }
        cout << "Please select a number of doors greater than 2." << endl;
        cin >> doors;
    }
    // Select the winning prize door.
    int correctdoor = rightdoor(doors);
    // Pick a choice between switching or not switching.
    cout << "Please select a door." << endl;
    int choice;
    cin >> choice;
    // While loop for checking if the door is greater than 0.
    while (choice <= 0) {
        // If the choice is a legitimate door.
        if (choice >= 1) {
            break;
        }
        cout << "Please select a door not numbered less than 1.";
        cin >> choice;
    }
    // Open the door that does not contain the number.
    int opendoor = losingdoor(correctdoor, doors);
    cout << "The door opened by the host is: " << opendoor << endl;
    // Ask user if they would like to switch doors.
    cout << "Would you like to switch doors? Type (y/n)" << endl;
    // Initialize switch option
    char switchoption = 'd';
    // Begin while loop to check if doors are opened or not.
    while (switchoption != 'y' && switchoption != 'n') {
        cin >> switchoption;
        // Break if it is equal to 'y' for yes or 'n' for no.
        if (switchoption == 'y' || switchoption == 'n')
            break;
        // Print error message.
        cout << "Please choose between y and n." << endl;
    }
    // The second door choice is seconddoor.
    int seconddoor = 0;
    // Allow user to select their second door.
    if (switchoption == 'y') {
        cout << "Choose which door you would like." << endl;
        cin >> seconddoor;
        // Do not let user open the already open door or a door less than or equal to zero.
        while (seconddoor == opendoor && seconddoor <= 0) {
            // Please select a door that fits the above criteria.
            cout << "Please choose another door." << endl;
            cin >> seconddoor;
            // Break once all of the criteria are met.
            if (seconddoor != opendoor) {
                break;
            }
        }
    }
    // Show probability that you were right.
    cout << "The probability that you were correct is: ";
    float probability;
    float one = 1;
    /* If a second door was chosen, then the probability is based on the total doors
    without the open one and the available doors that were not selected. */
    if (seconddoor != 0) {
        probability = ((static_cast<float>(doors) - 1) / static_cast<float>(doors)) * 1/(static_cast<float>(doors) - 2);
        cout << probability << endl;
    }
    // If a second door was not chosen, then the probability is only one out of the number of doors.
    else {
        probability = (one / static_cast<float>(doors));
        cout << probability << endl;
    }
    // Print winning messages for a second door choice or an unchanged correct choice.
    if (seconddoor == correctdoor) {
        cout << "Congratulations!  You won!" << endl;
        cout << "The correct door was: " << correctdoor << endl;
    }
    else if (choice == correctdoor) {
        cout << "Congratulations!  You won!" << endl;
        cout << "The correct door was: " << correctdoor << endl;
    }
    // Print a losing message if either guess is incorrect.
    else {
        cout << "Unfortunately, you did not win." << endl;
        cout << "The correct door was: " << correctdoor << endl;
    }
    // Print a thank you message for playing the game.
    cout << "Thank you for playing the Monty Hall Game!" << endl;
    return 0;
    
}