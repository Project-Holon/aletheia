/*
 * function: PMSI_PARAM_CheckCanceled
 * address:  0x0202411C
 * packet:   pkt_0202411C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf accessor: byte at +1.
 *
 * symbols:
 *   (none - no relocations)
 */

int PMSI_PARAM_CheckCanceled(unsigned char *p)
{
    return p[1];
}
