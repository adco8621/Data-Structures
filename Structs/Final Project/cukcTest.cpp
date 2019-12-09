#include "hash.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main(){

    HashCuckoo test;

    // ifstream infile ("nums.txt");
    // string line;

    // for (int i = 0; i < 100; i++){
    //     getline(infile, line);
    //     test.insert(stoi(line));
    // }

    // cout << test.getLoad() << endl;

    // cout << test.rehashed << endl;

    ////    lookup test    ////////////////////////////////

    test.insert(10);
    test.insert(1029);

    cout << test.lookup(10) << endl << test.lookup(1029) << endl;

////    remove test    /////////////////////////////////


    // test.insert(10);
    // test.insert(1029);

    // test.remove(10);

    // cout << test.lookup(10) << endl << test.lookup(1029) << endl;

    // test.insert(10);

    // test.remove(10);

    // cout << test.lookup(10) << endl << test.lookup(1029) << endl;

    return 1;

}