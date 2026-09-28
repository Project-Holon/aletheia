/*
 * function: func_021DFAA0
 * address:  0x021DFAA0
 * packet:   pkt_021DFAA0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Untraced ARM accessor that sits in the tail of func_021DFA6C's extent (the
 * +0x84 half of the pair at 0x021DFA98/0x021DFAA0).  It is reached only by the
 * `bx ip` at the end of the func_021DF224 thunk, so disasm.py never labelled it
 * a start; per the brief's rule 10 the TARGET is filed first and the `matched`
 * class then attests the thunk's pool word that names it.
 */

typedef unsigned int u32;

u32 func_021DFAA0(u32 p)
{
    return p + 0x84;
}
