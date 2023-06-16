#ifndef NODE_H
#define NODE_H
#include<iostream>
#include "node.h"

using namespace std;
class node
{
    int data;
    node* nxt;
    node* head=NULL;
    int curpos;
    int currsz;
    //void traverseLL();
public:
    //temporary
    void traverseLL();
    //end here
    void init(int);
    void insrt(int);
    int rmv();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    int currPos();
    void moveToPos(int);
    int getValue();
};

#endif // NODE_H
