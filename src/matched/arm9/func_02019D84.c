/*
 * function: func_02019D84
 * address:  0x02019D84
 * packet:   pkt_02019D84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0209E42C 0x0209E42C data a2
 *
 * Witness leaf for ov119 func_021DD0CC: membership test in a 12 entry u16 table.
 */

extern const unsigned short d_0209E42C[];

int func_02019D84(unsigned short value)
{
    unsigned i;
    for (i = 0; i < 12; i++) {
        if (value == d_0209E42C[i])
            return 1;
    }
    return 0;
}
