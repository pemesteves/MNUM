#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

tuple<vector<vector<double>>, vector<vector<double>>> decomposicaoLU(vector<vector<double>> A) {
	vector<vector<double>> L, U;
	L.resize(A.size());
	U.resize(A.size());
	for (size_t i = 0; i < A.size(); i++) {
		L[i].resize(A[i].size());
		U[i].resize(A[i].size());
		for (size_t j = 0; j < A[i].size(); j++) {
			L[i][j] = U[i][j] = 0;
		}
	}

	U = A;

	for (size_t i = 0; i < L.size(); i++) {
		L[i][i] = 1;
	}

	for (unsigned j = 0; j < 2; j++) {
		for (unsigned i = j + 1; i <= 2; i++) {
			L[i][j] = U[i][j] / U[j][j];
			for (unsigned k = j; k <= 2; k++) {
				U[i][k] = U[i][k] - L[i][j] * U[j][k];
			}
		}
	}

	tuple<vector<vector<double>>, vector<vector<double>>> t = make_tuple(L, U);
	return t;
}

vector<vector<double>> invert_matrix(vector<vector<double>> &m) {
	vector<vector<double>> invert = m;
	double determinant = 0;
	for (unsigned i = 0; i < 3; i++)
		determinant += (m[0][i] * (m[1][(i + 1) % 3] * m[2][(i + 2) % 3] - m[1][(i + 2) % 3] * m[2][(i + 1) % 3]));

	for (unsigned i = 0; i < 3; i++) {
		for (unsigned j = 0; j < 3; j++) {
			invert[i][j] = (m[(j + 1) % 3][(i + 1) % 3] * m[(j + 2) % 3][(i + 2) % 3] - (m[(j + 1) % 3][(i + 2) % 3] * m[(j + 2) % 3][(i + 1) % 3])) / determinant;
		}
	}

	return invert;
}

int main() {
	vector<vector<double>> A;
	vector<double> v = { 7, 2, 0 };
	A.push_back(v);
	v.clear();
	v = { 4, 10, 1 };
	A.push_back(v);
	v.clear();
	v = { 5, -2, 8 };
	A.push_back(v);

	tuple<vector<vector<double>>, vector<vector<double>>> t = decomposicaoLU(A);
	vector<vector<double>> L = get<0>(t), U = get<1>(t);

	vector<vector<double>> L1 = invert_matrix(L);

	v.clear();
	v = { 24, 27, 27 };

	vector<double> y;

	for (unsigned i = 0; i < L1.size(); i++) {
		double value = 0;
		for (unsigned j = 0; j < L1[i].size(); j++) {
			value += L1[i][j] * v[j];
		}
		y.push_back(value);
	}

	vector<vector<double>> U1 = invert_matrix(U);

	vector<double> x;
	for (unsigned i = 0; i < U1.size(); i++) {
		double value = 0;
		for (unsigned j = 0; j < U1[i].size(); j++) {
			value += U1[i][j] * y[j];
		}
		x.push_back(value);
	}

	for (unsigned i = 0; i < x.size(); i++) {
		cout << x[i] << endl;
	}

	return 0;
}
