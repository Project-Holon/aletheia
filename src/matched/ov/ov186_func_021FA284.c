/*
 * function: BR_BTN_HandleInput
 * address: 0x021FA284
 * packet: pkt_ov186_021FA284
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTest 0x021FAD04 thumb ov186
 *   BR_BTN_GetRowField 0x021FAF24 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_BTN_SetPos 0x021FAFCC thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_BTN_SetDrawPriority 0x021FAFA0 thumb ov186
 *   BR_BTN_UpdateTextInput 0x021FAA74 thumb ov186
 *   BR_BTN_UpdateHide 0x021FA758 thumb ov186
 *   BR_BTN_UpdateSpread 0x021FA444 thumb ov186
 *   BR_BTN_UpdateHide2 0x021FAB7C thumb ov186
 *   BR_BTN_UpdateBack 0x021FAA34 thumb ov186
 */
#include "../include/Obj00313.h"
typedef struct {int x,y;} Pair;
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTest(int *,int,int),BR_BTN_GetRowField(char *,int);
extern void BR_UTIL_DeleteTextWin(void *p, int a1);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BR_UTIL_StartEffect(char *,unsigned,const Pair *);
extern void BR_BTN_SetPos(char *p, unsigned value);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern int BR_BTN_SetDrawPriority(void *,int);
extern void BR_BTN_UpdateTextInput(void *,int *,unsigned *);
extern void BR_BTN_UpdateHide(void *,int *,unsigned char *);
extern void BR_BTN_UpdateSpread(void *,int *,unsigned char *);
extern void BR_BTN_UpdateHide2(void *,int *,unsigned char *);
extern void BR_BTN_UpdateBack(void *,int *,int *);
void BR_BTN_HandleInput(void *p,int *state,unsigned char *ctx)
{
 int found,i,x,y,kind;
 found=0;((struct Obj00313 *)ctx)->f18=0;((struct Obj00313 *)ctx)->f14=0;
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
  for(i=0;i<ctx[0x38];i++){
   if(BR_BTN_HitTest((int *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44),x,y)){
    if(BR_BTN_GetRowField(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,3)){
     if(((struct Obj00313 *)ctx)->f50){
      BR_UTIL_DeleteTextWin((void *)(((struct Obj00313 *)ctx)->f50),((struct Obj00313 *)ctx)->f4);
      ((struct Obj00313 *)ctx)->f50=0;
     }
     GFL_USE_PlaySeDefaultVolume(0x703);
     ((struct Obj00313 *)ctx)->f2C=i;
     found=1;
     ((struct Obj00313 *)ctx)->f30=x;((struct Obj00313 *)ctx)->f34=y;
     BR_UTIL_StartEffect(*(char * *)&((struct Obj00313 *)ctx)->f58,7,(Pair *)(ctx+0x30));
     BR_BTN_SetPos(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,(unsigned int)((Pair *)(ctx+0x30)));
     ((struct Obj00313 *)ctx)->f54=0;
    }else{
     kind=BR_BTN_GetRowField(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,5);
     BR_BTN_GetRowField(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,6);
     GFL_USE_PlaySeDefaultVolume(0x704);
     if(kind==1){((struct Obj00313 *)ctx)->f2C=i;BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateTextInput);}
    }
    break;
   }
  }
 }
 if(found){
  ((struct Obj00313 *)ctx)->f14=1;
  *(int *)&((struct Obj00313 *)ctx)->f1C=BR_BTN_GetRowField(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,0);
  ((struct Obj00313 *)ctx)->f20=BR_BTN_GetRowField(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,3);
  ((struct Obj00313 *)ctx)->f24=BR_BTN_GetRowField(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,1);
  ((struct Obj00313 *)ctx)->f28=BR_BTN_GetRowField(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,2);
  for(i=0;i<ctx[0x39];i++){
   if(i==((struct Obj00313 *)ctx)->f2C)BR_BTN_SetDrawPriority(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,1);
   else BR_BTN_SetDrawPriority(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,3);
  }
  switch(((struct Obj00313 *)ctx)->f1C){
  case 2:BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateHide);break;
  case 0:case 1:case 4:BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateSpread);break;
  case 3:BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateHide2);break;
  default:BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateBack);break;
  }
 }
}
