#include <iostream>

const float EPSILON = 1e-5;

class Point
{
public:
	Point(int x, int y) : X(x), Y(y) {}
	//设置坐标
	void setCoor(int x, int y)
	{
		X = x;
		Y = y;
	}
	//获取位置
	int getCoor_X() { return X; }
	int getCoor_Y() { return Y; }
	//计算与另一个点之间的距离
	double GetDistance(Point p)
	{
		int xDis = p.getCoor_X() - getCoor_X();
		int yDis = p.getCoor_Y() - getCoor_Y();
		return sqrt(xDis * xDis + yDis * yDis);
	}

private:
	int X;
	int Y;
};

class Circle {
public:
	Circle(int r, int x, int y) :Radius(r), Center(x, y) {}
	void setCenter(int x, int y) { Center.setCoor(x, y); }
	void setRadius(int r) { Radius = r; }
	int getRadius() { return Radius; }
	Point getCenter() { return Center; }
private:
	//半径
	int Radius;
	//圆心坐标
	Point Center;
};

//判断点是否在圆上
//返回值  大于0 在圆外；等于0 在圆上；小于0 在圆内
int isPointOnCircle(Circle c, Point p);

int main()
{
	Point p1(0, 0), p2(1, 1);
	std::cout << "(0, 0)和(1, 1)之间的距离为：" << p1.GetDistance(p2) << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;
	Circle c(5, 0, 1);
	Point p(3, 5);
	std::cout << "点(3, 5)在圆内？" << isPointOnCircle(c, p) << std::endl;
	p.setCoor(3, 4);
	std::cout << "点(3, 4)在圆内？" << isPointOnCircle(c, p) << std::endl;
	p.setCoor(4, 5);
	std::cout << "点(4, 5)在圆内？" << isPointOnCircle(c, p) << std::endl;
	return 0;
}

int isPointOnCircle(Circle c, Point p)
{
	float diff = abs(p.GetDistance(c.getCenter())) - c.getRadius();
	return diff == 0 ? 0 : diff > 0 ? 1 : -1;
}