/*
 * function: GX_EndLoadTex
 * address:  0x0207F9B4
 * packet:   pkt_0207F9B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load3d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Waits for the DMA, maps the texture banks back and clears the state.
 *
 * symbols:
 *   GX_SetBankForTex       0x02080294  arm
 *   sClrImg                0x02150E2C  data
 *   GXi_DmaId              0x020A84C0  data
 *   MI_WaitNDma            0x0272FCB0  arm
 *   MI_WaitDma             0x02082594  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef void (*MIDmaCallback)(void *);

#define GX_DMA_NOT_USE ((u32)-1)

/* gx_load3d.o's .bss statics, in their laid-out order */
typedef struct {
    int clrImg;
    u32 texLCDCBlk1;
    u32 texPlttLCDCBlk;
    int texPltt;
    u32 clrImgLCDCBlk;
    int tex;
    u32 texLCDCBlk2;
    u32 szTexBlk1;
} GXLoad3DState;

typedef struct {
    u16 blk1;
    u16 blk2;
    u16 szBlk1;
} GXTexStartAddr;

extern GXLoad3DState sClrImg;
extern u32 GXi_DmaId;
extern const GXTexStartAddr sTexStartAddrTable[16];
extern const u16 sTexPlttStartAddrTable[8];

extern int GX_ResetBankForTex(void);
extern int GX_ResetBankForTexPltt(void);
extern void GX_SetBankForTex(int tex);
extern void GX_SetBankForTexPltt(int texPltt);
extern void GX_SetBankForClearImage(int clrImg);
extern void MI_NDmaCopy(u32 ndmaNo, const void *src, void *dest, u32 size);
extern void MI_NDmaCopyAsync(u32 ndmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
extern void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
extern void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
extern void MI_WaitNDma(u32 ndmaNo);
extern void MI_WaitDma(u32 dmaNo);

static inline void MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo > 3) {
        MI_NDmaCopy(dmaNo - 4, src, dest, size);
    } else {
        MIi_DmaCopy32(dmaNo, src, dest, size, 1);
    }
}

static inline void MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    if (dmaNo > 3) {
        MI_NDmaCopyAsync(dmaNo - 4, src, dest, size, callback, arg);
    } else {
        MIi_DmaCopy32Async(dmaNo, src, dest, size, callback, arg, 1);
    }
}

static inline void MI_WaitDmaAny(u32 dmaNo)
{
    if (dmaNo > 3) {
        MI_WaitNDma(dmaNo - 4);
    } else {
        MI_WaitDma(dmaNo);
    }
}

static inline void GXi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo != GX_DMA_NOT_USE && size > 0x30) {
        MI_DmaCopy32(dmaNo, src, dest, size);
    } else {
        MIi_CpuCopy32(src, dest, size);
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

static inline void GXi_WaitDma(u32 dmaNo)
{
    if (dmaNo != GX_DMA_NOT_USE) {
        MI_WaitDmaAny(dmaNo);
    }
}

void GX_EndLoadTex(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForTex(sClrImg.tex);
    sClrImg.szTexBlk1 = 0;
    sClrImg.texLCDCBlk2 = 0;
    sClrImg.texLCDCBlk1 = 0;
    sClrImg.tex = 0;
}
