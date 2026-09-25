/*
 * function: func_021BAC00
 * address:  0x021BAC00
 * packet:   pkt_021BAC00
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BC320  0x021BC320  thumb  ov110
 *
 * blocker: Target 0x021BC320 is unlabelled in ov110; sole witness is this function's own pool word. Byte-correct.
 */

void func_021BC320(int);

void func_021BAC00(int *p)
{
    func_021BC320(*(int *)((char *)p + 0x54));
}
