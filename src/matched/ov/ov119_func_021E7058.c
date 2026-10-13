/*
 * function: func_021E7058
 * address: 0x021E7058
 * packet: pkt_ov119_021E7058
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
#include "../include/Obj00001.h"
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_021E7058(void *p)
{
    if (((struct Obj00001 *)p)->fF24) {
        CLACT_DeleteActor((struct Obj *)(((struct Obj00001 *)p)->fF24));
        ((struct Obj00001 *)p)->fF24 = 0;
        *((char *)p + 0x11f5) = 0;
    }
}
