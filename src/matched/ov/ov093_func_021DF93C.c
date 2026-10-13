/*
 * function: BTL_HANDLER_ITEM_BoostMovePowerOfType
 * address:  0x021DF93C
 * packet:   pkt_ov093_021DF93C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern int BTL_HANDLER_ITEM_GetBoostRatio(int a);

void BTL_HANDLER_ITEM_BoostMovePowerOfType(int a, int b, int c, int d)
{
    if (c != BTL_EVENT_GetVar(3))
        return;
    if (d != BTL_EVENT_GetVar(22))
        return;
    BTL_EVENT_MultiplyVar(49, BTL_HANDLER_ITEM_GetBoostRatio(a));
}
