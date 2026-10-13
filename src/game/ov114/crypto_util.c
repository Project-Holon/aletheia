/*
 * file:     crypto_util.c
 * unit:     yes
 * function: CRYPTOi_MyAlloc, CRYPTOi_MyFree, CRYPTO_SetMemAllocator
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
 *   gCryptoAllocators     0x021D422C  data
 *   func_020869E8  0x020869E8  arm
 */
#include "crypto_types.h"

extern void *func_020868E0(int arenaId, int heap, unsigned long size);
extern void func_020869E8(int arenaId, int heap, void *ptr);
void *CRYPTOi_MyAlloc(unsigned long size);
void CRYPTOi_MyFree(void *ptr);
void CRYPTO_SetMemAllocator(void *(*allocFunc)(unsigned long), void (*freeFunc)(void *), void *(*reallocFunc)(void *, unsigned long));

/*
 * sdk:      CRYPTOi_MyAlloc (libcrypto.TWL.HYB.a(util.o))
 *
 * Allocates through the hook set by CRYPTO_SetMemAllocator, else from the main arena.
 */
void *CRYPTOi_MyAlloc(unsigned long size)
{
    if (gCryptoAllocators.allocFunc != 0)
        return gCryptoAllocators.allocFunc(size);
    return func_020868E0(0, -1, size);
}

/*
 * sdk:      CRYPTOi_MyFree (libcrypto.TWL.HYB.a(util.o))
 */
void CRYPTOi_MyFree(void *ptr)
{
    if (gCryptoAllocators.freeFunc != 0)
        gCryptoAllocators.freeFunc(ptr);
    else
        func_020869E8(0, -1, ptr);
}

/*
 * Installs the allocation hooks used by the library.
 */
void CRYPTO_SetMemAllocator(void *(*allocFunc)(unsigned long), void (*freeFunc)(void *), void *(*reallocFunc)(void *, unsigned long))
{
    gCryptoAllocators.allocFunc = allocFunc;
    gCryptoAllocators.freeFunc = freeFunc;
    gCryptoAllocators.reallocFunc = reallocFunc;
}
