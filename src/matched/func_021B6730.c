/*
 * function: func_021B6730
 * address:  0x021B6730
 * packet:   pkt_021B6730
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6290  0x021B6290  thumb  ov179
 */

extern void func_021B6290(int, int, int, int);

int func_021B6730(int a, int *q)
{
    func_021B6290(a, *(int *)((char *)q + 4), *(int *)((char *)q + 8), 5);
    return 1;
}
