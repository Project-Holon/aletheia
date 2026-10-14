/*
 * function: UNION_MSG_GetTalkChildBusyMsg
 * address:  0x0217EC34
 * packet:   pkt_ov019_0217EC34
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180348  0x02180348  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkChildMain.
 */

typedef unsigned short u16;

extern const u16 d_02180348[];

u16 UNION_MSG_GetTalkChildBusyMsg(int i)
{
    return d_02180348[i];
}
