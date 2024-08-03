// Last Occurence : 

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
        void SumDigits();
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

void SinglyLL :: SumDigits()
{
    int iSum = 0;
    int iDigit = 0;
    int iNo = 0;
    PNODE temp = NULL;
    temp = First;
    
    while(temp != NULL)
    {
        iNo = temp->data;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo/10;
        }
        cout<<"Sum of Digits of "<<temp->data<<" is : "<<iSum<<endl;
        iSum = 0;
        temp = temp->next;
    }
}

int main()
{
    SinglyLL obj;

    obj.InsertFirst(55);
    obj.InsertFirst(44);
    obj.InsertFirst(33);
    obj.InsertFirst(22);
    obj.InsertFirst(11);
    obj.Display();
    obj.SumDigits();

    return 0;
}