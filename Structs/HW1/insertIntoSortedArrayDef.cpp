#include "insertIntoSortedArray.h"
#include <iostream>
int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
    //This is going to use a binary search insertion

    int index, min, max; 
    index = numEntries/2; //skipping the null elements of the array
    max = numEntries-1;
    min = 0;

    if (numEntries == 0){     //first value
        myArray[0] = newValue;
    }

    if (numEntries == 1){
        if (newValue >= myArray[0]){
            myArray[1] = newValue;
        } else {
            myArray[1] = myArray[0];
            myArray[0] = newValue;
        }
    }

    if (numEntries > 1){
        while (1)
        {
            if (newValue >= myArray[index]){
                if (index == numEntries-1){
                    myArray[numEntries] = newValue;
                    break;
                }
                else if (newValue <= myArray[index + 1]){
                    for (int i = numEntries; i > index; i--){
                        myArray[i+1] = myArray[i];
                    }
                    myArray[index+1] = newValue;
                    break;
                } 
                else {
                    min = index;
                    index = (index + max)/2 + 1;
                }
            } 
            else if (newValue < myArray[index]){
                if(index == 0){
                    for (int i = numEntries - 1; i >= index; i--){
                        myArray[i+1] = myArray[i];
                    }
                    myArray[index] = newValue;
                break;
                } 
                else if (newValue >= myArray[index - 1]){
                    for (int i = numEntries - 1; i >= index; i--){
                        myArray[i+1] = myArray[i];
                    }
                    myArray[index] = newValue;
                break;
                } 
                else {
                    max = index;
                    index = (index + min)/2;
                }
            }
        }
        
    }
return numEntries + 1;
}