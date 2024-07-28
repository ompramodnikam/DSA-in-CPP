#include<iostream>
using namespace std;

class Demo
{
    public:
        int i;

    private:
        int j;
    
    protected:
        int k;
    
    public:
        Demo()
        {
            i = 10;
            j = 20; 
            k = 30;
        }
};

int main()
{
    Demo obj;
    cout<<obj.i;
    cout<<obj.j;
    cout<<obj.k;
    return 0;
}