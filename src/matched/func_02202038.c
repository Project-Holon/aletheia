/*
 * function: func_02202038
 * address:  0x02202038
 * packet:   pkt_02202038
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4E98  0x021F4E98  thumb  ov135
 *   func_0220251C  0x0220251C  thumb  ov135

 * Publish the 0x29/0x22 then the 0x25/0x28 pair and report 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_0220251C(u8 *p, u32 a, u32 b);

int func_02202038(u8 *p)
{
    func_021F4E98(p, 0x29, 0x22);
    func_0220251C(p, 0x25, 0x28);
    return 2;
}
