/*
 * function: CRYPTOi_MyAlloc
 * address:  0x021CAAB4
 * packet:   pkt_ov114_021CAAB4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(util.o).  decl_line 39, param size.
 *
 * symbols:
 *   d_021D422C   0x021D422C  data
 *   OS_AllocFromHeap   0x020868E0  arm
 */
typedef unsigned long u32;

extern char d_021D422C[];
extern void *OS_AllocFromHeap(int heap, long size);

typedef void *(*CryptoAlloc)(u32 size);

void *CRYPTOi_MyAlloc(u32 size)
{
    CryptoAlloc alloc = *(CryptoAlloc *)(d_021D422C + 4);

    if (alloc)
        return alloc(size);
    return OS_AllocFromHeap(0, -1);
}
