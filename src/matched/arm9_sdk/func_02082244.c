/*
 * function: MIi_DmaCopy32
 * address:  0x02082244
 * packet:   pkt_02082244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_DmaCopy32 (libmi.TWL.HYB.a mi_dma.o)
 *
 * symbols:
 *   MIi_CheckDma0SourceAddress     0x0208270C  arm
 *   MIi_DmaSetParameters           0x01FF8020  arm
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

void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode);
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);

static inline void MIi_Wait(vu32 *dmaCntp)
{
    while (*dmaCntp & MI_DMA_ENABLE) {
    }
}

void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable)
{
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }
    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, 0);

    dmaCntp = (vu32 *)(REG_DMA0SAD_ADDR + (dmaNo * 3 + 2) * 4);
    MIi_Wait(dmaCntp);

    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, 0x84000000 | (size / 4), 2);
    } else {
        MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, 0x04000000 | (size / 4), 6);
    }
    MIi_Wait(dmaCntp);
}
