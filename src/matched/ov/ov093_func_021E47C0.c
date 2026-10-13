/*
 * function: HAND_WAZA_AddTorment
 * address: 0x021E47C0
 * packet: pkt_ov093_021E47C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4754.c and filed here.
 *
 * symbols:
 *   gTormentHandlers 0x021F28A8 data ov093 a4
 */

int *HAND_WAZA_AddTorment(int *p);
extern int gTormentHandlers[];

int *HAND_WAZA_AddTorment(int *p)
{
    *p = 2;
    return gTormentHandlers;
}
