#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

vector<int> toSort;

void get_input() {
	ifstream file("rosalind_ins.txt");
	int n;
	file >> n;
	for(int i = 0; i < n; ++i) {
		int num;
		file >> num;
		toSort.push_back(num);
	}
}

bool sorted() {
	for (int i = 1; i < toSort.size(); ++i) {
		if (toSort[i] < toSort[i - 1]){
			return false;
		}
	}
	return true;
}

int iSort() {
	int swap_n = 0;
	while(!sorted()) {
		for (int i = 0; i < (toSort.size() - 1); ++i) {
			//if current and next are in wrong order
			if (toSort[i] > toSort[i + 1]) {
				//swap elements
				int temp = toSort[i];
				toSort[i] = toSort[i + 1];
				toSort[i + 1] = temp;

				//increment swap counter
				++swap_n;
			}
		}
	}
	return swap_n;
}

int main() {
	get_input();
	cout << iSort();
	return 0;
}
