#include<stdio.h>
#include<string.h>
#include <ctype.h> 


void stringConcat(char str1[], char str2[]){
	char str3[10];
	char str4[10];
	strcpy(str3, str1);
	strcpy(str4, str2);
	strcat(str3, str4);
	printf("\nStrings after concatination: %s",str3);
}

void stringCmp(char str1[], char str2[]){
	if (strcmp(str1, str2)==0)
		printf("\nStrings are equal");

	else
		printf("\nStrings are unequal");
}

void stringcpy(char str1[], char str2[]){
	
	char str3[10];
	char str4[10];
	strcpy(str3, str1);
	strcpy(str4, str2);
	strcpy(str3, str4);
	printf("\nAfter copy string %s into %s, string %s is: %s", str2, str1, str1, str3);
}
void stringLen(char str1[], char str2[]){
	
	int len1, len2;

	len1 = strlen(str1);
	len2 = strlen(str2);
	
	printf("\nLength of string %s is: %d",str1, len1);
	printf("\nLength of string %s is: %d",str2, len2);

}

void stringUpper(char str1[], char str2[]){
	int i = 0;
	char str3[10];
	char str4[10];
	strcpy(str3, str1);
	strcpy(str4, str2);

	while(str3[i] != '\0'){
		char ch = str3[i];
		if( ch >=97 && ch <= 122)
			ch = ch - 32;

		str3[i] = ch;
		i++;
	}
	printf("\n %s in upper case represented as : %s ",str1, str3);
	
	i = 0;
	while(str4[i] != '\0'){
		char ch = str4[i];
		if( ch >=97 && ch <= 122)
			ch = ch - 32;

		str4[i] = ch;
		i++;
	}
	printf("\n %s in upper case represented as : %s ",str2, str4);
}

void stringLower(char str1[], char str2[]){
	
	int i = 0;
	char str3[10];
	char str4[10];
	strcpy(str3, str1);
	strcpy(str4, str2);

	while(str3[i] != '\0'){
		char ch = str3[i];
		if( ch >=65 && ch <= 90)
			ch = ch + 32;

		str3[i] = ch;
		i++;
	}
	printf("\n %s in lower case represented as : %s ",str1, str3);
	
	i = 0;
	while(str4[i] != '\0'){
		char ch = str4[i];
		if( ch >=65 && ch <= 90)
			ch = ch + 32;

		str4[i] = ch;
		i++;
	}
	
	printf("\n %s in lower case represented as : %s ",str2, str4);
}

void main()
{
	char str1[10], str2[10];

	printf("\nEnter 1st String: ");
	scanf("%s", str1);
	printf("\nEnter 2nd String: ");
	scanf("%s", str2);

	stringConcat(str1, str2);
	stringCmp(str1, str2);
	stringcpy(str1, str2);
	stringLen(str1, str2);
	stringUpper(str1, str2);
	stringLower(str1, str2);
	printf("\n");
}
