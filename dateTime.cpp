//C++ program to display date and time 

#include <iostream>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;

int main(){

	cout<<"********1st Way to Print Date And Time*******"<<endl;
	// Declaring argument for time()
	time_t tim;

	//Declaring variable to store return value of localtime()
	struct tm* ti;

	//applying time 
	time( &tim);

	// use local time of PC
	ti = localtime( &tim);

	cout<<"Day Date & Time: "<<asctime(ti)<<endl;
	cout<<"********2nd Way to Print Date And Time*******"<<endl;

	// declaring argument of time
	time_t my_time = time(NULL);

	// ctime is used to give present time
	cout<<"Day Date & Time: "<<ctime( &my_time)<<endl;
	cout<<"********3rd Way to Print Date And Time*******"<<endl;

	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
	cout<<"Day Date & Time: "<<ctime( &timenow)<<endl;

	cout<<"*********************************************"<<endl;

	return 0;
}