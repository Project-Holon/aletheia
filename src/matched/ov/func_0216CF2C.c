/*
 * function: FLDMMDL_DeleteMmdl
 * address:  0x0216CF2C
 * packet:   pkt_0216CF2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysCheckDrawInit  0x0216D948  thumb  ov010
 *   FLDMMDL_CallDrawDeleteProc  0x0216D76C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_CallMoveDeleteProc  0x0216D71C  thumb  ov010
 *   FLDMMDL_DeleteMoveTcb  0x0216DFAC  thumb  ov010
 *   FLDMMDL_SysDecMmdlCount  0x0216D508  thumb  ov010
 *   FLDMMDL_ClearMmdlWork  0x0216E180  thumb  ov010
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_SysCheckDrawInit(int a0);
extern int FLDMMDL_CallDrawDeleteProc();
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_CallMoveDeleteProc();
extern int FLDMMDL_DeleteMoveTcb(int a0);
extern int FLDMMDL_SysDecMmdlCount(int a0);
extern int FLDMMDL_ClearMmdlWork();

int FLDMMDL_DeleteMmdl(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)FLDMMDL_GetMmdlSys((void *)a0);
loc_0216CF34:
    a0 = FLDMMDL_SysCheckDrawInit(a0);
loc_0216CF38:
    if (a0 != 1) goto loc_0216CF42;
loc_0216CF3C:
a0 = t4 + 0;
    a0 = FLDMMDL_CallDrawDeleteProc(a0);
loc_0216CF42:
a0 = t4 + 0;
a1 = 2;
    a0 = FLDMMDL_CheckStatusBit(a0, a1);
loc_0216CF4A:
    if (a0 == 0) goto loc_0216CF5A;
loc_0216CF4E:
a0 = t4 + 0;
    a0 = FLDMMDL_CallMoveDeleteProc(a0);
loc_0216CF54:
a0 = t4 + 0;
    a0 = FLDMMDL_DeleteMoveTcb(a0);
loc_0216CF5A:
a0 = t4 + 0;
a0 = a0 + 0x88;
a0 = *(int *)&((struct Obj00113 *)((char *)a0))->f0;
    a0 = FLDMMDL_SysDecMmdlCount(a0);
loc_0216CF64:
a0 = t4 + 0;
    a0 = FLDMMDL_ClearMmdlWork(a0);
loc_0216CF6A:
    return a0;}
