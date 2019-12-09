#include <vector>
#include <iostream>
#include "hash.h"
#include <cmath>

using namespace std;

/* HASH 
    This function will return the value of the element being inserted into 
    the hash table. We will use x mod TABLE_SIZE.
*/
int HashLL::hash(int data)
{
    return data % tableSize; // Hash Function 1
    // return (int)floor(data/tableSize) % tableSize; // Hash Function 2
}

/* LOOKUP
    This function will lookup any value being input and return true if it
    is found and false if not. 
*/
bool HashLL::lookup(int num)
{
    int key = hash(num); // The location of the element in the hash table
    LLNode *lookupNode = table[key];
    while((lookupNode != NULL) && (lookupNode->data != num))
    {
        lookupNode = lookupNode->next;
    }
    
    if(lookupNode == NULL) 
    {
        return false;
    }
    else // If the lookupNode is the same at the data searching for
    {
        return true;
    }
}

/* INSERT
    This function will insert the value that was sent to this function and
    use the Linear Probing collision resolution.
*/
void HashLL::insert(int num)
{
    int key = hash(num); // Sends the data to be hashed
    LLNode *insertNode = table[key]; // At the correct hash location
    if(insertNode == NULL) // Check if the head is empty and insert
    {
        table[key] = new LLNode;
        table[key]->data = num;
        occupied++; // Adds to the number of elements (only use when its the head being added)
        return; // Head node added successfully
    }
    else // Case for if there already is a Linked List at the location
    {
        while(insertNode->next != NULL) // Crawl to the end of the LL
        {
            insertNode = insertNode->next;
        }
        insertNode->next = new LLNode;
        insertNode->next->data = num;
        return; // LL Node added successfully
    }
}

/* REMOVE
    This function will remove any element that is input and return true if 
    successfully removed, and false otherwise.
*/
bool HashLL::remove(int num)
{
    int key = hash(num);
    LLNode *pres = table[key];
    LLNode *prev = NULL;
    if(lookup(key) == false)
    {
        return false;
    }
    else if(pres->data == num) // Delete the first element
    {
        table[key] = table[key]->next;
        delete pres;
    }
    else // Delete element in the LL
    {
        while(pres->data != num)
        {
            prev = pres;
            pres = pres->next;
        }
        prev->next = pres->next;
        delete pres;
    }
}

/* GET LOAD
    This function will return the load factor of the hash table at any given
    time. The load factor is the amount of space that is filled in the hash
    table at any given moment.
*/
float HashLL::getLoad()
{
    // Need to find the load for only one decimal place (truncate the rest)
    load = ((float)occupied/(float)tableSize)*100;
    int temp = (int)load;
    load = (float)temp/100;
    return load;
}