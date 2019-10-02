#include <iostream>
#include <fstream>

int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
    // This is going to use a binary search insertion
    // Checks if number to insert is larger or smaller than current index. If larger, current index is set to min, if smaller
    // current index is set to max, then new current index moves halfway between min and max

    int index, min, max; 
    index = numEntries/2; // start at middle of array
    max = numEntries-1;
    min = 0;

    if (numEntries == 0){     //first value
        myArray[0] = newValue;
    }

    if (numEntries == 1){ // second value
        if (newValue >= myArray[0]){
            myArray[1] = newValue;
        } else {
            myArray[1] = myArray[0];
            myArray[0] = newValue;
        }
    }

    if (numEntries > 1){ // everything else
        while (1)
        {
            if (newValue >= myArray[index]){ // if num to insert is larger than current index
                if (index == numEntries-1){  // if current index is final in array
                    myArray[numEntries] = newValue;
                    break;
                }
                else if (newValue <= myArray[index + 1]){     // to insert to the right of current index
                    for (int i = numEntries; i > index; i--){ // shift array elements
                        myArray[i+1] = myArray[i];
                    }
                    myArray[index+1] = newValue;
                    break;
                } 
                else { // not yet insert
                    min = index;
                    index = (index + max)/2 + 1;
                }
            } 
            else if (newValue < myArray[index]){ // less than current index
                if(index == 0){ // insert as first array element
                    for (int i = numEntries - 1; i >= index; i--){
                        myArray[i+1] = myArray[i];
                    }
                    myArray[index] = newValue;
                break;
                } 
                else if (newValue >= myArray[index - 1]){ // insert in arbitrary spot
                    for (int i = numEntries - 1; i >= index; i--){ // shift elements
                        myArray[i+1] = myArray[i];
                    }
                    myArray[index] = newValue;
                break;
                } 
                else { // still not insert
                    max = index;
                    index = (index + min)/2;
                }
            }
        }
        
    }
return numEntries + 1;
}

// Pulls numbers from a text file and inserts them into a sorted array
int main(){
    int array[100] = {};
    int numIn;

    std::ifstream nums ("numbers.txt");

    int numel = 0;

    for (int i = 0; i < 100; i++){
        nums >> numIn;
        numel = insertIntoSortedArray(array, i, numIn);
        for (int j = 0; j <= i; j++){
            if (numel == 1 || j == i){
                std::cout<<array[j]<<std::endl;;
            }
            std::cout<<array[j]<<",";
        }
    }
    
    return 1;
}