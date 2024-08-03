//Impimentation of stack : 

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Stack
{
    private : 
        PNODE First;
        int iCount;

    public : 
        Stack();
        void Display();
        int Count();
        void Push(int No);
        int Pop();
};

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}
void Stack :: Display()
{
    PNODE temp = NULL;
    temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int Stack :: Count()
{
    return iCount;
}

void Stack :: Push(int No)
{
    PNODE newn = NULL;
    newn = new node;

    newn->data = No;
    newn->next = NULL;

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

int Stack :: Pop()//DeleteFirst()
{
    int Poped = 0;
    PNODE temp = NULL;
    
    if(First == NULL)
    {
        cout<<"Linked List is empty..."<<endl;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        Poped = First->data;
        First = First->next;
        delete temp;
    }
    iCount++;
    return Poped;
}

int main()
{
    Stack obj;

    int iRet = 0;
    int iPoped = 0;

    cout<<"----------Implimentation of Stack-------------"<<endl;
    
    //Push :
    cout<<"Push"<<endl;
    obj.Push(50);
    obj.Push(40);
    obj.Push(30);
    obj.Push(20);
    obj.Push(10);  
    obj.Display(); 
    iRet = obj.Count();
    cout<<"Total elements in stack are : "<<iRet<<endl;

    //Pop :
    iPoped = obj.Pop();
    obj.Display(); 
    iRet = obj.Count();
    cout<<"Poped element is : "<<iPoped<<endl;
    cout<<"Total elements in stack are : "<<iRet;

    return 0;
}