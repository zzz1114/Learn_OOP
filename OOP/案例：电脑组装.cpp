#include <iostream>

class CPU
{
public:
    CPU() { std::cout << "CPU生产完成" << std::endl; }
    virtual void Calculate() = 0;
};

class ShowCard
{
public:
    ShowCard() { std::cout << "显卡生产完成" << std::endl; }
    virtual void Display() = 0;
};

class RAM
{
public:
    RAM() { std::cout << "RAM生产完成 " << std::endl; }
    virtual void Storage() = 0;
};

//将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件
//具体的CPU零件
class IntelCPU : public CPU
{
    void Calculate() { std::cout << "Intel的CPU开始计算" << std::endl; }
};

class LenovoCPU : public CPU
{
    void Calculate() { std::cout << "Lenovo的CPU开始计算" << std::endl; }
};

//具体的显卡零件
class IntelShowCard : public ShowCard
{
    void Display() { std::cout << "Intel的显卡开始显示" << std::endl; }
};

class LenovoShowCard : public ShowCard
{
    void Display() { std::cout << "Lenovo的显卡开始显示" << std::endl; }
};

//具体的内存条零件
class IntelRAM : public RAM
{
    void Storage() { std::cout << "Intel的内存条开始存储" << std::endl; }
};

class LenovoRAM : public RAM
{
    void Storage() { std::cout << "Lenovo的内存条开始存储" << std::endl; }
};



class Cumputer
{
public:
    Cumputer(CPU* cpu, ShowCard* card, RAM* ram) : m_cpu(cpu), m_card(card), m_ram(ram) { }
    ~Cumputer()
    {
        std::cout << "销毁一个电脑" << std::endl;
        delete m_cpu;
        m_cpu = NULL;
        delete m_card;
        m_card = NULL;
        delete m_ram;
        m_ram = NULL;
    }
    void Work()
    {
        m_cpu->Calculate();
        m_card->Display();
        m_ram->Storage();
    }
private:
    CPU* m_cpu;
    ShowCard* m_card;
    RAM* m_ram;
};

void test01()
{
    Cumputer a(new IntelCPU, new LenovoShowCard, new IntelRAM);
    std::cout << "-------------" << std::endl;
    a.Work();
}

int main()
{
    test01();
    return 0;
}