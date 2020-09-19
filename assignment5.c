/*CSC Assignment 5: Pointers and Condition driven loops
 * Alex Holland - V00928553
 * 2/19/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROLL 1
#define MAX_ROLL 6
#define MIN_BET 5

int get_bet(int bankroll);
int play_again();
int compute_winnings(int num_matches, int bet);
int get_guess();
void roll_dice(int* die1, int* die2, int* die3);
int count_matches(int guess, int die1, int die2, int die3);
int play_round(int bet);
void play_game(int* bankroll);

int main(void) {
    // we have called srand with a constant value 0 for testing purposes
    // with this call, you will always get the same sequence of numbers generated
    // this allows you to anticipate what the dice rolls will be and let you test play_game more easily
    srand(0);

    // instead of using call srand(0) as shown above:
    // use this call srand(time(0)) to mimic a new set of random numbers every time you play the game
    // this is a much more real game that you can get your friends to play
//    srand(time(0));


    // a test for get_bet
/*
    int bet = 0;

    printf("testing get_bet with $300 bankroll\n\n");
    bet = get_bet(300);
    printf("finished testing get_bet, returned result: %d\n", bet);
    printf("(returned result will be dependant on user input, cannot be >300)\n\n");

*/
    // some tests for compute_winnings
/*
    int winnings_result = 0;

    printf("testing compute_winnings with 0 matches and $50\n\n");
    winnings_result = compute_winnings(0, 50);
    printf("finished testing compute_winnings, returned result: %d (should be -50)\n\n", winnings_result);

    printf("testing compute_winnings with 1 match and $150\n\n");
    winnings_result = compute_winnings(1, 150);
    printf("finished testing compute_winnings, returned result: %d (should be 150)\n\n", winnings_result);

    printf("testing compute_winnings with 2 matches and $30\n\n");
    winnings_result = compute_winnings(2, 30);
    printf("finished testing compute_winnings, returned result: %d (should be 60)\n\n", winnings_result);

    printf("testing compute_winnings with 3 matches and $25\n\n");
    winnings_result = compute_winnings(3, 25);
    printf("finished testing compute_winnings, returned result: %d (should be 250)\n\n", winnings_result);

*/

    // some tests for count_matches
/*
    int match_count = 0;

    printf("testing count_matches with none matching\n\n");
    match_count = count_matches(4, 3, 5, 1);
    printf("finished testing count_matches, returned value: %d (should be 0)\n\n", match_count);

    printf("testing count_matches with 1 matching\n\n");
    match_count = count_matches(2, 2, 5, 3);
    printf("finished testing count_matches, returned value: %d (should be 1)\n\n", match_count);

    printf("testing count_matches with 2 matching\n\n");
    match_count = count_matches(3, 3, 5, 3);
    printf("finished testing count_matches, returned value: %d (should be 2)\n\n", match_count);

    printf("testing count_matches with 3 matching\n\n");
    match_count = count_matches(5, 5, 5, 5);
    printf("finished testing count_matches, returned value: %d (should be 3)\n\n", match_count);

*/


    // a test for play_round
/*
    printf("testing play_round with $30 bet\n\n");
    int round_result = play_round(30);
    printf("finished testing play_round with $30 bet, returned value was: %d\n", round_result);
*/

    // play_again();
    // get_guess();
  /*  int x, y, z;
    roll_dice(&x, &y, &z); */
 int p = 500;
 play_game(&p);
    return 0;
}


// Write your function definitions here:

/*
 * Purpose: take amount of money user has and prompt for a valid bet
 * Parameters: int - bankroll
 * Returns: int - bet
 */

int get_bet(int bankroll){
    int bet;
    printf("Place your bet please\n");
    printf("Enter a whole number between 5 and %d inclusive\n", bankroll);
    scanf("%d", &bet);
    while (bet < MIN_BET || bet > bankroll ){
        printf("That was not a whole number between 5 and %d inclusive\n", bankroll);
        scanf("%d", &bet);

    }
    if (bankroll < MIN_BET) {
        printf("You have $%d to play with\n", bankroll);
        return bet;
    }
    printf("You have bet $%d\n\n", bet);
    return bet;
}

/*Purpose: Prompt the user to determine if they want to play again or not
 * Parameters: No argument
 * Returns: 0 - if they dont want to play, 1 - if they do want to play
 */

int play_again(){
    int input;
    printf ("Do you want to make a bet? (1 for yes, 0 for no)\n");
    printf ("Enter a whole number between 0 and 1 inclusive\n");
    scanf("%d", &input);
    while (input != 0 && input != 1){
        printf ("That was not a whole number between 0 and 1 inclusive, try again\n");
        scanf("%d", &input);
    }
    if (input == 0){
        //printf ("Thanks for playing! Come back soon!\n");
        return 0;
    }else return 1;
}

/*Purpose: Calculate the amount the user has won or lost
 *Parameters: int - num_matches, int - bet
 *Returns: int - won;
 */

int compute_winnings(int num_matches, int bet){
    int won = 0;
    if (num_matches == 0){
        won = won - bet;
        //   printf ("Sorry you lost $%d\n", -won);
    }else if (num_matches == 1){
        won = bet;
        // printf ("Congrats! You won $%d\n", won);
    }else if (num_matches == 2){
        won = bet * 2;
        //  printf ("Congrats! You won $%d\n", won);
    }else if (num_matches == 3) {
        won = bet * 10;
        // printf("Congrats! You won $%d\n", won);
    }
    return won;
}

/*Purpose: Prompt the user for a valid dice roll between 1 and 6 inclusive
 * parameters: No argument
 * Returns: int - guess
 */

int get_guess(){
    int guess;
    printf ("Guess your number!\n");
    printf ("Enter a number between 1 and 6 inclusive\n");
    scanf("%d", &guess);
    while (guess < MIN_ROLL || guess > MAX_ROLL){
        printf ("That was not a whole number between 1 and 6, try again\n");
        scanf("%d", &guess);
    }
    printf ("You guessed: %d\n", guess);
    return guess;
}

/*Purpose: Generate 3 random numbers from 1 to 6 inclusive using ran() function
 *Parameters: int* - die1, int* - die2, int* - die3
 */
void roll_dice(int* die1, int* die2, int* die3){

    *die1 = rand() % 6 + 1;
    *die2 = rand() % 6 + 1;
    *die3 = rand() % 6 + 1;
    printf ("You rolled: %d, %d, %d\n\n", *die1, *die2, *die3);
}

/*Purpose: Count the number of dice roll values that match users guess
 * Parameters: int - guess, int - die1, int - die2, int - die3
 * Returns: int - count
 */

int count_matches(int guess, int die1, int die2, int die3){
    int count = 0;
    if (guess == die1){
        count++;
    }
    if (guess == die2){
        count++;
    }
    if (guess == die3){
        count++;
    }
    printf ("Your guess (%d) matched %d of the dice\n", guess, count);
    return count;
}

/*Purpose: takes the user's bet and plays one round using the get_guess, roll_dice,
 * roll_dice, count_matches, and compute_winnings function
 * Parameters: int - bet
 * Returns: int - won;
 */

int play_round(int bet) {
    int die1,die2,die3;
    int guess = get_guess();
    roll_dice(&die1,&die2,&die3);
    int count = count_matches(guess,die1,die2,die3);
    int won = compute_winnings(count, bet);
    return won;
}

/*Purpose: Allow the user to play infinite rounds of the game as long as
 * they still have enough money in their bankroll
 * Parameters: int* - bankroll
 */

void play_game(int* bankroll){
    int die1, die2, die3;
    int bet;
    int guess;
    int match;
    int won;
    printf ("You have $%d to play with\n", *bankroll);
    while (*bankroll > MIN_BET) {
        if (play_again() == 0){
            break;
        }
        bet = get_bet(*bankroll);
        guess = get_guess();
        roll_dice(&die1, &die2, &die3);
        match = count_matches(guess, die1, die2, die3);
        won = compute_winnings(match, bet);
        if (match == 1 || match == 2 || match == 3){
            printf ("Congrats! You won $%d\n", won);
        }else{
            printf ("Sorry you lost $%d\n",-won);}
        *bankroll = *bankroll + won;
        printf("You have $%d in your bankroll\n\n", *bankroll);
    }

    printf ("Thanks for playing! Come back soon!\n");
    printf ("You have $%d left in your bankroll\n", *bankroll);
}