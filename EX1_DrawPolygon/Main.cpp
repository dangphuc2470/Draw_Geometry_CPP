#include "graphics.h"
#include "Header.h"
#pragma comment(lib, "graphics.lib")

void OxyDraw(int TamX, int TamY, int Cach)
{
	for (int i = (TamX % Cach); i < 1000; i += Cach)
	{
		for (int j = (TamY % Cach); j < 1000; j += Cach)
		{
			putpixel(i, j, DARKGRAY); //Ve luoi
		}
	}
	outtextxy(TamX + 324, TamY - 8, ">");
	outtextxy(TamX + 320, TamY + 2, "x");
	line(0, TamY, 2000, TamY); //Ve truc x
	outtextxy(TamX - 15, -4, "y");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(TamX - 6, -4, "^");
	settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	line(TamX, 0, TamX, 2000); //Ve truc y
	int i = TamX % Cach + Cach;
	int j = TamY % Cach + Cach;
	while (i < 1000)
	{
		int n = (TamY - j) / Cach;
		char buffer[16] = { 0 };
		_itoa_s(n, buffer, 10); //Chuyen tu so sang ky tu
		putpixel(TamX - 1, j, WHITE); // Danh dau diem truc tung
		putpixel(TamX - 2, j, WHITE); // Danh dau diem truc tung x2
		if (n != 0) outtextxy(TamX - 12, j - 7, buffer); //Gia tri tren truc tung

		n = (i - TamX) / Cach;
		_itoa_s(n, buffer, 10); //Chuyen tu so sang ky tu
		putpixel(i, TamY + 1, WHITE); // Danh dau diem truc hoanh
		putpixel(i, TamY + 2, WHITE); // Danh dau diem truc hoanh x2
		if (n != 0) outtextxy(i - 3, TamY + 4, buffer); //Gia tri tren truc hoanh
		i += Cach;
		j += Cach;
	}
	settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	outtextxy(TamX - 10, TamY + 4, "O");
	return;
}


int main()
{
	int n;
	cout << "Nhap so canh: ";
	cin >> n;
	DaGiac T(n);
	T.Input();
	T.Output();
	DaGiac tGoc = T;

	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	int TamX = 300, TamY = 256, Cach = 30;
	OxyDraw(TamX, TamY, Cach);
	tGoc.DrawPolygon(TamX, TamY, Cach);
	cout << "Tinh tien: ";
	DaGiac tTinhTien = T;
	int mx, my;
	cin >> mx >> my;
	tTinhTien.TinhTien(mx, my);
	tTinhTien.Output();
	DaGiac tTo = tTinhTien;
	tTinhTien.DrawPolygon(TamX, TamY, Cach);

	//cout << "Xoay: ";
	//TamGiac tXoay = tTinhTien;
	//int Angle;
	//cin >> Angle;
	//cout << Angle << " ";
	//tXoay.Xoay(Angle);
	//tXoay.Output();
	//tXoay.Convert(TamX, TamY, Cach);
	//tXoay.DrawTriangle();

	cout << "Phong to: ";
	double scale;
	cin >> scale;
	tTo.PhongTo(scale);
	tTo.Output();
	//tTo.Convert(TamX, TamY, Cach);
	tTo.DrawPolygon(TamX, TamY, Cach);

	getch();
	closegraph();
	return 0;
}