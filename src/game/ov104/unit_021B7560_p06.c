/*
 * file:     unit_021B7560_p06.c
 * unit:     yes
 * function: func_021B816C, func_021B8178, func_021B817C, func_021B818C, func_021B8198, func_021B8220, func_021B829C, func_021B8384, func_021B8528, func_021B85D8, func_021B85E4, func_021B8614, func_021B8624, func_021B86A0, func_021B8724, func_021B874C, func_021B8768
 * address:  0x021B816C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B6480 0x021B6480 thumb ov101
 *   func_02040588 0x02040588 arm
 *   func_021B8104 0x021B8104 thumb ov104
 *   func_021B8F00 0x021B8F00 thumb ov104
 *   func_021B727C 0x021B727C thumb ov101
 *   func_021B884C 0x021B884C thumb ov104
 *   func_021B8C3C 0x021B8C3C thumb ov104
 *   func_021B7F1C 0x021B7F1C thumb ov104
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B630C 0x021B630C thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_021B6424 0x021B6424 thumb ov101
 *   func_021B72A0 0x021B72A0 thumb ov101
 *   func_021B8880 0x021B8880 thumb ov104
 *   func_021B87F4 0x021B87F4 thumb ov104
 *   func_02087058 0x02087058 arm
 *   func_02086FE8 0x02086FE8 arm
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B64F0 0x021B64F0 thumb ov101
 *   d_021B8F28 0x021B8F28 data a4
 *   func_021B6508 0x021B6508 thumb ov101
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021B64B8 0x021B64B8 thumb ov101
 */
#include "../../matched/include/Obj10246.h"
#include "../../matched/include/Obj22226.h"
#include "../../matched/include/Obj22227.h"
#include "../../matched/include/Obj13744.h"
#include "../../matched/include/Obj13745.h"
#include "../../matched/include/Obj05275.h"
#include "../../matched/include/Obj04432.h"
#include "../../matched/include/Obj22229.h"
#include "../../matched/include/Obj01389.h"
#include "../../matched/include/Obj22230.h"
#include "../../matched/include/Obj22231.h"
#include "../../matched/include/Obj22232.h"
#include "../../matched/include/Obj04433.h"

#define CTX(p) (*(u8 **)((p)+0x8b0))
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef enum { BASE=0x814 } Offset;

typedef struct {int words[33];} Block;

typedef struct { u32 f0; u32 f4; } Pair;

extern int func_021B7250(int *p);
extern int func_021B6480(int *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021B8104(u32 *);
extern void func_021B8F00(void *);
extern int func_021B727C(int);
extern int func_021B884C(u32 *p);
extern void func_021B8C3C(u8 *p, const void *a, int color);
extern void func_021B7F1C(u8 *,void *,int,int,s16);
extern void func_020061E4(u32 a);
extern void func_021B63BC(int *);
extern int func_021B630C(int *,int);
extern void func_021B63CC(int *,int);
extern int func_021B6424(int);
extern void func_021B72A0(int,int);
extern int func_021B8880(u8 *);
extern void func_021B87F4(u8 *,Block *);
extern void func_02082BCC(void *, int, int);
extern int func_02087058(void);
extern void func_02086FE8(void);
extern unsigned long long func_020870D0(void);
extern void func_021B64F0(u32 p, u32 a, u32 b, u32 c, u32 d);
extern void func_021B6508(u32 p, u32 a);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_021B64B8(u32 p, u32 a, u32 b, u32 c, u8 d, u32 e, u32 f, u32 g);
void func_021B816C(u8 *p);
u32 func_021B8178(u8 *p);
void func_021B817C(char *p, u32 v);
void func_021B818C(u8 *p);
void func_021B8198(u8 *p,u16 *state);
void func_021B8220(u8 *p,u16 *state);
void func_021B829C(u8 *p,u16 *state);
void func_021B8384(u8 *p,u16 *state);
void func_021B8528(u8 *p,u16 *state);
void func_021B85D8(void *p);
void func_021B85E4(u8 *p);
int func_021B8614(u8 *p);
void func_021B8624(u8 *p);
int func_021B86A0(u8 *p);
void func_021B8724(u8 *p,int a);
void func_021B874C(u8 *p);
int func_021B8768(u8 *p,const Block *q);
extern const u32 d_021B8F28[];


void func_021B816C(u8 *p) { ((struct Obj10246 *)p)->fC = 0; ((struct Obj10246 *)p)->f10 = 0; ((struct Obj10246 *)p)->f14 = 1; }


u32 func_021B8178(u8 *p) { return ((struct Obj22226 *)p)->f18; }

void func_021B817C(char *p, u32 v) {
    *(u32 *)(p + 0x804) = v;
    *(u16 *)(p + 0x808) = 0;
}


void func_021B818C(u8 *p) { ((struct Obj22227 *)p)->f80C = 1; }

void func_021B8198(u8 *p,u16 *state) { switch(*state) { case 0: ((struct Obj13744 *)p)->f80A=0; *state=1; break; case 1: func_02040588(2,0); *state=3; break; case 3: func_021B816C(p+0x7b0); func_021B817C((char *)p,(u32)func_021B8220); break; } if(func_021B7250(((struct Obj13744 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); } if(func_021B6480(*(void **)(CTX(p)+4))!=0) func_021B817C((char *)p,(u32)func_021B8528); }

void func_021B8220(u8 *p,u16 *state) { func_021B8104((u32 *)(p+0x7b0)); if(func_021B8178(p+0x7b0)) { ((struct Obj13745 *)p)->f8A8=1; func_021B85E4(p+0x814); func_021B8F00(p+0x7cc); func_021B817C((char *)p,(u32)func_021B829C); } if(func_021B7250(((struct Obj13745 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); } if(func_021B6480(*(void **)(CTX(p)+4))!=0) func_021B817C((char *)p,(u32)func_021B8528); }

/*
 * lever: Enum subblock offset and grouped offset arithmetic retain the far-field register.
 */
void func_021B829C(u8 *p,u16 *state) {
 Offset base=BASE;
 int point[2];
 *(u32 *)(p+(base+0x98))=0;
 if(!func_021B727C(*(int *)(p+(base-0x68)))) {
  if(func_021B884C((u32 *)point)) {
   func_021B8C3C(p+0x278,point,func_021B86A0(p+base));
   if(!*(u16 *)(p+(base+0x8c))) func_021B8624(p+base);
   ((struct Obj05275 *)p)->f8AC=1;
  }
 }
 if(func_021B8614(p+base)) {
  if(!((struct Obj05275 *)p)->f89C) {
   func_021B7F1C(p+0xcc,p+0xbc,1,0,0);
   func_020061E4(0x654);
   ((struct Obj05275 *)p)->f89C=1;
  }
  if(((struct Obj05275 *)p)->f89C) func_021B8384(p,(u16 *)(p+0x8a0));
 }
 if(!((struct Obj05275 *)p)->f89C) {
  if(func_021B7250(*(int * *)&((struct Obj05275 *)p)->f7AC)==1) { *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); }
  if(func_021B6480(*(int **)(CTX(p)+4))) func_021B817C((char *)p,(u32)func_021B8528);
 }
}

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
 if(*state<3) { if(func_021B6480(*(int **)(CTX(p)+4))) func_021B817C((char *)p,(u32)func_021B8528); }
}

/*
 * extent: 174 code bytes then two zero alignment bytes before 021B85D8.
 */
void func_021B8528(u8 *p,u16 *state) { switch(*state) { case 0: if(func_021B6480(*(void **)(CTX(p)+4))>0) { CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=1; func_021B818C(p); return; } if(func_021B6480(*(void **)(CTX(p)+4))<0) *state=1; break; case 1: CTX(p)[0x10]=0; *(u32 *)(CTX(p)+0xc)=2; *state=2; break; case 2: func_021B7F1C(p+0xcc,p+0xbc,4,0,0); *state=3; break; case 3: if(func_021B630C(*(void **)(CTX(p)+4),6)) *state=4; break; case 4: func_021B818C(p); break; } }

void func_021B85D8(void *p) { func_02082BCC(p, 0, 0x84); }

void func_021B85E4(u8 *p) { if(func_02087058()) func_02086FE8(); *(unsigned long long *)(p+0x7c)=(func_020870D0()<<6)/33514; }

int func_021B8614(u8 *p) { if(((struct Obj22229 *)p)->f78>=10) return 1; return 0; }

void func_021B8624(u8 *p) { if(((struct Obj01389 *)p)->f78<10) { ((Pair *)p)[((struct Obj01389 *)p)->f78].f0=(func_020870D0()<<6)/33514-*(unsigned long long *)(p+0x7c); if(((struct Obj01389 *)p)->f78==0) ((Pair *)p)[((struct Obj01389 *)p)->f78].f4=0; else ((Pair *)p)[((struct Obj01389 *)p)->f78].f4=((Pair *)p)[((struct Obj01389 *)p)->f78].f0-((Pair *)p)[((struct Obj01389 *)p)->f78-1].f0; ++((struct Obj01389 *)p)->f78; } else if(((struct Obj01389 *)p)->f7A<99) ++((struct Obj01389 *)p)->f7A; }

static inline int magnitude(int x) { return x<0 ? -x : x; }

int func_021B86A0(u8 *p) {
 int diff; int result; int sound; u16 n;
 n=((struct Obj22230 *)p)->f78;
 if(n<2) { sound=0x64c; result=3; }
 else {
  diff=*(int *)(p+(n-1)*8+4)-*(int *)(p+(n-2)*8+4);
  if(magnitude(diff)>=0 && magnitude(diff)<50) {sound=0x64c;result=3;}
  else if(diff<0) {
   if(magnitude(diff)<200) {sound=0x64f;result=1;} else {sound=0x650;result=0;}
  } else {
   if(magnitude(diff)<200) {sound=0x64d;result=5;} else {sound=0x64e;result=6;}
  }
 }
 func_020061E4(sound); return result;
}

void func_021B8724(u8 *p,int a) { func_02082BCC(p,0,0x198); ((struct Obj22231 *)p)->f0=a; func_021B64F0(a,0xf00,(int)d_021B8F28,1,(int)p); }

void func_021B874C(u8 *p) { func_021B6508(((struct Obj22232 *)p)->f0,0xf00); func_02082BCC(p,0,0x198); }

/*
 * extent: Two zero alignment bytes at 021B87F2 before 021B87F4.
 */
int func_021B8768(u8 *p,const Block *q) {
 switch(((struct Obj04433 *)p)->f4) {
 case 0: *(Block *)(p+0x110)=*q; ((struct Obj04433 *)p)->f4=1; break;
 case 1:
  if(func_021B64B8(((struct Obj04433 *)p)->f0,0xf00,0x84,(u32)(p+0x110),(u8)(func_0203D1A4((struct Link *)((int)func_020399A8()))==0),0,0,1)) ((struct Obj04433 *)p)->f4=2;
  break;
 case 2:
  if(((struct Obj04433 *)p)->f194) { ((struct Obj04433 *)p)->f194=0; ((struct Obj04433 *)p)->f4=0; return 1; }
  break;
 }
 return 0;
}
