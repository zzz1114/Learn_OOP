//#include <iostream>
//using namespace std;
//
//class Complex {
//	friend Complex operator+(Complex& c1, int m);
//	friend std::ostream& operator<<(std::ostream &out, Complex& a);
//	friend std::ostream& operator<<(std::ostream &out, Complex a);
//	friend  Complex& operator++(Complex& c1);
//	friend Complex operator++(Complex& c1, int);
//public:
//	Complex() : m_Real(0), m_Imag(0) {}
//	Complex(int real, int imag) : m_Real(real), m_Imag(imag) {}
//	Complex& operator+(Complex &comp);
//	//Complex& operator++();
//	//Complex& operator++(int);
//	//��ʾ�����show�����ǳ�Ա��������˿��Է���������˽������
//	void Show() const { cout << m_Real << " + " << m_Imag << "i" << endl; }
//private:
//	//ʵ��
//	int m_Real;
//	//�鲿
//	int m_Imag;
//};
//
////�Ӻ�����
//Complex& Complex::operator+(Complex &comp)
//{
//	Complex temp;
//	temp.m_Real = this->m_Real + comp.m_Real;
//	temp.m_Imag = this->m_Imag + comp.m_Imag;
//	return temp;
//}
//
//Complex operator+(Complex& c1, int m)
//{
//	Complex temp;
//	temp.m_Real = c1.m_Real + m;
//	temp.m_Imag = c1.m_Imag;
//	return temp;
//}
//
////�������������
//std::ostream& operator<<(std::ostream &out, Complex& a)
//{
//	out << a.m_Real << " + " << a.m_Imag << "i" << endl;
//	return out;
//}
////std::ostream& operator<<(std::ostream &out, Complex a)
////{
////	out << a.m_Real << " + " << a.m_Imag << "i" << endl;
////	return out;
////}
//
////�������������++		���� ++a
////Complex& Complex::operator++()
////{
////	m_Real += 1;
////	return *this;
////}
////Complex& Complex::operator++(int)
////{
////	Complex temp = *this;
////	m_Real++;
////	return temp;
////}
//
//Complex& operator++(Complex& c1)
//{
//	c1.m_Real++;
//	return c1;
//}
//Complex operator++(Complex& c1, int)
//{
//	Complex temp = c1;
//	c1.m_Real++;
//	return temp;
//}
//
//void test01()
//{
//	Complex a(2, 4), b(1, 5);
//	a.Show();
//	(a + b).Show();
//	(a + 5).Show();
//	//a.operator+(b).Show();
//}
//
//void test02()
//{
//	Complex a(2, 4);
//	Complex b(1, 3);
//	//std::cout << a;
//	//a.operator<<(cout);
//	//a << cout;
//	cout << a++;
//	++a;
//	cout << ++a;
//}
//
//int main()
//{
//	//test01();
//	test02();
//	return 0;
//}