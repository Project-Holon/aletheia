/*
 * function: SP_POKE_GIMMICK_StartWaitAnimeProgress
 * address:  0x021F3B40
 * packet:   pkt_ov059_021F3B40
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   SP_POKE_GIMMICK_WaitAnimeProgressEventMain  0x021F3C6C  thumb  ov059
 */

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int SP_POKE_GIMMICK_WaitAnimeProgressEventMain(void *p);

void SP_POKE_GIMMICK_StartWaitAnimeProgress(void *p, int v)
{
    int *o;
    o = FIELDMAP_GetCommonWork(GAMESYSTEM_GetFieldMap(p), 1);
    func_020122C0(p, 0, SP_POKE_GIMMICK_WaitAnimeProgressEventMain, 0);
    *o = v;
}
