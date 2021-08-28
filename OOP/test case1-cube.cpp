//#include <iostream>
//
////设计一个立方体类（Cube）
////求出立方体的面积和体积
////分别用全局函数和成员函数判断两个 立方体是否相等
//
//class Cube
//{
//public:
//	Cube() :length(1), width(1), height(1) {}
//	Cube(int len, int wid, int hei) : length(len), width(wid), height(hei) {}
//	~Cube();
//	//判断与对象c2是否相同
//	bool JudgeEqual(Cube c2);
//	//获取长宽高
//	//返回指向一个分别存储了 长宽高 三个数据的一个数组指针
//	int* GetData();
//	double GetArea() { return 2 * (length * width + length * height + width * height); }
//	double GetVolume() { return length * width * height; }
//private:
//	//长
//	int length;
//	//宽
//	int width;
//	//高
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
//	std::cout << "C1的面积是 " << c1.GetArea() << "C1的体积是 " << c1.GetVolume() << std::endl;
//	std::cout << "c1与c2相等？" << c1.JudgeEqual(c2) << std::endl;
//	std::cout << "c3与c4相等？" << JuegeEqual2(c3, c4) << std::endl;
//	return 0;
//}
//
//bool JuegeEqual2(Cube c1, Cube c2)
//{
//	int* data1 = c1.GetData();
//	int* data2 = c2.GetData();
//	return (data1[0] == data2[0] && data1[1] == data2[1] && data1[2] == data2[2]);
//}