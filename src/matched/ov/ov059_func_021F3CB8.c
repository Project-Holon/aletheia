/*
 * function: SP_POKE_GIMMICK_WaitAnimeEndEventMain
 * address:  0x021F3CB8
 * packet:   pkt_ov059_021F3CB8
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */

typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern int FLD_EXP_OBJ_IsAnimeStopped(int *p);

int SP_POKE_GIMMICK_WaitAnimeEndEventMain(void *a)
{
    void *t;
    void *s;
    int flag;
    int *p;

    t = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(a));
    s = (void *)FIELDMAP_GetExpObj(t);
    p = FIELDMAP_GetCommonWork(t, 1);
    flag = 1;
    if (*p == 0) {
        flag = 0;
    }
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(s, 0, (u16)flag, 0))) {
        return 1;
    }
    return 0;
}
