/*
 * function: HAND_ITEM_GetGroundGemHandlers
 * address: 0x021E001C
 * packet: pkt_ov093_021E001C
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
 *   gHandItemGroundGemHandlers 0x021F19AC data ov093 a4
 */

int *HAND_ITEM_GetGroundGemHandlers(int *p);

/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #4; str r4, [sp]; bl HAND_ITEM_GemMovePower; add sp, #4; pop {r3, r4, pc}.
 */
extern int gHandItemGroundGemHandlers[];

int *HAND_ITEM_GetGroundGemHandlers(int *p)
{
    *p = 3;
    return gHandItemGroundGemHandlers;
}
