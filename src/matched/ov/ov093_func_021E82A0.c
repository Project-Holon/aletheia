/*
 * function: HAND_WAZA_GetFreezeShockIceBurnHandlers
 * address: 0x021E82A0
 * packet: pkt_ov093_021E82A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E8270.c and filed here.
 *
 * symbols:
 *   gFreezeShockIceBurnHandlers 0x021F2814 data ov093 a4
 */

int *HAND_WAZA_GetFreezeShockIceBurnHandlers(int *p);
extern int gFreezeShockIceBurnHandlers[];

int *HAND_WAZA_GetFreezeShockIceBurnHandlers(int *p)
{
    *p = 1;
    return gFreezeShockIceBurnHandlers;
}
