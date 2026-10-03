/*
 * function: func_021E7DF0
 * address:  0x021E7DF0
 * packet:   pkt_021E7DF0
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020307B0  0x020307B0  arm
 */

extern void func_0204B3B4(int);
extern void func_020307B0(void *p);

void func_021E7DF0(int *p)
{
    func_0204B3B4(*(int *)((char *)p + 4));
    func_0204B3B4(*(int *)p);
    func_020307B0(p);
}
