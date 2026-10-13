/*
 * unit: yes
 * function: func_021B97C4, func_021B98FC
 * address: 0x021B97C4
 * packet: pkt_ov222_021B97C4
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021B9BFC 0x021B9BFC thumb ov222
 *   func_021B9E44 0x021B9E44 thumb ov222
 *   func_021B9BB0 0x021B9BB0 thumb ov222
 *   func_021B9DD0 0x021B9DD0 thumb ov222
 *   func_021BA014 0x021BA014 thumb ov222
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
#include "../include/Obj02560.h"
#include "../include/Obj26077.h"
#include "../include/Obj26078.h"
typedef unsigned int u32;
extern int func_021B9BFC(char *p);
extern int func_021B9E44(char *p);
extern void func_021B9BB0(char *p);
extern void func_021B9DD0(char *p);
struct PrintSys;
extern void func_021BA014(char *p);
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
  if(func_021B9BFC((char *)p)==0) ready=0;
  if(ready && ((struct Obj26077 *)(*(char* *)&((struct Obj02560 *)p)->f4))->f4==0) {
   if(GFL_USE_IsBgmFading()) ready=0;
   else {GFL_USE_SetBgmPlayerParam((void*)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(0x524,0xffff);}
  }
  if(ready) {FADE_Start(3,16,0,0);*state=1;}
  break;
 case 1:
  if(!FADE_IsActive()) {if(((struct Obj26078 *)(*(char* *)&((struct Obj02560 *)p)->f4))->f4!=0) *state=4;else *state=2;}
  break;
 case 2: if(func_021B9E44((char *)p)) *state=3; break;
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
 PRINTSYS_QUE_Main(*(void* *)&((struct Obj02560 *)p)->f10);
 func_021B9BB0((char *)p);
 if(*state>=1 && *state<=5) func_021B9DD0((char *)p);
 func_021BA014(*(void* *)&((struct Obj02560 *)p)->f8);
 return 0;
}
void func_021B98FC(void) {}
