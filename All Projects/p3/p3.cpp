/* Brendan Allen
   CSCI130-001
   Spring 2020
   Program 3
   Calculating the total cost to host a party
   Helped Drew with "per pack" calculation, Drew helped me with "cin.ignore" command
*/


// All the c++ library's needed for the program to run correctly
#include <iostream>
#include <iomanip>
#include <cmath>    // to round up the pack of materials we need

// declare functions
int getAge();
int getGuests();

using namespace std;
int main(void)
{

    // declare named constants
    const float eachBalloon = 0.35;
    const float eachGiftBag = 3.25;
    const int napkins_PerPack = 16;
    const float eachPack_napkins = 3.75;
    const int plates_PerPack = 8;
    const float eachPack_plates = 3.15;
    const int pizza_PerBox = 16;
    const float eachBox_pizza = 7.50;
    const int juice_PerBox = 10;
    const float eachBox_juice = 4.25;
    const float cakeCost = 14.50;
    
    // declare variables
    int ageofChild;
    int guests;
    int children;
    int balloons;
    float balloonsCost;
    float giftBag_Cost;
    int napkins;          
    float napkinsCost;
    int plates;           
    float platesCost;
    int pizza;            
    float pizzaCost;
    int juice;            
    float juiceCost;
    float total;

    // prints the welcome message
    cout << endl<< "Welcome to the Party Planner Calculator!";
    cout << endl;
    
    // gets age of the birthday child from a value returning function
    ageofChild = getAge();
    
    // gets how many guests are invited to the child's party
    guests = getGuests();
    
    // invited plus the birthday kid
    children = guests + 1;  
    
    // CALCULATIONS 
    
    // calculations for the amount of balloons the host would need plus the cost
    balloons = guests * ageofChild;
    balloonsCost = balloons * eachBalloon;
    
    // calculations for the cost of gift bags for all the guests
    giftBag_Cost = guests * eachGiftBag;
    
    // calculations for napkin packs and the cost of napkins
    napkins = ceil(float(children * 4) / napkins_PerPack);
    napkinsCost = napkins * eachPack_napkins;
    
    // calculations for plate packs and the cost of plates
    plates = ceil(float(children * 2) / plates_PerPack);
    platesCost = plates * eachPack_plates;
    
    // calculations for pizza boxes and the cost of each pizza box
    pizza = ceil(float(children * 3) / pizza_PerBox);
    pizzaCost = pizza * eachBox_pizza;
    
    // calculations for juice boxes and the cost of juice boxes
    juice = ceil(float(children * 2) / juice_PerBox);
    juiceCost = juice * eachBox_juice;
    
    // calculating the grand total
    total = balloonsCost+giftBag_Cost+napkinsCost+platesCost+pizzaCost+juiceCost+cakeCost;
    
    // end lines to seperate the inputs above
    cout << endl<<endl<<endl;;;
    
    // Outputs results to the user
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Balloons: " << setw(10) << balloons << setw(20) << "$" << setw(7) << balloonsCost;
    cout << endl;
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Gift Bags: " << setw(9) << guests << setw(20) << "$" << setw(7) << giftBag_Cost;
    cout <<endl;
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Napkin Packs: " << setw(6) << napkins << setw(20) << "$" << setw(7) << napkinsCost;
    cout << endl;
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Plate Packs: " << setw(7) << plates << setw(20) << "$" << setw(7) << platesCost;
    cout << endl;
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Pizza Boxes: " << setw(7) << pizza << setw(20) << "$" << setw(7) << pizzaCost;
    cout << endl;
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Juice Boxes: " << setw(7) << juice << setw(20) << "$" << setw(7) << juiceCost;
    cout << endl;
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Cake: " << setw(14) << "1" << setw(20) << "$" << setw(7) << cakeCost;
    cout << endl<<endl; // have the total cost that seperates from the items above
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "Total Cost: " << setw(28) << "$" << setw(7) << total;
    
    cout <<endl<<endl;;
    
    return 0;
}

int getAge()
{
    // declare variables 
    int ageofChild;
    
    // extra line to seperate the welcome message
    cout << endl;
    
    // asks the user for the birthday child's age
    cout << "Please enter the age of the birthday child: ";
    cin >> ageofChild;
    cin.ignore(256, '\n'); 
    
    return ageofChild;
}

int getGuests()
{
    // declare variables
    int guests;
    
    // asks the user for how many guests are attending the birthday party
    cout << "How many guests are invited to the birthday party? ";
    cin >> guests;
    cin.ignore(256, '\n');
    
    return guests;
}