/*
 * function: HAND_TOKUSEI_GetSandStreamHandlers
 * address: 0x021D978C
 * packet: pkt_ov093_021D978C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gSandStreamHandlers 0x021F08F0 data ov093 a4
 */

int *HAND_TOKUSEI_GetSandStreamHandlers(int *p);
extern int gSandStreamHandlers[];

int *HAND_TOKUSEI_GetSandStreamHandlers(int *p)
{
    *p = 2;
    return gSandStreamHandlers;
}
