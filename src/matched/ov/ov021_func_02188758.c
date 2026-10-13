/*
 * function: FIELDMAP_SeqUpdate
 * address:  0x02188758
 * packet:   pkt_ov021_02188758
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetEvent  0x02012104  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   FIELDMAP_UpdateCameraAndDraw  0x021888C8  thumb  ov021
 *   CLACT_DrawSystem  0x0204A600  arm
 *   func_02035648  0x02035648  arm
 *   FIELDMAP_UpdateZoneChange  0x021892CC  thumb  ov021
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   FIELD_CLOCK_Update  0x02168EEC  thumb  ov010
 *   FIELD_PLACE_NAME_Main  0x021BC484  thumb  ov021
 *   FIELDSKILL_MAPEFF_Update  0x021C7FAC  thumb  ov021
 *   FIELD_PLAYER_SaveToPlayerWork  0x021A2EB8  thumb  ov021
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   UNION_MAIN_UpdateField  0x021737A4  thumb  ov012
 *   INTRUDE_FIELD_Update  0x0217AE20  thumb  ov018
 *   FIELD_SUBSCREEN_Main  0x021A0D68  thumb  ov021
 *   FLDMMDL_UpdateSysProc  0x0216CD64  thumb  ov010
 *   FIELD_GIMMICK_RunMapCallback  0x021BE258  thumb  ov021
 *   FIELD_EFFECT_Update  0x021ABE04  thumb  ov021
 *   EVENT_COMM_COMMON_CmdCallMissionInfoEvent  0x0217F914  thumb  ov018
 *   FIELD_SUBPROC_MGR_RunUpdate  0x021BB948  thumb  ov021
 *   FIELD_MSGBG_Main  0x021903E0  thumb  ov021
 *   func_02030D28  0x02030D28  arm
 *   FIELD_TASK_MANAGER_Update  0x021C6D90  thumb  ov021
 *   FIELD_G3D_MAPPER_SetFocusPos  0x0218D158  thumb  ov021
 *   FIELDMAP_UpdateG3d  0x02189004  thumb  ov021
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   PLEASURE_BOAT_AckEvent  0x021C8660  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00518.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w[3];
} Rec12;

struct BigObj;
struct Ctx;
struct Obj;
struct Sub02014444Obj;
struct T;
struct V3;
extern u32 GAMESYSTEM_GetEvent(const struct Ctx *p);
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern void FIELDMAP_UpdateCameraAndDraw(char *o);
extern void CLACT_DrawSystem(void);
extern void func_02035648(void);
extern u32 FIELDMAP_UpdateZoneChange(u8 *a);
extern int GAMESYSTEM_IsEventActive(char *a);
extern void FIELD_CLOCK_Update(int a);
extern void FIELD_PLACE_NAME_Main(u32 a);
extern void FIELDSKILL_MAPEFF_Update(u32 a);
extern void FIELD_PLAYER_SaveToPlayerWork(u32 *a);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern void UNION_MAIN_UpdateField(void *a, int b);
extern void INTRUDE_FIELD_Update(u8 *a0, int a1, int a2);
extern void FIELD_SUBSCREEN_Main(u32 *a);
extern int FLDMMDL_UpdateSysProc(int a0);
extern void FIELD_GIMMICK_RunMapCallback(void *p);
extern void FIELD_EFFECT_Update(u32 a);
extern void EVENT_COMM_COMMON_CmdCallMissionInfoEvent(u32 a);
extern void FIELD_SUBPROC_MGR_RunUpdate(u8 *p);
extern void FIELD_MSGBG_Main(struct Obj *o);
extern void func_02030D28(struct Ctx *c);
extern void FIELD_TASK_MANAGER_Update(u8 *p);
extern void FIELD_G3D_MAPPER_SetFocusPos(struct T *dst, const struct V3 *src);
extern void FIELDMAP_UpdateG3d(u8 *p);
extern u32 *GAME_DATA_GetEventState(u32 a);
extern void PLEASURE_BOAT_AckEvent(u32 a);

int FIELDMAP_SeqUpdate(void *a, u8 *p)
{
    if (GAMESYSTEM_GetEvent((const struct Ctx *)(((struct Obj00518 *)p)->f4)) == 0)
        func_0201447C(GAME_DATA_GetMoveModelSys((const struct BigObj *)(((struct Obj00518 *)p)->f8)), 0);
    if (GAME_DATA_IsSaving((const u8 *)(((struct Obj00518 *)p)->f8)) != 0)
        return 0;
    if (((struct Obj00518 *)p)->f140 != 0) {
        FIELDMAP_UpdateCameraAndDraw((char *)p);
        CLACT_DrawSystem();
        return 0;
    }
    func_02035648();
    FIELDMAP_UpdateZoneChange(p);
    if (GAMESYSTEM_IsEventActive(a) == 0) {
        (*(void (**)(u8 *, void *))(*(u8 **)(p + 0x108) + 8))(p, p + 0xF4);
        FIELD_CLOCK_Update(((struct Obj00518 *)p)->f8);
    }
    if (((struct Obj00518 *)p)->f30 != 0)
        FIELD_PLACE_NAME_Main(((struct Obj00518 *)p)->f30);
    FIELDSKILL_MAPEFF_Update(((struct Obj00518 *)p)->fA0);
    FIELD_PLAYER_SaveToPlayerWork((u32 *)(((struct Obj00518 *)p)->f8C));
    if (func_02013CC8(((struct Obj00518 *)p)->fD0) == 1 || func_02013CE0(((struct Obj00518 *)p)->fD0) == 1)
        UNION_MAIN_UpdateField((void *)((void *)GAMESYSTEM_GetGameComm(a)), (int)p);
    else
        INTRUDE_FIELD_Update((u8 *)p, ((struct Obj00518 *)p)->f4, ((struct Obj00518 *)p)->f8C);
    FIELD_SUBSCREEN_Main((u32 *)(((struct Obj00518 *)p)->f24));
    if (((struct Obj00518 *)p)->f38 != 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        FLDMMDL_UpdateSysProc(((struct Obj00518 *)p)->f38);
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    FIELD_GIMMICK_RunMapCallback(p);
    FIELD_EFFECT_Update(((struct Obj00518 *)p)->f94);
    if (((struct Obj00518 *)p)->f98 != 0)
        EVENT_COMM_COMMON_CmdCallMissionInfoEvent(((struct Obj00518 *)p)->f98);
    FIELD_SUBPROC_MGR_RunUpdate((u8 *)(((struct Obj00518 *)p)->fBC));
    if (((struct Obj00518 *)p)->f28 != 0)
        FIELD_MSGBG_Main((struct Obj *)(((struct Obj00518 *)p)->f28));
    func_02030D28((struct Ctx *)(((struct Obj00518 *)p)->f110));
    FIELD_TASK_MANAGER_Update((u8 *)(((struct Obj00518 *)p)->f134));
    if (*(Rec12 * *)&((struct Obj00518 *)p)->fF0 != 0)
        *(Rec12 *)(p + 0xF4) = **(Rec12 * *)&((struct Obj00518 *)p)->fF0;
    FIELD_G3D_MAPPER_SetFocusPos((struct T *)(((struct Obj00518 *)p)->f48), (const struct V3 *)(p + 0xF4));
    FIELDMAP_UpdateG3d(p);
    PLEASURE_BOAT_AckEvent(*GAME_DATA_GetEventState(((struct Obj00518 *)p)->f8));
    CLACT_DrawSystem();
    FIELDMAP_UpdateCameraAndDraw((char *)p);
    return 0;
}
