// Count Frquency of element : 

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
        int CheakFrequency(int No);
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

int SinglyLL :: CheakFrequency(int No)
{
    int iCount = 0;
    PNODE temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        if(temp->data == No)
        {
            iCount++;
        }
        temp = temp->next;
    }
    return iCount;
}

int main()
{
    SinglyLL obj;

    int iRet = 0;

    obj.InsertFirst(40);
    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertFirst(31);
    obj.Display();
    iRet = obj.CheakFrequency(31);
    cout<<"Frequency of number is : "<<iRet<<endl;

    return 0;
}