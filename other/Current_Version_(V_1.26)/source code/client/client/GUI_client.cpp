#include <windows.h>
#include <iostream>
using namespace std;

int USERPICK()
{
     int a;
     cin >> a;
     system("cls");
return a;
}

void set_color(int color)
{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole, color);   
    
}
int GUI()//creates small GUI for user 
{
 system("cls");//clears the screen
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  
 set_color(15);//white text
 cout << "Welcome to the Henrey Madden Library Inventory Processing System (LIPS)"<<endl;
 set_color(12);
 cout << "==========================================================================="<<endl;   
set_color(14);//yellow text   
 cout << "Please make a selection:"<<endl<<endl;

 cout <<"1)";
set_color(15);//reset to white
 cout <<"Add a new repair"<<endl<<endl;
 
set_color(14);//yellow text 
 cout<<"2)";  
 set_color(15);//reset to white
 cout <<"Remove a Service Tag"<<endl<<endl;
 
 set_color(14);//yellow text 
 cout<<"3)";  
 set_color(15);//reset to white
 cout <<"Remove a repair"<<endl<<endl;
 
 set_color(14);//yellow text 
 cout<<"4)";  
 set_color(15);//reset to white
 cout <<"Update a repair"<<endl<<endl;
 
  set_color(14);//yellow text 
 cout<<"5)";  
 set_color(15);//reset to white
 cout <<"View a Service Tag's history"<<endl<<endl;
 
  set_color(14);//yellow text 
 cout<<"6)";  
 set_color(15);//reset to white
 cout <<"View most recent repair for a Service Tag"<<endl<<endl;
 
  set_color(14);//yellow text 
 cout<<"7)";  
 set_color(15);//reset to white
 cout <<"View Open repairs"<<endl<<endl;

  set_color(14);//yellow text 
 cout<<"0)";  
 set_color(15);//reset to white
 cout <<"Exit"<<endl<<endl; 
 
 set_color(15);
 cout << "==========================================================================="<<endl;   

cout <<": ";

     return USERPICK();
}

