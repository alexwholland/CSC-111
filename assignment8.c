/* CSC Assignment 8
 * Alex Holland V00928553
 * 3/17/2020
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN        50
#define CHAR_ARRAY_WIDTH    MAX_WORD_LEN+1
#define MAX_WORDS           1000


void emphasize(char word[]);
int strip_punctuation(char word[]);//y
int find(char word[],char words[][CHAR_ARRAY_WIDTH], int num_words);
void to_lowercase(char dest[], char word[]);
void print_words(char words[][CHAR_ARRAY_WIDTH], int num_words);
int read_words(char words[][CHAR_ARRAY_WIDTH]);
int get_word_frequencies(char words[][CHAR_ARRAY_WIDTH], char unique_words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words);
int get_most_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]);
int get_least_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]);


int main() {
    char word[] ="!Hello";
    char dest[MAX_WORD_LEN];
    char dest1[10][CHAR_ARRAY_WIDTH];
    char dest2[10][CHAR_ARRAY_WIDTH];
    char words[10][CHAR_ARRAY_WIDTH];
    char unique_words[10][CHAR_ARRAY_WIDTH];
    int frequencies[MAX_WORDS];

    puts(word);
    emphasize(word);
    puts(word);

    int n = strip_punctuation(word);
    puts(word);
    printf("%d\n", n);


    to_lowercase(dest, word);
    puts(dest);

    n = read_words(words);
    print_words(words, n);

    int m = get_word_frequencies(words, unique_words, frequencies, n);
    int p = get_most_used(unique_words, frequencies, m, dest1);
    int q = get_least_used(unique_words, frequencies, m, dest2);

//test your functions here

    return 0;
}

/* Purpose: Add a '!' to the end of a string
 * Parameters: char word[]
 * Returns: void
 */
void emphasize(char word[]){

    int n = strlen(word);

    if(n==MAX_WORD_LEN)
        return;
    word[n] = '!';
    word[n+1] = '\0';
}
/* Purpose: Strips all punctuation from the beginning and end of strin
 * Parameters: char word[]
 * Returns: int
 */
int strip_punctuation(char word[]){

    int i, j, z;
    int len = strlen(word);
    char tmp[MAX_WORD_LEN];

    strcpy(tmp, word);

    for(i = 0; ispunct(tmp[i]); i++);

    for(j = len-1; ispunct(tmp[j]); j--);

    for(z = i; z <= j; z++) {
        word[z - i] = tmp[z];
    }
    word[z-i] = '\0';

    return j-i+1;
}

/* Purpose: search and find a given string word
 * Parameters: char word[],char words[][CHAR_ARRAY_WIDTH], int num_words
 * Returns: int
 */
int find(char word[],char words[][CHAR_ARRAY_WIDTH], int num_words){

    for(int i=0; i<num_words; i++){

        if(!strcmp(word, words[i]))
            return i;
    }
    return -1;
}

/* Purpose: Copy and make all values lowercase into an array
 * Parameters: char dest[], char word[]
 * Returns: void
 */
void to_lowercase(char dest[], char word[]){

    int length = strlen(word);

    for(int i=0; i <= length; i++){
        dest[i] = tolower(word[i]);
    }
}

/* Purpose: Print each string on its own line
 * Parameters: char words[][CHAR_ARRAY_WIDTH], int num_words
 * Returns: void
 */
void print_words(char words[][CHAR_ARRAY_WIDTH], int num_words){

    for(int i=0; i<num_words; i++){
        puts(words[i]);                     //write a line to output screen puts(string)
    }
}

/* Purpose: Print each string on its own line
 * Parameters: char words[][CHAR_ARRAY_WIDTH
 * Returns: int
 */
int read_words(char words[][CHAR_ARRAY_WIDTH]){

    int i, count = 0;

    puts("Enter words. '#' to end: ");

    for(i=0;i < MAX_WORDS;i++){
        scanf("%s", words[i]);

        if(strchr(words[i], '#') != NULL) count = 1;
        strip_punctuation(words[i]);

        if(count){
            break;
        }
    }
    return i+1;
}

/* Purpose: Add unique null terminated string as lower case into an array.
 * And count occurrence of the strings
 * Parameters: char words[][CHAR_ARRAY_WIDTH], char unique_words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words
 * Returns: int
 */
int get_word_frequencies(char words[][CHAR_ARRAY_WIDTH], char unique_words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words){

strcpy(unique_words[0], words[0]);

int unique;
int count = 1;

    for(int i = 1; i < num_words; i++){

    if(find(words[i], unique_words, count) == -1){              //find() function locate first occurrence of a string
        strcpy(unique_words[unique], words[i]);
            count++;
        }
    }

     for(int i = 0; i < count; i++){
        frequencies[i] = 0;

        if(find(unique_words[i], words, count) != -1){
            frequencies[i]++;
        }
     }
return count;
}

/* Purpose: Return count of most frequent null terminated strings
 * Parameters: char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]
 * Returns: int
 */
int get_most_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]){

    int max = 0;
    int count = 0;

    for(int i = 0; i < num_words; i++){

        if(frequencies[i] > max)
            max = frequencies[i];
    }
    for(int i = 0; i < num_words; i++){

        if(frequencies[i] == max){
            strcpy(dest[count], words[i]);
            count++;
        }
     }
return count;
}

/* Purpose:  Return count of smallest frequency of null terminated strings
 * Parameters: char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]
 * Returns: int
 *
 */
int get_least_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]){

     int most = MAX_WORDS;
     int count = 0;

    for(int i = 0; i < num_words; i++){

        if(frequencies[i] < most)
            most = frequencies[i];
    }

    for(int i = 0; i < num_words; i++){

        if(frequencies[i] == most){
            strcpy(dest[count], words[i]);
            count++;
         }
     }
return count;
}