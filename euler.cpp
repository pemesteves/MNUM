// euler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

inline double f(double x, double y){
	return (pow(x, 2)+pow(y,2));
}

int main()
{
	double x, y, h;
	x = 0; y = 0; h = 0.1;
	
	for (; x <= 1.4; x += h) {
		y += f(x, y)*h;
	}
	cout << y << endl;
	double S = y;
	cout << S << endl;

	x = 0; y = 0; h = 0.05;
	for (; x <= 1.4; x += h) {
		y += f(x, y)*h;
	}
	cout << y << endl;
	double S1 = y;
	cout << S1 << endl;

	x = 0; y = 0; h = 0.025; int i = 0;
	for (; i<56; i++) {
		y += f(x, y)*h;
		x += h ;
	}
	cout << y << endl;
	double S2 = y;
	cout << S2 << endl;

	cout << "QC: " << (S1 - S) / (S2 - S1) << endl;
	cout << "e: " << (S2 - S1);
	return 0;
}

