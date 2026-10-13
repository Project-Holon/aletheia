/*
 * function: HAND_WAZA_ChargeGetHandlers
 * address: 0x021E1EAC
 * packet: pkt_ov093_021E1EAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1E44.c and filed here.
 *
 * symbols:
 *   gChargeHandlers 0x021F2DD8 data ov093 a4
 */

int *HAND_WAZA_ChargeGetHandlers(int *p);
extern int gChargeHandlers[];

/*
 * Leaf: -40000 - (a * 100 + b), the plain two-term member of the
 *  *  func_021E20B8 family (that one adds the 50-byte header).
 */
int *HAND_WAZA_ChargeGetHandlers(int *p)
{
    *p = 4;
    return gChargeHandlers;
}
