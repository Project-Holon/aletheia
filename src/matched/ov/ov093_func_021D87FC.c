/*
 * function: BTL_CALC_GetQuickFeetHandlers
 * address: 0x021D87FC
 * packet: pkt_ov093_021D87FC
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
 *   gQuickFeetHandlers 0x021F0748 data ov093 a4
 */

int *BTL_CALC_GetQuickFeetHandlers(int *p);
extern int gQuickFeetHandlers[];

int *BTL_CALC_GetQuickFeetHandlers(int *p)
{
    *p = 1;
    return gQuickFeetHandlers;
}
