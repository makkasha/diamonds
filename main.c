#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int clean_stdin() //Function for the user input
{
    while (getchar()!='\n');
    return 1;
}
//Find odd numbers smaller or equal to a number
void odd_num(unsigned int number, unsigned int* odd_array){
    unsigned int count = 0;
    for(int i = 1; i < (number + 1); i++){
        if(i % 2) {
            odd_array[count] = i;
            count++;
        }
    }
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

int main(void) {
    unsigned int maxWidth = 0;
    char c = 0;
    //Require user input
    do {
        printf("Max. Breite des Diamanten: ");
        printf("\n");
    }while(((scanf("%d%c", &maxWidth, &c)!=2 || c!='\n') && clean_stdin()) || maxWidth<1 || maxWidth>128); //Only allow unsigned int input

    //Reserve heap memory for the output stars string
    char* s = (char*)calloc(maxWidth * 2 + 2, sizeof(char));
    //Reserve heap memory for the odd numbers array
    unsigned int* odd_array = (unsigned int*)calloc(round(maxWidth / 2), sizeof(unsigned int));
    //Fill the odd_array with odd numbers smaller or equal to maxWidth
    odd_num(maxWidth, odd_array);

    int odd_even = 0;
    if (maxWidth % 2){
        odd_even = 1;
    }
    //Print the upper half of the diamond (ascending)
    for(int i = 0; i < round(maxWidth / 2) + odd_even; i++){
        out_line(odd_array[i], s);
        printf("%*s", maxWidth + 2 * i, s);
        printf("\n");
    }
    free(s); //Free heap memory

    //Reserve heap memory for the output stars string
    char* v = (char*)calloc(maxWidth * 2, sizeof(char));

    //Print the lower half of the diamond (descending)
    for(int i = round(maxWidth / 2) - 2 + odd_even; i >= 0; i--){
        out_line(odd_array[i], v);
        printf("%*s", maxWidth + 2 * i, v);
        printf("\n");
    }

    return 0;
}
