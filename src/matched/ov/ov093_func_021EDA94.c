/*
 * function: func_021EDA94
 * address:  0x021EDA94
 * packet:   pkt_ov093_021EDA94
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDA3C  0x021EDA3C  thumb  ov093
 *   func_021EDCA8  0x021EDCA8  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EDA3C(u8 *, u32);
extern int func_021EDCA8(u8 *);
void func_021EDA94(u8 *p, u32 x)
{
    func_021EDCA8(p + 0x90 + func_021EDA3C(*(u8 **)(p + 0x134), x) * 0x24);
}
