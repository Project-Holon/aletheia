/*
 * function: FLDMMDL_SetHeaderPos
 * address: 0x0216D02C
 * packet: pkt_ov010_0216D02C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_SetGridPosFromHeader 0x0216D0F8 thumb ov010
 *   FLDMMDL_MOVE_SetStatusPauseDraw 0x021642F8 thumb ov010
 */
#include "../include/Obj19118.h"
typedef unsigned char u8;
extern void FLDMMDL_SetGridPosFromHeader(void *obj, const u8 *a1);
extern void FLDMMDL_MOVE_SetStatusPauseDraw(void *a0);
void FLDMMDL_SetHeaderPos(int a, u8 *p) {
    if (((struct Obj19118 *)p)->f18 == 0) FLDMMDL_SetGridPosFromHeader((void *)a, p);
    else FLDMMDL_MOVE_SetStatusPauseDraw((void *)a);
}
