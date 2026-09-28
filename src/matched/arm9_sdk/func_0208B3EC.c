/*
 * function: func_0208B3EC
 * address:  0x0208B3EC
 * packet:   pkt_0208B3EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi mic.o.  Catalog calls this MIC_AdjustAutoSampling, but the
 * member section that reproduces these bytes is MIC_StartAutoSampling (it
 * calls MIC_StartAutoSamplingAsync); the catalog/DWARF disagree here.
 * Synchronous wrapper: install MicGetResultCallback, run the async start, and
 * when it did not fail immediately, wait for the busy flag.
 *
 * symbols:
 *   MIC_StartAutoSamplingAsync  0x0208B2BC  arm
 *   MicWaitBusy                 0x0208B798  arm
 *   g_02152FE0                  0x02152FE0  data
 *   MicGetResultCallback        0x0208B788  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;
typedef u32 OSIntrMode;

typedef struct MicBss {
    u16 micInitialized;
    u8  pad02[2];
    u32 lock;
    u32 callback;
    u32 callbackArg;
    s32 commonResult;
} MicBss;

extern MicBss g_02152FE0;

extern s32 MIC_StartAutoSamplingAsync(void *buf, void *callback, void *arg);
extern void MicWaitBusy(void);
extern void MicGetResultCallback(s32 result);

s32 func_0208B3EC(void *buf)
{
    s32 result;

    result = MIC_StartAutoSamplingAsync(buf, MicGetResultCallback, 0);
    g_02152FE0.commonResult = result;
    if (result == 0)
    {
        MicWaitBusy();
    }
    return g_02152FE0.commonResult;
}
