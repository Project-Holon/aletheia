/*
 * file:     mi_dma_card.c
 * function: MIi_CardDmaCopy32
 * address:  0x020835A0
 * packet:   pkt_020835A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_CardDmaCopy32 (libmi.TWL.HYB.a mi_dma_card.o)
 *
 * symbols:
 *   MIi_CheckAnotherAutoDMA        0x02082680  arm
 *   MIi_CheckDma0SourceAddress     0x0208270C  arm
 *   MIi_DmaSetParameters           0x01FF8020  arm
 */

#include "../types.h"
#include "../sdk_ioreg.h"
#include "../sdk_os.h"

#define MI_DMA_ENABLE    0x80000000
#define MI_DMA_REGADDR(dmaNo, reg) (((dmaNo) * 12) + (reg))

#include "os_system.h"

#include "mi_dma.h"
#include "../arm9_autoload0_ITCM/mi_dma.h"

static inline void MIi_Wait(vu32 *dmaCntp)
{
    while (*dmaCntp & MI_DMA_ENABLE) {
    }
}

void MIi_CardDmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    vu32 *dmaCntp;

    MIi_CheckAnotherAutoDMA(dmaNo, 0xFFFFFFFF);
    MIi_CheckDma0SourceAddress(dmaNo, (uptr)src, size, 0x01000000);

    if (size == 0) {
        return;
    }
    dmaCntp = (vu32 *)(REG_DMA0SAD_ADDR + (dmaNo * 3 + 2) * 4);
    MIi_Wait(dmaCntp);
    MIi_DmaSetParameters(dmaNo, (uptr)src, (uptr)dest, 0xAF000001, 0);
}
