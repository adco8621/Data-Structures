#include <iostream>

using namespace std;

int ack(int m, int n){
    //cout << "calling ack(" << m << ',' << n << ")" << endl;
    if (m == 0){
        return n+1;
    }
    else if (m > 0 && n == 0){
        return ack(m-1, 1);
    }
    else{
        return ack(m-1, ack(m, n-1));
    }
}

int main(){
    cout << ack(4,1) << endl;
    return 1;
}