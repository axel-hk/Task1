#include "eq2.cpp"
#include "rational.h"
#include <vector>
int main()
{
  /*  double a, b, c;
    cin >> a >> b >> c;
    eq2 exmpl(a, b, c);
    exmpl.find_X();
    cout << exmpl.find_Y(6);

    // Ввод количества объектов
    int n;
   cout << "Введите количество объектов: ";
   cin >> n;

   // Создание динамического массива из объектов rational
   rational* fractions = new rational[n];

   // Заполнение массива значениями пользователя
   for (int i = 0; i < n; i++) {
       int numerator, denominator;
       std::cout << "Введите числитель и знаменатель для дроби #" << i + 1 << ": ";
       std::cin >> numerator >> denominator;

       // Создание объекта и установка значений
       rational fraction;
       fraction.set(numerator, denominator);
       fractions[i] = fraction;
   }

   // Вывод значений на экран
   for (int i = 0; i < n; i++) {
       std::cout << "Дробь #" << i + 1 << ": ";
       fractions[i].show();
       std::cout << std::endl;
   }

   // Освобождение памяти
   delete[] fractions;*/

   // Ввод количества объектов
    int n;
    cout << "Введите количество объектов: ";
    cin >> n;
    rational* fractions2 = new rational[n];
    for (int i = 0; i < n; i++) {
        int numerator, denominator;
        std::cout << "Введите числитель и знаменатель для дроби #" << i + 1 << ": ";
        std::cin >> numerator >> denominator;

        // Создание объекта и установка значений
        rational fraction;
        fraction.set(numerator, denominator);
        fractions2[i] = fraction;
    }
    for (int i = 0; i < n; i++) {
        std::cout << "Дробь #" << i + 1 << ": ";
        fractions2[i].show();
        std::cout << std::endl;
    }

    for (int i = 0; i < n-1; i++) {
        rational c;
        // Операция сложения с помощью внутреннего метода класса
        int f = i;
        f++;
        c = fractions2[i] + fractions2[f];
        std::cout << "сложение" << endl;
        c.show();

        // Операция вычитания с помощью дружественной функции
        c = fractions2[i] - fractions2[f];
        std::cout << "Вычитание" << endl;
        c.show();

        // Операция инкремента числителя дроби
        ++fractions2[i];
        cout << "Инкримента" << endl;
        fractions2[i].show();

        // Операция сравнения для дробей (==)
        if (fractions2[i] == fractions2[f]) {
            cout << "Соседние элементы равны" << endl;
        }
        else {
            cout << "Соседние элементы неравны" << endl;
        }

        // Операция сравнения для дробей (>)
        if (fractions2[i] > fractions2[f]) {
            cout << "Первый элемент больше второго" << endl;
        }
        else {
            cout << "Первый элемент меньше или равен второму" << endl;
        }

        // Операция присваивания для дробей
        c = fractions2[i];
        cout << "c = " << endl;
        c.show();
    }

    delete[] fractions2;


}