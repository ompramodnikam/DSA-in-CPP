//Implimentation of Queue :

#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Queue
{
    private : 
        int iCount;
        PNODE First;

    public : 
        Queue();
        void Display();
        int Count();
        void EnQueue(int No);
        int DeQueue();
};

Queue :: Queue()
{
    First = NULL;
    iCount = 0;
}

void Queue :: Display()
{
    PNODE temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp ->next;
    }
    cout<<endl;
}

int Queue :: Count()
{
    return iCount;
}

void Queue :: EnQueue(int No)
{
    PNODE newn = NULL;
    newn = new node;

    PNODE temp = NULL;
    
    newn ->data = No;
    newn ->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp ->next = newn;
    }
    iCount++;
}

int Queue :: DeQueue()
{
    PNODE temp = NULL;
    int iDelete = 0;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
    }
    else if(First ->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        iDelete = temp->data;
        delete temp;
    }
    iCount--;
    return iDelete;
}

int main()
{
    Queue obj;

    int iValue = 0;
    int iRet = 0;

    //EnQueue : 
    obj.EnQueue(10);
    obj.EnQueue(20);
    obj.EnQueue(30);
    obj.EnQueue(40);
    obj.EnQueue(50);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of elements int Queue is : "<<iRet<<endl;

    obj.DeQueue();
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of elements int Queue is : "<<iRet<<endl;

    return 0;
}