#include<iostream>
#include<iomanip>

using namespace std;

class time
{
    public: int h,m,s,total;
    void second()
    {
        total=h*3600+m*60+s;
        cout<<"Time in total seconds: "<<total;
    }
};

int main()
{
    class time t;
    cout<<"Enter time:\nHours? ";
    cin>>t.h;
    cout<<"Minutes? ";
    cin>>t.m;
    cout<<"Seconds? ";
    cin>>t.s;
    cout<<"The time is = "<<setw(2)<<setfill('0')<<t.h<<":"<<setw(2)<<setfill('0')<<t.m<<":"<<setw(2)<<setfill('0')<<t.s<<endl;
    t.second();
    return 0;
}
