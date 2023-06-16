#include<iostream>
using namespace std;
class lst
{
    int currentsz=0;
    int* listarr;
    int curpos=0;
    int sz;
    void print();
public:
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
void lst::init(int K,int X)
{
    cout<<"initiating list...\n";
    listarr=(int* )malloc(X*sizeof(int));
    sz=X;
    int temp;
    for(int i=0; i<K; i++)
    {
        cin>>temp;
        insrt(temp);
    }
    //CHECK THIS ISSUE ...REVERSE INPUT ??
    //is the part below OK?
    moveToPos(2);
    print();
}
 void lst::insrt(int item)
 {
     if(currentsz+1>sz)
     {
         listarr=(int* )realloc(listarr,(2*sz*sizeof(int)));
         sz=sz*2;
     }
     for(int i=currentsz;i>curpos;i--)
     {
         listarr[i]=listarr[i-1];
         //left shifting
     }
     listarr[curpos]=item;
     ++currentsz;
     print();
 }

 int lst::rmv()
 {
     if(currentsz==0)
     {
         cout<<"error!list is empty\n";
         print();
         return -1;
     }
     if(curpos==currentsz)
     {
         cout<<"error!nothing to remove\n";
         print();
         return -1;
     }
     int retval=listarr[curpos];
     for(int i=curpos;i<=currentsz-2;i++)
     {
         listarr[i]=listarr[i+1];
     }
     --currentsz;
     print();
     return retval;
 }
 void lst::moveToStart()
 {
     curpos=0;
     print();
 }
 void lst::moveToEnd()
 {
     curpos=currentsz-1;
     print();
 }
 void lst::prev()
 {
     if(curpos>0)
        --curpos;
     //else do nothing
     print();
 }
 void lst::nxt()
 {
     if(curpos==currentsz)
     {
         //do nothing
         print();
         return;
     }
     //else
     ++curpos;
     print();
 }
 int lst::length()
 {
     print();
     return currentsz;
 }
 int lst::currPos()
 {
     print();
     return curpos;
 }
 void lst::moveToPos(int pos)
 {
     if(pos>=0 && pos<currentsz)
     {
         curpos=pos;
         print();
     }
     else{
        cout<<"Invalid position,out of bounds\n";
        print();
     }
 }
 int lst::getValue()
 {
     print();
     return listarr[curpos];
 }
 void lst::print()
 {
//     if(currentsz==0)
//     {
//         cout<<"< | >"<<endl;
//         return;
//     }
     cout<<"< ";
     for(int i=0;i<currentsz;i++)
     {
         if(i==curpos)
            cout<<" | ";
         cout<<listarr[i]<<" ";
     }
     cout<<" >"<<endl;
 }
int main()
{
    lst l1;
    int k,x;
    cin>>k>>x;
    l1.init(k,x);
    int Q,P;
    //is this part valid?from now on to next comment?
//    l1.moveToPos(2);
//    l1.print();
    while(1)
    {
        cin>>Q;
        if(Q==0)
            break;
        else if(Q==1)
        {
            cin>>P;
            l1.insrt(P);
        }
        else if(Q==2)
        {
           cout<<l1.rmv()<<endl;
        }
        else if(Q==3)
        {
            l1.moveToStart();
        }
        else if(Q==4)
        {
            l1.moveToEnd();
        }
        else if(Q==5)
        {
            l1.prev();
        }
        else if(Q==6)
        {
            l1.nxt();
        }
        else if(Q==7)
        {
            cout<<l1.length()<<endl;;
        }
        else if(Q==8)
        {
            cout<<l1.currPos()<<endl;
        }
        else if(Q==9)
        {
            cin>>P;
            l1.moveToPos(P);
        }
        else if(Q==10)
        {
            cout<<l1.getValue()<<endl;;
        }
        else
        {
            cout<<"INVALID SELECTION\n";
        }

    }

}

