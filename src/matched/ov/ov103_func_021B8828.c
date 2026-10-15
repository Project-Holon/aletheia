/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_HandleScoring
 * address: 0x021B8828
 * packet: pkt_ov103_021B8828
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 *   COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 *   COMPATIBLE_IRC_SYS_SendOwnValue 0x021B6424 thumb ov101
 *   IRC_APPBAR_SetActive 0x021B72A0 thumb ov101
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_SetFinished 0x021B8358 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_PrintMessage 0x021B8138 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_SendDrawing 0x021B8B38 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing 0x021B8DE4 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing 0x021B8BC0 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_SetHandler 0x021B8338 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_HandleAbort 0x021B8A44 thumb ov103
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200A9D4 0x0200A9D4 thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   IRC_RANKING_GetFromSave  0x0200A8A0  thumb  arm9
 */
#include "../include/Obj03232.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y;} Pair;
typedef struct {Pair point[12];} Line;
typedef struct {Pair origin,end;Line a,b;u32 tail[2];} Block;
extern int IRC_APPBAR_GetResult(int *);
extern int COMPATIBLE_IRC_SYS_StepShareValue(int *,int);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(int *,int);
extern int COMPATIBLE_IRC_SYS_SendOwnValue(int);
extern void IRC_APPBAR_SetActive(int,int);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(u8 *,void *,int,int,s16);
extern int IRC_COMPATIBLE_TOUCH_TEST_SendDrawing(u8 *,const Block *);
extern u8 IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing(u8 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing(u8 *,Block *);
extern void IRC_COMPATIBLE_TOUCH_TEST_SetHandler(u32 p, u32 a);
extern void IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(u8 *,u16 *);
struct Big;
struct Ctx;
struct T0200A9A4;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *IRC_RANKING_GetFromSave(void *);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_0200A9D4(struct T0200A9A4 *o, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32);
#define CTX (*(u8 **)(p+0xb0c))
void IRC_COMPATIBLE_TOUCH_TEST_HandleScoring(u8 *p,u16 *state) {
 Block ref; Block cur;
 if(*state<5 && IRC_APPBAR_GetResult(*(int * *)&((struct Obj03232 *)p)->fA38)==1) {
  *(u32 *)(CTX+12)=1; IRC_COMPATIBLE_TOUCH_TEST_SetFinished(p); return;
 }
 switch(*state) {
 case 0: if(COMPATIBLE_IRC_SYS_StepShareValue(*(int **)(CTX+4),4)) *state=1; break;
 case 1: IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,4,0,0); *state=2; break;
 case 2:
  ref.origin=*(Pair *)(p+0xa3c);
  ref.end=*(Pair *)(p+0xa44);
  ref.a=*(Line *)(p+0xa4c);
  ref.b=*(Line *)(p+0xaac);
  ref.tail[0]=((struct Obj03232 *)p)->f738;
  if(*(void **)CTX) {
   void *src;
   src=IRC_RANKING_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(*(void **)CTX)));
   ref.tail[1]=func_0200A9D4(src,func_02008530((const struct Sub0200852CObj *)(*(u8 **)(CTX+8)+12)))==0;
  }
  if(IRC_COMPATIBLE_TOUCH_TEST_SendDrawing(p+0x75c,&ref)) *state=3; break;
 case 3:
  COMPATIBLE_IRC_SYS_SetOwnValue(*(int **)(CTX+4),3);
  if(COMPATIBLE_IRC_SYS_SendOwnValue(*(int *)(CTX+4))) *state=4; break;
 case 4:
  if(COMPATIBLE_IRC_SYS_StepShareValue(*(int **)(CTX+4),5)) {
   IRC_APPBAR_SetActive(*(int *)&((struct Obj03232 *)p)->fA38,0); *state=5;
  } break;
 case 5:
  if(((struct Obj03232 *)p)->f72E>=60) {
   GFL_USE_PlaySeDefaultVolume(0x64b);IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(p+0x184,p+0x174,5,0,0);
   ((struct Obj03232 *)p)->f73C=0; *state=6;
  } break;
 case 6:
  if((((struct Obj03232 *)p)->f73C)++<30) return;
  CTX[0x10]=IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing(p);
  IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing(p+0x75c,&cur);
  CTX[0x11]=((struct Obj03232 *)p)->f738+cur.tail[0];
  CTX[0x12]=cur.tail[1];
  *(u32 *)(CTX+12)=0;*state=7;return;
 case 7:IRC_COMPATIBLE_TOUCH_TEST_SetFinished(p);return;
 }
 if(*state<3 && COMPATIBLE_IRC_SYS_GetValueDifference(*(int **)(CTX+4))) IRC_COMPATIBLE_TOUCH_TEST_SetHandler((u32)p,(u32)IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
 if(*state>=1 && *state<=5) { if(((struct Obj03232 *)p)->f72E<=60) ++((struct Obj03232 *)p)->f72E; }
}
