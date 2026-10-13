/*
 * function: FIELDMAP_SeqDeleteSubsystems
 * address:  0x02188990
 * packet:   pkt_ov021_02188990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENCEFF_Delete  0x021CF480  thumb  ov021
 *   FLD3D_CI_Delete  0x021C1C04  thumb  ov021
 *   FLD_PARTICLE_Delete  0x021C1AD0  thumb  ov021
 *   func_0201209C  0x0201209C  thumb
 *   FIELD_PLAYER_SaveToPlayerWork  0x021A2EB8  thumb  ov021
 *   FIELD_SUBPROC_MGR_Delete  0x021BB90C  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_CallKindNotify  0x020263B0  thumb
 *   FIELD_PLACE_NAME_Delete  0x021BC424  thumb  ov021
 *   FIELD_GIMMICK_Exit  0x021BE218  thumb  ov021
 *   FLD_EXP_OBJ_Delete  0x021BE2E0  thumb  ov021
 *   FIELD_ENCOUNT_Delete  0x021A9F28  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELD_SUBSCREEN_Delete  0x021A0D44  thumb  ov021
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FIELD_EFFECT_Delete  0x021ABDE8  thumb  ov021
 *   UNION_EFF_Delete  0x0217F8EC  thumb  ov019
 *   WEATHER_Delete  0x021A1AAC  thumb  ov021
 *   FIELD_LIGHT_Delete  0x021A0448  thumb  ov021
 *   FIELD_ZONEFOG_Delete  0x021A02F4  thumb  ov021
 *   FIELD_FOG_Delete  0x021A0138  thumb  ov021
 *   FIELD_PALACE_SYS_Delete  0x021D33E0  thumb  ov021
 *   FIELD_NOGRID_MAPPER_Delete  0x021BB240  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Delete  0x021AB81C  thumb  ov021
 *   FLD_SCENEAREA_Delete  0x021AB624  thumb  ov021
 *   FIELD_CAMERA_Delete  0x0218E0E4  thumb  ov021
 *   FIELDMAP_ClearCtrlWork  0x021895DC  thumb  ov021
 *   FIELDMAP_DeleteMmdlSys  0x021892B4  thumb  ov021
 *   FIELD_PLAYER_Delete  0x021A2E90  thumb  ov021
 *   FIELD_G3D_MAPPER_ReleaseBlocks  0x0218D05C  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   FIELD_MSGBG_Delete  0x021902BC  thumb  ov021
 *   GAME_DATA_SetWalkCountEnable  0x020129DC  thumb
 *   func_02035660  0x02035660  arm
 *   SODATEYA_Delete  0x021C31FC  thumb  ov021
 *   FIELDSKILL_MAPEFF_Delete  0x021C7F9C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00401.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Obj;
extern int ENCEFF_Delete(void *a);
extern void FLD3D_CI_Delete(u32 *p);
extern void FLD_PARTICLE_Delete(u32 a);
extern void func_0201209C(void *o, u32 v1, u32 v2);
extern void FIELD_PLAYER_SaveToPlayerWork(u32 *a);
extern void FIELD_SUBPROC_MGR_Delete(u32 a);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern void GAME_COMM_CallKindNotify(struct Obj *p, u32 a);
extern void FIELD_PLACE_NAME_Delete(u32 a);
extern void FIELD_GIMMICK_Exit(void *arg);
extern void FLD_EXP_OBJ_Delete(u32 a);
extern void FIELD_ENCOUNT_Delete(u32 a);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 FIELD_SUBSCREEN_Delete(u32 *p);
extern void GAME_DATA_SetSubscreenType(struct BigObj *p, u32 v);
extern void FIELD_EFFECT_Delete(u32 a);
extern void UNION_EFF_Delete(char *p);
extern void WEATHER_Delete(u8 *p);
extern void FIELD_LIGHT_Delete(u8 *p);
extern int FIELD_ZONEFOG_Delete(void *a);
extern void FIELD_FOG_Delete(u32 a);
extern void FIELD_PALACE_SYS_Delete(u32 *p);
extern int FIELD_NOGRID_MAPPER_Delete(u32 a);
extern void FLD_SCENEAREA_LOADER_Delete(u32 a);
extern void FLD_SCENEAREA_Delete(u8 *p);
extern void FIELD_CAMERA_Delete(u8 *a);
extern int FIELDMAP_ClearCtrlWork(u32 a);
extern int FIELDMAP_DeleteMmdlSys(u8 *a);
extern int FIELD_PLAYER_Delete(void *a);
extern void FIELD_G3D_MAPPER_ReleaseBlocks(char *p);
extern int FIELD_MSGBG_DeleteMsgWin(void *a);
extern void FIELD_MSGBG_Delete(struct Obj *o);
extern void GAME_DATA_SetWalkCountEnable(struct BigObj *p, u8 v);
extern void func_02035660(u32 a);
extern void SODATEYA_Delete(u32 a);
extern void FIELDSKILL_MAPEFF_Delete(u8 *p);

int FIELDMAP_SeqDeleteSubsystems(void *a, u8 *p)
{
    ENCEFF_Delete((void *)(((struct Obj00401 *)p)->f13C));
    FLD3D_CI_Delete((u32 *)(((struct Obj00401 *)p)->f124));
    FLD_PARTICLE_Delete(((struct Obj00401 *)p)->f120);
    func_0201209C(a, 0, 0);
    FIELD_PLAYER_SaveToPlayerWork((u32 *)(((struct Obj00401 *)p)->f8C));
    FIELD_SUBPROC_MGR_Delete(((struct Obj00401 *)p)->fBC);
    GAME_COMM_CallKindNotify((void *)GAMESYSTEM_GetGameComm(a), (u32)p);
    if (((struct Obj00401 *)p)->f30 != 0)
        FIELD_PLACE_NAME_Delete(((struct Obj00401 *)p)->f30);
    FIELD_GIMMICK_Exit(p);
    FLD_EXP_OBJ_Delete(((struct Obj00401 *)p)->f34);
    FIELD_ENCOUNT_Delete(((struct Obj00401 *)p)->f90);
    GAME_DATA_SetSubscreenType(GAMESYSTEM_GetGameData(a), FIELD_SUBSCREEN_Delete((u32 *)(((struct Obj00401 *)p)->f24)));
    FIELD_EFFECT_Delete(((struct Obj00401 *)p)->f94);
    if (((struct Obj00401 *)p)->f98 != 0) {
        UNION_EFF_Delete((char *)(((struct Obj00401 *)p)->f98));
        ((struct Obj00401 *)p)->f98 = 0;
    }
    WEATHER_Delete((u8 *)(((struct Obj00401 *)p)->f20));
    ((struct Obj00401 *)p)->f20 = 0;
    FIELD_LIGHT_Delete((u8 *)(((struct Obj00401 *)p)->f14));
    FIELD_ZONEFOG_Delete((void *)(((struct Obj00401 *)p)->f1C));
    FIELD_FOG_Delete(((struct Obj00401 *)p)->f18);
    FIELD_PALACE_SYS_Delete((u32 *)(((struct Obj00401 *)p)->f9C));
    FIELD_NOGRID_MAPPER_Delete(((struct Obj00401 *)p)->f3C);
    FLD_SCENEAREA_LOADER_Delete(((struct Obj00401 *)p)->f44);
    FLD_SCENEAREA_Delete((u8 *)(((struct Obj00401 *)p)->f40));
    FIELD_CAMERA_Delete((u8 *)(((struct Obj00401 *)p)->f10));
    (*(void (**)(u8 *))(*(u8 **)(p + 0x108) + 0xC))(p);
    FIELDMAP_ClearCtrlWork((u32)p);
    FIELDMAP_DeleteMmdlSys(p);
    FIELD_PLAYER_Delete((void *)(((struct Obj00401 *)p)->f8C));
    FIELD_G3D_MAPPER_ReleaseBlocks((char *)(((struct Obj00401 *)p)->f48));
    if (((struct Obj00401 *)p)->f2C != 0)
        FIELD_MSGBG_DeleteMsgWin((void *)(((struct Obj00401 *)p)->f2C));
    if (((struct Obj00401 *)p)->f28 != 0)
        FIELD_MSGBG_Delete((struct Obj *)(((struct Obj00401 *)p)->f28));
    GAME_DATA_SetWalkCountEnable(GAMESYSTEM_GetGameData(a), 0);
    func_02035660(0x3C);
    SODATEYA_Delete(((struct Obj00401 *)p)->f128);
    FIELDSKILL_MAPEFF_Delete((u8 *)(((struct Obj00401 *)p)->fA0));
    return 1;
}
