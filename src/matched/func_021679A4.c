/*
 * function: func_021679A4
 * address:  0x021679A4
 * packet:   pkt_021679A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The record's second word is the first argument of the six-argument
 * overlay call, with a zero bail.
 *
 * symbols:
 *   func_02194384   0x02194384  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02194384(int, int, int, int, int, int);

int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5)
{
    int v = *(int *)((char *)a0 + 4);

    if (v == 0)
        return 0;

    return func_02194384(v, a1, a2, a3, a4, a5);
}

