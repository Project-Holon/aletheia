/*
 * function: func_021BABF4
 * address:  0x021BABF4
 * packet:   pkt_021BABF4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BC6E0  0x021BC6E0  thumb  ov110
 *
 * blocker: Target 0x021BC6E0 is unlabelled in ov110; sole witness is this function's own pool word. Byte-correct.
 */

void func_021BC6E0(int);

void func_021BABF4(int *p)
{
    func_021BC6E0(*(int *)((char *)p + 0x54));
}
