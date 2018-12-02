#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

int get_fib(int n) {
	if (n == 0) {
	  return 0;	
	} else if (n == 1) {
	  return 1;	
	} else {
		return get_fib(n - 1) + get_fib(n - 2);
	}
}

int main() {
	ifstream file("rosalind_fibo.txt");
	int idx;
	file >> idx;

	cout << get_fib(idx) << endl;

	return 0;
}
