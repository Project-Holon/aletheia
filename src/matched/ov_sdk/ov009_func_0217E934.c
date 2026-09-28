/*
 * function: func_0217E934
 * address:  0x0217E934
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reverses the n*4-byte payload that follows the count word, in place.
 *
 * symbols:
 *

 */

int func_0217E934(char *p)
{
    int n = *(int *)p;
    char *a = p + 4;
    char *b = a + n * 4 - 1;

    if (n == 0) return 1;
    while (a < b) {
        char t = *a;

        *a++ = *b;
        *b-- = t;
    }
    return 1;
}


