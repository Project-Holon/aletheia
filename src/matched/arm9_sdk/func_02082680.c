/*
 * function: func_02082680
 * address:  0x02082680
 * packet:   pkt_02082680
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_CheckAnotherAutoDMA (libmi.TWL.HYB.a mi_dma.o)
 *
 * symbols:
 *   OS_Terminate                   0x02088234  arm
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

void OS_Terminate(void);

void func_02082680(u32 dmaNo, u32 dmaType)
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
