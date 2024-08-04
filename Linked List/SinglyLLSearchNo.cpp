// Search Number : 

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
        bool SearchNo(int No);
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

bool SinglyLL :: SearchNo(int No)
{
    bool bFlag = false;
    PNODE temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }
    return bFlag;
}

int main()
{
    SinglyLL obj;

    bool bRet = false;

    obj.InsertFirst(50);
    obj.InsertFirst(40);
    obj.InsertFirst(30);
    obj.InsertFirst(20);
    obj.InsertFirst(10);
    obj.Display();
    bRet = obj.SearchNo(31);
    
    if(bRet = true)
    {
        cout<<"Number is present in the Linked List"<<endl;
    }
    else
    {
        cout<<"Number is not present in the Linked List"<<endl;
    }

    return 0;
}