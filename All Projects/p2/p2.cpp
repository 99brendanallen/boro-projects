/* Brendan Allen
   CSCI130-001
   Spring 2020
   Program 2
   Calculating the cost for the caterer 
   Asked discussion board about calculating tip
*/


// All the c++ library's needed for the program to run correctly
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;
int main(void)
{
	//delare variables
	string caterer;
	int numPeople;
	float costPerson;
	float food;
	float salesTax;
	float tip;
	float grandTotal;
	
	// prints welcome message with some end lines
	cout<<endl;
	cout << "Welcome to the Party Caterer Calculator!";
	cout <<endl<<endl<<endl;;;
	
	// get inputs from user
	cout << "Please enter the caterer’s name: ";
	getline(cin, caterer);
	
	cout << "Please enter the number of people: ";
	cin >> numPeople;
	
	cout << "Please enter the cost per person: $";
	cin >> costPerson;

	// bunch of end lines
	cout<<endl<<endl<<endl;;;
	
	// perform calculations
	food = numPeople * costPerson;
	salesTax = food * 0.06;     
    tip = ceil(food * 0.15);    // calculating food and tip, then it rounds up
	grandTotal = food + salesTax + tip;
	
	
	// outputs results to the user
	cout << "Estimate for: " << caterer <<endl<<endl;;
	
	cout << setprecision(2) << fixed << showpoint;
	cout << setw(15) << "Food: $"<< food <<endl;

    cout << setprecision(2) << fixed << showpoint;
	cout << setw(15)<< "Tax: $"<< salesTax <<endl;
	
	cout << setprecision(2) << fixed << showpoint;
	cout << setw(15)<< "Tip: $"<< tip <<endl;
	
	cout << setprecision(2) << fixed << showpoint;
	cout << setw(15)<< "Total: $"<<grandTotal <<endl;
	
	// more end lines
	cout<<endl<<endl;;
	
	return 0;
}