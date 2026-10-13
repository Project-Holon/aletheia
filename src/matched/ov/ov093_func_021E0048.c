/*
 * function: HAND_ITEM_GetFlyingGemHandlers
 * address: 0x021E0048
 * packet: pkt_ov093_021E0048
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
 *   gHandItemFlyingGemHandlers 0x021F1A24 data ov093 a4
 */

int *HAND_ITEM_GetFlyingGemHandlers(int *p);

/* 021E0054  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0x2) */
extern int gHandItemFlyingGemHandlers[];

int *HAND_ITEM_GetFlyingGemHandlers(int *p)
{
    *p = 3;
    return gHandItemFlyingGemHandlers;
}
