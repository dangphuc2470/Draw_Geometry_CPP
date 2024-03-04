#pragma once
#include <iostream>

using namespace std;

class Point
{
private:
	int x, y;
public:
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	int GetX()
	{
		return x;
	}

	int GetY()
	{
		return y;
	}

	void SetX(int x)
	{
		this->x = x;
	}

	void SetY(int y)
	{
		this->y = y;
	}

	void Input()
	{
		cout << "Input X: ";
		cin >> x;
		cout << "Input Y: ";
		cin >> y;
	}

	void Output()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

	void Translate(int mx, int my)
	{
		x += mx;
		y += my;

	}

	~Point() {};
};