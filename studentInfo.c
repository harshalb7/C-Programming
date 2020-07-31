#include<stdio.h>
#include<string.h>
struct studentInfo
{
	int rollNo,std;
	long int PRN,phoneNo;
	char name[10],homeTown[10];
	char gender;
};

void getInfo(struct studentInfo *sI1, int no){

	for(int i = 0; i < no; i++){

		printf("\nEnter Roll Number: ");
		scanf("%d", &sI1->rollNo);
		//printf("\n%d", sI1->rollNo);
		printf("\nEnter Name: ");
		scanf(" %s", sI1->name);
		printf("\nEnter Gender: ");
		scanf("%s", &sI1->gender);
		printf("\nEnter PRN Number: ");
		scanf("%ld", &sI1->PRN);
		printf("\nEnter Phone Number: ");
		scanf("%ld", &sI1->phoneNo);
		printf("\nEnter Home Town: ");
		scanf("%s", sI1->homeTown);

		sI1++;
	}
}

void displayInfo(struct studentInfo *sI1, int no){
	for( int i = 0; i< no; i++){
		printf("\n\t %d \t %s \t %c \t %ld \t %ld \t %s \t", sI1->rollNo, sI1->name, sI1->gender, sI1->PRN, sI1->phoneNo, sI1->homeTown);
		sI1++;
	}
}
int main(){
	int no;
	printf("\nEnter Number of Student: ");
	scanf("%d",&no);
	struct studentInfo sI1[10];

	
	getInfo(sI1, no);

	printf("\n\tRoll No\tName\tGender\tPRN\tPhone No\tHome Town");
	
	displayInfo(sI1, no);
	printf("\n");
	return 0;
}