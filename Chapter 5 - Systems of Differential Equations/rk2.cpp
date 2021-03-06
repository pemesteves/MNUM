// rk2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double df(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

int main()
{
	double x = 0, y = 0, h = 0.1;

	for (; x <= 1.4; x += h) {
		y += h * df(x + h / 2, y + h * df(x, y) / 2);
	}
	double S = y, S1, S2;

	cout << y << endl;

	x = 0; y = 0; h = h / 2;
	for (; x <= 1.4; x += h) {
		y += h * df(x + h / 2, y + h * df(x, y) / 2);
	}
	S1 = y;

	cout << y << endl;

	x = 0; y = 0; h = h/2;
	int n = 0;
	for (; n <56; n++) {
		y += h * df(x + h / 2, y + h * df(x, y) / 2);
		x += h;
	}
	S2 = y;

	cout << y << endl;

	cout << "QC: " << (S1 - S) / (S2 - S1) << endl;

	cout << "Epsilon: " << (S2 - S1) / 3 << endl;

	return 0;
}

