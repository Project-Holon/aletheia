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

extern unsigned int func_02183D3C(unsigned int *p);
extern void func_02184818(char *p);
extern void func_02183D44(unsigned int *p);

void func_02183EC0(int *p)
{
    func_02184818((char *)func_02183D3C((unsigned int *)((int)p)));
    func_02183D44((unsigned int *)p);
}
