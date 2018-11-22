#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

void decomposicaoLU(vector<vector<double>> A, vector<double> b) {
	//TODO Corrigir método
	vector<vector<double>> L, U;
	L.resize(A.size());
	U.resize(A.size());
	for (size_t i = 0; i < A.size(); i++) {
		L[i].resize(b.size());
		U[i].resize(b.size());
		for (size_t j = 0; j < A.size(); j++) {
			L[i][j] = U[i][j] = 0;
		}
	}

	for (size_t i = 0; i < A.size(); i++) {
		U[i][i] = 1;
	}

	//li1 = ai1
	for (size_t i = 0; i < A.size(); i++) {
		L[i].at(1) = A[i].at(1);
	}
	//U1j = a1j/l11
	for (size_t i = 0; i < A.size(); i++) {
		U[1].at(i) = A[1].at(i) / L[1][1];
	}

	for (size_t i = 1; i < A.size(); i++) {
		for (size_t j = 1; j < A.size(); j++) {
			if (L[i][j] == 0)
				L[i][j] = A[1][j];

			for (size_t k = 1; k < j - 1; k++) {
				if (L[i][j] == 0)
					L[i][j] -= L[i][k] * U[k][j];
			}
		}
		for (size_t j = 1; j < A.size(); j++) {
			U[i][j] = A[i][j] / L[i][i];
			for (size_t k = 1; k < j - 1; k++) {
				if (U[i][j] == 0)
					U[i][j] -= L[i][k] * U[k][j] / L[i][i];
			}
		}
	}

	cout << "L" << endl;
	for (size_t i = 0; i < L.size(); i++) {
		for (size_t j = 0; j < L[i].size(); j++) {
			cout << L[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "U" << endl;
	for (size_t i = 0; i < L.size(); i++) {
		for (size_t j = 0; j < L[i].size(); j++) {
			cout << U[i][j] << "  ";
		}
		cout << endl;
	}
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
	v.clear();
	v = { 24, 27, 27 };
	decomposicaoLU(A, v);

	return 0;
}