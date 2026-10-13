/*
 * function: FIELD_PLAYER_NOGRID_ForcedSlide
 * address:  0x021A6908
 * packet:   pkt_ov021_021A6908
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FIELD_PLAYER_NOGRID_GetHitBits  0x021A5B6C  thumb  ov021
 *   FIELD_PLAYER_NOGRID_EndForcedMove  0x021A6870  thumb  ov021
 *   FIELD_PLAYER_NOGRID_SetForcedMove  0x021A6708  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearSpinA  0x021A6750  thumb  ov021
 *   FIELD_PLAYER_NOGRID_ClearSpinB  0x021A6768  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01658.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FLDMMDL_GetDirMove(void *o);
extern int FIELD_PLAYER_NOGRID_GetHitBits(u32 a, u32 b, u32 c, u32 d);
extern void FIELD_PLAYER_NOGRID_EndForcedMove(u8 *p);
extern void FIELD_PLAYER_NOGRID_SetForcedMove(void *a);
extern void FIELD_PLAYER_NOGRID_ClearSpinA(void *a);
extern void FIELD_PLAYER_NOGRID_ClearSpinB(void *a);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *o, u32 v);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *o, u32 v);

u32 FIELD_PLAYER_NOGRID_ForcedSlide(u8 *p, u32 a1)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r6 = FLDMMDL_GetDirMove(o);

    if (FIELD_PLAYER_NOGRID_GetHitBits((u32)p, (u32)o, r6, 0)) {
        FIELD_PLAYER_NOGRID_EndForcedMove(p);
        return a1;
    }
    FIELD_PLAYER_NOGRID_SetForcedMove(p);
    FIELD_PLAYER_NOGRID_ClearSpinA(p);
    FIELD_PLAYER_NOGRID_ClearSpinB(p);
    FLDMMDL_SetDirDispCheckPause((int)o, r6);
    FLDMMDL_SetAcmd(o, FLDMMDL_ACMD_ConvertCodeByDir(r6, 0x10));
    FLDMMDL_SetStatusBit(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    FIELD_PLAYER_CORE_SetStepKind(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r6;
}
