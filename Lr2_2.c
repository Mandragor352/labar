#include <stdio.h>
#include <math.h>


double f(double x) {
    return x * x; 
}


double right_rectangle_integration(double a, double b, double epsilon) {
    int n = 1;  
    double h;   
    double I_old, I_new;

    //Начальное значение интеграла
    h = (b - a) / n;
    I_old = 0.0;
    I_new = 0.0;

    
    do {
        I_old = I_new;
        I_new = 0.0;
        n *= 2;  
        h = (b - a) / n;

        // Вычисление интеграла
        for (int i = 1; i <= n; i++) {
            double x = a + i * h;
            I_new += f(x) * h;
        }
    } while (fabs(I_new - I_old) < epsilon);  

    return I_new;
}

int main() {
    double a, b, epsilon;


    printf("Введите пределы интегрирования (a, b): ");
    scanf("%lf %lf", &a, &b);
    printf("Введите погрешность: ");
    scanf("%lf", &epsilon);

    double result = right_rectangle_integration(a, b, epsilon);
    printf("Результат интегрирования: %lfn", result);

    return 0;
}