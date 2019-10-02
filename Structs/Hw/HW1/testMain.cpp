#include "insertIntoSortedArray.h"
#include <iostream>
#include <fstream>

// This file is to test a bubble sort-esque method of inserting a number into a sorted array from a file

int main(int argc, char const* argv[]){
    int array[100] = {};
    int line, num1;
    std::string numIn;

    std::ifstream nums (argv[1]); 

    int numel = 0;
    int i = 0;

    if (nums.is_open()){
        while(getline(nums, numIn)){
            num1 = stoi(numIn);
            numel = insertIntoSortedArray(array, i, num1);
            for (int j = 0; j <= i; j++){
                if (numel == 1 || j == i){
                    std::cout<<array[j]<<std::endl;;
                }
                else {
                    std::cout<<array[j]<<",";
                }
            }
            i++;
        }
    }
    else {
        std::cout << "Failed to open the file.";
    }

    return 1;
}