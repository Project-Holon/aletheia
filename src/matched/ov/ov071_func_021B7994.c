/*
 * function: func_021B7994
 * address:  0x021B7994
 * packet:   pkt_ov071_021B7994
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_020452E8 on the pointer loaded from offset 0.
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 */
#include "../include/Obj20695.h"

struct Descriptor;
void func_021B7994(void *p)
{
    void func_020452E8(struct Descriptor *d);
    func_020452E8(((struct Obj20695 *)p)->f0);
}
