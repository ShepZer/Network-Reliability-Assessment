// Project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
using namespace std;
#include <iostream>
#include <math.h>

int bin_code[1000] = { 0 };
int matrix[11][11] = { 0,0 };
int x;
int y;
double sum[11] = {};
double p[11] = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
float sumPR[11] = {};
int N = 0;
int ogranic = 0;

int visit[10] = { 0 };

void test(int i) {
	for (int j = 0; j < ogranic; j++) {
		if (matrix[i][j] == 1 && visit[j] == 0) {
			visit[j] = 1;
			test(j);
		}
	}
}

int main() {

	cout << "Enter:" << endl << "N: ";
	cin >> N;

	cout << "x: "; cin >> x;
	x--;
	cout << "y: "; cin >> y;
	y--;

	int flag = 0; //ограничитель
	int Perenos = 1;

	int matrix_dano[10][10] = {
		{0,1,1,0,0,1},
		{0,0,0,0,1,0},
		{0,0,0,1,0,1},
		{0,0,0,0,1,1},
		{0,0,0,0,0,1},
		{0,0,0,0,0,0},
	};

	long bin_code_dano[1000] = { 0 };

	int t = 1;
	int k = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0 + t; j < N; j++) {
			bin_code_dano[k] = matrix_dano[i][j];
			if (bin_code_dano[k] == 1) {
				ogranic++;
			}
			k++;
		}
		t++;
	}

	//перебор
	while (flag != pow(2, ogranic) - 1){

		for (int i = 0; i < N; i++) {
			visit[i] = 0;
		}

		Perenos = 1;
		int col_1 = 0;

		for (long i = ogranic-1; i >= 0; i--) {
			if (Perenos == 1) {
				if (bin_code[i] == 1) { 
					bin_code[i] = 0;
				}
				else {
					bin_code[i] = 1;
					Perenos = 0;
				}
			}
		}

		int st = 0;
		for (int i = 0; i < N; i++) { 
			for (int j = 0; j < N; j++) {
				if (matrix_dano[i][j] == 1) {
					matrix[i][j] = bin_code[st];
					matrix[j][i] = bin_code[st];
					st++;
				}
			}
		}

		visit[x] = 1;
		test(x);//обычный DFS

		double pr[11] = {1,1,1,1,1,1,1,1,1,1,1};

		if (visit[y] == 1) {

			for (int i = 0; i < ogranic; i++) {
				if (bin_code[i] == 0) {
					for (int i = 0; i < 11; i++) {
						pr[i] = pr[i] * (1.0 - p[i]);
					}
				}
				else {
					for (int i = 0; i < 11; i++) {
						pr[i] = pr[i] * p[i];
					}
				}
			}
			for (int i = 0; i < 11; i++) {
				sum[i] = sum[i] + pr[i];
			}
		}
		else {}
		flag++;
	}
	for (int i = 0; i < 11; i++) {
		sumPR[i] = 5 * pow(p[i],9) - 22 * pow(p[i],8) + 32 * pow(p[i],7) - 11 * pow(p[i],6) - 10 * pow(p[i],5) + 3 * pow(p[i],4) + 3 * pow(p[i],3) + pow(p[i],2);
	}
	for (int i = 0; i < 11; i++) {
		cout << "p = " <<p[i] << endl << "probability: " << sum[i] << endl;
		cout << "probability PRACT: " << sumPR[i] << endl << endl;
	}
}