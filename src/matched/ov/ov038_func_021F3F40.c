/*
 * function: GIMMICK38_EventBumpDoorSide
 * address:  0x021F3F40
 * packet:   pkt_ov038_021F3F40
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     k (0x021BE674/0x021BE700/0x021BE6CC fourth argument) is an enum
 *           local incremented as `k = (u8)(k + 1)`: a u8 local folds 2+1 to
 *           `movs #3`, and the enum keeps the unfolded adds plus truncation.
 *           Those callees take the enum through an `int` parameter; a u16
 *           parameter adds a second truncation before each bl.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K_0 } KType;

typedef struct {
    int a;
    int b;
    int c;
} V3;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct Big;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern V3 *FLD_EXP_OBJ_GetModelStatus(int p, int i, int j);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimeFrame(int p, int i, int j, int k, int flag);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);

int GIMMICK38_EventBumpDoorSide(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    int *p;
    u8 c;
    int j;
    KType k;
    void *e;
    V3 *src;

    sys = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)a0));
    h = FIELDMAP_GetExpObj(sys);
    s = (u8 *)FIELDMAP_GetCommonWork(sys, 1);
    FIELDMAP_GetFieldPlayer(sys);
    p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(sys))), 6);
    if (*(int *)((char *)p + s[3] * 4 + 0x48) == 0) {
        c = s[3] + 0x12;
        j = 0x21;
    } else {
        c = s[3] + 0x19;
        j = 0x22;
    }
    k = 2;
    if (s[6] == 1)
        k = (u8)(k + 1);
    e = FLD_EXP_OBJ_GetAnime((char *)h, 0, j, k);
    switch (*a1) {
    case 0:
        FLD_EXP_OBJ_SetModelHidden((char *)h, 0, c, 1);
        FLD_EXP_OBJ_SetModelHidden((char *)h, 0, j, 0);
        src = FLD_EXP_OBJ_GetModelStatus(h, 0, c);
        *FLD_EXP_OBJ_GetModelStatus(h, 0, j) = *src;
        FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, j, k, 1);
        FLD_EXP_OBJ_SetAnimePaused(e, 0);
        FLD_EXP_OBJ_SetAnimeFrame(h, 0, j, k, 0);
        GFL_USE_PlaySeDefaultVolume(0x6C5);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(e)) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, j, k, 0);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, j, 1);
            FLD_EXP_OBJ_SetModelHidden((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
