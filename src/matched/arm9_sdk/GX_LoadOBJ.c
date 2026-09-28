/*
 * function: GX_LoadOBJ
 * address:  0x0207E780
 * packet:   pkt_0207E780
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load2d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Copies OBJ character data into the main engine OBJ VRAM.
 *
 * symbols:
 *   GXi_DmaId          0x020A84C0  data
 *   MI_NDmaCopy        0x0272FB78  arm
 *   MIi_DmaCopy32      0x02082244  arm
 *   MIi_CpuCopy32      0x02082A90  arm
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

static inline void MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size)
{
    if (dmaNo > 3) {
        MI_NDmaCopy(dmaNo - 4, src, dest, size);
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

void GX_LoadOBJ(const void *pSrc, u32 offset, u32 szByte)
{
    u32 ptr = 0x06400000;

    GXi_DmaCopy32(GXi_DmaId, pSrc, (void *)(ptr + offset), szByte);
}
