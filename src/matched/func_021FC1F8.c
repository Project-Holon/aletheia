/*
 * function: func_021FC1F8
 * address:  0x021FC1F8
 * packet:   pkt_021FC1F8
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 */

extern void func_0204ADA4(int);

void func_021FC1F8(int *p, int i)
{
    func_0204ADA4(p[i]);
    p[i] = -1;
}
