/*
 * function: func_021B14E8
 * address:  0x021B14E8
 * packet:   pkt_021B14E8
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
 *   func_021B13F8  0x021B13F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021B13F8(u32 v);

int func_021B14E8(u8 *p)
{
    func_021B13F8(*(u32 *)(p + 4));
    return 1;
}
