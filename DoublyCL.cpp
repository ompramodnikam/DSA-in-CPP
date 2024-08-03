//Implimentation of Doubly Circular Linked List :

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private : 
        PNODE First;
        PNODE Last;
        int iCount;
    
    public :
        DoublyCL();
        void Display();
        int Count();
        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void DoublyCL :: Display()
{
    do
    {
        cout<<"| "<<First->data<<" | -> ";
        First = First->next;
    } while (First != Last->next);   

    cout<<endl;
}

int DoublyCL :: Count()
{
    return iCount;
}

void DoublyCL :: InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new node;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First->next = newn;
        First->prev = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
        First->prev = Last;
        Last->next = First;
    }
    iCount++;
}

void DoublyCL :: InsertLast(int No)
{
    PNODE newn = NULL;
    newn = new node;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        First->next = newn;
        First->prev = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
        newn->next = First;
        First->prev = Last;
    }
    iCount++;
}

void DoublyCL :: InsertAtPos(int No, int iPos)
{
    int i = 0;
    int iLength = 0;
    iLength = Count();

    PNODE temp = NULL;

    PNODE newn = NULL;
    newn = new node;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

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
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
        iCount++;
    }
}

void DoublyCL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }

    iCount--;
}

void DoublyCL :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

void DoublyCL :: DeleteAtPos(int iPos)
{
    int i = 0;
    int iLength = 0;

    iLength = Count();

    PNODE temp = NULL;

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
        temp = First;

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyCL obj;

    int iRet = 0;

    cout<<"--------------Implimentation of Doubly Circular Linked List---------------"<<endl;

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