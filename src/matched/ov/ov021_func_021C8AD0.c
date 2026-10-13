/*
 * function: FIELD_TILE_MOVE_SpinTick
 * address:  0x021C8AD0
 * packet:   pkt_ov021_021C8AD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TILE_MOVE_GetSpinInterval  0x021C8A9C  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "../include/Obj00876.h"

typedef unsigned int   u32;
extern int FIELD_TILE_MOVE_GetSpinInterval(u32 a);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern void FLDMMDL_SetDirDispCheckPause(int a, int b);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);

void FIELD_TILE_MOVE_SpinTick(int *p)
{
    int d = FIELD_TILE_MOVE_GetSpinInterval((u32)p);

    ((struct Obj00876 *)p)->f18 = ((struct Obj00876 *)p)->f18 + 1;
    if (((struct Obj00876 *)p)->f18 % d == 0) {
        ((struct Obj00876 *)p)->f14 = (((struct Obj00876 *)p)->f14 + 1) % 4;
        FLDMMDL_ClearStatusBit((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
        FLDMMDL_SetDirDispCheckPause(*(int *)&((struct Obj00876 *)p)->fC, ((struct Obj00876 *)p)->f14);
        FLDMMDL_SetStatusBit((u32 *)(*(int *)&((struct Obj00876 *)p)->fC), 8);
    }
}
