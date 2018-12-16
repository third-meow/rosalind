#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<fstream>
using namespace std;

int arr_n, arr_len;

vector<vector<int>> arrs;

void get_input() {
	ifstream file("rosalind_maj.txt");
	file >> arr_n;
	file >> arr_len;

	for(int i = 0; i < arr_n; ++i) {
		vector<int> temp_arr;
		for(int j = 0; j < arr_len; ++j) {
			int temp_elmt;
			file >> temp_elmt;
			temp_arr.push_back(temp_elmt);
		}
		arrs.push_back(temp_arr);
	}
}

int maj_elmt(vector<int> vec) {
	//build key-freq map
	map<int, int> freq_map;
	for(int i = 0; i < arr_len; ++i) {
		if (freq_map.find(vec[i]) != freq_map.end()) {
			freq_map[vec[i]]++;
		} else {
			freq_map[vec[i]] = 1;
		}
	}

	//find most freq key
	int max_val = 0;
	int max_key = 0;
	for (auto pair : freq_map) {
		if (pair.second > max_val) {
			max_key = pair.first;
			max_val = pair.second;
		}
	}

	if (max_val > (arr_len / 2)) { 
		return max_key; 
	} else {
		return -1;
	}

}
	


int main() {
	get_input();

	vector<int> output;
	for(int i = 0; i < arr_n; ++i) {
		output.push_back(maj_elmt(arrs[i]));
	}

	cout << output[0];
	for(int i = 1; i < output.size(); ++i) {
		cout << " " << output[i];
	}

	return 0;
}
