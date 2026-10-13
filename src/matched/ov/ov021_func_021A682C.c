/*
 * function: FIELD_PLAYER_NOGRID_RunForcedMove
 * address:  0x021A682C
 * packet:   pkt_ov021_021A682C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_NOGRID_GetForcedMoveKind  0x021A67A4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_EndForcedMove  0x021A6870  thumb  ov021
 *   gFieldPlayerNogridForcedMoveFuncs  0x021D8AB8  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01658.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef u32 (*Fn)(u8 *p, u32 a, u32 b);

extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern u32 FIELD_PLAYER_NOGRID_GetForcedMoveKind(u8 *p);
extern void FIELD_PLAYER_NOGRID_EndForcedMove(u8 *p);
extern const Fn gFieldPlayerNogridForcedMoveFuncs[];

u32 FIELD_PLAYER_NOGRID_RunForcedMove(u8 *p, u32 a1, u32 a2)
{
    u32 k;

    if (!FLDMMDL_CheckPossibleAcmd(*(u32 *)&((struct Obj01658 *)p)->f1C))
        return a1;
    if (a2 == 0) {
        k = FIELD_PLAYER_NOGRID_GetForcedMoveKind(p);
        if (k != 0)
            return gFieldPlayerNogridForcedMoveFuncs[k](p, a1, a2);
    }
    FIELD_PLAYER_NOGRID_EndForcedMove(p);
    return a1;
}
