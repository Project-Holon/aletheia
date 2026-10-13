/*
 * function: FLDMMDL_SetHeaderParams
 * address:  0x0216CFC4
 * packet:   pkt_0216CFC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SetObjId  0x0216D584  thumb  ov010
 *   FLDMMDL_SetMoveCode  0x0216D59C  thumb  ov010
 *   FLDMMDL_SetEventType  0x0216D5A4  thumb  ov010
 *   FLDMMDL_SetEventFlag  0x0216D5AC  thumb  ov010
 *   FLDMMDL_SetEventId  0x0216D5B4  thumb  ov010
 *   FLDMMDL_SetParam  0x0216D620  thumb  ov010
 *   FLDMMDL_SetMoveLimitX  0x0216D65C  thumb  ov010
 *   FLDMMDL_SetMoveLimitZ  0x0216D668  thumb  ov010
 */
#include "../include/Obj00113.h"
#include "../include/Obj02051.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_SetObjId();
extern int FLDMMDL_SetMoveCode();
extern int FLDMMDL_SetEventType();
extern int FLDMMDL_SetEventFlag();
extern int FLDMMDL_SetEventId();
extern int FLDMMDL_SetParam(int a0, int a1, int a2);
extern int FLDMMDL_SetMoveLimitX();
extern int FLDMMDL_SetMoveLimitZ();

int FLDMMDL_SetHeaderParams(int a0, int a1)
{
    int a2;
    int t4;
    int t5;

t4 = a1 + 0;
a1 = ((struct Obj02051 *)((char *)t4))->f0;
t5 = a0 + 0;
    a0 = FLDMMDL_SetObjId(a0, a1);
loc_0216CFD0:
a1 = ((struct Obj02051 *)t4)->f4;
a0 = t5 + 0;
    a0 = FLDMMDL_SetMoveCode(a0, a1);
loc_0216CFD8:
a1 = ((struct Obj02051 *)t4)->f6;
a0 = t5 + 0;
    a0 = FLDMMDL_SetEventType(a0, a1);
loc_0216CFE0:
a1 = ((struct Obj02051 *)t4)->f8;
a0 = t5 + 0;
    a0 = FLDMMDL_SetEventFlag(a0, a1);
loc_0216CFE8:
a1 = ((struct Obj02051 *)t4)->fA;
a0 = t5 + 0;
    a0 = FLDMMDL_SetEventId(a0, a1);
loc_0216CFF0:
a0 = ((struct Obj02051 *)t4)->fC;
a1 = ((struct Obj02051 *)t4)->fE;
a2 = 0;
*(u16 *)((char *)t5 + 0x16) = a0;
((struct Obj00113 *)t5)->f1A = a0;
a0 = t5 + 0;
    a0 = FLDMMDL_SetParam(a0, a1, a2);
loc_0216D000:
a1 = ((struct Obj02051 *)t4)->f10;
a0 = t5 + 0;
a2 = 1;
    a0 = FLDMMDL_SetParam(a0, a1, a2);
loc_0216D00A:
a1 = ((struct Obj02051 *)t4)->f12;
a0 = t5 + 0;
a2 = 2;
    a0 = FLDMMDL_SetParam(a0, a1, a2);
loc_0216D014:
a1 = 0x14;
a1 = *(short *)((char *)t4 + a1);
a0 = t5 + 0;
    a0 = FLDMMDL_SetMoveLimitX(a0, a1);
loc_0216D01E:
a1 = 0x16;
a1 = *(short *)((char *)t4 + a1);
a0 = t5 + 0;
    a0 = FLDMMDL_SetMoveLimitZ(a0, a1);
loc_0216D028:
    return a0;}
