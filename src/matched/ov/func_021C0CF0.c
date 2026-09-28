/*
 * function: func_021C0CF0
 * address:  0x021C0CF0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C0CF0(void *p)
{
    *(u32 *)((char *)p + 0x2c) = 0;
}
