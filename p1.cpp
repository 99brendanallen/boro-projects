// Brendan Allen
// CSCI130-001
// Spring 2020
// Program 1
// Converting Fahrenheit to Celsius
// Did this with no help

#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	float celsius; 	// value for degrees in Celsius
	float fahrenheit; // value for degrees in Fahrenheit
	
	// Get input value from user
	cout <<endl;
	cout <<"Enter Fahrenheit temperature: ";
	cin >> fahrenheit;
	
	// perform calculations
	celsius = (fahrenheit - 32.0) * (5.0/9.0);
	
	//output results to the screen
	cout << setprecision(2) << fixed << showpoint;
	cout << "Celsius= " << celsius <<endl<<endl;;
	
	return 0;

}