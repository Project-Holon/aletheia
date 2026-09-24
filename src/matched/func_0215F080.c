/*
 * function: func_0215F080
 * address:  0x0215F080
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reads the object at +0xa0 of the block: in mode 1 returns the halfword at
 * +4 of its +0x104 child, in modes 0 and 4 the +0x50 minus +0xf8 difference,
 * and 0 in every other case.
 *
 * symbols:
 *

 */

int func_0215F080(char *p)
{
    char *q = *(char **)(p + 0xa0);
    int r = 0;

    if (q != 0) {
        int t = *(signed char *)(p + 0xaf);

        if (t == 1) {
            char *u = *(char **)(q + 0x104);

            if (u != 0) r = *(unsigned short *)(u + 4);
        } else if (t == 0 || t == 4) {
            r = *(int *)(p + 0x50) - *(int *)(q + 0xf8);
        }
    }
    return r;
}


