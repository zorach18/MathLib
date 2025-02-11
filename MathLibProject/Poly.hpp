#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename C>
class Poly : public vector<C> {
public:
	using vector<C>::vector;
	void clearLeadingZeros();
	void addShift(int x);
};
template<typename C>
ostream& operator<<(ostream& os, const Poly<C>& polynom);

template<typename C>
void Poly<C>::clearLeadingZeros() {
	while (!this->empty() && this->back() == 0) {
		this->pop_back();
	}
}

template<typename C>
void Poly<C>::addShift(int x) {
	if (x >= 0) {
		resize(this->size() + x);
		for (int i = (int)this->size() - 1; i >= 0; i--) {
			if (i >= x) {
				*(this->begin() + i) = *(this->begin() + i - x);
			} else {
				*(this->begin() + i) = C();
			}
		}
	} else {
		if ((int)this->size() + x >= 0) {
			*this = vector<C>(this->begin() - x, this->end());
		} else {
			this->clear();
		}
	}
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
Poly<C> operator/(const Poly<C>& a, const Poly<C>& b) {
	assert(b.size() > 0);
	int resSize = max(0, (int)a.size() - (int)b.size());
	Poly<C> res(resSize), c = a;
	while (c.size() >= b.size()) {
		C k = c.back() / b.back();
		assert(b.back() * k == c.back());
		c -= (k * b).addShift(c.size() - b.size());
		res[c.size() - b.size()] = k;
	}
	return res;
}

template<typename C>
Poly<C> operator%(const Poly<C>& a, const Poly<C>& b) {
	assert(b.size() > 0);
	Poly<C> c = a;
	while (c.size() >= b.size()) {
		C k = c.back() / b.back();
		assert(b.back() * k == c.back());
		c -= (k * b).addShift(c.size() - b.size());
	}
	return c;
}

template<typename C>
ostream& operator<<(ostream& os, const Poly<C>& polynom) {
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
