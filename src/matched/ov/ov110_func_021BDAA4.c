/*
 * function: PMS_INPUT_HitSentenceButtons
 * address: 0x021BDAA4
 * packet: pkt_ov110_021BDAA4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPmsInputSlotRectTemplate 0x021C38F0 data a1
 *   gPmsInputSentenceButtonHits 0x021C395C data a1
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_HitPoint 0x02035D40 arm
 *   PMSI_PARAM_HasInitialSentence 0x02024158 thumb
 *   PMS_INPUT_VIEW_GetEditValue 0x021BABE8 thumb ov110
 *   PMS_INPUT_VIEW_SetEditText 0x021BAC00 thumb ov110
 */
#include "../include/Obj10282.h"
typedef unsigned char u8;
typedef struct { u8 b[8]; } Box;
extern const Box gPmsInputSlotRectTemplate;
extern const Box gPmsInputSentenceButtonHits;
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
struct Ctx;
extern unsigned int TOUCHPANEL_GetPointTrg(unsigned int *outA, unsigned int *outB);
extern unsigned int TOUCHPANEL_HitPoint(struct Ctx *ctx, unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern u32 PMSI_PARAM_HasInitialSentence(const u8 *p);
extern int PMS_INPUT_VIEW_GetEditValue(u8 *p);
extern void PMS_INPUT_VIEW_SetEditText(u8 *p, u8 *b, u8 n);
int PMS_INPUT_HitSentenceButtons(u8 *p) {
 int x,y;
 Box box=gPmsInputSlotRectTemplate;
 int i,count,result;
 if(!TOUCHPANEL_GetTrg()) return -1;
 result=TOUCHPANEL_HitTrg(&gPmsInputSentenceButtonHits);
 if(result!=-1) {
  if(PMSI_PARAM_HasInitialSentence((const u8 *)(((struct Obj10282 *)p)->f0))) { if((unsigned)(result-2)<=3) result=-1; return result; }
  return result;
 }
 count=PMS_INPUT_VIEW_GetEditValue(((struct Obj10282 *)p)->f14);
 TOUCHPANEL_GetPointTrg((unsigned int *)(&x),(unsigned int *)(&y));
 for(i=0;i<count;i++) { PMS_INPUT_VIEW_SetEditText(((struct Obj10282 *)p)->f14,(u8 *)(&box),i); if(TOUCHPANEL_HitPoint((struct Ctx *)(&box),x,y)!=-1) return i+6; }
 return -1;
}
