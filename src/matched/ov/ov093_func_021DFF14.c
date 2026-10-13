/*
 * function: HAND_ITEM_GetWaterGemHandlers
 * address: 0x021DFF14
 * packet: pkt_ov093_021DFF14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCE8.c and filed here.
 *
 * symbols:
 *   gHandItemWaterGemHandlers 0x021F1A54 data ov093 a4
 */

int *HAND_ITEM_GetWaterGemHandlers(int *p);

/* 021DFF20  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0xa) */
extern int gHandItemWaterGemHandlers[];

int *HAND_ITEM_GetWaterGemHandlers(int *p)
{
    *p = 3;
    return gHandItemWaterGemHandlers;
}
