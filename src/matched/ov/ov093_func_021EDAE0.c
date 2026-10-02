/*
 * function: func_021EDAE0
 * address:  0x021EDAE0
 * packet:   pkt_ov093_021EDAE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDA3C  0x021EDA3C  thumb  ov093
 *   func_021EDF78  0x021EDF78  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EDA3C(u8 *, u32);
extern int func_021EDF78(u8 *);
void func_021EDAE0(u8 *p, u32 x)
{
    u8 k = func_021EDA3C(*(u8 **)(p + 0x134), x);
    func_021EDF78(p + 0x90 + k * 0x24);
}
