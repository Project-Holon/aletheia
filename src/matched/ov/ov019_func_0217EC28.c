/*
 * function: func_0217EC28
 * address:  0x0217EC28
 * packet:   pkt_ov019_0217EC28
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180330  0x02180330  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC.
 */

typedef unsigned short u16;

extern const u16 d_02180330[];

u16 func_0217EC28(int i)
{
    return d_02180330[i];
}
