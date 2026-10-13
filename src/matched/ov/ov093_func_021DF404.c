/*
 * function: BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnter
 * address:  0x021DF404
 * packet:   pkt_ov093_021DF404
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8408  0x021C8408  thumb  ov093
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern void func_021C8408(u8 *, int);
void BTL_HANDLER_ITEM_AmuletCoinFlagDoublePrizeOnEnter(int a, u8 *b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        func_021C8408(b, c);
}
