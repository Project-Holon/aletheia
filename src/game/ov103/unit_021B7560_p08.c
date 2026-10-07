/*
 * file:     unit_021B7560_p08.c
 * unit:     yes
 * function: func_021B81A4, func_021B824C, func_021B82DC, func_021B831C, func_021B8338
 * address:  0x021B81A4
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8004 0x021B8004 thumb ov103
 *   func_021B8000 0x021B8000 thumb ov103
 *   func_021B7FFC 0x021B7FFC thumb ov103
 *   func_021B8008 0x021B8008 thumb ov103
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_021B8138 0x021B8138 thumb ov103
 *   func_02045334 0x02045334 arm
 */
#include "../../matched/include/Obj02811.h"
#include "../../matched/include/Obj02159.h"
#include "../../matched/include/Obj01388.h"
#include "../../matched/include/Obj10244.h"
#include "../../matched/include/Obj13734.h"

struct Descriptor;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int   u32;

extern int func_021B8004(void *);
extern int func_021B8000(void *);
extern int func_021B7FFC(void *);
extern int func_021B8008(void *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int,u8);
extern void func_02045CAC(int,int,int);
extern void func_0201C6EC(int);
extern void func_0201C6FC(int,int,s16,s16,int,int);
extern u8 func_02045738(struct Descriptor *p);
extern int func_02045740(int);
extern int func_0201D304(int,int,int);
extern int func_0201D42C(int,int);
extern void func_0201C724(int,int,s16,s16,int,int,int);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern int func_02045EC0(int,int);
extern void func_0201F250(int,int,int);
extern void func_02045808(int);
extern void func_021B8138(u8 *,void *,int,int,s16);
extern void func_02045334(struct Descriptor *);
void func_021B81A4(u8 *p,void *q,int c);
void func_021B824C(u8 *p,void *q,int c,u8 *x,s16 y,s16 z,int k);
void func_021B82DC(u8 *a,u8 *b,int c);
void func_021B831C(u8 *p);
void func_021B8338(u32 p,u32 a);

/*
 * note: Narrow each dimension after shifting right, then subtract from the u16 coordinates.
 */
void func_021B81A4(u8 *p,void *q,int c) {int a,b,d; u16 x,y; a=func_021B8004(q); b=func_021B8000(q); d=func_021B7FFC(q); func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj02811 *)p)->f0),((struct Obj02811 *)p)->f10); func_02045CAC(a,c,((struct Obj02811 *)p)->fC); x=func_02045738((struct Descriptor *)(((struct Obj02811 *)p)->f0))*4; y=func_02045740(((struct Obj02811 *)p)->f0)*4; x-=(u16)(func_0201D304(((struct Obj02811 *)p)->fC,d,0)>>1); y-=(u16)(func_0201D42C(((struct Obj02811 *)p)->fC,d)>>1); func_0201C6EC(b); func_0201C724(b,(int)func_02045770((struct Descriptor *)((struct Obj02811 *)p)->f4),x,y,((struct Obj02811 *)p)->fC,d,0x3dc4); p[8]=1; }

void func_021B824C(u8 *p,void *q,int c,u8 *x,s16 y,s16 z,int k) {int a,b,d,e; func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f0),((struct Obj02159 *)p)->f10); a=func_021B8008(q); b=func_021B8004(q); func_0201F02C((struct WordSet *)a,0,x+12); e=func_02045EC0(b,c); func_0201F250(a,((struct Obj02159 *)p)->fC,e); func_02045808(e); b=func_021B8000(q); d=func_021B7FFC(q); func_0201C6EC(b); func_0201C6FC(b,(int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f4),y,z,((struct Obj02159 *)p)->fC,d); p[8]=1; }

void func_021B82DC(u8 *a,u8 *b,int c) { int *p=*(int * *)&((struct Obj01388 *)b)->fB0C; if(p[0])func_021B824C(a,b+0x174,c,(u8 *)p[2],0,0,0x37); else func_021B8138(a,b+0x174,c,0,0); }

void func_021B831C(u8 *p) {func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj10244 *)p)->f0),((struct Obj10244 *)p)->f10);func_02045334((struct Descriptor *)((struct Obj10244 *)p)->f0);}

void func_021B8338(u32 p,u32 a) {((struct Obj13734 *)p)->f728=a;((struct Obj13734 *)p)->f72C=0;}
