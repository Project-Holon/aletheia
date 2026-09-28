/*
 * function: func_0219F024
 * address:  0x0219F024
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Maps the +0x10 sign and the +0x60 state word to a small mode code.
 *
 * symbols:
 *

 */

int func_0219F024(char *p)
{
    int v;

    if (*(int *)(p + 0x10) > 0) return 2;
    v = *(int *)(p + 0x60);
    if (v == 3 || v == 0) return 1;
    if (v == 1) return 0;
    return 3;
}


