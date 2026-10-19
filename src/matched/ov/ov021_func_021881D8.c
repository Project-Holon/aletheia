/*
 * function: FIELDMAP_SeqCreateSubsystems
 * address:  0x021881D8
 * packet:   pkt_ov021_021881D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELD_MAP_CHANGE_Empty  0x0216447C  thumb  ov010
 *   FIELD_MSGBG_Create  0x021901EC  thumb  ov021
 *   FIELD_PLACE_NAME_Create  0x021BC388  thumb  ov021
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetMapEffectMask  0x02014470  thumb
 *   FIELDSKILL_MAPEFF_Create  0x021C7F70  thumb  ov021
 *   ZONEDATA_GetCameraId  0x02013BBC  thumb
 *   FIELD_CAMERA_Create  0x0218E018  thumb  ov021
 *   FLD_SCENEAREA_Create  0x021AB5F4  thumb  ov021
 *   FLD_SCENEAREA_LOADER_Create  0x021AB7E4  thumb  ov021
 *   FIELD_NOGRID_MAPPER_Create  0x021BB1F4  thumb  ov021
 *   FIELD_PALACE_SYS_Create  0x021D33A8  thumb  ov021
 *   FIELD_G3D_MAPPER_GetBuildModel  0x0218DC6C  thumb  ov021
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   FIELDMAP_SetupMapperParam  0x02189B30  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   FIELD_PALACE_SYS_GetPalTable  0x021D33F8  thumb  ov021
 *   FIELD_BUILDMODEL_LoadArea  0x0218B8AC  thumb  ov021
 *   FIELD_G3DOBJ_SetPalTable  0x021C6534  thumb  ov021
 *   FIELDMAP_SetupWfbc  0x02189614  thumb  ov021
 *   ZONEDATA_SetExitLocation  0x02014110  thumb
 *   FIELD_G3D_MAPPER_Setup  0x0218CEE4  thumb  ov021
 *   ZONEDATA_GetSpecialKind  0x02013C9C  thumb
 *   FIELD_NOGRID_MAPPER_LoadDataFromArc  0x021BB2F8  thumb  ov021
 *   FIELDMAP_GetProjDepthOffset  0x02189ACC  thumb  ov021
 *   FIELDMAP_SetupCameraArea  0x021895E8  thumb  ov021
 *   FIELDMAP_SetupMmdlSys  0x02189204  thumb  ov021
 *   FIELD_EFFECT_Create  0x021ABD50  thumb  ov021
 *   FIELD_EFFECT_InitObjectSystem  0x021ABF68  thumb  ov021
 *   FIELD_EFFECT_SetPaletteTable  0x021AC1EC  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   sFieldEffectTaskCount     0x021D8F00  data
 *   sFieldEffectTaskTable     0x021D8F10  data
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   UNION_EFF_Create  0x0217F8C0  thumb  ov019
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   ZONEDATA_IsBikeEnabled  0x02013C20  thumb
 *   GAME_DATA_SetPlayerObjectCode  0x02012B2C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   FIELD_PLAYER_Create  0x021A2E50  thumb  ov021
 *   FIELD_G3D_MAPPER_SetFocusPos  0x0218D158  thumb  ov021
 *   FIELDMAP_InitCommonWork  0x02189758  thumb  ov021
 *   FLD_EXP_OBJ_Create  0x021BE2A8  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_SetupEdgeMarking  0x02189154  thumb  ov021
 *   FIELD_FOG_Create  0x021A0104  thumb  ov021
 *   FIELD_ZONEFOG_Create  0x021A02C4  thumb  ov021
 *   ZONEDATA_GetFogId  0x02013EEC  thumb
 *   ZONEDATA_GetLightId  0x02013F2C  thumb
 *   FIELD_ZONEFOG_SetUp  0x021A0338  thumb  ov021
 *   ZONEDATA_GetAreaLightType  0x020140DC  thumb
 *   GF_STANDARD_GetSecondsOfDay  0x0203F4FC  arm
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   FIELD_LIGHT_Create  0x021A03D0  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   WEATHER_Create  0x021A19E8  thumb  ov021
 *   GAME_DATA_GetWeatherId  0x02012994  thumb
 *   WEATHER_SetImmediate  0x021A1B74  thumb  ov021
 *   FIELD_GIMMICK_Setup  0x021BE1DC  thumb  ov021
 *   GAME_DATA_GetSubscreenType  0x020129AC  thumb
 *   FIELD_SUBSCREEN_Create  0x021A0CF4  thumb  ov021
 *   FIELD_ENCOUNT_Create  0x021A9ED8  thumb  ov021
 *   GAME_COMM_CallHandler  0x02026388  thumb
 *   FIELD_SUBPROC_MGR_Create  0x021BB890  thumb  ov021
 *   FLD_PARTICLE_Create  0x021C1A08  thumb  ov021
 *   FLD3D_CI_Create  0x021C1AF4  thumb  ov021
 *   ENCEFF_Create  0x021CF45C  thumb  ov021
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   DAYCARE_GetFromSave  0x0200BDB0  thumb
 *   SODATEYA_Create  0x021C31D4  thumb  ov021
 *   FIELDMAP_SetupSceneArea  0x02189684  thumb  ov021
 */
#include "../include/Obj00571.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} V3;

typedef struct {
    void *f0;
    void (*f4)(char *p, V3 *v, int c);
} Ops;

extern int sFieldEffectTaskCount;
extern int sFieldEffectTaskTable[];

struct Ctx;
struct Big;
struct BigObj;
struct Obj;
struct Rec44;
struct Src;
struct Sub0200852CObj;
struct Sub020140BCObj;
struct Sub02014444Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void FIELD_MAP_CHANGE_Empty(int sys, u16 id);
extern u8 *FIELD_MSGBG_Create(u16 heap, u32 b);
extern int FIELD_PLACE_NAME_Create(int a, int b, int c);
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern u16 FIELD_STATUS_GetMapEffectMask(struct Sub02014444Obj *o);
extern int FIELDSKILL_MAPEFF_Create(int flags, u16 heap);
extern u8 ZONEDATA_GetCameraId(u32 id);
struct Light;
extern char *FIELD_CAMERA_Create(int a0, int a1, struct Light *a2, int a3, u16 heap);
extern int FLD_SCENEAREA_Create(u16 heap, int a, void *b);
extern int FLD_SCENEAREA_LOADER_Create(u16 heap);
extern u32 *FIELD_NOGRID_MAPPER_Create(u32 a, u32 b, u32 c, u32 d);
extern void *FIELD_PALACE_SYS_Create(u16 heapId, void *a1, void *a2, u16 a3);
extern u32 FIELD_G3D_MAPPER_GetBuildModel(u8 *p);
extern u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
extern void FIELDMAP_SetupMapperParam(int a, int x, char *out, void *obj);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern void *FIELD_PALACE_SYS_GetPalTable(u32 *p);
extern void FIELD_BUILDMODEL_LoadArea(char *p, int a, int b, int c);
extern void FIELD_G3DOBJ_SetPalTable(u32 *p, u32 v);
extern void FIELDMAP_SetupWfbc(void *p, char *q, u16 id);
extern void ZONEDATA_SetExitLocation(void *p, u16 a, int b, int c, int d, int e, int f, int g);
extern void FIELD_G3D_MAPPER_Setup(struct Obj *p, const struct Src *src, void *c);
extern int ZONEDATA_GetSpecialKind(u16 key);
extern void FIELD_NOGRID_MAPPER_LoadDataFromArc(u32 a, u32 b, u32 c);
extern int FIELDMAP_GetProjDepthOffset(u32 a0);
struct T;
struct V3;
extern void FIELDMAP_SetupCameraArea(unsigned char *p, int id, int c);
extern void FIELDMAP_SetupMmdlSys(u8 *a);
extern char *FIELD_EFFECT_Create(int a, int b, u16 c);
extern void FIELD_EFFECT_InitObjectSystem(int t, int n);
extern void FIELD_EFFECT_SetPaletteTable(u32 *p, u32 v);
extern void FIELD_EFFECT_LoadResources(int t, int *arr, int n);
extern u32 ZONEDATA_IsUnionRoom(u32 id);
extern u32 ZONEDATA_IsZone96Pair(u32 id);
extern void *UNION_EFF_Create(u16 id);
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *a);
extern u32 GAME_DATA_GetPlayerDirectionType(const struct Rec44 *p);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct Rec44 *p);
extern u32 ZONEDATA_IsBikeEnabled(u32 id);
extern void GAME_DATA_SetPlayerObjectCode(struct Rec44 *p, u32 v);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 *FIELD_PLAYER_Create(int a, u32 b, int c, int d, u16 heap);
extern void FIELD_G3D_MAPPER_SetFocusPos(struct T *dst, const struct V3 *src);
extern void FIELDMAP_InitCommonWork(int *p);
extern int FLD_EXP_OBJ_Create(int a, int b, u16 heap);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void FIELDMAP_SetupEdgeMarking(void *a, u32 b);
extern u8 *FIELD_FOG_Create(u16 heap);
extern u8 *FIELD_ZONEFOG_Create(u16 heap);
extern u32 ZONEDATA_GetFogId(u32 id);
extern u32 ZONEDATA_GetLightId(u32 id);
extern void FIELD_ZONEFOG_SetUp(u8 *p, u32 id, u32 c, u8 d);
extern u8 ZONEDATA_GetAreaLightType(struct Sub020140BCObj *p);
extern u32 GF_STANDARD_GetSecondsOfDay(void);
extern int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
extern u8 *FIELD_LIGHT_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern int WEATHER_Create(int a0, int a1, int a2, int a3, int a4, int a5, int heap);
extern u8 GAME_DATA_GetWeatherId(const struct BigObj *p);
extern void WEATHER_SetImmediate(u8 *p, int a, int f);
extern void FIELD_GIMMICK_Setup(void *arg);
extern u8 GAME_DATA_GetSubscreenType(const struct BigObj *p);
extern u32 *FIELD_SUBSCREEN_Create(u32 a, u32 b, u32 c);
extern u32 *FIELD_ENCOUNT_Create(u32 a);
extern void GAME_COMM_CallHandler(struct Obj *p, u32 a);
extern int *FIELD_SUBPROC_MGR_Create(int a, int b, int n);
extern u32 *FLD_PARTICLE_Create(u32 a);
extern u32 *FLD3D_CI_Create(u32 a, u32 b);
extern void *ENCEFF_Create(u32 heap, u32 v);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *DAYCARE_GetFromSave(void *sys);
extern int SODATEYA_Create(u16 heap, void *a, int b);
extern void FIELDMAP_SetupSceneArea(char *p, unsigned int id);

#define F16(o)  (*(u16 *)(p + (o)))
#define F32(o)  (*(int *)(p + (o)))

int FIELDMAP_SeqCreateSubsystems(int a, char *p)
{
    int sys = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    int flag = 1;

    switch (((struct Obj00571 *)p)->fC8) {
    case 0: {
        int x;
        FIELD_MAP_CHANGE_Empty(sys, F16(0xd0));
        x = (int)FIELD_MSGBG_Create(F16(0), F32(0xa4));
        F32(0x2c) = 0;
        F32(0x28) = x;
        F32(0x30) = FIELD_PLACE_NAME_Create(a, 0x93, x);
        F32(0xa0) = FIELDSKILL_MAPEFF_Create(FIELD_STATUS_GetMapEffectMask(GAME_DATA_GetMoveModelSys((const struct BigObj *)F32(8))), F16(0));
        F32(0x10) = (int)FIELD_CAMERA_Create(ZONEDATA_GetCameraId(F16(0xd0)), 0, (struct Light *)F32(0xa4), (int)(p + 0xf4), F16(0));
        F32(0x40) = FLD_SCENEAREA_Create(F16(0), F32(0x10), p);
        F32(0x44) = FLD_SCENEAREA_LOADER_Create(F16(0));
        break;
    }
    case 1: {
        int m;
        int t;
        F32(0x3c) = (int)FIELD_NOGRID_MAPPER_Create(F16(0), F32(0x10), F32(0x40), F32(0x44));
        F32(0x9c) = (int)FIELD_PALACE_SYS_Create(F16(0), (void *)a, p, F16(0xd0));
        m = FIELD_G3D_MAPPER_GetBuildModel((u8 *)F32(0x48));
        FIELDMAP_SetupMapperParam(F16(0xd0), F32(0xc), p + 0x50, (void *)GAME_DATA_GetFieldWork((const struct BigObj *)F32(8)));
        GAMESYSTEM_GetGameComm((const struct Ctx *)F32(4));
        t = (int)FIELD_PALACE_SYS_GetPalTable((u32 *)F32(0x9c));
        FIELD_BUILDMODEL_LoadArea((char *)m, F16(0xd0), F32(0xc), t);
        FIELD_G3DOBJ_SetPalTable((u32 *)F32(0x130), t);
        FIELDMAP_SetupWfbc((void *)sys, p, F16(0xd0));
        break;
    }
    case 2: {
        int v;
        ZONEDATA_SetExitLocation(p + 0xd4, F16(0xd0), 0, 0, 0, F32(0xf4), F32(0xf8), F32(0xfc));
        GAMESYSTEM_GetGameComm((const struct Ctx *)F32(4));
        FIELD_G3D_MAPPER_Setup((struct Obj *)F32(0x48), (const struct Src *)(p + 0x50), FIELD_PALACE_SYS_GetPalTable((u32 *)F32(0x9c)));
        v = ZONEDATA_GetSpecialKind(F16(0xd0));
        if (v != -1) {
            FIELD_NOGRID_MAPPER_LoadDataFromArc(F32(0x3c), v, F16(0));
        }
        F32(0x104) = FIELDMAP_GetProjDepthOffset(F16(0xd0));
        FIELDMAP_SetupCameraArea((unsigned char *)p, (u16)F16(0xd0), (u16)F16(0));
        break;
    }
    case 3:
        FIELDMAP_SetupMmdlSys((u8 *)p);
        F32(0x94) = (int)FIELD_EFFECT_Create((int)p, 0x18, F16(0));
        FIELD_EFFECT_InitObjectSystem(F32(0x94), 0x5e);
        FIELD_EFFECT_SetPaletteTable((u32 *)F32(0x94), (u32)FIELD_PALACE_SYS_GetPalTable((u32 *)F32(0x9c)));
        FIELD_EFFECT_LoadResources(F32(0x94), sFieldEffectTaskTable, sFieldEffectTaskCount);
        if (ZONEDATA_IsUnionRoom(F16(0xd0)) == 1 || ZONEDATA_IsZone96Pair(F16(0xd0)) == 1) {
            F32(0x98) = (int)UNION_EFF_Create(F16(0));
        }
        break;
    case 4: {
        int w;
        int k;
        V3 *pos;
        int r;
        int g;
        w = (int)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)a);
        k = GAME_DATA_GetPlayerDirectionType((const struct Rec44 *)w);
        pos = (V3 *)(w + 4);
        if (GAME_DATA_GetPlayerObjectCode((const struct Rec44 *)w) == 1 && ZONEDATA_IsBikeEnabled(F16(0xd0)) == 0) {
            GAME_DATA_SetPlayerObjectCode((struct Rec44 *)w, 0);
        }
        F32(0x8c) = (int)FIELD_PLAYER_Create(w, (u32)p, (int)pos, func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus((void *)sys)), F16(0));
        *(V3 *)(p + 0xf4) = *pos;
        (*(Ops **)(p + 0x108))->f4(p, (V3 *)(p + 0xf4), k);
        FIELD_G3D_MAPPER_SetFocusPos((struct T *)F32(0x48), (const struct V3 *)(p + 0xf4));
        FIELDMAP_InitCommonWork((int *)(p + 0x118));
        F32(0x34) = FLD_EXP_OBJ_Create(0x3c, 0x23, F16(0));
        FIELDMAP_SetupEdgeMarking((void *)F32(0xc), (int)FIELDMAP_GetZoneId((u8 *)p));
        F32(0x18) = (int)FIELD_FOG_Create(F16(0));
        F32(0x1c) = (int)FIELD_ZONEFOG_Create(F16(0));
        r = ZONEDATA_GetFogId(F16(0xd0));
        FIELD_ZONEFOG_SetUp((u8 *)F32(0x1c), r, ZONEDATA_GetLightId(F16(0xd0)), 1);
        r = ZONEDATA_GetAreaLightType((struct Sub020140BCObj *)F32(0xc));
        g = GF_STANDARD_GetSecondsOfDay();
        F32(0x14) = (int)FIELD_LIGHT_Create(r, g, COMM_PLAYER_SUPPORT_GetInfoCode((void *)a), F32(0x18), F32(0xa8), F16(0));
        r = GAME_DATA_GetBgmInfo((const struct BigObj *)F32(8));
        F32(0x20) = WEATHER_Create(F32(0x10), F32(0x14), F32(0x18), F32(0x1c), r, COMM_PLAYER_SUPPORT_GetInfoCode((void *)a), 0x92);
        WEATHER_SetImmediate((u8 *)F32(0x20), (u16)((int)GAME_DATA_GetWeatherId((const struct BigObj *)F32(8))), 0x92);
        FIELD_GIMMICK_Setup(p);
        break;
    }
    case 5:
        F32(0x24) = (int)FIELD_SUBSCREEN_Create(F16(0), (u32)p, GAME_DATA_GetSubscreenType((const struct BigObj *)sys));
        break;
    case 6:
        F32(0x90) = (int)FIELD_ENCOUNT_Create((u32)p);
        GAME_COMM_CallHandler((struct Obj *)GAMESYSTEM_GetGameComm((const struct Ctx *)a), (u32)p);
        F32(0xbc) = (int)FIELD_SUBPROC_MGR_Create((int)p, F16(0), 0x20);
        F32(0x120) = (int)FLD_PARTICLE_Create(0x50);
        F32(0x124) = (int)FLD3D_CI_Create(0x50, F32(0x120));
        F32(0x13c) = (int)ENCEFF_Create(F16(0), (u32)p);
        F32(0x128) = SODATEYA_Create(F16(0), p, (int)DAYCARE_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)F32(8))));
        FIELDMAP_SetupSceneArea(p, F16(0xd0));
        flag = 0;
        break;
    }
    (((struct Obj00571 *)p)->fC8)++;
    F32(0x12c) = 0;
    return flag == 0;
}
