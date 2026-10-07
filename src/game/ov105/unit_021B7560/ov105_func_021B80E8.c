/*
 * function: func_021B80E8,func_021B8340
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
 *   func_021B871C 0x021B871C thumb ov105
 *   func_021B8730 0x021B8730 thumb ov105
 *   func_021B83E0 0x021B83E0 thumb ov105
 *   func_021B8438 0x021B8438 thumb ov105
 *   func_021B7EEC 0x021B7EEC thumb ov105
 *   func_021B87E8 0x021B87E8 thumb ov105
 *   func_021B658C 0x021B658C thumb ov101
 *   func_021B8860 0x021B8860 thumb ov105
 *   func_021B8008 0x021B8008 thumb ov105
 *   func_021B7DE4 0x021B7DE4 thumb ov105
 *   func_021B728C 0x021B728C thumb ov101
 *   func_021B80BC 0x021B80BC thumb ov105
 *   func_021B80CC 0x021B80CC thumb ov105
 *   func_021B8434 0x021B8434 thumb ov105
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B8340 0x021B8340 thumb ov105
 *   func_02035C60 0x02035C60 arm
 */
#include "../../../matched/include/Obj01709.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; u8 low:4,high:4; u8 tail[32]; } Data;
typedef struct {u32 objects[3]; u8 pad[0x24];u8 digits[3];u8 pad1;int state[3];} Display;
extern void func_021B871C(u8 *);
extern unsigned func_021B8730(u8 *p);
extern void func_021B83E0(Display *,int);
extern int func_021B8438(u8 *p, int i);
extern void func_021B7EEC(u8 *,void *,u8,u16,u16);
extern int func_021B87E8(unsigned,int *);
extern void func_021B658C(void *,Data *);
extern int func_021B8860(u8 *);
extern void func_021B8008(u8 *,void *,u8 *,u8,int);
extern void func_021B7DE4(u8 *,void *,int,int,s16);
extern void func_021B728C(int,int);
extern void func_021B80BC(unsigned char *p, unsigned int v);
extern void func_021B80CC(u8 *);
extern int func_021B8434(void *);
extern int func_021B7250(int *);
extern void func_021B8340(u8 *,u16 *);
extern int func_02035C60(void);
extern void func_020061E4(u32);
extern void func_02005D90(int,int);
extern int func_02005F38(void);
#define CTX (*(u8 **)(p+0x1a4))
void func_021B80E8(u8 *p,u16 *state) {
 Data data; int value; u32 ratio; u8 score;
 switch(*state) {
 case 0:
  if((((struct Obj01709 *)p)->f198)++>30) {((struct Obj01709 *)p)->f198=0;*state=1;} break;
 case 1:func_021B871C(p+0x128);*state=2;break;
 case 2:
  if(func_021B8730(p+0x128)) {
   func_020061E4(0x653);
   func_021B83E0((Display *)(p+0xe8),0);func_021B83E0((Display *)(p+0xe8),1);func_021B83E0((Display *)(p+0xe8),2);*state=3;
  } break;
 case 3:
  if(func_021B8438((u8 *)(p+0xe8),0) && func_021B8438((u8 *)(p+0xe8),1) && func_021B8438((u8 *)(p+0xe8),2)) *state=4;
  break;
 case 4:
  score=CTX[12];ratio=(u8)(score/10+2);
  if(ratio>12)ratio=12;else if(ratio<2)ratio=2;
  func_021B7EEC(p+0xc0,p+0xb0,ratio,score,2);*state=5;break;
 case 5:
  if((((struct Obj01709 *)p)->f198)++>50) {
   ((struct Obj01709 *)p)->f198=0;
   switch(func_021B87E8(CTX[12],0)) {
   case 5:func_02005D90(0x527,65535);break;
   case 4:func_02005D90(0x528,65535);break;
   case 1:case 2:case 3:func_02005D90(0x529,65535);break;
   case 0:func_02005D90(0x529,65535);break;
   default:break;
   }
   *state=6;
  } break;
 case 6:
  if(!func_02005F38() && (((struct Obj01709 *)p)->f198)++>30) {((struct Obj01709 *)p)->f198=0;*state=7;}
  break;
 case 7:
  if(func_02035C60()) {
   if(*(void **)CTX)func_021B658C(*(void **)CTX,&data);
   value=func_021B8860(p);
   if(value==0) {
    if(((struct Obj01709 *)p)->f19C==0)func_021B8008(p+0xc0,p+0xb0,(u8 *)&data,((struct Obj01709 *)p)->f1A0,13);
    else func_021B8008(p+0xc0,p+0xb0,(u8 *)&data,((struct Obj01709 *)p)->f1A0,14);
    *state=8;
   } else if(value==2) {func_021B7DE4(p+0xc0,p+0xb0,15,0,0);*state=8;}
   else *state=9;
  } break;
 case 8:
  if((((struct Obj01709 *)p)->f198)++>30) {func_021B728C(*(int *)&((struct Obj01709 *)p)->f188,1);((struct Obj01709 *)p)->f198=0;*state=9;}break;
 case 9:func_021B728C(*(int *)&((struct Obj01709 *)p)->f188,1);*state=10;break;
 case 10:if(func_02035C60())func_021B80BC(p,(unsigned int)func_021B8340);break;
 }
 if(func_021B7250(*(int * *)&((struct Obj01709 *)p)->f188)==1)func_021B80CC(p);
 func_021B8434(p+0xe8);
}
void func_021B8340(u8 *p,u16 *state) {func_021B80CC(p);}
