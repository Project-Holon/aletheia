/*
 * function: BTL_HANDLER_ITEM_GetDreadPlateHandlers
 * address: 0x021DF34C
 * packet: pkt_ov093_021DF34C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DEFC4.c and filed here.
 *
 * symbols:
 *   d_021F14EC 0x021F14EC data ov093 a4
 */

extern int d_021F14EC[];
int *BTL_HANDLER_ITEM_GetDreadPlateHandlers(int *p);

int *BTL_HANDLER_ITEM_GetDreadPlateHandlers(int *p)
{
    *p = 1;
    return d_021F14EC;
}
