/*
 * function: HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnter
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
 *   BTL_SERVER_FLOW_TryFinishMainCounter  0x021C8408  thumb  ov093
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern void BTL_SERVER_FLOW_TryFinishMainCounter(u8 *, int);
void HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnter(int a, u8 *b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_SERVER_FLOW_TryFinishMainCounter(b, c);
}
