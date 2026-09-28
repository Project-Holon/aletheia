/*
 * function: DWCi_SetMemFunc
 * address:  0x0205A158
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   s_mem  0x02146AB4  data  a4
 *
 * TwlDWC libdwccommon dwc_memfunc.o. The file-local table has free at +0 and alloc at +4.
 */
typedef void *(*DWCiMemAlloc)(int, unsigned long);
typedef void (*DWCiMemFree)(int, void *, unsigned long);
typedef struct { DWCiMemFree free; DWCiMemAlloc alloc; } DWCiMemFunc;

static DWCiMemFunc s_mem;

void DWCi_SetMemFunc(DWCiMemAlloc alloc, DWCiMemFree free)
{
    s_mem.alloc = alloc;
    s_mem.free = free;
}
