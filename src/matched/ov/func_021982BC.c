/*
 * function: func_021982BC
 * address:  0x021982BC
 * packet:   pkt_021982BC
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
 *   func_02197FC0  0x02197FC0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_02197FC0(u8 *a, u32 b, u32 c, u16 d, u16 e);

int func_021982BC(u32 a)
{
    func_02197FC0((u8 *)a, 0x0, 0x1000, 0x10, 0x5);
    return 1;
}
