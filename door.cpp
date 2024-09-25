#include <bits/stdc++.h>
using namespace std;

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
