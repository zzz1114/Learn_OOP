#include <iostream>

class AbstractCalculator    //计算器的抽象类
{
public:
    AbstractCalculator(int a, int b) : m_Num1(a), m_Num2(b) { }
    virtual int getResult() { return 0; }
    int m_Num1;
    int m_Num2;
};

//加法：
class AddCalculator : public AbstractCalculator
{
public:
    AddCalculator(int a, int b) : AbstractCalculator(a, b) { }
    int getResult() { return m_Num1 + m_Num2; }
};

//减法：
class SubCalculator : public AbstractCalculator
{
public:
    SubCalculator(int a, int b) :AbstractCalculator(a, b) {}
    int getResult() { return m_Num1 - m_Num2; }
};


void test01()
{
    AbstractCalculator* ptr = new AddCalculator(10, 20);
    std::cout << ptr->getResult() << std::endl;
    delete ptr;

    ptr = new SubCalculator(12, 20);
    std::cout << ptr->getResult() << std::endl;
    delete ptr;
}

int main()
{
    test01();
    return 0;
}