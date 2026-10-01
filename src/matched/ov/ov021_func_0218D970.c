/*
 * function: func_0218D970
 * address:  0x0218D970
 * packet:   pkt_ov021_0218D970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

int func_0218D970(u32 a, int b, int c)
{
    int r = -(int)(a >> 1);
    r += c / b;
    return r;
}
