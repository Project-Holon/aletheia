/*
 * function: func_02021730
 * address:  0x02021730
 * packet:   pkt_02021730
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module: word field of a 0x14-byte strided
 * array.
 *
 * Addresses are Black-image addresses.
 */

int func_02021730(char *p, int i)
{
    return *(int *)(p + i * 0x14 + 4);
}
