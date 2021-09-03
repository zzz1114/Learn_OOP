//#include <iostream>
//
//class Base {
//public:
//	Base(): m_A(200) { std::cout << "基类构造函数调用" << std::endl; }
//	~Base() { std::cout << "基类析构函数调用" << std::endl; }
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
//	A() : m_A(100) { std::cout << "派生类构造函数调用" << std::endl; }
//	~A() { std::cout << "派生类析构函数调用" << std::endl; }
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