/*
 * function: func_021BC2CC
 * address:  0x021BC2CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store three arguments at +0x3c/+0x40/+0x44 and clear +0x48.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BC2CC(void *p, u32 a, u32 b, u32 c)
{
    *(u32 *)((char *)p + 0x3c) = a;
    *(u32 *)((char *)p + 0x40) = b;
    *(u32 *)((char *)p + 0x44) = c;
    *(u32 *)((char *)p + 0x48) = 0;
}
