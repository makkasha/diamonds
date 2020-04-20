#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

void out_line(unsigned int const asterisks, char* s){
    for(int i = 0; i < asterisks; i++) {
        if(i < asterisks - 1) {
            sprintf(s + 2 * i, "%.*s", 2, "* ");
        }
        else{
            sprintf(s + 2 * i, "%.*s", 2, "*");
        }
    }
}

void odd_num(unsigned int number, unsigned int* odd_array){
    unsigned int count = 0;
    for(int i = 1; i < (number + 1); i++){
        if(i % 2) {
            odd_array[count] = i;
            count++;
        }
    }
}

int main(void) {
    unsigned int maxWidth = 0;
    char c = 0;
    do {
        printf("Max. Breite des Diamanten: ");
        printf("\n");
    }while(((scanf("%d%c", &maxWidth, &c)!=2 || c!='\n') && clean_stdin()) || maxWidth<1 || maxWidth>128);

    char* s = (char*)calloc(maxWidth * 2 + 2, sizeof(char));
    unsigned int* odd_array = (unsigned int*)calloc(round(maxWidth / 2), sizeof(unsigned int));
    odd_num(maxWidth, odd_array);
    int odd_even = 0;
    if (maxWidth % 2){
        odd_even = 1;
    }

    for(int i = 0; i < round(maxWidth / 2) + odd_even; i++){
        out_line(odd_array[i], s);
        printf("%*s", maxWidth + 2 * i, s);
        printf("\n");
    }
    free(s);

    char* v = (char*)calloc(maxWidth * 2, sizeof(char));
    for(int i = round(maxWidth / 2) - 2 + odd_even; i >= 0; i-- ){
        out_line(odd_array[i], v);
        printf("%*s", maxWidth + 2 * i, v);
        printf("\n");
    }

    return 0;
}
