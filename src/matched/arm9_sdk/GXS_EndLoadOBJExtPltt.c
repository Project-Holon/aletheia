/*
 * function: GXS_EndLoadOBJExtPltt
 * address:  0x0207F754
 * packet:   pkt_0207F754
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load2d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Waits for the DMA, maps the sub OBJ extended palette bank back and clears
 * the state.
 *
 * symbols:
 *   GXi_DmaId                  0x020A84C0  data
 *   sSubBGExtPltt              0x02150E10  data
 *   GX_SetBankForSubOBJExtPltt 0x0208083C  arm
 *   MI_WaitNDma                0x0272FCB0  arm
 *   MI_WaitDma                 0x02082594  arm
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

static inline void GXi_WaitDma(u32 dmaNo)
{
    if (dmaNo != GX_DMA_NOT_USE) {
        if (dmaNo > 3) {
            MI_WaitNDma(dmaNo - 4);
        } else {
            MI_WaitDma(dmaNo);
        }
    }
}
extern void GX_SetBankForSubOBJExtPltt(int bank);

void GXS_EndLoadOBJExtPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForSubOBJExtPltt(sSubBGExtPltt.subOBJExtPltt);
    sSubBGExtPltt.subOBJExtPltt = 0;
}
