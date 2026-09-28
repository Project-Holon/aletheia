/*
 * function: func_020825F0
 * address:  0x020825F0
 * packet:   pkt_020825F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_StopDma (libmi.TWL.HYB.a mi_dma.o)
 *
 * symbols:
 *   OS_DisableInterrupts           0x02087988  arm
 *   OS_RestoreInterrupts           0x0208799C  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef int BOOL;
typedef u32 OSIntrMode;

#define REG_DMA0SAD_ADDR 0x040000B0
#define REG_DMA0CNT_ADDR 0x040000B8
#define MI_DMA_ENABLE    0x80000000
#define MI_DMA_REGADDR(dmaNo, reg) (((dmaNo) * 12) + (reg))

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);

void func_020825F0(u32 dmaNo)
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
