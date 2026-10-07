/*
 * file:     unit_021B7560_p05.c
 * unit:     yes
 * function: func_021B7D24, func_021B7D28, func_021B7DAC, func_021B7DD4, func_021B7DE0, func_021B7DE4, func_021B7DE8, func_021B7DEC, func_021B7DF0, func_021B7E58, func_021B7EC8, func_021B7EE4, func_021B7F1C, func_021B7F80, func_021B7F90, func_021B8030, func_021B80B8, func_021B80D4, func_021B80F8, func_021B8104
 * address:  0x021B7D24
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
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B7968 0x021B7968 thumb ov104
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../../matched/include/Obj07988.h"
#include "../../matched/include/Obj22219.h"
#include "../../matched/include/Obj22220.h"
#include "../../matched/include/Obj22221.h"
#include "../../matched/include/Obj22222.h"
#include "../../matched/include/Obj22223.h"
#include "../../matched/include/Obj03233.h"
#include "../../matched/include/Obj13743.h"
#include "../../matched/include/Obj06372.h"
#include "../../matched/include/Obj22224.h"
#include "../../matched/include/Obj05273.h"
#include "../../matched/include/Obj02812.h"
#include "../../matched/include/Obj05274.h"
#include "../../matched/include/Obj10245.h"

struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct PrintSys;
struct Cfg;
struct Descriptor;
struct U16Vec;
struct CharBuf;
struct StrObj;
struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef struct {
    void *f0;
    void *f4;
    u8 f8;
    u8 pad_9[3];
    void *fC;
    u16 f10;
} Rec;

extern void func_02082BCC(void *,int,unsigned);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045808(struct U16Vec *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_021B7968(u8 *,int);
extern void func_020061E4(u32 a);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
u32 func_021B7D24(u32 *p);
void func_021B7D28(unsigned *p, int mode, u16 heap);
void func_021B7DAC(u8 *p);
int func_021B7DD4(u8 *p);
int func_021B7DE0(void *p);
int func_021B7DE4(void *p);
int func_021B7DE8(void *p);
int func_021B7DEC(void *p);
void func_021B7DF0(Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 size);
void func_021B7E58(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size);
void func_021B7EC8(u8 *p);
int func_021B7EE4(u8 *p,u8 *q);
void func_021B7F1C(u8 *p,void *a,int b,int x,s16 y);
void func_021B7F80(u8 *p,void *a,int b);
void func_021B7F90(u8 *p,void *a,int b,u16 c);
void func_021B8030(u8 *p, void *a, int b, u8 *c, s16 x, s16 y, u16 a6);
void func_021B80B8(u8 *p);
void func_021B80D4(int *p, u8 *q, int a2);
void func_021B80F8(void *p);
void func_021B8104(u32 *p);


/*
 * First-word accessor.
 */
u32 func_021B7D24(u32 *p)
{
    return *p;
}

/*
 * func_02082BCC 0x02082BCC arm
 * func_0201DD60 0x0201DD60 thumb
 * func_0201D7EC 0x0201D7EC thumb
 * func_0201C440 0x0201C440 thumb
 * func_02045B38 0x02045B38 arm
 * func_0201EC64 0x0201EC64 thumb
 * func_02049B40 0x02049B40 arm
 */
void func_021B7D28(unsigned *p, int mode, u16 heap) {
 func_02082BCC(p,0,0x10);
 func_0201DD60();
 switch (mode) {
 case 0:
  p[0]=(unsigned int)func_0201D7EC(0x17,0,0,0,heap);
  break;
 case 1:
  p[0]=(unsigned int)func_0201D7EC(0x17,1,0,0,heap);
  break;
 }
 p[2]=func_0201C440((void *)heap);
 p[1]=(unsigned int)func_02045B38(0,2,0x34,heap);
 p[3]=(unsigned int)func_0201EC64(heap);
 func_02049B40(0x17,5,4,0x1C0,0x20,heap);
 func_02049B40(0x17,5,0,0x1C0,0x20,heap);
}

void func_021B7DAC(u8 *p) { func_0201ED04(*(struct WordSet * *)&((struct Obj07988 *)p)->fC); func_02045C04(*(struct Rec * *)&((struct Obj07988 *)p)->f4); func_0201C4C0(((struct Obj07988 *)p)->f8); func_0201D83C(((struct Obj07988 *)p)->f0); func_02082BCC(p,0,16); }

int func_021B7DD4(u8 *p) { return func_0201C4E4((struct PrintSys *)(((struct Obj22219 *)p)->f8)); }


int func_021B7DE0(void *p)
{
    return ((struct Obj22220 *)p)->f0;
}


int func_021B7DE4(void *p)
{
    return ((struct Obj22221 *)p)->f8;
}


/*
 * four int getters at +0, +8, +4, +c.
 */
int func_021B7DE8(void *p)
{
    return ((struct Obj22222 *)p)->f4;
}


int func_021B7DEC(void *p)
{
    return ((struct Obj22223 *)p)->fC;
}

void func_021B7DF0(Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 size)
{
    void *q;
    func_02082BCC(p, 0, 0x14);
    p->f10 = 15;
    p->f0 = (void *)func_020450F0(a, b, c, d, e, f, 1);
    p->fC = func_020457B0(0xff, size);
    p->f4 = p->f0;
    p->f8 = 0;
    func_021B80B8((u8 *)p);
    q = p->f0;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}

/*
 * lever: c and its callee parameter are u8; u32 hoists its spill reload.
 */
void func_021B7E58(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size) { void *q; func_02082BCC(p,0,0x14); ((struct Obj03233 *)p)->f10=color; ((struct Obj03233 *)p)->f0=(void *)func_020450F0(a,b,c,d,e,f,heap); ((struct Obj03233 *)p)->fC=func_020457B0(0xff,size); ((struct Obj03233 *)p)->f4=((struct Obj03233 *)p)->f0; p[8]=0; func_02043B5C(func_02045770(((struct Obj03233 *)p)->f0),((struct Obj03233 *)p)->f10); q=((struct Obj03233 *)p)->f0; func_02045334(q); func_02045374(q); func_020409B4(func_02045730(q)); }

void func_021B7EC8(u8 *p) { func_02045808(*(struct U16Vec * *)&((struct Obj13743 *)p)->fC); func_020452E8(*(struct Descriptor * *)&((struct Obj13743 *)p)->f0); func_02082BCC(p,0,20); }

int func_021B7EE4(u8 *p,u8 *q) { void *v; v=((struct Obj22224 *)q)->f8; if(p[8]) { if(!func_0201C6C4(v,func_02045770(((struct Obj06372 *)p)->f4))) { func_02045334(*(struct Descriptor * *)&((struct Obj06372 *)p)->f4); p[8]=0; } } if(!p[8]) return 1; return 0; }

void func_021B7F1C(u8 *p,void *a,int b,int x,s16 y) { int bank; int font; int tag; bank=func_021B7DE8(a); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_02043B5C(func_02045770(((struct Obj05273 *)p)->f0),((struct Obj05273 *)p)->f10); func_02045CAC((struct MsgBank *)bank,b,((struct Obj05273 *)p)->fC); func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05273 *)p)->f4),(s16)x,y,((struct Obj05273 *)p)->fC,tag); p[8]=1; }

void func_021B7F80(u8 *p,void *a,int b) { func_021B7F90(p,a,b,0x3dc4); }

void func_021B7F90(u8 *p,void *a,int b,u16 c) { int bank; int font; int tag; u16 x; u16 y; bank=func_021B7DE8(a); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_02043B5C(func_02045770(((struct Obj02812 *)p)->f0),((struct Obj02812 *)p)->f10); func_02045CAC((struct MsgBank *)bank,b,((struct Obj02812 *)p)->fC); x=func_02045738(((struct Obj02812 *)p)->f0)*4; y=func_02045740(((struct Obj02812 *)p)->f0)*4; x-=(u16)(func_0201D304(((struct Obj02812 *)p)->fC,tag,0)/2); y-=(u16)(func_0201D42C(((struct Obj02812 *)p)->fC,(void *)tag)/2); func_0201C724((void *)font,(u32)func_02045770(((struct Obj02812 *)p)->f4),(s16)x,(s16)y,(u32)(((struct Obj02812 *)p)->fC),tag,c); p[8]=1; }

void func_021B8030(u8 *p, void *a, int b, u8 *c, s16 x, s16 y, u16 a6) { int set; int bank; void *text; int font; int tag; func_02043B5C(func_02045770(((struct Obj05274 *)p)->f0),((struct Obj05274 *)p)->f10); set=func_021B7DEC(a); bank=func_021B7DE8(a); func_0201F02C((struct WordSet *)set,0,c+0xc); text=func_02045EC0((struct MsgBank *)bank,b); func_0201F250((struct WordSet *)set,((struct Obj05274 *)p)->fC,text); func_02045808(text); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_0201C6FC((struct PrintSys *)font,(u32)func_02045770(((struct Obj05274 *)p)->f4),x,y,((struct Obj05274 *)p)->fC,tag); p[8]=1; }

void func_021B80B8(u8 *p) { func_02043B5C(func_02045770(((struct Obj10245 *)p)->f0),((struct Obj10245 *)p)->f10); func_02045334(((struct Obj10245 *)p)->f0); }

void func_021B80D4(int *p, u8 *q, int a2) { int i; func_02082BCC(p,0,0x1c); for(i=0;i<3;i++) *p=func_021B7968(q,i+0x1f); }

void func_021B80F8(void *p) { func_02082BCC(p, 0, 0x1c); }

void func_021B8104(u32 *p) { if(p[5]) { if(p[3]==0) { func_020061E4(0x66a); func_0204B3DC((void *)p[0],1); func_0204B878((void *)p[0],4-p[4]); } if(p[3]++>=60) { p[3]=0; p[4]++; } if(p[4]==3) { func_020061E4(0x66b); p[6]=1; p[5]=0; func_0204B3DC((void *)p[0],0); } } }
