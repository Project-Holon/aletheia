/*
 * function: func_021BF764
 * address:  0x021BF764
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BF764(void *p, u32 v)
{
    *(u32 *)((char *)p + 0x2cc) = v;
}
