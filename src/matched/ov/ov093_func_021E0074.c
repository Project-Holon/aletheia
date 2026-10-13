/*
 * function: HAND_ITEM_GetPsychicGemHandlers
 * address: 0x021E0074
 * packet: pkt_ov093_021E0074
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
 *   gHandItemPsychicGemHandlers 0x021F1A6C data ov093 a4
 */

int *HAND_ITEM_GetPsychicGemHandlers(int *p);

/* 021E0080  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0xd) */
extern int gHandItemPsychicGemHandlers[];

int *HAND_ITEM_GetPsychicGemHandlers(int *p)
{
    *p = 3;
    return gHandItemPsychicGemHandlers;
}
