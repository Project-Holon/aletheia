/*
 * function: func_021B10F4
 * address:  0x021B10F4
 * packet:   pkt_021B10F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_021B10A4  0x021B10A4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021B10A4(u32 v);

int func_021B10F4(u8 *p)
{
    func_021B10A4(*(u32 *)(p + 4));
    return 1;
}
