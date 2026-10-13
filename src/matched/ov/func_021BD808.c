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
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm  arm9
 *   (none)
 *
 * Loads the word at [p] and tail-calls the function at 0x0204B3F4 with it.
 *
 * The pool word carries the thumb bit, so the callee is deliberately left
 * undeclared here and resolved through the label class.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

void func_021BD808(int *p)
{
    CLACT_GetActorDrawEnable((struct Obj *)(*p));
}
