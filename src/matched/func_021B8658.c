/*
 * function: func_021B8658
 * address:  0x021B8658
 * packet:   pkt_021B8658
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    *(u16 *)p = 1;
    *(u32 *)(p + 4) = a;
    *(u32 *)(p + 0x14) = d;
    *(u32 *)(p + 0x10) = e;
    *(u32 *)(p + 0x20) = b;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x18) = f;
}
