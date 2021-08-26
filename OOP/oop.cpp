#include <iostream>
#include <string>

const double PI = 3.14159;

//面向对象---封装
class Circle {
public:
	//半径
	int radius;	

	//获取面积
	double getArea()
	{
		return PI * radius * radius;
	}
};

class Student {
public:
	//设置姓名
	void SetName(std::string name)
	{
		StuName.assign(name);
	}

	//设置学号
	void SetNum(int num)
	{
		StuNum = num;
	}

	//显示信息
	void ShowInfo()
	{
		std::cout << "学生姓名：" << StuName << std::endl;
		std::cout << "学生学号：" << StuNum << std::endl;
	}

private:
	std::string StuName;
	int StuNum;
};

int main()
{
	Student stu;
	stu.SetName("张三");
	stu.SetNum(10086);
	stu.ShowInfo();
	std::cout << "-------------------" << std::endl;

	Circle c;
	c.radius = 10;
	std::cout << "圆的面积为：" << c.getArea() << std::endl;

	return 0;
}

/*
//引用
int& func()
{
	static int a = 10;
	return a;
}

//常量引用，在引用前面加上const: const int &p，则p不可修改，可以用于函数中防止形参被意外修改
//本来引用 int& p = a; 相当于  int* const p = &a;
//前面加上了const后,const int& p = a: 相当于 const int* const p = &a;则既不能修改p指向的对象，也不能通过p修改对象的值
void ShowValue(const int& val)
{
	std::cout << "value is " << val << std::endl;
}

int main()
{
	int &c = func();		//c也是一个引用，它是函数func返回值的一个引用，而func是a的一个引用，因此c也就是a的一个引用
	std::cout << "c = " << c << std::endl;
	func() = 100;			//返回值是静态变量a的一个引用，可以作为左值，直接修改a的值。
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
	std::cout << "\n由ref3修改之后：" << std::endl;
	std::cout << "num = " << num << std::endl;
	std::cout << "ref1 = " << ref1 << std::endl;
	std::cout << "ref2 = " << ref2 << std::endl;
	std::cout << "ref3 = " << ref3 << std::endl;			//可见，一个变量的引用的引用，等价于这个变量的一个引用
	return 0;
}
*/








/*
//申请内存与释放

//申请一个10*5的二维数组，并返回首地址
void get2DArr(int(*&p)[5])
{
	p = new int[2][5];	//int (*)[5] 类型和 int** 类型是不一样的。一个数指向数组的指针，一个是指向指针的指针
}

void delete2DArr(int(*&p)[5])
{
	//delete p;		//释放数组的时候需要加一个中括号才可以
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