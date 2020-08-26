#include <iostream>
#include <fstream>

using namespace std;

const string TRANS_FILE_NAME = "orders.data";
void openTransactionFile(ifstream & theFile);
void closeTransactionFile(ifstream & transactionFile);
string ReadOrderFromTransFile(ifstream & theFile);

int main() {
  string orderFileName;
  ifstream transactionFile;

  // open transaction file
  openTransactionFile(transactionFile);

  // Read an order file name
  orderFileName = ReadOrderFromTransFile(transactionFile);

  // while not at the end of the transaction
  while(transactionFile) {
      // process the order
      cout << "Processing " << orderFileName << endl;
      // read a new order file name
      orderFileName =  ReadOrderFromTransFile(transactionFile);
  }
  // close the transaciton file
  closeTransactionFile(transactionFile);

  return 0;
}

void openTransactionFile(ifstream & theFile) {
  theFile.open(TRANS_FILE_NAME);

  return;
}

void closeTransactionFile(ifstream & transactionFile) {
  transactionFile.close();
}

string ReadOrderFromTransFile(ifstream & theFile) {
  string tmp;
  theFile >> tmp;

  return tmp;
}
