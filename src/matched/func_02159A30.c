/*
 * function: func_02159A30
 * address:  0x02159A30
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Shifts the 0xc-byte records above index i one slot up (each record's
 * +0x70 triple moving to +0x7c) and clears the +0x70 triple of slot i.
 *
 * symbols:
 *

 */

struct S { int a, b, c; };

void func_02159A30(char *p, int i)
{
    int j;

    for (j = 2; j >= i; j--) {
        char *e = p + j * 0xc;

        *(struct S *)(e + 0x7c) = *(struct S *)(e + 0x70);
    }
    *(int *)(p + i * 0xc + 0x70) = 0;
}


