/*
 * function: UNION_MSG_GetSpinTradeStartMsg
 * address:  0x0217EDEC
 * packet:   pkt_ov019_0217EDEC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180358  0x02180358  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */

typedef unsigned short u16;

extern const u16 d_02180358[];

u16 UNION_MSG_GetSpinTradeStartMsg(int i)
{
    return d_02180358[i];
}
