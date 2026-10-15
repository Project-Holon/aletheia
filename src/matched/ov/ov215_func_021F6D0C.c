/*
 * function: EGG_DEMO_VIEW_OnAnimStop
 * address:  0x021F6D0C
 * packet:   pkt_021F6D0C
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *
 * blocker: 0x02015E04 is an unlabelled ARM9 leaf (no func_ label, no SDK
 *   entry), so neither label nor sole-ref/code can attest the bl site;
 *   byte-correct.
 */
#include "../include/Obj14711.h"

extern void MCSS_SetAnmStopFlag(void *p);

int EGG_DEMO_VIEW_OnAnimStop(char *a)
{
    MCSS_SetAnmStopFlag((void *)(((struct Obj14711 *)a)->f34));
    ((struct Obj14711 *)a)->f38 = 1;
    return 1;
}