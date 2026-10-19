/*
 * function: GAME_DATA_GetTradeHistory
 * address:  0x02012F14
 * packet:   pkt_02012F14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TRADE_HISTORY_GetFromSave  0x02009EC8  thumb
 *
 * Save-block getter through the handle's first word: tail call to
 * TRADE_HISTORY_GetFromSave (block 0x1f).  Seeded from ov119 0x021E0226, 0x021E06D0,
 * 0x021E080C (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */

extern void *TRADE_HISTORY_GetFromSave(void *sys);

void *GAME_DATA_GetTradeHistory(void **h)
{
    return TRADE_HISTORY_GetFromSave(*h);
}
