/*
 * file:     unit_021B7560_p03.c
 * unit:     yes
 * function: func_021B7D20, func_021B7D90, func_021B7DAC, func_021B7DE4, func_021B7E48, func_021B7EEC, func_021B7F78, func_021B8008, func_021B80BC, func_021B80CC, func_021B80D8
 * address:  0x021B7D20
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B7CA8 0x021B7CA8 thumb ov105
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_021B7CAC 0x021B7CAC thumb ov105
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201EF6C 0x0201EF6C thumb
 *   func_021B80E8 0x021B80E8 thumb ov105
 */
#include "../../matched/include/Obj03235.h"
#include "../../matched/include/Obj13752.h"
#include "../../matched/include/Obj06374.h"
#include "../../matched/include/Obj22248.h"
#include "../../matched/include/Obj05277.h"
#include "../../matched/include/Obj02813.h"
#include "../../matched/include/Obj05278.h"
#include "../../matched/include/Obj05279.h"
#include "../../matched/include/Obj13753.h"
#include "../../matched/include/Obj22249.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct PrintSys;
struct MsgBank;
struct StrObj;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct { void *descriptor,*window; u8 active,pad[3]; void *buffer; u16 color; } Window;

extern void func_02082BCC(void *,int,int);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_02045808(struct U16Vec *);
extern void func_020452E8(struct Descriptor *);
extern unsigned int func_0201C6C4(struct PrintSys *,void *);
extern int func_021B7CA0(void *);
extern int func_021B7CA4(void *);
extern int func_021B7CA8(void *);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern unsigned func_0201D42C(void *,int);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int func_021B7CAC(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void func_021B80E8(u8 *,u16 *);
void func_021B7D20(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size);
void func_021B7D90(unsigned char *p);
int func_021B7DAC(unsigned char *p,unsigned char *q);
void func_021B7DE4(u8 *p,void *a,int b,int x,s16 y);
void func_021B7E48(u8 *p,void *a,int b);
void func_021B7EEC(u8 *p, void *a, u8 b, u16 c, u16 d);
void func_021B7F78(u8 *p, void *a, int b, u8 *c, u8 *d, int a5);
void func_021B8008(Window *p, void *a, u8 *b, unsigned c, int d);
void func_021B80BC(unsigned char *p, unsigned int v);
void func_021B80CC(unsigned char *p);
void func_021B80D8(u8 *p);

void func_021B7D20(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size) {
 void *q;
 func_02082BCC(p,0,0x14); ((struct Obj03235 *)p)->f10=color;
 ((struct Obj03235 *)p)->f0=(void *)func_020450F0(a,b,c,d,e,f,heap);
 ((struct Obj03235 *)p)->fC=func_020457B0(0xff,size);
 ((struct Obj03235 *)p)->f4=((struct Obj03235 *)p)->f0; p[8]=0;
 func_02043B5C(func_02045770(((struct Obj03235 *)p)->f0),((struct Obj03235 *)p)->f10);
 q=((struct Obj03235 *)p)->f0; func_02045334(q); func_02045374(q); func_020409B4(func_02045730(q));
}

void func_021B7D90(unsigned char *p) { func_02045808(*(struct U16Vec * *)&((struct Obj13752 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13752 *)p)->f0); func_02082BCC(p,0,20); }

int func_021B7DAC(unsigned char *p,unsigned char *q) { struct PrintSys *s; s=*(struct PrintSys * *)&((struct Obj22248 *)q)->f8; if(p[8]) { if(!func_0201C6C4(s,func_02045770(*(struct Descriptor * *)&((struct Obj06374 *)p)->f4))) { func_02045334(*(struct Descriptor * *)&((struct Obj06374 *)p)->f4); p[8]=0; } } if(!p[8]) return 1; return 0; }

void func_021B7DE4(u8 *p,void *a,int b,int x,s16 y) {
 int bank; int font; int tag;
 bank=func_021B7CA8(a); font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_02043B5C(func_02045770(((struct Obj05277 *)p)->f0),((struct Obj05277 *)p)->f10);
 func_02045CAC((struct MsgBank *)bank,b,((struct Obj05277 *)p)->fC);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05277 *)p)->f4),(s16)x,y,((struct Obj05277 *)p)->fC,tag); p[8]=1;
}

void func_021B7E48(u8 *p,void *a,int b)
{
 int bank; int font; int tag; u16 x,y;
 bank=func_021B7CA8(a); font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_02043B5C(func_02045770(((struct Obj02813 *)p)->f0),((struct Obj02813 *)p)->f10);
 func_02045CAC((struct MsgBank *)bank,b,((struct Obj02813 *)p)->fC);
 x=func_02045738(((struct Obj02813 *)p)->f0)*4; y=func_02045740(((struct Obj02813 *)p)->f0)*4;
 x-= (u16)(func_0201D304(((struct Obj02813 *)p)->fC,tag,0)/2);
 y-= (u16)(func_0201D42C(((struct Obj02813 *)p)->fC,tag)/2);
 func_0201C724((void *)font,(u32)func_02045770(((struct Obj02813 *)p)->f4),(s16)x,(s16)y,(u32)(((struct Obj02813 *)p)->fC),tag,15812);
 p[8]=1;
}

void func_021B7EEC(u8 *p, void *a, u8 b, u16 c, u16 d)
{
 void *msg; int bank; void *text; int font; int tag;
 func_02043B5C(func_02045770(((struct Obj05278 *)p)->f0),((struct Obj05278 *)p)->f10);
 msg=(void *)func_021B7CAC(a); bank=func_021B7CA8(a);
 func_0201EFA4(msg,d,c,3,0,1);
 text=func_02045EC0((struct MsgBank *)bank,b);
 func_0201F250(msg,((struct Obj05278 *)p)->fC,text); func_02045808(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05278 *)p)->f4),0,0,((struct Obj05278 *)p)->fC,tag);
 p[8]=1;
}

void func_021B7F78(u8 *p, void *a, int b, u8 *c, u8 *d, int a5)
{
 void *msg; int bank; void *text; int font; int tag;
 func_02043B5C(func_02045770(((struct Obj05279 *)p)->f0),((struct Obj05279 *)p)->f10);
 msg=(void *)func_021B7CAC(a); bank=func_021B7CA8(a);
 func_0201F02C(msg,0,d+12); func_0201F02C(msg,1,c+12);
 text=func_02045EC0((struct MsgBank *)bank,b);
 func_0201F250(msg,((struct Obj05279 *)p)->fC,text); func_02045808(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05279 *)p)->f4),0,0,((struct Obj05279 *)p)->fC,tag);
 p[8]=1;
}

void func_021B8008(Window *p, void *a, u8 *b, unsigned c, int d)
{
 void *msg; int bank; void *text; int font; int tag; int flag;
 func_02043B5C(func_02045770(p->descriptor),p->color);
 msg=(void *)func_021B7CAC(a);
 bank=func_021B7CA8(a);
 b+=12; func_0201F02C(msg,0,b); flag=0;
 if(c>1) flag=1;
 func_0201EF6C(msg,1,134,flag,0); func_0201EFA4(msg,2,c,1,0,1);
 text=func_02045EC0((void *)bank,d);
 func_0201F250(msg,p->buffer,text); func_02045808(text);
 font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(p->window),0,0,p->buffer,tag);
 p->active=1;
}


void func_021B80BC(unsigned char *p, unsigned int v) { ((struct Obj13753 *)p)->f18C=v; ((struct Obj13753 *)p)->f190=0; }


void func_021B80CC(unsigned char *p) { ((struct Obj22249 *)p)->f194=1; }

void func_021B80D8(u8 *p)
{
    func_021B80BC(p,(unsigned int)func_021B80E8);
}
