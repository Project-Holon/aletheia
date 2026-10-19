/*
 * function: WIFIBATTLEMATCH_NET_IsCompPartyWindowReady
 * address: 0x021D98CC
 * packet: pkt_ov175_021D98CC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindow 0x021E8338 thumb ov177
 */
#include "../include/Obj24307.h"
typedef struct Work Work;
extern int WIFIBATTLEMATCH_VIEW_StepPartyWindow(Work *);
int WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(char *p)
{
    return WIFIBATTLEMATCH_VIEW_StepPartyWindow(*(Work * *)&((struct Obj24307 *)p)->f24);
}
