#include <iostream>
using namespace std;

int getValidChoice(int min, int max) {
    int choice;
    while (cout << "Enter your choice: " && !(cin >> choice) || choice < min || choice > max) {
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return choice;
}

int main() {
    char playAgain;
    do {
        // Introduction
        cout << "Welcome to Escape the Dungeon!" << endl;
        cout << "You find yourself trapped in a dark dungeon." << endl;
        cout << "Your mission is to find a way out." << endl;

        int choice;
        bool hasKey = false; // Key for opening a locked door and escaping safely

        while (true) {
            // Player chooses a tunnel
            cout << "1. Take the left tunnel" << endl;
            cout << "2. Take the right tunnel" << endl;
            choice = getValidChoice(1, 2);

            if (choice == 1) {
                // Goblin encounter
                cout << "You encounter a goblin! What do you do?" << endl;
                cout << "1. Charge right ahead" << endl;
                cout << "2. Escape back to the original room" << endl;
                choice = getValidChoice(1, 2);

                if (choice == 1) {
                    // Player wins fight and gets key
                    cout << "You bravely fight the goblin and win! You find a key as a reward." << endl;
                    hasKey = true;
                    break; // Move forward with the key
                }
                else {
                    // Player returns to the starting area
                    cout << "You safely escape back to the original room, but gain nothing." << endl;
                }
            }
            else {
                // Right tunnel leads to a dead end and zombie attack
                cout << "You reach a dead end, but suddenly a zombie appears and blocks the exit!" << endl;
                cout << "The zombie attacks, and you don't survive. GAME OVER." << endl;
                break;
            }
        }

        // If the player has the key, they escape
        if (hasKey) {
            cout << "You use the key to open the next room and escape! You win!" << endl;
        }

        // Ask if the player wants to retry
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Escape the Dungeon!" << endl;
    return 0;
}
