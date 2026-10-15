/*
 * function: NNS_SndStrmSetup
 * address:  0x020738C0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   NNSi_SndStrmStopIfSetup  0x02073AB4  arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   NNSi_SndWaveOutAllocSlot  0x020729C0  arm
 *   SND_SetupChannelPcm  0x02089660  arm
 *   SND_SetupAlarm  0x02089540  arm
 *   NNS_FndAppendListObject  0x020604AC  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   NNSi_SndStrmUpdate  0x02073BF0  arm
 *   NNSi_SndStrmTimerCallback  0x02073BE0  arm
 *   gSndStrmChannels     0x0214E934  data
 *   gSndStrmList     0x0214E8E8  data
 *
 * The sound object's start: tear down a running instance, size the per-slot
 * buffer (func_0209C2B0 is the divide), claim a hardware channel through
 * NNSi_SndWaveOutAllocSlot (negative = none, answer 0), set up one PCM channel per slot
 * byte at +0x54 with its buffer address recorded in gSndStrmChannels, arm the timer
 * SND_SetupAlarm with the callback NNSi_SndStrmTimerCallback (a 16-byte tail-call leaf,
 * filed EXACT alongside this so the pool word has a `matched` witness), link
 * the object into gSndStrmList, latch the parameters, and prime one step of
 * NNSi_SndStrmUpdate with the frame count forced to 1 inside a
 * OS_DisableInterrupts/OS_RestoreInterrupts bracket.
 *
 * One lever: the first quotient is its own statement (`size = div(...);
 * size = (size * frames) << 5;`).  Folded into one expression the multiply
 * comes out `mul r0, fp, r0` instead of the image's `mul r1, r0, fp`.
 */

#include "../include/G_SlotDesc.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed   int  s32;

struct SndObj {
    u8  pad_00[0x28];
    u32 f28;
    s32 flag0 : 1;
    u32 flag_hi : 31;
    u32 f30;
    s32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    s32 f48;
    u32 f4c;
    s32 f50;
    u8  f54[4];
};

extern struct SlotDesc gSndStrmChannels[];
extern u8 gSndStrmList[];

extern void NNSi_SndStrmStopIfSetup(struct SndObj *o);
extern u32  func_0209C2B0(u32 a, s32 b);
extern s32  NNSi_SndWaveOutAllocSlot(void);
extern void SND_SetupChannelPcm(u32 chan, int fmt, u32 data, int loopmode,
                          int a, int b, int vol, int pan, u32 period, int e);
extern void SND_SetupAlarm(s32 chan, u32 a, u32 b, void (*cb)(void *), void *arg);
extern void NNS_FndAppendListObject(void *list, void *node);
extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 tok);
extern void NNSi_SndStrmUpdate(struct SndObj *o, u32 arg);
extern void NNSi_SndStrmTimerCallback(void *o);

int NNS_SndStrmSetup(struct SndObj *o, int fmt, u32 base, u32 len,
                  u32 rate, s32 frames, u32 cb, u32 ctx)
{
    u32 size;
    u32 period;
    int i;
    u32 tok;

    if (o->flag0) NNSi_SndStrmStopIfSetup(o);
    size = func_0209C2B0(len, o->f50 * (frames << 5));
    size = (size * frames) << 5;
    o->f30 = size;
    if (fmt == 1) size >>= 1;
    period = func_0209C2B0(rate * size, frames);
    o->f48 = NNSi_SndWaveOutAllocSlot();
    if (o->f48 < 0) return 0;
    for (i = 0; i < o->f50; i++) {
        u8 slot = o->f54[i];
        gSndStrmChannels[slot].a = o->f30 * i + base;
        gSndStrmChannels[slot].b = 0;
        SND_SetupChannelPcm(slot, fmt, gSndStrmChannels[slot].a, 1, 0, o->f30 >> 2,
                      0x7f, 0, rate << 5, 0x40);
    }
    SND_SetupAlarm(o->f48, period, period, NNSi_SndStrmTimerCallback, o);
    NNS_FndAppendListObject(gSndStrmList, o);
    o->f28 = fmt;
    o->f34 = frames;
    o->f38 = cb;
    o->f3c = ctx;
    o->f40 = 0;
    o->f44 = 0;
    o->flag0 = 1;
    tok = OS_DisableInterrupts();
    o->f34 = 1;
    NNSi_SndStrmUpdate(o, 0);
    o->f34 = frames;
    OS_RestoreInterrupts(tok);
    return 1;
}
