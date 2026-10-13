/*
 * function: func_0205A148
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
 *   func_0205A12C    0x0205A12C  arm
*/

typedef struct {
    unsigned long magic;
    unsigned long size;
    unsigned char pad[24];
} _tagDWCiAllocHeader;
extern void *func_0205A12C(char *p);

unsigned long func_0205A148(char *ptr)
{
    _tagDWCiAllocHeader *header = func_0205A12C(ptr);
    return header->size;
}
