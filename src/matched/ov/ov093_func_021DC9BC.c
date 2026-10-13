/*
 * function: HAND_TOKUSEI_GetMummyHandlers
 * address: 0x021DC9BC
 * packet: pkt_ov093_021DC9BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC960.c and filed here.
 *
 * symbols:
 *   gMummyHandlers 0x021F0678 data ov093 a4
 */

int *HAND_TOKUSEI_GetMummyHandlers(int *p);
extern int gMummyHandlers[];

int *HAND_TOKUSEI_GetMummyHandlers(int *p)
{
    *p = 1;
    return gMummyHandlers;
}
