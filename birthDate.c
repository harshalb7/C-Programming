#include<stdio.h>
#include<stdbool.h>
int date;
int month;
int year;

int checkYear( int yy){
	int flag = 0;
	do{
		if( yy <= 999 || yy > 2999){
			printf("\nEnter Year is Invalid..Re-Enter Year.");
			flag = 1;
		}

		if(flag == 1){
			printf("\nEnter Year: ");
			scanf("%d", &yy);
		}
	}while( yy <= 999 || yy > 2999 );

	return yy;
}

int checkMonth(int mm){
	int flag = 0;
	do{
		if( mm <= 0 || mm > 12){
			printf("\nEnter Month is Invalid..Re-Enter Month.");
			flag = 1;
		}

		if(flag == 1){
			printf("\nEnter Month: ");
			scanf("%d", &mm);
		}
	}while( mm <= 0 || mm > 12 );

	return mm;
}

bool leapYear( int yy){
	if( yy % 2 == 0)
		return true;

	return false;
}

bool checkMdate( int mm){
	if( mm % 2 == 0)
		return false;
	return true;
}
bool checkDay( int dd, int mm, int yy){
	if( leapYear( yy) == true){
		if( mm == 2){
			if( dd < 0 || dd > 29)
				return false;
		}
		else{
			if( checkMdate( mm ) == true){
				if(dd <= 0 || dd > 31)
					return false;
			}
			else{
				if( dd <= 0 || dd > 30 )
					return false;
			}
		}
	}
	else{
		if(mm == 2){
			if( dd <= 0 || dd >=29)
				return false;
		}
		else{
			if( checkMdate( mm ) == false){
				if( dd <= 0 || dd > 30)
					return false;
			}
			else{
				if( dd <= 0 || dd > 31)
					return false;
			}
		}
	}

	return true;
}

int checkDate( int dd, int mm, int yy){
	int flag = 0;
	do{
		if( checkDay(date, month, year) == false){
			printf("\nEnter Month is Invalid..Re-Enter Month.");
			flag = 1;
		}
		if (flag == 1){
			printf("\nEnter Date: ");
			scanf("%d", &date);
		}
	}while(checkDay(date, month, year) == false);

	return dd;
}
void birthDate(){
	printf("\nEnter Year: ");
	scanf("%d", &year);
	year = checkYear(year);

	printf("\nEnter month: ");
	scanf("%d", &month);
	month = checkMonth(month);

	printf("\nEnter Date: ");
	scanf("%d", &date);
	date = checkDate(date, month, year);

	printf("\nBirth Date: %d-%d-%d", date, month, year);
}

int main( void ){
	birthDate();
	return 0;
}