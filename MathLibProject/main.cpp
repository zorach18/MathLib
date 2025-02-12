#include <iostream>
#include "Module.hpp"
#include "Poly.hpp"

using namespace std;
#define C Module<int>
#define P Poly<C>
#define R Module<P>

int C::m = 17;
int C::n0 = 0;
int C::ord = C::m - 1;

P R::m{0, 1, 2, 3};
P R::n0{};
int R::ord = binpow(C::m, R::m.degree()) - 1;

int main() {
	cout << binpow(3, 5) << "\n";
	Module<int> x(5), y(-20);
	cout << x << " " << y << "\n";
	cout << x + y << " " << x - y << "\n";
	cout << x * y << " " << (x * y == Module<int>(2)) << "\n";
	cout << x / y << "\n";

	//Poly<int> a(5, 1), b{3, 4, 5, 1, -1};
	//cout << a << "\n";
	//cout << b << "\n";
	//cout << a + b << "\n";
	//cout << a - b << "\n";
	//cout << a / b << "\n";
	//cout << a % b << "\n";
	//Poly<int> m{2}, n{1, 2, 3};
	//cout << "\n\n\n\n\n";
	//cout << m << "\n";
	//cout << n << "\n";
	//cout << m + n << "\n";
	//cout << n - m << "\n";
	//cout << m / n << "\n";
	//cout << n % m << "\n";
}