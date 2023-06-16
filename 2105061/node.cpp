#include "node.h"
#include<iostream>
using namespace std;

void node::init(int k)
{
    if(k==0)
    {
        head=NULL;
        return;
    }
    int temp;
    node* prevnode;
    head=new node();
    cin>>temp;
    head->data=temp;
    head->nxt=NULL;
    prevnode=head;
    for(int i=2; i<=k; i++)
    {
        cin>>temp;
        node* tempnode=new node();
        prevnode->nxt=tempnode;
        tempnode->data=temp;
        tempnode->nxt=NULL;
        prevnode=tempnode;
    }
    currsz=k;
    curpos=2;//as set by ADT list example
    traverseLL();

}
void node::insrt(int item)
{
    if(head==NULL)
    {
        //this part is ONLY if the input part in init() is NOT DONE..otherwise it won't be executed
        head=new node();
        head->data=item;
        head->nxt=NULL;
        ++currsz;
        //traverseLL();
        return;
    }
    //else

    if(curpos==0)
    {
        node* newnode=new node();
        newnode->data=item;
        newnode->nxt=head;
        head=newnode;
        ++currsz;
        //traverseLL();
        return;
    }
    node* hd=head;
    for(int i=0; i<curpos-1; i++)
    {
        hd=hd->nxt;
    }
    //it stops before the previous node of the node just after the curpos(i.e --> (i) NODE1 --> | NODE2)
    node* tempnxt=hd->nxt;
    node* newnode=new node();
    hd->nxt=newnode;
    newnode->data=item;
    newnode->nxt=tempnxt;
    ++currsz;
    //traverseLL();
}
void node::traverseLL()
{
    node* hd=head;
    int i=0;
    cout<<"< ";
    while(hd!=NULL)
    {
        if(i==curpos)
            cout<<" | ";
        cout<<hd->data<<" ";
        hd=hd->nxt;
        ++i;
    }
    cout<<">\n";
}

int node::rmv()
{
    if(currsz==0)
    {
        cout<<"List is empty,nothing to remove\n";
       // traverseLL();
        return -1;
    }
    if(curpos>=currsz)
    {
        cout<<"Nothing to remove here\n";
        //traverseLL();
        return -1;
    }
    node* hd=head;
    if(curpos==0)
    {
        int tmp=head->data;
        head=hd->nxt;
        delete hd;
        --currsz;
        //traverseLL();
        return  tmp;
    }
    for(int i=0; i<curpos-1; i++)
    {
        hd=hd->nxt;
    }
    int nxtnode_data=(hd->nxt)->data;
    node* nxtnode_nxt=(hd->nxt)->nxt;
    delete hd->nxt;
    hd->nxt=nxtnode_nxt;
    --currsz;
//    traverseLL();
    return nxtnode_data;
}

void node::moveToStart()
{
    curpos=0;
    //traverseLL();
}
void node::moveToEnd()
{
    curpos=currsz-1;
   // traverseLL();
}
void node::next()
{
    if(curpos<currsz)
        ++curpos;
    //else do nothing
    //traverseLL();
}
void node::prev()
{
    if(curpos>0)
        --curpos;
    //else do nothing
    //traverseLL();
}
void node::moveToPos(int pos)
{
    if(pos>=0 && pos<=currsz)
        curpos=pos;
    //traverseLL();
}
int node::getValue()
{
    node* hd=head;
    for(int i=0; i<curpos; i++)
    {
        hd=hd->nxt;
    }
    //traverseLL();
    return hd->data;
}
int node::currPos()
{
    //traverseLL();
    return curpos;
}
int node::length()
{
   // traverseLL();
    return currsz;
}
