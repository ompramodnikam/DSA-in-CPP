//Display Middle element : 

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
        int MiddleElement();
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

int SinglyLL :: MiddleElement()
{
    int iCount = 0;
    int iPos = 0;

    PNODE temp = NULL;
    temp = First;
    
    while(temp != NULL)
    {
        temp = temp->next;
        iCount++;
    }

    iPos = iCount/2;

    for(int i = 1 ; i <= iPos ; i++)
    {
        First = First->next;
    }
    return First->data;

}

int main()
{
    SinglyLL obj;

    int iRet = 0;

    obj.InsertFirst(50);
    obj.InsertFirst(40);
    obj.InsertFirst(30);
    obj.InsertFirst(20);
    obj.InsertFirst(10);
    obj.Display();
    iRet = obj.MiddleElement();
    
    cout<<"Middle element in the Linked List is : "<<iRet<<endl;

    return 0;
}