/*
 * file:     mi_dma.c
 * unit:     yes
 * function: MIi_DmaFill32, MIi_DmaCopy32, MIi_DmaCopy16, MIi_DmaFill32Async, MIi_DmaCopy32Async, MI_WaitDma, MI_StopDma, MI_StopAllDma, MIi_CheckAnotherAutoDMA, MIi_CheckDma0SourceAddress
 * address:  0x020821C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_DmaSetParameters           0x01FF8020  arm
 *   MIi_CheckDma0SourceAddress     0x0208270C  arm
 *   MI_WaitDma                     0x02082594  arm
 *   OSi_EnterDmaCallback           0x020848A4  arm
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 *   MI_StopDma  0x020825F0  arm
 *   OS_Terminate                   0x02088234  arm
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_os.h"

typedef void (*MIDmaCallback)(void *arg);

#include "os_system.h"
#include "../arm9_autoload0_ITCM/mi_dma.h"
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
void MI_WaitDma(u32 dmaNo);
#include "os_interrupt.h"
void MI_StopDma(u32 dmaNo);
#include "os_terminate_processor.h"
void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable);
void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
void MIi_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
void MI_StopAllDma(void);
void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);



#define MI_DMA_ENABLE    0x80000000

#define MI_DMA_REGADDR(dmaNo, reg) (((dmaNo) * 12) + (reg))

static inline void MIi_Wait(vu32 *dmaCntp)
{
    while (*dmaCntp & MI_DMA_ENABLE) {
    }
}

/*
 * sdk:      MIi_DmaFill32 (libmi.TWL.HYB.a mi_dma.o)
 */
void MIi_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable)
{
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }
    dmaCntp = (vu32 *)(REG_DMA0SAD_ADDR + (dmaNo * 3 + 2) * 4);
    MIi_Wait(dmaCntp);

    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, data, (uptr)dest, 0x85000000 | (size / 4), 0x12);
    } else {
        MIi_DmaSetParameters(dmaNo, data, (uptr)dest, 0x05000000 | (size / 4), 0x16);
    }
    MIi_Wait(dmaCntp);
}

/*
 * sdk:      MIi_DmaCopy32 (libmi.TWL.HYB.a mi_dma.o)
 */
void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable)
{
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }
    MIi_CheckDma0SourceAddress(dmaNo, (uptr)src, size, 0);

    dmaCntp = (vu32 *)(REG_DMA0SAD_ADDR + (dmaNo * 3 + 2) * 4);
    MIi_Wait(dmaCntp);

    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0x84000000 | (size / 4), 2);
    } else {
        MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0x04000000 | (size / 4), 6);
    }
    MIi_Wait(dmaCntp);
}

static inline void MIi_CallCallback(MIDmaCallback callback, void *arg)
{
    if (callback) {
        (callback)(arg);
    }
}

/*
 * sdk:      MIi_DmaCopy16 (libmi.TWL.HYB.a mi_dma.o)
 */
void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable)
{
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }
    MIi_CheckDma0SourceAddress(dmaNo, (uptr)src, size, 0);

    dmaCntp = (vu32 *)(REG_DMA0SAD_ADDR + (dmaNo * 3 + 2) * 4);
    MIi_Wait(dmaCntp);

    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0x80000000 | (size / 2), 2);
    } else {
        MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0x00000000 | (size / 2), 6);
    }
    MIi_Wait(dmaCntp);
}

/*
 * sdk:      MIi_DmaFill32Async (libmi.TWL.HYB.a mi_dma.o)
 */
void MIi_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable)
{
    if (size == 0) {
        MIi_CallCallback(callback, arg);
    } else {
        MI_WaitDma(dmaNo);

        if (callback) {
            OSi_EnterDmaCallback(dmaNo, callback, arg);
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, data, (uptr)dest, 0xC5000000 | (size / 4), 0x10);
            } else {
                MIi_DmaSetParameters(dmaNo, data, (uptr)dest, 0x45000000 | (size / 4), 0x14);
            }
        } else {
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, data, (uptr)dest, 0x85000000 | (size / 4), 0x10);
            } else {
                MIi_DmaSetParameters(dmaNo, data, (uptr)dest, 0x05000000 | (size / 4), 0x14);
            }
        }
    }
}

/*
 * sdk:      MIi_DmaCopy32Async (libmi.TWL.HYB.a mi_dma.o)
 */
void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable)
{
    MIi_CheckDma0SourceAddress(dmaNo, (uptr)src, size, 0);

    if (size == 0) {
        MIi_CallCallback(callback, arg);
    } else {
        MI_WaitDma(dmaNo);

        if (callback) {
            OSi_EnterDmaCallback(dmaNo, callback, arg);
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0xC4000000 | (size / 4), 0);
            } else {
                MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0x44000000 | (size / 4), 4);
            }
        } else {
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0x84000000 | (size / 4), 0);
            } else {
                MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0x04000000 | (size / 4), 4);
            }
        }
    }
}

/*
 * sdk:      MI_WaitDma (libmi.TWL.HYB.a mi_dma.o)
 */
void MI_WaitDma(u32 dmaNo)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    vu32 *dmaCntp = (vu32 *)MI_DMA_REGADDR(dmaNo, REG_DMA0CNT_ADDR);

    while (*dmaCntp & MI_DMA_ENABLE) {
    }

    if (dmaNo == 0) {
        vu32 *p = (vu32 *)MI_DMA_REGADDR(dmaNo, REG_DMA0SAD_ADDR);
        *p = 0;
        *(p + 1) = 0;
        *(p + 2) = 0x81400001;
    }
    (void)OS_RestoreInterrupts(enabled);
}

/*
 * sdk:      MI_StopDma (libmi.TWL.HYB.a mi_dma.o)
 */
void MI_StopDma(u32 dmaNo)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    vu32 *dmaCntp = (vu32 *)MI_DMA_REGADDR(dmaNo, REG_DMA0CNT_ADDR);

    *dmaCntp &= ~0x3A000000;
    *dmaCntp &= ~MI_DMA_ENABLE;
    {
        u32 dummy = dmaCntp[0];
    }
    {
        u32 dummy = dmaCntp[0];
    }

    if (dmaNo == 0) {
        vu32 *p = (vu32 *)MI_DMA_REGADDR(dmaNo, REG_DMA0SAD_ADDR);
        *p = 0;
        *(p + 1) = 0;
        *(p + 2) = 0x81400001;
    }
    (void)OS_RestoreInterrupts(enabled);
}

void MI_StopAllDma(void)
{
    MI_StopDma(0);
    MI_StopDma(1);
    MI_StopDma(2);
    MI_StopDma(3);
}

/*
 * sdk:      MIi_CheckAnotherAutoDMA (libmi.TWL.HYB.a mi_dma.o)
 */
void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType)
{
    int n;

    for (n = 0; n < 3; n++) {
        u32 dmaCnt;
        u32 timing;

        if (n == dmaNo) {
            continue;
        }
        dmaCnt = *(vu32 *)MI_DMA_REGADDR(n, REG_DMA0CNT_ADDR);
        if ((dmaCnt & MI_DMA_ENABLE) == 0) {
            continue;
        }
        timing = dmaCnt & 0x38000000;
        if (timing == dmaType) {
            continue;
        }
        if (timing == 0x08000000 && dmaType == 0x10000000) {
            continue;
        }
        if (timing == 0x10000000 && dmaType == 0x08000000) {
            continue;
        }
        if (timing == 0x18000000 || timing == 0x20000000 || timing == 0x28000000 ||
            timing == 0x30000000 || timing == 0x38000000 || timing == 0x08000000 ||
            timing == 0x10000000) {
            OS_Terminate();
        }
    }
}

/*
 * sdk:      MIi_CheckDma0SourceAddress (libmi.TWL.HYB.a mi_dma.o)
 */
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir)
{
    if (dmaNo == 0) {
        u32 addStart = src & 0xFF000000;
        u32 addEnd;

        switch (dir) {
        case 0:
            addEnd = src + size;
            break;
        case 0x00800000:
            addEnd = src - size;
            break;
        default:
            addEnd = src;
            break;
        }
        addEnd &= 0xFF000000;

        if (addStart == 0x04000000 || addStart >= 0x08000000 ||
            addEnd == 0x04000000 || addEnd >= 0x08000000) {
            OS_Terminate();
        }
    }
}
