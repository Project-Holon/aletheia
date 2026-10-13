/*
 * function: FIELD_GIMMICK_62_Init
 * address:  0x021F36C0
 * packet:   pkt_ov062_021F36C0
 * region:   ov062
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   d_021F3768     0x021F3768  data  a4
 *   d_021F3790     0x021F3790  data  a4
 */

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern V3 d_021F3768;
extern V3 d_021F3790;

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int a, void *b, int c);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);

void FIELD_GIMMICK_62_Init(int a)
{
    int *q;
    int s;

    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))), 0x34);
    s = FIELDMAP_GetExpObj((int *)a);
    FLD_EXP_OBJ_AddUnitFromArchive(s, &d_021F3768, 0);
    *(V3 *)FLD_EXP_OBJ_GetModelStatus((char *)s, 0, 0) = d_021F3790;
    FLD_EXP_OBJ_SetModelCullDraw((char *)s, 0, 0, 1);
    FLD_EXP_OBJ_SetAnimeEnabled((void *)s, 0, 0, 0, 1);
    if (*q != 0)
        FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 0, 1);
}
