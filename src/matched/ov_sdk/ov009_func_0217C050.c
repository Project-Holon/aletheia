/*
 * function: DWCi_Prof_Alloc
 * address:  0x0217C050
 * packet:   pkt_ov009_0217C050
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWC_Alloc                    0x0205A16C  arm
*/

extern void *DWC_Alloc(int name, unsigned long size);

static void *DWCi_Prof_Alloc(int name, unsigned long size)
{
    return DWC_Alloc(0, size);
}
