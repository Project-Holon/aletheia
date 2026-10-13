/*
 * function: FIELD_PLAYER_GRID_StartForcedMove
 * address:  0x021A5538
 * packet:   pkt_ov021_021A5538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FIELD_PLAYER_GRID_GetStepHitFlags  0x021A5264  thumb  ov021
 *   FIELD_PLAYER_GRID_ReleaseForcedMove  0x021A550C  thumb  ov021
 *   FIELD_PLAYER_GRID_SetNoForcedMoveFlag  0x021A5354  thumb  ov021
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 *   FIELD_PLAYER_GRID_SetForcedMoveFlag  0x021A5328  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06014.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetDirMove(void *p);
extern int FIELD_PLAYER_GRID_GetStepHitFlags(u8 *a, void *b, u32 c, int *d);
extern void FIELD_PLAYER_GRID_ReleaseForcedMove(u32 *p);
extern void FIELD_PLAYER_GRID_SetNoForcedMoveFlag(u32 a);
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);
extern void FIELD_PLAYER_GRID_SetForcedMoveFlag(u32 a);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *a0, int a1);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v); /* its third parameter is a scratch it never reads */

int FIELD_PLAYER_GRID_StartForcedMove(u8 *a)
{
    int v;
    void *x = FIELD_PLAYER_CORE_GetMmdl(*(unsigned char * *)&((struct Obj06014 *)a)->fC);
    u32 y = FLDMMDL_GetDirMove(x);
    if (FIELD_PLAYER_GRID_GetStepHitFlags(a, x, y, &v) != 0) {
        FIELD_PLAYER_GRID_ReleaseForcedMove((u32 *)a);
        FIELD_PLAYER_GRID_SetNoForcedMoveFlag((u32)a);
        FIELD_PLAYER_CORE_SetStepKind(*(u8 * *)&((struct Obj06014 *)a)->fC, 0);
        return 0;
    }
    FIELD_PLAYER_GRID_SetForcedMoveFlag((u32)a);
    FLDMMDL_SetAcmd(x, FLDMMDL_ACMD_ConvertCodeByDir(y, 0x10));
    FLDMMDL_SetStatusBit(x, 0x18);
    ((struct Obj06014 *)a)->f0 = 1;
    FIELD_PLAYER_CORE_SetStepKind(*(u8 * *)&((struct Obj06014 *)a)->fC, 1);
    return 1;
}
