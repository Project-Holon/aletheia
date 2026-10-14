/*
 * function: UNION_MSG_GetTalkMenuPromptMsg
 * address:  0x0217EC88
 * packet:   pkt_ov019_0217EC88
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180300  0x02180300  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkParentMain and UNION_ONESELF_BattleMenuMain.
 */

typedef unsigned short u16;

extern const u16 d_02180300[];

u16 UNION_MSG_GetTalkMenuPromptMsg(int i)
{
    return d_02180300[i];
}
