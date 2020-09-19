/* CSC Assignment 9
 * Alex Holland - V00928553
 * 3/27/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROWS      10000  // maximum number of rows that the input file can have
#define NUMRIDINGS   338    // number of ridings

#define NUMCOLS      3      // number of columns in data
#define ID           0      // index of voter ID in data
#define RIDING       1      // index of riding number in data
#define VOTE         2      // index of vote in data

#define NUMPARTIES   4      // number of parties to vote for
#define NOPARTY     -1      // number to represents a party that doesn't exist
#define NDP          0      // number to represent NDP party
#define CONSERVATIVE 1      // number to represent Conservative party
#define LIBERAL      2      // number to represent Liberal party
#define GREEN        3      // number to represent Green party


int to_array( char filename[], int data[][NUMCOLS] );
void compute_riding_results(int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes);
int index_of_max(int array[], int length);
int calculate_winner(int counts_per_riding[][NUMPARTIES], int winners[]);
int calculate_popular_vote(int counts_per_riding[][NUMPARTIES]);
void to_party_name(char dest[], int party_num);
void to_file(char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]);


int main(void) {
    // test your methods here.
    // You have been provided with 4 sample input files and the corresponding output file
  /*  int data[MAXROWS][NUMCOLS] = {0};
    printf("Reading file in \n");
    int num_rows = to_array("data.txt", data);
    printf ("%d\n",num_rows);
    for (int i = 0; i < num_rows; i++){
        printf("%d %d %d\n", data[i][0], data[i][1], data[i][2]);
    }

    printf ("\n");

    int a1[6] = {3,4,1,6,1,6};
    int max = index_of_max(a1,6);
    printf("Max index: %d\n",max);

    printf("\n");

   char a2[12];
    to_party_name(a2,-1);
    printf("%s",a2);

    int array[3][3] = {{44564,17,1},
                    {37897,308,3},
                    {41230,104,0}}; */
 /*
    int data[MAXROWS][NUMCOLS];

    char filename[] = "data.txt";

    int dataC;

    int riding_array[NUMRIDINGS][NUMPARTIES];

    int winners[NUMRIDINGS];
    
    int winner, popular;
    char winnerName[100], popularName[100];
    char output[] = "output.txt";

 dataC = to_array(filename, data);

    compute_riding_results(data, riding_array, dataC);

    winner = calculate_winner(riding_array, winners);

    popular = calculate_popular_vote(riding_array);
    to_party_name(winnerName, winner);
    to_party_name(popularName, popular);

    to_file(output, riding_array, winners, winnerName, popularName); */

    return 0;
}

/* Purpose: store input data into a 2d array
 * Parameters: char filename[], int data[][NUMCOLS]
 * Returns: int count
 */

int to_array( char filename[], int data[][NUMCOLS] ){

    int id;
    int riding;
    int vote;
    int count = 0;

    FILE *my_file;
    my_file = fopen(filename, "r");

    if (my_file == NULL) {
        printf("File was not found");
        return -1;
    }
    while (fscanf(my_file, "%d %d %d", &id, &riding, &vote) == NUMCOLS){
        data[count][ID] = id;
        data[count][RIDING] = riding;
        data[count][VOTE] = vote;
        count++;
    }
    return count;
}

/* Purpose: collect data from a 2d array and store the riding results
 * into another 2d array
 * Parameters: int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes
 * Returns: void
 */

void compute_riding_results(int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes){

    for (int i = 0; i < NUMRIDINGS; i++) {
        for (int j = 0; j < NUMPARTIES; j++) {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < num_votes; i++) {
        result[data[i][1]][data[i][2]] += 1;
    }
}

/* Purpose: determine the index with the highest value
 * Parameters: int array[], int length
 * Returns: int index
 */

int index_of_max(int array[], int length){

 int index = 0;
 int max = array[index];

 for (int i = 1; i < length; i++) {
     if (array[i] == max) {
         return -1;
     }
     if (array[i] > max) {
         max = array[i];
         index = i;
     }
 }
 return index;
}

/* Purpose: determine and store the winner of each riding in a outut arrary,
 * and count the number of ridings each party won.
 * Parameters: int counts_per_riding[][NUMPARTIES], int winners[]
 * Returns: int index_of_max(winners,NUMRIDINGS) <-- returns int index
 */

int calculate_winner(int counts_per_riding[][NUMPARTIES], int winners[]){

    for (int i = 0; i < NUMRIDINGS; i++){
        winners[i] = index_of_max(counts_per_riding[i],NUMPARTIES);
    }
    return index_of_max(winners,NUMRIDINGS);
}

/* Purpose: Compute the sum of votes of each party across all ridings
 * and determine winner with most votes
 * Parameters: int counts_per_riding[][NUMPARTIES]
 * Returns: int index_of_max(result, NUMPARTIES) <-- returns int index
 */

int calculate_popular_vote(int counts_per_riding[][NUMPARTIES]){

    int res[NUMPARTIES];
    int count = 0;

    for (int j = 0; j < NUMPARTIES; j++) {
        count = 0;

        for (int i = 0; i < NUMRIDINGS; i++) {
            count += counts_per_riding[i][j];
        }
        res[j] = count;
    }
    return index_of_max(res, NUMPARTIES);
}

/* Purpose: Copy strings into a destination array
 * Parameters: char dest[], int party_num
 * Returns: void
 */

void to_party_name(char dest[], int party_num){

    if (party_num == NOPARTY){
        strcpy(dest,"NOT NAMED");
    } else if(party_num == NDP){
        strcpy(dest,"NDP");
    }else if(party_num == CONSERVATIVE){
        strcpy(dest,"CONSERVATIVE");
    }else if(party_num == LIBERAL){
        strcpy(dest,"LIBERAL");
    } else if (party_num == GREEN){
        strcpy(dest,"GREEN");
    }
}

/* Purpose: Write the election results to given filename.
 * Parameters: char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]
 * Returns: void
 */

void to_file(char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]){

    FILE* my_file = fopen(filename, "w");
    char hold[1000];

    if (my_file == NULL) {
        printf("File was not found \n");
                exit(0);                    //terminates program execution
     }
    fprintf(my_file, "Winner of the election: %s\n", election_winner);
    fprintf(my_file, "Winner of the popular vote: %s\n", popular_winner);
    fprintf(my_file, "%s %s %s %s %s %s\n",
            "RIDING #","NDP","CONSERVATIVE","LIBERAL","GREEN","WINNING PARTY");

    for (int i = 0; i < NUMRIDINGS; i++) {
        fprintf(my_file, "%d ", i);

        for (int j = 0; j < NUMPARTIES; j++) {
            fprintf(my_file, "%d ", riding_vote_counts[i][j]);
        }
        to_party_name(hold, riding_winners[i]);
        fprintf(my_file,"%s \n", hold);
    }
    fclose(my_file);
}
