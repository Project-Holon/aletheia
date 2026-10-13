/*
 * function: FIELD_PLAYER_NOGRID_EndForcedMove
 * address:  0x021A6870
 * packet:   pkt_ov021_021A6870
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_HasFlags  0x021A66F8  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FIELD_PLAYER_NOGRID_ClearForcedMove  0x021A6714  thumb  ov021
 *   FIELD_PLAYER_NOGRID_SetForcedMoveEnded  0x021A6720  thumb  ov021
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearSpinA  0x021A6750  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearSpinB  0x021A6768  thumb  ov021
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FIELD_PLAYER_NOGRID_ClearFaceRight  0x021A6780  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearInputHold  0x021A6798  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ResetInputHold  0x021A6BAC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01658.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_NOGRID_HasFlags(u8 *p, u32 m);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern void FIELD_PLAYER_NOGRID_ClearForcedMove(void *a);
extern void FIELD_PLAYER_NOGRID_SetForcedMoveEnded(void *a);
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);
extern void FIELD_PLAYER_NOGRID_ClearSpinA(void *a);
extern void FIELD_PLAYER_NOGRID_ClearSpinB(void *a);
extern u16 FLDMMDL_GetDirMove(void *p);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int i);
extern int FLDMMDL_SetDirAll(int a0, int a1);
extern void FIELD_PLAYER_NOGRID_ClearFaceRight(void *a);
extern void FIELD_PLAYER_NOGRID_ClearInputHold(void *a);
extern int FIELD_PLAYER_NOGRID_ResetInputHold(void *a);

void FIELD_PLAYER_NOGRID_EndForcedMove(u8 *p)
{
    u32 o = *(u32 *)&((struct Obj01658 *)p)->f1C;

    if (FIELD_PLAYER_NOGRID_HasFlags(p, 0x59))
        FLDMMDL_ClearStatusBit((u32 *)o, 0x18);
    if (FIELD_PLAYER_NOGRID_HasFlags(p, 1)) {
        FIELD_PLAYER_NOGRID_ClearForcedMove(p);
        FIELD_PLAYER_NOGRID_SetForcedMoveEnded(p);
        FIELD_PLAYER_CORE_SetStepKind((u8 *)(*(u32 *)&((struct Obj01658 *)p)->f14), 0);
    }
    if (FIELD_PLAYER_NOGRID_HasFlags(p, 0x18)) {
        FIELD_PLAYER_NOGRID_ClearSpinA(p);
        FIELD_PLAYER_NOGRID_ClearSpinB(p);
        FLDMMDL_SetDirAll(o, FLDMMDL_MOVE_GetDirTableValue(FLDMMDL_GetDirMove((void *)o)));
    }
    if (FIELD_PLAYER_NOGRID_HasFlags(p, 0x20)) {
        FIELD_PLAYER_NOGRID_ClearFaceRight(p);
        FLDMMDL_SetDirAll(o, 3);
    }
    if (FIELD_PLAYER_NOGRID_HasFlags(p, 0x40)) {
        FIELD_PLAYER_NOGRID_ClearInputHold(p);
        FIELD_PLAYER_NOGRID_ResetInputHold(p + 0xC);
    }
}
