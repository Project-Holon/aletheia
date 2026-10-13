/*
 * function: func_0217ECA0
 * address:  0x0217ECA0
 * packet:   pkt_ov019_0217ECA0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180320  0x02180320  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkParentMain.
 */

typedef unsigned short u16;

extern const u16 d_02180320[];

u16 func_0217ECA0(int i)
{
    return d_02180320[i];
}
