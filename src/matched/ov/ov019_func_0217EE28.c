/*
 * function: UNION_MSG_GetMultiBattleWaitMsg
 * address:  0x0217EE28
 * packet:   pkt_ov019_0217EE28
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180334  0x02180334  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */

typedef unsigned short u16;

extern const u16 d_02180334[];

u16 UNION_MSG_GetMultiBattleWaitMsg(int i)
{
    return d_02180334[i];
}
