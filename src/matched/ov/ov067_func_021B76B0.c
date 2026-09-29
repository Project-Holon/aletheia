/*
 * function: func_021B76B0
 * address:  0x021B76B0
 * packet:   pkt_ov067_021B76B0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf after func_021B7378's pool (inside its handed extent).
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct S {
    u8 pad00[0x98];
    u32 f98;
    int f9c;
} S;

int func_021B76B0(S *p)
{
    if (p->f98 != 0 && p->f98 != 4)
        return 2;
    return p->f9c;
}
