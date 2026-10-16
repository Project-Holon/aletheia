/*
 * function: PMSIV_FADE_StartBrightness
 * address: 0x021BC8FC
 * packet: pkt_ov110_021BC8FC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: difference of stored fixed-point fields prevents shift factoring.
 * symbols:
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   PMSIV_FADE_BrightnessTask 0x021BC964 thumb ov110
 *   PMS_INPUT_VIEW_AddVBlankTask 0x021B9BA4 thumb ov110
 */
#include "../include/Obj03241.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void PMSIV_FADE_BrightnessTask(void *, u8 *);
extern void *PMS_INPUT_VIEW_AddVBlankTask(void (*fn)(void *, u8 *), u8 *p, int n);
void PMSIV_FADE_StartBrightness(u8 *p,int a,int start,int end,int n)
{
    G2x_SetBlendBrightness_(0x4000050,a,start);
    ((struct Obj03241 *)p)->f0=a;
    ((struct Obj03241 *)p)->f14=n;
    ((struct Obj03241 *)p)->f8=start<<12;
    ((struct Obj03241 *)p)->fC=end<<12;
    ((struct Obj03241 *)p)->f10=(((struct Obj03241 *)p)->fC-((struct Obj03241 *)p)->f8)/n;
    ((struct Obj03241 *)p)->f18=0;
    ((struct Obj03241 *)p)->f1C=PMS_INPUT_VIEW_AddVBlankTask(PMSIV_FADE_BrightnessTask,p,0);
}
