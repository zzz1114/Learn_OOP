//#include <iostream>
//
//const double EPSILON = 1e-5;
//
//class Point
//{
//public:
//	//无参构造函数
//	Point() : X(0), Y(0) {}
//	//有参构造函数
//	Point(int x, int y) : X(x), Y(y) { std::cout << "Point构造函数调用" << std::endl; }
//	Point(int x) :X(x), Y(0) {}
//	//拷贝构造函数
//	Point(Point& p) { X = p.getCoor_X(); Y = p.getCoor_Y(); std::cout << "Point拷贝构造调用" << std::endl; }
//	Point(const Point& p) { X = p.X; Y = p.Y; std::cout << "Point(const)拷贝构造调用" << std::endl;
//	}
//	~Point() { std::cout << "Point析构函数调用" << std::endl; }
//	//设置坐标
//	void setCoor(int x, int y)
//	{
//		X = x;
//		Y = y;
//	}
//	//获取位置
//	int getCoor_X() { return X; }
//	int getCoor_Y() { return Y; }
//	//计算与另一个点之间的距离
//	double GetDistance(Point p)
//	{
//		int xDis = p.getCoor_X() - getCoor_X();
//		int yDis = p.getCoor_Y() - getCoor_Y();
//		return sqrt(xDis * xDis + yDis * yDis);
//	}
//
//	//静态成员变量
//	static int value;
//	static void fun()
//	{
//		int a = value;
//		int b = m;
//		std::cout << "静态成员函数" << std::endl;
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
//	std::cout << "静态成员函数" << std::endl;
//}
//
//
//class Circle {
//public:
//	Circle(int r, int x, int y) :Radius(r), Center(x, y) { std::cout << "Circle构造函数调用" << std::endl; }
//	Circle(Circle& c) { Radius = c.getRadius(); Center = c.	getCenter(); std::cout << "Circle拷贝构造函数调用" << std::endl; }
//	~Circle() { std::cout << "Circle析构函数调用" << std::endl; }
//	void setCenter(int x, int y) { Center.setCoor(x, y); }
//	void setRadius(int r) { Radius = r; }
//	int getRadius() { return Radius; }
//	Point getCenter() { return Center; }
//private:
//	//半径
//	int Radius;
//	//圆心坐标
//	Point Center;
//};
//
////判断点是否在圆上
////返回值  大于0 在圆外；等于0 在圆上；小于0 在圆内
//int isPointOnCircle(Circle c, Point &p);
//
//void test1()
//{
//	Circle c(5, 0, 1);
//	Point p(3, 5);
//	std::cout << "点(3, 5)在圆内？" << isPointOnCircle(c, p) << std::endl;
//	p.setCoor(3, 4);
//	std::cout << "点(3, 4)在圆内？" << isPointOnCircle(c, p) << std::endl;
//	p.setCoor(4, 5);
//	std::cout << "点(4, 5)在圆内？" << isPointOnCircle(c, p) << std::endl;
//}
//
//Point fun()
//{
//	Point a(1, 2); 
//	std::cout << "上面是对象a" << std::endl;
//	return a; 
//}
//
////拷贝构造函数的调用时机
//void test2()
//{
//	//Point p1(1, 2);
//	//Point p2(p1);
//	std::cout << "-------------------" << std::endl;
//	Point p3 = fun();
//}
//
////类对象作为类成员
//void test3()
//{
//	Circle cir(5, 1, 1);
//}
//
////静态成员变量
//void test4()
//{
//	//两种访问方式
//	
//	//1 通过对象访问
//	Point p1(1, 2);
//	std::cout << p1.value << std::endl;
//
//	Point p2(2, 3);
//	p2.value = 5;
//	std::cout << "通过另一个对象修改后：\n" << p1.value << std::endl;
//
//	//2 直接通过类名访问
//	std::cout << "\n\n" << Point::value << std::endl;
//
//}
//
////静态成员函数
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
//		std::cout << "调用func函数, " << std::endl;
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