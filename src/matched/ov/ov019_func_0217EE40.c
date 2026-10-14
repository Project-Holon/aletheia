/*
 * function: UNION_MSG_GetMultiBattleBusyMsg
 * address:  0x0217EE40
 * packet:   pkt_ov019_0217EE40
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021802FC  0x021802FC  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */

typedef unsigned short u16;

extern const u16 d_021802FC[];

u16 UNION_MSG_GetMultiBattleBusyMsg(int i)
{
    return d_021802FC[i];
}
