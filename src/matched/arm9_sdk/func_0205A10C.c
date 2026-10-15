/*
 * function: DWCi_GetGamecode
 * address:  0x0205A10C
 * packet:   pkt_0205A10C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   s_data_02146AAC  0x02146AAC  data
 */

extern void *s_data_02146AAC;

void *DWCi_GetGamecode(void)
{
    return s_data_02146AAC;
}
