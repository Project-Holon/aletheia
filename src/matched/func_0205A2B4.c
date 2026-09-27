/*
 * function: DWCi_GsMemalign
 * address:  0x0205A2B4
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwccommon dwc_memfunc.o.
 */
extern void *DWC_AllocEx(int name, unsigned long size, int align);

void *DWCi_GsMemalign(unsigned long boundary, unsigned long size)
{
    return DWC_AllocEx(9, size, boundary);
}
