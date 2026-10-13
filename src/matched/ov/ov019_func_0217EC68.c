/*
 * function: func_0217EC68
 * address:  0x0217EC68
 * packet:   pkt_ov019_0217EC68
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0218053C  0x0218053C  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from UNION_ONESELF_TalkChildMain.
 */

typedef unsigned short u16;

extern const u16 d_0218053C[];

u16 func_0217EC68(int i)
{
    return d_0218053C[i - 2];
}
