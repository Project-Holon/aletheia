/*
 * function: CRYPTO_SetMemAllocator
 * address:  0x021CAB1C
 * packet:   pkt_ov114_021CAB1C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libcrypto.TWL.HYB.a(util.o).  decl_line 105, params alloc, free,
 * realloc.
 *
 * symbols:
 *   d_021D422C   0x021D422C  data
 */

#include "../include/G_CryptoAllocators.h"

extern struct CryptoAllocators d_021D422C;

void CRYPTO_SetMemAllocator(void *alloc, void *free, void *realloc)
{
    *(void **)(((char *)&d_021D422C) + 4) = alloc;
    *(void **)(((char *)&d_021D422C) + 0) = free;
    *(void **)(((char *)&d_021D422C) + 8) = realloc;
}
