/*
 * function: CONFIG_GetButtonMode
 * address:  0x02008428
 * packet:   pkt_02008428
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 *
 * symbols:
 *   CONFIG_GetButtonMode  0x02008428  thumb
 */

int CONFIG_GetButtonMode(unsigned short *p)
{
    return ((unsigned int)*p << 22) >> 31;
}
