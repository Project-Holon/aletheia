/*
 * function: DWC_Free
 * address:  0x0205A1B0
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   s_mem  0x02146AB4  data  a4
 *   DWCi_GetAllocateHeader  0x0205A12C  arm
 *
 * TwlDWC libdwccommon dwc_memfunc.o. The free hook takes name, header and the full block size.
 */
typedef struct { unsigned long magic; unsigned long size; unsigned char pad[24]; } _tagDWCiAllocHeader;

extern void *DWCi_GetAllocateHeader(char *p);

typedef void *(*DWCiMemAlloc)(int, unsigned long);
typedef void (*DWCiMemFree)(int, void *, unsigned long);
typedef struct { DWCiMemFree free; DWCiMemAlloc alloc; } DWCiMemFunc;

static DWCiMemFunc s_mem;

void DWC_Free(int name, void *ptr)
{
    _tagDWCiAllocHeader *header;
    if (ptr == 0)
        return;
    header = DWCi_GetAllocateHeader(ptr);
    s_mem.free(name, header, header->size + 32);
}
