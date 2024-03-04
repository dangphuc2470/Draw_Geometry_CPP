#pragma once
#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.14159265359

using namespace std;

class Diem
{
private:
	double x, y;
public:
	Diem(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}

	void SetX(double x)
	{
		this->x = x;
	}

	void SetY(double y)
	{
		this->y = y;
	}

	void Input()
	{
		cout << "Nhap hoanh do: ";
		cin >> x;
		cout << "Nhap tung do: ";
		cin >> y;
	}
	void Output()
	{
		cout <<setprecision(2)<< "(" << x << ", " << y << ")" << endl;
	}
	void TinhTien(double mx, double my)
	{
		x += mx;
		y += my;

	}
	void PhongTo(double ZoomIn)
	{
		x *= ZoomIn;
		y *= ZoomIn;

	}

	void OxyConvert(double TamX, double TamY, double Cach)
	{
		x = (x * Cach) + TamX;
		y = TamY - (y * Cach);
	}

	friend class DaGiac;
	~Diem() {};
};

class DaGiac
{
private:
	Diem A[100];
	int Canh;
public:
	DaGiac(int Canh) 
	{
		this->Canh = Canh;
	};


	void Input()
	{
		for (int i = 0; i < Canh; i++)
		{
			cout << "Nhap toa do diem "<<i+1<<":\n";
			A[i].Input();
		}
	}

	void Output()
	{
		for (int i = 0; i < Canh; i++)
		{
			A[i].Output();
		}
	}

	void TinhTien(double mx, double my)
	{
		for (int i = 0; i < Canh; i++)
		{
			A[i].TinhTien(mx, my);
		}
	}


	void DrawPolygon(int TamX, int TamY, int Cach)
	{
		for (int i = 0; i < Canh; i++)
		{
			A[i].OxyConvert(TamX, TamY, Cach);
		}
		int point[100];
		int i = 0, j = 0;
		while (i < (Canh + 1) * 2)
		{
			if (i == (Canh * 2))
			{
				point[i] = A[0].x;
				point[i + 1] = A[0].y;
				break;
			}
			point[i] = A[j].x;
			point[i + 1] = A[j].y;
			i += 2;
			j++;

		}
		drawpoly(Canh + 1, point);

	}
	//void Xoay(int Angle)
	//{
	//	int c, s;
	//	c = cos(Angle*PI/180);
	//	s = sin(Angle*PI/180);
	//	cout << 1 * cos(Angle*PI/180) + 1 * sin(Angle*PI/180)<<"  ";
	//	cout << "Truoc " << A.x;
	//	A.x= A.x * cos(Angle * PI / 180) + A.x * sin(Angle * PI / 180);
	//	cout <<"Sau " << A.x;
	//	A.SetY(-A.x * s + A.y * c);

	//	B.SetX(B.x * c + B.y * s);
	//	B.SetY(-B.x * s + B.y * c);

	//	C.SetX(C.x * c + C.y * s);
	//	C.SetY(-C.x * s + C.y * c);
	//}
	
	void PhongTo(int scale)
	{
		double xTruoc=0;
		double yTruoc=0;
		for (int i = 0; i < Canh; i++)
		{
			xTruoc += A[i].x;
			yTruoc += A[i].y;
		}
		xTruoc /= Canh;
		yTruoc /= Canh;
		for (int i = 0; i < Canh; i++)
		{
			A[i].PhongTo(scale);
		}
		double xSau = 0;
		double ySau = 0;
		for (int i = 0; i < Canh; i++)
		{
			xSau += A[i].x;
			ySau += A[i].y;
		}
		xSau /= Canh;
		ySau /= Canh;
		for (int i = 0; i < Canh; i++)
		{
			A[i].TinhTien(xTruoc - xSau, yTruoc - ySau);
		}

	}

	~DaGiac() {};

};