/*
 * function: PMSI_PARAM_GetWord
 * address:  0x02024124
 * packet:   pkt_02024124
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf accessor: halfword at +0x18.
 *
 * symbols:
 *   (none - no relocations)
 */

unsigned int PMSI_PARAM_GetWord(unsigned short *p)
{
    return p[12];
}
