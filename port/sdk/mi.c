/*
 * port/sdk/mi.c -- the MI module shim: the memcpy/memset family.
 *
 * On the DS these are DMA or CPU loops with width and alignment guarantees;
 * on the host they are memcpy and memset.  The width in the SDK name is the
 * *unit* the copy is performed in, not an alignment the caller must honour
 * for the 8-bit forms, so the byte forms take anything and the 16/32-bit
 * forms assume the caller's alignment exactly as the SDK does.
 *
 * MIi_CpuClearFast appears in the matched tree under its address spelling
 * (func_02082AC0, see src/matched/func_02008AF0.c) with the argument order
 * (value, dest, size); the alias below preserves that order rather than
 * normalising it, because the matched call site is the authority.
 */

#include <string.h>

#include "port.h"

void MI_CpuCopy8(const void *src, void *dst, u32 size)
{
    memcpy(dst, src, (size_t)size);
}

void MI_CpuCopy16(const void *src, void *dst, u32 size)
{
    memcpy(dst, src, (size_t)size & ~(u32)1);
}

void MI_CpuCopy32(const void *src, void *dst, u32 size)
{
    memcpy(dst, src, (size_t)size & ~(u32)3);
}

void MI_CpuFill8(void *dst, u8 value, u32 size)
{
    memset(dst, (int)value, (size_t)size);
}

void MI_CpuClear8(void *dst, u32 size)
{
    memset(dst, 0, (size_t)size);
}

void MI_CpuFill32(void *dst, u32 value, u32 size)
{
    u8 *p = (u8 *)dst;
    u32 i;

    for (i = 0; i + 4 <= size; i += 4) {
        bw_wr32(p + i, value);
    }
}

void MI_CpuClear32(void *dst, u32 size)
{
    MI_CpuFill32(dst, 0, size);
}

/*
 * MIi_CpuClearFast at 0x02082AC0, called as func_02082AC0(value, dst, size).
 */
void func_02082AC0(u32 value, void *dst, u32 size)
{
    MI_CpuFill32(dst, value, size);
}
