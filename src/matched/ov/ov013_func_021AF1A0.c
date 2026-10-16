/*
 * function: VCT_MAIN_Exit
 * address:  0x021AF1A0
 * packet:   pkt_ov013_021AF1A0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gVctWork     0x021B3C80  data  ov013
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   MIC_StopAutoSampling  0x0208B480  arm
 *   MIC_StopLimitedSampling  0x0208B528  arm
 *   NNSi_SndStrmStopIfSetup  0x02073AB4  arm
 *   NNS_SndStrmFreeChannel  0x02073898  arm
 *   VCT_Exit  0x021B3844  arm  ov013
 *   PM_SetAmp  0x0208BEF0  arm
 *   DWC_RAPCOMMON_Free  0x02156FDC  thumb  ov009
 */

#include "../include/G_Work.h"

typedef unsigned char u8;

typedef struct Work Work;

extern struct Work *gVctWork;
typedef unsigned int   u32;
extern u32 APP_ENV_IsRunOnTwl(void);
extern int MIC_StopAutoSampling(void);
extern int MIC_StopLimitedSampling(void);
extern void NNSi_SndStrmStopIfSetup(void *p);
struct X;
extern void NNS_SndStrmFreeChannel(struct X *x);
extern void VCT_Exit(void);
extern unsigned int PM_SetAmp(unsigned int status);
extern void DWC_RAPCOMMON_Free(u32 a, void *p, int b);

void VCT_MAIN_Exit(void)
{
    void (*cb)(void);

    if (gVctWork == 0) {
        return;
    }
    cb = gVctWork->f1984;
    if (APP_ENV_IsRunOnTwl() == 0) {
        MIC_StopAutoSampling();
    } else {
        MIC_StopLimitedSampling();
    }
    NNSi_SndStrmStopIfSetup(gVctWork->f19B8);
    NNS_SndStrmFreeChannel((struct X *)gVctWork->f19B8);
    VCT_Exit();
    PM_SetAmp(0);
    DWC_RAPCOMMON_Free(0, gVctWork->f880, 0);
    DWC_RAPCOMMON_Free(0, gVctWork, 0);
    gVctWork = 0;
    if (cb) {
        cb();
    }
}
