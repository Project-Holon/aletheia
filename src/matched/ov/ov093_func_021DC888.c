/*
 * function: HAND_TOKUSEI_GetMoxieHandlers
 * address: 0x021DC888
 * packet: pkt_ov093_021DC888
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC6EC.c and filed here.
 *
 * symbols:
 *   gMoxieHandlers 0x021F0770 data ov093 a4
 */

int *HAND_TOKUSEI_GetMoxieHandlers(int *p);
extern int gMoxieHandlers[];

int *HAND_TOKUSEI_GetMoxieHandlers(int *p)
{
    *p = 1;
    return gMoxieHandlers;
}
