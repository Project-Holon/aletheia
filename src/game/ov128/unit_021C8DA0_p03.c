/*
 * file:     unit_021C8DA0_p03.c
 * unit:     yes
 * function: func_021C9154, func_021C9180, func_021C91CC, func_021C9238
 * address:  0x021C9154
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_02041300 0x02041300 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_021C9628 0x021C9628 thumb ov128
 */
#include "../../matched/include/Obj10489.h"
#include "../../matched/include/Obj00329.h"
#include "../../matched/include/Obj10490.h"
#include "../../matched/include/Obj14044.h"
#include "../../matched/include/Obj23102.h"
#include "../../matched/include/Obj23103.h"

struct Descriptor;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern void func_021CA444(char *);
extern void func_021CA458(char *p, void *q);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021C6ADC(u8 *p, u8 *q, unsigned v);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
extern void func_021C6B38(u8 *p);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_021C9628(void *,void *,void *,void *);
void func_021C9154(char *p,int unused,char *q);
void func_021C9180(char *p,char *q,char *r);
void func_021C91CC(char *p,void *q);
void func_021C9238(char *p,void *b,void *c,void *d);

void func_021C9154(char *p,int unused,char *q) { func_021CA444(q);func_021CA458(q,q+12);func_020452E8(((struct Obj10489 *)p)->f0);func_020452E8(((struct Obj10489 *)p)->f8);func_020307B0(((struct Obj10489 *)p)->f10);}

void func_021C9180(char *p,char *q,char *r) {
 char *s;
 func_0201F02C(((struct Obj00329 *)r)->f0,0,func_02012944(((struct Obj23102 *)q)->f4));
 func_021C6ADC((u8 *)r,(u8 *)(r+12),50);
 s=*(char * *)&((struct Obj10490 *)p)->f14;
 func_02041090(2,(u32)(s+12),0,0,(((struct Obj14044 *)s)->f0>>3)&255,(((struct Obj14044 *)s)->f2>>3)&255);
 func_02041B6C(2);
}

void func_021C91CC(char *p,void *q) {
 void *v;
 func_021C6B38(q);
 func_02041300(2,0,0,0,32,24,0);func_02041B6C(2);
 v=((struct Obj10490 *)p)->f0;func_020456F8(v);func_02041B6C(func_02045730(v));
 v=((struct Obj10490 *)p)->f8;func_020456F8(v);func_02041B6C(func_02045730(v));
 func_02041300(3,0,0,0,32,24,0);func_02041B6C(3);
}

void func_021C9238(char *p,void *b,void *c,void *d) { ((struct Obj23103 *)p)->f10=1; func_021C9628(p,b,c,d); }
