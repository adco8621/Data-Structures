#include "hash.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    HashBST test;

    cout << test.table[10]->data << endl;

    test.insert(10);

    return 1;

}