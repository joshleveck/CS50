#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    //check if they put in 26 char
    if (strlen(argv[1]) == 26) {
        for (int i = 0; i < strlen(argv[1]); i++) {
            if (isalpha(argv[1][i])) {

            }
            else {
                printf("Please include 26 characters after ./cipher");
                return 1;
            }
        }

        //get the text they want
        string s = get_string ("Normal:");
        printf("Ciper:");

        for (int i = 0; i < strlen(s);){

            //to keep the letter the same case check what case they are in, if not a letter print it
            if (islower(s[i])) {
                int l = s[i] - 97;
                printf("%c", tolower(argv[1][l]));
            }
            else if (isupper(s[i])) {
                int l = tolower(s[i]) - 97;
                printf("%c", toupper(argv[1][l]));
            }

            else {
                printf("%c", s[i]);
            }
            i++;
        }
        printf("\n");
    }
}
