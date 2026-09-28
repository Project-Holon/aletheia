/*
 * function: func_02183EC0
 * address:  0x02183EC0
 * packet:   pkt_02183EC0
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D3C  0x02183D3C  thumb  ov168
 *   func_02184818  0x02184818  thumb  ov168
 *   func_02183D44  0x02183D44  thumb  ov168
 */

extern void func_02183D3C(void);
extern void func_02184818(void);
extern void func_02183D44(int *);

void func_02183EC0(int *p)
{
    func_02183D3C();
    func_02184818();
    func_02183D44(p);
}
