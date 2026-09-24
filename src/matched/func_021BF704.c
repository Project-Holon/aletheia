/*
 * function: func_021BF704
 * address:  0x021BF704
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the u32 at +0x3d8.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BF704(void *p)
{
    *(u32 *)((char *)p + 0x3d8) = 0;
}
