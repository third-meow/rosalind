#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

struct DNAString {
	string name;
	string str;
	int strlen;
};

char complement(char in) {
	switch (in) {
		case 'A':
			return 'T';
		case 'T':
			return 'A';
		case 'G':
			return 'C';
		case 'C':
			return 'G';
	}
	return -1;
}

bool rev_pldm(string instr) {
	string rev_comp;
	for (int i = 0; i < instr.size(); ++i) {
		rev_comp += complement(instr[i]);
	}
	reverse(rev_comp.begin(), rev_comp.end());

	if (rev_comp == instr) {
		return true;
	} else {
		return false;
	}
}


int main(int argc, char* argv[]) {
	ifstream fasta_file("rosalind_revp.txt");
	DNAString data;

	//get string name
	fasta_file >> data.name;

	//get DNA string 
	string line;
	while (fasta_file >> line) {
		data.str += line;
	};

	//calc DNA string length
	data.strlen = data.str.size();

	//find reverse palindromes
	for (int i = 0; i < data.strlen; ++i) {
		for (int j = 4; j <= 12; ++j) {

			if ((i + j) > data.strlen)
				break;

			if (rev_pldm(data.str.substr(i,j))) {
				cout << (i + 1) << " " << j << endl;
				//cout << data.str.substr(i,j) << endl << endl;
			}

			}
		}
		cout << data.strlen << endl;	
		return 0;
	}


