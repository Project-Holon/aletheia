/*
 * function: HAND_TOKUSEI_GetSandVeilHandlers
 * address: 0x021D8A9C
 * packet: pkt_ov093_021D8A9C
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
 *   gSandVeilHandlers 0x021F09E0 data ov093 a4
 */

int *HAND_TOKUSEI_GetSandVeilHandlers(int *p);
extern int gSandVeilHandlers[];

int *HAND_TOKUSEI_GetSandVeilHandlers(int *p)
{
    *p = 2;
    return gSandVeilHandlers;
}
