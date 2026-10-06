/*
 * function: func_0218F0B8
 * address:  0x0218F0B8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Walks the list hanging off the +0x5d8 member of the object and returns the
 * node whose +0x10 word equals v, or 0 when the list runs out.
 *
 * symbols:
 *

 */

char *func_0218F0B8(void **p, int v)
{
    char *q = *(char **)(*(char **)p + 0x5d8);

    while (q != 0) {
        if (*(int *)(q + 0x10) == v) return q;
        q = *(char **)(q + 0x4c);
    }
    return 0;
}


