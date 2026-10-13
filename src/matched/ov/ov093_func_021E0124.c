/*
 * function: HAND_ITEM_GetDragonGemHandlers
 * address: 0x021E0124
 * packet: pkt_ov093_021E0124
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
 *   gHandItemDragonGemHandlers 0x021F1A0C data ov093 a4
 */

int *HAND_ITEM_GetDragonGemHandlers(int *p);

/* 021E0130  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0xf) */
extern int gHandItemDragonGemHandlers[];

int *HAND_ITEM_GetDragonGemHandlers(int *p)
{
    *p = 3;
    return gHandItemDragonGemHandlers;
}
