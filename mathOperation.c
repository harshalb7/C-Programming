#include<stdio.h>

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
	if(num2 != 0)
		return (num1/num2);
	
	else
		return 0;
}
void main(){
	float num1, num2;

	printf("\nEnter Numbers");
	printf("\nEnter 1st Number: ");
	scanf("%f", &num1);
	printf("\nEnter 2nd Number: ");
	scanf("%f", &num2);

	float sum = addition(num1, num2);
	float sub = subtraction(num1, num2);
	float mul = multiplication(num1, num2);
	float div = division(num1, num2);

	printf("\nAddition is      : %f", sum);
	printf("\nSubtraction is   : %f", sub);
	printf("\nMultiplication is: %f", mul);
	printf("\nDivision is      : %f", div);
	if(div != 0)
		printf("\nDivision is      : %f", div);
	else
		printf("\nDivision is      : Divide by ZERO error");

	printf("\n");
}