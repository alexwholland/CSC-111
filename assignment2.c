/*CSC Assigment 2
 * Alex Holland
 */

#include <stdio.h>
#include <math.h>

#define THRESHOLD 0.01

int test_count = 0;
int tests_passed = 0;

// assignment function prototypes
void print_dog_years(int age);
double get_average(int n1, int n2, int n3);
double get_rectangle_area(double len, double wid);
void is_speeding(int speed, int limit);
int get_max(int n1, int n2, int n3);
double distance(double x1, double y1, double x2, double y2);
double get_shipping_cost(double wt, double len, double wid);

// testing function prototypes
void print_test(int expr);
void test_print_dog_years();
void test_get_average();


int main() {
    printf("Running tests!\n");
    test_print_dog_years();
    test_get_average();

   double n = get_rectangle_area(2, 2);
   printf ("%f\n",n);

   is_speeding(10, 20);

   int v = get_max(1,2,1);
   printf ("%d\n", v);

    double a = distance(1,2,3,4);
    printf ("%f\n",a);

    double cost = get_shipping_cost(0.03, 12, 10);
    printf ("shipping cost: %f\n", cost);


    printf("%d/%d tests passed\n", tests_passed, test_count);
    return 0;
}

/*
 * purpose: prints the age of a dog in dog years
 *  give their age in human years
 * parameters: int age - dog's age in human years
 */

void print_dog_years(int age) {

    age =  age * 7;
    printf("dog is %d\n", age);
}

/*
 * purpose: calculates the floating point average of numbers n1, n2 and n3
 * parameters: int n1, int n2, int n3 - numbers
 * returns: double - the average
 */

double get_average(int n1, int n2, int n3) {

    double avg = 0;
    avg = (n1 + n2 + n3)/3.0;
    return avg;
}


/* Purpose: Calculate the area of rectangle
 * Parameters: double len - double wid
 * returns double - rectangle_area
 */

double get_rectangle_area(double len, double wid){

    double rectangle_area;
    rectangle_area = len * wid;
    return rectangle_area;
}


/*Purpose: Take an two integers representing speed
 * and the speed limit respectively and determines
 * whether a car is speeding or not
 * Parameters: int speed - int limit
 */

void is_speeding(int speed, int limit){

    int slow_speed_difference = limit - speed;
    if (speed < limit){
        printf("You are %d km/hr below the legal limit\n", slow_speed_difference);
    }else if (speed > limit){
        printf("Slow down! You are going %d km/hr\n", speed);
    }
}


/* Purpose: Takes 3 integers and finds the largest value.
 * Parameters: int n1, int n2, int n3
 * Returns: int - the largest value of 3 integers
 */

int get_max(int n1, int n2, int n3){

    if (n1 > n2 && n1 > n3) {
        return n1;
    }
    else if (n2 > n1 && n2 > n3){
        return n2;
    }
    else {
        return n3;
    }
}


/* Purpose: Calculates distance between two points
 * Parameters: double x1 - double y1 - double x2 - double y2
 * Returns: double - dist
 */

double distance(double x1, double y1, double x2, double y2){
    double dist;
    double power = 2;
    dist = sqrt(pow(x2-x1,power)+pow(y2-y1, power));
    return dist;
}


/*Purpose: Calculate the cost of shipping a letter
 * of different area's and weight using the
 * get_rectangle_area() function
 * Parameters: double wt - double len - double wid
 * Returns: double - cost
 */
double get_shipping_cost(double wt, double len, double wid) {
    double standard = 1.05;
    double non_standard = 1.90;
    double cost = 0;
    double weight_over_small = wt - 0.03;
    double weight_over_large = wt - 0.1;

    double size = get_rectangle_area(len, wid);

     if (size <= 282 && wt <= 0.05 && wt > 0.03) {
              cost = standard + ((weight_over_small * 1000) * 0.02);
          } else if (size <= 282 && wt <= 0.03){
              cost = standard;
          }else if (size > 282 && wt <= 0.1){
              cost = non_standard;
          }else if (size > 282 || wt > 0.1){
              cost = non_standard + ((weight_over_large * 1000) * 0.005);
          }else if (wt <= 0.1 ){
              cost = non_standard;
    }
return cost;
}


/*
 * purpose: increments the test count
 *  determines whether the given boolean expression result is true or false
 *  increments the number of tests passed it is true
 * parameters: int expr - the result of a boolean expression
 */
void print_test(int expr) {
    test_count++;
    if (expr) {
        printf("passed\n");
        tests_passed++;
    } else {
        printf("failed\n");
    }
    printf("\n");
}

void test_print_dog_years() {
    printf("testing print_dog_years\n");

    print_dog_years(1);
    print_dog_years(5);
    printf("\n");
}

void test_get_average() {
    printf("testing get_average\n");

    double result, expected = 0;

    result = get_average(0,0,0);
    expected = 0;
    printf("expected: %f, result: %f\n", expected, result);
    print_test(fabs(expected-result)<THRESHOLD);
    // fabs returns the absolute value of the given value

    result = get_average(0,0,9);
    expected = 3.0;
    printf("expected: %f, result: %f\n", expected, result);
    print_test(fabs(expected-result)<THRESHOLD);

    result = get_average(2, 4, 7);
    expected = 13/3.0;
    printf("expected: %f, result: %f\n", expected, result);
    print_test(fabs(expected-result)<THRESHOLD);

    printf("\n");
}
