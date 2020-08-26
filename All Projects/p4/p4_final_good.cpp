/* Brendan Allen
   CSCI130-001
   Spring 2020
   Program 4
   Calculating the total cost to host a party
   Asked the discussion board about declaring the printPartyReport function and helped Drew out on a few things
*/


// All the c++ library's needed for the program to run correctly
#include <iostream>
#include <iomanip>  // setw and setprecision
#include <cmath>    // to round up the pack of materials we need
#include <string>   // for the name and fileName
#include <fstream>  // to output everything to a file


using namespace std;

// declare functions
string getName(void);
int getAge(void);
int getGuests(void);
float getCakeCost(void);
void printPartyReport(ofstream & partyOut, string name, int ageofChild, int guests, int balloons, float balloonsCost, float giftBag_Cost, int napkins, float napkinsCost, int plates, float platesCost, int pizza, float pizzaCost, int juice, float juiceCost, int sheetAmt, int halfAmt, float cakeCost_sheet, float cakeCost_half, float total);
string getFileName(void);


// declare named constants
const float eachBalloon = 0.45;
const float eachGiftBag = 4.15;
const int napkins_PerPack = 12;
const float eachPack_napkins = 3.00;
const int plates_PerPack = 8;
const float eachPack_plates = 3.15;
const int pizza_PerBox = 12;
const float eachBox_pizza = 5.35;
const int juice_PerBox = 10;
const float eachBox_juice = 4.25;

// cake variables constants
const int SHEET_FEEDS = 50;
const int HALF_FEEDS = 25;
const float HALF_SHEET_COST = 10.00;
const float FULL_SHEET_COST = 15.75;

int main(void)
{

    // declare variables
    string name;
    string fileName;
    int ageofChild;
    int guests;
    int tPeople;  // everyone including the birthday boy/girl
    int balloons;
    float balloonsCost;
    float giftBag_Cost;
    int totalNapkins;
    int napkins;
    float napkinsCost;
    int totalPlates;
    int plates;
    float platesCost;
    int pizza;
    float pizzaCost;
    int juice;
    float juiceCost;
    int sheetAmt;
    int halfAmt;
    float cakeCost_sheet;
    float cakeCost_half;
    float total;
    ofstream partyOut;

    // prints the welcome message
    cout << endl<< "Welcome to the Party Planner Calculator!";
    cout << endl;

    // gets the name of the birthday person from the user
    name = getName();

    // gets age of the birthday person from a value returning function
    ageofChild = getAge();

    // gets how many guests are invited to the child's party
    guests = getGuests();

    // gets the cost of cake -- not included anymore
    // cakeCost = getCakeCost();

    // invited plus the birthday kid
    tPeople = guests + 1;

    // CALCULATIONS

    // calculations for the amount of balloons the host would need
    balloons = guests * ageofChild;

    // determining the cost of balloons with the amount of balloons the user needs
    if (balloons > 100) // if there are more than 100 balloons, then it'll cost 0.25 each
    {
      balloonsCost = balloons * 0.25;
    }
    else if (balloons >= 50) // if there are 50 or more balloons, but less than 100, it'll cost 0.35 each
    {
      balloonsCost = balloons * 0.35;
    }
    else // if there are less than 50 balloons, then it would cost 0.45 (the constant declared above)
    {
      balloonsCost = balloons * eachBalloon;
    }

    // calculations for the cost of gift bags for all the guests
    giftBag_Cost = guests * eachGiftBag;

    // calculations for napkin packs and the cost of napkins
    napkins = ceil(float(tPeople * 4) / napkins_PerPack); // calculation for the amount of napkin packs the hoster needs

    // calculating the total amount of napkins
    totalNapkins = tPeople * 4;

    // determining the cost of napkins from the total amount of napkins needed
    if (totalNapkins >= 300) // if there are more than 300 napkins needed, then each pack costs 1.50
    {
      napkinsCost = napkins * 1.50;
    }
    else if (totalNapkins >= 101) // if there are 101 napkins to 300 napkins needed, then each pack costs 2.50
    {
      napkinsCost = napkins * 2.50;
    }
    else // if napkins are less than 100, then each pack costs 3.50 (constant listed above)
    {
      napkinsCost = napkins * eachPack_napkins;
    }

    // calculations for plate packs and how many packs the hoster needs
    plates = ceil(float(tPeople * 2) / plates_PerPack);

    // calculating the total amount of plates
    totalPlates = tPeople * 2;

    // determing the cost of plates from the total amount of plates needed
    if (totalPlates > 50) // if there are more than 50 plates, a plate pack will cost $3 each
    {
      platesCost = plates * 3.00;
    }
    else // if there are less than 50 plates needed, then a plate pack will cost $3.15 each (constant above)
    {
      platesCost = plates * eachPack_plates;
    }

    // calculations for pizza boxes the host needs and the cost of each pizza box
    pizza = ceil(float(tPeople * 3) / pizza_PerBox);
    pizzaCost = pizza * eachBox_pizza;

    // calculations for juice boxes the host needs and the cost of juice boxes
    juice = ceil(float(tPeople * 2) / juice_PerBox);
    juiceCost = juice * eachBox_juice;

    // determining the cost of cake using the amount of people including the birthday person

    // determining how much full sheets the hoster needs
    sheetAmt = tPeople / SHEET_FEEDS;

    // determining how much half sheets the hoster needs
    halfAmt = (tPeople - (sheetAmt * SHEET_FEEDS)) % HALF_FEEDS;
    if (halfAmt >= 0)
    {
      if ((sheetAmt == 0) && (halfAmt == 1)) // if there is 0 full sheet and 1 half sheet (in the remainder)
      {
        sheetAmt = 1; /* this becomes a full sheet because with 26 including
                         the birthday boy/girl, you need a full sheet */
        halfAmt = 0;
      }
      else
      {
        halfAmt = 1;
      }
    }

    // determining the cost of the half and full sheet of cakes
    cakeCost_half = halfAmt * HALF_SHEET_COST;
    cakeCost_sheet = sheetAmt * FULL_SHEET_COST;

    // calculating the grand total
    total = balloonsCost+giftBag_Cost+napkinsCost+platesCost+pizzaCost+juiceCost+cakeCost_sheet+cakeCost_half;

    // sends everything that was inputted / calculated above into an output file
    printPartyReport(partyOut, name, ageofChild, guests, balloons, balloonsCost, giftBag_Cost, napkins, napkinsCost, plates, platesCost, pizza, pizzaCost, juice, juiceCost, sheetAmt, halfAmt, cakeCost_sheet, cakeCost_half, total);

    return 0;
}

string getName()
{
    // declare variables
    string name;

    // ask the user for the birthday boy/girl's name
    cout << "What is the name of the birthday person? ";
    getline(cin, name);

    return name;
}

int getAge()
{
    // declare variables
    int ageofChild;

    // asks the user for the birthday person's age
    cout << "Please enter the age of the birthday person: ";
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

float getCakeCost() // not included
{
    // declare variables
    float cakeCost;

    // ask the user the cost of the cake
    cout << "What is the cost of the cake? ";
    cin >> cakeCost;
    cin.ignore(256, '\n');

    return cakeCost;
}

void printPartyReport(ofstream & partyOut, string name, int ageofChild, int guests, int balloons, float balloonsCost, float giftBag_Cost, int napkins, float napkinsCost, int plates, float platesCost, int pizza, float pizzaCost, int juice, float juiceCost, int sheetAmt, int halfAmt, float cakeCost_sheet, float cakeCost_half, float total)
{
  string fileName;

  fileName = getFileName(); // asks the user for the fileName to generate the output report.

  partyOut.open(fileName.c_str(), ios::app); // starts the output file, will output everything in here to a file and not on the screen.

  partyOut << "Party Cost for " << name <<"'s Party:"<<endl<<endl;;

  // outputs results from the calculations above, with proper formatting.
  partyOut << setprecision(2) << fixed << showpoint;
  partyOut << "Balloons: " << setw(12) << balloons << setw(20) << "$" << setw(8) << balloonsCost;
  partyOut << endl;

  partyOut << setprecision(2) << fixed << showpoint;
  partyOut << "Gift Bags: " << setw(11) << guests << setw(20) << "$" << setw(8) << giftBag_Cost;
  partyOut <<endl;

  partyOut << setprecision(2) << fixed << showpoint;
  partyOut << "Napkin Packs: " << setw(8) << napkins << setw(20) << "$" << setw(8) << napkinsCost;
  partyOut << endl;

  partyOut << setprecision(2) << fixed << showpoint;
  partyOut << "Plate Packs: " << setw(9) << plates << setw(20) << "$" << setw(8) << platesCost;
  partyOut << endl;

  partyOut << setprecision(2) << fixed << showpoint;
  partyOut << "Pizza Boxes: " << setw(9) << pizza << setw(20) << "$" << setw(8) << pizzaCost;
  partyOut << endl;

  partyOut << setprecision(2) << fixed << showpoint;
  partyOut << "Juice Boxes: " << setw(9) << juice << setw(20) << "$" << setw(8) << juiceCost;
  partyOut << endl;

  // determining if the half, full, or both sheets of cake will output from the calculation of cake above
  if ((sheetAmt >= 1) && (halfAmt >= 1))
  {

    partyOut << setprecision(2) << fixed << showpoint;
    partyOut << "Cake - half sheet: " << setw(3) << halfAmt << setw(20) << "$" << setw(8) << cakeCost_half;
    partyOut << endl;

    partyOut << setprecision(2) << fixed << showpoint;
    partyOut << "Cake - full sheet: " << setw(3) << sheetAmt << setw(20) << "$" << setw(8) << cakeCost_sheet;
    partyOut << endl;
  }
  else if(sheetAmt > 0)
  {
    partyOut << setprecision(2) << fixed << showpoint;
    partyOut << "Cake - full sheet: " << setw(3) << sheetAmt << setw(20) << "$" << setw(8) << cakeCost_sheet;
    partyOut << endl;
  }
  else
  {
    partyOut << setprecision(2) << fixed << showpoint;
    partyOut << "Cake - half sheet: " << setw(3) << halfAmt << setw(20) << "$" << setw(8) << cakeCost_half;
    partyOut << endl;
  }

  partyOut << endl; // have the total cost that seperates from the items above

  // outputs the total cost to host a party
  partyOut << setprecision(2) << fixed << showpoint;
  partyOut << "Total Cost: " << setw(30) << "$" << setw(8) << total;

  partyOut <<endl; // endline to seperate the output above

  partyOut << "**************************************************"; // prints 50 asterisk's

  partyOut <<endl; // extra endline to seperate the asterisks

  partyOut.close(); // closes and automatically saves the file

  cout << endl; // extra endline

  return;
}

string getFileName()
{
  // declare variables
  string fileName;

  // asks the user to name the file name for the output report.
  cout << "What is the name of the file you want to use for the report? ";
  cin >> fileName;

  return fileName;
}
