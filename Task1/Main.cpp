#include "Triangle.cpp"
#include "Circle.h"
#include "Figure.h"

int main(){	
	cout << "Задание 1";
	cout << "\n";
	Triangle mas[3];
	double a, b, c;
	for (int i = 0; i < 3; i++) {
		cout << "Введите a,b и с для треугольник № " << i + 1 << " через пробел: " << endl;
		cin >> a >> b >> c;
		mas[i].set(a, b, c);
		if (!(mas[i].exst_tr())) {
			mas[i].show();
			cout << "Треугольника с такими сторонами не существует, попробуйте еще раз" << endl;
			i--;
		}
	}

	for (int i = 0; i < 3; i++) {
		mas[i].show();
		cout << "Периметри треугольника: " << mas[i].perimetr() << endl;
		cout << "Площадь треугольника: " << mas[i].square() << endl;
	}

	cout << "Задание 2";
	cout << "\n";
	float radius, x_center, y_center;
	float d, e, f;
	for (int i = 0; i < 3; i++) {
		cout << "Введите радиус, центр по Х и центр по У для окружности №" << i + 1 << " через пробел: " << endl;
		cin >> radius >> x_center >> y_center;
		Circle *circle = new Circle(radius, x_center, y_center);
		cout << "Площадь круга №" << i + 1 << " равна " << circle->square();
		cout << "Введите a,b и с для треугольник через пробел: " << endl;
		cin >> d >> e >> f;
		if (circle->triangle_in(d, e, f)) {
			cout << "Треугольник можно вписать окружность" << endl;
		}
		else if (circle->triangle_around(d, e, f)) {
			cout << "Окружность можно вписать в треугольник" << endl;
		}
		else {
			cout << "Треугольник не подходит ни для вписания, ни для описания";
		}
		float radius2, x_center2, y_center2;
		cout << "Введите радиус, центр по Х и центр по У для новой окружности" << i + 1 << " через пробел: " << endl;
		cin >> radius2 >> x_center2 >> y_center2;
		if (circle->check_circle(radius2, x_center2, y_center2)) {
			cout << "Новая окружность пересекается с окружность №" << i + 1 << endl;
		}
		else {
			cout << "Новая окружность НЕ пересекается с окружность №" << i + 1 << endl;
		}
		cout << "\n";
	}

	cout << "Задание 3";
	cout << "\n";
	float  x1, x2, x3, x4, y1, y2, y3, y4;
	for (int i = 0; i < 3; i++) {
		cout << "Введите координаты для x1, x2, x3, x4, y1, y2, y3, y4 четыреугольнка №" << i + 1 << " через пробел: " << endl;
		cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
		cout << "\n";
		Figure* figure = new Figure(x1, x2, x3, x4, y1, y2, y3, y4);
		figure->show();
		cout << "\n";
		if (figure->is_prug()) {
			cout << "Это прямоугольник!";
		}
		if (figure->is_square()) {
			cout << "Это квадрат!";
		}
		if (figure->is_romb()) {
			cout << "Это ромб!";
		}
		if (figure ->is_in_circle()) {
			cout << "Четырехугольник можно вписать в окружность";
		}
		if (figure->is_out_circle()) {
			cout << "В четырехугольник можно вписать окуржность";
		}
		cout << "\n";
	}

	return 0;
}