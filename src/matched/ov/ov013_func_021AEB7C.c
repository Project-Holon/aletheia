/*
 * function: VCT_MAIN_StreamCallback
 * address:  0x021AEB7C
 * packet:   pkt_ov013_021AEB7C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Microphone sampling step: with mode 0 clears the n buffers; otherwise
 * stops the pending auto-sampling (param block at G+0x1A20, busy flag
 * G+0x1A4B), picks the sample window, processes each buffer and, unless
 * G+0x19B0 is set, analyses the window. Callback is the empty leaf
 * VCT_MAIN_MicRestartDone.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   MIC_StartAutoSamplingAsync  0x0208B2BC  arm
 *   MIC_StartLimitedSamplingAsync  0x0208B4C8  arm
 *   MIC_GetLastSamplingAddress  0x0208B4B8  arm
 *   VCT_SESSION_MixVoices  0x021B0B48  arm  ov013
 *   VCT_SESSION_QueueFrame  0x021B07F8  arm  ov013
 *   VCT_MAIN_MicRestartDone  0x021AEB78  thumb  ov013
 *   gVctWork     0x021B3C80  data  ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern struct Work *gVctWork;

extern void MI_CpuFill8(void *p, int v, u32 n);
extern u32 APP_ENV_IsRunOnTwl(void);
extern int MIC_StartAutoSamplingAsync(void *param, void (*cb)(void), void *arg);
extern int MIC_StartLimitedSamplingAsync(void *param, void (*cb)(void), void *arg);
extern u32 MIC_GetLastSamplingAddress(void);
extern int VCT_SESSION_MixVoices(void *a, u32 b, int *out);
extern int VCT_SESSION_QueueFrame(const u8 *src, u32 n);
extern void VCT_MAIN_MicRestartDone(void);

void VCT_MAIN_StreamCallback(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6)
{
    u8 *addr;
    u32 i;

    addr = (u8 *)arg6;

    if (mode == 0) {
        for (i = 0; i < n; i++) {
            MI_CpuFill8(bufs[i], 0, size);
        }
        return;
    }
    if (APP_ENV_IsRunOnTwl() == 0) {
        if (((u8 *)gVctWork)[0x1A4B] != 0) {
            MIC_StartAutoSamplingAsync(((u8 *)gVctWork) + 0x1A20, VCT_MAIN_MicRestartDone, 0);
            ((u8 *)gVctWork)[0x1A4B] = 0;
        }
    } else {
        if (((u8 *)gVctWork)[0x1A4B] != 0) {
            MIC_StartLimitedSamplingAsync(((u8 *)gVctWork) + 0x1A20, VCT_MAIN_MicRestartDone, 0);
            ((u8 *)gVctWork)[0x1A4B] = 0;
        }
    }
    if ((u32)(MIC_GetLastSamplingAddress() - (u32)addr) < size) {
        addr = addr + size;
    }
    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0
        || *(u16 *)(((u8 *)gVctWork) + 0x19B2) != 0) {
        addr = ((u8 *)gVctWork) + 0x1104;
    }
    for (i = 0; i < n; i++) {
        VCT_SESSION_MixVoices(bufs[i], size, 0);
    }
    if (*(u16 *)(((u8 *)gVctWork) + 0x19B0) == 0) {
        VCT_SESSION_QueueFrame(addr, size);
    }
    ((u8 *)gVctWork)[0x1A4A] = 2;
}
