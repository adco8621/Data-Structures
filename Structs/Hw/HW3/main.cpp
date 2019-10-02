/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/*  Yes I know I should have used while() instead of goto: but  */
/*  I was learning loops in assembly at the time so it was on   */
/*  my mind.                                                    */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <cctype>
#include <string>
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    int menuChoice;
    string receive, msg, addCountry, after,menuStr;
    Country *exists;
    bool isPop = false;

    MENU:         // poorly implemented while loop, check hw4 to see a while loop implementation
    displayMenu();

    getline(cin,menuStr,'\n');
    menuChoice = stoi(menuStr);

    switch(menuChoice){

        case 1:  // load default LL
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();
            isPop = true;
            goto MENU;

        case 2:  // print current LL
            CountryNet.printPath();
            goto MENU;

        case 3:  // Send message
            cout << "Enter name of the country to receive the message:" << endl;
            getline(cin,receive,'\n');
            cout << "Enter the message to send:" << endl;
            getline(cin,msg,'\n');
            if (!isPop){
                cout << endl << "Empty list" << endl;
                goto MENU;
            }
            CountryNet.transmitMsg(receive, msg);
            goto MENU;

        case 4:  // Add country
            cout << "Enter a new country name:" << endl;
            getline(cin,addCountry,'\n');
            cout << "Enter the previous country name (or First):" << endl;
            getline(cin,after,'\n');

            if(after != "First"){ // not adding to beginning of LL
                AGAIN:   // another bad while loop
                exists = CountryNet.searchNetwork(after);

                if(exists == NULL){ // check if country to add after exists
                    cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    getline(cin,after,'\n');
                    goto AGAIN;
                }
                else{
                    if (!isupper(addCountry[0])){ // capitalize first letter of new country
                        addCountry[0] = toupper(addCountry[0]);
                    }
                    CountryNet.insertCountry(CountryNet.searchNetwork(after),addCountry);
                    CountryNet.printPath();
                    isPop = true;
                    goto MENU;
                }

            }
            else { // adding to beginning of LL
                if (!isupper(addCountry[0])){ // capitalize
                    addCountry[0] = toupper(addCountry[0]);
                }
                CountryNet.insertCountry(NULL, addCountry);
                CountryNet.printPath();
                goto MENU;
            }
        case 5: // quit
            cout << "Quitting..." << endl << "Goodbye!" << endl;
            break;

    }

    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
