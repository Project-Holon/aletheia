/*
 * function: PMSI_PARAM_GetSentenceType
 * address:  0x0202452C
 * packet:   pkt_0202452C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module: returns the first halfword.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

int PMSI_PARAM_GetSentenceType(const u16 *p)
{
    return *p;
}
