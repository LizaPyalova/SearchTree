#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	unsigned int size = 0;
	if (in.is_open()) {
		in >> size;
		int *size_array = new int[size + 1];
		for (int i = 0; i < size; i++) {
			in>>size_array[i]; in >> size_array[i+1];
		}
		int** array = new int*[size];
		for (int i = 0; i < size; i++) {
			array[i] = new int[size];
		}
		for (int i = 0; i < size; i++) array[i][i] = 0;
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				int k = i + j;
				array[j][k] = 2147483647;
				for (int l = j; l < k; l++) {
					int tmp = array[j][l] + array[l + 1][k] + size_array[j] * size_array[k + 1] * size_array[l + 1];
					if (array[j][k] > tmp) array[j][k] = tmp;
				}
			}
		}
		out << array[0][size - 1];
	}
}