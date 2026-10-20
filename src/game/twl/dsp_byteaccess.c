/*
 * file:     dsp_byteaccess.c
 * unit:     yes
 * function: DSP_LoadData, DSP_Store8, DSP_StoreData
 * address:  0x0270633C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libdsp.TWL.HYB.a dsp_byteaccess.o
 *
 * The bodies were written from the listing.
 *
 * symbols:
 *   DSP_SendFifoExCore  0x02705088  arm
 *   DSP_RecvFifoExCore  0x02705150  arm
 */

#include "../types.h"
#include "../sdk_ioreg.h"

#define DSP_CTRL (*(volatile u16 *)REG_AES_WRFIFO_ADDR)

typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
#include "../arm9/os_emulator.h"
#include "dsp_if.h"

void DSP_LoadData(u32 addr, u8 *dst, u32 len)
{
    u16 t8;
    u16 t6;
    u16 t4;
    u32 ints;
    u32 n;
    u32 lo;
    int w;

    if (len == 0) {
        return;
    }
    lo = addr & 1;
    if (lo != 0) {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &t8, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        *dst++ = (u8)(t8 >> (lo * 8));
        addr++;
        len--;
    }
    if (((uptr)dst & 1) == 0) {
        n = len & ~1;
        if (n != 0) {
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_RecvFifoExCore(0, (u16 *)dst, addr >> 1, (u16)(n >> 1), 0);
            }
            DSP_CTRL &= 0xFFF1;
            OS_RestoreInterrupts(ints);
            dst += n;
            addr += n;
            len -= n;
        }
    } else {
        while (len >= 2) {
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_RecvFifoExCore(0, &t6, addr >> 1, 1, 0);
            }
            DSP_CTRL &= 0xFFF1;
            OS_RestoreInterrupts(ints);
            w = t6;
            len -= 2;
            dst[0] = (u8)w;
            dst[1] = (u8)(w >> 8);
            dst += 2;
            addr += 2;
        }
    }
    if (len != 0) {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &t4, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        *dst = (u8)(t4 >> ((addr & 1) * 8));
    }
}

void DSP_Store8(u32 addr, u32 val)
{
    u16 ra;
    u16 wa;
    u16 rb;
    u16 wb;
    u32 ints;

    if ((addr & 1) == 0) {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &ra, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        wa = (u16)((ra & 0xFF00) | (val & 0xFF));
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_SendFifoExCore(0, addr >> 1, &wa, 1, 0);
        }
        OS_RestoreInterrupts(ints);
    } else {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &rb, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        wb = (u16)((rb & 0xFF) | ((val << 8) & 0xFF00));
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_SendFifoExCore(0, addr >> 1, &wb, 1, 0);
        }
        OS_RestoreInterrupts(ints);
    }
}

void DSP_StoreData(u32 addr, u8 *src, u32 len)
{
    u16 w;
    u32 n;
    u32 ints;

    if (len == 0) {
        return;
    }
    if (addr & 1) {
        DSP_Store8(addr, *src++);
        addr++;
        len--;
    }
    if (((uptr)src & 1) == 0) {
        n = len & ~1;
        if (n != 0) {
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_SendFifoExCore(0, addr >> 1, (u16 *)src, (u16)(n >> 1), 0);
            }
            OS_RestoreInterrupts(ints);
            src += n;
            addr += n;
            len -= n;
        }
    } else {
        while (len >= 2) {
            w = src[0] | (src[1] << 8);
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_SendFifoExCore(0, addr >> 1, &w, 1, 0);
            }
            OS_RestoreInterrupts(ints);
            len -= 2;
            src += 2;
            addr += 2;
        }
    }
    if (len != 0) {
        DSP_Store8(addr, *src);
    }
}
