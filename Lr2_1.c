#include <stdio.h> 
double sum(int n) 
{ 
    
  double i, s = 0.0; 
  for (i = 1; i <= n; i++) 
      s = s + 1/i; 
  return s; 
} 
  
  
int main(){
    int n ; 
    printf("Enter n");
    scanf("%d", &n);
    
    printf("Sum is %f", sum(n)); 
    
    
    
    return 0; 
}
