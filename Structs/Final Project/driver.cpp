#include "hash.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>

using namespace std;

int main(){
    HashCuckoo cuckoo;
    //HashLL LL;
    //HashLP LP;
    HashBST BST;


    ifstream pre ("dataSetA.csv"), setA ("dataSetA.csv");
    ifstream setC ("dataSetC.csv");

    string line;

    int testNums[1000];

    LARGE_INTEGER frequency;
    LARGE_INTEGER startTime, endTime, totalTime;
    QueryPerformanceFrequency(&frequency);

    for (int i = 0; i < 1000; i++){
        getline(pre, line, ',');
        testNums[i] = stoi(line);
    }

    int j;

    for (float i = 0.1; i <= 1.1; i+=0.1){
        cout << "Load: " << i << endl;

        // Inserting to BST

        // while(BST.getLoad() < i){
        //     getline(setA, line, ',');
        //     BST.insert(stoi(line));
        // }

        // cout << BST.getLoad() << endl;

        // QueryPerformanceCounter(&startTime);
        // for (j = 0; j < 100; j++){
        //     BST.lookup(testNums[(int)((i-.1)*1000) + j]);
        // }
        // QueryPerformanceCounter(&endTime);
        // totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e6) / frequency.QuadPart;
        // cout << "BST Lookup Time: " << totalTime.QuadPart << endl;

        // QueryPerformanceCounter(&startTime);
        // for (j = 0; j < 100; j++){
        //     BST.remove(testNums[(int)((i-.1)*1000) + j]);
        // }
        // QueryPerformanceCounter(&endTime);
        // totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e6) / frequency.QuadPart;
        // cout << "BST Remove Time: " << totalTime.QuadPart << endl;

        // QueryPerformanceCounter(&startTime);
        // for (j = 0; j < 100; j++){
        //     BST.insert(testNums[(int)((i-.1)*1000) + j]);
        // }
        // QueryPerformanceCounter(&endTime);
        // totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e6) / frequency.QuadPart;
        // cout << "BST Insert Time: " << totalTime.QuadPart << endl;
        // cout << endl;

        // Cuckoo

        while(cuckoo.getLoad() < i){
            getline(setA, line, ',');
            cuckoo.insert(stoi(line));
        }

        QueryPerformanceCounter(&startTime);
        for (j = 0; j < 100; j++){
            cuckoo.lookup(testNums[testNums[(int)((i-.1)*1000) + j]]);
        }
        QueryPerformanceCounter(&endTime);
        totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e6) / frequency.QuadPart;
        cout << "Cuckoo Lookup Time: " << totalTime.QuadPart << endl;

        // QueryPerformanceCounter(&startTime);
        // for (int j = 0; j < 100; j++){
        //     cuckoo.remove(testNums[j]);
        // }
        // QueryPerformanceCounter(&endTime);
        // totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e6) / frequency.QuadPart;
        // cout << "Cuckoo Remove Time: " << totalTime.QuadPart << endl;

        // QueryPerformanceCounter(&startTime);
        // for (int j = 0; j < 100; j++){
        //     cuckoo.insert(testNums[j]);
        // }
        // QueryPerformanceCounter(&endTime);
        // totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e6) / frequency.QuadPart;
        // cout << "Cuckoo Insert Time: " << totalTime.QuadPart << endl;
        // cout << endl;
        
    }
    return 0;
}