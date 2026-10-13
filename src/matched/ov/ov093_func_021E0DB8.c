/*
 * function: HAND_WAZA_GetSplashHandlers
 * address: 0x021E0DB8
 * packet: pkt_ov093_021E0DB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0D54.c and filed here.
 *
 * symbols:
 *   gSplashHandlers 0x021F26FC data ov093 a4
 */

extern int gSplashHandlers[];
int *HAND_WAZA_GetSplashHandlers(int *p);

int *HAND_WAZA_GetSplashHandlers(int *p)
{
    *p = 1;
    return gSplashHandlers;
}
