#ifndef ELEMENT_H
#define ELEMENT_H
# include <iostream>
# include <string>
# include <vector>
using namespace std;

class element
{
//private variables
	string laptopModel;
	string warrantyStateDate;
	string warrantyEndDate;
	string laptopName;
	string techName;
	char dateEntered[9];
	string dispatchNumber;
	string caseNumber;
public:
//	element();
//	~element();
//public variables
	string currentLocation;
	string serviceTag;
	string callInTime;
	string callOutTime;
	string techNotes;
	string partsAffected;

//methods
	void setModel();
    void getModel();
	void setStartDate();
	void getStartDate();
	void setEndDate();
	void getEndDate();
	void setLaptopName();
	void getLaptopName();
	void setLocation();
	void getLocation();
	void setTag();
	void getTag();
	void setTechName();
	void getTechName();
	void setDateEntered();
	void getDateEntered();
	void setDispatchNumber();
	void getDispatchNumber();
	void setCaseNumber();
	void getCaseNumber();
	void setCallInTime();
	void getCallInTime();
	void setCallOutTime();
	void getCallOutTime();
	void setTechNotes();
	void getTechNotes();
	void setPartsAffected();
	void getPartsAffected();
	void setAll();
	void displayAll();
	void displayOne();
	void displayTwo();
	void transferLaptopModel(string text);
	void transferWarrantyStateDate(string text);
	void transferWarrantyEndDate(string text);
	void transferLaptopName(string text);
	void transferTechName(string text);
	void transferDateEntered(char text[9]);
	void transferDispatchNumber(string text);
	void transferCaseNumber(string text);
	void writeLaptopModel(string &text);
	void writeWarrantyStateDate(string &text);
	void writeWarrantyEndDate(string &text);
	void writeLaptopName(string &text);
	void writeTechName(string &text);
	void writeDateEntered(string &text);
	void writeDispatchNumber(string &text);
	void writeCaseNumber(string &text);
	
	
	
};
#endif
