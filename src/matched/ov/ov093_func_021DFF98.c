/*
 * function: HAND_ITEM_GetIceGemHandlers
 * address: 0x021DFF98
 * packet: pkt_ov093_021DFF98
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
 *   gHandItemIceGemHandlers 0x021F18BC data ov093 a4
 */

int *HAND_ITEM_GetIceGemHandlers(int *p);

/* 021DFFA4  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0xe) */
extern int gHandItemIceGemHandlers[];

int *HAND_ITEM_GetIceGemHandlers(int *p)
{
    *p = 3;
    return gHandItemIceGemHandlers;
}
