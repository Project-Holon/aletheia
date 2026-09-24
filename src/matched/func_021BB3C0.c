/*
 * function: func_021BB3C0
 * address:  0x021BB3C0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Clears the leading word.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void func_021BB3C0(u8 *p)
{
    *(u32 *)(p + 0) = 0;
}
