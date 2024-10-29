#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x; 
}

double right_rectangle_integration(double a, double b, double epsilon) {
    double n = 1;  
    double h;   
    double I_old, I_new;

    // Начальное значение интеграла
    h = (b - a) / n;
    I_new = 0.0;

    // Вычисление начального интеграла
    for (double i = 1; i <= n; i++) {
        double x = a + i * h;
        I_new += f(x) * h;
    }

    do {
        I_old = I_new;
        n *= 2;  
        h = (b - a) / n;

        // Вычисление интеграла
        I_new = 0.0; // Обнуляем I_new для нового этапа
        for (double i = 1; i <= n; i++) {
            double x = a + i * h;
            I_new += f(x) * h;
        }
    } while (fabs(I_new - I_old) > epsilon);  

    return I_new;
}

int main() {
    double a, b, epsilon;

    printf("Введите пределы интегрирования (a, b): ");
    scanf("%lf %lf", &a, &b);
    printf("Введите погрешность: ");
    scanf("%lf", &epsilon);

    // Проверяем, что a < b
    if (a >= b) {
        printf("Ошибка: значение a должно быть меньше значения b.\n");
        return 1; // Завершаем программу с ошибкой
    }

    // Проверяем, что epsilon положительный
    if (epsilon <= 0) {
        printf("Ошибка: погрешность должна быть положительной.\n");
        return 1; // Завершаем программу с ошибкой
    }

    double result = right_rectangle_integration(a, b, epsilon);
    printf("Результат интегрирования: %lf", result); 

    return 0;
}

