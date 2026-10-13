/*
 * function: GIMMICK39_RideRefusedEventMain
 * address:  0x021F4610
 * packet:   pkt_ov039_021F4610
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   SCRIPT_SYS_CallScriptEvent 0x02158780 thumb ov010
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   GIMMICK39_SetAnimeFrame 0x021F3E04 thumb ov039
 *   GIMMICK39_GetAnimeFrame 0x021F3DE4 thumb ov039
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u8 sel;
    u8 pad5[3];
    int timer[4];
    u8 pad18[0x21F0 - 0x18];
    s8 slot[4];
} Work;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern Work *FIELDMAP_GetCommonWork(void *p, int idx);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern u32 FIELDMAP_GetGameSystem(void *p);
struct Big;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern int SCRIPT_SYS_ChangeScriptEvent(int a0, int a1, int a2, int a3);
extern void GIMMICK39_SetAnimeFrame(void *p, u8 delta, u16 i, int frame);
extern int GIMMICK39_GetAnimeFrame(void *p, u16 delta, u16 i);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern void func_020061E4(u32 a);

int GIMMICK39_RideRefusedEventMain(void *a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    int c;
    u8 j;
    void *o;

    sys = GAMESYSTEM_GetFieldMap(func_020124E4(a0));
    h = FIELDMAP_GetExpObj(sys);
    s = FIELDMAP_GetCommonWork(sys, 1);
    c = (u8)(s->sel >> 1);
    j = c;
    o = FLD_EXP_OBJ_GetAnime((char *)h, 0, j, 0);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem(sys))), 2);
    switch (*a1) {
    case 0:
        SCRIPT_SYS_CallScriptEvent(a0, 0xF, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 1:
        GIMMICK39_SetAnimeFrame((void *)h, j, 0, 0);
        FLD_EXP_OBJ_SetAnimePaused(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 2:
        if (GIMMICK39_GetAnimeFrame((void *)h, j, 0) < 0xF000) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(o, 1);
        SCRIPT_SYS_CallScriptEvent(a0, 7, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 3:
        FLD_EXP_OBJ_SetAnimePaused(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 4:
        if (FLD_EXP_OBJ_IsAnimeStopped(o) == 0) {
            break;
        }
        FLD_EXP_OBJ_SetAnimePaused(o, 1);
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)h, 0, j, (u8)(s->sel + 1)), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        s->sel = 0xff;
        SCRIPT_SYS_ChangeScriptEvent((int)a0, 8, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}
