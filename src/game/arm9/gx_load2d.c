/*
 * file:     gx_load2d.c
 * unit:     yes
 * function: GX_LoadBGPltt, GXS_LoadBGPltt, GX_LoadOBJPltt, GXS_LoadOBJPltt, GX_LoadOAM, GXS_LoadOAM, GX_LoadOBJ, GXS_LoadOBJ, GX_LoadBG0Scr, GXS_LoadBG0Scr, GX_LoadBG1Scr, GXS_LoadBG1Scr, GX_LoadBG2Scr, GXS_LoadBG2Scr, GX_LoadBG3Scr, GXS_LoadBG3Scr, GX_LoadBG0Char, GXS_LoadBG0Char, GX_LoadBG1Char, GXS_LoadBG1Char, GX_LoadBG2Char, GXS_LoadBG2Char, GX_LoadBG3Char, GXS_LoadBG3Char, GX_BeginLoadBGExtPltt, GX_LoadBGExtPltt, GX_EndLoadBGExtPltt, GX_BeginLoadOBJExtPltt, GX_LoadOBJExtPltt, GX_EndLoadOBJExtPltt, GXS_BeginLoadBGExtPltt, GXS_LoadBGExtPltt, GXS_EndLoadBGExtPltt, GXS_BeginLoadOBJExtPltt, GXS_LoadOBJExtPltt, GXS_EndLoadOBJExtPltt
 * address:  0x0207E3D0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load2d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Merged by tools/restructure.py and arm9_lane05 from the src/matched files of these functions.
 *
 * symbols:
 *   GXi_DmaId          0x020A84C0  data
 *   MI_NDmaCopy        0x0272FB78  arm
 *   MIi_CpuCopy16      0x02082A60  arm
 *   MIi_DmaCopy16      0x020822E8  arm
 *   MIi_DmaCopy32      0x02082244  arm
 *   MIi_CpuCopy32      0x02082A90  arm
 *   G2_GetBG0ScrPtr    0x0207DF60  arm
 *   G2S_GetBG0ScrPtr   0x0207DF94  arm
 *   G2_GetBG1ScrPtr    0x0207DFB4  arm
 *   G2S_GetBG1ScrPtr   0x0207DFE8  arm
 *   G2_GetBG2ScrPtr    0x0207E008  arm
 *   G2S_GetBG2ScrPtr   0x0207E08C  arm
 *   G2_GetBG3ScrPtr    0x0207E100  arm
 *   G2S_GetBG3ScrPtr   0x0207E184  arm
 *   G2_GetBG0CharPtr   0x0207E1F8  arm
 *   G2S_GetBG0CharPtr  0x0207E22C  arm
 *   G2_GetBG1CharPtr   0x0207E24C  arm
 *   G2S_GetBG1CharPtr  0x0207E280  arm
 *   G2_GetBG2CharPtr   0x0207E2A0  arm
 *   G2S_GetBG2CharPtr  0x0207E2F0  arm
 *   G2_GetBG3CharPtr   0x0207E330  arm
 *   G2S_GetBG3CharPtr  0x0207E388  arm
 *   sSubBGExtPltt              0x02150E10  data
 *   GX_ResetBankForBGExtPltt   0x0208091C  arm
 *   MI_NDmaCopyAsync           0x0272FC2C  arm
 *   MIi_DmaCopy32Async         0x02082498  arm
 *   GX_SetBankForBGExtPltt     0x02080100  arm
 *   MI_WaitNDma                0x0272FCB0  arm
 *   MI_WaitDma                 0x02082594  arm
 *   GX_ResetBankForOBJExtPltt  0x02080940  arm
 *   GX_SetBankForOBJExtPltt    0x020801F8  arm
 *   GX_ResetBankForSubBGExtPltt   0x020809C8  arm
 *   GX_SetBankForSubBGExtPltt  0x020807BC  arm
 *   GX_ResetBankForSubOBJExtPltt   0x020809F0  arm
 *   GX_SetBankForSubOBJExtPltt 0x0208083C  arm
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#define GX_DMA_NOT_USE ((u32)-1)

extern u32 GXi_DmaId;

#include "../twl/mi_ndma.h"

#include "mi_dma.h"


#include "mi_memory.h"


static inline void MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo > 3) {
        if ((((uptr)src | (uptr)dest | size) & 3) == 0) {
            MI_NDmaCopy((int)(dmaNo - 4), (sptr)src, (sptr)dest, size);
        } else {
            MIi_CpuCopy16(src, dest, size);
        }
    } else {
        MIi_DmaCopy16(dmaNo, src, dest, size, 1);
    }
}

static inline void GXi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo != GX_DMA_NOT_USE && size > 0x1c) {
        MI_DmaCopy16(dmaNo, src, dest, size);
    } else {
        MIi_CpuCopy16(src, dest, size);
    }
}

void GX_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_BG_PLTT + offset), szByte);
}

void GXS_LoadBGPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_DB_BG_PLTT + offset), szByte);
}

void GX_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_OBJ_PLTT + offset), szByte);
}

void GXS_LoadOBJPltt(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)(HW_DB_OBJ_PLTT + offset), szByte);
}

static inline void MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo > 3) {
        MI_NDmaCopy((int)(dmaNo - 4), (sptr)src, (sptr)dest, size);
    } else {
        MIi_DmaCopy32(dmaNo, src, dest, size, 1);
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

void GX_LoadOAM(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(HW_OAM + offset), szByte);
}

void GXS_LoadOAM(const void *pSrc, u32 offset, u32 szByte)
{
    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(HW_DB_OAM + offset), szByte);
}

void GX_LoadOBJ(const void *pSrc, u32 offset, u32 szByte)
{
    uptr ptr = HW_OBJ_VRAM;

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(ptr + offset), szByte);
}

#include "gx_bgcnt.h"

void GXS_LoadOBJ(const void *pSrc, u32 offset, u32 szByte);

void GX_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte);

void GXS_LoadOBJ(const void *pSrc, u32 offset, u32 szByte)
{
    uptr ptr = HW_DB_OBJ_VRAM;

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(ptr + offset), szByte);
}

void GX_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG0ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG0ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GX_LoadBG1Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG1ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG1Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG1ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GX_LoadBG2Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG2ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG2Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG2ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GX_LoadBG3Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG3ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG3Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG3ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GX_LoadBG0Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG0CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG0Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG0CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GX_LoadBG1Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG1CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG1Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG1CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GX_LoadBG2Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG2CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG2Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG2CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GX_LoadBG3Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG3CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}


void GXS_LoadBG3Char(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2S_GetBG3CharPtr();

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)((uptr)ptr + offset), szByte);
}

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


extern void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);



#include "gx_vramcnt.h"


void GX_BeginLoadBGExtPltt(void);

void GX_LoadBGExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);

void GX_EndLoadBGExtPltt(void);

extern GXLoad2DState sSubBGExtPltt;

void GX_BeginLoadBGExtPltt(void)
{
    sSubBGExtPltt.bgExtPltt = GX_ResetBankForBGExtPltt();

    switch (sSubBGExtPltt.bgExtPltt) {
    case 0:
        break;
    case 0x10:
        sSubBGExtPltt.bgExtPlttLCDCBlk = 0x06880000;
        sSubBGExtPltt.bgExtPlttLCDCOffset = 0;
        break;
    case 0x40:
        sSubBGExtPltt.bgExtPlttLCDCBlk = 0x06894000;
        sSubBGExtPltt.bgExtPlttLCDCOffset = 0x4000;
        break;
    case 0x20:
    case 0x60:
        sSubBGExtPltt.bgExtPlttLCDCBlk = 0x06890000;
        sSubBGExtPltt.bgExtPlttLCDCOffset = 0;
        break;
    default:
        break;
    }
}

static inline void MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg)
{
    if (dmaNo > 3) {
        MI_NDmaCopyAsync(dmaNo - 4, (uptr)src, (uptr)dest, (unsigned int)size, callback, (uptr)arg);
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

void GX_EndLoadBGExtPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForBGExtPltt(sSubBGExtPltt.bgExtPltt);
    sSubBGExtPltt.bgExtPltt = 0;
    sSubBGExtPltt.bgExtPlttLCDCBlk = 0;
    sSubBGExtPltt.bgExtPlttLCDCOffset = 0;
}




void GX_BeginLoadOBJExtPltt(void);

void GX_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);

void GX_EndLoadOBJExtPltt(void);

void *GXS_BeginLoadBGExtPltt(void);

void GX_BeginLoadOBJExtPltt(void)
{
    sSubBGExtPltt.objExtPltt = GX_ResetBankForOBJExtPltt();

    switch (sSubBGExtPltt.objExtPltt) {
    case 0:
        break;
    case 0x40:
        sSubBGExtPltt.objExtPlttLCDCBlk = 0x06894000;
        break;
    case 0x20:
        sSubBGExtPltt.objExtPlttLCDCBlk = 0x06890000;
        break;
    default:
        break;
    }
}

void GX_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(sSubBGExtPltt.objExtPlttLCDCBlk + destSlotAddr), szByte, 0, 0);
}

void GX_EndLoadOBJExtPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForOBJExtPltt(sSubBGExtPltt.objExtPltt);
    sSubBGExtPltt.objExtPltt = 0;
    sSubBGExtPltt.objExtPlttLCDCBlk = 0;
}

void *GXS_BeginLoadBGExtPltt(void)
{
    return (void *)(uptr)(sSubBGExtPltt.subBGExtPltt = (int)GX_ResetBankForSubBGExtPltt());
}


void GXS_LoadBGExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);

void GXS_EndLoadBGExtPltt(void);

void GXS_LoadBGExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(0x06898000 + destSlotAddr), szByte, 0, 0);
}

void GXS_EndLoadBGExtPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForSubBGExtPltt(sSubBGExtPltt.subBGExtPltt);
    sSubBGExtPltt.subBGExtPltt = 0;
}



void *GXS_BeginLoadOBJExtPltt(void);

void GXS_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);

void GXS_EndLoadOBJExtPltt(void);

void *GXS_BeginLoadOBJExtPltt(void)
{
    void *p = (void *)(uptr)GX_ResetBankForSubOBJExtPltt();
    sSubBGExtPltt.subOBJExtPltt = (sptr)p;
    return p;
}

void GXS_LoadOBJExtPltt(const void *pSrc, u32 destSlotAddr, u32 szByte)
{
    GXi_DmaCopy32Async(GXi_DmaId, pSrc, (void *)(0x068A0000 + destSlotAddr), szByte, 0, 0);
}

void GXS_EndLoadOBJExtPltt(void)
{
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForSubOBJExtPltt(sSubBGExtPltt.subOBJExtPltt);
    sSubBGExtPltt.subOBJExtPltt = 0;
}
