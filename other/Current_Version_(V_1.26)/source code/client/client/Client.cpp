# include <windows.h>
# include <fstream>
# include <iomanip>
# include <time.h>
# include <iterator>
# include "Element.h"
# include "Element.cpp"


int prompt(int &flag);
void populate(vector<vector<element> > &orderedByTag);
void addElement(vector<vector<element> > &orderedByTag);
void sortElement(vector<vector<element> > &orderedByTag,element repair);
void removeTag(vector<vector<element> > &orderedByTag, bool &found);
void removeElement(vector<vector<element> > &orderedByTag, bool &found);
void updateElement(vector<vector<element> > &orderedByTag, bool &found);
void viewTagHistory(vector<vector<element> > orderedByTag);
void viewTagRecentAdd(vector<vector<element> > orderedByTag);
void viewOpenRepairs(vector<vector<element> > orderedByTag);
void traverseVector(vector<vector<element> > orderedByTag);
void sendToServer(vector<vector<element> > orderedByTag);
void writeToFile(vector<vector<element> > orderedByTag,int &flag);
void clearVector(vector<vector<element> > &orderedByTag);
int sync();
int delay(int millisec);
void inUse();
void set_color(int color);

int main()
{  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int selection;
	vector<vector<element> > orderedByTag;
	int flag;
	bool found;
	//change to a GUI format here//
	

	cout << endl << right << setw(25) << " " << "Welcome to the Inventory Proccessing System" << left << setw(25) << " " << endl;
	
	
	selection=prompt(flag);
	while (selection)
	{
		switch (selection)
		{
		case 1: if (flag==0)
				{
					inUse();
					clearVector(orderedByTag);
					populate(orderedByTag);
					addElement(orderedByTag);
                    sendToServer(orderedByTag);
				}
				else
				{	set_color(12);	
                    cout <<"You do not have permission to add repairs at this time.\n\nPlease try again momentarily"<< endl << endl;
                }
			    selection=prompt(flag);
			    break;
		
		case 2: if (flag==0)
		     	{
					inUse();
					clearVector(orderedByTag);
			     	populate(orderedByTag);
				    removeTag(orderedByTag,found);
				    if(found)
					   sendToServer(orderedByTag);
		            
		               
			    } 
			    else
				{	
                    set_color(12);
                    cout <<"You do not have permission to remove a service tag at this time.\n\nPlease try again momentarily" << endl << endl;
                }
				selection=prompt(flag);
				break;

		case 3:	if (flag==0)
				{
					inUse();
					clearVector(orderedByTag);
					populate(orderedByTag);
					removeElement(orderedByTag,found);
					if(found)
					    sendToServer(orderedByTag);
				}
				else
				{
                    set_color(14);
					cout <<"You do not have permission to remove a repair at this time.\n\nPlease try again momentarily" << endl << endl;
                }
				selection=prompt(flag);
				break;

		case 4: if (flag==0)
				{
					inUse();
					clearVector(orderedByTag);
					populate(orderedByTag);
					updateElement(orderedByTag,found);
					if(found)
                       sendToServer(orderedByTag);
				}
				else
				{
                    set_color(12);
					cout <<"You do not have permission to remove a repair at this time.\n\nPlease try again momentarily" << endl << endl;
                }
				selection=prompt(flag);
				break;

		case 5: 
				if(flag==0)
				{
                    set_color(5);
					cout << "This is the most current information available" << endl;
                }
				else
				{
                    set_color(14);
					cout << "The database is currently being updated.\n\nThis information is from the last successful save" << endl;
                }
				clearVector(orderedByTag);
                populate(orderedByTag);
                viewTagHistory(orderedByTag);
				selection=prompt(flag);
				break;

		case 6: 
				if(flag==0)
				{
                    set_color(5);
					cout << "This is the most current information available" << endl;
                }
  				else
  				{
                    set_color(14);
					cout << "The database is currently being updated.\n\nThis information is from the last successful save" << endl;
                }
				clearVector(orderedByTag);
                populate(orderedByTag);
                viewTagRecentAdd(orderedByTag);
				selection=prompt(flag);
				break;

		case 7: 
				if(flag==0)
				{
                    set_color(5);       
                   	cout << "This is the most current information available" << endl;
                }
				else
				{
                    set_color(14);
					cout << "The database is currently being updated.\n\nThis information is from the last successful save" << endl;
                }
				clearVector(orderedByTag);
                populate(orderedByTag);
                viewOpenRepairs(orderedByTag);
				selection=prompt(flag);
				break;

		case 8:
				if(flag==0)
				{
                    set_color(5);       
					cout << "This is the most current information available" << endl;
                }
				else
				{
                    set_color(14);
					cout << "The database is currently being updated.\n\nThis information is from the last successful save" << endl;
                }
				clearVector(orderedByTag);
                populate(orderedByTag);
                traverseVector(orderedByTag);
				selection=prompt(flag);
				break;

		default:
			selection=prompt(flag);
		}
	}
return 0;
}

	int prompt(int &flag)
	{
		ifstream inFile("InUseFlag.txt");
		inFile >> flag;
		inFile.close(); 
		int response;
		set_color(14);
		cout << "Please make a selection" << endl << endl;
		set_color(7);
		cout << "(1) Add a new repair " << endl;
		set_color(8);
		cout << "(2) Remove a service Tag " << endl;
		set_color(7);
		cout << "(3) Remove a repair " << endl;
		set_color(8);
		cout << "(4) Update a repair " << endl;
		set_color(7);
		cout << "(5) View a service tag's history " << endl;
		set_color(8);
		cout << "(6) View the most recent repair for a service tag " << endl;
		set_color(7);
		cout << "(7) View Open repairs " << endl;
		set_color(14);
		cout << "(0) EXIT" << endl;
		set_color(8);
		cin >> response;
		return response;
		//return GUI();
	}

	void populate(vector<vector<element> > &orderedByTag)
	{
		element repair;
		string text,part,name;
		char c[9];
		char tester;
    	ifstream inFile("MasterTextFile.txt");
		inFile.ignore(2);
		inFile >> tester;
		while (tester=='{')
		{
		inFile.ignore(1);
		inFile >> repair.serviceTag;
		inFile.ignore(2);
		inFile >> text;
		repair.transferLaptopModel(text);
		inFile.ignore(1);
		inFile >> text;
		repair.transferLaptopName(text);
		inFile.ignore(1);
		inFile >> text;
		repair.transferWarrantyStateDate(text);
		inFile.ignore(1);
		inFile >> text;
		repair.transferWarrantyEndDate(text);
		inFile.ignore(3);
		inFile >> c;
		repair.transferDateEntered(c);
		inFile.ignore(1);
		inFile >> repair.currentLocation;
		inFile.ignore(1);
		inFile >> text;
		repair.transferDispatchNumber(text);
		inFile.ignore(1);
		inFile >> text;
		repair.transferCaseNumber(text);
		inFile.ignore(1);
		inFile >> repair.callInTime;
		inFile.ignore(1);
		inFile >> repair.callOutTime;
		inFile.ignore(1);		
		getline(inFile,text);
		repair.transferTechName(text);
		inFile.ignore(2);
		getline(inFile,repair.partsAffected);
		inFile.ignore(2);
        getline(inFile,repair.techNotes);
	//	cout << endl ;
	//	repair.displayAll();
        sortElement(orderedByTag,repair);
		inFile.ignore(13);
		inFile >> tester;
	}
		inFile.close();
	}

void addElement(vector<vector<element> > &orderedByTag)
{//prompt for info
	element repair;
	int selection;
	char answer1;
	char answer2='y';
	do
	{
			repair.setAll();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~testing filling of data~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			cout << endl;
			repair.displayAll();
			set_color(12);
			cout << endl<< endl <<"Does any of the information need to be corrected? (y or n)" << endl;
			set_color(8);
			cin >> answer1;
			while(answer1=='y'||answer1=='Y')
			{set_color(14);
				cout << "Please make a selection" << endl;
				set_color(7);
				cout << "(1) service tag" << endl;
				set_color(8);
				cout << "(2) model number" << endl;
				set_color(7);
				cout << "(3) laptop name" << endl;
				set_color(8);
				cout << "(4) laptop namestarting date of the warranty(xx/xx/xxxx)" << endl;
				set_color(7);
				cout << "(5) ending date of the warranty(xx/xx/xxxx)" << endl;
				set_color(8);
				cout << "(6) current location" << endl;
				set_color(7);
				cout << "(7) technician's name" << endl;
				set_color(8);
				cout << "(8) change date entered to the current date" << endl;
				set_color(7);
				cout << "(9) dispatch number" << endl;
				set_color(8);
				cout << "(10) case number" << endl;
				set_color(7);
				cout << "(11) call in time" << endl;
				set_color(8);
				cout << "(12) call out time" << endl;
				set_color(7);
				cout << "(13) parts affected" << endl;
				set_color(8);
				cout << "(14) notes" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:	repair.setTag();
					break;
				case 2:	repair.setModel();
					break;
				case 3:	repair.setLaptopName();
					break;
				case 4:	repair.setStartDate();
					break;
				case 5:	repair.setEndDate();
					break;
				case 6: repair.setLocation();
					break;
				case 7:	repair.setTechName();
					break;
				case 8:	repair.setDateEntered();
					break;
				case 9:	repair.setDispatchNumber();
					break;
				case 10: repair.setCaseNumber();
					break;
				case 11: repair.setCallInTime();
					break;
				case 12: repair.setCallOutTime();
					break;
				case 13: repair.setPartsAffected();
					break;
				case 14: repair.setTechNotes();
					break;
				case 0:
				default:
					break;
				}
				repair.displayAll();
				set_color(12);
				cout << endl << endl << "Does any of the information need to be corrected? (y or n)" << endl;
				set_color(8);
				cin >> answer1;
			}				
	sortElement(orderedByTag,repair);
	set_color(12);
	cout << endl << "Would you like to add another repair? (y or n) " << endl;
	set_color(8);
	cin >> answer2;
	}while(answer2=='y'||answer2=='Y');
}

void sortElement(vector<vector<element> > &orderedByTag,element repair)
{
/*Begins the search for the right place in the vector to add the repair. 
Starts at the begining of the vector. Searchs for the right place to insert the repair's data. 
Exits if a service tag is equal to or larger than the repair or if it reaches the end of the vector. 
Checking that i is less than the length ensures that there isn't a comparison outside of the subscripts of the vector.*/
	int i=0,j=0;
	int length=static_cast<int>(orderedByTag.size());
	if (orderedByTag.empty())
	{
		orderedByTag.resize(orderedByTag.size()+1);
        orderedByTag[0].push_back(repair);
	}
	else 
	{
		while((i<length) && orderedByTag[i][0].serviceTag<repair.serviceTag)
		{
			i++;
		}
/*if i has not reach the end then the service tag is equal to or smaller than a service tag already in the vector*/
		if (i!=length)
		{
/*if the service tag is found, searches for the right place in the embedded vector to add the repair*/
			if (orderedByTag[i][0].serviceTag==repair.serviceTag)
			{
				length=static_cast<int>(orderedByTag[i].size());
				orderedByTag[i].push_back(repair);				
			}
/*In this case  So the vector is resized to add in the service Tag. From the back of the vector the data is moved until the subscript i is reached; the 
subscript i where the new repair is added.*/	
			else
			{
				length=static_cast<int>(orderedByTag.size());
				orderedByTag.resize(length+1);
				for(j=length;j>i;j--)
				{	
					orderedByTag[j].resize(0);
					for(int k=0;k<static_cast<int>(orderedByTag[j-1].size());k++)
					{
						orderedByTag[j].push_back(orderedByTag[j-1][k]);
					}
				}
				orderedByTag[i].resize(0);
				orderedByTag[i].push_back(repair);
			}
		}
		else 
		{
/*In this case the service tag is not found. The vector is then resized and the new repair is added to the back.*/
			orderedByTag.resize(length+1);
			orderedByTag[length].push_back(repair);		
		}
	}
}


	void removeTag(vector<vector<element> > &orderedByTag,bool &found)
	{
		char repeat;
		int first;
		int last;
		int mid;
		string target;
	
		do
		{
			
		last=static_cast<int>(orderedByTag.size());
		first=0;

        set_color(14);
		cout << endl <<"Please enter the service tag " << endl;
		set_color(8);
		cin >> target;

		while (first<last)
		{
			mid=(first+last)/2;
			if (orderedByTag[mid][0].serviceTag <target)
				first=mid+1;
			else if(orderedByTag[mid][0].serviceTag>target)
				last=mid;
			else
				break;
		}
		if (orderedByTag[mid][0].serviceTag!=target)
		{
            set_color(12);
        	cout << endl <<"This service tag is not valid or does not have a repair history" << endl;
        	found=false;
         }
		else
		{
            found=true;
			int	length=static_cast<int>(orderedByTag.size());
			for(int i=mid;i<length-1;i++)
			{	
					orderedByTag[i].resize(0);
					for(int j=0;j<static_cast<int>(orderedByTag[i+1].size());j++)
						orderedByTag[i].push_back(orderedByTag[i+1][j]);
			}
			orderedByTag.pop_back();			
		}
		set_color(14);
		cout << "Would you like to remove another service tag? (y or n)" << endl;
		set_color(8);
		cin >> repeat;
	}while(repeat=='y'||repeat=='Y');
	}


	void removeElement(vector<vector<element> > &orderedByTag,bool &found)
	{	
		char repeat,response;

		int first;
		int last;
		int mid;
		string target;

		
		do
		{
			
		last=static_cast<int>(orderedByTag.size());
		first=0;

        set_color(14);
		cout << endl <<"Please enter the service tag " << endl;
		set_color(8);
		cin >> target;

		while (first<last)
		{
			mid=(first+last)/2;
			if (orderedByTag[mid][0].serviceTag <target)
				first=mid+1;
			else if(orderedByTag[mid][0].serviceTag>target)
				last=mid;
			else
				break;
		}
		if (orderedByTag[mid][0].serviceTag!=target)
		{
           set_color(12);                                         
           cout << endl <<"This service tag is not valid or does not have a repair history" << endl;
           set_color(8);
           found=false;
        }
		else
		{
            found=true;
			for(int i=0;i<static_cast<int>(orderedByTag[mid].size());i++)
				{
					orderedByTag[mid][i].displayAll();
					set_color(12);
					cout << "Delete this repair? (y or n)" << endl;
					set_color(8);
					cin >> response;
					if(response=='y'||response=='Y')
					{
						orderedByTag[mid].erase(orderedByTag[mid].begin()+i);
						i--;
					}
				}			
		}
		set_color(12);	
		cout << "Would you like to remove another record from a different service tag? (y or n)" << endl;
		set_color(8);
		cin >> repeat;
		}while(repeat=='y'||repeat=='Y');
	}

	

	
	void updateElement(vector<vector<element> > &orderedByTag,bool &found)//assumes that updating is for the most recent record only
	{
		char repeat;
		char answer;
		int selection;
		int first;
		int last;
		int mid;
		string target;

		
		do
		{
		last=static_cast<int>(orderedByTag.size());
		first=0;

		cout << endl <<"Please enter the service tag " << endl;
		set_color(8);
		cin >> target;

		while (first<last)
		{
			mid=(first+last)/2;
			if (orderedByTag[mid][0].serviceTag <target)
				first=mid+1;
			else if(orderedByTag[mid][0].serviceTag>target)
				last=mid;
			else
				break;
		}
		if (orderedByTag[mid][0].serviceTag!=target)
		{
		   set_color(12);
           cout << endl <<"This service tag is not valid or does not have a repair history" << endl;
           found=false;
        }
		else
		{
		    found=true;	
			int	length=static_cast<int>(orderedByTag[mid].size());
			do
			{
				cout << "Please make a selection" << endl;
				set_color(7);
				cout << "(1) service tag" << endl;
				set_color(8);
				cout << "(2) model number" << endl;
				set_color(7);
				cout << "(3) laptop name" << endl;
				set_color(8);
				cout << "(4) starting date of the warranty(xx/xx/xxxx)" << endl;
				set_color(7);
				cout << "(5) ending date of the warranty(xx/xx/xxxx)" << endl;
				set_color(8);
				cout << "(6) current location" << endl;
				set_color(7);
				cout << "(7) technician's name" << endl;
				set_color(8);
				cout << "(8) change date entered to the current date" << endl;
				set_color(7);
				cout << "(9) dispatch number" << endl;
				set_color(8);
				cout << "(10) case number" << endl;
				set_color(7);
				cout << "(11) call in time" << endl;
				set_color(8);
				cout << "(12) call out time" << endl;
				set_color(7);
				cout << "(13) parts affected" << endl;
				set_color(8);
				cout << "(14) notes" << endl;
				cin >> selection;
				
				switch (selection)
				{
					case 1:	orderedByTag[mid][length-1].setTag();
							break;
					case 2:	orderedByTag[mid][length-1].setModel();
							break;
					case 3:	orderedByTag[mid][length-1].setLaptopName();
							break;
					case 4:	orderedByTag[mid][length-1].setStartDate();
							break;
					case 5:	orderedByTag[mid][length-1].setEndDate();
							break;
					case 6: orderedByTag[mid][length-1].setLocation();
							break;
					case 7:	orderedByTag[mid][length-1].setTechName();
							break;
					case 8:	orderedByTag[mid][length-1].setDateEntered();
							break;
					case 9:	orderedByTag[mid][length-1].setDispatchNumber();
							break;
					case 10: orderedByTag[mid][length-1].setCaseNumber();
							break;
					case 11: orderedByTag[mid][length-1].setCallInTime();
							break;
					case 12: orderedByTag[mid][length-1].setCallOutTime();
							break;
					case 13: getchar();
                             orderedByTag[mid][length-1].setPartsAffected();
							break;
					case 14: getchar(); 
                            orderedByTag[mid][length-1].setTechNotes();
							break;
					default:
							break;
				}
			orderedByTag[mid][length-1].displayAll();
			set_color(12);
			cout << "Would you like to update any other information for this record? (y or n)" << endl;
			set_color(8);
			cin >> answer;
		}while(	answer=='y'||answer=='Y');
		}
		set_color(12);
		cout << "Would you like to update a other record? (y or n)" << endl;
		set_color(8);
		cin >> repeat;
	}while(repeat=='y'||repeat=='Y');
	}

void viewTagHistory(vector<vector<element> > orderedByTag)
{
	int first=0;
	int last=static_cast<int>(orderedByTag.size());
	int mid; 
	string target;
    set_color(14);
	cout << endl << "Please enter the service tag " << endl;
	cin >> target;

	while (first<last)
	{
		mid=(first+last)/2;
		if (orderedByTag[mid][0].serviceTag <target)
			first=mid+1;
		else if(orderedByTag[mid][0].serviceTag>target)
			last=mid;
		else
			break;
	}
if (orderedByTag[mid][0].serviceTag!=target)
{   
    set_color(12);
	cout << endl << "This service tag is not valid or does not have a repair history" << endl;
}
else
{
	set_color(8);
	cout << endl << right << setw(30) << " "<< "HISTORY FOR " << target << left<< setw(30) <<" "<< endl;
	orderedByTag[mid][0].displayOne();
	cout << endl;
	for (int j=0;j<static_cast<int>(orderedByTag[mid].size());j++)
	{
		orderedByTag[mid][j].displayTwo();
		cout << endl;
	}
}
}


void viewTagRecentAdd(vector<vector<element> > orderedByTag)
{
	int first=0;
	int last=static_cast<int>(orderedByTag.size());
	int mid;
	string target;

	set_color(14);
	cout << endl <<"Please enter the service tag " << endl;
	cin >> target;

	while (first<last)
	{
		mid=(first+last)/2;
		if (orderedByTag[mid][0].serviceTag <target)
			first=mid+1;
		else if(orderedByTag[mid][0].serviceTag>target)
			last=mid;
		else
			break;
	}
	if (orderedByTag[mid][0].serviceTag!=target)
	{
		set_color(12);
		cout << endl <<"This service tag is not valid or does not have a repair history" << endl;
    }
	else
	{
		set_color(8);
		int	length=static_cast<int>(orderedByTag[mid].size());
		cout << endl << right << setw(30) << " "<< "MOST RECENT REPAIR FOR " << target << left<< setw(30) <<" "<< endl;
		set_color(10);
		orderedByTag[mid][length-1].displayAll();
	}
}

void viewOpenRepairs(vector<vector<element> > orderedByTag)
{
	unsigned int i;
	unsigned int length=orderedByTag.size();
	set_color(8);
	cout << endl << right << setw(30) << " "<<"LIST OF OPEN REPAIRS" << left<< setw(30) <<" "<<endl;
	for (i=0;i<length;i++)
	{set_color(10);
		if(orderedByTag[i][orderedByTag[i].size()-1].currentLocation!="Circulation")
		{
			cout << endl;
			orderedByTag[i][orderedByTag[i].size()-1].displayAll();
			cout << endl;
		}
}
}

void traverseVector(vector<vector<element> > orderedByTag)//for testing , possible for "show all repair history"
{
	set_color(8);
	cout<<"Testing traversing the vector"<< endl;
unsigned int i,j;
set_color(10);
for(i=0;i<orderedByTag.size();i++)
	for(j=0;j<orderedByTag[i].size();j++)
	{//cout << "index 1: " <<i <<"index 2: " <<j;//testing
	//	cout << endl;
		orderedByTag[i][j].displayAll();		
	//	orderedByTag[i][j].getTag();
	//	orderedByTag[i][j].getLocation();
	//	orderedByTag[i][j].getDateEntered();
	//	orderedByTag[i][j].getTechNotes();
		cout << endl;
	}
}
bool inuse()
{
int in=-1;
ifstream myfile ("InUseFlag.txt");
myfile>>in;
myfile.close();
if(in==1)
return true;
else return false;

}
void set_useflag()
{
ofstream myfile ("InUseFlag.txt");
myfile<<0;
myfile.close();
}
void set_sucflag()
{
ofstream myfile ("SuccessFlag.txt");
myfile<<0;
myfile.close();
}
void sendToServer(vector<vector<element> > orderedByTag)
{
int flag;
         //set success flag
         set_sucflag();
         //populate temptext
         
         writeToFile(orderedByTag,flag);
         //set OPtext to "!"
	
	while (flag==-1)
	{
		writeToFile(orderedByTag,flag);
	}
	if (flag)
	{
		set_color(3);
		cout << "The save was successful." << endl<<endl;
	}
	else
	{
        set_color(12);
		cout << "The server is unavailable. Please try again momentarily" << endl;
    }
         
set_useflag();
}

void writeToFile(vector<vector<element> > orderedByTag,int &flag)
{
	ofstream outFile("TempText.txt");
	outFile << "!" << endl;
    string text;
	for (int i=0;i<static_cast<int>(orderedByTag.size());i++)
	{
		for(int j=0;j<static_cast<int>(orderedByTag[i].size());j++)
		{
			outFile << "{ " << orderedByTag[i][j].serviceTag << endl;
			outFile << "( " ;
			orderedByTag[i][j].writeLaptopModel(text);
			outFile << text << " " ;
			orderedByTag[i][j].writeLaptopName(text);
			outFile << text << " " ;
			orderedByTag[i][j].writeWarrantyStateDate(text);
			outFile << text << " " ;
			orderedByTag[i][j].writeWarrantyEndDate(text);
			outFile	<< text << " " << endl;
			outFile << "[ ";
			orderedByTag[i][j].writeDateEntered(text);
			outFile << text << " " ;
			outFile << orderedByTag[i][j].currentLocation << " " ; 
			orderedByTag[i][j].writeDispatchNumber(text);
			outFile << text << " " ;
			orderedByTag[i][j].writeCaseNumber(text);
			outFile << text << " " ;
			outFile << orderedByTag[i][j].callInTime <<" " << orderedByTag[i][j].callOutTime<<" ";
			orderedByTag[i][j].writeTechName(text);
			outFile << text << " "<< endl;
			outFile << "< " << orderedByTag[i][j].partsAffected << endl ;
			outFile << "# " << orderedByTag[i][j].techNotes << endl;
			outFile << "& " << endl;
			outFile << "> " << endl;
			outFile << "] " << endl; 
			outFile << ") " << endl;
			outFile << "} " << endl << endl;
		}
	}
	outFile << "-" << endl;
	outFile.close();
	flag=sync();
}

int is_succ()
{
	int flag=7;
	ifstream inFile;
		inFile.open("SuccessFlag.txt");
		//getline(inFile,flag);
        inFile>>flag;
		inFile.close();
		return flag;
		/*if(flag==0)
			return 0;
		else if(flag=="1")
			return 1;
		else if(flag=="-1")
			return -1;
		else return 3;
		*/



}
/*int sync()
{
	ofstream outFile("OpText.txt");
	outFile << "!" << endl;
	outFile.close();
	
	//send message for server to change flag--0 while working(checking and updating),-1 error, 1 success.
	ifstream inFile("SuccessFlag.txt");
	int flag,i=0;
	inFile >> flag;
	inFile.close();
	while (flag==0 && i<50)
	{
		i++;
		delay(500); //how long of a wait?? 10sec??
		inFile.open("SucessFlag.txt");
		inFile >> flag;
		cout<<"flag: "<<flag<<endl;
		inFile.close();
		
	}
return flag;
}*/

int sync()
{
	ofstream outFile("OpText.txt");
	outFile << "!" << endl;
	outFile.close();
	
	//send message for server to change flag--0 while working(checking and updating),-1 error, 1 success.
	int flag,i=0;
	while (i<50)
	{
		i++;
		delay(500); //how long of a wait?? 10sec??
		flag=is_succ();
		if(flag==1)
			break;
	}
return flag;
}

int delay(int millisec)
{
clock_t timesec;

timesec = clock();

while((clock() - timesec) < millisec)
{
}

return millisec;

}

void inUse()
{
ofstream outFile("InUseFlag.txt");
outFile << 1;       
outFile.close();          
}

void clearVector(vector<vector<element> > &orderedByTag)
{    
     orderedByTag.resize(0);
}

void set_color(int color)
{
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hConsole, color);   
   
}
