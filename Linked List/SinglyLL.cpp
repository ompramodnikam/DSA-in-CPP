//Implimentation of Singly Linear Linked List :

#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLL
{
    private :
        PNODE First;
        int iCount;

    public :
        SinglyLL();
        void Display();
        int Count();
        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

SinglyLL :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

void SinglyLL :: Display()
{
    PNODE temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL\n";
}

int SinglyLL :: Count()
{
    return iCount;
}

void SinglyLL :: InsertFirst(int No)
{
    PNODE newn = NULL;
    newn = new node;
    
    newn ->data = No;
    newn ->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void SinglyLL :: InsertLast(int No)
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

void SinglyLL :: InsertAtPos(int No, int iPos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iLength = 0;
    int i = 0;

    newn = new node;
    newn ->data = No;
    newn ->next = NULL;

    iLength = Count();

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

        for(i = 1 ; i < iPos-1 ; i++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

void SinglyLL :: DeleteFirst()
{    
    PNODE temp = NULL;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
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
        delete temp;
    }

    iCount--;
}

void SinglyLL :: DeleteLast()
{
    PNODE temp = NULL;

    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
        return;
    }
    else if(First ->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        
        while(temp ->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

void SinglyLL :: DeleteAtPos(int iPos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int iLength = 0;
    int i = 0;

    iLength = Count();

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
            temp1 = temp1 ->next;
        }

        temp2 = temp1 ->next;
        temp1 ->next = temp2->next;
        delete temp2;

        iCount--;
    }
}


int main()
{
    SinglyLL obj;

    int iRet = 0;

    cout<<"-----------Implimentation of Singly Linear Linked List--------------"<<endl;

    cout<<"InsertFirst ->"<<endl;
    obj.InsertFirst(40);
    obj.InsertFirst(30);
    obj.InsertFirst(20);
    obj.InsertFirst(10);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total nodes are : "<<iRet<<endl;

    cout<<"InsertLast ->"<<endl;
    obj.InsertLast(50);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total nodes are : "<<iRet<<endl;

    cout<<"InsertAtPos ->"<<endl;
    obj.InsertAtPos(25,3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total nodes are : "<<iRet<<endl;

    cout<<"DeleteFirst ->"<<endl;
    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Total nodes are : "<<iRet<<endl;

    cout<<"DeleteLast ->"<<endl;
    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Total nodes are : "<<iRet<<endl;

    cout<<"DeleteAtPos ->"<<endl;
    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout<<"Total nodes are : "<<iRet<<endl;

    return 0;
}