/*
 * function: func_021D6954
 * address:  0x021D6954
 * packet:   pkt_021D6954
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D65C8  0x021D65C8  thumb
 *
 * Clears the word at +0xe4 (the last-read length) and then tail-calls the
 *     +0x28 release path func_021D65C8, which is why nothing is saved.
 */
#include "../include/Obj24232.h"

typedef unsigned long u32;

extern void func_021D65C8(char *obj);

void func_021D6954(char *obj)
{
    ((struct Obj24232 *)obj)->fE4 = 0;
    func_021D65C8(obj);
}

