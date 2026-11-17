/******************************************
* Автор:   Хнкоян Михаил Араикович        *
* Задание: Laboratory 6 - Functions       *
* Вариант: 29                             *
******************************************/

#include <iostream>
#include <cmath>

using namespace std;

// Counts positive elements outside the open interval (leftBound, rightBound).
// Requires 1 <= elementCount <= 100 and leftBound < rightBound.
// Does not modify the input array; returns a count from 0 to elementCount.
int countPositiveOutsideInterval(const double values[], int elementCount,
    double leftBound, double rightBound) {
    int matchingCount;
    matchingCount = 0;

    for (int elementIndex = 0; elementIndex < elementCount; ++elementIndex) {
        if (values[elementIndex] > 0.0 &&
            (values[elementIndex] <= leftBound || values[elementIndex] >= rightBound)) {
            ++matchingCount;
        }
    }

    return matchingCount;
}

int main() {
    const int maxElementCount = 100;
    const double maxAbsoluteValue = 1000.0;

    double leftBound;
    double rightBound;
    double firstValues[maxElementCount];
    double secondValues[maxElementCount];
    int firstCount;
    int secondCount;
    int firstResult;
    int secondResult;
    int elementIndex;

    if (!(cin >> leftBound >> rightBound) ||
        !isfinite(leftBound) || !isfinite(rightBound) || leftBound >= rightBound) {
        cout << "INVALID\n";
        return 0;
    }

    if (!(cin >> firstCount) || firstCount < 1 || firstCount > maxElementCount) {
        cout << "INVALID\n";
        return 0;
    }

    for (elementIndex = 0; elementIndex < firstCount; ++elementIndex) {
        if (!(cin >> firstValues[elementIndex]) ||
            !isfinite(firstValues[elementIndex]) ||
            abs(firstValues[elementIndex]) > maxAbsoluteValue) {
            cout << "INVALID\n";
            return 0;
        }
    }

    if (!(cin >> secondCount) || secondCount < 1 || secondCount > maxElementCount) {
        cout << "INVALID\n";
        return 0;
    }

    for (elementIndex = 0; elementIndex < secondCount; ++elementIndex) {
        if (!(cin >> secondValues[elementIndex]) ||
            !isfinite(secondValues[elementIndex]) ||
            abs(secondValues[elementIndex]) > maxAbsoluteValue) {
            cout << "INVALID\n";
            return 0;
        }
    }

    firstResult = countPositiveOutsideInterval(firstValues, firstCount,
        leftBound, rightBound);
    secondResult = countPositiveOutsideInterval(secondValues, secondCount,
        leftBound, rightBound);

    cout << "S: " << firstResult << "\nD: " << secondResult << "\n";
    return 0;
}
