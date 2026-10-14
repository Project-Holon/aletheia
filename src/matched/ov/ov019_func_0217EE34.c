/*
 * function: UNION_MSG_GetMultiBattleStartMsg
 * address:  0x0217EE34
 * packet:   pkt_ov019_0217EE34
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0218030C  0x0218030C  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_ColosseumEnterChildMain.
 */

typedef unsigned short u16;

extern const u16 d_0218030C[];

u16 UNION_MSG_GetMultiBattleStartMsg(int i)
{
    return d_0218030C[i];
}
