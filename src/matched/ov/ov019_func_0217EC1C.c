/*
 * function: UNION_MSG_GetTalkParentGreetingMsg
 * address:  0x0217EC1C
 * packet:   pkt_ov019_0217EC1C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0218034C  0x0218034C  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkParentMain.
 */

typedef unsigned short u16;

extern const u16 d_0218034C[];

u16 UNION_MSG_GetTalkParentGreetingMsg(int i)
{
    return d_0218034C[i];
}
