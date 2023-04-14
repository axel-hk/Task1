#include <iostream>
#include <cmath>

using namespace std;

class eq2 {
private:
    double a, b, c;
    double D;

public:
    eq2(double a1, double b1, double c1) {
        a = a1; b = b1; c = c1;
        D = b * b - 4 * a * c;
    }
    void set(double a1, double b1, double c1) {
        a = a1; b = b1; c = c1;
        D = b * b - 4 * a * c;
    }
    double find_X() {
        if (D < 0) {
            cout << "Корней нет" << endl;
            return 0;
        }
        else {
            if (D == 0) {
                cout << "Корень один: " << endl;
                double x = (-b - sqrt(D)) / (2 * a);
                cout << x << endl;
                return x;
            }
            else {
                cout << "Корней 2, наибольший: " << endl;
                double x1 = (-b - sqrt(D)) / (2 * a);
                double x2 = (-b + sqrt(D)) / (2 * a);
                if (x1 > x2) {
                    cout << x1 << endl;
                    return x1;
                }
                else {
                    cout << x2 << endl;
                    return x2;
                }
            }
        }
    }
    double find_Y(double x1) {
        return a * x1 * x1 + b * x1 + c;
    }
};