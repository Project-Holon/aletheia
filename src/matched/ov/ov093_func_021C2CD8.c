/*
 * function: BTL_SERVER_FLOW_ProcMoveAddedRankEffect
 * address: 0x021C2CD8
 * packet: pkt_ov093_021C2CD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x021C2D0E.
 * symbols:
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_RollMoveAddedEffectChance 0x021C2D10 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveRankEffects 0x021C2E64 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int BTL_POKEPARAM_IsFainted(void *);
extern int BTL_SERVER_FLOW_RollMoveAddedEffectChance(u8 *, u16 *, u8 *, u8 *);
extern int BTL_SERVER_FLOW_ProcMoveRankEffects(u8 *, const u16 *, u8 *, u8 *, int);
void BTL_SERVER_FLOW_ProcMoveAddedRankEffect(u8 *p, u16 *q, u8 *a, u8 *b)
{
    if (BTL_POKEPARAM_IsFainted(b) == 0) {
        if (BTL_SERVER_FLOW_RollMoveAddedEffectChance(p, q, a, b) != 0)
            BTL_SERVER_FLOW_ProcMoveRankEffects(p, q, a, b, 0);
    }
}
