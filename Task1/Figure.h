#ifndef FIGURE_H
#define FIGURE_H

class Figure {
private:
    float x1, x2, x3, x4; // координаты x вершин четырехугольника
    float y1, y2, y3, y4; // координаты y вершин четырехугольника
    float S; // площадь четырехугольника
    float P; // периметр четырехугольника

public:
    Figure(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4); // конструктор объектов класса figure
    void show(); // вывод параметров четырехугольника на экран, включая площадь и периметр
    float dist(float x1, float y1, float x2, float y2); //возвращает расстояние между двуся координатами
    bool is_prug(); // возвращает true, если четырехугольник прямоугольник, и false в противном случае
    bool is_square(); // возвращает true, если четырехугольник квадрат, и false в противном случае
    bool is_romb(); // возвращает true, если четырехугольник ромб, и false в противном случае
    bool is_in_circle(); // возвращает true, если четырехугольник можно вписать в окружность, и false в противном случае
    bool is_out_circle(); // возвращает true, если в четырехугольник может быть вписана окружность, и false в противном случае
};

#endif // FIGURE_H


