//#include <iostream>
//
//class Base
//{
//public:
//    Base()
//    {
//        std::cout << "Base��Ĭ�Ϲ��캯��" << std::endl;
//    }
//    virtual ~Base()
//    {
//        std::cout << "Base����������" << std::endl;
//    }
//};
//
//class A : public Base
//{
//public:
//    A(int a)
//    {
//        std::cout << "A�Ĺ��캯��" << std::endl;
//        m_Num1 = new int(a);
//    }
//    ~A()
//    {
//        std::cout << "A����������" << std::endl;
//        delete m_Num1;
//        m_Num1 = NULL;
//    }
//    int* m_Num1;
//};
//
//class B : public Base
//{
//public:
//    B(int a)
//    {
//        std::cout << "B�Ĺ��캯��" << std::endl;
//        m_Num = a;
//    }
//    ~B()
//    {
//        std::cout << "B����������" << std::endl;
//    }
//    int m_Num;
//};
//
//void test01()
//{
//    Base* p = new A(10);
//    //Base* p2 = new B(10);
//    delete p;
//    //delete p2;
//}
//
//int main()
//{
//    test01();
//    return 0;
//}