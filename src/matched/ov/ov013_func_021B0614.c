/*
 * function: VCT_MIXER_AddMember
 * address: 0x021B0614
 * packet: pkt_ov013_021B0614
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * Register request in a free slot, restarting clock/counters for the first type-2 request.
 * 2026-10-05: EXACT with opt_lifetimes off (the first loop counter otherwise gets r2 instead of sharing r5 with the second loop). Plain i = 0 in the second loop.
 * symbols:
 *   gVctSendState     0x021B3C84  data  ov013  a4
 *   gVctMembers     0x021B3CB0  data  ov013  a4
 *   gVctReceiveSources     0x021B3CBC  data  ov013  a4
 *   gVctSendBuffer     0x021B42C0  data  ov013  a4
 *   OS_GetTickLo  0x02087170  arm
 *   VCT_AUDIO_ClearReadyQueue  0x021B16E4  arm  ov013
 *   VCT_AUDIO_InitReceiveSource  0x021B19BC  arm  ov013
 *   VCT_DSP_ResetVoiceGate  0x021B3018  arm  ov013
 */

#include "../include/G_Ctx42C0.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 pad8[8];
    u16 f10;
    u8 f12;
    u8 pad13;
    int f14;
    u8 pad18[8];
    int f20;
} Ctx3C84;

typedef struct {
    u8 pad0[0x8c0];
    int f8C0;
    u32 f8C4;
    u32 f8C8;
    u32 f8CC;
    int f8D0;
    int f8D4;
} Ctx42C0;

typedef struct {
    u8 raw[0x94];
} Slot;

typedef struct {
    u8 pad0[5];
    u8 f5;
    u8 pad6[2];
    u32 f8;
    int fC;
} Req;

extern Ctx3C84 gVctSendState;
extern Req *gVctMembers[3];
extern Slot gVctReceiveSources[3];
extern struct Ctx42C0 gVctSendBuffer;

extern u16 OS_GetTickLo(void);
extern void VCT_AUDIO_ClearReadyQueue(u32 i);
extern void VCT_AUDIO_InitReceiveSource(char *p, int i, int a2);
extern void VCT_DSP_ResetVoiceGate(void);

#pragma opt_lifetimes off
int VCT_MIXER_AddMember(Req *p)
{
    u32 i;

    if (p == 0) {
        return 0;
    }
    if (gVctSendState.f20 == 3) {
        return 0;
    }
    if (p->fC != 2 && p->fC != 3) {
        return 0;
    }
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        if (gVctMembers[i] == p) {
            return 1;
        }
    }
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        if (gVctMembers[i] == 0) {
            gVctMembers[i] = p;
            break;
        }
    }
    gVctSendState.f20++;
    gVctSendState.f4 |= p->f8;
    VCT_AUDIO_InitReceiveSource((char *)&gVctReceiveSources[i], i, p->f5);
    VCT_AUDIO_ClearReadyQueue(i);
    if (p->fC != 2) {
        return 1;
    }
    if (gVctSendState.f20 == 1) {
        VCT_DSP_ResetVoiceGate();
        gVctSendState.f0 = OS_GetTickLo();
        gVctSendState.f10 = 0;
        gVctSendState.f12 = 0;
        gVctSendState.f14 = 1;
        gVctSendBuffer.f8C0 = 0;
        gVctSendBuffer.f8C4 = 0;
        gVctSendBuffer.f8CC = 0;
        gVctSendBuffer.f8C8 = 0;
        gVctSendBuffer.f8D0 = 0;
        gVctSendBuffer.f8D4 = 0;
    }
    return 1;
}
#pragma opt_lifetimes reset
