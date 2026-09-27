/*
 * function: DWC_ReallocEx
 * address:  0x0205A200
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwccommon dwc_memfunc.o. The copy/free block is a single if-body so both paths share the tail return.
 */
extern void *DWC_AllocEx(int name, unsigned long size, int align);
extern unsigned long DWCi_GetAllocateSize(void *ptr);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern void DWC_Free(int name, void *ptr, unsigned long size);

void *DWC_ReallocEx(int name, void *ptr, unsigned long oldsize, unsigned long newsize, int align)
{
    void *newptr = DWC_AllocEx(name, newsize, align);
    if (newptr == 0)
        return 0;
    if (ptr != 0) {
        oldsize = DWCi_GetAllocateSize(ptr);
        if (oldsize <= newsize)
            newsize = oldsize;
        MI_CpuCopy8(ptr, newptr, newsize);
        DWC_Free(name, ptr, oldsize);
    }
    return newptr;
}
