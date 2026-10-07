/*
 * file:     unit_021CAAB4.c
 * unit:     yes
 * function: func_021CAAB4, func_021CAAE8, func_021CAB1C
 * address:  0x021CAAB4
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020868E0  0x020868E0  arm
 *   g_021D422C     0x021D422C  data
 *   func_020869E8  0x020869E8  arm
 *   d_021D422C   0x021D422C  data
 */
#include "../../matched/include/G_CryptoAllocators.h"

extern void *func_020868E0(int id, int heap, unsigned long size);
extern void func_020869E8(int id, int heap, void *ptr);
void *func_021CAAB4(unsigned long size);
void func_021CAAE8(void *ptr);
void CRYPTO_SetMemAllocator(void *alloc, void *free, void *realloc);
extern struct CryptoAllocators g_021D422C;
extern struct CryptoAllocators d_021D422C;


/*
 * sdk:      CRYPTOi_MyAlloc (libcrypto.TWL.HYB.a(util.o))
 */
void *func_021CAAB4(unsigned long size)
{
	if (g_021D422C.alloc_fn != 0)
		return g_021D422C.alloc_fn(size);
	return func_020868E0(0, -1, size);
}


/*
 * sdk:      CRYPTOi_MyFree (libcrypto.TWL.HYB.a(util.o))
 */
void func_021CAAE8(void *ptr)
{
	if (g_021D422C.free_fn != 0)
		g_021D422C.free_fn(ptr);
	else
		func_020869E8(0, -1, ptr);
}


void CRYPTO_SetMemAllocator(void *alloc, void *free, void *realloc)
{
    *(void **)(((char *)&d_021D422C) + 4) = alloc;
    *(void **)(((char *)&d_021D422C) + 0) = free;
    *(void **)(((char *)&d_021D422C) + 8) = realloc;
}
