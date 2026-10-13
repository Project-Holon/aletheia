/*
 * function: HAND_ITEM_GetDarkGemHandlers
 * address: 0x021E0150
 * packet: pkt_ov093_021E0150
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
 *   gHandItemDarkGemHandlers 0x021F188C data ov093 a4
 */

int *HAND_ITEM_GetDarkGemHandlers(int *p);

/* 021E015C  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0x10) */
extern int gHandItemDarkGemHandlers[];

int *HAND_ITEM_GetDarkGemHandlers(int *p)
{
    *p = 3;
    return gHandItemDarkGemHandlers;
}
