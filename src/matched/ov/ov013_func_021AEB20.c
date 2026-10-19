/*
 * function: VCT_MAIN_InitAudio
 * address:  0x021AEB20
 * packet:   pkt_ov013_021AEB20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MIC_Init  0x0208B24C  arm
 *   PM_Init  0x0208B8B0  arm
 *   PM_SetAmp  0x0208BEF0  arm
 *   PM_SetAmpGain  0x0208BF38  arm
 *   VCT_MIXER_SetSendEnabled  0x021B0CD8  arm  ov013
 *   NNS_SndInit  0x020726D0  arm
 *   NNS_SndStrmInit  0x020737C0  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   VCT_MIXER_SetFilterEnabled  0x021B0D08  arm  ov013
 *   gVctWork     0x021B3C80  data  ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct Work *gVctWork;

extern void MIC_Init(void);
extern void PM_Init(void);
extern unsigned int PM_SetAmp(unsigned int status);
extern unsigned int PM_SetAmpGain(unsigned int gain);
extern void VCT_MIXER_SetSendEnabled(int x);
extern void NNS_SndInit(void);
struct S;
extern void NNS_SndStrmInit(struct S *p);
extern void MIi_CpuClearFast(int v, void *p, u32 n);
extern void VCT_MIXER_SetFilterEnabled(int x);

void VCT_MAIN_InitAudio(void)
{
    MIC_Init();
    PM_Init();
    PM_SetAmp(1);
    PM_SetAmpGain(3);
    VCT_MIXER_SetSendEnabled(1);
    NNS_SndInit();
    NNS_SndStrmInit((struct S *)(((u8 *)gVctWork) + 0x19B8));
    MIi_CpuClearFast(0, ((u8 *)gVctWork) + 0x1104, 0x880);
    *(u32 *)(((u8 *)gVctWork) + 0x1A44) = 0;
    VCT_MIXER_SetFilterEnabled(1);
}
