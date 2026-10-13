/*
 * function: FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent
 * address:  0x021F3ADC
 * packet:   pkt_ov064_021F3ADC
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped  0x021F3BD8  thumb  ov064
 */

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped(void *p);

void *FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent(void *p)
{
    GAMESYSTEM_GetFieldMap(p);
    return func_020122C0(p, 0, FIELD_GIMMICK_ARC_EFFECT_IsArcAnimeStopped, 0);
}
