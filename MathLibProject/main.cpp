#include <iostream>
#include "Poly.hpp"

using namespace std;

int main() {
	Poly<int> p(vector<int>{1, 2, 3}), q(vector<int>{4, 5});
	p += q;
	cout << p << "\n";
	p *= p;
	p %= p;
	p /= p;
	p -= p;
}