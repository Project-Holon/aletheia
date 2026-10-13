/*
 * function: FIELD_GIMMICK_SWITCH_TOGGLE_Init
 * address:  0x021F36C0
 * packet:   pkt_ov045_021F36C0
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The BE480 result goes through the local e: assigning through the call
 * directly schedules the i*12 table offset before the call.
 *
 * symbols:
 *   sSwitchToggleUnitDesc     0x021F3B50  data  ov045
 *   sSwitchTogglePrimaryModelPos     0x021F3B80  data  ov045  a4
 *   sSwitchToggleSecondaryModelPos     0x021F3BA4  data  ov045  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FIELD_GIMMICK_SWITCH_TOGGLE_SetSwitchModelPose  0x021F3938  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int sSwitchToggleUnitDesc;
extern V sSwitchTogglePrimaryModelPos[];
extern V sSwitchToggleSecondaryModelPos[];

struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Big;
extern unsigned char *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *p, void *a, int b);
extern V    *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void  FIELD_GIMMICK_SWITCH_TOGGLE_SetSwitchModelPose(void *a0, int a1, int a2, int a3);

void FIELD_GIMMICK_SWITCH_TOGGLE_Init(void *a0)
{
    void *r4;
    int *q;
    int i;
    int j;
    int k;
    void *b;
    V *e;

    r4 = (void *)FIELDMAP_GetExpObj(a0);
    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave((struct Big *)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0))), 9);
    FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 4);
    FLD_EXP_OBJ_AddUnitFromArchive(r4, &sSwitchToggleUnitDesc, 0);
    for (i = 0; i < 3; i++) {
        e = FLD_EXP_OBJ_GetModelStatus(r4, 0, i);
        *e = sSwitchTogglePrimaryModelPos[i];
        FLD_EXP_OBJ_SetModelCullDraw(r4, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            b = FLD_EXP_OBJ_GetAnime(r4, 0, i, j);
            FLD_EXP_OBJ_SetAnimeLoop(b, 0);
            FLD_EXP_OBJ_SetAnimePaused(b, 1);
        }
        k = i + 3;
        e = FLD_EXP_OBJ_GetModelStatus(r4, 0, k);
        *e = sSwitchToggleSecondaryModelPos[i];
        FLD_EXP_OBJ_SetModelCullDraw(r4, 0, (u16)k, 1);
        for (j = 0; j < 2; j++) {
            b = FLD_EXP_OBJ_GetAnime(r4, 0, k, j);
            FLD_EXP_OBJ_SetAnimeLoop(b, 0);
            FLD_EXP_OBJ_SetAnimePaused(b, 1);
        }
        FIELD_GIMMICK_SWITCH_TOGGLE_SetSwitchModelPose(r4, q[i], i, 1);
        FIELD_GIMMICK_SWITCH_TOGGLE_SetSwitchModelPose(r4, q[i], i, 0);
    }
}
