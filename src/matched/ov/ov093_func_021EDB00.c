/*
 * function: func_021EDB00
 * address:  0x021EDB00
 * packet:   pkt_ov093_021EDB00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDA3C  0x021EDA3C  thumb  ov093
 *   func_021EDF7C  0x021EDF7C  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EDA3C(u8 *, u32);
extern void func_021EDF7C(u8 *, u8);
void func_021EDB00(u8 *p, u8 a)
{
    func_021EDF7C(p + 0x90 + func_021EDA3C(*(u8 **)(p + 0x134), a) * 0x24, a);
}
