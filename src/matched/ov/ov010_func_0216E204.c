/*
 * function: FLDMMDL_ChangeObjCode
 * address:  0x0216E204
 * packet:   pkt_ov010_0216E204
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
 *   FLDMMDL_CheckMoveBitDrawInitComp  0x0216DAA0  thumb  ov010
 *   FLDMMDL_CallDrawDeleteProc  0x0216D76C  thumb  ov010
 *   FLDMMDL_SetObjCode  0x0216D594  thumb  ov010
 *   FLDMMDL_LoadMmdlObjCodeParam  0x0216E39C  thumb  ov010
 *   FLDMMDL_OffMoveBitDrawInitComp  0x0216DA94  thumb  ov010
 *   FLDMMDL_ResetMoveStart  0x0216E190  thumb  ov010
 *   FLDMMDL_InitDraw  0x0216E114  thumb  ov010
 */
#include "../include/Obj00113.h"
#include "../include/Obj05908.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern void *FLDMMDL_GetMmdlSys(void *a);
extern int FLDMMDL_SysCheckDrawInit(int a0);
extern int FLDMMDL_CheckMoveBitDrawInitComp(void *a);
extern void FLDMMDL_CallDrawDeleteProc(void *a);
typedef unsigned int   u32;
extern void FLDMMDL_SetObjCode(void *p, u32 v);
extern void FLDMMDL_LoadMmdlObjCodeParam(int a0, int a1, int a2);
extern void FLDMMDL_OffMoveBitDrawInitComp(void *a);
extern void FLDMMDL_ResetMoveStart(void *a);
extern int FLDMMDL_InitDraw(int a0);

void FLDMMDL_ChangeObjCode(char *a, u32 v)
{
    void *ctx;
    char *p;

    ctx = FLDMMDL_GetMmdlSys(a);
    if (FLDMMDL_SysCheckDrawInit((int)ctx) == 1 && FLDMMDL_CheckMoveBitDrawInitComp(a) == 1)
        FLDMMDL_CallDrawDeleteProc(a);
    FLDMMDL_SetObjCode(a, v);
    FLDMMDL_LoadMmdlObjCodeParam((int)ctx, v, (int)a);
    p = a + 0xe4;
    ((struct Obj00113 *)a)->f7C = ((struct Obj05908 *)p)->fB;
    ((struct Obj00113 *)a)->f7D = ((struct Obj05908 *)p)->fC;
    *(s8 *)&((struct Obj00113 *)a)->f7E = ((struct Obj05908 *)p)->fD;
    *(s8 *)&((struct Obj00113 *)a)->f7F = ((struct Obj05908 *)p)->fE;
    *(s8 *)&((struct Obj00113 *)a)->f80 = ((struct Obj05908 *)p)->fF;
    FLDMMDL_OffMoveBitDrawInitComp(a);
    FLDMMDL_ResetMoveStart(a);
    FLDMMDL_InitDraw((int)a);
}
