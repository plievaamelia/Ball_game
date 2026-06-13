#include <iostream>
using namespace std;

struct Node {
    int color;
    Node* prev;
    Node* next; 
    Node(int c); 
};

class DoubleLinkedList {
private:
    Node* head; 
    Node* tail;
    int size; 
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void push_back(int color);
    void removeNode(Node* node);
    int removeChains();
    int countChains() const; 
};
