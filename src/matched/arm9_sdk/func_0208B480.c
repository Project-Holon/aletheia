/*
 * function: func_0208B480
 * address:  0x0208B480
 * packet:   pkt_0208B480
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * TwlSDK libspi mic.o, catalog MIC_StopAutoSampling.  Synchronous wrapper
 * around MIC_StopAutoSamplingAsync.
 *
 * symbols:
 *   MIC_StopAutoSamplingAsync  0x0208B424  arm
 *   MicWaitBusy                0x0208B798  arm
 *   g_02152FE0                 0x02152FE0  data
 *   MicGetResultCallback       0x0208B788  arm
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

extern s32 MIC_StopAutoSamplingAsync(void *callback, void *arg);
extern void MicWaitBusy(void);
extern void MicGetResultCallback(s32 result);

s32 func_0208B480(void)
{
    s32 result;

    result = MIC_StopAutoSamplingAsync(MicGetResultCallback, 0);
    g_02152FE0.commonResult = result;
    if (result == 0)
    {
        MicWaitBusy();
    }
    return g_02152FE0.commonResult;
}
