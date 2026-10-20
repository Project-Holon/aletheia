/*
 * file:     mi_dma.c
 * function: MIi_DmaSetParameters
 * address:  0x01FF8020
 * packet:   pkt_01FF8020
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   OS_DisableInterrupts    0x02087988  arm
 *   OS_RestoreInterrupts    0x0208799C  arm
 */

#include "../types.h"
#include "../sdk_ioreg.h"

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int);

typedef union
{
    u32 b32;
    u16 b16;
} MIiDmaClearSrc;

void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode)
{
    int enabled;
    vu32 *p;

    if (!(mode & 1))
    {
        enabled = OS_DisableInterrupts();
    }

    p = (vu32 *)(REG_DMA0SAD_ADDR + dmaNo * 12);

    if (mode & 0x10)
    {
        MIiDmaClearSrc *srcp = (MIiDmaClearSrc *)(REG_DMA0FILL_ADDR + dmaNo * 4);
        srcp->b32 = src;
        src = (uptr)srcp;
    }
    else if (mode & 0x20)
    {
        MIiDmaClearSrc *srcp = (MIiDmaClearSrc *)(REG_DMA0FILL_ADDR + dmaNo * 4);
        srcp->b16 = (u16)src;
        src = (uptr)srcp;
    }

    *p = (vu32)src;
    *(p + 1) = (vu32)dest;
    *(p + 2) = (vu32)ctrl;

    if (mode & 2)
    {
        {
            u32 dummy = *(volatile u32 *)REG_DMA0SAD_ADDR;
        }
        {
            u32 dummy = *(volatile u32 *)REG_DMA0SAD_ADDR;
        }

        if (!(mode & 4))
        {
            if (dmaNo == 0)
            {
                *p = 0;
                *(p + 1) = 0;
                *(p + 2) = 0x81400001;
            }
        }
    }

    if (!(mode & 1))
    {
        OS_RestoreInterrupts(enabled);
    }

    if (mode & 2)
    {
        {
            u32 dummy = *(volatile u32 *)REG_DMA0SAD_ADDR;
        }
        {
            u32 dummy = *(volatile u32 *)REG_DMA0SAD_ADDR;
        }
    }
}
