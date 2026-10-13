/*
 * function: GIMMICK64_IsArcPeakReached
 * address: 0x021F3BAC
 * packet: pkt_ov064_021F3BAC
 * region: ov064
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * checks: 1 own BE6E8 confirms four args/int return and matched accessor chain confirms pointer forwarding; 2 ov064/065 callers refreshed; 3 _Bool zero/flag retained, 4 two initialisation-order variants stayed DIFF4, 5 idioms/neighbours refreshed. W75 three fixed runs, baseline explain, first permuter300 reached EXACT* at candidate102; fixed one and shard verify confirmed it.
 * lever: initialise flag after the callee result has been captured; the
 * saved zero is then materialised before the saved one. The trailing
 * halfword at 021F3BD6 is zero alignment padding.
 * symbols:
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_GetAnimeFrame 0x021BE6E8 thumb ov021
 */
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int FLD_EXP_OBJ_GetAnimeFrame(int a, int b, int c, int d);

int GIMMICK64_IsArcPeakReached(void *p)
{
    unsigned char zero;
    unsigned char flag;
    int v;
    int s;
    int tmp;
    s = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(p)));
    zero = 0;
    tmp = FLD_EXP_OBJ_GetAnimeFrame(s, zero, 1, zero);
    v = tmp;
    flag = 1;
    if (v < 0x5000)
        flag = zero;
    return flag;
}
