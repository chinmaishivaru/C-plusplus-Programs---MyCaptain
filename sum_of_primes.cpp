#include<iostream>
#include<iomanip>

using namespace std; 

int prime(int x)
{
   int check=1;
   for(int i=2;i<=x/2;i++) 
   {
      if(x%i==0)
      {
         check=0;
         break;
      }
   }
   return check;
}

int main()
{
   int n;
   cout<<"Enter a number: ";
   cin>>n;
   if(n<=0)
   {
       cout<<"Invalid!";
       exit(0);
   }
   else
    {
        for(int i=2;i<=n/2;i++)
        {
        if(prime(i)&&prime(n-i))
           cout<<n<<"="<<i<<"+"<<n-i<<endl;
        }
    }
   return 0;
}
