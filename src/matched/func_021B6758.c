/*
 * function: func_021B6758
 * address:  0x021B6758
 * packet:   pkt_021B6758
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B62E0  0x021B62E0  thumb  ov179
 */

extern void func_021B62E0(int, int, int, int);

int func_021B6758(int a, int *q)
{
    func_021B62E0(a, *(int *)((char *)q + 4), *(int *)((char *)q + 8), 5);
    return 1;
}
