#include <iostream>

//new�����ڴ�
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