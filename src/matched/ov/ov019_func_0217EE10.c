/*
 * function: UNION_MSG_GetDrawStartMsg
 * address:  0x0217EE10
 * packet:   pkt_ov019_0217EE10
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021802F0  0x021802F0  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */

typedef unsigned short u16;

extern const u16 d_021802F0[];

u16 UNION_MSG_GetDrawStartMsg(int i)
{
    return d_021802F0[i];
}
