/*
 * function: HAND_ITEM_GetGhostGemHandlers
 * address: 0x021E00F8
 * packet: pkt_ov093_021E00F8
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
 *   gHandItemGhostGemHandlers 0x021F19DC data ov093 a4
 */

int *HAND_ITEM_GetGhostGemHandlers(int *p);

/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl HAND_ITEM_GemMovePower; add sp, #4; pop {r3, r4, pc}.
 */
extern int gHandItemGhostGemHandlers[];

int *HAND_ITEM_GetGhostGemHandlers(int *p)
{
    *p = 3;
    return gHandItemGhostGemHandlers;
}
