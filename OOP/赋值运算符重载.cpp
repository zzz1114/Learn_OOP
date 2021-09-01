#include <iostream>
using namespace std;

class Complex {
	friend std::ostream& operator<<(std::ostream& cout, Complex& c);
public:
	Complex(int i, int j) : m_Real(i), m_Imag(j) { }
	Complex operator+(Complex& c2);
	Complex operator-(Complex& c2);
	Complex& operator=(Complex& c2);

	void Show() const { cout << m_Real << " + " << m_Imag << "i" << endl; }
private:
	//Êµ²¿
	int m_Real;
	//Ðé²¿
	int m_Imag;
};

Complex Complex::operator+(Complex& c2)
{
	Complex temp(0, 0);
	temp.m_Imag += c2.m_Imag;
	temp.m_Real += c2.m_Real;
	return temp;
}

Complex Complex::operator-(Complex& c2)
{
	this->m_Imag -= c2.m_Imag;
	this->m_Real -= c2.m_Real;
	return *this;
}

Complex& Complex::operator=(Complex& c2)
{
	Complex temp(0, 0);
	temp.m_Imag = c2.m_Imag;
	temp.m_Real = c2.m_Real;
	return temp;
}

std::ostream& operator<<(std::ostream& cout, Complex& c)
{
	cout << c.m_Real << ((c.m_Imag > 0) ? " + " : " - ") << abs(c.m_Imag) << "i ";
	return cout;
}

void test01()
{
	Complex c1(1, 2);
	Complex c2(2, 5);
	Complex c3(-2, -3);
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;
	cout << "c1 + c2 = " << c1 + c2 << endl;
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;
	c3 = c1 + c2;
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;
	//a.operator+(b).Show();
}

int main()
{
	test01();
	return 0;
}