/*
 * function: VCT_AUDIO_SendFrameStep
 * address:  0x021B11E8
 * packet:   pkt_ov013_021B11E8
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSendState  0x021B3C84  data  ov013  a4
 *   gVctSendBuffer  0x021B42C0  data  ov013  a4
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   gVctSendSchedule  0x021B3ADA  data  ov013  a1
 *   VCT_AUDIO_EncodeSendFrame  0x021B0D18  arm  ov013
 *   func_02177044  0x02177044  arm  ov009
 */

#include "../include/G_Ctx42C0.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0xc];
    u32 fC;
    u8 pad10[0x8];
    u32 f18;
    u32 f1C;
    u32 f20;
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

extern Ctx3C84 gVctSendState;
extern struct Ctx42C0 gVctSendBuffer;
extern Ctx60D8 gVctSession;
extern u8 gVctSendSchedule[][3];

extern u32 VCT_AUDIO_EncodeSendFrame(void);
extern void func_02177044(u8 bit, u32 a, u32 b);

static inline u32 clz32(u32 x)
{
    asm { clz x, x }
    return x;
}

int VCT_AUDIO_SendFrameStep(void)
{
    int i;
    int count;
    u32 mask;
    u32 z;

    if (gVctSendState.f20 == 0)
        return 1;

    if (gVctSendBuffer.f8C8 == 0) {
        gVctSendBuffer.f8C8 = VCT_AUDIO_EncodeSendFrame();
        if (gVctSendBuffer.f8C8 != 0 && gVctSendState.f18 != 0)
            return 0;
        return 1;
    }

    count = 1;
    if (gVctSession.f10 == 2)
        count = gVctSendSchedule[gVctSendBuffer.f8D4][gVctSendBuffer.f8D0++];

    for (i = 0; i < count; i++) {
        mask = gVctSendBuffer.f8CC;
        z = clz32(mask);
        if (z == 32)
            break;
        gVctSendBuffer.f8CC = mask & ~(0x80000000 >> z);
        func_02177044((u8)(31 - z), gVctSendBuffer.f8C8, gVctSendState.fC);
        if (gVctSendBuffer.f8CC == 0) {
            gVctSendBuffer.f8C0++;
            gVctSendBuffer.f8C8 = 0;
            gVctSendBuffer.f8CC = 0;
            break;
        }
    }
    return 1;
}
