#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <chrono>
std::vector<int>znalezione;
int sprawdz(int a, int b, int c) {
	std::vector<int>pomoc;
	if (znalezione.size() == 0)return 1;
	for (int x = 0; x < znalezione.size()-1; x+= 3) {
		if (znalezione[x] == a&&znalezione[x + 1] == b&&znalezione[x + 2] == c)return 0;
	}
	return 1;
}
void tSum(std::vector<int> &tab) {
	int l = tab.size();
	std::cout << std::endl<< "3SUM: ";
	for (int i = 0; i < l; i++) {
		std::cout << tab[i] << ",";
	}
	std::cout << std::endl;
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < l - 2; i++) {
		for (int j = i + 1; j < l - 1; j++) {
			for (int k = j + 1; k < l; k++) {
				if (sprawdz(tab[i], tab[j], tab[k]) == 1) {
					int suma = tab[i] + tab[j] + tab[k];
					if (suma == 0) {
						std::cout << "" << tab[i] << " + " << tab[j] << " + " << tab[k] << " = " << suma << std::endl;
					}
					znalezione.push_back(tab[i]);
					znalezione.push_back(tab[j]);
					znalezione.push_back(tab[k]);
				}
			}
		}
	}
	std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms" << std::endl;
	znalezione.clear();
}
void main() {
	znalezione.reserve(100);
	std::vector<int>liczby = { 4, 5, -1,-2, -7, 2 ,-5, -3, -7, -3, 1 };;
	std::vector<int>liczby2 = {-1,-6,-3,-7,5,-8,2,-8,1};
	std::vector<int>liczby3 = { -5,-1,-4,2,9,-9,-6,-1,-7 };
	std::sort(liczby.begin(), liczby.end());
	std::sort(liczby2.begin(), liczby2.end());
	std::sort(liczby3.begin(), liczby3.end());
	tSum(liczby);
	tSum(liczby2);
	tSum(liczby3);
	_getch();
}