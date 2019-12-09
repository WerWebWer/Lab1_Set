#include <iomanip>

#define USE_SET // using class TSet,
                // comment out to use bitfield

#ifndef USE_SET // using class TBitField

#include "tbitfield.h"

int main() {
	int n, m, k, count;
	cout << "Testing multiple support programs. Resheto Eratosfena" << endl;
	cout << "Enter the upper bound of integer values : ";
	cin >> n;
	TSet s(n + 1);
	for (m = 2; m <= n; m++) s.InsElem(m); // filling the set
	for (m = 2; m * m <= n; m++) //validation to sqrt (n) and removal of multiples
		if (s.IsMember(m)) for (k = 2 * m; k <= n; k += m) if (s.IsMember(k)) s.DelElem(k); //if M in S, removal of multiples
	// the remaining elements in S are prime numbers
	cout << endl << "Printing multiple non-multiple numbers" << endl << s << endl << endl << "Printing prime numbers" << endl;
	count = 0;
	k = 1;
	for (m = 2; m <= n; m++)
		if (s.IsMember(m)) {
			count++;
			cout << setw(3) << m << " ";
			if (k++ % 10 == 0)
				cout << endl;
		}
	cout << endl;
	cout << "Firstly " << n << " numbers " << count << " prime" << endl;
}
#else

#include "tset.h"

int main() {
	int n, m, k, count;
	cout << "Testing multiple support programs. Resheto Eratosfena" << endl;
	cout << "Enter the upper bound of integer values : ";
	cin >> n;
	TSet s(n + 1);
	for (m = 2; m <= n; m++) s.InsElem(m); //filling the set
	for (m = 2; m * m <= n; m++) //validation to sqrt (n) and removal of multiples
		if (s.IsMember(m)) for (k = 2 * m; k <= n; k += m) if (s.IsMember(k)) s.DelElem(k); //if M in S, removal of multiples
	//the remaining elements in S are prime numbers
	cout << endl << "Printing multiple non-multiple numbers" << endl << s << endl << endl << "Printing prime numbers" << endl;
	count = 0;
	k = 1;
	for (m = 2; m <= n; m++)
		if (s.IsMember(m)) {
			count++;
			cout << setw(3) << m << " ";
			if (k++ % 10 == 0)
				cout << endl;
		}
	cout << endl;
	cout << "Firstly " << n << " numbers " << count << " prime" << endl;
}

#endif
