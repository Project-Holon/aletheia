/*
 * function: func_021ED53C
 * address:  0x021ED53C
 * packet:   pkt_ov093_021ED53C
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
void func_021ED53C(u8 *p, int k)
{
    func_021ED9EC(p + 0x48 + k * 12);
    func_021F87D4(1);
}
