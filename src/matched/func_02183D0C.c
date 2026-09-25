/*
 * function: func_02183D0C
 * address:  0x02183D0C
 * packet:   pkt_02183D0C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D34  0x02183D34  thumb  ov168
 */

extern void func_02183D34(int *, int);

void func_02183D0C(int *p, int a, int b)
{
    *p = a;
    *(int *)((char *)p + 0xc) = 0;
    func_02183D34(p, b);
}
