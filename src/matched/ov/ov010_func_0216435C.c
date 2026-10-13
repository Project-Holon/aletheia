/*
 * function: FLDMMDL_MOVE_SetRailMoveRequest
 * address: 0x0216435C
 * packet: pkt_ov010_0216435C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_GetMoveProcWork 0x0216D69C thumb ov010
 */
#include "../include/Obj05896.h"

typedef unsigned short u16;
extern void *FLDMMDL_GetMoveProcWork(void *p);
void FLDMMDL_MOVE_SetRailMoveRequest(void *a, const u16 *b) { u16 *p=FLDMMDL_GetMoveProcWork(a); p[2]=b[0]; p[3]=b[1]; p[4]=b[2]; p[5]=b[3]; ((struct Obj05896 *)p)->f0=0xEFEFEFEF; }
