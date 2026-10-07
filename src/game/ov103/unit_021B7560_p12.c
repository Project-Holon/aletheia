/*
 * file:     unit_021B7560_p12.c
 * unit:     yes
 * function: func_021B8BC0, func_021B8BD8, func_021B8BFC, func_021B8C14, func_021B8C40, func_021B8C4C, func_021B8CA0, func_021B8CB0, func_021B8D54
 * address:  0x021B8BC0
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
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B7D4C 0x021B7D4C thumb ov103
 *   func_021B7F60 0x021B7F60 thumb ov103
 *   func_021B7F04 0x021B7F04 thumb ov103
 *   func_021B7F78 0x021B7F78 thumb ov103
 *   func_021B7F4C 0x021B7F4C thumb ov103
 *   func_020061E4 0x020061E4 thumb
 *   func_0206E0C4 0x0206E0C4 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_021B7F50 0x021B7F50 thumb ov103
 *   func_02035D20 0x02035D20 arm
 */
#include "../../matched/include/Obj22211.h"
#include "../../matched/include/Obj04430.h"

struct Entry;
struct V3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 words[54];} Copy;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef struct {int x,y,z;} Vec;

extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
extern void func_02082BCC(void *,int,int);
extern u8 *func_021B7D4C(u8 *,u16);
extern void func_021B7F60(u8 *,int);
extern void func_021B7F04(u8 *);
extern unsigned int func_021B7F78(u8 *);
extern unsigned int func_021B7F4C(u8 *);
extern void func_020061E4(u32 a);
extern void func_0206E0C4(int,int,Vec *,Vec *);
extern void func_0207CA00(Vec *,Vec *,Vec *);
extern void func_0207CCA4(Vec *,Vec *);
extern void func_0207CEE4(int,Vec *,Vec *,Vec *);
extern void func_021B7F50(char *p, struct V3 *q);
extern u32 func_02035D20(u32 *outA, u32 *outB);
void func_021B8BC0(u8 *p,Copy *q);
void func_021B8BD8(u32 a, u32 b, u32 c, u8 *p, struct Entry *e);
u8 *func_021B8BFC(u32 a,u8 *p);
void func_021B8C14(u8 **p,u8 *q);
void func_021B8C40(void *p);
void func_021B8C4C(u8 **p);
void func_021B8CA0(u8 **p,int i,int v);
void func_021B8CB0(u8 *p,int i,int x,int y);
int func_021B8D54(u32 *p,u32 *out);

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void func_021B8BC0(u8 *p,Copy *q) {*q=*(Copy *)(p+8);}

/*
 * extent: two zero alignment bytes follow compiled code.
 */
void func_021B8BD8(u32 a, u32 b, u32 c, u8 *p, struct Entry *e) { if(e == func_020399A8()) { if(a != func_02039338()) ((struct Obj22211 *)p)->f290=1; } }

u8 *func_021B8BFC(u32 a,u8 *p) { if(a == func_02039338()) p += 0xe0; else p += 8; return p; }

void func_021B8C14(u8 **p,u8 *q) { int i; func_02082BCC(p,0,16); for(i=0;i<2;i++) { p[i]=func_021B7D4C(q,i); func_021B7F60(p[i],0); } }

void func_021B8C40(void *p) { func_02082BCC(p, 0, 0x10); }

void func_021B8C4C(u8 **p) {
 int i;
 for(i=0;i<2;i++)func_021B7F04(p[i]);
 if(func_021B7F78(p[0]) && func_021B7F4C(p[0]))func_020061E4(0x651);
 if(func_021B7F78(p[1]) && func_021B7F4C(p[1]))func_020061E4(0x656);
}

void func_021B8CA0(u8 **p,int i,int v) { func_021B7F60(p[i],v); }

void func_021B8CB0(u8 *p,int i,int x,int y) {
 Vec a,b,c;
 switch(i) {
 case 0:
  func_0206E0C4(x,y,&a,&b);func_0207CA00(&b,&a,&c);func_0207CCA4(&c,&c);func_0207CEE4(0x40000,&c,&a,&a);func_021B7F50(*(void **)(p+i*4),(struct V3 *)(&a));((struct Obj04430 *)p)->f8=x;((struct Obj04430 *)p)->fC=y;break;
 case 1:
  func_0206E0C4(((struct Obj04430 *)p)->f8+(x-((struct Obj04430 *)p)->f8)*2,((struct Obj04430 *)p)->fC+(y-((struct Obj04430 *)p)->fC)*2,&a,&b);func_0207CA00(&b,&a,&c);func_0207CCA4(&c,&c);func_0207CEE4(0x40000,&c,&a,&a);func_021B7F50(*(void **)(p+i*4),(struct V3 *)(&a));break;
 }
}

int func_021B8D54(u32 *p,u32 *out) {
 u32 x,y;
 if(func_02035D20(&x,&y)) {
  if(x-p[0]<p[2]-p[0] && y-p[1]<p[3]-p[1]) {
   if(out) {out[0]=x;out[1]=y;}
   return 1;
  }
 }
 return 0;
}
