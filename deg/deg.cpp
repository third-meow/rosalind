#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


int main() {
	ifstream file("rosalind_deg.txt");
	int node_n, edge_n;
	file >> node_n;
	file >> edge_n; 
	vector<int> nodes(node_n, 0);
	for (int i = 0; i < edge_n; ++i) {
		int to, from;
		file >> to;
		file >> from;
		++nodes[to - 1];
		++nodes[from - 1];
	}

	cout << node_n << " " << edge_n << endl;
	cout << nodes[0];
	for (int i = 1; i < node_n; ++i) {
		cout << " " << nodes[i];
	}

	return 0;
}
