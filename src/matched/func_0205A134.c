/*
 * function: DWCi_SetAllocateHeader
 * address:  0x0205A134
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwccommon dwc_memfunc.o. 32-byte allocation header; the return is header + 1.
 */
typedef struct {
    unsigned long magic;
    unsigned long size;
    unsigned char pad[24];
} _tagDWCiAllocHeader;

void *DWCi_SetAllocateHeader(void *ptr, unsigned long size)
{
    _tagDWCiAllocHeader *header = (_tagDWCiAllocHeader *)ptr;
    header->size = size;
    header->magic = 0x4457434d;
    return header + 1;
}
