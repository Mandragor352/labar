#include <stdio.h>

double sum(float epsilon) 
{ 
    double s = 0.0; 
    double term = 1.0; 

    for (int i = 1; term >= epsilon; i++) { 
        s += term; 
        term /= i;
    } 

    return s; 
}

int main(){
    float epsilon;

    printf("Введите погрешность E: ");
    if (scanf("%f", &epsilon) != 1) {  // Проверка успешности ввода
        printf("Ошибка: введено некорректное значение\n");
        return 1;
    }

    if (epsilon <= 0) {  // Проверка, что значение больше 0
        printf("Ошибка: E должно быть больше 0\n");
        return 1;
    }    

    double result = sum(epsilon);
    printf("Сумма равна: %lf\n", result-1); 

    return 0; 
}

