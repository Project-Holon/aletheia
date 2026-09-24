/*
 * function: func_021BE460
 * address:  0x021BE460
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u32 at +0x3e4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BE460(void *p, u32 v)
{
    *(u32 *)((char *)p + 0x3e4) = v;
}
