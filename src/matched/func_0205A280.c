/*
 * function: DWCi_GsRealloc
 * address:  0x0205A280
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwccommon dwc_memfunc.o. oldsize and newsize are both the caller's size.
 */
extern void *func_0205A1EC(int name, void *ptr, unsigned long oldsize, unsigned long newsize);

void *DWCi_GsRealloc(void *ptr, unsigned long size)
{
    return func_0205A1EC(9, ptr, size, size);
}
