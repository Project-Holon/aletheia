/*
 * function: func_021C288C
 * address:  0x021C288C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store two u32 arguments at +4 and +8.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C288C(void *p, u32 a, u32 b)
{
    *(u32 *)((char *)p + 4) = a;
    *(u32 *)((char *)p + 8) = b;
}
