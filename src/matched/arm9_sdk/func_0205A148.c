/*
 * function: DWCi_GetAllocateSize
 * address:  0x0205A148
 * packet:   pkt_0205A148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_GetAllocateHeader    0x0205A12C  arm
*/

typedef struct {
    unsigned long magic;
    unsigned long size;
    unsigned char pad[24];
} _tagDWCiAllocHeader;
extern void *DWCi_GetAllocateHeader(char *p);

unsigned long DWCi_GetAllocateSize(char *ptr)
{
    _tagDWCiAllocHeader *header = DWCi_GetAllocateHeader(ptr);
    return header->size;
}
