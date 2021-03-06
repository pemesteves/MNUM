// cubatura.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <math.h>

#define PI 4*atan(1)

using namespace std;

inline double f(double x, double y) {
	return (sin(x + y));
}

int main()
{
	double a = 0, A = PI / 2, b = 0, B = PI / 2;
	double hx = (A - a) / 2, hy = (B - b) / 2;

	double cubatura = 0;

	cubatura += f(a, b) + f(a, B) + f(A, b) + f(A, B); //Soma dos vértices->somatório 0
	cubatura += 4 * (f(a, hy) + f(hx, b) + f(hx, B) + f(A, hy)); //Soma dos pontos médios das arestas->somatório 1
	cubatura += 16 * (f(hx, hy)); //Centro->somatório 2

	cubatura = hx * hy*cubatura / 9; //Fórmula da cubatura = hx*hy*(Somatório 0 +4*Somatório 1 + 16*Somatório 2)/9

	cout << cubatura;


	return 0;
}
