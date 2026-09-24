/*
 * function: func_021BC250
 * address:  0x021BC250
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Accumulate +0x50 into +0x4c, zeroing the total when the product is not positive.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BC250(void *p)
{
    s32 a = *(u32 *)((char *)p + 0x4c);
    s32 b = *(u32 *)((char *)p + 0x50);
    s32 t = a + b;
    if (a * t <= 0) {
        t = 0;
    }
    *(u32 *)((char *)p + 0x4c) = t;
}
