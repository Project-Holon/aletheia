/*
 * function: HAND_ITEM_GetFightingGemHandlers
 * address: 0x021DFFC4
 * packet: pkt_ov093_021DFFC4
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
 *   gHandItemFightingGemHandlers 0x021F194C data ov093 a4
 */

int *HAND_ITEM_GetFightingGemHandlers(int *p);

/* 021DFFD0  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0x1) */
extern int gHandItemFightingGemHandlers[];

int *HAND_ITEM_GetFightingGemHandlers(int *p)
{
    *p = 3;
    return gHandItemFightingGemHandlers;
}
