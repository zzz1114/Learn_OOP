#include <iostream>

//new申请内存
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