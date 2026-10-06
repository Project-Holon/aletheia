/*
 * file:     unit_0205A134_p03.c
 * unit:     yes
 * function: func_0205A1EC, func_0205A200, func_0205A26C, func_0205A280, func_0205A29C, func_0205A2B4
 * address:  0x0205A1EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void *DWC_AllocEx(int name, unsigned long size, int align);
extern unsigned long DWCi_GetAllocateSize(void *ptr);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern void DWC_Free(int name, void *ptr, unsigned long size);
extern void *DWC_Alloc(int name, unsigned long size);
void *func_0205A1EC(int name, void *ptr, unsigned long oldsize, unsigned long newsize);
void *DWC_ReallocEx(int name, void *ptr, unsigned long oldsize, unsigned long newsize, int align);
void *DWCi_GsMalloc(unsigned long size);
void *DWCi_GsRealloc(void *ptr, unsigned long size);
void DWCi_GsFree(void *ptr);
void *DWCi_GsMemalign(unsigned long boundary, unsigned long size);


/*
 * The ARM9 listing labels this address func_0205A1EC; it is dwc_memfunc.o's DWC_Realloc, forcing align 32 (the SDK table's CTRDG_DmaCopy32 attribution here does not match the linked bytes).
 */
void *func_0205A1EC(int name, void *ptr, unsigned long oldsize, unsigned long newsize)
{
    return DWC_ReallocEx(name, ptr, oldsize, newsize, 32);
}


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


void *DWCi_GsMalloc(unsigned long size)
{
    return DWC_Alloc(9, size);
}


void *DWCi_GsRealloc(void *ptr, unsigned long size)
{
    return func_0205A1EC(9, ptr, size, size);
}


void DWCi_GsFree(void *ptr)
{
    DWC_Free(9, ptr, 0);
}


void *DWCi_GsMemalign(unsigned long boundary, unsigned long size)
{
    return DWC_AllocEx(9, size, boundary);
}
