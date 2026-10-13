/*
 * function: func_0217EC78
 * address:  0x0217EC78
 * packet:   pkt_ov019_0217EC78
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180570  0x02180570  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkChildMain.
 */

typedef unsigned short u16;

extern const u16 d_02180570[];

u16 func_0217EC78(int i)
{
    return d_02180570[i - 2];
}
