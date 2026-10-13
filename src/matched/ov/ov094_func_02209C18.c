/*
 * function: BTLV_FINGER_CURSOR_DeleteActor
 * address:  0x02209C18
 * packet:   pkt_ov094_02209C18
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */
#include "../include/Obj10160.h"

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void BTLV_FINGER_CURSOR_DeleteActor(char *p)
{
    if (((struct Obj10160 *)p)->f4 != 0) {
        CLACT_DeleteActor(((struct Obj10160 *)p)->f4);
        ((struct Obj10160 *)p)->f4 = 0;
    }
}
