/*
 * function: HAND_ITEM_GetRockyHelmetHandlers
 * address: 0x021DFAB0
 * packet: pkt_ov093_021DFAB0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF9C8.c and filed here.
 *
 * symbols:
 *   gBtlHandlerItemRockyHelmetHandlers 0x021F140C data ov093 a4
 */

int *HAND_ITEM_GetRockyHelmetHandlers(int *p);
extern int gBtlHandlerItemRockyHelmetHandlers[];

int *HAND_ITEM_GetRockyHelmetHandlers(int *p)
{
    *p = 1;
    return gBtlHandlerItemRockyHelmetHandlers;
}
