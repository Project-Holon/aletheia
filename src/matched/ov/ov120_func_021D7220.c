/*
 * function: GTSNEGO_MSG_ScrollListDown
 * address: 0x021D7220
 * packet: pkt_ov120_021D7220
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   GTSNEGO_MSG_SetListEntry 0x021D71B8 thumb ov120
 */
#include "../include/Obj10397.h"
typedef unsigned char u8;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void GTSNEGO_MSG_SetListEntry(u8 *, void *, int);
void GTSNEGO_MSG_ScrollListDown(u8 *p, void *q)
{
    int i;
    if (q) {
        if (((struct Obj10397 *)p)->f14C) CLACT_DeleteActor(((struct Obj10397 *)p)->f14C);
        for (i = 0; i < 5; i++) *(void **)(p + 0x14c + i * 4) = *(void **)(p + 0x150 + i * 4);
        ((struct Obj10397 *)p)->f160 = 0;
        GTSNEGO_MSG_SetListEntry(p, q, 5);
    }
}
