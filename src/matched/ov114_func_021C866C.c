/*
 * function: func_021C866C
 * address:  0x021C866C
 * packet:   pkt_ov114_021C866C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in a .word run (disasm.py only labels lr-saving
 * prologues).  Extent 0x021C866C..0x021C86A8 (60 bytes) read from the ov114
 * listing: 14 instructions plus one pool word naming d_021D3D2C.
 *
 * symbols:
 *   d_021D3D2C  0x021D3D2C  data  a4
 */

extern unsigned int d_021D3D2C[];

int func_021C866C(void)
{
    switch (d_021D3D2C[0]) {
    case 1:
        return 1;
    case 0x18:
        d_021D3D2C[0] = 1;
        return 1;
    }
    return 0;
}
