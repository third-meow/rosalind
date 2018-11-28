#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

vector<int> sorted;
vector<int> keys;

void get_input() {
	ifstream file("rosalind_bins.txt");
	int n, m;
	file >> n;
	file >> m;
	for(int i = 0; i < n; ++i) {
		int num;
		file >> num;
		sorted.push_back(num);
	}

	for(int i = 0; i < m; ++i) {
		int num;
		file >> num;
		keys.push_back(num);
	}
}

int bin_search(int key, int start, int end) {
	if (end < start) {
		return -1;
	}
	if ((end - start) <= 1) {
		if (sorted[start] == key) {
			while(sorted[start] == sorted[start - 1])
				start--;
			return start;
		} else if (sorted[end] == key) {
			return end;
		} else {
			return -1;
		}
	} else {
		int centerpoint = (start + end) / 2;
		int center = sorted[centerpoint];
		if (key == center) {
			while (sorted[centerpoint] == sorted[centerpoint - 1])
				centerpoint--;
			return centerpoint;
		} else if (key > center) {
			return bin_search(key, centerpoint, end);
		} else if (key < center) {
			return bin_search(key, start, (centerpoint - 1));
		}
	}
}


int main() {
	get_input();

	int bin_idx = bin_search(keys[0], 0, (sorted.size() - 1));
	if (bin_idx != -1) 
		++bin_idx;
	cout << bin_idx;
	for(int i = 1; i < keys.size(); ++i) {
		int bin_idx = bin_search(keys[i], 0, (sorted.size() - 1));
		if (bin_idx != -1) 
			++bin_idx;
		cout << " " << bin_idx;
	}
	return 0;
}
