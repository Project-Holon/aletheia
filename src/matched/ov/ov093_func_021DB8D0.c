/*
 * function: HAND_TOKUSEI_GetStickyHoldHandlers
 * address: 0x021DB8D0
 * packet: pkt_ov093_021DB8D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB650.c and filed here.
 *
 * symbols:
 *   gStickyHoldHandlers 0x021F0AA0 data ov093 a4
 */

int *HAND_TOKUSEI_GetStickyHoldHandlers(int *p);
extern int gStickyHoldHandlers[];

int *HAND_TOKUSEI_GetStickyHoldHandlers(int *p)
{
    *p = 3;
    return gStickyHoldHandlers;
}
