/*
 * function: MUSICAL_MCSS_GetRenderSize
 * address:  0x021F5424
 * packet:   pkt_ov112_021F5424
 * region:   ov112
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * STA_ACT_LIGHT_CallElemB.  The +8 word is loaded once and shared by both arms
 * (the two identical loads CSE, which schedules the load before the branch).
 *
 * symbols:
 *   MUSICAL_MCSS_GetFieldC  0x021F626C  thumb  ov112
 *   MUSICAL_MCSS_GetFieldD  0x021F6280  thumb  ov112
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13831.h"

typedef unsigned char  u8;
extern void MUSICAL_MCSS_GetFieldC(u8 *p);
extern void MUSICAL_MCSS_GetFieldD(u8 *p);

void MUSICAL_MCSS_GetRenderSize(int a0, int a1)
{
    if (a1 == 1)
        MUSICAL_MCSS_GetFieldC((u8 *)(((struct Obj13831 *)a0)->f8));
    else
        MUSICAL_MCSS_GetFieldD((u8 *)(((struct Obj13831 *)a0)->f8));
}
