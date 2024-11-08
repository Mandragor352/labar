#include <stdio.h>

double sum(int n, float epsilon) 
{ 
    double s = 0.0; 
    double term; 

    for (int i = 1; i <= n; i++) { 
        term = 1.0 / i; 
        if (term < epsilon) {
            break; 
        }
        s += term; 
    } 

    return s; 
}

int main(){
    float epsilon; 
    int n;

    printf("Введите количество членов n: ");
    scanf("%d", &n);

    printf("Введите погрешность E: ");
    scanf("%f", &epsilon); 
    
    double result = sum(n, epsilon);
    printf("Сумма равна: %lfn", result); 
    
    return 0; 
}