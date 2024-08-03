//Implimentation of Doubly Linear Linked List :

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

class DoublyLL
{
    private :
        PNODE First;
        int iCount;

    public : 
        DoublyLL();
        void Display();
        int Count();
        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyLL :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLL :: Display()
{
    PNODE temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int DoublyLL :: Count()
{
    return iCount;
}

void DoublyLL :: InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new node;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void DoublyLL :: InsertLast(int No)
{
    PNODE newn = NULL;
    newn = new node;
    PNODE temp = NULL;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

void DoublyLL :: InsertAtPos(int No, int iPos)
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
    else if(iPos == (iLength+1))
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        for(i = 1 ; i < (iPos-1) ; i++)
        {
            temp = temp->next;
        }
        temp ->next->prev = newn;
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;

        iCount++;

    }

}

void DoublyLL :: DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    iCount--;
}

void DoublyLL :: DeleteLast()
{
    PNODE temp = NULL;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void DoublyLL :: DeleteAtPos(int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    int iLength = 0;
    iLength = Count();

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength+1)
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
    DoublyLL obj;

    int iRet = 0;

    cout<<"----------------Implimentation of Doubly Linear Linked List-----------------"<<endl;
    
    //InsertFirst :
    cout<<"InsertFirst->"<<endl;
    obj.InsertFirst(60);
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
    obj.InsertLast(70);
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
    cout<<"DeleteLast"<<endl;
    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    //DeleteAtPos :
    cout<<"DeleteAtPos"<<endl;
    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total number of nodes are : "<<iRet<<endl;

    return 0;
}