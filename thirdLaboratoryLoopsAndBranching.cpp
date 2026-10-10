/****************************************************
 * Автор:   Сабитов Ильнур                          *
 * Задание: Циклы с ветвлениями                     *
 * Вариант: 28                                      *
 ****************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    const double reynoldsBorder = 50.0;
    const double firstCoefficient = 25.0;
    const double firstExponent = 0.75;
    const double secondCoefficient = 4.0;
    const double secondExponent = 0.3;
    const double millimetersInCentimeter = 10.0;
    const int speedCount = 5;

    double diameter;
    double viscosity;
    double speedList[speedCount];
    double reynoldsNumber;
    double dragCoefficient;
    int speedIndex;

    cout << "Enter sphere diameter dC (mm): ";
    cin >> diameter;
    cout << "Enter viscosity v (cm^2/s): ";
    cin >> viscosity;
    for (speedIndex = 0; speedIndex < speedCount; ++speedIndex) {
        cout << "Enter speed w number " << speedIndex + 1 << " (cm/s): ";
        cin >> speedList[speedIndex];
    }

    diameter = diameter / millimetersInCentimeter;

    cout << "w (cm/s)\tC\t\tRe";

    for (speedIndex = 0; speedIndex < speedCount; ++speedIndex) {
        reynoldsNumber = speedList[speedIndex] * diameter / viscosity;
        if (reynoldsNumber < reynoldsBorder) {
            dragCoefficient = firstCoefficient / pow(reynoldsNumber, firstExponent);
        }
        else {
            dragCoefficient = secondCoefficient / pow(reynoldsNumber, secondExponent);
        }
        cout << "\n" << speedList[speedIndex] << "\t\t" << dragCoefficient << "\t\t" << reynoldsNumber;
    }

    return 0;
}