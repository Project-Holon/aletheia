/*
 * function: CRYPTOi_MyFree
 * address:  0x021CAAE8
 * packet:   pkt_ov114_021CAAE8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi_MyFree (libcrypto.TWL.HYB.a(util.o))
 *
 * symbols:
 *   OS_FreeToHeap  0x020869E8  arm
 *   gCryptoAllocators     0x021D422C  data
 */

#include "../include/G_CryptoAllocators.h"

extern void OS_FreeToHeap(int id, int heap, void *ptr);
extern struct CryptoAllocators gCryptoAllocators;

void CRYPTOi_MyFree(void *ptr)
{
	if (gCryptoAllocators.free_fn != 0)
		gCryptoAllocators.free_fn(ptr);
	else
		OS_FreeToHeap(0, -1, ptr);
}
