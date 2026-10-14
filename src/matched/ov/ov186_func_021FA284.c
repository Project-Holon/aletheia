/*
 * function: func_021FA284
 * address: 0x021FA284
 * packet: pkt_ov186_021FA284
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021FAD04 0x021FAD04 thumb ov186
 *   func_021FAF24 0x021FAF24 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   BR_BTN_SetPos 0x021FAFCC thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FAA74 0x021FAA74 thumb ov186
 *   func_021FA758 0x021FA758 thumb ov186
 *   func_021FA444 0x021FA444 thumb ov186
 *   func_021FAB7C 0x021FAB7C thumb ov186
 *   func_021FAA34 0x021FAA34 thumb ov186
 */
#include "../include/Obj00313.h"
typedef struct {int x,y;} Pair;
typedef unsigned int   u32;
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int func_021FAD04(int *,int,int),func_021FAF24(char *,int);
extern void func_021FD15C(void *p, int a1);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021FD860(char *,unsigned,const Pair *);
extern void BR_BTN_SetPos(char *p, unsigned value);
extern int *func_021FD73C(int *p, int v);
extern int func_021FAFA0(void *,int);
extern void func_021FAA74(void *,int *,unsigned *);
extern void func_021FA758(void *,int *,unsigned char *);
extern void func_021FA444(void *,int *,unsigned char *);
extern void func_021FAB7C(void *,int *,unsigned char *);
extern void func_021FAA34(void *,int *,int *);
void func_021FA284(void *p,int *state,unsigned char *ctx)
{
 int found,i,x,y,kind;
 found=0;((struct Obj00313 *)ctx)->f18=0;((struct Obj00313 *)ctx)->f14=0;
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
  for(i=0;i<ctx[0x38];i++){
   if(func_021FAD04((int *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44),x,y)){
    if(func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,3)){
     if(((struct Obj00313 *)ctx)->f50){
      func_021FD15C((void *)(((struct Obj00313 *)ctx)->f50),((struct Obj00313 *)ctx)->f4);
      ((struct Obj00313 *)ctx)->f50=0;
     }
     GFL_USE_PlaySeDefaultVolume(0x703);
     ((struct Obj00313 *)ctx)->f2C=i;
     found=1;
     ((struct Obj00313 *)ctx)->f30=x;((struct Obj00313 *)ctx)->f34=y;
     func_021FD860(*(char * *)&((struct Obj00313 *)ctx)->f58,7,(Pair *)(ctx+0x30));
     BR_BTN_SetPos(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,(unsigned int)((Pair *)(ctx+0x30)));
     ((struct Obj00313 *)ctx)->f54=0;
    }else{
     kind=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,5);
     func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,6);
     GFL_USE_PlaySeDefaultVolume(0x704);
     if(kind==1){((struct Obj00313 *)ctx)->f2C=i;func_021FD73C(p,(int)func_021FAA74);}
    }
    break;
   }
  }
 }
 if(found){
  ((struct Obj00313 *)ctx)->f14=1;
  *(int *)&((struct Obj00313 *)ctx)->f1C=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,0);
  ((struct Obj00313 *)ctx)->f20=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,3);
  ((struct Obj00313 *)ctx)->f24=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,1);
  ((struct Obj00313 *)ctx)->f28=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,2);
  for(i=0;i<ctx[0x39];i++){
   if(i==((struct Obj00313 *)ctx)->f2C)func_021FAFA0(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,1);
   else func_021FAFA0(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,3);
  }
  switch(((struct Obj00313 *)ctx)->f1C){
  case 2:func_021FD73C(p,(int)func_021FA758);break;
  case 0:case 1:case 4:func_021FD73C(p,(int)func_021FA444);break;
  case 3:func_021FD73C(p,(int)func_021FAB7C);break;
  default:func_021FD73C(p,(int)func_021FAA34);break;
  }
 }
}
