/*
 * function: CRYPTOi_MyAlloc
 * address:  0x021CAAB4
 * packet:   pkt_ov114_021CAAB4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi_MyAlloc (libcrypto.TWL.HYB.a(util.o))
 *
 * symbols:
 *   func_020868E0  0x020868E0  arm
 *   gCryptoAllocators     0x021D422C  data
 */

#include "../include/G_CryptoAllocators.h"

extern void *func_020868E0(int id, int heap, unsigned long size);
extern struct CryptoAllocators gCryptoAllocators;

void *CRYPTOi_MyAlloc(unsigned long size)
{
	if (gCryptoAllocators.alloc_fn != 0)
		return gCryptoAllocators.alloc_fn(size);
	return func_020868E0(0, -1, size);
}
