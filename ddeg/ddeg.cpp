#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

int node_n;
int edge_n;
vector<vector<int>> edges;

vector<vector<bool>> adj_list;

void get_input() {
	ifstream file("rosalind_ddeg.txt");
	file >> node_n;
	file >> edge_n;

	for(int i = 0; i < edge_n; ++i) {
		vector<int> pair(2, 0);
		file >> pair[0] >> pair[1];
		--pair[0];
		--pair[1];
		edges.push_back(pair);
	}
}

void build_adjacency_list() {
	for (int i = 0; i < node_n; ++i) {
		vector<bool> temp(node_n, false);
		adj_list.push_back(temp);
	}

	if (adj_list.size() != adj_list[0].size()) {
		cout << "ADJ LIST CORRUPTED" << endl;
		while (true) {}
	}

	for (int i = 0; i < edge_n; ++i) {
		adj_list[edges[i][0]][edges[i][1]] = true;
		adj_list[edges[i][1]][edges[i][0]] = true;
	}
}

int sum_trues(vector<bool> set) {
	int n = 0;
	for (int i = 0; i < set.size(); ++i) {
		if (set[i]){
			++n;
		}
	}
	return n;
}

int sum_edges(int node_idx) {
	return sum_trues(adj_list[node_idx]);
}

vector<int> get_neighbours(int node_idx) {
	vector<int> neighbours;
	for (int i = 0; i < node_n; ++i) {
		if (adj_list[node_idx][i]) {
			neighbours.push_back(i);
		}
	}
	return neighbours;
}

int neighbours_edges(int node_idx) {
	vector<int> neighbours = get_neighbours(node_idx);

	int total = 0;
	for (int i = 0; i < neighbours.size(); ++i) {
		total += sum_edges(neighbours[i]);
	}
	return total;

}


int main() {
	get_input();
 	build_adjacency_list();

	vector<int> output;
	for (int i = 0; i < node_n; ++i) {
		output.push_back(neighbours_edges(i));
	}

	cout << output[0];
	for (int i = 1; i < output.size(); ++i) {
		cout << " " << output[i];
	}

	return 0;
}
