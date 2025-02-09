#include <iostream>
#include <cmath>
#include <time.h>
#include<graphics.h>
#define fillc 13
#define linus line
#define M 2
#define a 3.14/18
#define iang 30
using namespace std;
void Fill(float* x1, float* y1, float* x2, float* y2, float* x3, float* y3)
{
float tp = 0, bot = 0, lft = 0, rght = 0, midlx = 0, midly = 0;
tp = min(min((*y1), (*y3)), min((*y1), (*y2)));
bot = max(max((*y1), (*y3)), max((*y1), (*y2)));
lft = min(min((*x1), (*x3)), min((*x1), (*x2)));
rght = max(max((*x1), (*x3)), max((*x1), (*x2)));
float topx = 0, topy = 0, midx = 0, midy = 0, botx = 0, boty = 0;
float pt1 = 0, pt2 = 0, ptv = 0, d1 = 0, d2 = 0;
int cho = 0;
{
if ((*y1) == tp)
{
topx = (*x1);
topy = (*y1);
}
else if ((*y1) == bot)
{
botx = (*x1);
boty = (*y1);
}
else
{
midx = (*x1);
midy = (*y1);
}
if ((*y2) == tp)
{
topx = (*x2);
topy = (*y2);
}
else if ((*y2) == bot)
{
botx = (*x2);
boty = (*y2);
}
else
{
midx = (*x2);
midy = (*y2);
}
if ((*y3) == tp)
{
topx = (*x3);
topy = (*y3);
}
else if ((*y3) == bot)
{
botx = (*x3);
boty = (*y3);
}
else
{
midx = (*x3);
midy = (*y3);
}
}
{
if (((*x1) != lft) && ((*x1) != rght))
{
midlx = (*x1);
midly = (*y1);
}
if (((*x2) != lft) && ((*x2) != rght))
{
midlx = (*x2);
midly = (*y2);
}
if (((*x3) != lft) && ((*x3) != rght))
{
midlx = (*x3);
midly = (*y3);
}
}
for (int i = ceil(topy); i < ceil(midy); i++)
{
cho = 0;
pt1 = ((i - topy) / (midy - topy)) * (midx - topx) + topx;
pt2 = ((i - topy) / (boty - topy)) * (botx - topx) + topx;
if (pt1 > pt2)
{
ptv = pt1;
pt1 = pt2;
pt2 = ptv;
}
if (pt1 < lft)
pt1 = lft;
if (pt2 > rght)
pt2 = rght;
d1 = abs(midlx - pt1);
d2 = abs(midlx - pt2);
if (d1 < d2)
{
if ((i == round(midly)) && (pt1 < midlx))
{
if (i <= round(tp))
{
cho = 3;
}
else
cho = 1;
}
}
else
{
if ((i == round(midly)) && (pt2 > midlx))
{
if (i <= round(tp))
{
cho = 3;
}
else
cho = 2;
}
}
switch (cho)
{
case 1:
linus(round(midlx), i, round(pt2), i);
break;
case 2:
linus(round(pt1), i, round(midlx), i);
break;
case 3:
break;
default:
linus(round(pt1), i, round(pt2), i);
break;
}
}
for (int i = ceil(midy); i < floor(boty); i++)
{
cho = 0;
pt1 = ((i - midy) / (boty - midy)) * (botx - midx) + midx;
pt2 = ((i - topy) / (boty - topy)) * (botx - topx) + topx;
if (pt1 > pt2)
{
ptv = pt1;
pt1 = pt2;
pt2 = ptv;
}
if (pt1 < lft)
pt1 = lft;
if (pt2 > rght)
pt2 = rght;
d1 = abs(midlx - pt1);
d2 = abs(midlx - pt2);
if (d1 < d2)
{
if ((i == round(midly)) && (pt1 < midlx))
{
if (i >= round(bot))
{
cho = 3;
setcolor(4);
setcolor(fillc);
}
else
cho = 1;
}
}
else
{
if ((i == round(midly)) && (pt2 > midlx))
{
if (i >= round(bot))
{
cho = 3;
setcolor(0);
setcolor(fillc);
}
else
cho = 2;
}
}
switch (cho)
{
case 1:
linus(round(midlx), i, round(pt2), i);
break;
case 2:
linus(round(pt1), i, round(midlx), i);
break;
case 3:
break;
default:
linus(round(pt1), i, round(pt2), i);
break;
}
}
}
void Sort(float list[], int list2[], int listLength)
{
while (listLength--)
{
for (int i = 0; i < listLength; i++)
{
if (list[i] > list[i + 1])
{
swap(list[i], list[i + 1]);
swap(list2[i], list2[i + 1]);
}
}
}
}
if ((i == round(midly)) && (pt1 < midlx))
{
float dx = ((*x2) - (*x1));
float dy = ((*y2) - (*y1));
float dz = ((*z2) - (*z1));
float L = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
return L;
}
void Draw(float* x1, float* y1, float* x2, float* y2, float* x3, float* y3)
{
line(*(x1), *(y1), *(x2), *(y2));
line(*(x3), *(y3), *(x2), *(y2));
line(*(x1), *(y1), *(x3), *(y3));
}
void Izo(float* x, float* y, float* z)
{
int cix = 500, ciy = 150;
float ix = cix, iy = ciy;
ix = ix - (*(x)) * cos((iang * (atan(1) * 4)) / 180) + (*(y)) * cos((iang * (atan(1) *
4)) / 180);
iy = iy + (*(x)) * sin((iang * (atan(1) * 4)) / 180) + (*(y)) * sin((iang * (atan(1) *
4)) / 180);
iy -= (*(z));
*(x) = ix;
*(y) = iy;
}
void Cent(float* x1, float* y1, float* z1, float* x2, float* y2, float* z2, float* x3,
float* y3, float* z3, float* x, float* y, float* z)
{
*(x) = (*(x1)+*(x2)+*(x3)) / 3;
*(y) = (*(y1)+*(y2)+*(y3)) / 3;
*(z) = (*(z1)+*(z2)+*(z3)) / 3;
}
void Gran(float* x1, float* y1, float* z1, float* x2, float* y2, float* z2, float* x3,
float* y3, float* z3, float* x4, float* y4, float* z4, int list[])
{
float cx1, cx2, cx3, cx4;
float cy1, cy2, cy3, cy4;
float cz1, cz2, cz3, cz4;
Cent(x1, y1, z1, x2, y2, z2, x3, y3, z3, &cx1, &cy1, &cz1);
Cent(x4, y4, z4, x2, y2, z2, x3, y3, z3, &cx2, &cy2, &cz2);
Cent(x4, y4, z4, x2, y2, z2, x1, y1, z1, &cx3, &cy3, &cz3);
Cent(x4, y4, z4, x3, y3, z3, x1, y1, z1, &cx4, &cy4, &cz4);
float minx = min(min((*x1), (*x3)), min((*x4), (*x2)));
float miny = min(min((*y1), (*y3)), min((*y4), (*y2)));
float minz = min(min((*z1), (*z3)), min((*z4), (*z2)));
float fax = minx - 40000, fay = miny - 40000, faz = minz - 40000;
float faceord[4]{};
list[0] = 0;
list[1] = 1;
list[2] = 2;
list[3] = 3;
faceord[0] = Lline(&fax, &fay, &faz, &cx1, &cy1, &cz1);
faceord[1] = Lline(&fax, &fay, &faz, &cx2, &cy2, &cz2);
faceord[2] = Lline(&fax, &fay, &faz, &cx3, &cy3, &cz3);
faceord[3] = Lline(&fax, &fay, &faz, &cx4, &cy4, &cz4);
Sort(faceord, list, 4);
}
void Show(float* x1, float* y1, float* x2, float* y2, float* x3, float* y3, float* x4,
float* y4, int list[])
{
for (int i = 0; i < 4; i++)
{
switch (list[i])
{
case 0:
setcolor(1);
Fill(x1, y1, x2, y2, x3, y3);
setcolor(15);
Draw(x1, y1, x2, y2, x3, y3);
break;
case 1:
setcolor(2);
Fill(x4, y4, x2, y2, x3, y3);
setcolor(15);
Draw(x4, y4, x2, y2, x3, y3);
break;
case 2:
setcolor(3);
Fill(x1, y1, x2, y2, x4, y4);
setcolor(15);
Draw(x1, y1, x2, y2, x4, y4);
break;
case 3:
setcolor(4);
Fill(x1, y1, x4, y4, x3, y3);
setcolor(15);
Draw(x1, y1, x4, y4, x3, y3);
break;
}
}
}
void Lines(int x0, int y0, int x1, int y1)
{
int deltaY = y1 - y0;
int deltaX = x0 - x1;
int sign = abs(deltaY) > abs(deltaX) ? 1 : -1;
int signX = deltaX < 0 ? -1 : 1;
int signY = deltaY < 0 ? -1 : 1;
int f = 0, x = x0, y = y0;
putpixel(x0, y0, WHITE);
if (sign == -1)
{
do {
f += deltaY * signY;
if (f > 0)
{
f -= deltaX * signX;
y += signY;
}
x -= signX;
putpixel(x, y, WHITE);
} while (x != x1 || y != y1);
}
else
{
do {
f += deltaX * signX;
if (f > 0) {
f -= deltaY * signY;
x -= signX;
}
y += signY;
putpixel(x, y, WHITE);
} while (x != x1 || y != y1);
}
}
class dot
{
public:
float x;
float y;
float z;
float x2;
float y2;
float z2;
};
class fig
{
float x1, y1, z1;
float x2, y2, z2;
float x3, y3, z3;
float x4, y4, z4;
float centerX;
float centerY;
float centerZ;
int n;
int count2;
public:
void centr()
{
float sumx = 0;
float sumy = 0;
float sumz = 0;
sumx = x1 + x2 + x3 + x4;
sumy = y1 + y2 + y3 + y4;
sumz = z1 + z2 + z3 + z4;
centerX = sumx / n;
centerY = sumy / n;
centerZ = sumz / n;
}
fig()
{
n = 4;
count2 = 6;
}
void Draw()
{
int i = 0;
centr();
float ix1 = x1, iy1 = y1, iz1 = z1;
float ix2 = x2, iy2 = y2, iz2 = z2;
float ix3 = x3, iy3 = y3, iz3 = z3;
float ix4 = x4, iy4 = y4, iz4 = z4;
int faceval[4] = {};
Izo(&ix1, &iy1, &iz1);
Izo(&ix2, &iy2, &iz2);
Izo(&ix3, &iy3, &iz3);
Izo(&ix4, &iy4, &iz4);
Gran(&x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4,
faceval);
Show(&ix1, &iy1, &ix2, &iy2, &ix3, &iy3, &ix4, &iy4, faceval);
}
void print()
{
 x1 = 20, y1 = 0, z1 = 0;
 x2 = 350, y2 = 0, z2 = 0;
 x3 = 35, y3 = 10, z3 = 100;
 x4 = 30, y4 = 350, z4 = 60;
Draw();
}
void Shift(char c)
{
float buf;
float al = 3.14159265358979323846264 / 18;
float del = 2.0;
if (c == 'w')
{
y1 -= 10;
y2 -= 10;
y3 -= 10;
y4 -= 10;
}
if (c == 's')
{
y1 += 10;
y2 += 10;
y3 += 10;
y4 += 10;
}
if (c == 'a')
{
x1 += 10;
x2 += 10;
x3 += 10;
x4 += 10;
}
if (c == 'd')
{
x1 -= 10;
x2 -= 10;
x3 -= 10;
x4 -= 10;
}
if (c == 'z')
{
z1 += 10;
z2 += 10;
z3 += 10;
z4 += 10;
}
if (c == 'x')
{
z1 -= 10;
z2 -= 10;
z3 -= 10;
z4 -= 10;
}
if (c == '=')
{
x1 = (x1 - centerX) * M + centerX;
x2 = (x2 - centerX) * M + centerX;
x3 = (x3 - centerX) * M + centerX;
x4 = (x4 - centerX) * M + centerX;
y1 = (y1 - centerY) * M + centerY;
y2 = (y2 - centerY) * M + centerY;
y3 = (y3 - centerY) * M + centerY;
y4 = (y4 - centerY) * M + centerY;
z1 = (z1 - centerZ) * M + centerZ;
z2 = (z2 - centerZ) * M + centerZ;
z3 = (z3 - centerZ) * M + centerZ;
z4 = (z4 - centerZ) * M + centerZ;
}
if (c == '-')
{
x1 = (x1 - centerX) / M+ centerX;
x2 = (x2 - centerX) / M+ centerX;
x3 = (x3 - centerX) / M + centerX;
x4 = (x4 - centerX) / M + centerX;
y1 = (y1 - centerY) / M + centerY;
y2 = (y2 - centerY) / M + centerY;
y3 = (y3 - centerY) / M + centerY;
y4 = (y4 - centerY) / M + centerY;
z1 = (z1 - centerZ) / M + centerZ;
z2 = (z2 - centerZ) / M + centerZ;
z3 = (z3 - centerZ) / M + centerZ;
z4 = (z4 - centerZ) / M + centerZ;
}
if (c == '=')
{
x1 = (x1 - centerX) * M + centerX;
x2 = (x2 - centerX) * M + centerX;
x3 = (x3 - centerX) * M + centerX;
x4 = (x4 - centerX) * M + centerX;
y1 = (y1 - centerY) * M + centerY;
y2 = (y2 - centerY) * M + centerY;
y3 = (y3 - centerY) * M + centerY;
y4 = (y4 - centerY) * M + centerY;
z1 = (z1 - centerZ) * M + centerZ;
z2 = (z2 - centerZ) * M + centerZ;
z3 = (z3 - centerZ) * M + centerZ;
z4 = (z4 - centerZ) * M + centerZ;
}
if (c == '1')
{
centr();
float temp1 = y1;
float temp2 = y2;
float temp3 = y3;
float temp4 = y4;
y1 = (y1 - centerY) * cos(a) + (z1 - centerZ) * sin(a) + centerY;
y2 = (y2 - centerY) * cos(a) + (z2 - centerZ) * sin(a) + centerY;
y3 = (y3 - centerY) * cos(a) + (z3 - centerZ) * sin(a) + centerY;
y4 = (y4 - centerY) * cos(a) + (z4 - centerZ) * sin(a) + centerY;
z1 = -(temp1 - centerY) * sin(a) + (z1 - centerZ) * cos(a) + centerZ;
z2 = -(temp2 - centerY) * sin(a) + (z2 - centerZ) * cos(a) + centerZ;
z3 = -(temp3 - centerY) * sin(a) + (z3 - centerZ) * cos(a) + centerZ;
z4 = -(temp4 - centerY) * sin(a) + (z4 - centerZ) * cos(a) + centerZ;
}
if (c == '2')
{
centr();
float temp1 = x1;
float temp2 = x2;
float temp3 = x3;
float temp4 = x4;
x1 = (x1 - centerX) * cos(a) + (z1 - centerZ) * sin(a) + centerX;
x2 = (x2 - centerX) * cos(a) + (z2 - centerZ) * sin(a) + centerX;
x3 = (x3 - centerX) * cos(a) + (z3 - centerZ) * sin(a) + centerX;
x4 = (x4 - centerX) * cos(a) + (z4 - centerZ) * sin(a) + centerX;
z1 = -(temp1 - centerX) * sin(a) + (z1 - centerZ) * cos(a) + centerZ;
z2 = -(temp2 - centerX) * sin(a) + (z2 - centerZ) * cos(a) + centerZ;
z3 = -(temp3 - centerX) * sin(a) + (z3 - centerZ) * cos(a) + centerZ;
z4 = -(temp4 - centerX) * sin(a) + (z4 - centerZ) * cos(a) + centerZ;
}
if (c == '3')
{
centr();
float temp1 = x1;
float temp2 = x2;
float temp3 = x3;
float temp4 = x4;
x1 = (x1 - centerX) * cos(a) + (y1 - centerY) * sin(a) + centerX;
x2 = (x2 - centerX) * cos(a) + (y2 - centerY) * sin(a) + centerX;
x3 = (x3 - centerX) * cos(a) + (y3 - centerY) * sin(a) + centerX;
x4 = (x4 - centerX) * cos(a) + (y4 - centerY) * sin(a) + centerX;
y1 = -(temp1 - centerX) * sin(a) + (y1 - centerY) * cos(a) +
centerY;
y2 = -(temp2 - centerX) * sin(a) + (y2 - centerY) * cos(a) +
centerY;
y3 = -(temp3 - centerX) * sin(a) + (y3 - centerY) * cos(a) +
centerY;
y4 = -(temp4 - centerX) * sin(a) + (y4 - centerY) * cos(a) +
centerY;
}
cleardevice();
Draw();
}
};
int main()
{
initwindow(800, 800);
setbkcolor(0);
setcolor(15);
fig one;
one.print();
char f;
while (1)
{
f = getch();
one.Shift(f);
}
getch();
closegraph();
return 0;
}
