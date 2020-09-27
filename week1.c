#include <stdio.h>
#include <cs50.h>

int main(void) {
        int a = get_int("How many blocks?\n");
        mario:
        if (a > 0 && a < 9) {

            for (int b = 0; b < a;) {
                for (int i = 0; a-b > i; i++) {
                    printf(" ");
                }

                for (int i = -1; b > i; i++) {
                    printf("#");
                }

                printf("  ");

                for (int i = -1; b > i; i++) {
                    printf("#");
                }

                for (int i = 0; a-b > i; i++) {
                    printf(" ");
                }
                printf("\n");
                b++;
            }
        }
        else {
            printf("Try again(1-8)\n");
            a = get_int("How many blocks?\n");
            goto mario;
        }
}
