//Bubble Sorting : 

#include<iostream>
using namespace std;

class BubbleSorting
{
    private :   
        int iSize;
        int *Arr;
    
    public : 
        BubbleSorting(int A);
        ~BubbleSorting();
        void Accept();
        void Display();
        void BubbleSort();
};

BubbleSorting :: BubbleSorting(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
}

BubbleSorting :: ~BubbleSorting()
{
    delete []Arr;
}

void BubbleSorting :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

void BubbleSorting :: Display()
{
    int i = 0;

    cout<<"Entered elements are : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}

void BubbleSorting :: BubbleSort()
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = 0 ; i < iSize ; i++)
    {
        for(j = 0 ; j < iSize-1-i ; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int iLength = 0;

    cout<<"Enter the total elements of Array : "<<endl;
    cin>>iLength;

    BubbleSorting *obj = new BubbleSorting(iLength);

    obj->Accept();
    cout<<"Elements before sorting ->"<<endl;
    obj->Display();
    
    obj->BubbleSort();
    cout<<"Elements after sorting ->"<<endl;
    obj->Display();


    return 0;
}