/*
 * function: func_021ED4E4
 * address:  0x021ED4E4
 * packet:   pkt_ov093_021ED4E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ED9EC  0x021ED9EC  thumb  ov093
 *   func_021F87D4  0x021F87D4  thumb  ov094
 */
typedef unsigned char u8;
extern void func_021ED9EC(u8 *);
extern void func_021F87D4(int);
void func_021ED4E4(u8 *p, int a, int b)
{
    func_021ED9EC(p + 0x48 + a * 12);
    func_021ED9EC(p + 0x48 + b * 12);
    func_021F87D4(1);
}
