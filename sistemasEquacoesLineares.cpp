#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

void sistemasEquacoesLineares(vector<vector<double>> matrix, vector<double> &result) {
	double diagonalValue; 
	for (size_t i = 0; i < matrix.size() - 1; i++) {
		diagonalValue = matrix.at(i).at(i);
		for (size_t j = i + 1; j < matrix.size(); j++) {
			for (size_t k = i; k < matrix.at(i).size(); k++) {
				matrix.at(i).at(k) /= diagonalValue;
				matrix.at(j).at(k) += matrix.at(i).at(k)*(-matrix.at(j).at(k));
			}
		}
	}

	for (size_t i = matrix.size()-1; i >= 0; i++) {
		for (size_t j = matrix.size() - 1; j >= 0; j++) {
			//TODO Acabar
		}
	}
}

int main() {
	vector<vector<double>> matrix;
	vector<double> line;
	line = { 3, -1, 2, -1 };
	matrix.push_back(line);
	line = { 1, 1, 1, 8 };
	matrix.push_back(line);
	line = { 2, 0, 1, 5 };
	matrix.push_back(line);
	line.clear();
	sistemasEquacoesLineares(matrix, line);
	return 0;
}
