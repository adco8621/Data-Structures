/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
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

    MENU:
    displayMenu();

    getline(cin,menuStr,'\n');
    menuChoice = stoi(menuStr);

    switch(menuChoice){

        case 1:
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();
            isPop = true;
            goto MENU;

        case 2:
            CountryNet.printPath();
            goto MENU;

        case 3:
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

        case 4:
            cout << "Enter a new country name:" << endl;
            getline(cin,addCountry,'\n');
            cout << "Enter the previous country name (or First):" << endl;
            getline(cin,after,'\n');

            if(after != "First"){
                AGAIN:
                exists = CountryNet.searchNetwork(after);

                if(exists == NULL){
                    cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    getline(cin,after,'\n');
                    goto AGAIN;
                }
                else{
                    if (!isupper(addCountry[0])){
                        addCountry[0] = toupper(addCountry[0]);
                    }
                    CountryNet.insertCountry(CountryNet.searchNetwork(after),addCountry);
                    CountryNet.printPath();
                    isPop = true;
                    goto MENU;
                }

            }
            else {
                if (!isupper(addCountry[0])){
                    addCountry[0] = toupper(addCountry[0]);
                }
                CountryNet.insertCountry(NULL, addCountry);
                CountryNet.printPath();
                goto MENU;
            }
        case 5:
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
