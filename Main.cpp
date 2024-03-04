#include "graphics.h"
#include "Header.h"
#pragma comment(lib, "graphics.lib")

void Put9pixel(int x, int y, int color, int oX, int oY, int distanceBetweenPoints)
{
	putpixel(x + 1, y + 1, color);	//Ve 9 pixel
	putpixel(x + 1, y, color);		//
	putpixel(x + 1, y - 1, color);	//
	putpixel(x, y - 1, color);		//
	putpixel(x - 1, y - 1, color);	//
	putpixel(x - 1, y, color);		//
	putpixel(x - 1, y + 1, color);	//
	putpixel(x, y + 1, color);		//
	putpixel(x, y, color);			//
	char buffer[16] = { 0 };
	_itoa_s((x - oX) / distanceBetweenPoints, buffer, 10);
	outtextxy(x + 5, y - 13 ,"(");					//In ra toa do
	outtextxy(x +9, y-13, buffer);					//
	outtextxy(x + 17, y - 13, ", ");				//
	_itoa_s((oY - y) / distanceBetweenPoints, buffer, 10);			//
	outtextxy(x + 21, y - 13, buffer);				//
	outtextxy(x + 30, y - 13, ")");					//
	return;
}

void OxyDraw(int oX, int oY, int distanceBetweenPoints)
{
	for (int i = (oX % distanceBetweenPoints); i < 1000; i += distanceBetweenPoints)
	{
		for (int j = (oY % distanceBetweenPoints); j < 1000; j += distanceBetweenPoints)
		{
			putpixel(i, j, DARKGRAY); //Ve luoi
		}
	}
	outtextxy(oX + 324, oY - 8, ">");
	outtextxy(oX + 320, oY + 2, "x");
	line(0, oY, 2000, oY); //Ve truc x
	outtextxy(oX - 15, -4, "y");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(oX - 6, -4, "^");
	settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	line(oX, 0, oX, 2000); //Ve truc y
	int i = oX % distanceBetweenPoints + distanceBetweenPoints;
	int j = oY % distanceBetweenPoints + distanceBetweenPoints;
	while (i < 1000)
	{
		int n = (oY - j) / distanceBetweenPoints;
		char buffer[16] = { 0 };
		_itoa_s(n, buffer, 10); //Chuyen tu so sang ky tu
		putpixel(oX - 1, j, WHITE); // Danh dau diem truc tung
		putpixel(oX - 2, j, WHITE); // Danh dau diem truc tung x2
		if (n != 0) outtextxy(oX - 12, j - 7, buffer); //Gia tri tren truc tung

		n = (i - oX) / distanceBetweenPoints;
		_itoa_s(n, buffer, 10); //Chuyen tu so sang ky tu
		putpixel(i, oY + 1, WHITE); // Danh dau diem truc hoanh
		putpixel(i, oY + 2, WHITE); // Danh dau diem truc hoanh x2
		if (n != 0) outtextxy(i - 3, oY + 4, buffer); //Gia tri tren truc hoanh
		i += distanceBetweenPoints;
		j += distanceBetweenPoints;
	}
	settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	outtextxy(oX - 10, oY + 4, "O");
	return;
}

void PixelDraw(int x, int y, int color, int oX, int oY, int distanceBetweenPoints )
{
	Put9pixel((x * distanceBetweenPoints) + oX, oY - (y * distanceBetweenPoints), color, oX, oY, distanceBetweenPoints); //Convert N Draw 
	return;
}

int main()
{
	Point A(2, 3);
	A.Output();
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	int x1 = A.GetX();
	int y1 = A.GetY();
	A.Translate(2, -5);
	A.Output();
	int x2 = A.GetX();
	int y2 = A.GetY();
	int oX = 300, oY = 256, distanceBetweenPoints = 30;
	OxyDraw(oX, oY, distanceBetweenPoints);
	putpixel(1.5, 2.4, YELLOW);
	PixelDraw(x1, y1, YELLOW, oX, oY, distanceBetweenPoints);
	PixelDraw(x2, y2, YELLOW, oX, oY, distanceBetweenPoints);
	getch();
	closegraph();
	return 0;
}
