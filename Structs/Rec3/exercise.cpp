#include <iostream>
#include <fstream>

using namespace std;


//Uncomment the lines and implement the TODOs in the resizing logic
void resize(int *&arrayPtr, int &capacity)
{

	cout<<"Resizing from "<<capacity<<" to "<<capacity*2<<endl;
	int *dbld = new int[capacity*2];
    for (int i = 0; i < capacity; i++) {
        dbld[i] = arrayPtr[i];
    }
    delete[] arrayPtr;
    arrayPtr = dbld;
	capacity += capacity;

}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		return -1;
	}
	string filename = argv[1];
	ifstream data;
	data.open(filename.c_str());

	int capacity = 10;
	int *arrayPtr;

	arrayPtr = new int;
	int numOfElement = 0;
	string temp;

	if(data.is_open())
	{
		while(getline(data, temp))
		{
			int toBeInsert = stoi(temp);
			if(numOfElement == capacity)
			{
				// Complete this function
				resize(arrayPtr, capacity);
			}
			arrayPtr[numOfElement] = toBeInsert;
			numOfElement++;
		}
		data.close();
	}

	for(int i = 0; i < numOfElement; i++)
	{
		cout << "Num: " << arrayPtr[i] << endl;
	}
	return 0;
}
