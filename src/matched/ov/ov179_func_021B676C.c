/*
 * function: func_021B676C
 * address:  0x021B676C
 * packet:   pkt_021B676C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B630C  0x021B630C  thumb  ov179
 */

extern void func_021B630C(int, int, int, int);

int func_021B676C(int a, int *q)
{
    func_021B630C(a, *(int *)((char *)q + 4), *(int *)((char *)q + 8), 5);
    return 1;
}
