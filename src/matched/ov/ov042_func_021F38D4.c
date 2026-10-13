/*
 * function: FIELD_GIMMICK_BUTTON_STATES_EventSetState
 * address:  0x021F38D4
 * packet:   pkt_ov042_021F38D4
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The u16 j/k parameters of FLD_EXP_OBJ_SetAnimeEnabled/674/6CC (as ov043/ov045 declare
 * them) with the byte held in a u8 local move the join's stack-argument
 * store ahead of the register setup; with int parameters it lands last.
 *
 * symbols:
 *   FIELD_GIMMICK_BUTTON_STATES_EventSetState  0x021F38D4  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
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
extern void FLD_EXP_OBJ_SetAnimeEnabled(u32 a, int b, u16 c, u16 d, int e);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);

int FIELD_GIMMICK_BUTTON_STATES_EventSetState(void *a, int *st)
{
    void *s;
    u32 t;
    u8 *p;
    u8 *e;
    u8 x;
    int z;

    s = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(a));
    t = FIELDMAP_GetExpObj(s);
    p = (u8 *)FIELDMAP_GetCommonWork(s, 1);
    GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(s))), 4);
    switch (*st) {
    case 0:
        x = p[0];
        z = 0;
        FLD_EXP_OBJ_SetAnimeEnabled(t, 0, x, 0, 1);
        e = FLD_EXP_OBJ_GetAnime((char *)t, 0, x, 0);
        if (p[2] != 0) {
            FLD_EXP_OBJ_SetAnimePaused(e, z);
            z = FLD_EXP_OBJ_GetAnimeLastFrame((u32)e);
        } else {
            FLD_EXP_OBJ_SetAnimePaused(e, 1);
        }
        FLD_EXP_OBJ_SetAnimeFrame(t, 0, x, 0, z);
        FLD_EXP_OBJ_SetAnimeLoop(e, 0);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
