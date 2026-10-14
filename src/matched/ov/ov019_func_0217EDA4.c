/*
 * function: UNION_MSG_GetMultiBattleInviteDeclinedMsg
 * address:  0x0217EDA4
 * packet:   pkt_ov019_0217EDA4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180304  0x02180304  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of UNION_MSG_GetSpinTradeChatMsg.
 */

typedef unsigned short u16;

extern const u16 d_02180304[];

u16 UNION_MSG_GetMultiBattleInviteDeclinedMsg(int i)
{
    return d_02180304[i];
}
