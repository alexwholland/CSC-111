/* CSC Assignment 7
 * Alex Holland
 */
#include <stdio.h>

#define NUM_COLS 2  // you are free to change this value, we will when we test your code


void print_array(int array[], int len);
void print_matrix(int m[][NUM_COLS], int num_rows);
void get_location_of_min(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col);
void get_location_of_max(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col);
void swap_min_max_values(int matrix[][NUM_COLS], int num_rows);

void print_matrix_pointers(int* matrix[], int num_rows, int num_cols);
void matrix_transpose_pointers(int* m1[], int* m_result[], int num_rows, int num_cols);
void matrix_multiply_by_vector_pointers(int* matrix[], int vector[], int v_result[], int num_rows, int num_cols);
void matrix_multiply_pointers(int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m2);



int main (void) {

    int A1[3][NUM_COLS] = {{1,7},
                           {4,2},
                           {2,9}};
    print_matrix(A1,3);

    printf ("\n");

    int row;
    int col;
    get_location_of_min(A1, 3,&row,&col);
    printf ("%d %d", row, col);

    printf ("\n");
    get_location_of_max(A1, 3,&row,&col);
    printf ("%d %d", row, col);

    printf ("\n\n");

    swap_min_max_values(A1, 3);
    print_matrix(A1,3);

    printf ("\n");
    int b1[2] = {1,7};
    int b2[2] = {4,2};
    int b3[2] = {3,9};
    int* A2[3] = {b1,b2,b3};
    print_matrix_pointers(A2, 3, 2);

    printf ("\n");

    int d1[2] = {1,7};
    int d2[2] = {4,2};
    //  int d3[2] = {3,9};
    int* t[3] = {d1,d2};
    int b4[3];
    int b5[3];
    int* A3[2] = {b4,b5};
    matrix_transpose_pointers(t,A3,2,2);
    print_matrix_pointers(A3, 2,2);

    printf ("\n");
    int b6[3] = {1,-1,2};
    int b7[3] = {0,-3,1};
    int array[3] = {2,1,0};
    int dest[2] = {};
    int *A4[2] = {b6,b7};
    matrix_multiply_by_vector_pointers(A4, array, dest, 2, 3);
    print_array(dest, 2);

    printf ("\n");
    int b8[3] = {0,4,-2};
    int b9[3] = {-4,-3,0};
    int b10[2] = {0,1};
    int b11[2] = {1,-1};
    int b12[2] = {2,3};
    int* input[2] = {b8,b9};
    int* mat[3] = {b10,b11,b12};
    int b13[2];
    int b14[2];
    int* dst[2] = {b13,b14};
    matrix_multiply_pointers(input,mat,dst,2,3);
    print_matrix_pointers(dst,2,2);
    return 0;
}


// Purpose: prints values in array on one line with space after each
// Params:  int array[], int len - number of elements in array
// Returns: nothing
void print_array(int array[], int len){
    int i;
    for(i=0; i<len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/* Purpose: Prints all values in matrix
 * Parameters: int m{}{}, int num_rows
 * Returns: nothing
 */

void print_matrix(int m[][NUM_COLS], int num_rows){
    for (int row = 0; row < num_rows; row++){
        for (int col = 0; col < NUM_COLS; col++){
            printf ("%d ", m[row][col]);
        }
        printf("\n");
    }
}

/* Purpose: Find location of min value in matrix and stores row and column
 * into a memory location
 * Parameters: int matrix[][], int num_rows, int* location_row. int * location_col
 * Returns: nothing
 */

void get_location_of_min(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col) {
    *location_row = 0;
    *location_col = 0;
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (matrix[row][col] <= matrix[*location_row][*location_col]) {
                *location_row = row;
                *location_col = col;
            }
        }
    }
}

/* Purpose: Find location of max value in matrix and stores row and column
 * into a memory location
 * Parameters: int matrix[][], int num_rows, int* location_row. int * location_col
 * Returns: nothing
 */

void get_location_of_max(int matrix[][NUM_COLS], int num_rows, int* location_row, int* location_col){
    *location_row = 0;
    *location_col = 0;
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (matrix[row][col] >= matrix[*location_row][*location_col]) {
                *location_row = row;
                *location_col = col;
            }
        }
    }
}

/* Purpose: Find the location of max and min values and swap there location
 * Parameters: int matrix[][], int num_rows
 * Returns: nothing
 */

void swap_min_max_values(int matrix[][NUM_COLS], int num_rows){

    int hold;
    int minrow, mincol;
    int maxrow, maxcol;

    get_location_of_min(matrix, 3, &minrow, &mincol);
    get_location_of_max(matrix, 3, &maxrow, &maxcol);

    hold = matrix[minrow][maxrow];                      //holds the min values
    matrix[minrow][mincol] = matrix[maxrow][maxcol];    //sets min value equal to max value
    matrix[maxrow][maxcol] = hold;                      //sets max value to the holded min value
}

/* Purpose: Prints all values in a matrix
 * Parameters: int* matrix[], int num_rows, int num_cols
 * Returns: nothing
 */

void print_matrix_pointers(int* matrix[], int num_rows, int num_cols){
    for (int row = 0; row < num_rows; row++){
        for (int col = 0; col < num_cols; col++){
            printf ("%d ", matrix[row][col]);
        }
        printf ("\n");
    }
}

/* Purpose: Calculates and stores the transpose of a matrix
 * Parameters: int* m1[], int* m_result[], int num_rows, int num_cols
 * Returns: nothing
 */

void matrix_transpose_pointers(int* m1[], int* m_result[], int num_rows, int num_cols){
    for (int row = 0; row < num_rows; row++){
        for (int col = 0; col < num_cols; col++){
            m_result[col][row] = m1[row][col];
        }
    }
}

/* Purpose: Multiply a matrix by an array
 * Parameters: int* matrix[], int vector[], int v_result[], int num_rows, int num_cols
 * Returns: nothing
 */

void matrix_multiply_by_vector_pointers(int* matrix[], int vector[], int v_result[], int num_rows, int num_cols){
    for (int row = 0; row < num_rows; row++){
        int sum = 0;
        for (int col = 0; col < num_cols; col++){
            sum += matrix[row][col] * vector[col];
        }
        v_result[row] = sum;
    }
}

/* Purpose: Multiply two matrices
 * Parameters: int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m2
 * Returns: nothing
 */

void matrix_multiply_pointers(int* m1[], int* m2[], int* m_result[], int num_rows_m1, int num_cols_m2) {

    for (int i = 0; i < num_rows_m1; i++) {
        for (int j = 0; j < num_cols_m2; j++) {
            m_result[i][j] = 0;
            for (int k = 0; k < num_cols_m2; k++) {
                m_result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
