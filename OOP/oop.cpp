#include <iostream>
#include <string>

const double PI = 3.14159;

//�������---��װ
class Circle {
public:
	//�뾶
	int radius;	

	//��ȡ���
	double getArea()
	{
		return PI * radius * radius;
	}
};

class Student {
public:
	//��������
	void SetName(std::string name)
	{
		StuName.assign(name);
	}

	//����ѧ��
	void SetNum(int num)
	{
		StuNum = num;
	}

	//��ʾ��Ϣ
	void ShowInfo()
	{
		std::cout << "ѧ��������" << StuName << std::endl;
		std::cout << "ѧ��ѧ�ţ�" << StuNum << std::endl;
	}

private:
	std::string StuName;
	int StuNum;
};

int main()
{
	Student stu;
	stu.SetName("����");
	stu.SetNum(10086);
	stu.ShowInfo();
	std::cout << "-------------------" << std::endl;

	Circle c;
	c.radius = 10;
	std::cout << "Բ�����Ϊ��" << c.getArea() << std::endl;

	return 0;
}

/*
//����
int& func()
{
	static int a = 10;
	return a;
}

//�������ã�������ǰ�����const: const int &p����p�����޸ģ��������ں����з�ֹ�βα������޸�
//�������� int& p = a; �൱��  int* const p = &a;
//ǰ�������const��,const int& p = a: �൱�� const int* const p = &a;��Ȳ����޸�pָ��Ķ���Ҳ����ͨ��p�޸Ķ����ֵ
void ShowValue(const int& val)
{
	std::cout << "value is " << val << std::endl;
}

int main()
{
	int &c = func();		//cҲ��һ�����ã����Ǻ���func����ֵ��һ�����ã���func��a��һ�����ã����cҲ����a��һ������
	std::cout << "c = " << c << std::endl;
	func() = 100;			//����ֵ�Ǿ�̬����a��һ�����ã�������Ϊ��ֵ��ֱ���޸�a��ֵ��
	std::cout << "c = " << c << std::endl;

	int num = 5;
	int& ref1 = num;
	int& ref2 = ref1;
	int& ref3 = ref2;
	std::cout << "---------------------------" << std::endl;
	std::cout << "num = " << num << std::endl;
	std::cout << "ref1 = " << ref1 << std::endl;
	std::cout << "ref2 = " << ref2 << std::endl;
	std::cout << "ref3 = " << ref3 << std::endl;

	ref3 = 10;
	std::cout << "\n��ref3�޸�֮��" << std::endl;
	std::cout << "num = " << num << std::endl;
	std::cout << "ref1 = " << ref1 << std::endl;
	std::cout << "ref2 = " << ref2 << std::endl;
	std::cout << "ref3 = " << ref3 << std::endl;			//�ɼ���һ�����������õ����ã��ȼ������������һ������
	return 0;
}
*/








/*
//�����ڴ����ͷ�

//����һ��10*5�Ķ�ά���飬�������׵�ַ
void get2DArr(int(*&p)[5])
{
	p = new int[2][5];	//int (*)[5] ���ͺ� int** �����ǲ�һ���ġ�һ����ָ�������ָ�룬һ����ָ��ָ���ָ��
}

void delete2DArr(int(*&p)[5])
{
	//delete p;		//�ͷ������ʱ����Ҫ��һ�������Ųſ���
	delete[] p;	
	p = NULL;
}

int main()
{	
	int(*p)[5] = NULL;
	get2DArr(p);
	//p = new int[10][5];
	p[0][1] = 12;
	p[0][4] = 12;
	p[1][1] = 23;
	p[1][4] = 34;	

	delete2DArr(p);
	std::cout << (int)p << std::endl;
	std::cout << "p " << (p == NULL) << std::endl;
	//std::cout << p[0][1] << " " << p[0][4] << std::endl;
	//std::cout << p[1][1] << " " << p[1][4] << std::endl;
	return 0;
}
*/