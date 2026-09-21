/*
 * function: func_0200D2D8
 * address:  0x0200D2D8
 * packet:   pkt_0200D2D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0200C780 - not matched (parked at src/pending/func_0200C780.c, itself capped on its own data table), and this call at 0x0200D2F4 is the only branch to it in the image.  All 56 bytes right.
 */

typedef unsigned short u16;

extern int func_0200CED4(void *p, u16 i);
extern int func_0200C780(u16 v);

u16 func_0200D2D8(void *a0)
{
    int i;
    u16 n = 0;

    for (i = 1; i <= 0x289; i++) {
        if (func_0200CED4(a0, i) == 1 && func_0200C780(i) == 1)
            n++;
    }
    return n;
}
