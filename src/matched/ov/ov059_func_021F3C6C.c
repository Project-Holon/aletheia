/*
 * function: SP_POKE_GIMMICK_WaitAnimeProgressEventMain
 * address:  0x021F3C6C
 * packet:   pkt_ov059_021F3C6C
 * region:   ov059
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
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 */

typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FLD_EXP_OBJ_GetAnimeFrame(int a, int b, int c, int d);

int SP_POKE_GIMMICK_WaitAnimeProgressEventMain(void *a)
{
    void *t;
    void *s;
    int lim;
    int flag;
    int *p;

    t = GAMESYSTEM_GetFieldMap(func_020124E4(a));
    s = (void *)FIELDMAP_GetExpObj(t);
    p = FIELDMAP_GetCommonWork(t, 1);
    flag = 1;
    if (*p == 0) {
        lim = 0x5000;
        flag = 0;
    } else {
        lim = 0x22000;
    }
    if (FLD_EXP_OBJ_GetAnimeFrame((int)s, 0, (u16)flag, 0) >= lim) {
        return 1;
    }
    return 0;
}
