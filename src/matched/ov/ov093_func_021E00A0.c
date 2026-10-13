/*
 * function: HAND_ITEM_GetBugGemHandlers
 * address: 0x021E00A0
 * packet: pkt_ov093_021E00A0
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
 *   gHandItemBugGemHandlers 0x021F185C data ov093 a4
 */

int *HAND_ITEM_GetBugGemHandlers(int *p);

/* 021E00AC  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0x6) */
extern int gHandItemBugGemHandlers[];

int *HAND_ITEM_GetBugGemHandlers(int *p)
{
    *p = 3;
    return gHandItemBugGemHandlers;
}
