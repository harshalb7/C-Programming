#include<iostream>
using namespace std;

float addition(float num1, float num2){
	return (num1 + num2);
}

float subtraction(float num1, float num2){
	return (num1 - num2);
}

float multiplication(float num1, float num2){
	return (num1 * num2);
}

float division(float num1, float num2){
	if(num2 != 0){
		return (num1/num2);
	}
	else
		return 0;
	}

int main(){
	float num1, num2;

	cout<<"Enter Numbers:"<<endl<<"Enter 1st Number: ";
	cin>>num1;
	cout<<"Enter 2nd Number: ";
	cin>>num2;

	float sum = addition(num1, num2);
	float sub = subtraction(num1, num2);
	float mul = multiplication(num1, num2);
	float div = division(num1, num2);

	cout<<"\nAddition is      : "<<sum;
	cout<<"\nSubtraction is   : "<<sub;
	cout<<"\nMultiplication is: "<<mul;
	if(div == 0)
		cout<<"\nDivision is      : Divide by ZERO error"<<endl;
	else
		cout<<"\nDivision is      : "<<div<<endl;

}