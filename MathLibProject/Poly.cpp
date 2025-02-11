#include "Poly.h"
#include <iostream>
using namespace std;

template<typename C>
Poly<C>::Poly() {
	p = {};
}

template<typename C>
Poly<C>::Poly(C c) {
	p = vector<C>{c};
}

template<typename C>
Poly<C>::Poly(const vector<C>& p_) {
	p = p_;
}

template<typename C>
void Poly<C>::operator+=(const Poly<C>& other) {
	int x = 0;
}

template<typename C>
void Poly<C>::operator-=(const Poly<C>& other) {
}

template<typename C>
void Poly<C>::operator*=(const Poly<C>& other) {
}

template<typename C>
void Poly<C>::operator/=(const Poly<C>& other) {
}

template<typename C>
void Poly<C>::operator%=(const Poly<C>& other) {
}

template<typename C>
Poly<C> Poly<C>::operator+(const Poly<C>& other) const {
	Poly<C> res = *this;
	res += other;
	return res;
}

template<typename C>
Poly<C> Poly<C>::operator-(const Poly<C>& other) const {
	Poly<C> res = *this;
	res -= other;
	return res;
}

template<typename C>
Poly<C> Poly<C>::operator*(const Poly<C>& other) const {
	Poly<C> res = *this;
	res *= other;
	return res;
}

template<typename C>
Poly<C> Poly<C>::operator/(const Poly<C>& other) const {
	Poly<C> res = *this;
	res /= other;
	return res;
}

template<typename C>
Poly<C> Poly<C>::operator%(const Poly<C>& other) const {
	Poly<C> res = *this;
	res %= other;
	return res;
}

template<class C>
void Y<C>::f() {
	int aboba = 0;
	cout << ++aboba << " " << aboba++ << "\n";
}
