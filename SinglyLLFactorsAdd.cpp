// Factors Addition : 

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
        void AddFactors();
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

void SinglyLL :: AddFactors()
{
    int iSum = 0;
    int iNo = 0;
    int i = 0;

    PNODE temp = NULL;
    temp = First;
    
    while(temp != NULL)
    {
        iNo = temp->data;
        for(i = 1 ; i <=iNo/2 ; i++)
        {
            if(iNo % i == 0)
            {
                iSum = iSum + i;
            }
        }
        cout<<"Factor Addition of "<<temp->data<<" is : "<<iSum<<endl;
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
    obj.AddFactors();

    return 0;
}