/*
 * function: func_021ED554
 * address:  0x021ED554
 * packet:   pkt_ov093_021ED554
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EDA04  0x021EDA04  thumb  ov093
 *   func_021F87D4  0x021F87D4  thumb  ov094
 */
typedef unsigned char u8;
extern void func_021EDA04(u8 *);
typedef unsigned int   u32;
extern void func_021F87D4(u32 v);
int func_021ED554(u8 *p, int k)
{
    func_021EDA04(p + 0x48 + k * 12);
    func_021F87D4(0);
    return 1;
}
