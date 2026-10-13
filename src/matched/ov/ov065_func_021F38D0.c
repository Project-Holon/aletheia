/*
 * function: FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain
 * address:  0x021F38D0
 * packet:   pkt_021F38D0
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching the leaf at 0x021897BC in ov021 (region hint added
 * to the symbols line); the bl at +0x0E now resolves via `matched`.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb
 */

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *, int);

int FIELD_GIMMICK_TIME_EFFECT_WaitEffectEventMain(void *task)
{
    void *a;
    int r;
    a = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(task));
    r = 1;
    if (*FIELDMAP_GetCommonWork(a, 1) != 0)
        r = 0;
    return r;
}
