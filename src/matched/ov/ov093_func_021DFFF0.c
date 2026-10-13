/*
 * function: HAND_ITEM_GetPoisonGemHandlers
 * address: 0x021DFFF0
 * packet: pkt_ov093_021DFFF0
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
 *   gHandItemPoisonGemHandlers 0x021F1994 data ov093 a4
 */

int *HAND_ITEM_GetPoisonGemHandlers(int *p);

/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #3; str r4, [sp]; bl HAND_ITEM_GemMovePower; add sp, #4; pop {r3, r4, pc}.
 */
extern int gHandItemPoisonGemHandlers[];

int *HAND_ITEM_GetPoisonGemHandlers(int *p)
{
    *p = 3;
    return gHandItemPoisonGemHandlers;
}
