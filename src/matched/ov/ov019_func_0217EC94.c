/*
 * function: func_0217EC94
 * address:  0x0217EC94
 * packet:   pkt_ov019_0217EC94
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0218032C  0x0218032C  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217D7A4 / func_0217D890.
 */

typedef unsigned short u16;

extern const u16 d_0218032C[];

u16 func_0217EC94(int i)
{
    return d_0218032C[i];
}
