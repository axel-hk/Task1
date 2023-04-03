#include "Figure.h"
#include <iostream>
#include <cmath>
#define EPS 1e-9

using namespace std;

float Figure::dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

Figure::Figure(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) {
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
    this->x4 = x4;
    this->y1 = y1;
    this->y2 = y2;
    this->y3 = y3;
    this->y4 = y4;

    // вычисляем стороны четырехугольника
    float a = dist(x1, y1, x2, y2);
    float b = dist(x2, y2, x3, y3);
    float c = dist(x3, y3, x4, y4);
    float d = dist(x4, y4, x1, y1);

    // вычисляем периметр
    P = a + b + c + d;

    // вычисляем площадь через полупериметры треугольников
    float p1 = (a + b + dist(x1, y1, x3, y3)) / 2;
    float p2 = (c + d + dist(x2, y2, x4, y4)) / 2;
    S = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - dist(x1, y1, x3, y3))) +
        sqrt(p2 * (p2 - c) * (p2 - d) * (p2 - dist(x2, y2, x4, y4)));
    }
    
   void Figure::show() {
        cout << "Координаты вершин четырехугольника: " << endl;
        cout << "(" << x1 << ", " << y1 << ")" << endl;
        cout << "(" << x2 << ", " << y2 << ")" << endl;
        cout << "(" << x3 << ", " << y3 << ")" << endl;
        cout << "(" << x4 << ", " << y4 << ")" << endl;
        cout << "Периметр: " << P << endl;
        cout << "Площадь: " << S << endl;
   }

   bool Figure::is_prug() {
       float ab = dist(x1, y1, x2, y2);
       float bc = dist(x2, y2, x3, y3);
       float cd = dist(x3, y3, x4, y4);
       float da = dist(x4, y4, x1, y1);
       float ac = dist(x1, y1, x3, y3);
       float bd = dist(x2, y2, x4, y4);

       // Проверяем, есть ли две противоположные стороны, которые параллельны и имеют одинаковую длину
       if (abs(ab - cd) < EPS && abs(bc - da) < EPS) {
           return true;
       }
       if (abs(ac - bd) < EPS && abs(ab - cd) < EPS) {
           return true;
       }
       if (abs(ac - bd) < EPS && abs(bc - da) < EPS) {
           return true;
       }
       return false;
   }

   bool Figure::is_square() {
       float ab = dist(x1, y1, x2, y2);
       float bc = dist(x2, y2, x3, y3);
       float cd = dist(x3, y3, x4, y4);
       float da = dist(x4, y4, x1, y1);
       float ac = dist(x1, y1, x3, y3);
       float bd = dist(x2, y2, x4, y4);

       // Проверяем, является ли фигура прямоугольником и все стороны равными
       if (is_prug() && abs(ab - bc) < EPS && abs(bc - cd) < EPS && abs(cd - da) < EPS) {
           return true;
       }
       return false;
   }

   bool Figure::is_romb() {
       float d1 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
       float d2 = sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));
       float d3 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
       float d4 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
       float d5 = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2));
       float d6 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

      

       if (abs(d1 - d2) < EPS && abs(d2 - d3) < EPS && abs(d3 - d4) < EPS && abs(d4 - d5) < EPS && abs(d5 - d6) < EPS) {
           return true;
       }
       return false;
   }

   bool Figure::is_in_circle() {
       float AB = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
       float BC = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
       float CD = sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2));
       float DA = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));
       float AC = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
       float BD = sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));

       float S1 = (AB + BC + AC) / 2.0;
       float S2 = (CD + DA + AC) / 2.0;
       float R1 = AB * BC * AC / (4 * sqrt(S1 * (S1 - AB) * (S1 - BC) * (S1 - AC)));
       float R2 = CD * DA * AC / (4 * sqrt(S2 * (S2 - CD) * (S2 - DA) * (S2 - AC)));

       if (R1 > AC - EPS && R2 > AC - EPS) {
           return true;
       }
       return false;
   }

   bool Figure::is_out_circle() {
       // Вычисляем длины диагоналей
       float d1 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
       float d2 = sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));

       // Если длины диагоналей не равны, то четырехугольник не может быть вписан в окружность
       if (abs(d1 - d2) > EPS) {
           return false;
       }

       // Вычисляем радиус окружности, описанной вокруг четырехугольника
       float R = d1 / 2;

       // Вычисляем координаты центра окружности, описанной вокруг четырехугольника
       float cx = (x1 + x3) / 2;
       float cy = (y1 + y3) / 2;

       // Проверяем, что все вершины четырехугольника лежат вне окружности
       if (sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2)) > R + EPS &&
           sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2)) > R + EPS &&
           sqrt(pow(x3 - cx, 2) + pow(y3 - cy, 2)) > R + EPS &&
           sqrt(pow(x4 - cx, 2) + pow(y4 - cy, 2)) > R + EPS) {
           return true;
       }
       else {
           return false;
       }
   }
