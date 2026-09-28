/*
 * function: GX_BeginLoadBGExtPltt
 * address:  0x0207F308
 * packet:   pkt_0207F308
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_load2d.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Frees the BG extended palette banks to LCDC and records where each slot
 * range starts in LCDC space.
 *
 * symbols:
 *   sSubBGExtPltt              0x02150E10  data
 *   GX_ResetBankForBGExtPltt   0x0208091C  arm
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
extern int GX_ResetBankForBGExtPltt(void);

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
