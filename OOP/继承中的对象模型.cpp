//#include <iostream>
//
//class Base {
//public:
//	Base(): m_A(200) { std::cout << "���๹�캯������" << std::endl; }
//	~Base() { std::cout << "����������������" << std::endl; }
//	int m_A;
//	void Show() { std::cout << "show func in Base" << std::endl; }
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class A : public Base {
//public:
//	A() : m_A(100) { std::cout << "�����๹�캯������" << std::endl; }
//	~A() { std::cout << "������������������" << std::endl; }
//	int m_A;
//	void Show() { std::cout << "show func in A " << std::endl; }
//};
//
//void test01()
//{
//	A a;
//	a.Show();
//	a.Base::Show();
//	std::cout << "---------------" << std::endl;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}