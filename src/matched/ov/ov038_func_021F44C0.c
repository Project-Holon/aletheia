/*
 * function: GIMMICK38_EventScripted
 * address:  0x021F44C0
 * packet:   pkt_ov038_021F44C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: The handed extent includes rodata after 0x021F45E8.
 *         0200B3A4 receives the visibly loaded second argument 6.
 *         Enum id plus u16 extern arguments preserves the observed #16
 *         truncations at 021F4594/459A and 021F45C4/45CA; u16 local alone
 *         folds them away. Matched callee's wide id receives the same bits.
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetSaveArea 0x0200B3A4 thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   FLD_EXP_OBJ_GetAnime 0x021BE674 thumb ov021
 *   FLD_EXP_OBJ_SetAnimePaused 0x021BE6B0 thumb ov021
 *   FLD_EXP_OBJ_SetAnimeFrame 0x021BE6CC thumb ov021
 *   FLD_EXP_OBJ_GetModelStatus 0x021BE480 thumb ov021
 *   FLD_EXP_OBJ_IsAnimeStopped 0x021BE6BC thumb ov021
 *   SCRIPT_SYS_CallScriptEvent 0x02158780 thumb ov010
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   gGimmick38EffectPos 0x021F465C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { ID_ZERO } Id;
typedef struct { int x, y, z; } V3;
struct Big;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int i);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern void *FLD_EXP_OBJ_GetAnime(char *p, int i, unsigned int j, u16 k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeFrame(int p, int i, int j, u16 k, int v);
extern V3 *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
extern int SCRIPT_SYS_ChangeScriptEvent(int a0, int a1, int a2, int a3);
extern const V3 gGimmick38EffectPos[];

int GIMMICK38_EventScripted(void *a, int *state)
{
    void *sys;
    void *h;
    u8 *s;
    int i;
    Id id;

    sys = (void *)GAMESYSTEM_GetFieldMap(func_020124E4(a));
    h = (void *)FIELDMAP_GetExpObj(sys);
    s = (u8 *)FIELDMAP_GetCommonWork(sys, 1);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((void *)FIELDMAP_GetGameSystem(sys))), 6);
    switch (*state) {
    case 0:
        for (i = 0; i < 2; i++) {
            FLD_EXP_OBJ_SetAnimeEnabled(h, 0, 0x20, (u16)i, 1);
            FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(h, 0, 0x20, i), 0);
            FLD_EXP_OBJ_SetAnimeFrame((int)h, 0, 0x20, i, 0);
        }
        *FLD_EXP_OBJ_GetModelStatus(h, 0, 0x20) = gGimmick38EffectPos[s[2]];
        *state = *state + 1;
        break;
    case 1:
        id = 4;
        if (s[2] == 0)
            id = 3;
        SCRIPT_SYS_CallScriptEvent(a, (u16)id, 0, 0, 0x8015);
        *state = *state + 1;
        break;
    case 2:
        if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(h, 0, 0x20, 0))) {
            id = 6;
            if (s[2] == 0)
                id = 5;
            SCRIPT_SYS_ChangeScriptEvent((int)a, (u16)id, 0, 0x8015);
            *state = *state + 1;
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}
