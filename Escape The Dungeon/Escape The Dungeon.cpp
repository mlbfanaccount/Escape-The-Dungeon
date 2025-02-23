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
        bool hasKey = false;
        bool hasHolySword = false;
        bool foundTreasure = false;
        bool leftTunnelExplored = false;
        bool leftTunnelEmpty = false;
        
        while (true) {
            // Player chooses a tunnel
            cout << "1. Take the left tunnel" << endl;
            cout << "2. Take the right tunnel" << endl;
            choice = getValidChoice(1, 2);
            
            if (choice == 1) {
                if (leftTunnelEmpty) {
                    cout << "The left tunnel is now empty. There is nothing left to find here." << endl;
                    cout << "Do you want to: " << endl;
                    cout << "1. Escape the dungeon" << endl;
                    cout << "2. Continue exploring the dungeon" << endl;
                    choice = getValidChoice(1, 2);
                    if (choice == 1) {
                        cout << "You use the key to open the next room and escape! You win!" << endl;
                        break;
                    }
                    continue;
                }
                
                if (leftTunnelExplored) {
                    cout << "You return to the left tunnel, but find nothing new." << endl;
                    leftTunnelEmpty = true;
                    continue;
                }
                
                // Goblin encounter
                cout << "You encounter a goblin! What do you do?" << endl;
                cout << "1. Charge right ahead" << endl;
                cout << "2. Escape back to the original room" << endl;
                choice = getValidChoice(1, 2);
                
                if (choice == 1) {
                    // Player wins fight and gets key
                    cout << "You bravely fight the goblin and win! You find a key as a reward." << endl;
                    hasKey = true;
                    
                    // Major decision using switch
                    cout << "Do you want to: " << endl;
                    cout << "1. Search the room" << endl;
                    cout << "2. Escape the dungeon" << endl;
                    choice = getValidChoice(1, 2);
                    
                    switch (choice) {
                        case 1:
                            cout << "You search the room and discover a Holy Sword!" << endl;
                            hasHolySword = true;
                            cout << "Armed with the Holy Sword, you decide to explore further..." << endl;
                            cout << "Do you want to: " << endl;
                            cout << "1. Escape the dungeon" << endl;
                            cout << "2. Go back to the original starting point" << endl;
                            choice = getValidChoice(1, 2);
                            if (choice == 1) {
                                cout << "You use the key to open the next room and escape! You win!" << endl;
                                break;
                            }
                            break;
                        case 2:
                            cout << "You use the key to open the next room and escape! You win!" << endl;
                            break;
                    }
                    leftTunnelExplored = true;
                } else {
                    // Player returns to the starting area
                    cout << "You safely escape back to the original room, but gain nothing." << endl;
                }
            } else if (hasHolySword) {
                // Right tunnel encounter after getting the Holy Sword
                cout << "You enter the right tunnel again and encounter a zombie!" << endl;
                cout << "With the Holy Sword, you fend off the zombie effortlessly!" << endl;
                cout << "A hidden path opens up, leading you to a secret treasure room!" << endl;
                cout << "You find a treasure chest filled with gold and another exit!" << endl;
                cout << "You escape the dungeon with riches! Congratulations, you win!" << endl;
                foundTreasure = true;
                break;
            } else {
                // Right tunnel leads to a dead end and zombie attack if no Holy Sword
                cout << "You reach a dead end, but suddenly a zombie appears and blocks the exit!" << endl;
                cout << "The zombie attacks, and you don't survive. GAME OVER." << endl;
                break;
            }
        }
        
        // Ask if the player wants to retry
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing Escape the Dungeon!" << endl;
    return 0;
}

