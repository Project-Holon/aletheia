/*
 * function: GIMMICK45_SwitchToggleEventProc
 * address:  0x021F3A68
 * packet:   pkt_ov045_021F3A68
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: GIMMICK45_IsSwitchOn's result held in a u8 local k (truncated in place,
 * lsls r0 / lsrs r3, where passing the call inline copies it to r3 first);
 * f = 1 written after q's assignment (before it, it takes r0 and lands
 * after the copy of t). The extent past 0x021F3B36 is rodata.
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
 *   GIMMICK45_IsSwitchOn  0x021F39A8  thumb  ov045
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   GIMMICK45_SetSwitchModelPose  0x021F3938  thumb  ov045
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
struct Big;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int GIMMICK45_IsSwitchOn(int *p, int i);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void func_020061E4(u32 a);
extern void GFL_USE_StopAllSe(void);
extern void GIMMICK45_SetSwitchModelPose(void *a0, int a1, int a2, int a3);

int GIMMICK45_SwitchToggleEventProc(void *a, int *st)
{
    int f;
    void *s;
    u32 t;
    int *q;
    int *w;
    int i;
    u8 k;

    s = GAMESYSTEM_GetFieldMap(func_020124E4(a));
    t = FIELDMAP_GetExpObj(s);
    q = FIELDMAP_GetCommonWork(s, 1);
    f = 1;
    w = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 9);
    switch (*st) {
    case 0:
        i = *q;
        k = GIMMICK45_IsSwitchOn(w, i);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)t, 0, (u8)i, (u8)k), 0);
        func_020061E4(0x6d0);
        (*st)++;
        break;
    case 1:
        i = *q;
        k = GIMMICK45_IsSwitchOn(w, i);
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)t, 0, (u8)i, (u8)k))) {
            GFL_USE_StopAllSe();
            func_020061E4(0x6f0);
            if (w[*q] != 0)
                f = 0;
            GIMMICK45_SetSwitchModelPose((void *)t, f, *q, 1);
            w[*q] = w[*q] ? 0 : 1;
            return 1;
        }
        break;
    }
    return 0;
}
