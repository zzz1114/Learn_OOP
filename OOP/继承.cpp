//#include <iostream>
//
//class Base {
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Pub : public Base {
//public:
//	void func4() { m_A = 10; m_B = 10; }
//};
//
//class Pro : protected Base {
//public:
//	void func5() { m_A = 10; m_B = 10; }
//};
//
//class Pri : private Base {
//public:
//	void func6() { m_A = 10; m_B = 10; }
//};
//
//class Pro2 : public Pro {
//	void func() {
//		m_A = 10;
//		m_B = 10;
//	}
//};
//
//class Pri2 : public Pri {
//	void func()
//	{
//		m_A = 10;
//		m_B = 10;
//	}
//};
//
//void test01()
//{
//	Base base;
//	Pub pub;
//	Pro pro;
//	Pri pri;
//	
//}
//
//
//int main()
//{
//	test01();
//	return 0;
//}