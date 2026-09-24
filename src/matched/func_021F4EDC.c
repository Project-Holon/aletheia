/*
 * function: func_021F4EDC
 * address:  0x021F4EDC
 * packet:   pkt_021F4EDC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4894  0x021F4894  thumb  ov135
 *   func_021F49F8  0x021F49F8  thumb  ov135
 *   func_021F4BCC  0x021F4BCC  thumb  ov135
 *   g_02202BFC  0x02202BFC  data  ov135

 * Wire the shared table into the two initialisers and release the channel.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_021F4894(u32 v);
extern void func_021F49F8(u8 *p, u32 v);
extern void func_021F4BCC(u8 *p);
extern u8 g_02202BFC[];

void func_021F4EDC(u8 *p)
{
    func_021F4894((u32)g_02202BFC);
    func_021F49F8(p, (u32)g_02202BFC);
    func_021F4BCC(p);
}
