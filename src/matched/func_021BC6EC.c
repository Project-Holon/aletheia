/*
 * function: func_021BC6EC
 * address:  0x021BC6EC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u8 at +0x31.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BC6EC(void *p, u8 v)
{
    *(u8 *)((char *)p + 0x31) = v;
}
