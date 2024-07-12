#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void box1();
void box2();
void box3();
void left_door();
void right_door();
void play_again();

vector<string> inventory;
 
int main() {
    cout << "Welcome to the Text-based Adventure Game!\n";
    cout << "You find yourself in a room.\n";
    cout << "You see two doors in front of you\n";
    cout << "one on the left and one on the right.\n";
 
    while (true) {
        string choice;
        cout << "Which door do you choose? (left/right) ";
        cin >> choice;
        
        if (choice == "left") {
            left_door();
            break;
        }
        else if (choice == "right") {
            right_door();
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'left' or 'right'.\n";
        }
    }
 
    return 0;
}
 
void left_door() {
    cout << "\nYou chose the left door.\n";
    box1();
}
 
void right_door() {
    cout << "\nYou chose the right door.\n";
    box2();
}
 
void box1() {
    cout << "You enter a room with a locked chest.\n";
    cout << "You notice a key on the table.\n";
 
    while (true) {
        cin.ignore();
        cout << "What would you like to do? (take key/leave) ";
        string choice;
        getline(cin, choice);
 
 
        if (choice == "take key") {
            inventory.push_back("key");
            cout << "You took the key.\n";
        }
 
        else if (choice == "leave") {
            cout << "You leave the room.\n";
            right_door();
            break;
        }
        else {
            cout << "Invalid choice.\n";
            break;
        }
         
    }
}
void box2() {
    cout << "You enter a room in a sleeping monster.\n";
 
    if (std::find(inventory.begin(), inventory.end(), "key") != inventory.end()) {
        cout << "You use the key to unlock the door and escape quietly.\n";
        box3();
    }
    else {
        cout << "The monster wakes up and eats you!\n";
        play_again();
    }
}
 
void box3() {
    cout << "You enter a room filled with treasures!\n";
    cout << "Congratulations, you win!\n";
    play_again();
}

void play_again() {
    while (true) {
        string choice;
        cout << "Do you want to play again? (yes/no) ";
        cin >> choice;
 
        if (choice == "yes") {
            inventory.clear();
            main();
            break;
        }
        else if (choice == "no") {
            cout << "Thanks for playing!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please enter 'yes' or 'no'.\n";
        }
    }
}