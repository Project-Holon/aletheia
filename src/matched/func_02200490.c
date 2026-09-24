/*
 * function: func_02200490
 * address:  0x02200490
 * packet:   pkt_02200490
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F4E98  0x021F4E98  thumb  ov135

 *
 * Store the 0xa/2 pair and report 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F4E98(u8 *p, u32 a, u32 b);

int func_02200490(u8 *p)
{
    func_021F4E98(p, 0xa, 2);
    return 2;
}
