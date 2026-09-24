/*
 * function: func_021C253C
 * address:  0x021C253C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialise the header: two mode bytes, two u16 fields, three cleared words.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C253C(void *p, u8 a, u8 b, u16 c, u32 d)
{
    *(u8 *)((char *)p + 0xe) = a;
    *(u32 *)p = 0;
    *(u32 *)((char *)p + 8) = 0;
    *(u16 *)((char *)p + 0xc) = 0;
    *(u8 *)((char *)p + 0xf) = b;
    *(u16 *)((char *)p + 4) = c;
    *(u32 *)((char *)p + 0x10) = d;
}
