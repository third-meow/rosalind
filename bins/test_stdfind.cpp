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

int bin_search1(int key, int start, int end) { if (end < start) { return -1;
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
			return bin_search1(key, centerpoint, end);
		} else if (key < center) {
			return bin_search1(key, start, (centerpoint - 1));
		}
	}
}



int bin_search2(int key, int start, int end) {
	if (end < start) {
		return -1;
	}
	if ((end - start) <= 1) {
		if (sorted[start] == key) {
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
			return centerpoint;
		} else if (key > center) {
			return bin_search2(key, centerpoint, end);
		} else if (key < center) {
			return bin_search2(key, start, centerpoint);
		}
	}
}

int main() {
	get_input();

	int wrong_n = 0;

	for(int i = 0; i < keys.size(); ++i) {
		int idx1	 = bin_search1(keys[i], 0, (sorted.size() - 1)) + 1;
		int idx2	 = bin_search2(keys[i], 0, (sorted.size() - 1)) + 1;
		int idx_f  = distance(sorted.begin(), find(sorted.begin(), sorted.end(), keys[i]));
		if (idx_f == sorted.size())
			idx_f = 0;
		else
			idx_f++;

		if ((idx1 != idx_f)) {
			cout << idx1 << " " << idx2 << " " << idx_f << endl;
			++wrong_n;
		}
	}
	cout << wrong_n << endl;
	return 0;
}
