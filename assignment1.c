/*
 * CSC 111 Assignment 1
 * 
 * Author: Alex Holland
 *
 * Purpose:
 * -Write functions to print Ascii Art (logo) in a specified order.
 * -Calculate the surface area of cylinder given height and diameter.
 */

#include <stdio.h>
#include <math.h>

void print_pig();
void print_frog();
void print_line();
void print_logo();
void print_surface_area();

int main() {

    print_logo();
    printf("\n");
    print_surface_area();

    return 0;
}

/*
 * Purpose:
 * Function that prints Ascii pig art.
 */

void print_pig(){
    printf("  ^  ^\n");
    printf(" (0  0)\n");
    printf("  (oo)\n");
    printf("@(\")_(\")\n");
}

/*
 * Purpose:
 * Function that prints Ascii frog art
 */

void print_frog(){
    printf("  @..@\n");
    printf(" (----)\n");
    printf("( >__< )\n");
    printf(" \"    \"\n");
}

/*
 * Purpose:
 * Function that prints a Ascii line. Used to separate art
 */

void print_line(){
    printf("/~~~~~~\\\n");
}

/*
 * Purpose:
 * Function used to print the desired order of Ascii art
 */

void print_logo(){
    print_line();
    print_frog();
    print_line();
    print_pig();
    print_line();
    print_frog();
    print_line();
    print_pig();
    print_line();
    print_line();
}

/*
 * Purpose:
 * Function that calculates the surface area of a cylinder
 * given a specified height and diameter.
 * Output of 133.52 square meters is the exact answer to two decimal places.
 * Area of cylinder formula: 2πrh + 2πr^2
 */

void print_surface_area(){

    double height = 6;
    double diameter = 5;

    double circumference =  (2 * M_PI * diameter/2);     //M_PI being pi from math.h library

    double area_of_top = (M_PI * diameter/2 * diameter/2);

    double area_of_wall = (height * circumference);

    double total_area = (2*area_of_top + area_of_wall);

    printf("%.2f square meters\n",total_area);

}
