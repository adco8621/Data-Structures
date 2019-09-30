#include <iostream>
#include <fstream>

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
            myArray[0] = myArray[1];
            myArray[0] = newValue;
        }
    }

    if (numEntries > 1){
        while (1)
        {
            if (newValue >= myArray[index]){
                if (index == numEntries-1){
                    myArray[numEntries] = newValue;
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
                    index = (index + max)/2;
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
    /*
    for(int i = 0; i < numEntries;i++){
       std::cout<<myArray[i]<<", ";
    }
    std::cout<<myArray[numEntries]<<std::endl;
    */
return numEntries + 1;
}

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