/*
 * function: HAND_TOKUSEI_GetJustifiedHandlers
 * address: 0x021DC8FC
 * packet: pkt_ov093_021DC8FC
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
 *   gJustifiedHandlers 0x021F05D0 data ov093 a4
 */

int *HAND_TOKUSEI_GetJustifiedHandlers(int *p);
extern int gJustifiedHandlers[];

int *HAND_TOKUSEI_GetJustifiedHandlers(int *p)
{
    *p = 1;
    return gJustifiedHandlers;
}
