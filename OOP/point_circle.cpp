//#include <iostream>
//
//const double EPSILON = 1e-5;
//
//class Point
//{
//public:
//	//�޲ι��캯��
//	Point() : X(0), Y(0) {}
//	//�вι��캯��
//	Point(int x, int y) : X(x), Y(y) { std::cout << "Point���캯������" << std::endl; }
//	Point(int x) :X(x), Y(0) {}
//	//�������캯��
//	Point(Point& p) { X = p.getCoor_X(); Y = p.getCoor_Y(); std::cout << "Point�����������" << std::endl; }
//	Point(const Point& p) { X = p.X; Y = p.Y; std::cout << "Point(const)�����������" << std::endl;
//	}
//	~Point() { std::cout << "Point������������" << std::endl; }
//	//��������
//	void setCoor(int x, int y)
//	{
//		X = x;
//		Y = y;
//	}
//	//��ȡλ��
//	int getCoor_X() { return X; }
//	int getCoor_Y() { return Y; }
//	//��������һ����֮��ľ���
//	double GetDistance(Point p)
//	{
//		int xDis = p.getCoor_X() - getCoor_X();
//		int yDis = p.getCoor_Y() - getCoor_Y();
//		return sqrt(xDis * xDis + yDis * yDis);
//	}
//
//	//��̬��Ա����
//	static int value;
//	static void fun()
//	{
//		int a = value;
//		int b = m;
//		std::cout << "��̬��Ա����" << std::endl;
//	}
//	void fun3() { fun2(); }
//
//private:
//	int X;
//	int Y;
//	static int m;
//	static void fun2();
//};
//
//int Point::value = 0;
//int Point::m = 10;
//
//void Point::fun2()
//{
//	std::cout << "��̬��Ա����" << std::endl;
//}
//
//
//class Circle {
//public:
//	Circle(int r, int x, int y) :Radius(r), Center(x, y) { std::cout << "Circle���캯������" << std::endl; }
//	Circle(Circle& c) { Radius = c.getRadius(); Center = c.	getCenter(); std::cout << "Circle�������캯������" << std::endl; }
//	~Circle() { std::cout << "Circle������������" << std::endl; }
//	void setCenter(int x, int y) { Center.setCoor(x, y); }
//	void setRadius(int r) { Radius = r; }
//	int getRadius() { return Radius; }
//	Point getCenter() { return Center; }
//private:
//	//�뾶
//	int Radius;
//	//Բ������
//	Point Center;
//};
//
////�жϵ��Ƿ���Բ��
////����ֵ  ����0 ��Բ�⣻����0 ��Բ�ϣ�С��0 ��Բ��
//int isPointOnCircle(Circle c, Point &p);
//
//void test1()
//{
//	Circle c(5, 0, 1);
//	Point p(3, 5);
//	std::cout << "��(3, 5)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
//	p.setCoor(3, 4);
//	std::cout << "��(3, 4)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
//	p.setCoor(4, 5);
//	std::cout << "��(4, 5)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
//}
//
//Point fun()
//{
//	Point a(1, 2); 
//	std::cout << "�����Ƕ���a" << std::endl;
//	return a; 
//}
//
////�������캯���ĵ���ʱ��
//void test2()
//{
//	//Point p1(1, 2);
//	//Point p2(p1);
//	std::cout << "-------------------" << std::endl;
//	Point p3 = fun();
//}
//
////�������Ϊ���Ա
//void test3()
//{
//	Circle cir(5, 1, 1);
//}
//
////��̬��Ա����
//void test4()
//{
//	//���ַ��ʷ�ʽ
//	
//	//1 ͨ���������
//	Point p1(1, 2);
//	std::cout << p1.value << std::endl;
//
//	Point p2(2, 3);
//	p2.value = 5;
//	std::cout << "ͨ����һ�������޸ĺ�\n" << p1.value << std::endl;
//
//	//2 ֱ��ͨ����������
//	std::cout << "\n\n" << Point::value << std::endl;
//
//}
//
////��̬��Ա����
//void test5()
//{
//	Point p1, p2;
//	p1.fun();
//	p2.fun3();
//}
//
//class A {
//public:
//	A() : d(10) { m = 10; }
//	~A() {}
//	A(int m) : d(m) { this->m = m; }
//
//	void fun() 
//	{ 
//		std::cout << "����func����, " << std::endl;
//		std::cout << "m = " << this->m << std::endl;
//	}
//
//	int m;
//	const int d;
//	static int b;
//	static const int n;
//};
//int A::b = 0;
//const int A::n = 10;
//
//void test6()
//{
//	A a;
//	A b(14);
//	std::cout << sizeof(A) << std::endl;
//	std::cout << sizeof(a) << std::endl;
//	std::cout << b.m << std::endl;
//}
//
//void test7()
//{
//	A* a = NULL;
//	a->fun();
//}
//
//int main()
//{
//	//test1();
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	//test6();
//	test7();
//
//	return 0;
//}
//
//
//int isPointOnCircle(Circle cir, Point &point)
//{
//	Point p = cir.getCenter();
//	double diff = abs(point.GetDistance(cir.getCenter()) - cir.getRadius());
//	return diff == 0 ? 0 : diff > 0 ? 1 : -1;
//}