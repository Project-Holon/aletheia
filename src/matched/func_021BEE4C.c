/*
 * function: func_021BEE4C
 * address:  0x021BEE4C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEC00  0x021BEC00  arm  ov114
 *
 *
 * Stores the +0x24/+0x28 pair on node `a`; -1 when the node is absent.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEC00(int, int);

int func_021BEE4C(int a, int b, int c, int d)
{
    u8 *p = func_021BEC00(a, b);
    if (p == 0)
        return -1;
    *(u32 *)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = d;
    return 0;
}
