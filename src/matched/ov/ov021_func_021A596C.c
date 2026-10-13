/*
 * function: FIELD_PLAYER_NOGRID_Update
 * address:  0x021A596C
 * packet:   pkt_ov021_021A596C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_ChooseMoveDirFromKeys  0x021A3AB8  thumb  ov021
 *   FIELD_PLAYER_CORE_StepFormChange  0x021A3CC0  thumb  ov021
 *   FIELD_PLAYER_NOGRID_UpdateInputHold  0x021A6BB4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_RunForcedMove  0x021A682C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_CheckAction  0x021A5A68  thumb  ov021
 *   FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck  0x021A5B4C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartAction  0x021A5AD4  thumb  ov021
 *   FIELD_PLAYER_NOGRID_UpdateSpin  0x021A5B7C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_EndInputHoldFrame  0x021A6C30  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09572.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef unsigned short u16;
extern u16 FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(u32 a, u32 v);
extern void FIELD_PLAYER_CORE_StepFormChange(u32 a);
extern void FIELD_PLAYER_NOGRID_UpdateInputHold(u8 *p, u32 a1, u32 a2);
extern u32  FIELD_PLAYER_NOGRID_RunForcedMove(u8 *p, u32 a1, u32 a2);
extern int FIELD_PLAYER_NOGRID_CheckAction(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern void FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck(u32 *p, u32 a, int mode);
extern void FIELD_PLAYER_NOGRID_StartAction(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void FIELD_PLAYER_NOGRID_UpdateSpin(u8 *p);
extern void FIELD_PLAYER_NOGRID_EndInputHoldFrame(u8 *p);

void FIELD_PLAYER_NOGRID_Update(u8 *p, u32 b, u32 c)
{
    u32 t;
    u32 x;
    u32 y;

    t = FIELD_PLAYER_CORE_ChooseMoveDirFromKeys(((struct Obj09572 *)p)->f14, c);
    FIELD_PLAYER_CORE_StepFormChange(((struct Obj09572 *)p)->f14);
    FIELD_PLAYER_NOGRID_UpdateInputHold(p + 0xc, t, ((struct Obj09572 *)p)->f1C);
    x = FIELD_PLAYER_NOGRID_RunForcedMove(p, t, 0);
    y = FIELD_PLAYER_NOGRID_CheckAction(p, x, b, c, 0);
    FIELD_PLAYER_NOGRID_UpdateFlagsAfterCheck((u32 *)p, c, y);
    FIELD_PLAYER_NOGRID_StartAction(p, y, x, b, c, 0);
    FIELD_PLAYER_NOGRID_UpdateSpin(p);
    FIELD_PLAYER_NOGRID_EndInputHoldFrame(p + 0xc);
}
