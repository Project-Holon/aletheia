/*
 * function: NNSi_SndShutdown
 * address:  0x02073DFC
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   gNNSSndSystem     0x0214E9FC  data
 *   gNNSSndMessageQueue     0x0214E9BC  data
 *   func_020894DC  0x020894DC  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 *   func_02085E50  0x02085E50  arm
 *   SND_CHANNEL_ClearClaimedMask  0x020729A4  arm
 *   SND_CHANNEL_UnlockChannels  0x02072974  arm
 *   NNS_SndWaveOutFreeChannel  0x02072A08  arm
 *   func_0208972C  0x0208972C  arm
 *
 * Shutdown of the global sequence object gNNSSndSystem: release its channel
 * pair, and when it owns a channel save/mute/restore the driver and spin
 * until func_02085E50 reports idle; then free the +0x28 mask, the +0x20
 * channel and the +0x2c channel bit, notify when +0x04 == 1, and clear the
 * liveness word.
 *
 * THE LEVER (after four passes and 2215 permuter candidates flat on the
 * body, docs/notes/NNSi_SndShutdown.c.txt): two extern signatures.
 * SND_CHANNEL_ClearClaimedMask and SND_CHANNEL_UnlockChannels each take the field their guard just
 * tested -- SND_CHANNEL_ClearClaimedMask(s->f28), SND_CHANNEL_UnlockChannels(s->f20) -- exactly as
 * their own matched sources declare them (`u32 mask`, `u32 chan`).  The
 * image's `ldr r0,[r4,#0x28]; cmp r0,#0; beq; bl` was always passing it.
 * Declared void(void), the three callee-saved locals rotated r5/r6/r7.
 */

#include "../include/G_St.h"

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct St St;

extern struct St gNNSSndSystem;
extern u8   gNNSSndMessageQueue[];
extern void func_020894DC(u32 a, u32 b, u32 c, s32 d);
extern s32  func_02089D40(void);
extern void func_02089B38(s32 a);
extern void func_02089CD4(s32 a);
extern s32  func_02085E50(void *p, s32 b, s32 c);
extern void SND_CHANNEL_ClearClaimedMask(u32 mask);
extern void SND_CHANNEL_UnlockChannels(u32 chan);
extern void NNS_SndWaveOutFreeChannel(u32 bit);
extern void func_0208972C(s32 a, s32 b, s32 c, s32 d);

void NNSi_SndShutdown(void)
{
    St  *s;
    s32  on;
    s32  h;
    s32  z;

    s = &gNNSSndSystem;
    if (s->f00 == 0) {
        return;
    }

    on = (s->f2c >= 0);
    func_020894DC(s->f24, s->f28, on ? (u32)(1 << s->f2c) : 0, 0);

    if (on) {
        h = func_02089D40();
        func_02089B38(1);
        func_02089CD4(h);
        z = 0;
        while (func_02085E50(gNNSSndMessageQueue, z, z) != 0)
            ;
    }

    if (s->f28 != 0) {
        SND_CHANNEL_ClearClaimedMask(s->f28);
    }
    if (s->f20 != 0) {
        SND_CHANNEL_UnlockChannels(s->f20);
    }
    if (on) {
        NNS_SndWaveOutFreeChannel(s->f2c);
    }
    if (s->f04 == 1) {
        func_0208972C(0, 0, 0, 0);
    }
    s->f00 = 0;
}
