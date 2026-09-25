/*
 * function: func_021B6744
 * address:  0x021B6744
 * packet:   pkt_ov179_021B6744
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B62B8  0x021B62B8  thumb  ov179
 */

extern void func_021B62B8(int, int, int, int);

int func_021B6744(int a, int *q)
{
    func_021B62B8(a, *(int *)((char *)q + 4), *(int *)((char *)q + 8), 5);
    return 1;
}
