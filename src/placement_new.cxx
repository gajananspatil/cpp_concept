#include <iostream>
#include <cstdlib>

class LinkedList;

class Node
{
    int num;
    Node *next;

public:
    Node( int no )
        :num(no)
    { }

    ~Node()
    {
        std::cout<< "Node destructor: "<<num <<std::endl;
    }

void * operator new ( size_t size )
{
    void *n = malloc ( size );
    return n;
}

void operator delete(void *ptr )
{
    free(ptr);
}

private:
    Node( const Node & );
    Node& operator=( const Node & );
};


int main()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(11);
    Node *n3 = new Node(12);
    Node *n4 = new Node(13);
    Node *n5 = new Node(14);
    Node *n6 = new Node(15);

    delete n1;
}

