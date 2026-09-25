/*
 * function: func_021F535C
 * address:  0x021F535C
 * packet:   pkt_021F535C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021F624C  0x021F624C  thumb  ov112
 *
 * blocker: Target 0x021F624C is unlabelled in ov112; sole witness is this function's own pool word. Byte-correct.
 */

void func_021F624C(int);

void func_021F535C(int *p)
{
    func_021F624C(*(int *)((char *)p + 8));
}
