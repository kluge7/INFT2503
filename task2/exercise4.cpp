#include <iostream>
using namespace std;

int main() {
  int a = 5;
  int &b = a;
  int *c = nullptr;
  c = &b;
  a = b + *c;
  a = 2;
  
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  
  
  return 0;
}
