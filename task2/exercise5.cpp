#include <iostream>
using namespace std;

int main() {
  double number;
  cout << "Enter number: ";
  cin >> number;
  double *pointer = &number;
  double &reference = number;
  
  cout << number << endl;
  cout << *pointer << endl;
  cout << reference << endl;
  
  
  return 0;
}
