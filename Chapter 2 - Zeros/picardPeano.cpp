// picarPeano.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using namespace std;

double g(double x)
{
	return (2 * log(x) + 5);
}

double dg(double x)
{
	return (2 / x);
}


void picardPeano()
{
	double x0, xn;

	cout << "x0? "; cin >> x0;

	unsigned int i = 0;

	if (abs(dg(x0)) < 1)
	{
		xn = g(x0);

		while (abs(xn - x0) >= pow(10, -5))
		{
			if (g(xn) == 0)
				break;

			x0 = xn;

			xn = g(x0);

			i++;
		}
	}
	else
	{
		//Definir outra função g(x) cuja derivada no ponto seja inferior a 1
		//g(x) = e^((x-5)/2)

		xn = exp((x0 - 5) / 2);

		while (abs(xn - x0) >= pow(10, -5))
		{
			if (exp((xn - 5) / 2) == 0)
				break;

			x0 = xn;

			xn = exp((x0 - 5) / 2);

			i++;
		}

	}

	cout << "xn = " << xn << endl << "Number of iterations: " << i << endl << endl;
}

int main()
{
	picardPeano();

	return 0;
}
