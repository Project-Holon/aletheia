/*
 * file:     unit_0205A134_p02.c
 * unit:     yes
 * function: func_0205A16C, func_0205A17C, func_0205A1B0
 * address:  0x0205A16C
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
 *   DWCi_SetAllocateHeader 0x0205A134 arm
 *   s_mem                  0x02146AB4 data
 */
typedef void *(*DWCiMemAlloc_0205A17C)(int, unsigned long, int);

typedef void (*DWCiMemFree)(int, void *, unsigned long);

typedef struct { DWCiMemFree free; DWCiMemAlloc_0205A17C alloc; } DWCiMemFunc;

typedef struct { unsigned long magic; unsigned long size; unsigned char pad[24]; } _tagDWCiAllocHeader;

typedef void *(*DWCiMemAlloc_0205A1B0)(int, unsigned long);

extern void *DWC_AllocEx(int name, unsigned long size, int tag);
extern void *DWCi_SetAllocateHeader(void *ptr, unsigned long size);
extern void *func_0205A12C(char *p);
void *DWC_Alloc(int name, unsigned long size);
void *func_0205A17C(int name, unsigned long size, int align);
void DWC_Free(int name, void *ptr);
extern DWCiMemFunc s_mem;


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


static DWCiMemFunc s_mem;


void DWC_Free(int name, void *ptr)
{
    _tagDWCiAllocHeader *header;
    if (ptr == 0)
        return;
    header = func_0205A12C(ptr);
    s_mem.free(name, header, header->size + 32);
}
