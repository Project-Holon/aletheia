/*
 * function: HAND_ITEM_GetFireGemHandlers
 * address: 0x021DFEE8
 * packet: pkt_ov093_021DFEE8
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
 *   gHandItemFireGemHandlers 0x021F1A3C data a4
 */

int *HAND_ITEM_GetFireGemHandlers(int *p);

/* 021DFEF4  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0x9) */
extern int gHandItemFireGemHandlers[];

int *HAND_ITEM_GetFireGemHandlers(int *p)
{
    *p = 3;
    return gHandItemFireGemHandlers;
}
