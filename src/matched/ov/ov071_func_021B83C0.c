/*
 * function: func_021B83C0
 * address:  0x021B83C0
 * packet:   pkt_ov071_021B83C0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_020452E8 on the pointer loaded from offset 0x3c.
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 */
#include "../include/Obj20724.h"

struct Descriptor;
typedef unsigned int   u32;
void func_021B83C0(void *p)
{
    u32 func_020452E8(struct Descriptor *d);
    func_020452E8(((struct Obj20724 *)p)->f3C);
}
