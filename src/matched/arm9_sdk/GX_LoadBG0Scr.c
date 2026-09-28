/*
 * function: GX_LoadBG0Scr
 * address:  0x0207E888
 * packet:   pkt_0207E888
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load2d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Copies screen data to BG0's screen base on the main engine (16-bit DMA
 * when one is assigned and the copy is long enough, else CPU).
 *
 * symbols:
 *   GXi_DmaId          0x020A84C0  data
 *   G2_GetBG0ScrPtr    0x0207DF60  arm
 *   MI_NDmaCopy        0x0272FB78  arm
 *   MIi_CpuCopy16      0x02082A60  arm
 *   MIi_DmaCopy16      0x020822E8  arm
 */

typedef unsigned long u32;
typedef int BOOL;

#define GX_DMA_NOT_USE ((u32)-1)

extern u32 GXi_DmaId;

extern void MI_NDmaCopy(u32 ndmaNo, const void *src, void *dest, u32 size);
extern void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
extern void MIi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);

extern void *G2_GetBG0ScrPtr(void);

static inline void MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo > 3) {
        if ((((u32)src | (u32)dest | size) & 3) == 0) {
            MI_NDmaCopy(dmaNo - 4, src, dest, size);
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

void GX_LoadBG0Scr(const void *pSrc, u32 offset, u32 szByte)
{
    void *ptr = G2_GetBG0ScrPtr();

    GXi_DmaCopy16(GXi_DmaId, pSrc, (void *)((u32)ptr + offset), szByte);
}
