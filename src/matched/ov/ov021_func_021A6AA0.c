/*
 * function: FIELD_PLAYER_NOGRID_ForcedInputHold
 * address:  0x021A6AA0
 * packet:   pkt_ov021_021A6AA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_HasFlags  0x021A66F8  thumb  ov021
 *   FIELD_PLAYER_NOGRID_SetInputHold  0x021A678C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_EnableInputHold  0x021A6B9C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_GetInputHoldDir  0x021A6C4C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_IsInputHoldKept  0x021A6C64  thumb  ov021
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07501.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_NOGRID_HasFlags(u8 *p, u32 m);
extern void FIELD_PLAYER_NOGRID_SetInputHold(void *a);
extern void FIELD_PLAYER_NOGRID_EnableInputHold(u8 *p);
extern u32 FIELD_PLAYER_NOGRID_GetInputHoldDir(u8 *p, u32 v);
extern u32 FIELD_PLAYER_NOGRID_IsInputHoldKept(u8 *p);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *o, u32 v);
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *o, u32 v);

u32 FIELD_PLAYER_NOGRID_ForcedInputHold(u8 *p, u32 a1)
{
    u32 r5;

    if (!FIELD_PLAYER_NOGRID_HasFlags(p, 0x40)) {
        FIELD_PLAYER_NOGRID_SetInputHold(p);
        FIELD_PLAYER_NOGRID_EnableInputHold(p + 0xC);
    }
    r5 = (u16)FIELD_PLAYER_NOGRID_GetInputHoldDir(p + 0xC, a1);
    if (FIELD_PLAYER_NOGRID_IsInputHoldKept(p + 0xC)) {
        FLDMMDL_SetStatusBit(((struct Obj07501 *)p)->f1C, 0x18);
        FLDMMDL_SetAcmd(((struct Obj07501 *)p)->f1C, FLDMMDL_ACMD_ConvertCodeByDir(r5, 8));
        FIELD_PLAYER_CORE_SetStepKind(*(u8 * *)&((struct Obj07501 *)p)->f14, 1);
        r5 = 9;
    } else {
        FLDMMDL_ClearStatusBit(((struct Obj07501 *)p)->f1C, 0x18);
    }
    return r5;
}
