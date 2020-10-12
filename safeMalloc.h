/* file     : safeMalloc.h */
/* author   : Tom Couperus (t.couperus@student.rug.nl) */
/* date     : Fir Oct 9 2020 */
/* version  : 1.0 */

/* Description:
* Just a header file containing Meijster's safe version of malloc, because I don't want to copy it in every time. */

#include <stdlib.h>
#include <stdio.h>

/* Meijster's safe version of malloc */
void *safeMalloc(int n) {
    void *p = malloc(n);
    if (p == NULL) {
        printf("Error: malloc(%d) failed. Out of memory?\n", n); 
        exit(EXIT_FAILURE);
    }
    return p;
}
