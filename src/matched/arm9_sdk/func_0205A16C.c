/*
 * function: DWC_Alloc
 * address:  0x0205A16C
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
extern void *DWC_AllocEx(int name, unsigned long size, int tag);

void *DWC_Alloc(int name, unsigned long size)
{
    return DWC_AllocEx(name, size, 32);
}
