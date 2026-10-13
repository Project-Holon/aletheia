/*
 * function: BTL_ABILITY_GetInfiltratorHandlers
 * address: 0x021DC87C
 * packet: pkt_ov093_021DC87C
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
 *   gInfiltratorHandlers 0x021F0A00 data ov093 a4
 */

int *BTL_ABILITY_GetInfiltratorHandlers(int *p);
extern int gInfiltratorHandlers[];

int *BTL_ABILITY_GetInfiltratorHandlers(int *p)
{
    *p = 2;
    return gInfiltratorHandlers;
}
