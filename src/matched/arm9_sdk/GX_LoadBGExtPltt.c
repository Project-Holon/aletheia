/*
 * function: GX_LoadBGExtPltt
 * address:  0x0207F394
 * packet:   pkt_0207F394
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load2d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Copies BG extended palette data into the LCDC-mapped extended palette
 * banks.
 *
 * symbols:
 *   GXi_DmaId                  0x020A84C0  data
 *   sSubBGExtPltt              0x02150E10  data
 *   MI_NDmaCopyAsync           0x0272FC2C  arm
 *   MIi_DmaCopy32Async         0x02082498  arm
 *   MIi_CpuCopy32              0x02082A90  arm
 */

#include "../include/G_GXLoad2DState.h"

typedef unsigned long u32;
typedef int BOOL;

#define GX_DMA_NOT_USE ((u32)-1)

extern u32 GXi_DmaId;

extern void MI_NDmaCopy(u32 ndmaNo, const void *src, void *dest, u32 size);
extern void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
extern void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);

typedef void (*MIDmaCallback)(void *);

/* the .bss statics of gx_load2d.o from sSubBGExtPltt on, in their laid-out order */
typedef struct {
    int subBGExtPltt;
    u32 objExtPlttLCDCBlk;
    int objExtPltt;
    u32 bgExtPlttLCDCOffset;
    u32 bgExtPlttLCDCBlk;
    int bgExtPltt;
    int subOBJExtPltt;
} GXLoad2DState;

extern struct GXLoad2DState sSubBGExtPltt;

extern void MI_NDmaCopyAsync(u32 ndmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
extern void MI_WaitNDma(u32 ndmaNo);
extern void MI_WaitDma(u32 dmaNo);

static inline void MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    if (dmaNo > 3) {
        MI_NDmaCopyAsync(dmaNo - 4, src, dest, size, callback, arg);
    } else {
        MIi_DmaCopy32Async(dmaNo, src, dest, size, callback, arg, 1);
    }
}

static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    if (dmaNo != GX_DMA_NOT_USE) {
        MI_DmaCopy32Async(dmaNo, src, dest, size, callback, arg);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_LoadBGExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(sSubBGExtPltt.bgExtPlttLCDCBlk + destSlotAddr - sSubBGExtPltt.bgExtPlttLCDCOffset), szByte, 0, 0);
}
