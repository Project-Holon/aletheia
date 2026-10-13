/*
 * function: HAND_TOKUSEI_GetPoisonGuardHandlers
 * address: 0x021D94F8
 * packet: pkt_ov093_021D94F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gPoisonGuardHandlers 0x021F0C74 data ov093 a4
 */

int *HAND_TOKUSEI_GetPoisonGuardHandlers(int *p);

/* 021D9504  shape F5: out-param store of HAND_TOKUSEI_BlockSickIfTargeted(..., 4) */
extern int gPoisonGuardHandlers[];

int *HAND_TOKUSEI_GetPoisonGuardHandlers(int *p)
{
    *p = 5;
    return gPoisonGuardHandlers;
}
