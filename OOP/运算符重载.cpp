#include <iostream>
using namespace std;

class Complex {
	friend Complex operator+(Complex& c1, int m);
	friend std::ostream& operator<<(std::ostream &out, Complex a);
public:
	Complex() : m_Real(0), m_Imag(0) {}
	Complex(int real, int imag) : m_Real(real), m_Imag(imag) {}
	Complex operator+(Complex &comp);
	void operator<<(std::ostream& out);
	//显示，这个show函数是成员函数，因此可以访问这个类的私有属性
	void Show() const { cout << m_Real << " + " << m_Imag << "i" << endl; }
private:
	//实部
	int m_Real;
	//虚部
	int m_Imag;
};
Complex Complex::operator+(Complex &comp)
{
	Complex temp;
	temp.m_Real = this->m_Real + comp.m_Real;
	temp.m_Imag = this->m_Imag + comp.m_Imag;
	return temp;
}

Complex operator+(Complex& c1, int m)
{
	Complex temp;
	temp.m_Real = c1.m_Real + m;
	temp.m_Imag = c1.m_Imag;
	return temp;
}

//左移运算符重载
std::ostream& operator<<(std::ostream &out, Complex a)
{
	out << a.m_Real << " + " << a.m_Imag << "i" << endl;
	return out;
}
void Complex::operator<<(std::ostream& out)
{
	out << m_Real << " + " << m_Imag << "i" << endl;
}


void test01()
{
	Complex a(2, 4), b(1, 5);
	a.Show();
	(a + b).Show();
	(a + 5).Show();
	//a.operator+(b).Show();
}

void test02()
{
	Complex a(2, 4);
	//std::cout << a;
	//a.operator<<(cout);
	//a << cout;
	cout << a << " hello world" << endl;
}

int main()
{
	//test01();
	test02();
	return 0;
}