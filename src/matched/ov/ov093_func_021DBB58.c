/*
 * function: HAND_TOKUSEI_GetUnburdenHandlers
 * address: 0x021DBB58
 * packet: pkt_ov093_021DBB58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DBAF0.c and filed here.
 *
 * symbols:
 *   gUnburdenHandlers 0x021F0960 data ov093 a4
 */

int *HAND_TOKUSEI_GetUnburdenHandlers(int *p);
extern int gUnburdenHandlers[];

int *HAND_TOKUSEI_GetUnburdenHandlers(int *p)
{
    *p = 2;
    return gUnburdenHandlers;
}
