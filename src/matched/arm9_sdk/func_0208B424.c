/*
 * function: func_0208B424
 * address:  0x0208B424
 * packet:   pkt_0208B424
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi mic.o, catalog MIC_StopAutoSamplingAsync.  Takes the work
 * lock, records the completion callback, kicks the ARM7 command and releases
 * the lock when the command failed to be queued (return 3).
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_02152FE0            0x02152FE0  data
 *   MicStopAutoSampling   0x0208B75C  arm
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

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern s32 MicStopAutoSampling(void);

s32 func_0208B424(void *callback, void *arg)
{
    OSIntrMode e;

    e = OS_DisableInterrupts();
    if (g_02152FE0.lock != 0)
    {
        (void)OS_RestoreInterrupts(e);
        return 1;
    }
    g_02152FE0.lock = 1;
    (void)OS_RestoreInterrupts(e);
    g_02152FE0.callback = (u32)callback;
    g_02152FE0.callbackArg = (u32)arg;
    if (MicStopAutoSampling() == 0)
    {
        g_02152FE0.lock = 0;
        return 3;
    }
    return 0;
}
