#include<iostream>

using namespace std;

int main()
{
	char name[20],cnty[20];
	int age;
	cout<<"Enter the country of origin of the Candidate : ";
	cin>>cnty;
	getchar();
	cout<<"\nEnter the name of Candidate : ";
	gets(name);
	cout<<"\nEnter the age of Candidate : ";
	cin>>age;
	cout<<"\n\nVerifying......\n\n";
	if(age>=18)
		cout<<name<<" is eligible for voting.\n";
	else cout<<name<<" is not eligible for voting because of underage.";
	return 0;
}
