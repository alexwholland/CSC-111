/*CSC Assignment 6
 * Alex Holland - V00928553
 * 2/29/2020
 */
#include <stdio.h>


void print_array(int array[], int len);
int count_occurances(int array[], int len, int val);
void multiply_by(int array[], int len, int multiplier);
void multiply_by_to_dest(int array[], int dest[], int len, int multiplier);
int copy_values_above_to_dest(int array[], int dest[], int len, int threshold);
void shift_left_by_one(int array[], int start, int length);
int keep_values_above(int array[], int len, int threshold);
int contains_negatives(int array[], int len);


int main (void) {
    // Test your functions!
    int A1[5] =  {31, -41, 59, 2, 65};

    print_array(A1, 5);

    printf ("\n");

    int A2[4] = {1,2,4,2};
    int occur = count_occurances(A2, 4, 7);
    printf ("%d\n", occur);

    printf ("\n");

    int A3[5] = {1,2,4,2,2};
    multiply_by(A3,5, 2);
    print_array(A3, 5);

    printf("\n");

    int A4[5] = {1,2,4,2,2};
    int A5[5] = {};
    multiply_by_to_dest(A4,A5,5,2);
    print_array(A5, 5);

    printf("\n");

    int A6[3] = {3,7,5};
    int A7[3] = {};
    int copy = copy_values_above_to_dest(A6,A7,3,4);
    printf ("%d\n", copy);
    print_array(A7, 3);

    printf("\n");

    int A8[6] = {1,2,4,5,3,7};
    shift_left_by_one(A8, 1, 6);
    print_array(A8, 6);

    printf ("\n");

    int A9[5] = {};
    int above = keep_values_above(A9, 0, 5);
    print_array(A9, 0);
    printf ("%d\n", above);

    printf ("\n");

    int A10[3] = {0,5,3};
    int neg = contains_negatives(A10, 3);
    printf ("%d", neg);

    return 0;
}
/* Purpose: Print the array on one line with spaces
 * Parameters: int - array[], int - len
 */
void print_array(int array[], int len){
    for (int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    printf ("\n");
}

/* Purpose: count the values in an array that match a value
 * Parameters: int array[], int len, int val
 * Returns: int - count
 */

int count_occurances(int array[], int len, int val){
    int count = 0;
    for (int i = 0; i < len; i++){
        if (array[i] == val){
            count++;
        }
    }
    return count;
}

/* Purpose: Multiply every value in the array by a value
 * parameters: int array[], int len, int multiplier
 */

void multiply_by(int array[], int len, int multiplier){
    for (int i = 0; i < len; i++) {
        array[i] *= multiplier;
    }
}

/* Purpose: store multiplication of each value in
 * input array by given multiplier into destination array
 * Parameters: int array[], int dest[], int len, int multiplier
 *
 */

void multiply_by_to_dest(int array[], int dest[], int len, int multiplier){
    for (int i = 0; i < len; i++){
        dest[i] = array[i] * multiplier;
    }
}

/* Purpose: Store values of an array that are above a threshold value
 * into a destination array
 * Parameters: int array[], int dest[], int len, int threshold
 * Returns: int - count
 */

int copy_values_above_to_dest(int array[], int dest[], int len, int threshold){
    int count = 0;
    for (int i = 0; i < len; i++){
        if (array[i] > threshold){
            dest[count++] = array[i];
        }
    }
    return count;
}

/* purpose: shift every element left by one. Place a 0 at the last index
 * Parameters: int array[], int starts, int length
 */


void shift_left_by_one(int array[], int start, int length){
    for (int i = start; i < length; i++) {
        array[i] = array[i+1];
    }
    array[length-1] = 0;
}

/* Purpose: push all values above a threshold to the front of array
 * and pad the remainder elements with 0's
 * The function uses the shift_left_by_one function to discard of
 * values below threshold.
 * Parameters: int array[], int len, int threshold
 * Returns: int - len the (length of the array) - (discarded values)
 */

int keep_values_above(int array[], int len, int threshold) {
    for (int i = 0; i < len; i++){
        if (array[i] <= threshold){
            shift_left_by_one(array, i, len);     //implementation of shift_left_by_one //i+1
            array[len-1] = 0;
            len--;
            i--;
        }
    }
    return len;
}

/* Purpose: determine whether the array contains neg values
 * parameters: int array[], int len
 * Returns: int - 1, or int - 0
 */

int contains_negatives(int array[], int len) {
    for (int i = 0; i < len; i++) {
        if (array[i] < 0) {
            return 1;
        }
    }
    return 0;
}