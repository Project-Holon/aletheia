/*
 * function: func_0217ED80
 * address:  0x0217ED80
 * packet:   pkt_ov019_0217ED80
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180314  0x02180314  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of func_0217ED64.
 */

typedef unsigned short u16;

extern const u16 d_02180314[];

u16 func_0217ED80(int i)
{
    return d_02180314[i];
}
