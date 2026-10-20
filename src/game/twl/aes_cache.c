/*
 * file:     aes_cache.c
 * unit:     yes
 * function: AESi_FlushRange, AESi_InvalidateRange
 * address:  0x02707C2C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libaes.TWL.HYB.a aes_cache.o
 */
#include "../types.h"

extern void DC_FlushRange(const void *start, u32 bytes);
extern void DC_FlushAll(void);
extern void IC_InvalidateRange(const void *start, u32 bytes);
extern void IC_InvalidateAll(void);
extern void DC_StoreRange(const void *start, u32 bytes);
extern void DC_InvalidateRange(const void *start, u32 bytes);
void AESi_FlushRange(void *addr, u32 size);
void AESi_InvalidateRange(void *addr, u32 size);

void AESi_FlushRange(void *addr, u32 size)
{
    if (size < 0x2400) {
        DC_FlushRange(addr, size);
    } else {
        DC_FlushAll();
    }
}

void AESi_InvalidateRange(void *addr, u32 size)
{
    if (size < 0x400) {
        IC_InvalidateRange(addr, size);
    } else {
        IC_InvalidateAll();
    }

    if (size < 0x2400) {
        u32 end = (uptr)addr + size;
        if ((uptr)addr & 0x1F) {
            DC_StoreRange(addr, 1);
        }
        if (end & 0x1F) {
            DC_StoreRange((const void *)(end - 1), 1);
        }
        DC_InvalidateRange(addr, size);
    } else {
        DC_FlushAll();
    }
}
