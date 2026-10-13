/*
 * function: HAND_ITEM_GetMicleBerryHandlers
 * address: 0x021DDF8C
 * packet: pkt_ov093_021DDF8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDCA4.c and filed here.
 *
 * symbols:
 *   gMicleBerryHandlers 0x021F1E0C data ov093 a4
 */

int *HAND_ITEM_GetMicleBerryHandlers(int *p);
extern int gMicleBerryHandlers[];

int *HAND_ITEM_GetMicleBerryHandlers(int *p)
{
    *p = 6;
    return gMicleBerryHandlers;
}
