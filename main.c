#include <stdio.h>
int main(){
    char municipality[50];
    char mayor[50];
    int population;


printf("Municipal Financial Management system\n");

printf("Welcome to windhoek municipality\n\n");

printf("Enter municipality: ");
scanf("%49s" , municipality);

printf("Enter mayor's name: ");
scanf("%49s", mayor);

printf("Enter population: ");
scanf("%d", &population);

printf("\n========================\n");

printf("Municipality report\n");
printf("=========================\n");
printf("Municipality: %s\n", municipality);
printf("Mayor's name: %s\n", mayor);
printf("Population  : %d\n", population);

return 0;

}