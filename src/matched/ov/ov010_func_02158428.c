/*
 * function: func_02158428
 * address:  0x02158428
 * packet:   pkt_ov010_02158428
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, so disasm.py prints it inside the extent of
 * func_0215841C); sole blocker of ov018 func_0217D1C0. Followed by another
 * unlabelled leaf at 0x02158434.
 */

typedef unsigned char u8;

u8 func_02158428(u8 *p)
{
    return p[0x90C];
}
