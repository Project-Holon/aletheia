/*
 * function: acAlloc
 * address:  0x021CD55C
 * packet:   pkt_ov016_021CD55C
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

void *acAlloc(void *unused, unsigned long size)
{
    return DWCi_HEAPlAllocEx(size, 0x20);
}
