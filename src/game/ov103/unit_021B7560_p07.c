/*
 * file:     unit_021B7560_p07.c
 * unit:     yes
 * function: func_021B8074, func_021B80E4, func_021B8100, func_021B8138
 * address:  0x021B8074
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
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 */
#include "../../matched/include/Obj03231.h"
#include "../../matched/include/Obj13732.h"
#include "../../matched/include/Obj06367.h"
#include "../../matched/include/Obj22190.h"
#include "../../matched/include/Obj02159.h"

struct Descriptor;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

extern int func_021B8004(void *);
extern int func_021B8000(void *);
extern int func_021B7FFC(void *);
extern int func_021B8008(void *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int,u8);
extern void func_02045CAC(int,int,int);
extern void func_0201C6EC(int);
extern void func_0201C6FC(int,int,s16,s16,int,int);
extern void func_02082BCC(void *,int,int);
extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);
extern int func_020457B0(int,u16);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(int);
extern int func_02045730(int);
extern void func_020409B4(int);
extern void func_02045808(struct U16Vec *vec);
extern void func_020452E8(void *);
extern int func_0201C6C4(int,int);
void func_021B8074(u8 *p,int a,int b,u8 c,u8 d,u8 e,u8 f,u16 g,u8 h,u16 i);
void func_021B80E4(u8 *p);
int func_021B8100(u8 *p,u8 *q);
void func_021B8138(u8 *p,void *q,int c,int x,s16 y);

/*
 * note: The third register parameter is u8: its full-word spill reload stays after the stack-argument stores.
 */
void func_021B8074(u8 *p,int a,int b,u8 c,u8 d,u8 e,u8 f,u16 g,u8 h,u16 i) {int q; func_02082BCC(p,0,20); ((struct Obj03231 *)p)->f10=g; ((struct Obj03231 *)p)->f0=func_020450F0(a,b,c,d,e,f,h); ((struct Obj03231 *)p)->fC=func_020457B0(255,i); ((struct Obj03231 *)p)->f4=((struct Obj03231 *)p)->f0; p[8]=0; func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj03231 *)p)->f0),((struct Obj03231 *)p)->f10); q=((struct Obj03231 *)p)->f0; func_02045334((struct Descriptor *)q); func_02045374(q); func_020409B4(func_02045730(q)); }

void func_021B80E4(u8 *p) {func_02045808(((struct Obj13732 *)p)->fC);func_020452E8(((struct Obj13732 *)p)->f0);func_02082BCC(p,0,20);}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
int func_021B8100(u8 *p,u8 *q) {int a; a=((struct Obj22190 *)q)->f8; if(p[8]!=0) {if(func_0201C6C4(a,(int)func_02045770((struct Descriptor *)((struct Obj06367 *)p)->f4))==0) {func_02045334((struct Descriptor *)((struct Obj06367 *)p)->f4);p[8]=0;}} if(p[8]==0)return 1;return 0;}

/*
 * note: 2-byte zero padding before the next labelled function.
 */
void func_021B8138(u8 *p,void *q,int c,int x,s16 y) { int a,b,d; a=func_021B8004(q); b=func_021B8000(q); d=func_021B7FFC(q); func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f0),((struct Obj02159 *)p)->f10); func_02045CAC(a,c,((struct Obj02159 *)p)->fC); func_0201C6EC(b); func_0201C6FC(b,(int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f4),x,y,((struct Obj02159 *)p)->fC,d); p[8]=1; }
