#include <stdio.h>
#include <math.h>

double f(double x) {
    return log(x);  
    }

double right_rectangle_integration(double a, double b, double epsilon) {
    int n = 1;  
    double h;   
    double I_old, I_new;

    // Начальное значение прямоугольника
    h = (b - a) / n;
    I_new = 0.0;

    // Вычисление начального интеграла
    for (int i = 1; i <= n; i++) {
        double x = a + i * h;
        I_new += f(x) * h;
    }

    do {
        I_old = I_new;
        n *= 2;  
        h = (b - a) / n;

        // Вычисление интеграла
        I_new = 0.0; 
        for (int i = 1; i <= n; i++) {
            double x = a + i * h;
            I_new += f(x) * h;
        }
    } while (fabs(I_new - I_old) > epsilon);  

    return I_new;
}

int main() {
    double a, b, epsilon;

    printf("Введите пределы интегрирования (a, b): ");
    if (scanf("%lf %lf", &a, &b) != 2 || a <= 0) {
        printf("Ошибка: Пределы интегрирования должны удовлетворять условиям: a > 0, a и b - числа.\n");
        return 1;
    }

    printf("Введите погрешность: ");
    if (scanf("%lf", &epsilon) != 1 || epsilon <= 0) {
        printf("Ошибка: Погрешность должна быть положительной.\n");
        return 1; 
    }

    double result = right_rectangle_integration(a, b, epsilon);
    printf("Результат интегрирования: %lf\n", result); 

    return 0;
}


