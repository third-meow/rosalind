#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

vector<int> arr1;
vector<int> arr2;
vector<int> sorted;
int minlen;

void get_input() {
	ifstream file("rosalind_mer.txt");

	file >> minlen;
	for(int i = 0; i < minlen; ++i) {
		int num;
		file >> num;
		arr1.push_back(num);
	}


	int len;
	file >> len;

	if (len < minlen)
		minlen = len;


	for(int i = 0; i < len; ++i) {
		int num;
		file >> num;
		arr2.push_back(num);
	}

}

int pop_front(vector<int>& vec) {
	int num = vec.front();
	vector<int> newvec(vec.begin() + 1, vec.end());
	vec = newvec;
	return num;
}

int main() {
	get_input();

	while(!(arr1.empty()) && !(arr2.empty())){
		if (arr1[0] < arr2[0])
			sorted.push_back(pop_front(arr1));
		else
			sorted.push_back(pop_front(arr2));
	}

	if (!(arr1.empty())){
		for(auto x: arr1)
			sorted.push_back(x);
	} else if (!(arr2.empty())) {
		for(auto x: arr2)
			sorted.push_back(x);
	}


	cout << sorted[0];
	for(int i = 1; i < sorted.size(); ++i) {
		cout << " " << sorted[i];
	}



	return 0;
}
