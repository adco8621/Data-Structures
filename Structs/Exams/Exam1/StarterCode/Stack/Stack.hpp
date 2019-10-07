#ifndef STRINGMATCH
#define STRINGMATCH

class StackLL
{
  private:
    struct Node
    {
        char key;
        Node *next;
    };

    Node * stackHead;

  public:
    StackLL();
    ~StackLL();
    bool isEmpty();
    void push(char key);
    void pop();
    char peek();
};

#endif
