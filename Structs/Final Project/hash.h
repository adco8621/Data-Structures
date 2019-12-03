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

class HashLBST{
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