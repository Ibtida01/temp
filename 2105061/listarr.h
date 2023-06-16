#ifndef LISTARR_H
#define LISTARR_H
#include<iostream>
#include "listarr.h"
using namespace std;
class lst
{
    int currentsz=0;
    int* listarr;
    int curpos=0;
    int sz;
public:
    void print();
    void init(int,int);
    void insrt(int);
    int rmv();
    void moveToStart();
    void moveToEnd();
    void prev();
    void nxt();
    int length();
    int currPos();
    void moveToPos(int);
    int getValue();
};

#endif // LISTARR_H
