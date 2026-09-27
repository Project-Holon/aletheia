/*
 * function: DWCi_GsMalloc
 * address:  0x0205A26C
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwccommon dwc_memfunc.o. Allocation name DWCi_MEMNAME_GS (9).
 */
extern void *DWC_Alloc(int name, unsigned long size);

void *DWCi_GsMalloc(unsigned long size)
{
    return DWC_Alloc(9, size);
}
