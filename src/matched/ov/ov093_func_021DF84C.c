/*
 * function: BTL_HANDLER_ITEM_GetSpellTagHandlers
 * address: 0x021DF84C
 * packet: pkt_ov093_021DF84C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF840.c and filed here.
 *
 * symbols:
 *   gSpellTagHandlers 0x021F15BC data ov093 a4
 */

int *BTL_HANDLER_ITEM_GetSpellTagHandlers(int *p);
extern int gSpellTagHandlers[];

int *BTL_HANDLER_ITEM_GetSpellTagHandlers(int *p)
{
    *p = 1;
    return gSpellTagHandlers;
}
