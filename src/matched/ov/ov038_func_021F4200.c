/*
 * function: GIMMICK38_EventPressSwitch
 * address:  0x021F4200
 * packet:   pkt_ov038_021F4200
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the case-0 byte must be held in a u8 (or u16) local: an int local
 *           swaps the 0x0201210C result and the 0x021897BC pointer between r4
 *           and r5.  GAME_EVENT_GetGameSystem/GAMESYSTEM_GetFieldMap are argless as in the twin
 *           ov045_func_021F39B8.  FLD_EXP_OBJ_SetAnimeEnabled/FLD_EXP_OBJ_GetAnime take their
 *           fourth argument as u16 (the caller truncates it before the bl).
 *           FLD_EXP_OBJ_GetAnime's third parameter must be `int` here, as for
 *           FLD_EXP_OBJ_SetAnimeEnabled: its own file's `unsigned int j` brings the r4/r5
 *           swap back even with the u8 local.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   GIMMICK_WORK_GetProgress 0x0200B3A8 thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern u32 FIELDMAP_GetGameSystem(u8 *p);
struct Big;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
struct Rec94;
extern u8 *GIMMICK_WORK_GetProgress(struct Rec94 *p, u32 a1);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, int j, u16 k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);

int GIMMICK38_EventPressSwitch(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    int *p;
    unsigned int t;
    unsigned short *q;
    int i;
    u8 c;

    sys = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem((void *)a0));
    h = FIELDMAP_GetExpObj(sys);
    s = (u8 *)FIELDMAP_GetCommonWork(sys, 1);
    t = (unsigned int)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(sys)));
    p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)t, 6);
    q = (short unsigned int *)GIMMICK_WORK_GetProgress((struct Rec94 *)t, 6);
    switch (*a1) {
    case 0:
        c = *s;
        for (i = 0; i < 2; i++) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, c, (u16)i, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, c, i), 0);
        }
        *a1 = *a1 + 1;
        break;
    case 1:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime((char *)h, 0, *s, 0))) {
            p[*s] = 1;
            q[*s] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
