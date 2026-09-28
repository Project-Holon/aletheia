/*
 * function: func_021B8434
 * address:  0x021B8434
 * packet:   pkt_ov067_021B8434
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021B8434(u8 *p, u8 a, u8 b, u16 c, u32 d)
{
    p[0x67] = a;
    p[0x68] = b;
    p[0x69] = 0;
    *(u16 *)(p + 0x50) = c;
    *(u16 *)(p + 0x4e) = 1;
    *(u32 *)(p + 0x6c) = d;
}
