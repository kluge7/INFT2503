#include <iostream>
#include <stdio.h>

using namespace std;
int main() {
  int under_10 = 0;
  int between_10_and_20 = 0;
  int over_20 = 0;
  double temperatur;

  for (int i = 0; i < 5; i++) {
    cout << "Temperatur nr " << i + 1 << ": ";
    cin >> temperatur;
    if (temperatur < 10) {
      under_10++;
    } else if (temperatur >= 10 && temperatur <= 20) {
      between_10_and_20++;
    } else {
      over_20++;
    }
  }
  cout << "Antall under 10 er " << under_10 << endl;
  cout << "Antall mellom 10 og 20 er " << between_10_and_20 << endl;
  cout << "Antall over 20 er " << over_20 << endl;
}
