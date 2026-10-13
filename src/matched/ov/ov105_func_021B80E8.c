/*
 * function: IRC_RESULT_StateShowScore,IRC_RESULT_StateEnd
 * unit: yes
 * address: 0x021B80E8
 * packet: pkt_ov105_021B80E8
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned word ratio retains repeated u8 narrowing; duplicate 0 and 1/2/3 sound calls retain the branch-to-branch switch arm.
 * function_starts: 0x021B8340 callback stub included in this unit.
 * symbols:
 *   IRC_RESULT_StartRankFade 0x021B871C thumb ov105
 *   IRC_RESULT_IsRankFadeFinished 0x021B8730 thumb ov105
 *   IRC_RESULT_ShowDigit 0x021B83E0 thumb ov105
 *   IRC_RESULT_IsDigitShown 0x021B8438 thumb ov105
 *   IRC_RESULT_PrintMessageWithNumber 0x021B7EEC thumb ov105
 *   IRC_RESULT_GetScoreRank 0x021B87E8 thumb ov105
 *   COMPATIBLE_IRC_SYS_BuildProfile 0x021B658C thumb ov101
 *   IRC_RESULT_GiveReward 0x021B8860 thumb ov105
 *   IRC_RESULT_PrintRewardMessage 0x021B8008 thumb ov105
 *   IRC_RESULT_PrintMessage 0x021B7DE4 thumb ov105
 *   IRC_APPBAR_SetEnabled 0x021B728C thumb ov101
 *   IRC_RESULT_SetState 0x021B80BC thumb ov105
 *   IRC_RESULT_Finish 0x021B80CC thumb ov105
 *   IRC_RESULT_UpdateScoreDisplay 0x021B8434 thumb ov105
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   IRC_RESULT_StateEnd 0x021B8340 thumb ov105
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01709.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; u8 low:4,high:4; u8 tail[32]; } Data;
typedef struct {u32 objects[3]; u8 pad[0x24];u8 digits[3];u8 pad1;int state[3];} Display;
extern void IRC_RESULT_StartRankFade(u8 *);
extern unsigned IRC_RESULT_IsRankFadeFinished(u8 *p);
extern void IRC_RESULT_ShowDigit(Display *,int);
extern int IRC_RESULT_IsDigitShown(u8 *p, int i);
extern void IRC_RESULT_PrintMessageWithNumber(u8 *,void *,u8,u16,u16);
extern int IRC_RESULT_GetScoreRank(unsigned,int *);
extern void COMPATIBLE_IRC_SYS_BuildProfile(void *,Data *);
extern int IRC_RESULT_GiveReward(u8 *);
extern void IRC_RESULT_PrintRewardMessage(u8 *,void *,u8 *,u8,int);
extern void IRC_RESULT_PrintMessage(u8 *,void *,int,int,s16);
extern void IRC_APPBAR_SetEnabled(int,int);
extern void IRC_RESULT_SetState(unsigned char *p, unsigned int v);
extern void IRC_RESULT_Finish(u8 *);
extern int IRC_RESULT_UpdateScoreDisplay(void *);
extern int IRC_APPBAR_GetResult(int *);
extern void IRC_RESULT_StateEnd(u8 *,u16 *);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern int GFL_USE_IsBgmPlaying(void);
#define CTX (*(u8 **)(p+0x1a4))
void IRC_RESULT_StateShowScore(u8 *p,u16 *state) {
 Data data; int value; u32 ratio; u8 score;
 switch(*state) {
 case 0:
  if((((struct Obj01709 *)p)->f198)++>30) {((struct Obj01709 *)p)->f198=0;*state=1;} break;
 case 1:IRC_RESULT_StartRankFade(p+0x128);*state=2;break;
 case 2:
  if(IRC_RESULT_IsRankFadeFinished(p+0x128)) {
   GFL_USE_PlaySeDefaultVolume(0x653);
   IRC_RESULT_ShowDigit((Display *)(p+0xe8),0);IRC_RESULT_ShowDigit((Display *)(p+0xe8),1);IRC_RESULT_ShowDigit((Display *)(p+0xe8),2);*state=3;
  } break;
 case 3:
  if(IRC_RESULT_IsDigitShown((u8 *)(p+0xe8),0) && IRC_RESULT_IsDigitShown((u8 *)(p+0xe8),1) && IRC_RESULT_IsDigitShown((u8 *)(p+0xe8),2)) *state=4;
  break;
 case 4:
  score=CTX[12];ratio=(u8)(score/10+2);
  if(ratio>12)ratio=12;else if(ratio<2)ratio=2;
  IRC_RESULT_PrintMessageWithNumber(p+0xc0,p+0xb0,ratio,score,2);*state=5;break;
 case 5:
  if((((struct Obj01709 *)p)->f198)++>50) {
   ((struct Obj01709 *)p)->f198=0;
   switch(IRC_RESULT_GetScoreRank(CTX[12],0)) {
   case 5:GFL_USE_CancelChangeAndPlayBgm(0x527,65535);break;
   case 4:GFL_USE_CancelChangeAndPlayBgm(0x528,65535);break;
   case 1:case 2:case 3:GFL_USE_CancelChangeAndPlayBgm(0x529,65535);break;
   case 0:GFL_USE_CancelChangeAndPlayBgm(0x529,65535);break;
   default:break;
   }
   *state=6;
  } break;
 case 6:
  if(!GFL_USE_IsBgmPlaying() && (((struct Obj01709 *)p)->f198)++>30) {((struct Obj01709 *)p)->f198=0;*state=7;}
  break;
 case 7:
  if(TOUCHPANEL_GetTrg()) {
   if(*(void **)CTX)COMPATIBLE_IRC_SYS_BuildProfile(*(void **)CTX,&data);
   value=IRC_RESULT_GiveReward(p);
   if(value==0) {
    if(((struct Obj01709 *)p)->f19C==0)IRC_RESULT_PrintRewardMessage(p+0xc0,p+0xb0,(u8 *)&data,((struct Obj01709 *)p)->f1A0,13);
    else IRC_RESULT_PrintRewardMessage(p+0xc0,p+0xb0,(u8 *)&data,((struct Obj01709 *)p)->f1A0,14);
    *state=8;
   } else if(value==2) {IRC_RESULT_PrintMessage(p+0xc0,p+0xb0,15,0,0);*state=8;}
   else *state=9;
  } break;
 case 8:
  if((((struct Obj01709 *)p)->f198)++>30) {IRC_APPBAR_SetEnabled(*(int *)&((struct Obj01709 *)p)->f188,1);((struct Obj01709 *)p)->f198=0;*state=9;}break;
 case 9:IRC_APPBAR_SetEnabled(*(int *)&((struct Obj01709 *)p)->f188,1);*state=10;break;
 case 10:if(TOUCHPANEL_GetTrg())IRC_RESULT_SetState(p,(unsigned int)IRC_RESULT_StateEnd);break;
 }
 if(IRC_APPBAR_GetResult(*(int * *)&((struct Obj01709 *)p)->f188)==1)IRC_RESULT_Finish(p);
 IRC_RESULT_UpdateScoreDisplay(p+0xe8);
}
void IRC_RESULT_StateEnd(u8 *p,u16 *state) {IRC_RESULT_Finish(p);}
