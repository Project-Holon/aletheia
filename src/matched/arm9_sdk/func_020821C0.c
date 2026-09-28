/*
 * function: func_020821C0
 * address:  0x020821C0
 * packet:   pkt_020821C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_DmaFill32 (libmi.TWL.HYB.a mi_dma.o)
 *
 * symbols:
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

void func_020821C0(u32 dmaNo, void *dest, u32 data, u32 size, BOOL dmaEnable)
{
    vu32 *dmaCntp;

    if (size == 0) {
        return;
    }
    dmaCntp = (vu32 *)(REG_DMA0SAD_ADDR + (dmaNo * 3 + 2) * 4);
    MIi_Wait(dmaCntp);

    if (dmaEnable) {
        MIi_DmaSetParameters(dmaNo, data, (u32)dest, 0x85000000 | (size / 4), 0x12);
    } else {
        MIi_DmaSetParameters(dmaNo, data, (u32)dest, 0x05000000 | (size / 4), 0x16);
    }
    MIi_Wait(dmaCntp);
}
