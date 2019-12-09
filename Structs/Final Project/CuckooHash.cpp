#include "hash.h"
#include <string>
#include <iostream>
#include <cmath>


using namespace std;

HashCuckoo::HashCuckoo(){
    load = 0;
    tableSize = 1019;
    occupied = 0;
    rehashed = 0;
    table1.assign(1019,-1);
    table2.assign(1019,-1);
}

bool HashCuckoo::lookup(int data){
    return ((table1[hash1(data)] == data) || (table2[hash2(data)] == data));
}

void HashCuckoo::insert(int data){

    // make sure data is not in either table during call to rehash

    if (table1[hash1(data)] == -1){
        table1[hash1(data)] = data;
        if (!rehashingFlag){
            occupied++;
        }
        return;
    }
    else if (table2[hash2(data)] == -1){
        table2[hash2(data)] = data;
        if (!rehashingFlag){
            occupied++;
        }
        return;
    }
    else{
        int currMov = data, key1, key2, flag = 0, nextMov, prevTable = 2;
        while (true){
            if (currMov == data){
                flag ++;
            }
            if (flag == 2 && !rehashingFlag){
                rehash(data);
                occupied++;
                return;
            }
            else if (flag == 2 && rehashingFlag){
                rehashCycleFlag = true;
                return;
            }
            key1 = hash1(currMov);
            key2 = hash2(currMov);

            if (table1[key1] != -1 && prevTable == 2){
                nextMov = table1[key1];
                table1[key1] = currMov;
                currMov = nextMov;
                prevTable = 1;
            }
            else if (table2[key2] !=-1 && prevTable == 1){
                nextMov = table2[key2];
                table2[key2] = currMov;
                currMov = nextMov;
                prevTable = 2;
            }
            else if (table1[key1] == -1 && prevTable == 2){
                table1[key1] = currMov;
                if (!rehashingFlag){
                    occupied++;
                }
                return;
            }
            else if (table2[key2] == -1 && prevTable == 1){
                table2[key2] = currMov;
                if (!rehashingFlag){
                    occupied++;
                }
                return;
            }
        }
    }
}

void HashCuckoo::remove(int data){
    if (table1[hash1(data)] == data){
        table1[hash1(data)] = -1;
    }
    else if (table2[hash2(data)] == data){
        table2[hash2(data)] = -1;
    }
    return;
}

float HashCuckoo::getLoad(){
    load = ((float)occupied/((float)tableSize*2))*100;
    int temp = (int)load;
    load = (float)temp/100;
    return load;
}

int HashCuckoo::hash1(int data){
    return data % tableSize;
}

int HashCuckoo::hash2(int data){
    return ((int)floor(data/tableSize)) % tableSize;
}

bool isPrime(int num){
    if (num <= 1){
        return false;
    } 
    if (num <= 3){
        return true;
    }
    
    if (num%2 == 0 || num%3 == 0) return false;  
    
    for (int i=5; i*i<=num; i=i+6)  
        if (num%i == 0 || num%(i+2) == 0)  
           return false;  
    
    return true;
}

int nextPrime(int num){
    if (num <= 1){
        return 2; 
    }

    int prime = num; 
    bool found = false; 
  
    while (!found) { 
        prime++; 
  
        if (isPrime(prime)) 
            found = true; 
    } 
  
    return prime;
}

void HashCuckoo::rehash(int data){
    vector<int> nums;

    for (vector<int>::iterator it = table1.begin() ; it != table1.end(); ++it){
        if (*it != -1){
            nums.push_back(*it);
        }
    }
    for (vector<int>::iterator it = table2.begin() ; it != table2.end(); ++it){
        if (*it != -1){
            nums.push_back(*it);
        }
    }

    nums.push_back(data);

    cycleMidRehash:
    rehashed++;

    cout << "r" << endl;

    table1.clear();
    table2.clear();

    rehashingFlag = true;
    rehashCycleFlag = false;

    tableSize = nextPrime(tableSize);

    table1.assign(tableSize, -1);
    table2.assign(tableSize, -1);

    for (vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it){
        insert(*it);
        if (rehashCycleFlag){
            goto cycleMidRehash;
        }
    }

    rehashingFlag = false;
    return;
}