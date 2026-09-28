/*
 * function: func_021BEF60
 * address:  0x021BEF60
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Null-guarded word setter at +0x2c.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void func_021BEF60(u8 *p, int v)
{
    if (p != 0)
        *(u32 *)(p + 0x2c) = v;
}
