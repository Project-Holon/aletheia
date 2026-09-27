/*
 * function: DWCi_GsFree
 * address:  0x0205A29C
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
extern void DWC_Free(int name, void *ptr, unsigned long size);

void DWCi_GsFree(void *ptr)
{
    DWC_Free(9, ptr, 0);
}
