#include <iostream>
using namespace std;

class Complex {
	friend std::ostream& operator<<(std::ostream& cout,const Complex& c);
public:
	Complex(int i, int j) : m_Real(i), m_Imag(j) { }
	Complex operator+(Complex& c2);
	Complex& operator=(Complex& c2);
	void operator()(string str) { cout << str << endl; }
private:
	//Êµ²¿
	int m_Real;
	//Ðé²¿
	int m_Imag;
};

Complex Complex::operator+(Complex& c2)
{
	return Complex(m_Real + c2.m_Real, m_Imag + c2.m_Imag);
}

Complex& Complex::operator=(Complex& c2)
{
	m_Real = c2.m_Real;
	m_Imag = c2.m_Imag;
	return *this;
}

std::ostream& operator<<(std::ostream& cout, const Complex& c)
{
	cout << c.m_Real << ((c.m_Imag > 0) ? " + " : " - ") << abs(c.m_Imag) << "i ";
	return cout;
}

void test01()
{
	Complex c1(1, 2);
	Complex c2(2, 5);
	const Complex c3(1, 4);
	cout << c1 << c2;
	c1("hello world ");
	//cout << c1 + c2;
}

int main()
{
	test01();
	return 0;
}