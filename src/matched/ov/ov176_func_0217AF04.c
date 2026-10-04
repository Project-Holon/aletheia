/*
 * function: func_0217AF04
 * address:  0x0217AF04
 * packet:   pkt_0217AF04
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E54E0  0x021E54E0  thumb  ov177
 */

extern void func_021E54E0(char *p);

void func_0217AF04(int *p)
{
    func_021E54E0((char *)(*(int *)((char *)p + 0x24)));
    *(int *)((char *)p + 0x24) = 0;
}
