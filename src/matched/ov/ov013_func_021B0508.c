/*
 * function: VCT_MIXER_Init
 * address: 0x021B0508
 * packet: pkt_ov013_021B0508
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * Initialize TCV session state, six counters and three request slots.
 * final push 2026-10-05 G7L7: closed. Two changes from the old draft. The f1C store is written in
 * each arm of the mode if/else (the join no longer splits the 3C84 pointer, f1C goes through the
 * first load). The pair table read takes a = d[k].a first and then p = &d[k] for p->b, which
 * gives the later-born address temp the lower register (r1) and the table base r2, so the table
 * load stays below the f1C store.
 * symbols:
 *   gVctSendState     0x021B3C84  data  ov013  a4
 *   gVctSendEnabled     0x021B3C24  data  ov013  a4
 *   gVctSession     0x021B60D8  data  ov013  a4
 *   gVctFrameSpecs     0x021B3AD0  data  ov013  a1
 *   gVctSendBuffer     0x021B42C0  data  ov013  a4
 *   gVctMembers     0x021B3CB0  data  ov013  a4
 *   gVctReceiveSources     0x021B3CBC  data  ov013  a4
 *   OS_GetTickLo  0x02087170  arm
 *   VCT_DSP_InitVoiceGateDefaults  0x021B3250  arm  ov013
 *   VCT_AUDIO_ClearReadyQueue  0x021B16E4  arm  ov013
 *   VCT_AUDIO_InitReceiveSource  0x021B19BC  arm  ov013
 *   VCT_AUDIO_ResetPendingList  0x021B12FC  arm  ov013
 *   VCT_DSP_InitEchoState  0x021B3364  arm  ov013
 */

#include "../include/G_Ctx42C0.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 pad8[4];
    u32 fC;
    u8 pad10[0xC];
    u32 f1C;
    int f20;
    u32 f24;
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
    u8 pad0[0x10];
    int f10;
} Ctx60D8;

typedef struct {
    u8 raw[0x94];
} Slot;

extern Ctx3C84 gVctSendState;
extern int gVctSendEnabled;
extern Ctx60D8 gVctSession;
typedef struct {
    u8 a;
    u8 b;
} Pair;

extern const Pair gVctFrameSpecs[];
extern struct Ctx42C0 gVctSendBuffer;
extern void *gVctMembers[3];
extern Slot gVctReceiveSources[3];

extern u16 OS_GetTickLo(void);
extern void VCT_DSP_InitVoiceGateDefaults(void);
extern void VCT_AUDIO_ClearReadyQueue(u32 i);
extern void VCT_AUDIO_InitReceiveSource(char *p, int i, int a2);
extern void VCT_AUDIO_ResetPendingList(void);
extern void VCT_DSP_InitEchoState(void);

static inline u32 pairValue(u32 k)
{
    const Pair *p;
    u32 a;
    a = gVctFrameSpecs[k].a;
    p = &gVctFrameSpecs[k];
    return a * 0x44 + p->b + 0xC;
}
int VCT_MIXER_Init(void)
{
    u32 i;
    u32 k;

    gVctSendState.f0 = OS_GetTickLo();
    gVctSendEnabled = 1;
    gVctSendState.f20 = 0;
    gVctSendState.f4 = 0;
    k = 0;
    if (gVctSession.f10 != 1) {
        k = 4;
        gVctSendState.f1C = k;
    } else {
        gVctSendState.f1C = k;
    }
    gVctSendState.f24 = 0x440;
    gVctSendState.fC = pairValue(k);
    gVctSendBuffer.f8C0 = 0;
    gVctSendBuffer.f8C4 = 0;
    gVctSendBuffer.f8CC = 0;
    gVctSendBuffer.f8C8 = 0;
    gVctSendBuffer.f8D0 = 0;
    gVctSendBuffer.f8D4 = 0;
    VCT_DSP_InitVoiceGateDefaults();
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        gVctMembers[i] = 0;
        VCT_AUDIO_ClearReadyQueue(i);
        VCT_AUDIO_InitReceiveSource((char *)&gVctReceiveSources[i], i, -1);
    }
    VCT_AUDIO_ResetPendingList();
    VCT_DSP_InitEchoState();
    return 1;
}
