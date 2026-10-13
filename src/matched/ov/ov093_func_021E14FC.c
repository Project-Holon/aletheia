/*
 * function: HAND_WAZA_AddEndeavor
 * address: 0x021E14FC
 * packet: pkt_ov093_021E14FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E14E4.c and filed here.
 *
 * symbols:
 *   gEndeavorHandlers 0x021F2938 data ov093 a4
 */

int *HAND_WAZA_AddEndeavor(int *p);
extern int gEndeavorHandlers[];

int *HAND_WAZA_AddEndeavor(int *p)
{
    *p = 2;
    return gEndeavorHandlers;
}
