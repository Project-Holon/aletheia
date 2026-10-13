/*
 * function: SCRCMD_WORK_SetTargetObject
 * address:  0x0215A644
 * packet:   pkt_ov010_0215A644
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (setter through the pointer at +0x20), filed as a blocker
 * of ov021 SCRCMD_PLAYER_GRID_EVENT_StartA / SCRCMD_PLAYER_GRID_EVENT_StartB.
 */
#include "../include/Obj00005.h"
#include "../include/Obj18789.h"

typedef unsigned int u32;

void SCRCMD_WORK_SetTargetObject(void *p, u32 v)
{
    ((struct Obj18789 *)(*(char * *)&((struct Obj00005 *)p)->f20))->f10 = v;
}
