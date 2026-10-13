/*
 * function: func_0217ED04
 * address:  0x0217ED04
 * packet:   pkt_ov019_0217ED04
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0218033C  0x0218033C  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkPlayingChildMain.
 */

typedef unsigned short u16;

extern const u16 d_0218033C[];

u16 func_0217ED04(int i)
{
    return d_0218033C[i];
}
