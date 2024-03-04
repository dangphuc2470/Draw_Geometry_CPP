#pragma once
#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.14159265359

using namespace std;

class Diem
{
private:
	
public:
	double x, y;
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
		cout << "(" << x << ", " << y << ")" << endl;
	}
	void TinhTien(double mx, double my)
	{
		x += mx;
		y += my;

	}
	void ThuNho(double scale)
	{
		x /= scale;
		y /= scale;
	}

	void PhongTo(double scale)
	{
		x *= scale;
		y *= scale;
	}

	void OxyConvert(int TamX, int TamY, int Cach)
	{
		x = (x * Cach) + TamX;
		y = TamY - (y * Cach);
	}

	friend class TamGiac;
	~Diem() {};
};

class TamGiac
{
private:
	
public:
	Diem A;
	Diem B;
	Diem C;
	TamGiac() {};
	TamGiac(Diem A, Diem B, Diem C)
	{
		this->A = A;
		this->B = B;
		this->C = C;
		return;
	}
	TamGiac(double x1, double y1, double x2, double y2, double x3, double y3)
	{
		A = Diem(x1, y1);
		B = Diem(x2, y2);
		C = Diem(x3, y3);
		return;
	}

	void Input()
	{
		cout << "Nhap toa do diem A:\n";
		A.Input();
		cout << "Nhap toa do diem B:\n";
		B.Input();
		cout << "Nhap toa do diem C:\n";
		C.Input();
	}

	void Output()
	{
		A.Output();
		B.Output();
		C.Output();
	}

	void TinhTien(double mx, double my)
	{
		A.TinhTien(mx, my);
		B.TinhTien(mx, my);
		C.TinhTien(mx, my);
	}

	/*void Xoay(double Angle)
	{
		double c, s;
		c = cos(Angle*PI/180);
		s = sin(Angle*PI/180);
		cout << 1 * cos(Angle*PI/180) + 1 * sin(Angle*PI/180)<<"  ";
		cout << "Truoc " << A.x;
		A.x= A.x * cos(Angle * PI / 180) + A.x * sin(Angle * PI / 180);
		cout <<"Sau " << A.x;
		A.SetY(-A.x * s + A.y * c);

		B.SetX(B.x * c + B.y * s);
		B.SetY(-B.x * s + B.y * c);

		C.SetX(C.x * c + C.y * s);
		C.SetY(-C.x * s + C.y * c);
	}*/
	
	void PhongTo(double Scale, double TamX, double TamY, double Cach)
	{
		double xTruoc= ((A.x+B.x+C.x)/3.0);
		double yTruoc= ((A.y + B.y + C.y) / 3.0);
		A.PhongTo(Scale);
		B.PhongTo(Scale);
		C.PhongTo(Scale);
		double xSau = (A.x + B.x + C.x) / 3.0;
		double ySau = (A.y + B.y + C.y) / 3.0;
		A.TinhTien(xTruoc - xSau, yTruoc - ySau);
		B.TinhTien(xTruoc - xSau, yTruoc - ySau);
		C.TinhTien(xTruoc - xSau, yTruoc - ySau);
	}

	void ThuNho(double Scale, double TamX, double TamY, double Cach)
	{
		double xTruoc = ((A.x + B.x + C.x) / 3.0);
		double yTruoc = ((A.y + B.y + C.y) / 3.0);
		A.ThuNho(Scale);
		B.ThuNho(Scale);
		C.ThuNho(Scale);
		double xSau = (A.x + B.x + C.x) / 3.0;
		double ySau = (A.y + B.y + C.y) / 3.0;
		A.TinhTien(xTruoc - xSau, yTruoc - ySau);
		B.TinhTien(xTruoc - xSau, yTruoc - ySau);
		C.TinhTien(xTruoc - xSau, yTruoc - ySau);
	}

	void DrawTriangle(int TamX, int TamY, int Cach)
	{
		A.OxyConvert(TamX, TamY, Cach);
		B.OxyConvert(TamX, TamY, Cach);
		C.OxyConvert(TamX, TamY, Cach);
		int point[] = { A.x, A.y , B.x, B.y, C.x, C.y, A.x, A.y };
		drawpoly(4, point);
		
	}
	~TamGiac() {};

};