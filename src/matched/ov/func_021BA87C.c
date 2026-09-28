/*
 * function: func_021BA87C
 * address:  0x021BA87C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Word setter at +0x10.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void func_021BA87C(u8 *p, int v)
{
    *(u32 *)(p + 0x10) = v;
}
