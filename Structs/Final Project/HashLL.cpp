#include<vector>

using namespace std;

struct element{
    int key;
    element *next;
}

class HashLL{
    private:
        int size;
        float load;
        vector<element> table;

    int hash(int key);

    public:
        HashLL(int size);
        void insert(int key);
        void lookup(int key);
        void remove(int key);
}

