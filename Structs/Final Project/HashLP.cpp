#include <vector>
#include <iostream>
#include "hash.h"
#include <cmath>

using namespace std;

/* CONSTRUCTOR 
    The purpose of having a constructor in this case is to be
    able to initialize the entire array to -1 for the below
    functions to work properly.
*/
HashLP::HashLP()
{
    for(int i = 0; i < 1019; i++) 
    {
        table[i] = -1;
    }
}

/* HASH
    This function will return the value of the element being inserted into 
    the hash table. We will use x mod TABLE_SIZE.
*/
int HashLP::hash(int data)
{
    // return data % tableSize; // Hash Function 1
    return (int)floor(data/tableSize) % tableSize; // Hash Function 2
}

/* LOOKUP
    This function will lookup any value being input and return true if it
    is found and false if not. 
*/
bool HashLP::lookup(int num)
{
    int key = hash(num);
    int start = key;

    while((table[key] != num) && (key != (start-1)) && (table[key] != -1)) // Crawl through until found
    {
        key += stepSize;
    }

    if(table[key] == num) //
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* INSERT
    This function will insert the value that was sent to this function and
    use the Linear Probing collision resolution.
*/
void HashLP::insert(int num)
{
    int key = hash(num);

    if((table[key] == -1) || (table[key] == -2)) // If there is no information within the hash spot
    {
        table[key] = num; // Insert the element
        occupied++;
        return;
    }
    else // If there is something there (not NULL)
    {
        while((table[key] != -1) && (table[key] != -2))
        {
            if(key < (tableSize - 1))
            {
                key += stepSize; // Step size of 1
            }
            else
            {
                key = 0;
            }
        }
        table[key] = num; // Add the element
        occupied++; // Increment the number of elements
        
        return;
    }
    return;
}

/* REMOVE
    This function will remove any element that is input and return true if 
    successfully removed, and false otherwise.

    Ignore -2's as well as -1's
*/
bool HashLP::remove(int num)
{
    int key = hash(num);
    int start = key;

    while((table[key] != num) && (key != (start-1)) && (table[key] != -1))
    {
        key += stepSize;
    }

    if(table[key] == num)
    {
        table[key] = -2;
        return true;
    }
    else
    {
        return false;
    }
    
}

/* GET LOAD
    This function will return the load factor of the hash table at any given
    time. The load factor is the amount of space that is filled in the hash
    table at any given moment.
*/
float HashLP::getLoad()
{
    // Need to find the load for only one decimal place (truncate the rest)
    load = ((float)occupied/(float)tableSize)*100;
    int temp = (int)load;
    load = (float)temp/100;
    return load;
}