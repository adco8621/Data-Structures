/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/*                                                              */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <cctype>
#include <string>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    int menuChoice, rotate;
    bool stop = false;
    string menuStr, addCountry, after, delCountry, rotateStr;
    Country *exists;

    while (!stop){
        displayMenu();
        getline(cin, menuStr, '\n');
        menuChoice = stoi(menuStr);

        switch (menuChoice)
        {
        case 1: // load default LL
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();

            break;
        
        case 2: // print LL
            CountryNet.printPath();
            
            break;

        case 3: // Add a new country
            cout << "Enter a new country name:" << endl;
            getline(cin,addCountry,'\n');
            cout << "Enter the previous country name (or First):" << endl;
            getline(cin,after,'\n');
            exists = CountryNet.searchNetwork(after);

            if(after != "First"){
                while(exists == NULL){
                    cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                    getline(cin,after,'\n');
                }
                if (!isupper(addCountry[0])){
                    addCountry[0] = toupper(addCountry[0]);
                }
                CountryNet.insertCountry(CountryNet.searchNetwork(after),addCountry);
                CountryNet.printPath();
            }
            else {
                if (!isupper(addCountry[0])){
                    addCountry[0] = toupper(addCountry[0]);
                }
                CountryNet.insertCountry(NULL, addCountry);
                CountryNet.printPath();
            }
            
            break;

        case 4: // delete country
            cout << "Enter a country name: " << endl;
            getline(cin,delCountry,'\n');
            CountryNet.deleteCountry(delCountry);
            CountryNet.printPath();

            break;

            case 5: // reverse LL
                CountryNet.reverseEntireNetwork();
                CountryNet.printPath();

                break;

            case 6: // rotate LL
                cout << "Enter the count of values to be rotated: " <<  endl;
                getline(cin, rotateStr, '\n');
                rotate = stoi(rotateStr);
                CountryNet.rotateNetwork(rotate);
                CountryNet.printPath();

                break;

            case 7: // delete entire LL
                cout << "Network before deletion" << endl;
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                cout << "Network after deletion" << endl;
                CountryNet.printPath();

                break;

            case 8: // delete entire LL and quit
                cout << "Quitting... cleaning up path: " << endl;
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                if (CountryNet.isEmpty()){
                    cout << "Path cleaned" << endl;
                }
                else{
                    cout << "Error: Path NOT cleaned" << endl;
                }
                cout << "Goodbye!" << endl;

                stop = true;
                break;

        default:
            break;
        }
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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
