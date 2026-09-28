/*
 * function: func_0208270C
 * address:  0x0208270C
 * packet:   pkt_0208270C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MIi_CheckDma0SourceAddress (libmi.TWL.HYB.a mi_dma.o)
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

void func_0208270C(u32 dmaNo, u32 src, u32 size, u32 dir)
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
