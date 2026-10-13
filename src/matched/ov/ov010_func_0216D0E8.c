/*
 * function: FLDMMDL_SetupRailPosFromHeader
 * address: 0x0216D0E8
 * packet: pkt_ov010_0216D0E8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: zero alignment halfword at 0x0216D0F6, then labelled 0x0216D0F8.
 * symbols:
 *   FLDMMDL_MOVE_RequestRailMove 0x02164304 thumb ov010
 */
#include "../include/Obj09310.h"
typedef unsigned char u8;
extern void FLDMMDL_MOVE_RequestRailMove(int, u8 *);
void FLDMMDL_SetupRailPosFromHeader(int a, u8 *p) {
    if (((struct Obj09310 *)p)->f18 == 1) FLDMMDL_MOVE_RequestRailMove(a, p);
}
