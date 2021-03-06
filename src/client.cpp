
/* Ryan Hoover - 04/30/17
 * CS202 - K. Fant
 * PROGRAM 2 
 * contact.cpp
 * CLIENT-SIDE FUCNTION IMPLEMENTATIONS */

//#include "contact.h"
#include "communication.h"

// ---------------------------------------------------------------

int mainMenu(void) {
    int menu = 0;
    cout << "\n\n+ + Main Menu + + + +\n"
        << "\nPress > 1 < Enter new CONTACT data."
        << "\nPress > 2 < Display the Address Book."
        << "\nPress > 3 < Search the address book."
        << "\nPress > 4 < remove all address entries."
        << "\nPress > 5 < Remove single address book entry by keyword."
        << "\nPress > 6 < to Enter new APPdata."
        << "\nPress > 7 < to Display the Inbox."
        << "\nPress > 8 < to Quit.";
    do {
        cout << "\n >> Make a selection: ";
        cin >> menu; cin.ignore(SIZE,'\n');
        if (cin.fail())
            cout << "\nError - Enter a valid number: ";
        while (cin.fail()) {
            cin.clear(); cin.ignore();
            cin >> menu; cin.ignore(SIZE,'\n');
        }
    } while (menu < 1 || menu > 8);
    return menu;
}

// ----------------------------------------------------------------

bool again(void) {
    char response = 'n';
    bool again = false;
    do {
        cout << "\n >> Again? (y,n): ";
        cin >> response; cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            again = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return again;
}

// ---------------------------------------------------------------

bool backToMenu(void) {
    char response = 'n';
    bool back = false;
    do {
        cout << " >> Back to menu? (y,n): ";
        cin >> response; cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            back = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return back;
}

// ---------------------------------------------------------------

bool confirm(void) {
    char response = 'n';
    bool confirm = false;
    do {
        cout << " >> Confirm? (y,n): ";
        cin >> response; cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            confirm = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return confirm;
}

// --------------------------------------------------------------

// Paves the word as all lower case, then goes through again and capitalizes accordingly
int formatName(char * aName)
{
    if (!aName) return 0;
    int t = strlen(aName);
    aName[0] = toupper(aName[0]);
    for (int i=1; i < t; ++i)
    {
        aName[i] = tolower(aName[i]);
    }
    for (int i=1; i < t; ++i)
    {
        if (aName[i] == ' ')
        {
            aName[i+1] = toupper(aName[i+1]);
        }
    }
    return 1;
}


