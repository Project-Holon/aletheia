/*
 * function: HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone
 * address: 0x021DF420
 * packet: pkt_ov093_021DF420
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF3A4.c and filed here.
 *
 * symbols:
 *   BTL_SERVER_FLOW_TryFinishMainCounter 0x021C8408 thumb ov093
 */

typedef unsigned char u8;
extern void BTL_SERVER_FLOW_TryFinishMainCounter(u8 *, int);
void HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone(int a, u8 *b, int c);

/*
 * Sibling of func_021DF3B0 against the func_021DFE08 probe.
 */
void HAND_ITEM_AmuletCoinFlagDoublePrizeOnEnterDone(int a, u8 *b, int c)
{
    BTL_SERVER_FLOW_TryFinishMainCounter(b, c);
}
