#pragma once
class rational {
public:
	rational();
	rational(int a, int b);
	static int gcd(int a, int b);
	static int lcm(int a, int b);
	rational operator+(const rational& other){
		int lcm = rational::lcm(denominator, other.denominator);
		int num = numerator * (lcm / denominator) + other.numerator * (lcm / other.denominator);
		rational result(num, lcm);
		result.simplify();
		return result;
	}
	friend rational operator-(const rational& r1, const rational& r2);
	rational& operator++();
	bool operator==(const rational& other);
	bool operator>(const rational& other);
	rational& operator=(const rational& other);
	void set(int a, int b);
	void show();

private:
	int numerator;
	int denominator;
	void simplify();


};


