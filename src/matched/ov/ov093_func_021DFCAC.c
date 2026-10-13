/*
 * function: BTL_HANDLER_ITEM_GetRingTargetHandlers
 * address: 0x021DFCAC
 * packet: pkt_ov093_021DFCAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFABC.c and filed here.
 *
 * symbols:
 *   gBtlHandlerItemRingTargetHandlers 0x021F14BC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetRingTargetHandlers(int *p);
extern int gBtlHandlerItemRingTargetHandlers[];

int *BTL_HANDLER_ITEM_GetRingTargetHandlers(int *p)
{
    *p = 1;
    return gBtlHandlerItemRingTargetHandlers;
}
