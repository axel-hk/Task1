#include "Circle.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
}


void Circle::set_circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
}

float Circle::square() {
    return M_PI * pow(radius, 2);
}

bool Circle::triangle_around(float a, float b, float c) {
    float p = (a + b + c) / 2;
    float R = (a * b * c) / (4 * sqrt(p * (a + b - p) * (a + c - p) * (b + c - p)));
    return R >= radius;
}

bool Circle::triangle_in(float a, float b, float c) {
    float r = (2 * square()) / (a + b + c);
    return r <= radius;
}

bool Circle::check_circle(float r, float x_cntr, float y_cntr) {
    float distance = sqrt(pow(x_center - x_cntr, 2) + pow(y_center - y_cntr, 2));
    return distance <= radius + r;
}

