/*
 * function: func_021BABE8
 * address:  0x021BABE8
 * packet:   pkt_021BABE8
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BC6DC  0x021BC6DC  thumb  ov110
 *
 * blocker: Target 0x021BC6DC is unlabelled in ov110; sole witness is this function's own pool word. Byte-correct.
 */

void func_021BC6DC(int);

void func_021BABE8(int *p)
{
    func_021BC6DC(*(int *)((char *)p + 0x54));
}
