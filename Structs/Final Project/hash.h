#include <vector>
#include <string>

using namespace std;

struct LLNode{
    int data;
    LLNode *next = {};
};

struct BSTNode{
    int data;
    BSTNode *left = {};
    BSTNode *right = {};
};

class HashLL{
public:
    bool lookup(int num);
    void insert(int num);
    bool remove(int num);
    float getLoad();
//private:
    int hash(int data);

    LLNode *table[1019] = {}; // Makes the table all nullptrs
    float load = 0;
    int tableSize = 1019; // Also in the .cpp file
    int occupied = 0;
};

class HashBST{
public:
    bool lookup(int);
    void insert(int);
    BSTNode* remove(BSTNode*, int);
    float getLoad();
//private:
    int hash(int);

    BSTNode *table[1019] = {};
    float load = 0;
    int occupied = 0;
    int tableSize = 1019;
};

class HashLP{
public:
    HashLP();
    bool lookup(int num);
    void insert(int num);
    bool remove(int num);
    float getLoad();
private:
    int hash(int data);

    int table[1019];
    float load = 0;
    int occupied = 0;
    int tableSize = 1019;   // Given table size for the project
    int stepSize = 1;       // Step size is 1 for linear probing here
};

class HashCuckoo{
public:
    HashCuckoo();
    bool lookup(int);
    void insert(int);
    void remove(int);
    float getLoad();
//private:
    int hash1(int);
    int hash2(int);
    void rehash(int);

    vector<int> table1;
    vector<int> table2;
    int occupied;
    float load;
    int tableSize;
    int rehashed;
    bool rehashingFlag = false, rehashCycleFlag = false;
};