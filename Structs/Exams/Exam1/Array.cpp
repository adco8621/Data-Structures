#include<iostream>
#include<string>
using namespace std;


int main(int argc, char* argv[])
{
    srand(time(0));

    if(argc<3)
    {
      cout<<"usage: a.out 20 30";
      return -1;
    }

    int size1 = stoi(argv[1]);
    int *arr1 = new int[size1];


    cout<< "arr1:";
    for(int i = 0; i<size1; i++)
    {
        arr1[i] = rand()%100;
        cout<< arr1[i];
        if(i < size1-1)
          cout << ", ";
    }

    cout<<endl;
    return 0;
}
