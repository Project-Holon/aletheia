/*
 * function: GIMMICK64_CreateWaitPeakEvent
 * address:  0x021F3AC0
 * packet:   pkt_ov064_021F3AC0
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GIMMICK64_IsArcPeakReached  0x021F3BAC  thumb  ov064
 */

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK64_IsArcPeakReached(void *p);

void *GIMMICK64_CreateWaitPeakEvent(void *p)
{
    GAMESYSTEM_GetFieldMap(p);
    return func_020122C0(p, 0, GIMMICK64_IsArcPeakReached, 0);
}
