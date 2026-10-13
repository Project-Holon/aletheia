/*
 * function: BTL_HANDLER_ITEM_FloatStoneWeightRatio
 * address:  0x021DFA60
 * packet:   pkt_ov093_021DFA60
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
 */

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int m);

void BTL_HANDLER_ITEM_FloatStoneWeightRatio(int a, int b, int c)
{
    int n = 2;

    if (c == BTL_EVENT_GetVar(n))
        BTL_EVENT_MultiplyVar(53, n << 10);
}
