#include <radc++.h>
#include <string>
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>
#include "template.h"
using namespace std;

Form form1("Library Inventory Processing System (LIPS)");
ImageBox ibox(AUTO_ID,0,0,0,150,150,form1); //2nd arg : 0 = no image by default
ProgressBar pgb1(-1,160,20,200, 20,form1,RCP_HORIZONTAL); //horizontal
Label       lbl("Capacity of Server",AUTO_ID,160,0,120,20,form1);
Button Button3("Current status of data files", AUTO_ID, 10, 160, 100, 50, form1);
Button Button4("Reset all files (except Server Data and Backups)", AUTO_ID, 10, 220, 100, 60, form1);
Menu menu(form1);
MenuItem __File,__Exit,__Help,__About,__STServer,__ENDServer,__DEBUG,__BACKUP,__CURRSTAT,__RESET;

bool look_cap(string name)
{
     bool is_cap=false;
    int temp=0;
    string tmp;
     ifstream myfile (name.c_str());
     while(!myfile.eof())
     {
     getline(myfile,tmp);
     temp++;
     }
     myfile.close();
     if(temp>=95000)
     is_cap=true;
return is_cap;
}
void check_corr()
{
     format fm;
     vector<string> test; 
     string tmp;
     ifstream myfile ("MasterTextFile.txt");
     while(!myfile.eof())
     {
     getline(myfile,tmp);
     test.push_back(tmp);
     }
     myfile.close();
     if(!fm.is_right(test))
     form1.msgBox("CORRUPTION of MasterTextFile detected.");
     else
     form1.msgBox("No Corruption detected in MasterTextFile.");     
}

void check_cap()
{
     string temp;
     if(look_cap("MasterTextFile.txt")==true)
     temp="MasterTextFile.txt: ERROR FOUND. Capasity close or is exeeding txt file limit. \n";
     else
     temp="MasterTextFile.txt: no errors found. \n";
     if(look_cap("InUseFlag.txt"))
          temp+="InUseFlag.txt: ERROR FOUND. Capasity close or is exeeding txt file limit. \n";
     else
     temp+="InUseFlag.txt: no errors found. \n";
     if(look_cap("SuccessFlag.txt"))
          temp+="SuccessFlag.txt: ERROR FOUND. Capasity close or is exeeding txt file limit. \n";
     else
     temp+="SuccessFlag.txt: no errors found. \n";
     if(look_cap("TempText.txt"))
          temp+="TempText.txt: ERROR FOUND. Capasity close or is exeeding txt file limit. \n";
     else
     temp+="TempText.txt: no errors found. \n";
     if(look_cap("OpText.txt"))
          temp+="OpText.txt: ERROR FOUND. Capasity close or is exeeding txt file limit. \n";
     else
     temp+="OpText.txt: no errors found. \n";
     if(look_cap("server_cmds.txt"))
          temp+="server_cmds.txt: ERROR FOUND. Capasity close or is exeeding txt file limit. \n";
     else
     temp+="server_cmds.txt: no errors found. \n";
     
           
 form1.msgBox(temp);    
     
}


void stop()
{
     ofstream myfile ("server_cmds.txt");
     myfile<<"stop";
     myfile.close();     
}
void reset()
{
 ofstream USEflag ("InUseFlag.txt");//makes sure clients dont do anything while this is occuring
 USEflag<<1;
 USEflag.close();
 
 ofstream SUCflag ("SuccessFlag.txt");
 SUCflag<<0;
 SUCflag.close();     
 ofstream TEMflag ("TempText.txt");
 TEMflag<<"reset";
 TEMflag.close(); 
 ofstream CMDflag ("server_cmds.txt");
 CMDflag<<"reset";
 CMDflag.close(); 
 ofstream OPflag ("OpText.txt");
 OPflag<<"reset";
 OPflag.close();  
        
 ofstream USflag ("InUseFlag.txt");
 USflag<<0;
 USflag.close(); 
}
bool is_any_text()//checks to see if all .txt files are there. If not, prints out which ones are not there and exits server. If there, goes though rest of operations.
{
     string a;
     bool is_any=true;
     ifstream myfile("MasterTextFile.txt");
	if (myfile.is_open()) 
 {
   a="MasterTextFile.txt here: \n";
 }   
else {a+="ERROR: cannot access MASTER_DATABASE! Contact systems administrator! \n";
      is_any=false;}    
 myfile.close();
//**********************************
     ifstream fl("InUseFlag.txt");
	if (fl.is_open()) 
 {
   a+="InUseFlag.txt here: \n";
 }   
else {a+="ERROR: cannot access InUseFlag.txt! Contact systems administrator! \n";
      is_any=false;}    
 fl.close();     
//**********************************
     ifstream su("SuccessFlag.txt");
	if (su.is_open()) 
 {
   a+="SuccessFlag.txt here: \n";
 }   
else {a+="ERROR: cannot access SuccessFlag.txt! Contact systems administrator! \n";
      is_any=false;}    
 su.close();  
//**********************************
     ifstream temp("TempText.txt");
	if (temp.is_open()) 
 {
   a+="TempText.txt here: \n";
 }   
else {a+="ERROR: cannot access TempText.txt! Contact systems administrator! \n";
      is_any=false;}    
 temp.close();   
//**********************************
    ifstream op("OpText.txt");
    if (op.is_open())
    {
    a+="OpText.txt here \n";      
    }
else {a+="ERROR: cannot access OpText.txt! Contact systems administrator! \n";
is_any=false;}
op.close();
//**********************************
    ifstream ser("server_cmds.txt");
    if (ser.is_open())
    {
                     a+="server_cmds.txt file here \n";      
    }
else {a+="ERROR: cannot access server_cmds.txt! Contact systems administrator! \n";
is_any=false;}
ser.close();

form1.msgBox(a);
return is_any;     
};

int MAST_CAP()//100,000 is capasity need to have it less than that so putting max_cap at 95,000
{
    double temp=0;
    string tmp;
     ifstream myfile ("MasterTextFile.txt");
     while(!myfile.eof())
     {
     getline(myfile,tmp);
     temp++;
     }
     myfile.close();
     
     temp=temp/95000;
     temp=temp*100;
     return temp;    
    
}

FormProcedure form1Proc(FormProcArgs) {

	ON_CLOSE() 	Application.close();
	ON_COMMAND_BY(__BACKUP){//BACKUP() in other versions
  string sys,temp;
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );//getting the time
  timeinfo = localtime ( &rawtime );
  temp=asctime(timeinfo);
  temp.erase(0, 4);
  
  for(int i=0;i<temp.size();i++)//sets it to a way that the computer can use via command line
{	if(temp[i]==' '||temp[i]==':')
		temp[i]='_';
}
temp=temp+".txt";
temp="\\"+temp;
temp.erase(0,0);
sys=("copy /A MasterTextFile.txt \BACKUP")+temp;//timestamp

string a;
a="Timestamp for MasterTextFile : \BACKUP"+temp;
system(sys.c_str());
             
			form1.msgBox(a); 
                            
                            }
                       
    ON_COMMAND_BY(__STServer){
                              
                              system("server-start.bat");
                              form1.infoBox("LIPS system Started");
                              }
    ON_COMMAND_BY(__ENDServer)
   {
    stop();
    form1.infoBox("LIPS system Stopped");                          
    }
	ON_COMMAND_BY(__Exit) Application.close();
	ON_COMMAND_BY(__About) 
           form1.infoBox("LIPS system created by: Michael and Jennifer \n GUI Created with: www.radcpp.com RAD C++ 2 distributed under license RCDL v2 (created and maintained by flaxweb.com).");
bool server_on=false;

ON_COMMAND_BY ( Button3 ) {
              if(is_any_text()){//text files have to be there to make other options available.              
              check_cap(); 
              check_corr();
              pgb1.percent=MAST_CAP();
              }
              
             string a="Done";
			form1.msgBox(a);
		}
ON_COMMAND_BY ( Button4 ) {
              reset();
             string a="Done";
			form1.msgBox(a);
		}

	return 0;
}

rad_main()
ibox.loadImage("http://fc05.deviantart.com/fs43/f/2009/131/b/c/LOGO_by_1HKO.jpg"); //LIPS logo 
		form1.procedure = form1Proc;
        //main menus
		__File = menu.add("&Server");
		__DEBUG = menu.add("&Debug");
		__Help = menu.add("&About");
		
               
        //sub-menus tracked	
         
        __STServer=__File.add("&Start Server",AUTO_ID);
	__ENDServer=__File.add("&Stop Server",AUTO_ID);
        __Exit = __File.add("E&xit",AUTO_ID); 
        __BACKUP = __DEBUG.add("&Backup Data");
	__About = __Help.add("&About",AUTO_ID);	 
		
rad_end()
