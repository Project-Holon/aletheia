/*
 * function: func_021DCB70
 * address:  0x021DCB70
 * packet:   pkt_021DCB70
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 */

extern int func_02021518(int);
extern void func_0202155C(int, int, int, int);

void func_021DCB70(int *p)
{
    int x = func_02021518(0x8c);

    *(int *)((char *)p + 0xB30) = x;
    func_0202155C(x, 2, 0x200, 0x8c);
}
