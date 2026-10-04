/*
 * function: func_021B824C
 * address: 0x021B824C
 * packet: pkt_ov103_021B824C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2-byte zero padding before the next labelled function.
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
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj02159.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int func_021B8004(void *); extern int func_021B8000(void *); extern int func_021B7FFC(void *); extern int func_021B8008(void *);
struct Descriptor;
extern void *func_02045770(struct Descriptor *); extern void func_02043B5C(int,u8); extern void func_02045CAC(int,int,int); extern void func_0201C6EC(int); extern void func_0201C6FC(int,int,s16,s16,int,int);
typedef unsigned int   u32;
struct WordSet;
extern void func_0201F02C(struct WordSet *p, u32 i, void *a); extern int func_02045EC0(int,int); extern void func_0201F250(int,int,int); extern void func_02045808(int);
void func_021B824C(u8 *p,void *q,int c,u8 *x,s16 y,s16 z,int k) {int a,b,d,e; func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f0),((struct Obj02159 *)p)->f10); a=func_021B8008(q); b=func_021B8004(q); func_0201F02C((struct WordSet *)a,0,x+12); e=func_02045EC0(b,c); func_0201F250(a,((struct Obj02159 *)p)->fC,e); func_02045808(e); b=func_021B8000(q); d=func_021B7FFC(q); func_0201C6EC(b); func_0201C6FC(b,(int)func_02045770((struct Descriptor *)((struct Obj02159 *)p)->f4),y,z,((struct Obj02159 *)p)->fC,d); p[8]=1; }
