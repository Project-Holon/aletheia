/*
 * function: func_0217EC88
 * address:  0x0217EC88
 * packet:   pkt_ov019_0217EC88
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02180300  0x02180300  data a2
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217C2AC and func_0217C88C.
 */

typedef unsigned short u16;

extern const u16 d_02180300[];

u16 func_0217EC88(int i)
{
    return d_02180300[i];
}
