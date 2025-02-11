#pragma once
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
	return res;
}

template<typename C>
Poly<C> Poly<C>::operator/(const Poly<C>& other) const {
	return Poly<C>();
}

template<typename C>
Poly<C> Poly<C>::operator%(const Poly<C>& other) const {
	return Poly<C>();
}