/*
 * function: func_021CEA84
 * address:  0x021CEA84
 * packet:   pkt_ov021_021CEA84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_021CEA84(u8 *p, int n)
{
    p[0x521] &= 0xff ^ (1 << n);
    p[0x522] &= 0xff ^ (1 << n);
}
