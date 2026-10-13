/*
 * function: GIMMICK39_SwitchEventMain
 * address:  0x021F3E70
 * packet:   pkt_ov039_021F3E70
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     case 1 reads s->idx once into a local (int or s8; u8 differs);
 *           re-reading the field per call reloads it and shifts sys to r6.
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeFrame 0x021BE6CC thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   GIMMICK39_ApplySwitch 0x021F4740 thumb ov039
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[5];
    s8 idx;
    u8 mode;
} Work;

typedef struct {
    u8 pad0[0x10];
    u8 flag[8];
} Save;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern Work *FIELDMAP_GetCommonWork(void *p, int idx);
extern u32 FIELDMAP_GetGameSystem(void *p);
struct Big;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void func_020061E4(u32 a);
extern void GIMMICK39_ApplySwitch(u32 a, void *b);

int GIMMICK39_SwitchEventMain(int a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    Save *q;
    u8 a;
    u8 b;
    void *o;
    void *o2;
    int i;

    sys = GAMESYSTEM_GetFieldMap(func_020124E4((void *)a0));
    h = FIELDMAP_GetExpObj(sys);
    s = FIELDMAP_GetCommonWork(sys, 1);
    q = (Save *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(sys))), 2);
    switch (*a1) {
    case 0:
        s->mode = q->flag[s->idx];
        a = s->idx + 4;
        b = s->idx + 8;
        if (s->mode == 0) {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, a, 0, 0);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, b, 0, 0);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, a, 1, 1);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, b, 1, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)a, (u16)1), 0);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)b, (u16)1), 0);
            FLD_EXP_OBJ_SetAnimeFrame((int)((void *)h), 0, a, 1, 0);
            FLD_EXP_OBJ_SetAnimeFrame((int)((void *)h), 0, b, 1, 0);
            s->mode = 1;
        } else {
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, a, 1, 0);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, b, 1, 0);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, a, 0, 1);
            FLD_EXP_OBJ_SetAnimeEnabled((void *)h, 0, b, 0, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)a, (u16)0), 0);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)b, (u16)0), 0);
            FLD_EXP_OBJ_SetAnimeFrame((int)((void *)h), 0, a, 0, 0);
            FLD_EXP_OBJ_SetAnimeFrame((int)((void *)h), 0, b, 0, 0);
            s->mode = 0;
        }
        func_020061E4(0x689);
        *a1 = *a1 + 1;
        break;
    case 1:
        i = s->idx;
        o = FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)(i + 4), (u16)s->mode);
        o2 = FLD_EXP_OBJ_GetAnime((char *)h, 0, (u8)(i + 8), (u16)s->mode);
        if (FLD_EXP_OBJ_IsAnimeStopped(o) && FLD_EXP_OBJ_IsAnimeStopped(o2)) {
            GIMMICK39_ApplySwitch((u32)sys, (void *)h);
            s->idx = -1;
            return 1;
        }
        break;
    }
    return 0;
}
