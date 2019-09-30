#include <iostream>
using namespace std;

void reset(int *ip){
    *ip = 0;
}

int main(){
    int i = 100;
    int *p = &i;
    reset(p);
    cout << *p << endl;
}