/*
 * function: AESi_VerifySignForJpeg
 * address:  0x0270788C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02735AE0  0x02735AE0  data
 *   AESi_CalcMac  0x027074B0  arm
 *   AESi_InitRand  0x02707570  arm
 *   AESi_Rand  0x0270768C  arm
 *   AESi_PxiSendFirst  0x02707994  arm
 *   AESi_Lock  0x02707B68  arm
 *   AESi_Unlock  0x02707BDC  arm
 *   CallbackForJpeg  0x02707558  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef struct OSThread OSThread;
typedef struct {
    OSThread *head;
    OSThread *tail;
} OSThreadQueueLike;
typedef struct {
    OSThreadQueueLike queue;
    u32 flags;
} OSEventLike;
typedef struct {
    u32 initialized;
    u32 f4;
    u32 f8;
    u8 buf[0x10];
} SysBufLike;
extern SysBufLike g_02735AE0;
extern void AESi_InitRand(void);
extern int AESi_Rand(void *p, u32 n);
extern int AESi_CalcMac(void *p, u32 a, u32 b, void *buf, void (*cb)(u32, OSEventLike *), OSEventLike *ev);
extern void CallbackForJpeg(u32 mask, OSEventLike *ev);
extern void AESi_PxiSendFirst(int tag, u32 a, u32 b);
extern void AESi_Lock(void);
extern void AESi_Unlock(void);
extern void OS_InitEvent(OSEventLike *ev);
extern u32 OS_WaitEventEx(OSEventLike *ev, u32 pattern, u32 mode, u32 clear);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern int MI_CpuComp8(const void *a, const void *b, u32 size);

int AESi_VerifySignForJpeg(u8 *p, u32 a, u32 b)
{
    OSEventLike ev;
    int r;

    AESi_Lock();
    if (g_02735AE0.initialized == 0) {
        AESi_InitRand();
    }
    OS_InitEvent(&ev);
    do {
        if (g_02735AE0.f4 == 0) {
            AESi_PxiSendFirst(0x13, 8, 1);
        }
        r = AESi_CalcMac(p, a, b, g_02735AE0.buf, CallbackForJpeg, &ev);
        if (r == 1) {
            r = OS_WaitEventEx(&ev, -1, 1, -1);
            if (r == 1) {
                if (MI_CpuComp8(g_02735AE0.buf, p + 0xC, 0x10) != 0) {
                    r = 2;
                }
            }
        }
    } while (r == 4);
    if (g_02735AE0.f4 == 0) {
        AESi_PxiSendFirst(0x13, 8, 0);
    }
    AESi_Unlock();
    return r;
}
