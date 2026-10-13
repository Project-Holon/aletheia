/*
 * file:     dwc_memfunc.c
 * unit:     yes
 * function: DWCi_GetAllocateHeader, func_0205A134, func_0205A148, func_0205A158, func_0205A16C, func_0205A17C, func_0205A1B0, func_0205A1EC, func_0205A200, func_0205A26C, func_0205A280, func_0205A29C, func_0205A2B4
 * address:  0x0205A12C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   s_mem  0x02146AB4  data  a4
 */
typedef struct {
    unsigned long magic;
    unsigned long size;
    unsigned char pad[24];
} _tagDWCiAllocHeader;

typedef void *(*DWCiMemAlloc)(int, unsigned long, int);

typedef void (*DWCiMemFree)(int, void *, unsigned long);

typedef struct { DWCiMemFree free; DWCiMemAlloc alloc; } DWCiMemFunc;

typedef void *(*DWCiMemAlloc_0205A1B0)(int, unsigned long);

extern void *DWC_AllocEx(int name, unsigned long size, int tag);
extern unsigned long DWCi_GetAllocateSize(void *ptr);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
void *DWCi_GetAllocateHeader(char *p);
void *DWCi_SetAllocateHeader(void *ptr, unsigned long size);
unsigned long func_0205A148(char *ptr);
void DWCi_SetMemFunc(DWCiMemAlloc alloc, DWCiMemFree free);
void *DWC_Alloc(int name, unsigned long size);
void *func_0205A17C(int name, unsigned long size, int align);
void DWC_Free(int name, void *ptr, unsigned long size);
void *func_0205A1EC(int name, void *ptr, unsigned long oldsize, unsigned long newsize);
void *DWC_ReallocEx(int name, void *ptr, unsigned long oldsize, unsigned long newsize, int align);
void *DWCi_GsMalloc(unsigned long size);
void *DWCi_GsRealloc(void *ptr, unsigned long size);
void DWCi_GsFree(void *ptr);
void *DWCi_GsMemalign(unsigned long boundary, unsigned long size);
extern DWCiMemFunc s_mem;

void *DWCi_GetAllocateHeader(char *p)
{
    return p - 0x20;
}





void *DWCi_SetAllocateHeader(void *ptr, unsigned long size)
{
    _tagDWCiAllocHeader *header = (_tagDWCiAllocHeader *)ptr;
    header->size = size;
    header->magic = 0x4457434d;
    return header + 1;
}





unsigned long func_0205A148(char *ptr)
{
    _tagDWCiAllocHeader *header = DWCi_GetAllocateHeader(ptr);
    return header->size;
}





static DWCiMemFunc s_mem;





void DWCi_SetMemFunc(DWCiMemAlloc alloc, DWCiMemFree free)
{
    s_mem.alloc = alloc;
    s_mem.free = free;
}





void *DWC_Alloc(int name, unsigned long size)
{
    return DWC_AllocEx(name, size, 32);
}





/*
 * sdk:      DWC_AllocEx (libdwccommon.TWL.HYB.a dwc_memfunc.o)
 */
void *func_0205A17C(int name, unsigned long size, int align)
{
    void *ptr = s_mem.alloc(name, size + 0x20, align);
    if (ptr == 0)
        return 0;
    return DWCi_SetAllocateHeader(ptr, size);
}





void DWC_Free(int name, void *ptr, unsigned long size)
{
    _tagDWCiAllocHeader *header;
    if (ptr == 0)
        return;
    header = DWCi_GetAllocateHeader(ptr);
    s_mem.free(name, header, header->size + 32);
}




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
