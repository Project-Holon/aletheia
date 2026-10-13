/*
 * function: aossAlloc
 * address:  0x021C0954
 * packet:   pkt_ov016_021C0954
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_HEAPlAllocEx            0x021D6414  arm
*/

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);

void *aossAlloc(unsigned long size)
{
    return DWCi_HEAPlAllocEx(size, 0x20);
}
