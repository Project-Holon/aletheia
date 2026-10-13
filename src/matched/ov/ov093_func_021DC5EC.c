/*
 * function: func_021DC5EC
 * address: 0x021DC5EC
 * packet: pkt_ov093_021DC5EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC57C.c and filed here.
 *
 * symbols:
 *   gRegeneratorHandlers 0x021F0700 data ov093 a4
 */

int *func_021DC5EC(int *p);

/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #2; bl BTL_ABILITY_BlockIndirectDamage; pop {r3, pc}.
 */
extern int gRegeneratorHandlers[];

int *func_021DC5EC(int *p)
{
    *p = 1;
    return gRegeneratorHandlers;
}
