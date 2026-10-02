/*
 * function: func_02051830
 * address:  0x02051830
 * packet:   pkt_02051790
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the halfword at offset 0x70. Filed as the witness for ov094 func_021FD1CC.
 */

unsigned short func_02051830(char *p)
{
    return *(unsigned short *)(p + 0x70);
}
