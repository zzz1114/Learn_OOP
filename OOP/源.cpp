#include <iostream>

//new�����ڴ�
//����һ��10*5�Ķ�ά���飬�������׵�ַ
void get2DArr(int(*p)[5])
{
	p = new int[10][5];	//int (*)[5] ���ͺ� int** �����ǲ�һ���ġ�һ����ָ�������ָ�룬һ����ָ��ָ���ָ��
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