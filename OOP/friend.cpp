//#include <iostream>
//#include <string>
//
//class A;
//class B {
//public:
//    B();
//    void set();
//private:
//    A *a;
//};
//
//B::B()  
//{
//    a = new A;
//}
//
//class A {
//    friend void B::set();
//public:
//    void display() { std::cout << m_X << std::endl; }
//    int getX() { return m_X; }
//private:
//    int m_X;
//};
//
//
//
//void B::set()
//{
//    a->m_X = 10;
//}
//
//void test1()
//{
//    B b;
//    b.set();
//}
//
//int main()
//{
//    test1();
//
//	return 0;
//}