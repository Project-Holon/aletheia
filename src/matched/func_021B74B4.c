/*
 * function: func_021B74B4
 * address:  0x021B74B4
 * packet:   pkt_021B74B4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm
 */

extern void func_0204B98C(int);

void func_021B74B4(int *p, int i)
{
    func_0204B98C(*(int *)((char *)p + i * 4 + 0x9048));
}
