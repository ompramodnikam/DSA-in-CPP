//Implimentation of Singly Circular Linked List : 

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    private : 
        PNODE First;
        PNODE Last;
        int iCount;

    public :
        SinglyCL();
        void Display();
        int Count();
        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
        
};

SinglyCL :: SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void SinglyCL :: Display()
{
    do
    {
        cout<<"| "<<First->data<<" | -> ";
        First = First->next;

    }while(First != Last->next);

    cout<<endl;
}

int SinglyCL :: Count()
{
    return iCount;
}

void SinglyCL :: InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new node;
    newn ->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First ->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = newn;
    }
    iCount++;
}

void SinglyCL :: InsertLast(int No)
{
    PNODE newn = NULL;
    newn = new node;
    newn ->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First ->next = First;
    }
    else
    {
        Last->next = newn;
        newn->next = First;
        Last = newn;
    }
    iCount++;
}

void SinglyCL :: InsertAtPos(int No, int iPos)
{
    int i = 0;

    PNODE temp = NULL;
    PNODE newn = NULL;
    newn = new node; 

    newn ->data = No;
    newn ->next = NULL;

    int iLength = 0;
    iLength = Count();

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp ->next;
        }
        newn->next = temp->next;
        temp ->next = newn;

        iCount++;
    }
}

void SinglyCL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty.."<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}

void SinglyCL :: DeleteLast()
{
    PNODE temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty.."<<endl;
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        while(temp ->next != Last)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp ->next = First;
    }
    iCount--;
}

void SinglyCL :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iLength = 0;
    iLength = Count();

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1 ->next = temp2 ->next;
        delete temp2;

        iCount--;
    }
}

int main()
{
    SinglyCL obj;

    int iRet = 0;

    cout<<"--------------Implimentation of Singly Circular Linked List---------------"<<endl;

    //InsertFirst :
    cout<<"InsertFirst->"<<endl;
    obj.InsertFirst(50);
    obj.InsertFirst(40);
    obj.InsertFirst(30);
    obj.InsertFirst(20);
    obj.InsertFirst(10);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    //InsertLast : 
    cout<<"InsertLast->"<<endl;
    obj.InsertLast(60);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    //InsertAtPos :
    cout<<"InsertAtPos->"<<endl;
    obj.InsertAtPos(25,3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    //DeleteFirst :
    cout<<"DeleteFirst->"<<endl;
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    //DeleteLast :
    cout<<"DeleteLast->"<<endl;
    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    //DeleteAtPos :
    cout<<"DeleteAtPos->"<<endl;
    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    return 0;
}