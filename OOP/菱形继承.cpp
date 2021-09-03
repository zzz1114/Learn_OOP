#include <iostream>

class Base {
public:
	int m_Age;
};

class Son1 : virtual public Base {
public:
	int m_A;
};

class Son2 : virtual public Base {
public:
	int m_A;
};

class GrandSon : public Son1, public Son2 {
public:
	int m_A;
};

void test01()
{
	GrandSon a;
	//16?    20?
	std::cout << sizeof(a) << std::endl;
}

int main()
{
	test01();
	return 0;
}