#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int grade(int wor[], int c, int num[], int d);

int main(void) {

    // get the text

    string s = get_string("Readability Text: ");

    // p is periods, b is spaces, curw is the current words, curl is the current letters, c and d are counting where the arrays are at
    int p = 0;
    int b = 0;
    int curw = 0;
    int curl = 0;
    int c = 0;
    int d = 0;

    int e = strlen(s);

    // gives the appropriate number of array spaces to the arrays

    for (int i = 0; i < e;) {
        if (s[i] == 46) {
            p++;
        }
        i++;
    }

    int wor[p];

    for (int i = 0; i < e;) {
        if (isspace(s[i])) {
            b++;
        }
        i++;
    }

    int num[b];


    //scrapes the string and logs the char
    for (int i = 0; i < e - 1;) {

        //if it is a space, log the letter, add a word, next array, letters start over
        if (isspace(s[i])) {
            num[d] = curl;
            curw++;
            d++;
            curl = 0;
        }

        // if it is a period(46), log the words, next array, letters and words start over
        else if (s[i] == 46) {
            wor[c] = curw;
            c++;
            curw = 0;
            curl = 0;
        }

        //anything else add a letter
        else {
            curl++;
        }

        i++;
    }

    //theres a bug that happens if the last char is a ".", this fixes it

        if (isspace(s[e - 1])) {
            num[d] = curl;
            curw++;
            d++;
            curl = 0;
        }

        // if it is a period(46), log the words, next array, letters and words start over
        else if (s[e - 1] == 46) {
            wor[c] =0;
        }

        //anything else add a letter
        else {
            curl++;
        }

    printf("Grade level: %i\n", grade(wor, c, num, d));

}



// average out the words
int grade(int wor[], int c, int num[], int d){

    int sum = 0;
    for (int i = 0; i <= c; i++) {

        sum += wor[i];
    }


    float avgw =  (float) sum / (float) c;

    int sum1 = 0;
    for (int i = 0; i <= d; i++) {

        sum1 += num[i];
    }

    float avgl = (float) sum / (float) d;

    return (avgl + avgw)/2;

}

