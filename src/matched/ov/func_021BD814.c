/*
 * function: func_021BD814
 * address:  0x021BD814
 * packet:   pkt_021BD814
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   (none)

 * Stores +4 and either re-arms +8 from +0x24 or takes it from +0x26 before handing the pair to 0x0204B878.
 */
#include "../include/Obj03065.h"


typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void func_021BD814(char *p, int v)
{
    ((struct Obj03065 *)p)->f4 = v;
    if (v != 0) {
        if (((struct Obj03065 *)p)->f8 == ((struct Obj03065 *)p)->f28)
            ((struct Obj03065 *)p)->f8 = ((struct Obj03065 *)p)->f24;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj03065 *)p)->f0), (unsigned short)((struct Obj03065 *)p)->f8);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj03065 *)p)->f0), ((struct Obj03065 *)p)->f26);
    }
}

