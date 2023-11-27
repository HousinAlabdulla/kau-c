#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Funktionen för att printa tabellen i första alternativet(Generator) och alternav 2 (som sorterar tabellen)*/

void print(int tabell[])
{
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%4d ", tabell[i]);
        if((i+1) % 10 == 0)
            printf("\n");
    }
    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Funktionen som genererar random 100 positiva tal 
for loopen stoppas när det blir 100 tall i vektorn tabell.
*/
void generate(int tabell[])
{
    
    srand(time(NULL));
    for(int i=0; i< SIZE; i++){
        tabell[i] = 0 + rand() % 901;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Sort(int tabell[])
{
    
    for(int i = 0; i < SIZE - 1; i++)
    {
        for(int j = 0; j < SIZE - 1; j++)
        {
            if(tabell[j] > tabell[j+1])                       // om i if satsen tabell[j] komm innan tabell[i] så skriver man (tabell[j] = tabell[j+1];) i nästa linje. dör att jämföra talet i första platsen och andra platsen o.s.v
            {
                int temp    = tabell[j];                       //variabel temp (temporärt) är för att spara valeus temporärt för att sortera 
                tabell[j]   = tabell[j+1];
                tabell[j+1] = temp;                           // här bytes platser
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cal(int tabell[])
{
    int sum = 0;
    // Melvärden
    for(int i = 0; i < SIZE; i++)
    {
        sum = sum + tabell[i];
    }
    float medel = sum / SIZE;

    //Median
    int median = (tabell[49] + tabell[50])/ 2;

    printf("Min = %d , Max = %d \n", tabell[0], tabell[99]);
    printf("Medelvärdet =  %.2f , Median = %d\n", medel, median);
    printf("\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*void hitta(int tabell[])
{
    int tal;
    printf("Skriv din tal som du vill hitta: ");
    scanf("%d", &tal);
    for(int i = 0; i < SIZE; i++)
    {
        if(tabell[i] == tal)                    //hitta vart talet är.
        {
            printf("found in %d\n ", i);
        }
    }
}

*/


void menu()
{
    printf("1. Generera en tallista med 100 positiva tal\n");
    printf("2. Soretera menyn i storleksordning\n");
    printf("3. Berakna medelvarde, median, min och max\n");
    printf("4. Kolla om talet finns med i listan\n");
    printf("0. Avsluta\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void binary_search(int tabell[]) {
    int tal;

    printf("Skriv in Talet: ");
    scanf("%d", &tal);

    int l = 0;
    int r = SIZE - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (tabell[mid] == tal) {
            printf("Numret %d hittades i rad %d, kolumn %d.\n", tal, mid / 10 + 1, mid % 10 + 1);
            return;
        } else if (tabell[mid] < tal) {
            l = mid + 1;
        } else {
            r = mid - 1;  // Uppdatera r här, inte l.
        }
    }

    printf("Numret %d finns inte i talfoljden.\n", tal);
}

*/


void binary_search (int tabell[])
{
    int tal, l = 0, left, right;
    printf("Enter a num to search; ");
    scanf("%d", &tal);
    int r = SIZE - 1;
    int mid = (l + r) / 2;
    left = 0 ; 
    right = SIZE;

    while (left <= right)
    {
       int middle = left + (right - left) / 2;

       if(tabell[middle] == tal){
           printf("The position of %d is %d\n", tal, middle +1);
           break;
       }
        else if (tabell[middle] < tal)
            left = middle + 1;
        else 
            right = middle - 1;

    }
    






/*
    for(int i = 0; i < SIZE; i++)
    {
        if(tabell[i] == tal)
            printf("The index of %d is %d\n", tal, i + 1);
    }
    */
/*
    if(tabell[mid] < tal)
    {
        l = mid +1;
    }
    else if (tabell[mid] == tal)
    {
        printf("taler är i %d \n", mid +1);
        return ; 
    }
    else
    {
        r = mid - 1;
        mid = (l + r) / 2;
    }
    */
}

int main(){
    int tabell[SIZE];
    menu();
    generate(tabell);
    print(tabell);
    printf("\n \n \n");
    Sort(tabell);
    print(tabell);
    cal(tabell);
    binary_search(tabell);

    return 0;
}
