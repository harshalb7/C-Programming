#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

void concatination(string str1, string str2){
	cout<<endl;
	string str3 = str1 + str2;
	cout<<"Concatination of Stings "<<str1<<" & "<<str2<<" is: "<<str3;
	cout<<endl;
}

void stringLength(string str1, string str2){
	cout<<"\nLength of string "<<str1<<" is: "<<str1.length()<<endl;
	cout<<"\nLength of string "<<str2<<" is: "<<str2.length()<<endl;

}
void stringUpper(string str1, string str2){
	cout<<"\nUpper Case of string "<<str1<<" is:";
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	cout<<str1<<endl;

	cout<<"\nUpper Case of string "<<str2<<" is:";
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	cout<<str2<<endl;
}
void stringLower(string str1, string str2){

	cout<<"\nLower Case of string "<<str1<<" is:";
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	cout<<str1<<endl;

	cout<<"\nLower Case of string "<<str2<<" is:";
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	cout<<str2<<endl;
}

void reverseString(string str1, string str2){
	
	cout<<"\nReverse of string "<<str1;
	reverse(str1.begin(), str1.end());
	cout<<" is:"<<str1<<endl;

	cout<<"\nReverse of string "<<str2<<" is:";
	reverse(str2.begin(), str2.end());
	cout<<str2<<endl;

}
void postionString(string str1, string str2){
	string s1, s2;
	cout <<"\nEnter word to find in string "<<str1<<" : ";
	cin>>s1;

	int pos = str1.find(s1);
	cout<<endl<<s1<<" is found in string "<<str1<<" at postion : "<<pos+1<<endl;
}
int main()
{
	string str1, str2;
	cout<<"\nEnter 1st String: ";
	cin>>str1;
	cout<<"\nEnter 2nd String: ";
	cin>>str2;

	concatination(str1, str2);
	stringLength(str1, str2);
	stringUpper(str1, str2);
	stringLower(str1, str2);
	reverseString(str1, str2);
	postionString(str1, str2);

	return 0;
}