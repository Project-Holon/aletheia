/*
 * function: UNION_MSG_GetNoEggInPartyMsg
 * address:  0x0217ECAC
 * packet:   pkt_ov019_0217ECAC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180318  0x02180318  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkParentMain.
 */

typedef unsigned short u16;

extern const u16 d_02180318[];

u16 UNION_MSG_GetNoEggInPartyMsg(int i)
{
    return d_02180318[i];
}
