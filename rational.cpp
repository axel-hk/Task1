#include "rational.h"
#include <numeric>
#include <stdexcept>
#include <iostream>
using namespace std;

rational::rational() {}
rational::rational(int a, int b) {
	if (b == 0) {
		throw std::invalid_argument("Denominator cannot be zero");
	}
	if (a > b) {
		numerator = a % b;
		denominator = b;
	}
	else {
		numerator = a;
		denominator = b;
	}
	simplify();
}

void rational::set(int a, int b) {
	if (b == 0) {
		throw std::invalid_argument("Denominator cannot be zero");
	}
	if (a > b) {
		numerator = a % b;
		denominator = b;
	}
	else {
		numerator = a;
		denominator = b;
	}
	simplify();
}


void rational::simplify() {
		int gcd_val = gcd(numerator, denominator);
		numerator /= gcd_val;
		denominator /= gcd_val;
}

void rational::show() {
	cout << numerator << "/" << denominator;
}

int rational::gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int rational::lcm(int a, int b) {
	return a * b / gcd(a, b);
}


rational& rational::operator++() {
	numerator += denominator;
	simplify();
	return *this;
}

bool rational::operator==(const rational& other) {
	return (numerator == other.numerator && denominator == other.denominator);
}

bool rational::operator>(const rational& other)  {
	return (numerator * other.denominator > denominator * other.numerator);
}

rational& rational::operator=(const rational& other) {
	if (this != &other) {
		numerator = other.numerator;
		denominator = other.denominator;
	}
	return *this;
}

rational operator-(const rational& r1, const rational& r2) {
	int lcm = rational::lcm(r1.denominator, r2.denominator);
	int num = r1.numerator * (lcm / r1.denominator) - r2.numerator * (lcm / r2.denominator);
	rational result(num, lcm);
	result.simplify();
	return result;
}
