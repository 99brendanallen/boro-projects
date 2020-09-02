/*
   Program 1: Finding Some Easy Stats
   Programmer: Brendan Allen
   Class:  CSCI 230,  Fall 2020
   Short Description:  This program processes statistics depending on if the statement is true or not.

   Narrative:
        This program ...

   Special Notes:
      *  If you run this program with the -G flag, the program will
	 simulate the presence of God, and thus no missing link will be
	 found, man is just created.
      *  This program ...
*/

#include <iostream>
#include <iomanip>

using namespace std;

void EnterMasterFile();

const string MASTER_FILE = "master.list";

int main() {
  // open master file
  EnterMasterFile();

  // start here

  return 0;
}

void EnterMasterFile() {
  string masterFile;

  // enter in master file
  cout << "Enter the name of the master file => "<<endl;
  cin >> masterFile;
  if (masterFile != MASTER_FILE) {
    cout << "ERROR: Unable to open the master file " << masterFile << "." << endl;
  }
  else {
    // successful in opening the file
  }
}
