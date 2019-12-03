#include <vector>

struct LLNode{
    int data;
    LLNode *next;
};

struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;
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
}

class HashBST{
public:
    int lookup(int);
    int insert(int);
    int remove(int);
    int getLoad();
private:
    int hash(int);

    vector<BSTNode> table;
    float load;
    int tableSize;
}

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
}

class HashCuckoo{
public:
    int lookup(int);
    int insert(int);
    int remove(int);
    int getLoad();
private:
    int hash1(int);
    int hash1(int);

    vector<int> table1;
    vector<int> table2;
    float load;
    int tableSize;
}