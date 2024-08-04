// Insertion Sorting : 

#include<iostream>
using namespace std;

class InsertionSorting
{
    private :   
        int iSize;
        int *Arr;
    
    public : 
        InsertionSorting(int A);
        ~InsertionSorting();
        void Accept();
        void Display();
        void InsertionSort();
};

InsertionSorting :: InsertionSorting(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
}

InsertionSorting :: ~InsertionSorting()
{
    delete []Arr;
}

void InsertionSorting :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

void InsertionSorting :: Display()
{
    int i = 0;

    cout<<"Entered elements are : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}

void InsertionSorting :: InsertionSort()
{
    int i = 0;
    int key = 0;
    int j = 0;

    for(i = 1 ; i < iSize ; i++)
    {
        key = Arr[i];
        j = i - 1;

        while((j >= 0) && (Arr[j] > key))
        {
            Arr[j+1] = Arr[j];
            j = j-1;
        }
        Arr[j+1] = key;
    }
}

int main()
{
    int iLength = 0;

    cout<<"Enter the total elements of Array : "<<endl;
    cin>>iLength;

    InsertionSorting *obj = new InsertionSorting(iLength);

    obj->Accept();
    cout<<"Elements before sorting ->"<<endl;
    obj->Display();
    
    obj->InsertionSort();
    cout<<"Elements after sorting ->"<<endl;
    obj->Display();


    return 0;
}