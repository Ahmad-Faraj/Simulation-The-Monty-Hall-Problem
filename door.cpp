#include <bits/stdc++.h>
using namespace std;

/*
The Monty Hall Problem Explained :

The Monty Hall problem is a famous probability puzzle based on a game show scenario.
Imagine there are three doors: behind one door is a valuable prize (like a car), while the other two doors hide goats.
The contestant initially picks one door, say Door 1, which gives a 1/3 chance of winning the car.

After the choice is made, the host—who knows what’s behind each door—opens one of the remaining doors (let’s say Door 3) to reveal a goat.
The host then offers the contestant a choice: stick with their original selection or switch to the other unopened door (Door 2).

Intuitively, many people think the odds are now 50/50 since there are two doors left.
However, the best strategy is actually to switch. By doing so, the contestant increases their chances of winning to 2/3.
This counterintuitive result arises because the initial choice had only a 1/3 chance of being correct,
meaning there’s a 2/3 chance the prize is behind one of the other doors.

To illustrate this, Here is a simulation that can be run where the game is played multiple times,
revealing that switching consistently yields a higher probability of winning.
This surprising outcome encourages deeper exploration into the nature of probability and decision-making.
*/

signed main()
{
    srand(time(0));
    int wins = 0;
    int trials = 100000; // Increase it for more Accuracy and precision

    while (trials--)
    {

        int car = rand() % 3;      // Randomly place the winning choice behind one door
        int choice = rand() % 3;   // Player's initial door choice
        int revealed = rand() % 3; // Host's revealed door

        /*Making sure that the Host reveals a door
        that is not the player's choice and not the car*/
        while (revealed == choice || revealed == car)
        {
            revealed = rand() % 3; // running until we pick a valid revealed door
        }

        // Player switches to the remaining door
        int switch_choice = 3 - choice - revealed;

        if (switch_choice == car)
        {
            wins++;
        }
    }

    cout << "Winning probability when switching: " << (static_cast<double>(wins) / trials) * 100 << "%" << endl;

    return 0;
}