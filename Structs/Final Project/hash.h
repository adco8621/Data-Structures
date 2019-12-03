#include <vector>

struct LLNode{
    int data;
    LLNode *next;
};

strcut BSTNode{
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