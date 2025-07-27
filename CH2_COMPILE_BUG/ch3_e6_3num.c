// Just a simple hello world test
// g++ -std=c++11 -g -o ch3_e6_3num.exe ch3_e6_3num.c  2>&1 | tee tmp.txt

#include "std_lib_facilities.h"
int main()
{
	cout << "Enter 3 integers\n";
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	cout << n1 << " " << n2 << " " << n3 << endl;
	if (n1 < n2 < n3) {
		cout << "True\n";
	} else {
		cout << "False\n";
	}

	cout << "n1 < n2 " << (n1 < n2) << endl; 

	cout << n1 << " " << n2 << " " << n3 << endl;

}
