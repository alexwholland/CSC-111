/* CSC assignment 10
 * Alex Holland - V00928553
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define THRESHOLD   0.001

// some of these constants will go unused
// we listed them all for completion sake
#define GP      0
#define MPG     1
#define PPG     2
#define RPG     3
#define APG     4
#define SPG     5
#define BPG     6
#define TOPG    7

#define MAX_WORD_LEN        63
#define CHAR_ARRAY_WIDTH    MAX_WORD_LEN+1
#define MAX_PLAYERS         28
#define MAX_TEAMS           30
#define NUM_STATS           8

typedef struct {
    char name[CHAR_ARRAY_WIDTH];
    char pos[CHAR_ARRAY_WIDTH];
    double stats[NUM_STATS];
} Player;

typedef struct {
    int num_players;
    char name[CHAR_ARRAY_WIDTH];
    Player* players[MAX_PLAYERS];
} Team;

int find_team(char name[], Team* teams[], int num_teams);
int read_file(char filename[], Team* teams[]);
int get_high_scorers(Team* teams[], int num_teams, Player* high_scorers[]);
void to_file(char filename[], Team* teams[], int num_teams);
int approximately_equal(double num1, double num2);
int compare(char name1[], char name2[]);

int main() {
char s1[] = "bob";

Team* team[MAX_TEAMS];
int num_teams = read_file("input.txt", team);
printf("%d\n", num_teams);
for (int j = 0; j < num_teams; j++){
    free(team[j]->players);
    free(team[j]);
}
Player* high_scorers[MAX_TEAMS];
    return 0;
}



/*
 * Purpose: determines if num1 and num2 are close enough to be considered equal
 *  NOTE: cannot compare equality of floating point values using ==
 * Params: double num1, double num2
 * Return: int - 1 if num1 and num2 are approximately equal, 0 otherwise
 */
int approximately_equal(double num1, double num2) {
    double diff = num1-num2;

    if (diff<0) {
        diff *= -1;
    }

    if (diff<THRESHOLD) {
        return 1;
    } else {
        return 0;
    }
}
/* Purpose: find name that teams array matches given name
 * Parameters: char name[], Team* teams[], int num_teams
 * Returns: int i or int -1
 */
int find_team(char name[], Team* teams[], int num_teams){
    for (int i = 0; i < num_teams; i++){
        if (strcmp(teams[i]->name,name)==0){
            return i;
        }
    }
    return -1;
}

/* Purpose: cream Team and Player instances and add pointers to them
 * Parameters: char filename[], Team* teams[]
 * Returns: int number of entries added to teams
 */

int read_file(char filename[], Team* teams[]){
int index = 0;
int a = 0;
char name[CHAR_ARRAY_WIDTH];
char team[CHAR_ARRAY_WIDTH];
char pos[CHAR_ARRAY_WIDTH];
    FILE *input_file;
    input_file = fopen(filename, "r");

    if (input_file == NULL){
        printf ("File was not found");
        return -1;
    }
   while(!feof(input_file)){
       fscanf(input_file,"%s",pos);
       //printf ("%d ",pos);
   }
 for (int i = 0; i < MAX_TEAMS; i++){
     Team* team = malloc(sizeof(Team));
     teams[i] = team;
 }

    fclose(input_file);
}

/* Purpose: Determine the highest scorer on a team
 * Parameters: Team* teams[], int num_teams, Player* high_scorers[]
 * Returns: int, number of Player pointers added to high_scorers
 */

int get_high_scorers(Team* teams[], int num_teams, Player* high_scorers[]){
approximately_equal(1,1);
    for (int i = 0; i < num_teams; i++){

}
}

/* Purpose: write information to the given filename
 * Parameters: char filename[], Team* teams[], int num_teams
 * Returns: void
*/

void to_file(char filename[], Team* teams[], int num_teams){
FILE* output = fopen(filename, "w");

if (output == NULL){
    printf ("File was not found \n");
    exit(0);
}
for (int i = 0; i < num_teams; i++){
    fwrite(teams[i], sizeof (Team),1,output);
}
fclose(output);
}


/*
int compare(char name1[], char name2[]){
    for (int i = 0; name1[i] != '\0'; i++){
        if (name2[i]=='\0'){
            return 1;
        } if (name1[i] != name2[i]){
            return 1;
        }
    }
    return 0;
}
*/
