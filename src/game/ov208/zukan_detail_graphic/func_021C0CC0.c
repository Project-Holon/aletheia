/*
 * function: func_021C0CC0
 * address:  0x021C0CC0
 * packet:   pkt_021C0CC0
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
 * Loads the word at +0xD4 of the second argument and tail-calls the function at 0x0204B3F4 with it.
 *
 * The pool word carries the thumb bit, so the callee is deliberately left
 * undeclared here and resolved through the label class.
 */
#include "../../../matched/include/Obj18273.h"

typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);

void func_021C0CC0(int unused, char *p)
{
    func_0204B3F4((struct Obj *)(((struct Obj18273 *)p)->fD4));
}
