#include<iostream>
using namespace std;
class Tickets {
public:
    Tickets();
    void Journey(int startpoint,int endpoint);
    void Fare();
    int Getstartpoint(void);
    int Getendpoint(void);
    void Hotkey1();
    void Hotkey2();
    void Hotkey3();
    void Hotkey4();
    void Hotkey5();
    void Hotkey6();
    int startp;
    int endp;
};
Tickets :: Tickets()
{
}
void Tickets :: Journey(int startpoint,int endpoint)
{
    startp = startpoint;
    endp = endpoint;
}
int Tickets :: Getstartpoint()
{
    return(startp);
}
int Tickets :: Getendpoint()
{
    return(endp);
}
void Tickets :: Hotkey1()
{
    cout<<"Start Point = CSMT station(E)"<<"\n";
    cout<<"End Point = The Asiatic Society"<<"\n";
      cout<<"Reserved";
}

void Tickets :: Hotkey2()
{
    cout<<"Start Point = CSMT station"<<"\n";
    cout<<"End Point = Flora Fountain"<<"\n";
      cout<<"Reserved";
}

void Tickets :: Hotkey3()
{
    cout<<"Start Point = CSMT station"<<"\n";
    cout<<"End Point = Cross Maidan"<<"\n";
      cout<<"Reserved";
}

void Tickets :: Hotkey4()
{
    cout<<"Start Point = The Asiatic Society"<<"\n";
    cout<<"End Point = Flora Fountain"<<"\n";
      cout<<"Reserved";
}

void Tickets :: Hotkey5()
{
    cout<<"Start Point = The Asiatic Society"<<"\n";
    cout<<"End Point = Cross Maidan"<<"\n";
      cout<<"Reserved";
}

void Tickets :: Hotkey6()
{
    cout<<"Start Point = Flora Fountain"<<"\n";
    cout<<"End Point = Cross Maidan"<<"\n";
    cout<<"Reserved";
}
void Tickets :: Fare()
{
    cout<<"FARE PRICE :" << (endp-startp)*10<<"\n";
}
int main(){
   cout<<"**BUS TICKET**"<<endl;
   int x;
   Tickets t1;
   cout<<"Enter a Hot key: "<<"\n";
   cin>>x;

   if ( x == 1 )
 {
    t1.Hotkey1();
   cout<<"\n";
   t1.Journey(15,20);
   t1.Fare();
   cout<<"\n";
 }
 else if (x == 2 )
 {
     t1.Hotkey2();
     cout<<"\n";
     t1.Journey(15,30);
     t1.Fare();
     cout<<"\n";
 }
 else if ( x == 3 )
 {
     t1.Hotkey3();
     cout<<"\n";
     t1.Journey(15,40);
     t1.Fare();
     cout<<"\n";
 }
 else if ( x == 4 )
 {
     t1.Hotkey4();
     cout<<"\n";
     t1.Journey(20,30);
     t1.Fare();
     cout<<"\n";
 }
 else if ( x == 5 )
 {
     t1.Hotkey5();
     cout<<"\n";
     t1.Journey(20,40);
     t1.Fare();
     cout<<"\n";
 }
 else ( x == 6 );
 {
     t1.Hotkey6();
     cout<<"\n";
     t1.Journey(30,40);
     t1.Fare();
     cout<<"\n";
 }
 return 0;
}