#include<iostream>
#include<string.h>
#include <cstring>
using namespace std;

//declare class student info
class studentInfo
{
	// declaretion of variables
	int rollNo,std;   
	long int PRN,phoneNo;
	string name,homeTown;
	char gender;

public:
	// declaration of constructor with initilization of variables
	studentInfo(){
		rollNo = 0;
		PRN = 0;
		phoneNo = 0;
		name = "";
		homeTown = "";
		gender = ' ';
	}

	// getInfo function to input data
	void getInfo(){
		cout<<"\nEnter Roll Number: ";
		cin>>rollNo;
		cout<<"\nEnter Name: ";
		cin>>name;
		cout<<"\nEnter Gender: ";
		cin>>gender;
		cout<<"\nEnter PRN Number: ";
		cin>>PRN;
		cout<<"\nEnter Phone Number: ";
		cin>>phoneNo;
		cout<<"\nEnter Home Town: ";
		cin>>homeTown;
		
	}
	
	// displayInfo function to display data
	void displayInfo(){
		cout<<"\n"<<"\t"<<rollNo<<"\t"<<name<<"\t"<<gender<<"\t"<<PRN<<"\t"<<phoneNo<<"\t"<<homeTown<<endl;
	}
};
int main(){
	//variable to store number of data
	int no;
	
	//number of records store in 'no' variable
	cout<<"\nEnter Number of Student: ";
	cin>>no;
	
	//array of object declaration
	studentInfo sI[no];
	
	//get info for 'no' number of data
	for(int i = 0; i < no; i++)
		sI[i].getInfo();

	cout<<"\n"<<"\t"<<"Roll No"<<"\t"<<"Name"<<"\t"<<"Gender"<<"\t"<<"PRN"<<"\t"<<"Phone No"<<"\t"<<"Home Town"<<endl;
	for( int i = 0; i< no; i++)
		sI[i].displayInfo(); //print all data 
	return 0;
}
