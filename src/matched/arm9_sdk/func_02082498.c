/*
 * function: func_02082498
 * address:  0x02082498
 * packet:   pkt_02082498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_DmaCopy32Async (libmi.TWL.HYB.a mi_dma.o)
 *
 * symbols:
 *   MIi_CheckDma0SourceAddress     0x0208270C  arm
 *   MI_WaitDma                     0x02082594  arm
 *   OSi_EnterDmaCallback           0x020848A4  arm
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

typedef void (*MIDmaCallback)(void *arg);

void MIi_DmaSetParameters(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode);
void MIi_CheckDma0SourceAddress(u32 dmaNo, u32 src, u32 size, u32 dir);
void MI_WaitDma(u32 dmaNo);
void OSi_EnterDmaCallback(u32 dmaNo, MIDmaCallback callback, void *arg);

static inline void MIi_Wait(vu32 *dmaCntp)
{
    while (*dmaCntp & MI_DMA_ENABLE) {
    }
}

static inline void MIi_CallCallback(MIDmaCallback callback, void *arg)
{
    if (callback) {
        (callback)(arg);
    }
}

void func_02082498(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable)
{
    MIi_CheckDma0SourceAddress(dmaNo, (u32)src, size, 0);

    if (size == 0) {
        MIi_CallCallback(callback, arg);
    } else {
        MI_WaitDma(dmaNo);

        if (callback) {
            OSi_EnterDmaCallback(dmaNo, callback, arg);
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, 0xC4000000 | (size / 4), 0);
            } else {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, 0x44000000 | (size / 4), 4);
            }
        } else {
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, 0x84000000 | (size / 4), 0);
            } else {
                MIi_DmaSetParameters(dmaNo, (u32)src, (u32)dest, 0x04000000 | (size / 4), 4);
            }
        }
    }
}
