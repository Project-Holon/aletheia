/*
 * function: GIMMICK46_PlayAnimEventProc
 * address:  0x021F3DE8
 * packet:   pkt_ov046_021F3DE8
 * region:   ov046
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
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 */
#include "../include/Obj03644.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Big;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *a);
extern u8 *FIELDMAP_GetCommonWork(char *a, int b);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern void func_020061E4(u32 a);
extern void GFL_USE_StopAllSe(void);

int GIMMICK46_PlayAnimEventProc(void *a, int *st)
{
    void *s;
    u32 t;
    u8 *w;
    u8 k;
    int i;
    u8 v;

    s = GAMESYSTEM_GetFieldMap(func_020124E4(a));
    t = FIELDMAP_GetExpObj(s);
    w = FIELDMAP_GetCommonWork(s, 1) + 0xc;
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(s))), 10);
    switch (*st) {
    case 0:
        k = w[0];
        for (i = 0; i < w[2]; i++) {
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)t, 0, (u16)k, (u16)i), 1);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)t, 0, (u16)k, (u8)i, 0);
        }
        for (i = 0; i < w[1]; i++) {
            v = *(int *)(w + 0xc + i * 4);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)t, 0, (u16)k, (u16)v), 0);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)t, 0, (u16)k, (u8)v, 1);
            FLD_EXP_OBJ_SetAnimeFrame(t, 0, k, v, 0);
            func_020061E4(((struct Obj03644 *)w)->f10);
        }
        (*st)++;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)t, 0, (u16)w[0], (u16)(((struct Obj03644 *)w)->fC)))) {
            GFL_USE_StopAllSe();
            if (((struct Obj03644 *)w)->f14 != -1)
                func_020061E4(((struct Obj03644 *)w)->f14);
            return 1;
        }
        break;
    }
    return 0;
}
