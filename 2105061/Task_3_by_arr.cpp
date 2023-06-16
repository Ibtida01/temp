#include <iostream>
#include "node.h"
#include "listarr.h"
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    lst* garages=(lst* )malloc((y+1)*sizeof(lst));
    int carCt,g;
    //Initializing for LL implementations
//    for(int i=0; i<y; i++)
//    {
//        cin>>g>>carCt;
//        garages[g-1].init(carCt);
//    }
    //This initialization is for array based implementation
    /*-------------------------------------------------------------------------------------------------*/
    for(int i=0;i<y;i++)
    {
        cin>>g>>carCt;
        garages[g].init(carCt,z);
    }
    /*--------------------------------------------------------------------------------------------------*/
    //all initialzed
    string  request;
    for(int i=1;i<=y;i++)
    {
        garages[i].print();
    }
    while(1)
    {
        cin>>request;
        if(request=="end")
            break;
        else if(request=="req")
        {
            //carRequisition
            int leastlabel;//least label of garage
            bool found=false;
            for(int i=1; i<=y; i++)
            {
                //finding the garage with least label
                if(garages[i].length()!=0)
                {
                    leastlabel=i;
                    found=true;
                    //the non empty garage with the least label has been found
                    break;
                }
            }
            //Now in the nonempty garage with the least label,we will search for the car available with least label
            if(found==false)
            {
                cout<<"no cars are available\n";
                continue;
            }
            int leastlabelC,curlabel;//current label of car in garage[leastlabel]

            //accessing garages[leastlabel]

            int pos;
            garages[leastlabel].moveToStart();
            leastlabelC=garages[leastlabel].getValue();
            pos=0;
            garages[leastlabel].nxt();
            while(garages[leastlabel].currPos()<garages[leastlabel].length())
            {
                curlabel=garages[leastlabel].getValue();
                if(curlabel<leastlabelC)
                {
                    leastlabelC=curlabel;
                    pos=garages[leastlabel].currPos();
                }

                garages[leastlabel].nxt();
            }
            garages[leastlabel].moveToPos(pos);
            garages[leastlabel].rmv();
            //Car Requisition completed
            //car requisitioned :car no #leastlabelC from garage# leastlabel

        }
        else if(request=="ret")
        {
            int carlabel;
            cin>>carlabel;
//            cout<<"car p : "<<p<<endl;//for debugging purposes ONLY
            int maxlabel=-1;
            bool found=false;
            for(int i=y; i>0; i--)
            {
                if(garages[i].length()<z)//Non empty
                {
                    maxlabel=i;
                    found=true;
                    break;
                }
            }
            if(found==false)
            {
                cout<<"all the garages are full\n";
                continue;
            }
            //else we have the non empty garage with the max label

            int pos=-1;
            int maxlabelC=-1,curlabel;//car with the max label
            garages[maxlabel].moveToStart();
            while(garages[maxlabel].currPos()<garages[maxlabel].length())
            {
                curlabel=garages[maxlabel].getValue();
                if(curlabel>maxlabelC)
                {
                    maxlabelC=curlabel;
                    pos=garages[maxlabel].currPos();
                }
                garages[maxlabel].nxt();
            }
            //car with the maxlabelC in the garage with the maxlabel has been found
            garages[maxlabel].moveToPos(pos);
            garages[maxlabel].nxt();//we are at the position after the car with max label
            garages[maxlabel].insrt(carlabel);

        }
        else
        {
            cout<<"INVALID SELECTION"<<endl;;
        }
        //Printing garage state
        for(int i=1;i<=y;i++)
        {
            garages[i].print();
        }
    }
    //OUTPUT
//    for(int i=0; i<y; i++)
//    {
//        garages[i].print();
//    }
}
