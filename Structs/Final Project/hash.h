#include <vector>
#include <string>

using namespace std;

struct LLNode{
    int data;
    LLNode *next;
};

struct BSTNode{
    int data;
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
};

class HashLL{
public:
    int lookup(int);
    int insert(int);
    int remove(int);
    int getLoad();
private:
    int hash(int);

    vector<LLNode> table;
    float load;
    int tableSize;
};

class HashBST{
public:
    bool lookup(int);
    void insert(int);
    void remove(int);
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
    int lookup(int);
    int insert(int);
    int remove(int);
    int getLoad();
private:
    int hash(int);

    int table[1019];
    float load;
    int tableSize;
};

class HashCuckoo{
public:
    int lookup(int);
    int insert(int);
    int remove(int);
    int getLoad();
private:
    int hash1(int);
    int hash2(int);

    vector<int> table1;
    vector<int> table2;
    float load;
    int tableSize;
};