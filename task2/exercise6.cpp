#include <iostream>
using namespace std;

int find_sum(const int*table, int length) {
  int sum = 0;
  for(int i = 0; i < length; i++) {
    sum += table[i];
  }
  return sum;
}

int main() {
  int SIZE = 20;
  int table[SIZE];
  for(int i = 0; i < SIZE; i++) {
    table[i] = i+1;
  }
  
  int sum_first_10 = find_sum(table, 10);
  cout << "The sum of the first 10 numbers is: " << sum_first_10 << endl;
  
  int sum_next_5 = find_sum(&table[10], 5);
  cout << "The sum of the next 5 numbers is: " << sum_next_5 << endl;
  
  int sum_last_5 = find_sum(&table[15], 5);
  cout << "The sum of the last 5 numbers is: " << sum_last_5 << endl;
  
  return 0;
}
