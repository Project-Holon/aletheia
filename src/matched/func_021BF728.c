/*
 * function: func_021BF728
 * address:  0x021BF728
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear both +0x30 and +0x3d4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BF728(void *p)
{
    *(u32 *)((char *)p + 0x30) = 0;
    *(u32 *)((char *)p + 0x3d4) = 0;
}
