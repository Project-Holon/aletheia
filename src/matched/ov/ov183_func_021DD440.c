/*
 * function: BR_CODEIN_ListMain
 * address: 0x021DD440
 * packet: pkt_ov183_021DD440
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021DD5C6..021DD5C8 is two zero alignment bytes.
 * symbols:
 *   BR_CODEIN_ListSetupRowD 0x021DDCCC thumb ov183
 *   BR_CODEIN_ListHitButton 0x021DDFA0 thumb ov183
 *   BR_CODEIN_ListTeardown 0x021DDDE8 thumb ov183
 *   BR_CODEIN_ListSetupRowA 0x021DD684 thumb ov183
 *   BR_CODEIN_ListSetupRowB 0x021DD858 thumb ov183
 *   BR_CODEIN_ListSetupRowC 0x021DDA2C thumb ov183
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj00363.h"
#include "../include/Obj00731.h"
typedef unsigned int u32;
struct Pair { int x,y; };
extern void BR_FADE_Start(int,int,int,int);
extern int BR_FADE_GetResult(int *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_CODEIN_ListHitButton(char *,int,int);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int,int,struct Pair *);
extern void BR_CODEIN_ListSetupRowD(char *,char *);
extern void BR_CODEIN_ListTeardown(char *,char *),BR_CODEIN_ListSetupRowA(char *,char *),BR_CODEIN_ListSetupRowB(char *,char *),BR_CODEIN_ListSetupRowC(char *,char *);
typedef unsigned char  u8;
struct PrintSys;
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern int BR_UTIL_FlushText(u8 *p);
extern void BR_UTIL_RunHandles(char *p);
extern void BR_UTIL_FlushWindow(void *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int BR_CODEIN_ListMain(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 struct Pair pair;
 switch(*state){
 case 0:BR_FADE_Start(*(int *)&((struct Obj00363 *)q)->f0,2,3,0);*state=1;break;
 case 1:if(BR_FADE_GetResult(*(int * *)&((struct Obj00363 *)q)->f0)) *state=2;break;
 case 2:
  if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
   ((struct Obj00731 *)p)->f78=BR_CODEIN_ListHitButton(p,x,y);
   if(((struct Obj00731 *)p)->f78) *state=3;
   if(BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj00731 *)p)->f20),x,y)){
    pair.x=x;pair.y=y;
    BR_UTIL_StartEffect(*(int *)&((struct Obj00731 *)p)->f74,1,&pair);
    *state=7;
   }
  }break;
 case 3:BR_FADE_Start(*(int *)&((struct Obj00363 *)q)->f0,2,1,1);++*state;break;
 case 4:if(BR_FADE_GetResult(*(int * *)&((struct Obj00363 *)q)->f0)) ++*state;break;
 case 5:
  BR_CODEIN_ListTeardown(p,q);
  switch(*(u32 *)&((struct Obj00731 *)p)->f78){
  case 1:BR_CODEIN_ListSetupRowA(p,q);break;
  case 2:BR_CODEIN_ListSetupRowB(p,q);break;
  case 3:BR_CODEIN_ListSetupRowC(p,q);break;
  case 4:BR_CODEIN_ListSetupRowD(p,q);break;
  }
  BR_FADE_Start(*(int *)&((struct Obj00363 *)q)->f0,2,1,0);++*state;break;
 case 6:if(BR_FADE_GetResult(*(int * *)&((struct Obj00363 *)q)->f0)) *state=2;break;
 case 7:BR_FADE_Start(*(int *)&((struct Obj00363 *)q)->f0,2,3,1);*state=8;break;
 case 8:if(BR_FADE_GetResult(*(int * *)&((struct Obj00363 *)q)->f0)) *state=9;break;
 case 9:BR_PROC_SYS_PopEntry(((struct Obj00363 *)q)->fC);return 1;
 }
 for(i=0;i<4;i++) if(*(void **)(p+i*4+0x24)) BR_UTIL_FlushText(*(void **)(p+i*4+0x24));
 for(i=0;i<16;i++) if(*(void **)(p+i*4+0x34)) BR_UTIL_FlushText(*(void **)(p+i*4+0x34));
 PRINTSYS_QUE_Main(((struct Obj00731 *)p)->f4);
 if(((struct Obj00731 *)p)->f1C)BR_UTIL_FlushWindow(((struct Obj00731 *)p)->f1C);
 BR_UTIL_RunHandles(((struct Obj00731 *)p)->f74);
 return 0;
}
