#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int p = 0;

class busres
{
	public:
  char busn[10], driver[20], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
  void update();
  void date();
  void book();
  void empty();
  void book_details();
  void seat_details();
  void position(int i);
  void contact();
  void about();
}
bus[10];

void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}

void busres::update()
{
  vline('*');
  cout<<"\n\n\n\n\n";
  cout<<"BUS DETAILS:\n\t\tEnter the Bus Number: ";
  cin>>bus[p].busn;
  cout<<"\n\t\tEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\n\t\tArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\n\t\tDeparture: ";
  cin>>bus[p].depart;
  cout<<"\n\t\tFrom:\t";
  cin>>bus[p].from;
  cout<<"\t\tTo:\t";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
}

void busres::date()
{
  vline('*');
  cout<<"\n\n\n\n\n";
  int d,m,y;
  cout<<"Enter the date in the format dd-mm-yyyy: ";
    cin>>d>>m>>y;
    if(2020 <= y <= 3000)
        {
          if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>0&&d<=31)
          cout<<"Departure Date: "<<d<<" / "<<m<<" / "<<y<<"\n";
          else 
        if(m==4||m==6||m==9||m==11&&d>0&&d<=30)
            cout<<"Departure Date: "<<d<<" / "<<m<<" / "<<y<<"\n";
           else
            if(m==2)
               {
                 if((y%400==0||(y%100!=0&&y%4==0))&&d>0&&d<=29)
                  cout<<"Departure Date: "<<d<<" / "<<m<<" / "<<y<<"\n";
                  else if(d>0 && d<=28)
                    cout<<"Departure Date: "<<d<<" / "<<m<<" / "<<y<<"\n";
                  else
                    cout<<"It is Invalid";
               }
          else
               cout<<"It is Invalid";
        }
      else
      cout<<"Either you are in the past or very far future!";
}

void busres::book()
{
  vline('*');
  cout<<"\n\n\n\n\n";
  int seat;
  char number[5];
  again:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto again;
    }
  }

void busres::empty()
{
  for(int i=0; i<8;i++)
    for(int j=0;j<4;j++)
      strcpy(bus[p].seat[i][j], "Empty");
}

void busres::book_details()
{
  vline('*');
  cout<<"\n\n\n\n\n";
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('*');
  cout<<"Bus no: \t"<<bus[n].busn
  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int busres=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      busres++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(busres-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}

void busres::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }

void busres::seat_details()
{
  vline('*');
  cout<<"\n\n\n\n\n";
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"\nBus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"<<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
}

void busres::contact()
{
  vline('*');
  cout<<"\n\n\n\n\n";
  cout<<"\n\n\t\tMYCAPTAIN RESERVATION SYSTEM - CONTACT DETAILS\n\t\tOfficial Working hours: 10:00AM to 7:00PM.";
  cout<<"\n\t\tOur HQ: MyCap Building, C++ Division, Lavelle Road, Nearby IIM Bangalore, Bengaluru - 33.";
  cout<<"\n\t\tOur Customer Service is available from Monday - Friday during the working hours.";
  cout<<"Call Us at: 080-46689234\t\t/9778462743.\n\n";
  vline('_');
}

void busres::about()
{
  vline('*');
  cout<<"\n\n\n\n\n";
  cout<<"\n\n\t\tMYCAPTAIN RESERVATION SYSTEM - ABOUT\n\t\tThis is an Official Portal of MyCaptain Reservation Systems.";
  cout<<"\n\t\tA word from Aadhar, CEO of MyCap Solutions: Let life be a Memeful experience. Just don't make it cringy!";
  cout<<"\n\t\tMyCaptain is an expert in solution technologies developed by individuals of extreme talent and passion.\n"<<
  "It is a platform for easy Reservation of your wonderful trip to make it relaxing. Just enter here and forget about all your worries on your travelling!\nBecause, WE help you in reaching your DESTINATION, safe and sound!\n\n";
  vline('_');
}

int main()
{
//system("cls");
back:
int w;
while(1)
{
  //system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t1.Update Bus Database\n\t\t\t2.Reservation\n\t\t\t3.Booking Details\n\t\t\t4.Check Availability.\n\t\t\t5.About Us\n\t\t\t6.Contact Us\n\t\t\t7.Exit";
  cout<<"\n\t\t\tEnter your choice: ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].update();
      break;
    case 2:  bus[0].date();
              bus[p].book();
      break;
    case 3:  bus[0].book_details();
      break;
    case 4:  bus[0].seat_details();
      break;
    case 5: bus[0].about();
      break;
    case 6: bus[0].contact();
      break;
    case 7:  exit(0);
    default:cout<<"Invalid Option! Try again.";
  }
}
return 0;
}
