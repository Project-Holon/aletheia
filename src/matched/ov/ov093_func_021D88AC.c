/*
 * function: BTL_CALC_GetHustleHandlers
 * address: 0x021D88AC
 * packet: pkt_ov093_021D88AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D87C8.c and filed here.
 *
 * symbols:
 *   gHustleHandlers 0x021F09C0 data ov093 a4
 */

int *BTL_CALC_GetHustleHandlers(int *p);

/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021D88CE; movs r0, #0x11; movs r1, #0; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
extern int gHustleHandlers[];

int *BTL_CALC_GetHustleHandlers(int *p)
{
    *p = 2;
    return gHustleHandlers;
}
