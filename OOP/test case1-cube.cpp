//#include <iostream>
//
////���һ���������ࣨCube��
////������������������
////�ֱ���ȫ�ֺ����ͳ�Ա�����ж����� �������Ƿ����
//
//class Cube
//{
//public:
//	Cube() :length(1), width(1), height(1) {}
//	Cube(int len, int wid, int hei) : length(len), width(wid), height(hei) {}
//	~Cube();
//	//�ж������c2�Ƿ���ͬ
//	bool JudgeEqual(Cube c2);
//	//��ȡ�����
//	//����ָ��һ���ֱ�洢�� ����� �������ݵ�һ������ָ��
//	int* GetData();
//	double GetArea() { return 2 * (length * width + length * height + width * height); }
//	double GetVolume() { return length * width * height; }
//private:
//	//��
//	int length;
//	//��
//	int width;
//	//��
//	int height;
//};
//
//Cube::~Cube()
//{
//	int* p = GetData();
//	delete p;
//}
//
//bool Cube::JudgeEqual(Cube c2)
//{
//	return height == c2.height && width == c2.width && length == c2.length;
//}
//
//int* Cube::GetData()
//{
//	int* res = new int[3];
//	res[0] = length;
//	res[1] = width;
//	res[2] = height;
//	return res;
//}
//
//bool JuegeEqual2(Cube c1, Cube c2);
//
//int main()
//{
//	Cube c1(1, 2, 3), c2(1, 3, 2);
//	Cube c3(2, 1, 3), c4(2, 1, 3);
//	std::cout << "C1������� " << c1.GetArea() << "C1������� " << c1.GetVolume() << std::endl;
//	std::cout << "c1��c2��ȣ�" << c1.JudgeEqual(c2) << std::endl;
//	std::cout << "c3��c4��ȣ�" << JuegeEqual2(c3, c4) << std::endl;
//	return 0;
//}
//
//bool JuegeEqual2(Cube c1, Cube c2)
//{
//	int* data1 = c1.GetData();
//	int* data2 = c2.GetData();
//	return (data1[0] == data2[0] && data1[1] == data2[1] && data1[2] == data2[2]);
//}