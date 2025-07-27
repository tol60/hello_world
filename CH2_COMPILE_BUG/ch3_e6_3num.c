// Just a simple hello world test
// g++ -std=c++11 -g -o ch3_e6_3num.exe ch3_e6_3num.c  2>&1 | tee tmp.txt
// Input 3 int numbers.
// Ouput them in increasing order

#include "std_lib_facilities.h"
int main()
{
	cout << "Enter 3 integers\n";
	int n1, n2, n3;
	int tmp;
	cin >> n1 >> n2 >> n3;
	
	// S1. order n1, n2
	if (n1 > n2) {
		tmp = n2;
		n2 = n1;
		n1 = tmp;
	}	

	// S2. order n2, n3
	if (n2 > n3) {
		tmp = n3;
		n3 = n2;
		n2 = tmp;
	}	

	// Need to check this again, as n2 might have been swapped with 3
	// Original input 1 3 2
	// S3. order n1, n2
	if (n1 > n2) {
		tmp = n2;
		n2 = n1;
		n1 = tmp;
	}	

	cout << n1 << " " << n2 << " " << n3 << endl;

}
