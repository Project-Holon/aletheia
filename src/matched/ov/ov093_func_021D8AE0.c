/*
 * function: HAND_TOKUSEI_GetSnowCloakHandlers
 * address: 0x021D8AE0
 * packet: pkt_ov093_021D8AE0
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
 *   gSnowCloakHandlers 0x021F09F0 data ov093 a4
 */

int *HAND_TOKUSEI_GetSnowCloakHandlers(int *p);
extern int gSnowCloakHandlers[];

int *HAND_TOKUSEI_GetSnowCloakHandlers(int *p)
{
    *p = 2;
    return gSnowCloakHandlers;
}
