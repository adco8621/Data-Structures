/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    if (head == NULL){
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    else if(previous == NULL){
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->next = head;
        head = newCountry;
        head->numberMessages = 0;
    }
    else{
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->next = previous->next;
        previous->next = newCountry;
        newCountry->numberMessages = 0;
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    insertCountry(NULL, "United States");
    insertCountry(head, "Canada");
    insertCountry(searchNetwork("Canada"), "Brazil");
    insertCountry(searchNetwork("Brazil"), "India");
    insertCountry(searchNetwork("India"), "China");
    insertCountry(searchNetwork("China"),"Australia");
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    Country *ptr = head;
    while (ptr != NULL && ptr->name != countryName){
        ptr = ptr->next;
    }
    return ptr;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    Country *exists;
    exists = searchNetwork(receiver);
    if (head == NULL){
        cout << "Empty list" << endl;
    }
    else if (exists == NULL){
        cout << endl << "Country not found" << endl;
    }
    else{
        Country *ptr = head;
        cout << endl;
        while (ptr != NULL && ptr->name != receiver)
        {
            ptr->message = message;
            ptr->numberMessages++;
            cout << ptr->name << " [# messages received: " << ptr->numberMessages << "] received: " << ptr->message << endl;
            ptr = ptr->next;
        }
        if(ptr->name == receiver){
            ptr->message = message;
            ptr->numberMessages++;
            cout << ptr->name << " [# messages received: " << ptr->numberMessages << "] received: " << ptr->message << endl;
        }
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    if(head == NULL){
        cout << "== CURRENT PATH ==" << endl;
        cout << "nothing in path" << endl << "===" << endl;
    }
    else{
        cout << "== CURRENT PATH ==" << endl;
        Country* ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl << "===" << endl;
    }
}
