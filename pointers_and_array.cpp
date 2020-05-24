#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    int arr[5];
    int *p;
    p=arr;
    cout<<"Enter Elements: ";
    for(int i=0;i<5;i++)
    cin>>*(p+i);
    cout<<"You Entered: ";
    for(int i=0;i<5;i++)
    {
        cout<<*(p+i);
        cout<<endl;
    }
    return 0;
}
