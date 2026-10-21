/****************************************************
 * Автор:   Сабитов Ильнур                          *
 * Задание: Циклы с ветвлениями                     *
 * Вариант: 28                                      *
 ****************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
  double diameterMillimeters;
  double viscosity;
  int speedCount;
  double speed;
  double reynoldsNumber;
  double dragCoefficient;
  int speedIndex;

  cout << "Enter sphere diameter dC (mm): ";
  cin >> diameterMillimeters;

  cout << "Enter viscosity v (cm^2/s): ";
  cin >> viscosity;

  cout << "Enter number of speeds: ";
  cin >> speedCount;

  for (speedIndex = 0; speedIndex < speedCount; ++speedIndex) { 
    cout << "\nEnter speed w number " << speedIndex + 1 << " (cm/s): ";
    cin >> speed;

    reynoldsNumber = speed * diameterMillimeters / 10.0 / viscosity;
    if (reynoldsNumber < 50.0) {
      dragCoefficient = 25.0 / pow(reynoldsNumber, 0.75);
    } else {
      dragCoefficient = 4.0 / pow(reynoldsNumber, 0.3);
    }

    cout << "w = " << speed << " cm/s, C = " << dragCoefficient << ", Re = " << reynoldsNumber;
  }

  return 0;
}