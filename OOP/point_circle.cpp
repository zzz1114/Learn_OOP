#include <iostream>

const float EPSILON = 1e-5;

class Point
{
public:
	Point(int x, int y) : X(x), Y(y) {}
	//��������
	void setCoor(int x, int y)
	{
		X = x;
		Y = y;
	}
	//��ȡλ��
	int getCoor_X() { return X; }
	int getCoor_Y() { return Y; }
	//��������һ����֮��ľ���
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
	//�뾶
	int Radius;
	//Բ������
	Point Center;
};

//�жϵ��Ƿ���Բ��
//����ֵ  ����0 ��Բ�⣻����0 ��Բ�ϣ�С��0 ��Բ��
int isPointOnCircle(Circle c, Point p);

int main()
{
	Point p1(0, 0), p2(1, 1);
	std::cout << "(0, 0)��(1, 1)֮��ľ���Ϊ��" << p1.GetDistance(p2) << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;
	Circle c(5, 0, 1);
	Point p(3, 5);
	std::cout << "��(3, 5)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
	p.setCoor(3, 4);
	std::cout << "��(3, 4)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
	p.setCoor(4, 5);
	std::cout << "��(4, 5)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
	return 0;
}

int isPointOnCircle(Circle c, Point p)
{
	float diff = abs(p.GetDistance(c.getCenter())) - c.getRadius();
	return diff == 0 ? 0 : diff > 0 ? 1 : -1;
}