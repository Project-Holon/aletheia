/*
 * function: HAND_ITEM_GetRockGemHandlers
 * address: 0x021E00CC
 * packet: pkt_ov093_021E00CC
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
 *   gHandItemRockGemHandlers 0x021F1964 data ov093 a4
 */

int *HAND_ITEM_GetRockGemHandlers(int *p);

/* 021E00D8  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0x5) */
extern int gHandItemRockGemHandlers[];

int *HAND_ITEM_GetRockGemHandlers(int *p)
{
    *p = 3;
    return gHandItemRockGemHandlers;
}
