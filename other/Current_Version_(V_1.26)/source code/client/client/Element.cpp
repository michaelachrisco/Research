# include "element.h"
# include <time.h>
# include <iomanip>


	
    void element::setModel()
	{
		cout << "Please enter the model number:"<<endl;
		cin >> laptopModel;
	}
    
	void element::getModel()
	{
		cout <<setw(25)<< left<< "LAPTOP MODEL"<<laptopModel << endl;
	}

	void element::setStartDate()
	{ 
		cout << "Please enter the starting date of the warranty(xx/xx/xxxx): " << endl ;
		cin >> warrantyStateDate;
	}
	
	void element::getStartDate()
	{
		cout << setw(25) << left<< "WARRANTY-STARTING DATE" <<warrantyStateDate << endl;
	}
	
	void element::setEndDate()
	{
		cout << "Please enter the ending date of the warranty (xx/xx/xxxx):" << endl ;
		cin >> warrantyEndDate;
	}
	
	void element::getEndDate()
	{
		cout << setw(25) << left<< "WARRANTY-ENDING DATE " << warrantyEndDate << endl;
	}
	
	void element::setLaptopName()
	{
		cout << "Please enter the laptop name:" << endl ;
		cin >>laptopName;
	}

	void element::getLaptopName()
	{
		cout << setw(25) << left<<"LAPTOP NAME " << laptopName << endl;
	
	}

	void element::setLocation()
	{cout <<"in fun set loc"<<endl;
		int selection;
		cout << "Please enter the current location."<<endl;
		cout<< "(1) Circulation" << endl;
		cout<< "(2) In storage " << endl ;
		cout<< "(3) With technician " << endl ;
		cin >> selection;
		switch (selection)
		{cout <<"in switch"<<endl;
		case 1: 
			currentLocation="Circulation";
			break;
		case 2:
			currentLocation="In storage ";
			break;
		case 3:
			currentLocation="With technician ";
			break;
		default:
			currentLocation="unknown";
		}

	}
	
	void element::getLocation()
	{
		cout <<setw(25) << left <<"CURRENT LOCATION "<< currentLocation << endl;
	}
	
	void element::setTag()
	{
		string tag1, tag2;
		do 
		{
		cout << "Please enter the service tag:" << endl ;
		cin >> tag1;
		cout << "Please reenter the service tag:" << endl ;
		cin >> tag2;
		if (tag1!=tag2)
			cout << "The in formation you have provided does not match." << endl ;
		if (tag1.size()<6)
			cout << "The serviced tag does not have the required length." << endl ;
		}while (tag1!=tag2||tag1.size()<6);
		
		serviceTag=tag1;
	}

	void element::getTag()
	{
		cout << setw(25) << left <<"SERVICE TAG" << serviceTag << endl;
	}

	void element::setTechName()
	{
		string first, last;
		cout << "Please enter the technician's name: " << endl ;
		cin >> first;
		cin >> last;
		techName=first+" "+last;
	}

	void element::getTechName()
	{
		cout << setw(25) <<left<< "TECHNICIAN NAME" << techName << endl;
	}

	void element::setDateEntered()
	{
       _strdate(dateEntered);
	}
	
	void element::getDateEntered()
	{
		cout << setw(25) << left << "DATE ENTERED" << dateEntered << endl;
	}

	
	void element::setDispatchNumber()
	{
		cout << "Please enter the dispatch number:" << endl ;
		cin >> dispatchNumber;
	}
	
	void element::getDispatchNumber()
	{
		cout << setw(25) << left<< "DISPATCH NUMBER" << dispatchNumber<< endl;
	}
	
	void element::setCaseNumber()
	{
		cout << "Please enter the case number:" << endl ;
		cin >> caseNumber;
	}

	void element::getCaseNumber()
	{
		cout << setw(25) << left<< "CASE NUMBER" << caseNumber<<endl;
	}

	void element::setCallInTime()
	{
		cout << "Please enter call in time:" << endl;
		cin >> callInTime;

	}
	void element::getCallInTime()
	{
		cout << setw(25) << left<< "CALL IN TIME" << callInTime << endl;
	}
	
	void element::setCallOutTime()
	{
		cout << "Please enter call out time:" << endl;
		cin >> callOutTime;
		getchar();
	}
	
	void element::getCallOutTime()
	{
		cout << setw(25) << left << "CALL OUT TIME"<< callOutTime << endl;
	}


	void element::setTechNotes()
	{
		string notes=" ";
		techNotes+=notes;
		cout << "Please enter notes: " << endl;
		getline(cin,notes);
		techNotes+=notes;
	}

	void element::getTechNotes()
	{
		cout << setw(25) << left << "NOTES" << techNotes << endl;
	}
	void element::setPartsAffected()
	{
		string part=" ";
		partsAffected+=part;
		cout << "Please enter the parts affected:" << endl ;
		getline(cin,part);
		partsAffected+=part;
	}

	void element::getPartsAffected()
	{
		cout << setw(25) << left<< "PARTS AFFECTED" << partsAffected << endl;
	}

	void element::setAll()
	{
	  	setTag();
		setModel();
    	setLaptopName();
		setStartDate();
		setEndDate();
		setLocation();
		setTechName();
		setDateEntered();
		setDispatchNumber();
		setCaseNumber();
		setCallInTime();
		setCallOutTime();
		setPartsAffected();
		setTechNotes();
	}
	void element::displayAll()
	{
		getTag();
		getModel();
        getLaptopName();
		getStartDate();
        getEndDate();
        getDateEntered();
		getLocation();        
        getDispatchNumber();
        getCaseNumber();
        getCallInTime();
        getCallOutTime();
		getTechName();
        getPartsAffected();
        getTechNotes();
	}

	void element::displayOne()
	{
		getModel();
		getLaptopName();
  	}

	void element::displayTwo()
	{	
		getStartDate();
        getEndDate();
		getDateEntered();
		getLocation();        
        getDispatchNumber();
        getCaseNumber();
        getCallInTime();
        getCallOutTime();
		getTechName();
        getPartsAffected();
        getTechNotes();
	}
void element:: transferLaptopModel(string text)
{
   laptopModel=text;
}

void element::transferWarrantyStateDate(string text)
{
    warrantyStateDate=text;
}

void element::transferWarrantyEndDate(string text)
{
	warrantyEndDate=text;
}

void element::transferLaptopName(string text)
{
	laptopName=text;
}

void element::transferTechName(string text)
{
	techName=text;
}

void element::transferDateEntered(char text[9])
{
	
	strcpy(dateEntered,text);
}

void element::transferDispatchNumber(string text)
{
	dispatchNumber=text;
}

void element::transferCaseNumber(string text)
{
	caseNumber=text;
}

void element:: writeLaptopModel(string &text)
{
   text=laptopModel;
}

void element::writeWarrantyStateDate(string &text)
{
   text=warrantyStateDate;
}

void element::writeWarrantyEndDate(string &text)
{
	text=warrantyEndDate;
}

void element::writeLaptopName(string &text)
{
	text=laptopName;
}

void element::writeTechName(string &text)
{
	text=techName;
}

void element::writeDateEntered(string &text)
{
	text=string(dateEntered);
}

void element::writeDispatchNumber(string &text)
{
	text=dispatchNumber;
}

void element::writeCaseNumber(string &text)
{
	text=caseNumber;
}


