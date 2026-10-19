/*
 * function: HAND_TOKUSEI_GetClearBodyHandlers
 * address: 0x021D9260
 * packet: pkt_ov093_021D9260
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9118.c and filed here.
 *
 * symbols:
 *   gIndirectGuardCause8Handlers 0x021F08A0 data ov093 a4
 */

int *HAND_TOKUSEI_GetClearBodyHandlers(int *p);

/* 021D926C  shifted 4-arg wrapper -> HAND_TOKUSEI_BlockIndirectDamage(..., 0x8) */
extern int gIndirectGuardCause8Handlers[];

int *HAND_TOKUSEI_GetClearBodyHandlers(int *p)
{
    *p = 2;
    return gIndirectGuardCause8Handlers;
}
