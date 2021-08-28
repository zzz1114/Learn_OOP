#include <iostream>

const float EPSILON = 1e-5;

class Point
{
public:
	//�޲ι��캯��
	Point() {}
	//�вι��캯��
	Point(int x, int y) : X(x), Y(y) {}
	//�������캯��
	Point(Point& p) { X = p.getCoor_X(); Y = p.getCoor_Y(); }
	Point(const Point& p) { X = p.X; Y = p.Y; }
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
	Circle(Circle& c) { Radius = c.getRadius(); Center = c.getCenter(); }
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
int isPointOnCircle(Circle c, Point &p);

int main()
{
	Point ponit1(0, 0), ponit2(1, 1);
	std::cout << "(0, 0)��(1, 1)֮��ľ���Ϊ��" << ponit1.GetDistance(ponit2) << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;
	Circle c(5, 0, 1);
	Point p(3, 5);
	std::cout << "��(3, 5)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
	p.setCoor(3, 4);
	std::cout << "��(3, 4)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;
	p.setCoor(4, 5);
	std::cout << "��(4, 5)��Բ�ڣ�" << isPointOnCircle(c, p) << std::endl;


	std::cout << "----------------------------------------------------" << std::endl;
	Circle c2(c);
	Point p2(p);
	std::cout << "��(3, 5)��Բ�ڣ�" << isPointOnCircle(c2, p2) << std::endl;
	p2.setCoor(3, 4);
	std::cout << "��(3, 4)��Բ�ڣ�" << isPointOnCircle(c2, p2) << std::endl;
	p2.setCoor(4, 5);
	std::cout << "��(4, 5)��Բ�ڣ�" << isPointOnCircle(c2, p2) << std::endl;


	std::cout << "----------------------------------------------------" << std::endl;
	Point point;





	return 0;
}


int isPointOnCircle(Circle cir, Point &point)
{
	Point p = cir.getCenter();
	float diff = abs(point.GetDistance(cir.getCenter()) - cir.getRadius());
	return diff == 0 ? 0 : diff > 0 ? 1 : -1;
}