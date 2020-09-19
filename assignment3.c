/* CSC Assignment 3
 * Name: Alex Holland - V00928553
 */
#include <stdio.h>

int is_multiple_of(int n1, int n2);
int get_quadrant(int x, int y);
void print_zodiac_sign(int month, int day);
int get_seconds(int days, int hours, int minutes);
void print_time_conversion(int seconds);
double get_distance_traveled(int days, int hours, double speed);


int main() {

    //TEST YOUR FUNCTIONS HERE
    int multiple = is_multiple_of(-1, 6);
    printf("%d\n", multiple);

    int quad = get_quadrant(3,-3);
    printf("%d\n",quad);

    print_zodiac_sign(12,22);

    int seconds = get_seconds(1,1,1);
    printf("%d\n", seconds);

    print_time_conversion(90070);

    double distance = get_distance_traveled(2,3,7.2);
    printf("%.2f\n",distance);

    return 0;

}


// DEFINE YOUR FUNCTIONS AFTER THIS LINE

/* Purpose: Calculates if a number (n2)
 * is a multiple of another (n1)
 * Parameters: int n1 - int n2
 * Returns: int - 1 if a multiple, 0 if not a multiple
 */
int is_multiple_of(int n1, int n2){

    if (n2 % n1 == 0){
        return 1;
    }else return 0;
}
/*Purpose: Determines which quadrant a point is in.
 * Parameters: int x - x coordinate, int y - y coordinate.
 * Returns: int - quadrant 1, or 2, or 3, or 4
 */
int get_quadrant(int x, int y){

    int quadrant;

    if (x > 0 && y > 0){
        quadrant = 1;
    }else if (x > 0 && y < 0){
        quadrant = 4;
    }else if (x < 0 && y > 0){
        quadrant = 2;
    }else quadrant = 3;

    if (x == 0 || y == 0){
        quadrant = -1;
    }
    return quadrant;
}

/* Purpose: Take two numbers; day and month and determines
 * the zodiac name.
 * Parameters: int month - int day
 *
 */

void print_zodiac_sign(int month, int day) {

    if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) {
        printf("Aquarius\n");
    } else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) {
        printf("Pisces\n");
    } else if ((month == 3 && day >= 21) || (month == 4 && day <= 19)){
        printf("Aries\n");
    }else if ((month == 4 && day >= 20) || (month == 5 && day <= 20)) {
        printf("Taurus\n");
    }  else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) {
        printf("Gemini\n");
    }else if ((month == 6 && day >= 21) || (month == 7 && day <= 22)) {
        printf("Cancer\n");
    }else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
        printf("Virgo\n");
    }else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
        printf("Libra\n");
    }else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
        printf("Scorpio\n");
    }else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
        printf("Sagittarius\n");
    }else printf ("Capricorn\n");
}

/* Purpose: Take 3 numbers; days, hours, minutes and calculate the
 *          total seconds.
 * Parameters: int days - int hours - int minutes
 * Returns: int - seconds calculated from days, hours, minutes
 */

int get_seconds(int days, int hours, int minutes){
    int minutes_s = 60;
    int hour_s = 3600;
    int day_s = 86400;
    int seconds;
    seconds = ((days*day_s)+(hours*hour_s)+(minutes*minutes_s));
    return seconds;
}

/* Purpose: Calculates the days, hours, and minutes from seconds
 * Parameters: int seconds
 */

void print_time_conversion(int seconds){

    int days, hours, minutes;

    int minutes_s = 60;
    int hours_s = 3600;
    int days_s = 86400;

    days = seconds / days_s;
    seconds -= days * days_s;
    hours = seconds / hours_s;
    seconds -= hours * hours_s;
    minutes = seconds / minutes_s;
    seconds -= minutes * minutes_s;
    printf ("%d days, %d hours, %d minutes, %d seconds\n",days, hours, minutes, seconds);
}

/* Purpose: Calculate the distance traveled from total time
 * Parameters: int days - int hours - int speed
 * Returns: double - distance
 */

double get_distance_traveled(int days, int hours, double speed){
    double time = get_seconds(days, hours, 0);
    double distance = (time * speed)/1000;
    return distance;
}
