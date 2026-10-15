/*
 * unit: yes
 * function: func_021B97C4, CHIHOU_ZUKAN_AWARD_Task
 * address: 0x021B97C4
 * packet: pkt_ov221_021B97C4
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   CHIHOU_ZUKAN_AWARD_IsWindowsReady 0x021B9B64 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_IsActorIdle 0x021B9DAC thumb ov221
 *   CHIHOU_ZUKAN_AWARD_FlushWindows 0x021B9B18 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_UpdateActor 0x021B9D38 thumb ov221
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Update 0x021B9F7C thumb ov221
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 */
#include "../include/Obj02558.h"
#include "../include/Obj26065.h"
#include "../include/Obj26066.h"
typedef unsigned int u32;
extern int CHIHOU_ZUKAN_AWARD_IsWindowsReady(unsigned char*);
extern int CHIHOU_ZUKAN_AWARD_IsActorIdle(char *p);
extern void CHIHOU_ZUKAN_AWARD_FlushWindows(unsigned char*);
extern void CHIHOU_ZUKAN_AWARD_UpdateActor(unsigned char*);
struct PrintSys;
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void*);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,unsigned short);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(unsigned char);
extern u32 TOUCHPANEL_GetPointTrg(u32*,u32*);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int func_021B97C4(int unused, int *state, int unused2, unsigned char *p)
{
 int ready;
 u32 x,y;
 switch(*state) {
 case 0:
  ready=1;
  if(CHIHOU_ZUKAN_AWARD_IsWindowsReady(p)==0) ready=0;
  if(ready && ((struct Obj26065 *)(*(char* *)&((struct Obj02558 *)p)->f4))->f4==0) {
   if(GFL_USE_IsBgmFading()) ready=0;
   else {GFL_USE_SetBgmPlayerParam((void*)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(0x524,0xffff);}
  }
  if(ready) {FADE_Start(3,16,0,0);*state=1;}
  break;
 case 1:
  if(!FADE_IsActive()) {if(((struct Obj26066 *)(*(char* *)&((struct Obj02558 *)p)->f4))->f4!=0) *state=4;else *state=2;}
  break;
 case 2: if(CHIHOU_ZUKAN_AWARD_IsActorIdle((char *)p)) *state=3; break;
 case 3:
  if(!GFL_USE_IsBgmPlaying()) {GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(6);*state=4;}
  break;
 case 4:
  ready=0;
  if(KEY_GetTrg()&3) {func_020355D8(0);ready=1;}
  else if(TOUCHPANEL_GetPointTrg(&x,&y)) {func_020355D8(1);ready=1;}
  if(ready) {*state=5;FADE_Start(3,0,16,0);}
  break;
 case 5: if(!FADE_IsActive()) *state=6; break;
 case 6: return 1;
 }
 PRINTSYS_QUE_Main(*(void* *)&((struct Obj02558 *)p)->f10);
 CHIHOU_ZUKAN_AWARD_FlushWindows(p);
 if(*state>=1 && *state<=5) CHIHOU_ZUKAN_AWARD_UpdateActor(p);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(*(void* *)&((struct Obj02558 *)p)->f8);
 return 0;
}
void CHIHOU_ZUKAN_AWARD_Task(void) {}
