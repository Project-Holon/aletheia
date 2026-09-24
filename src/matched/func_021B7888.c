/*
 * function: func_021B7888
 * address:  0x021B7888
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store the four u16 arguments at +0xc..+0x12 and the word 1 at +0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d)
{
    *(u32 *)p = 1;
    *(u16 *)((char *)p + 0xc) = a;
    *(u16 *)((char *)p + 0xe) = b;
    *(u16 *)((char *)p + 0x10) = c;
    *(u16 *)((char *)p + 0x12) = d;
}
