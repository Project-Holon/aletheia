/*
 * function: func_021BC34C
 * address:  0x021BC34C
 * packet:   pkt_021BC34C
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
 * Calls the ARM9 function at 0x020307B0 on the word at +0x10, then clears the field.
 */
#include "../include/Obj12110.h"

extern void func_020307B0(void *p);

void func_021BC34C(char *p)
{
    func_020307B0((void *)(((struct Obj12110 *)p)->f10));
    ((struct Obj12110 *)p)->f10 = 0;
}
