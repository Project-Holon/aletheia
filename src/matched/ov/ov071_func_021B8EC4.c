/*
 * function: func_021B8EC4
 * address:  0x021B8EC4
 * packet:   pkt_ov071_021B8EC4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B7070(word at 0x4, a + 0x48).
 *
 * symbols:
 *   func_021B7070  0x021B7070  thumb  ov071
 */
#include "../include/Obj06188.h"

void func_021B8EC4(void *p, int a)
{
    void func_021B7070(int *p, int *out);
    func_021B7070(((struct Obj06188 *)p)->f4, (int *)(a + 0x48));
}
