/*
 * function: func_021DE0AC
 * address:  0x021DE0AC
 * packet:   pkt_021DE0AC
 * region:   ov171
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

void func_021DE0AC(int *p, int i)
{
    func_0204B98C(*(int *)((char *)p + i * 4 + 0xB74));
}
