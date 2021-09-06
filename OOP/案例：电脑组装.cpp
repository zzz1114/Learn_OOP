#include <iostream>

class CPU
{
public:
    CPU() { std::cout << "CPU�������" << std::endl; }
    virtual void Calculate() = 0;
};

class ShowCard
{
public:
    ShowCard() { std::cout << "�Կ��������" << std::endl; }
    virtual void Display() = 0;
};

class RAM
{
public:
    RAM() { std::cout << "RAM������� " << std::endl; }
    virtual void Storage() = 0;
};

//��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����
//�����CPU���
class IntelCPU : public CPU
{
    void Calculate() { std::cout << "Intel��CPU��ʼ����" << std::endl; }
};

class LenovoCPU : public CPU
{
    void Calculate() { std::cout << "Lenovo��CPU��ʼ����" << std::endl; }
};

//������Կ����
class IntelShowCard : public ShowCard
{
    void Display() { std::cout << "Intel���Կ���ʼ��ʾ" << std::endl; }
};

class LenovoShowCard : public ShowCard
{
    void Display() { std::cout << "Lenovo���Կ���ʼ��ʾ" << std::endl; }
};

//������ڴ������
class IntelRAM : public RAM
{
    void Storage() { std::cout << "Intel���ڴ�����ʼ�洢" << std::endl; }
};

class LenovoRAM : public RAM
{
    void Storage() { std::cout << "Lenovo���ڴ�����ʼ�洢" << std::endl; }
};



class Cumputer
{
public:
    Cumputer(CPU* cpu, ShowCard* card, RAM* ram) : m_cpu(cpu), m_card(card), m_ram(ram) { }
    ~Cumputer()
    {
        std::cout << "����һ������" << std::endl;
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