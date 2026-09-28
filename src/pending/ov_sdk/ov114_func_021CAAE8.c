/*
 * function: CRYPTOi_MyFree
 * address:  0x021CAAE8
 * packet:   pkt_ov114_021CAAE8
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(util.o).  decl_line 51, param ptr.
 *
 * symbols:
 *   d_021D422C   0x021D422C  data
 *   OS_FreeToHeap   0x020869E8  arm
 */
typedef unsigned long u32;

extern char d_021D422C[];
extern void OS_FreeToHeap(int heap, void *ptr);

typedef void (*CryptoFree)(void *ptr);

void CRYPTOi_MyFree(void *ptr)
{
    CryptoFree free = *(CryptoFree *)d_021D422C;

    if (free)
        free(ptr);
    else
        OS_FreeToHeap(0, (void *)-1);
}
