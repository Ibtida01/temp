#include<iostream>
#include "node.h"
using namespace std;
node list1;
void clr()
{
    list1.moveToStart();
    int len=list1.length();
    for(int i=0;i<len;i++)
    {
        list1.rmv();
    }
    list1.traverseLL();
}
void append(int item)
{
    int ini_pos_cursor=list1.currPos();//
    //marking the initial position of the cursor
    //so that we can get it back there after the appending is complete
    list1.moveToEnd();
    list1.next();
    list1.insrt(item);
    list1.moveToPos(ini_pos_cursor);
    list1.traverseLL();
}

int Search(int item)
{
    int i=1,len=list1.length(),x;
    int ini_pos_cursor=list1.currPos();
    list1.moveToStart();
    while(i<=len)
    {
        x=list1.getValue();
        if(x==item)
        {
            int curpos=list1.currPos();
            list1.moveToPos(ini_pos_cursor);
            list1.traverseLL();
            return curpos;
        }
        ++i;
        list1.next();
    }
    list1.traverseLL();
    return -1;
}
int main()
{
    int K,P;
    cin>>K;
    list1.init(K);
    int Q;
    while(1)
    {
        cin>>Q;
        if(Q==0)
        {
            break;
        }
        else if(Q==1)
        {
            clr();
        }
        else if(Q==2)
        {
            cin>>P;
            append(P);
        }
        else if(Q==3)
        {
            cin>>P;
            cout<<Search(P)<<endl;
        }
        else{
            cout<<"INVALID SELECTION\n";
        }
    }

}
