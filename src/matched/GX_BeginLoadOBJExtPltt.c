/*
 * function: GX_BeginLoadOBJExtPltt
 * address:  0x0207F47C
 * packet:   pkt_0207F47C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load2d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Frees the OBJ extended palette bank to LCDC and records its LCDC block.
 *
 * symbols:
 *   sSubBGExtPltt              0x02150E10  data
 *   GX_ResetBankForOBJExtPltt  0x02080940  arm
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

extern GXLoad2DState sSubBGExtPltt;

extern void MI_NDmaCopyAsync(u32 ndmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void MIi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg, BOOL dmaEnable);
extern void MI_WaitNDma(u32 ndmaNo);
extern void MI_WaitDma(u32 dmaNo);
extern int GX_ResetBankForOBJExtPltt(void);

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
