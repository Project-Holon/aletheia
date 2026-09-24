/*
 * function: func_021BD0A0
 * address:  0x021BD0A0
 * packet:   pkt_021BD0A0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Tail call to the function at 0x0204A648: loads the pointer from the pool and branches through it.
 *
 * The pool word carries the thumb bit, so the callee is deliberately left
 * undeclared here and resolved through the label class.
 */

extern void func_0204A648(void);

void func_021BD0A0(void)
{
    func_0204A648();
}
