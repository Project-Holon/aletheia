/*
 * function: HAND_TOKUSEI_GetFlashFireHandlers
 * address: 0x021DB000
 * packet: pkt_ov093_021DB000
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624_p02.c and filed here.
 *
 * symbols:
 *   gFlashFireHandlers 0x021F0A28 data ov093 a4
 */

int *HAND_TOKUSEI_GetFlashFireHandlers(int *p);
extern int gFlashFireHandlers[];

int *HAND_TOKUSEI_GetFlashFireHandlers(int *p)
{
    *p = 3;
    return gFlashFireHandlers;
}
