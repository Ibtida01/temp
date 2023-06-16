Assignment 1
Author:Ibtida Bin Ahmed
Student ID#2105061
Task1:
ADT:(Linked list based list implemenetation)
    void traverseLL();
Call it to travarse the list and print it
    void init(int);
initially called to allocate memory and initialize,current position is set to 2
    void insrt(int item);
used to insert item at the current positon
    int rmv();
used to remove element from current position
    void moveToStart();
used to move the cursor to start
    void moveToEnd();
used to move the cursor to th end
    void prev();
used to move the cursor 1 step back,does nothing when at position 0
    void next();
used to move the cursor 1 step ahead,does nothing when at last position
    int length();
returns length(current) when called
    int currPos();
returns current position when called
    void moveToPos(int pos);
moves the cursor to the definite position "pos"
    int getValue();
returns the value just after the cursor (i.e. value at current position) 

(Array based list implementation)

    void print();
Call it to print the list
    void init(int);
initially called to allocate memory and initialize,current position is set to 2
    void insrt(int item);
used to insert item at the current positon
    int rmv();
used to remove element from current position
    void moveToStart();
used to move the cursor to start
    void moveToEnd();
used to move the cursor to th end
    void prev();
used to move the cursor 1 step back,does nothing when at position 0
    void next();
used to move the cursor 1 step ahead,does nothing when at last position
    int length();
returns length(current) when called
    int currPos();
returns current position when called
    void moveToPos(int pos);
moves the cursor to the definite position "pos"
    int getValue();
returns the value just after the cursor (i.e. value at current position) 

Task2:
for array based implementation:
input k and x
for linked list based implementation:
input k
clear()
makes the list empty
append(int item)
appends an item at the end of the list
Search(item)
searches the list for an item and returns the position where it is found ,if Not found ,returns -1


task3:
input x,y,z 
x=number of cars
y=number of garages
z=capacity of each garage
then y lines :
g CarCT a_1 a_2 a_3 .....a_p
... ... ...
where g is the garage no
CarCt is the # of cars in garage no g
a_i indicates the car label

purpose of the source files:
A1T1.cpp assignment 1 task1 using array
A1T1_LL.cpp assignment 1 task1 using LL
task_2.cpp and task_2_using_arr.cpp source code (driver code) for task 2 respectively by LL and array
task_3.cpp and task_3_using_arr.cpp source code (driver code) for task 3 respectively by LL and array
listarr.h contains all the declarartions of the class(for array based implementation)
node.h conatains all the declarartions of the class(for LL)
listarr.cpp conatains all the definitions of the functions aforementioned in the respective class
node.cpp contains all the definitions of the functions aforementioned in the respective class

