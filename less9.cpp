// less9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>


using namespace std;

class Shape
{
public:
	
	virtual ostream& print(ostream& out) const = 0;

	friend ostream& operator<<(ostream& out, const Shape& p)
	{
		return p.print(out);
	}


	virtual ~Shape(){}
};

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Triangle: public Shape
{
	Point m_p1;
	Point m_p2;
	Point m_p3;
public:
	Triangle(const Point &p1,const Point &p2,const Point &p3)
		:m_p1(p1),m_p2(p2),m_p3(p3)
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Triangle";
		return out;
	}
	virtual ~Triangle() {}

private:

};

class Circle :public Shape
{
	int m_radius;
	Point m_p;
public:
	Circle(const Point &p1, int radius)
		:m_p(p1),m_radius(radius)
	{

	}
	virtual ostream& print(ostream& out) const override
	{
		out << "Circle";
		return out;
	}

	const int getRadius()
	{
		return m_radius;
	}

};

int getLargestRadius(vector<Shape*> &v);


int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	// print each shape in vector v on its own line here
	for (auto const& element : v)
	{
		cout << *element << '\n';
	}

	cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	for (auto const& element : v)
	{
		delete element;
	}																   // delete each element in the vector here
}

int getLargestRadius(vector<Shape*> &v)
{
	int largest(0);
	for (auto& element : v)
	{
		if (Circle *c = dynamic_cast<Circle*>(element))
		{
			if (c->getRadius() > largest)
			{
				largest = c->getRadius();
			}
		}
	}
	return largest;
}
