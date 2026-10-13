/*
 * function: FIELD_EVENT_CHECK_LedgeJumpTaskMain
 * address:  0x0218B32C
 * packet:   pkt_ov021_0218B32C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb
 *   FLDEFF_NAMIPOKE_SetFollowMode  0x021ACBB8  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb
 *   FIELD_PLAYER_FinishFormChange  0x021A2F60  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FIELD_PLAYER_ChangeToNormalForm  0x021A2FD0  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELD_PLAYER_SetGridMoveState  0x021A35A0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05974.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void *FLDMMDL_GetMmdlSys(void *o);
extern void FLDMMDL_SysPauseMove(void *o);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern void FLDEFF_NAMIPOKE_SetFollowMode(u32 a, u8 v);
extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
extern void FIELD_PLAYER_FinishFormChange(int *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *o, int a);
extern int FLDMMDL_CheckEndAcmd(void *o);
extern int FIELD_PLAYER_ChangeToNormalForm(void *a);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern void FIELD_PLAYER_SetGridMoveState(u32 *p, int a);

int FIELD_EVENT_CHECK_LedgeJumpTaskMain(void *unused, int *st, char *ctx)
{
    void *a = FIELDMAP_GetFieldPlayer(((struct Obj05974 *)ctx)->fC);
    void *o;
    int r1;

    FIELD_PLAYER_GetFormCode(a);
    o = FIELD_PLAYER_GetMmdl(a);
    switch (*st) {
    case 0:
        FLDMMDL_SysPauseMove(FLDMMDL_GetMmdlSys(o));
        FLDMMDL_SetDirDispCheckPause((int)o, ((struct Obj05974 *)ctx)->f4);
        *st = *st + 1;
        break;
    case 1:
        FLDEFF_NAMIPOKE_SetFollowMode((u32)FIELD_PLAYER_GetRideEffect(a), 0);
        FIELD_PLAYER_StartFormChange(a, 1);
        FIELD_PLAYER_FinishFormChange(a);
        r1 = FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj05974 *)ctx)->f4, 0x34);
        if (((struct Obj05974 *)ctx)->f6 == 1)
            r1 = FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj05974 *)ctx)->f4, 0x38);
        FLDMMDL_SetAcmd(o, r1);
        *st = *st + 1;
        break;
    case 2:
        if (FLDMMDL_CheckEndAcmd(o) == 1) {
            FIELD_PLAYER_ChangeToNormalForm(a);
            *st = *st + 1;
        }
        break;
    case 3:
        FLDMMDL_SysResumeMove(FLDMMDL_GetMmdlSys(o));
        FIELD_PLAYER_SetGridMoveState(a, 1);
        return 1;
    }
    return 0;
}
