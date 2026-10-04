/*
 * function: func_021B8384
 * address: 0x021B8384
 * packet: pkt_ov104_021B8384
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B630C 0x021B630C thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_021B6424 0x021B6424 thumb ov101
 *   func_021B72A0 0x021B72A0 thumb ov101
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_021B818C 0x021B818C thumb ov104
 *   func_021B7F1C 0x021B7F1C thumb ov104
 *   func_021B8768 0x021B8768 thumb ov104
 *   func_021B8880 0x021B8880 thumb ov104
 *   func_021B87F4 0x021B87F4 thumb ov104
 *   func_021B817C 0x021B817C thumb ov104
 *   func_021B8528 0x021B8528 thumb ov104
 */
#include "../include/Obj04432.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int words[33];} Block;
extern int func_021B7250(int *);
extern void func_021B63BC(int *);
extern int func_021B630C(int *,int);
extern void func_021B63CC(int *,int);
extern int func_021B6424(int);
extern void func_021B72A0(int,int);
extern int func_021B6480(int *);
extern void func_021B818C(u8 *);
extern void func_021B7F1C(u8 *,void *,int,int,s16);
extern int func_021B8768(u8 *,const Block *);
extern int func_021B8880(u8 *);
extern void func_021B87F4(u8 *,Block *);
extern void func_020061E4(u32 a);
extern void func_021B817C(u8 *,void (*)(u8 *,u16 *));
extern void func_021B8528(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
void func_021B8384(u8 *p,u16 *state) {
 Block data; int diff;
 if(*state<5 && func_021B7250(*(int * *)&((struct Obj04432 *)p)->f7AC)==1) {
  func_021B63BC(*(int **)(CTX(p)+4));
  *(u32 *)(CTX(p)+0xc)=1;
  func_021B818C(p);
  return;
 }
 switch(*state) {
 case 0: if(func_021B630C(*(int **)(CTX(p)+4),2)) *state=1; break;
 case 1: func_021B7F1C(p+0xcc,p+0xbc,2,0,0); *state=2; break;
 case 2: if(func_021B8768(p+0xe0,(Block *)(p+0x814))) *state=3; break;
 case 3: func_021B63CC(*(int **)(CTX(p)+4),2); if(func_021B6424(*(int *)(CTX(p)+4))) *state=4; break;
 case 4: if(func_021B630C(*(int **)(CTX(p)+4),3)) { func_021B72A0(*(int *)&((struct Obj04432 *)p)->f7AC,0); *state=5; } break;
 case 5: if(((struct Obj04432 *)p)->f80A>=60) { func_020061E4(0x64b); func_021B7F1C(p+0xcc,p+0xbc,3,0,0); *state=6; } break;
 case 6:
  if((((struct Obj04432 *)p)->f8A2)++<30) return;
  CTX(p)[0x10]=func_021B8880(p);
  func_021B87F4(p+0xe0,&data);
  diff=((struct Obj04432 *)p)->f88E-*(u16 *)((u8 *)&data+122);
  if(diff<0) diff=-diff;
  *(int *)(CTX(p)+0x14)=diff;
  *(int *)(CTX(p)+0xc)=0;
  *state=7; return;
 case 7: func_021B818C(p); return;
 }
 if(*state>=1 && *state<=5) { if(((struct Obj04432 *)p)->f80A<=60) ++((struct Obj04432 *)p)->f80A; }
 if(*state<3) { if(func_021B6480(*(int **)(CTX(p)+4))) func_021B817C(p,func_021B8528); }
}
