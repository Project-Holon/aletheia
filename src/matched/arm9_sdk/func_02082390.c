/*
 * function: MIi_DmaFill32Async
 * address:  0x02082390
 * packet:   pkt_02082390
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_DmaFill32Async (libmi.TWL.HYB.a mi_dma.o)
 *
 * symbols:
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

void MIi_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable)
{
    if (size == 0) {
        MIi_CallCallback(callback, arg);
    } else {
        MI_WaitDma(dmaNo);

        if (callback) {
            OSi_EnterDmaCallback(dmaNo, callback, arg);
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, 0xC5000000 | (size / 4), 0x10);
            } else {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, 0x45000000 | (size / 4), 0x14);
            }
        } else {
            if (dmaEnable) {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, 0x85000000 | (size / 4), 0x10);
            } else {
                MIi_DmaSetParameters(dmaNo, data, (u32)dest, 0x05000000 | (size / 4), 0x14);
            }
        }
    }
}
