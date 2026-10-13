/*
 * function: FLDMMDL_AddMoveTcb
 * address:  0x0216DF64
 * packet:   pkt_ov010_0216DF64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030DA8  0x02030DA8  arm
 *   FLDMMDL_SysGetTcbPriority  0x0216D4F4  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_SysGetTcbSys  0x0216D514  thumb  ov010
 *   FLDMMDL_MoveTcbProc  0x0216D3A8  thumb  ov010
 */
#include "../include/Obj19133.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 FLDMMDL_SysGetTcbPriority(void *p);
extern u16 FLDMMDL_GetMoveCode(void *p);
extern u16 FLDMMDL_GetObjId(void *p);
extern u32 FLDMMDL_SysGetTcbSys(void *p);
extern void FLDMMDL_MoveTcbProc(u32 a, u32 b);
extern int func_02030DA8(int owner, int fn, int arg, int n);

void FLDMMDL_AddMoveTcb(u8 *o, u32 b)
{
    int d = 0;
    int base = FLDMMDL_SysGetTcbPriority((void *)b);
    int t = FLDMMDL_GetMoveCode(o);

    if (t == 0x30 || t == 0x32)
        d = 1;
    else if (FLDMMDL_GetObjId(o) == 0xff)
        d--;
    ((struct Obj19133 *)o)->f84 = func_02030DA8(FLDMMDL_SysGetTcbSys((void *)b), (int)FLDMMDL_MoveTcbProc, (int)o, base + d);
}
