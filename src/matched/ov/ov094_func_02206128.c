/*
 * function: BTLV_INPUT_DeleteBackActor
 * address:  0x02206128
 * packet:   pkt_ov094_02206128
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
#include "../include/Obj10158.h"

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void BTLV_INPUT_DeleteBackActor(char *p)
{
    if (((struct Obj10158 *)p)->f21C != 0) {
        CLACT_DeleteActor(((struct Obj10158 *)p)->f21C);
        ((struct Obj10158 *)p)->f21C = 0;
    }
}
