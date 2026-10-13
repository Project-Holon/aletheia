/*
 * function: MCSS_GetAnimCtrl
 * address:  0x02015EE8
 * packet:   pkt_02015EE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module (mcss.c). Returns the address
 * of the embedded renderer sub-object at +0x34.
 *
 * Addresses are Black-image addresses.
 */

void *MCSS_GetAnimCtrl(void *p)
{
    return (char *)p + 0x34;
}
