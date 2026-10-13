/*
 * function: HAND_WAZA_AddSecretPower
 * address: 0x021E1120
 * packet: pkt_ov093_021E1120
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E10D8.c and filed here.
 *
 * symbols:
 *   gSecretPowerHandlers 0x021F2908 data ov093 a4
 */

int *HAND_WAZA_AddSecretPower(int *p);
extern int gSecretPowerHandlers[];

int *HAND_WAZA_AddSecretPower(int *p)
{
    *p = 2;
    return gSecretPowerHandlers;
}
