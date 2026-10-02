/*
 * function: func_021ED510
 * address:  0x021ED510
 * packet:   pkt_ov093_021ED510
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
extern void func_021F87D4(int);
int func_021ED510(u8 *p, int a, int b)
{
    func_021EDA04(p + 0x48 + a * 12);
    func_021EDA04(p + 0x48 + b * 12);
    func_021F87D4(0);
    return 1;
}
