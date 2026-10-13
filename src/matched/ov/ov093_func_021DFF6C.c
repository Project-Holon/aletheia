/*
 * function: HAND_ITEM_GetGrassGemHandlers
 * address: 0x021DFF6C
 * packet: pkt_ov093_021DFF6C
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
 *   gHandItemGrassGemHandlers 0x021F18A4 data ov093 a4
 */

int *HAND_ITEM_GetGrassGemHandlers(int *p);

/* 021DFF78  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0xb) */
extern int gHandItemGrassGemHandlers[];

int *HAND_ITEM_GetGrassGemHandlers(int *p)
{
    *p = 3;
    return gHandItemGrassGemHandlers;
}
