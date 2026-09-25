/*
 * function: func_021F5350
 * address:  0x021F5350
 * packet:   pkt_021F5350
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021F6234  0x021F6234  thumb  ov112
 *
 * blocker: Target 0x021F6234 is unlabelled in ov112; sole witness is this function's own pool word. Byte-correct.
 */

void func_021F6234(int);

void func_021F5350(int *p)
{
    func_021F6234(*(int *)((char *)p + 8));
}
