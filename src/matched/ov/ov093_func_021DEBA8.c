/*
 * function: BTL_HANDLER_ITEM_GetExpertBeltHandlers
 * address: 0x021DEBA8
 * packet: pkt_ov093_021DEBA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE980.c and filed here.
 *
 * symbols:
 *   d_021F150C 0x021F150C data ov093 a4
 */

extern int d_021F150C[];
int *BTL_HANDLER_ITEM_GetExpertBeltHandlers(int *p);

int *BTL_HANDLER_ITEM_GetExpertBeltHandlers(int *p)
{
    *p = 1;
    return d_021F150C;
}
