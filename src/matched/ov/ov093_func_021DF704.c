/*
 * function: BTL_HANDLER_ITEM_GetSoftSandHandlers
 * address: 0x021DF704
 * packet: pkt_ov093_021DF704
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF48C.c and filed here.
 *
 * symbols:
 *   gSoftSandHandlers 0x021F13FC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetSoftSandHandlers(int *p);
extern int gSoftSandHandlers[];

int *BTL_HANDLER_ITEM_GetSoftSandHandlers(int *p)
{
    *p = 1;
    return gSoftSandHandlers;
}
