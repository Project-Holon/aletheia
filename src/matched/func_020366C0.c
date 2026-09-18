/*
 * function: func_020366C0
 * address:  0x020366C0
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Counts the 20-byte records of the array at p+0x18 whose halfword at +0x0E is
 * non-zero, up to the count in p+0x1C.  60 bytes, no calls, no pool: the loop
 * is rotated and the test is a predicated `addne`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366C0.c \
 *       --func func_020366C0 --addr 0x020366C0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

int func_020366C0(char *p)
{
    int         n = *(int *)(p + 0x1C);
    const char *e = *(char **)(p + 0x18);
    int         c = 0;
    int         i;

    for (i = 0; i < n; i++, e += 0x14) {
        if (*(u16 *)(e + 0x0E) != 0)
            c++;
    }
    return c;
}
