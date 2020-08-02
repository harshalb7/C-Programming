#include<iostream>
#include<string.h>
using namespace std;
bool checkLeap(int year, int month){
	if(month == 2 && year % 4 == 0)
			return true;
	else
		return false;
}

bool leapYear(int year, int month, int date){
	if(checkLeap(year, month) == true){
		if( date > 0 && date <= 29 )
			return true;
		else
			return false;
	}
	else{
		if( date > 0 && date < 29 )
			return true;
		else
			return false;
	}
}

bool checKDate(int date, int month, int year){
	if( year % 2 == 1){
		if(date > 0 && date <= 31 )
			return true;
		else
			return false;
	}
	else{
		if(date > 0 && date <= 30 )
			return true;
		else
			return false;
	}
}
void birthDate(){

	int yy, mm, dd, flag = 0;
	cout<<"\nEnter Year : ";
	cin>>yy;
	do{
		try{
			if( yy <= 999 || yy > 2999)
				throw(yy);
		}
		catch(int ){
			cout<<"\nEnter Year is Invalid..Re-Enter Year.";
			cout<<"\nEnter Year : ";
			cin>>yy;
		}
	}while( yy <= 999 || yy > 2999 );
	
	cout<<"\nEnter Month: ";
	cin>>mm;
	do{
		try{
			if( mm <= 0 || mm > 12 )
				throw(yy);
		}
		catch(int ){
			cout<<"\nEnter Month is Invalid..Re-Enter Month.";
			cout<<"\nEnter Month : ";
			cin>>mm;
		}
	}while( mm <= 0 || mm > 12 );
	cout<<"\nEnter Date : ";
	cin>>dd;
	do{
		try{
			if(mm != 2 ){
				if(checKDate(dd, mm, yy) == false){
					cout<<"\nEnter Date is Invalid..Re-Enter Date.";
					throw(dd);
				}
			}
			else{
				if(leapYear(yy, mm, dd) == false){
					cout<<"\nInvalid Date ..Leap Year...Re-Enter Date.";
					throw(dd);
				}
				else{
					if(leapYear(yy, mm, dd) == false){
						cout<<"\nEnter Date is Invalid..Re-Enter Date.";
						throw(dd);
					}
				}
			}
		}
		catch(int ){
			cout<<"\nEnter Date : ";
			cin>>dd;
		}
	}while(checKDate(dd, mm, yy) == false || leapYear(yy, mm, dd) == false);

	string dd1, mm1, yy1;

	if( dd < 10 )
		dd1 = '0'+ to_string(dd);
	else
		dd1 = to_string(dd);

	if( mm < 10 )
		mm1 = '0' + to_string(mm);
	else
		mm1 = to_string(mm);
	yy1 = to_string(yy);

	string date = dd1 + '-' + mm1 + '-' + yy1;
	
	cout<<"Date: "<<date<<endl;
}

int main(){
	birthDate();
	return 0;
}