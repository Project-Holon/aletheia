/*
 * function: func_021CFCF4
 * address:  0x021CFCF4
 * packet:   pkt_ov021_021CFCF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u8 func_021CFCF4(u8 *p, u32 i)
{
    u8 r = 0xff;

    if (i < 5 && i < p[1]) {
        r = p[8 + i];
    }
    return r;
}
