/*
 * function: FLDMMDL_MOVE_RequestRailMove
 * address:  0x02164304
 * packet:   pkt_ov010_02164304
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb
 *   FLDMMDL_SysCheckStatusBit  0x0216D4D4  thumb
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb
 *   FLDMMDL_MOVE_SetRailMoveRequest  0x0216435C  thumb
 */
#include "../include/Obj09310.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef struct {
    u16 a;
    u8 b;
    u8 c;
    s16 d;
    u16 e;
} Msg;

extern u8 ZONEDATA_DirToRailKey(int i);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysCheckStatusBit(int a, int b);
extern void FLDMMDL_RAIL_SetLocation(int a, Msg *m);
extern void FLDMMDL_InitMoveProcWork(int a, int b);
extern void FLDMMDL_MOVE_SetRailMoveRequest(void *a, const u16 *b);

void FLDMMDL_MOVE_RequestRailMove(int a, u8 *p)
{
    Msg m;
    u16 *q;

    m.a = ((struct Obj09310 *)p)->f1C;
    m.b = 1;
    q = (u16 *)(p + 0x1c);
    m.c = ZONEDATA_DirToRailKey(((struct Obj09310 *)p)->fC);
    m.e = q[1];
    m.d = ((s16 *)q)[2];
    if (FLDMMDL_SysCheckStatusBit((int)FLDMMDL_GetMmdlSys((void *)a), 0x10) != 0) {
        FLDMMDL_RAIL_SetLocation(a, &m);
        return;
    }
    FLDMMDL_InitMoveProcWork(a, 0xc);
    FLDMMDL_MOVE_SetRailMoveRequest((void *)a, (const u16 *)(&m));
}
