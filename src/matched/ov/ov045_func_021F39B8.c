/*
 * function: GIMMICK45_SecondarySwitchEventProc
 * address:  0x021F39B8
 * packet:   pkt_ov045_021F39B8
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   GIMMICK45_IsSwitchOn  0x021F39A8  thumb
 *   GIMMICK45_SetSwitchModelPose  0x021F3938  thumb
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */

typedef unsigned char u8;

struct Big;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int   GIMMICK45_IsSwitchOn(int *p, int i);
extern void  GIMMICK45_SetSwitchModelPose(void *a0, int a1, int a2, int a3);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);

int GIMMICK45_SecondarySwitchEventProc(void *a0, int *a1)
{
    void *r7;
    void *r6;
    int *s;
    int *p;
    int flag;
    int idx;
    u8 v;

    r7 = GAMESYSTEM_GetFieldMap(func_020124E4(a0));
    r6 = (void *)FIELDMAP_GetExpObj(r7);
    s = FIELDMAP_GetCommonWork(r7, 1);
    flag = 1;
    p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(r7))), 9);
    switch (*a1) {
    case 0:
        idx = s[0];
        v = GIMMICK45_IsSwitchOn(p, idx);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(r6, 0, (u8)(idx + 3), v), 0);
        *a1 = *a1 + 1;
        break;
    case 1:
        idx = s[0];
        v = GIMMICK45_IsSwitchOn(p, idx);
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(r6, 0, (u8)(idx + 3), v))) {
            if (p[s[0]]) {
                flag = 0;
            }
            GIMMICK45_SetSwitchModelPose(r6, flag, s[0], 0);
            return 1;
        }
        break;
    }
    return 0;
}
