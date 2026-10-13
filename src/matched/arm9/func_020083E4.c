/*
 * function: CONFIG_GetAppliedFlag
 * address:  0x020083E4
 * packet:   pkt_020083E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: bit 9 of the u16 at *p.
 *
 * symbols:
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 */

int CONFIG_GetAppliedFlag(unsigned short *p)
{
    return ((unsigned int)*p << 23) >> 31;
}
