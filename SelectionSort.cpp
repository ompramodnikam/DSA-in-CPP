//Selection Sorting :

#include<iostream>
using namespace std;

class SelectionSorting
{
    private :   
        int iSize;
        int *Arr;
    
    public : 
        SelectionSorting(int A);
        ~SelectionSorting();
        void Accept();
        void Display();
        void SelectionSort();
};

SelectionSorting :: SelectionSorting(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
}

SelectionSorting :: ~SelectionSorting()
{
    delete []Arr;
}

void SelectionSorting :: Accept()
{
    int i = 0;

    cout<<"Enter the elements : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cin>>Arr[i];
    }
}

void SelectionSorting :: Display()
{
    int i = 0;

    cout<<"Entered elements are : "<<endl;
    for(i = 0 ; i < iSize ; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<endl;
}

void SelectionSorting :: SelectionSort()
{
    int i = 0;
    int j = 0;
    int min_index = 0;
    int temp = 0;

    for(i = 0 ; i < iSize ; i++)
    {
        min_index = i;

        for(j = i ; j < iSize ; j++)
        {
            if(Arr[min_index] > Arr[j])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

int main()
{
    int iLength = 0;

    cout<<"Enter the total elements of Array : "<<endl;
    cin>>iLength;

    SelectionSorting *obj = new SelectionSorting(iLength);

    obj->Accept();
    cout<<"Elements before sorting ->"<<endl;
    obj->Display();
    
    obj->SelectionSort();
    cout<<"Elements after sorting ->"<<endl;
    obj->Display();


    return 0;
}