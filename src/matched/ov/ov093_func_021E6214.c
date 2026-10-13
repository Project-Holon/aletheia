/*
 * function: HAND_WAZA_GetShadowForceHandlers
 * address: 0x021E6214
 * packet: pkt_ov093_021E6214
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E61BC.c and filed here.
 *
 * symbols:
 *   gShadowForceHandlers 0x021F2F40 data ov093 a4
 */

int *HAND_WAZA_GetShadowForceHandlers(int *p);
extern int gShadowForceHandlers[];

int *HAND_WAZA_GetShadowForceHandlers(int *p)
{
    *p = 5;
    return gShadowForceHandlers;
}
