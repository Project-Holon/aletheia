/*
 * function: func_0208B24C
 * address:  0x0208B24C
 * packet:   pkt_0208B24C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libspi mic.o, catalog MIC_Init.  One-time init: raise the
 * micInitialized flag, clear the work lock/callback, bring up the PXI FIFO,
 * wait for channel 9 callback readiness, clear the codec lock word and
 * install MicCommonCallback on FIFO 9.
 *
 * symbols:
 *   g_02152FE0             0x02152FE0  data
 *   PXI_Init               0x02088498  arm
 *   PXI_IsCallbackReady    0x020885EC  arm
 *   PXI_SetFifoRecvCallback 0x020885A0  arm
 *   MicCommonCallback      0x0208B548  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long s32;

typedef struct MicBss {
    u16 micInitialized;
    u8  pad02[2];
    u32 lock;
    u32 callback;
} MicBss;

extern MicBss g_02152FE0;

extern void PXI_Init(void);
extern int PXI_IsCallbackReady(int fifotag, int procNo);
extern void PXI_SetFifoRecvCallback(int fifotag, void *callback);
extern void MicCommonCallback(int tag, u32 data, int err);

void func_0208B24C(void)
{
    if (g_02152FE0.micInitialized == 0)
    {
        g_02152FE0.micInitialized = 1;
        g_02152FE0.lock = 0;
        g_02152FE0.callback = 0;
        PXI_Init();
        while (PXI_IsCallbackReady(9, 1) == 0)
        {
        }
        *(volatile u32 *)0x02FFFF90 = 0;
        PXI_SetFifoRecvCallback(9, MicCommonCallback);
    }
}
