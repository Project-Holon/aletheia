/*
 * function: UNION_MSG_GetSpinTradeWaitMsg
 * address:  0x0217EDE0
 * packet:   pkt_ov019_0217EDE0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0218035C  0x0218035C  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */

typedef unsigned short u16;

extern const u16 d_0218035C[];

u16 UNION_MSG_GetSpinTradeWaitMsg(int i)
{
    return d_0218035C[i];
}
