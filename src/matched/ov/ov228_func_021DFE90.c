/*
 * function: func_021DFE90
 * address:  0x021DFE90
 * packet:   pkt_021DFC20
 * region:   ov228
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf in ov228: returns the byte at +0x378 of the overlay's
 * work object (0x378 built as 0xDE << 2).  Caller: arm9 sub_0200A358
 * (mystery_data.c).  Integrator: seed ov228 0x021DFE90.
 */

typedef unsigned char u8;

u8 func_021DFE90(u8 *p)
{
    return p[0x378];
}
