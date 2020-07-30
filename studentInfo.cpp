#include<iostream>
#include<string.h>
#include <cstring>
using namespace std;
class studentInfo
{
	int rollNo,std;
	long int PRN,phoneNo;
	string name,homeTown;
	char gender;

public:
	studentInfo(){
		rollNo = 0;
		PRN = 0;
		phoneNo = 0;
		name = "";
		homeTown = "";
		gender = ' ';
	}

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

	void displayInfo(){
		cout<<"\n"<<"\t"<<rollNo<<"\t"<<name<<"\t"<<gender<<"\t"<<PRN<<"\t"<<phoneNo<<"\t"<<homeTown<<endl;
	}
};
int main(){
	int no;
	cout<<"\nEnter Number of Student: ";
	cin>>no;
	studentInfo sI[no];

	for(int i = 0; i < no; i++)
		sI[i].getInfo();

	cout<<"\n"<<"\t"<<"Roll No"<<"\t"<<"Name"<<"\t"<<"Gender"<<"\t"<<"PRN"<<"\t"<<"Phone No"<<"\t"<<"Home Town"<<endl;
	for( int i = 0; i< no; i++)
		sI[i].displayInfo();
	return 0;
}