#include <stdio.h>                         /* pulls in getchar(), printf(), and EOF */

/* count digits, white space, others */    /* program's goal: tally how many of the
                                              input's characters are digits, how many
                                              are whitespace, and how many are anything else */

int main(void)
{

    int c, i, nwhite, nother;   /* c: the current character read from input.
                                   i: loop counter.
                                   nwhite: running count of whitespace chars.
                                   nother: running count of everything else. */
    int ndigit[10];             /* one counter per digit: ndigit[0] counts '0's,
                                   ndigit[1] counts '1's, ... ndigit[9] counts '9's */

    nwhite = nother = 0;        /* start both totals at zero before counting */

    for (i = 0; i < 10; ++i) {  /* walk each of the 10 slots in the array... */
        ndigit[i] = 0;          /* ...and zero it, so we start counting from a clean slate */
    }
    while ((c = getchar()) != EOF) {    /* read one char into c; stop at end-of-input (EOF).
                                           the assignment happens first, then we compare it */
        if (c >= '0' &&
            c <= '9') {                 /* is c a digit? '0'..'9' are consecutive in ASCII,
                                           so one range check covers all ten digits */
            ++ndigit[c - '0'];          /* c - '0' turns the digit character into its index
                                           (e.g. '7' - '0' == 7), then bump that counter */
        } else if (c == ' ' || c == '\n' || c == '\t') {  /* space, newline, or tab? */
            ++nwhite;                   /* count it as whitespace */
        } else {
            ++nother;                   /* anything else (letters, punctuation, ...) */
        }
    }
    printf("digits =");                 /* print the label once, before the list of counts */
    for (i = 0; i < 10; ++i) {          /* walk the array again... */
        printf(" %d", ndigit[i]);       /* ...printing each digit's count, space-separated */
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);  /* finish with the two totals */
}
