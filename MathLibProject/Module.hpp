#pragma once
#include <iostream>
#include <cassert>

using namespace std;


template<typename T>
T binpow(T a, int n);

template<typename N>
class Module {
public:
	N a;
	static N m;
	static N n0;
	static int ord;
	Module();
	Module(N);
};
template<typename N>
Module<N> binpow(Module<N> a, int n);
template<typename N>
bool operator==(const Module<N>& a, const Module<N>& b);
template<typename N>
bool operator!=(const Module<N>& a, const Module<N>& b);
template<typename N>
ostream& operator<<(ostream& os, const Module<N>& a);

template<typename N>
Module<N> operator+(const Module<N>&, const Module<N>&);
template<typename N>
Module<N> operator-(const Module<N>&, const Module<N>&);
template<typename N>
Module<N> operator*(const Module<N>&, const Module<N>&);
template<typename N>
Module<N> operator/(const Module<N>&, const Module<N>&);
template<typename N>
Module<N>& operator+=(Module<N>&, const Module<N>&);
template<typename N>
Module<N>& operator-=(Module<N>&, const Module<N>&);
template<typename N>
Module<N>& operator*=(Module<N>&, const Module<N>&);
template<typename N>
Module<N>& operator/=(Module<N>&, const Module<N>&);

template<typename N>
Module<N>::Module() {
	a = N();
}

template<typename N>
Module<N>::Module(N a_) {
	a = a_ % m;
}

template<typename N>
Module<N> operator+(const Module<N>& a, const Module<N>& b) {
	return Module<N>((a.a + b.a) % Module<N>::m);
}

template<typename N>
Module<N> operator-(const Module<N>& a, const Module<N>& b) {
	return Module<N>((a.a - b.a) % Module<N>::m);
}

template<typename N>
Module<N> operator*(const Module<N>& a, const Module<N>& b) {
	return Module<N>((a.a * b.a) % Module<N>::m);
}

template<typename N>
Module<N> operator/(const Module<N>& a, const Module<N>& b) {
	assert(b != Module<N>(Module<N>::n0));
	return a * binpow(b, Module<N>::ord - 1);
}

template<typename N>
Module<N>& operator+=(Module<N>& a, const Module<N>& b) {
	a = a + b;
	return a;
}

template<typename N>
Module<N>& operator-=(Module<N>& a, const Module<N>& b) {
	a = a - b;
	return a;
}

template<typename N>
Module<N>& operator*=(Module<N>& a, const Module<N>& b) {
	a = a * b;
	return a;
}

template<typename N>
Module<N>& operator/=(Module<N>& a, const Module<N>& b) {
	a = a / b;
	return a;
}

template<typename T>
T binpow(T a, int n) {
	assert(n >= 1);
	n--;
	T ans = a;
	while (n > 0) {
		if (n & 1) ans = (ans * a);
		a = (a * a);
		n >>= 1;
	}
	return ans;
}

template<typename N>
Module<N> binpow(Module<N> a, int n) {
	n = (n % Module<N>::ord) + Module<N>::ord - 1;
	Module<N> ans = a;
	while (n > 0) {
		if (n & 1) ans = (ans * a);
		a = (a * a);
		n >>= 1;
	}
	return ans;
}

template<typename N>
bool operator==(const Module<N>& a, const Module<N>& b) {
	return ((a.a - b.a) % Module<N>::m == Module<N>::n0);
}

template<typename N>
bool operator!=(const Module<N>& a, const Module<N>& b) {
	return ((a.a - b.a) % Module<N>::m != Module<N>::n0);
}

template<typename N>
ostream& operator<<(ostream& os, const Module<N>& a) {
	os << a.a;
	return os;
}