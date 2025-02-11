#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<typename C>
class Poly {
public:
	vector<C> p;
	Poly();
	Poly(C c);
	Poly(const vector<C>& p_);
	void clearLeadingZeros();
	int size() const;
	C& back();
	C back() const;
	C& operator[](int ind);
	C operator[](int ind) const;
	void operator+=(const Poly<C>& other);
	void operator-=(const Poly<C>& other);
	void operator*=(const Poly<C>& other);
	void operator/=(const Poly<C>& other);
	void operator%=(const Poly<C>& other);
	Poly<C> operator+(const Poly<C>& other) const;
	Poly<C> operator-(const Poly<C>& other) const;
	Poly<C> operator*(const Poly<C>& other) const;
	Poly<C> operator/(const Poly<C>& other) const;
	Poly<C> operator%(const Poly<C>& other) const;
};
template<typename C>
ostream& operator<<(ostream& os, const Poly<C>& polynom);


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
void Poly<C>::clearLeadingZeros() {
	while (!p.empty() && p.back() == 0) {
		p.pop_back();
	}
}

template<typename C>
int Poly<C>::size() const {
	return p.size();
}

template<typename C>
C& Poly<C>::back() {
	return p.back();
}

template<typename C>
C Poly<C>::back() const {
	return p.back();
}

template<typename C>
C& Poly<C>::operator[](int ind) {
	return p[ind];
}

template<typename C>
C Poly<C>::operator[](int ind) const {
	return p[ind];
}

template<typename C>
void Poly<C>::operator+=(const Poly<C>& other) {
	p.resize(max(size(), other.size()));
	for (int i = 0; i < other.size(); i++) {
		p[i] += other[i];
	}
	clearLeadingZeros();
}

template<typename C>
void Poly<C>::operator-=(const Poly<C>& other) {
	p.resize(max(size(), other.size()));
	for (int i = 0; i < other.size(); i++) {
		p[i] -= other[i];
	}
	clearLeadingZeros();
}

template<typename C>
void Poly<C>::operator*=(const Poly<C>& other) {
	*this = *this * other;
}

template<typename C>
void Poly<C>::operator/=(const Poly<C>& other) {
	*this = *this / other;
}

template<typename C>
void Poly<C>::operator%=(const Poly<C>& other) {
	*this = *this % other;
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
	Poly<C> res = Poly<C>();
	res.p.resize(p.size() + other.size());
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < other.size(); j++) {
			res[i + j] += p[i] * other[j];
		}
	}
	res.clearLeadingZeros();
	return res;
}

template<typename C>
Poly<C> Poly<C>::operator/(const Poly<C>& other) const {
	Poly<C> a = *this, res = Poly<C>();
	vector<C> p(a.size() - other.size() + 1, C());
	while (a.size() >= other.size()) {
		p.resize(a.size() - other.size() + 1);
		p.back() = a.back() / other.back();
		a -= other * p;
		res += p;
	}
	return res;
}

template<typename C>
Poly<C> Poly<C>::operator%(const Poly<C>& other) const {
	Poly<C> a = *this;
	vector<C> p(a.size() - other.size() + 1, C());
	while (a.size() >= other.size()) {
		p.resize(a.size() - other.size() + 1);
		p.back() = a.back() / other.back();
		a -= other * p;
	}
	return a;
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
