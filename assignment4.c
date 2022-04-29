/*Assigment 4: Count driven loops
 *Alex Holland
 */

#include <stdio.h>

int sum_odd(int n);
void draw_tail(int size);
void draw_booster(int size);
void draw_instrument_unit(int size);
void draw_lem_adapter(int size);
void draw_space_craft(int size);
void draw_rocket(int size, int n);

int main() {
    printf("Assignment 3\n");
    int odd = sum_odd(7);
    printf("%d\n",odd);
    printf("\n");
    draw_rocket(3,2);
    return 0;
}
/*Purpose: calculate the sum of odd integers 0-n
 * Parameters: int - n
 * Returns: int - sum
 */
int sum_odd(int n){
   int sum = 0;
    for (int i = 0; i <= n; i++){
        if (i % 2 != 0) {
             sum = sum + i;
        }
    }
    return sum;
}
/*Purpose: Print the ascii rocket tail at different sizes
 * Parameters: int - size
 */
void draw_tail(int size){
    printf("//  ");

    for (int j = 0; j < size; j++){
        printf("/\\  ");
    }

    printf("\\\\");
    printf("\n");
}
/*Purpose: print the ascii rocket booster at different sizes
 *Parameters: int - size
 */
void draw_booster(int size) {
for (int i = 0; i <= size; i++) {
    printf("|");
    for (int dot1 = size; dot1 > i; dot1--) {
        printf(".");
    }
    for (int slash1 = 0; slash1 < i + 1; slash1++) {
        printf("/\\");
    }
    for (int dot2 = size * 2; dot2 > i * 2; dot2--) {
        printf(".");
    }
    for (int slash1_2 = 0; slash1_2 < i + 1; slash1_2++) {
        printf("/\\");
    }
    for (int dot1_2 = size; dot1_2 > i; dot1_2--) {
        printf(".");
    }
    printf("|");
    printf("\n");
}
    for (int i = 0; i <= size; i++) {
        printf("|");
        for (int dot1 = 0; dot1 < i; dot1++) {
            printf(".");
        }
        for (int slash2 = size; slash2 >= i; slash2--){
            printf("\\/");
        }
        for (int dot2 = 0; dot2 < i*2; dot2++){
            printf(".");
        }
        for (int slash2_1 = size; slash2_1 >= i; slash2_1--){
            printf("\\/");
        }
        for (int dot2_2 = 0; dot2_2 < i; dot2_2++) {
            printf(".");
        }
        printf("|");
        printf("\n");
    }
    printf("+");
    for (int filler = 0; filler < size*2+2; filler++) {
        printf("=*");
    }
    printf("+");
    printf("\n");
}
/*Purpose: print the ascii rocket instrument_unit at different sizes
 *Parameters: int - size
 */
void draw_instrument_unit(int size) {

    for (int i = 0; i < 2; i++) {
        printf("||");

        for (int j = 0; j <= size * 2; j++) {
            printf("~#");
        }
    printf("||");
    printf ("\n");
    }
    printf("+");
    for (int filler = 0; filler < size*2+2; filler++) {
            printf("=*");
        }
    printf("+");
    printf("\n");
}

/*Purpose: print the ascii rocket lem_adapter at different sizes
 * Parameters: int - size
 */

void draw_lem_adapter(int size){

    for (int i = 0; i < 2; i++){
    if (i == 0){
    printf(" ");
    }
    printf ("//");
    for (int inner = 1; inner <= size*2; inner++) {
        printf(" &");
    }
    if (i == 1){
        printf(" &");
    }
    printf ("\\\\");
    printf("\n");
    }
    printf("+");
    for (int filler = 0; filler < size*2+2; filler++) {
        printf("=*");
    }
    printf("+");
    printf("\n");
}

/*Purpose: print the ascii rocket space_craft at different sizes
 * Parameters: int - size
 */

void draw_space_craft(int size){
    for (int i = 0; i < size*2; i++){
        printf("  ");
        for (int space1 = size*2-1; space1 >= i; space1--){
            printf(" ");
        }
        for (int slash1 = 1; slash1 <= i; slash1++){
            printf("/");
        }
        printf("**");
        for (int slash2 = 1; slash2 <= i; slash2++){
            printf("\\");
        }
        for (int space2 = size*2-1; space2 >= i; space2--){
            printf(" ");
        }

       printf("\n");
    }

    printf("  +");
    for (int filler = 0; filler < size*2; filler++) {
        printf("=*");
    }
    printf("+");
    printf("\n");
}

/*Purpoes: call the rocket ascii functions and print them according to size
 * and number of boosters n.
 *
 *Parameters: int - size, int - n
 */

void draw_rocket(int size, int n){
   draw_space_craft(size);
   draw_lem_adapter(size);
   draw_instrument_unit(size);

   for (int i = 0; i < n; i++) {
       draw_booster(size);
   }

   draw_tail(size);
}
