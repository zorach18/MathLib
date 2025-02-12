#pragma once
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template<typename C>
class Poly : public vector<C> {
public:
	using vector<C>::vector;
	void clearLeadingZeros();
	void addShift(int x);
	int degree();
};
template<typename C>
ostream& operator<<(ostream& os, Poly<C> polynom);

template<typename C>
Poly<C> operator+(const Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C> operator-(const Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C> operator*(const Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C> operator/(const Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C> operator%(const Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C>& operator+=(Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C>& operator-=(Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C>& operator*=(Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C>& operator/=(Poly<C>&, const Poly<C>&);
template<typename C>
Poly<C>& operator%=(Poly<C>&, const Poly<C>&);

template<typename C>
void Poly<C>::clearLeadingZeros() {
	while (!vector<C>::empty() && vector<C>::back() == C()) {
		vector<C>::pop_back();
	}
}

template<typename C>
void Poly<C>::addShift(int x) {
	if (x >= 0) {
		vector<C>::resize(vector<C>::size() + x);
		for (int i = (int)vector<C>::size() - 1; i >= 0; i--) {
			if (i >= x) {
				*(vector<C>::begin() + i) = *(vector<C>::begin() + i - x);
			} else {
				*(vector<C>::begin() + i) = C();
			}
		}
	} else {
		if ((int)vector<C>::size() + x >= 0) {
			for (int i = 0; i < vector<C>::size() + x; i++) {
				*(vector<C>::begin() + i) = *(vector<C>::begin() + i - x);
			}
			vector<C>::resize(vector<C>::size() + x);
		} else {
			vector<C>::clear();
		}
	}
}

template<typename C>
int Poly<C>::degree() {
	clearLeadingZeros();
	return (int)vector<C>::size() - 1;
}

template<typename C>
Poly<C>& operator+=(Poly<C>& a, const Poly<C>& b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); i++) {
		a[i] += b[i];
	}
	a.clearLeadingZeros();
	return a;
}

template<typename C>
Poly<C>& operator-=(Poly<C>& a, const Poly<C>& b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
	a.clearLeadingZeros();
	return a;
}

template<typename C>
Poly<C>& operator*=(Poly<C>& a, const Poly<C>& b) {
	a = a * b;
	return a;
}

template<typename C>
Poly<C>& operator/=(Poly<C>& a, const Poly<C>& b) {
	a = a / b;
	return a;
}

template<typename C>
Poly<C>& operator%=(Poly<C>& a, const Poly<C>& b) {
	a = a % b;
	return a;
}

template<typename C>
Poly<C> operator+(const Poly<C>& a, const Poly<C>& b) {
	Poly<C> res = a;
	res += b;
	return res;
}

template<typename C>
Poly<C> operator-(const Poly<C>& a, const Poly<C>& b) {
	Poly<C> res = a;
	res -= b;
	return res;
}

template<typename C>
Poly<C> operator*(const Poly<C>& a, const Poly<C>& b) {
	Poly<C> res = Poly<C>();
	res.resize(a.size() + b.size());
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			res[i + j] += a[i] * b[j];
		}
	}
	res.clearLeadingZeros();
	return res;
}

template<typename C>
Poly<C> operator/(const Poly<C>& c, const Poly<C>& d) {
	Poly<C> a = c, b = d, t;
	assert(b.size() > 0);
	int resSize = max(0, (int)a.size() - (int)b.size() + 1);
	Poly<C> res(resSize);
	while (a.size() >= b.size()) {
		C k = a.back() / b.back();
		assert(b.back() * k == a.back());
		res[a.size() - b.size()] = k;
		t = Poly<C>{k} * b;
		t.addShift(a.size() - b.size());
		a -= t;
	}
	return res;
}

template<typename C>
Poly<C> operator%(const Poly<C>& c, const Poly<C>& d) {
	Poly<C> a = c, b = d, t;
	assert(b.size() > 0);
	while (a.size() >= b.size()) {
		C k = a.back() / b.back();
		assert(b.back() * k == a.back());
		t = Poly<C>{k} *b;
		t.addShift(a.size() - b.size());
		a -= t;
	}
	return a;
}

template<typename C>
ostream& operator<<(ostream& os, Poly<C> polynom) {
	polynom.clearLeadingZeros();
	os << "{";
	for (int i = 0; i < polynom.size(); i++) {
		if (i > 0) {
			os << ", ";
		}
		os << polynom[i];
	}
	os << "}";
	return os;
}
