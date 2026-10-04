/*
 * function: func_021BD808
 * address:  0x021BD808
 * packet:   pkt_021BD808
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Loads the word at [p] and tail-calls the function at 0x0204B3F4 with it.
 *
 * The pool word carries the thumb bit, so the callee is deliberately left
 * undeclared here and resolved through the label class.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);

void func_021BD808(int *p)
{
    func_0204B3F4((struct Obj *)(*p));
}
