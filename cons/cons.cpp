#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

typedef vector<vector<int>> IntMat;
typedef vector<vector<char>> CharMat;


char basePairs[4];
CharMat DNAstrings;
IntMat profile;
vector<char> cons;

void print_profile() {
	for (int i = 0; i < profile.size(); ++i) {
		switch (i) {
			case 0:
				cout << "A:";
				break;
			case 1:
				cout << "C:";
				break;
			case 2:
				cout << "G:";
				break;
			case 3:
				cout << "T:";
				break;
		}
		for (int j = 0; j < profile[i].size(); ++j) {
			cout << " " << profile[i][j];
		}
		cout << endl;
	}
}

void build_profile(int c) {
	for (int i = 0; i < 4; ++i) {
		vector<int> temp(c, 0);
		profile.push_back(temp);
	}
}

void update_profile(vector<char> s) {
	//cout << "BEFORE =======================================" << endl;
	//print_profile();

	for (int i = 0; i < s.size(); ++i) {
		switch (s[i]) {
			case 'A':
				profile[0][i]++;
				break;
			case 'C':
				profile[1][i]++;
				break;
			case 'G':
				profile[2][i]++;
				break;
			case 'T':
				profile[3][i]++;
				break;
		}
	}
	//cout << "AFTER ======================" << endl;
	//print_profile();
	//cout << "=======================================" << endl;
}


void build_cons(){
	//loop through profile, left to right
	for(int i = 0; i < profile[0].size(); ++i){
		int max = 0;
		int maxidx = 0;
		//find max index
		for(int j = 0; j < profile.size(); ++j){
			if (profile[j][i] > max){
				max = profile[j][i];
				maxidx = j;
			}
		}
		//get appropriate base from index
		char base = basePairs[maxidx];
		cons.push_back(base);
	}


	//add most commen letter to 
}

void print_cons(){
	for(int i = 0; i < cons.size(); ++i){
		cout << cons[i];
	}
	cout << endl;
}

//read in the strings from file
int readInStrings() {
	ifstream fasta_file("rosalind_cons.txt");
	string line;
	string working;
	//get a line
	while (fasta_file >> line) {
		//if its a name
		if(line[0] == '>') {
			if (working.size() > 0) {
				//append current working string to main matrix
				vector<char> workingCharVec(working.begin(), working.end());
				DNAstrings.push_back(workingCharVec);
				working = "";
			}
		} else {
			//append line to working stirng
			working += line;
		}
	}
	vector<char> workingCharVec(working.begin(), working.end());
	DNAstrings.push_back(workingCharVec);
}

int main() {
	//setup base pair mapping vector
	basePairs[0] = 'A'; 
	basePairs[1] = 'C'; 
	basePairs[2] = 'G'; 
	basePairs[3] = 'T'; 

	//read in the strings from file
	readInStrings();

	//create profile
	build_profile(DNAstrings[0].size());
	for (int i = 0; i < DNAstrings.size(); ++i) {
		update_profile(DNAstrings[i]);
	}

	//create cons string
	build_cons();

	//output both the profile and cons
	print_cons();
	print_profile();
	return 0;
}


