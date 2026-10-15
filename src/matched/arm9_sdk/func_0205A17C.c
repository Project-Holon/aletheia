/*
 * function: DWC_AllocEx
 * address:  0x0205A17C
 * packet:   pkt_0205A17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AllocEx (libdwccommon.TWL.HYB.a dwc_memfunc.o)
 *
 * symbols:
 *   DWCi_SetAllocateHeader 0x0205A134 arm
 *   s_mem                  0x02146AB4 data
 */

typedef void *(*DWCiMemAlloc)(int, unsigned long, int);
typedef void (*DWCiMemFree)(int, void *, unsigned long);
typedef struct { DWCiMemFree free; DWCiMemAlloc alloc; } DWCiMemFunc;

extern DWCiMemFunc s_mem;
extern void *DWCi_SetAllocateHeader(void *ptr, unsigned long size);

void *DWC_AllocEx(int name, unsigned long size, int align)
{
    void *ptr = s_mem.alloc(name, size + 0x20, align);
    if (ptr == 0)
        return 0;
    return DWCi_SetAllocateHeader(ptr, size);
}
