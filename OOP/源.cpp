#include <iostream>

//new申请内存
//申请一个10*5的二维数组，并返回首地址
void get2DArr(int(*p)[5])
{
	p = new int[10][5];	//int (*)[5] 类型和 int** 类型是不一样的。一个数指向数组的指针，一个是指向指针的指针
}

void delet2DArr(int(*p)[5])
{
	free(p);
}

int main()
{
	/*
	int(*p)[5] = NULL;
	get2DArr(p);
	p[0][1] = 12;
	p[0][4] = 12;
	p[1][1] = 23;
	p[1][4] = 34;	
	*/
	std::cout << 0 % 5 << std::endl;
	return 0;
}