/*
 * function: HAND_TOKUSEI_GetPickupHandlers
 * address: 0x021DBBCC
 * packet: pkt_ov093_021DBBCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DBAF0.c and filed here.
 *
 * symbols:
 *   gPickupHandlers 0x021F06C8 data ov093 a4
 */

int *HAND_TOKUSEI_GetPickupHandlers(int *p);
extern int gPickupHandlers[];

int *HAND_TOKUSEI_GetPickupHandlers(int *p)
{
    *p = 1;
    return gPickupHandlers;
}
