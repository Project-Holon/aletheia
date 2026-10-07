/*
 * file:     unit_021B7560_p02.c
 * unit:     yes
 * function: func_021B7A80, func_021B7A88, func_021B7BC0, func_021B7C04, func_021B7C0C, func_021B7C14, func_021B7C1C, func_021B7C20, func_021B7C6C, func_021B7C94, func_021B7CA0, func_021B7CA4, func_021B7CA8, func_021B7CAC, func_021B7CB0
 * address:  0x021B7A80
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
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   d_020A1448 0x020A1448 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj07989.h"
#include "../../matched/include/Obj22243.h"
#include "../../matched/include/Obj22244.h"
#include "../../matched/include/Obj22245.h"
#include "../../matched/include/Obj22246.h"
#include "../../matched/include/Obj22247.h"

struct Cfg;
struct Bank;
struct Node;
struct Obj;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct PrintSys;
struct CharBuf;
struct Descriptor;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021B7A80;

typedef signed int     s32_021B7A88;

typedef int s32_021B7C94;

struct Rec { u32 f0; u32 f4; u8 f8; u8 pad9[3]; u32 fC; u16 f10; };

extern void func_020419E4(void);
extern void func_02082BCC(void *,int,int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_0204ABF0(void *,int,int,int,int);
extern void *func_0204A6C8(void *,int,int,int,int);
extern s32_021B7A88 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void *func_0204B294(void *,void *,void *,void *,void *,int,int);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(void *,int);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201ED04(struct WordSet *);
extern void func_02045C04(struct Rec *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201D83C(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
void func_021B7A80(void *a0);
void func_021B7A88(void **p,const void *config,int heap);
void func_021B7BC0(void **p);
void func_021B7C04(void *a0);
void func_021B7C0C(void);
u32 func_021B7C14(u8 *p, int i);
u32 func_021B7C1C(u32 *p);
void func_021B7C20(u32 *p, int flag, int heap);
void func_021B7C6C(unsigned char *p);
u32 func_021B7C94(u8 *p);
int func_021B7CA0(void *p);
int func_021B7CA4(void *p);
int func_021B7CA8(void *p);
int func_021B7CAC(void *p);
void func_021B7CB0(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g);
extern const u8 d_020A1448[];

void func_021B7A80(void *a0) { func_020419E4(); }

/*
 * lever: later pos2 declaration reproduces its lower stack slot.
 */
void func_021B7A88(void **p,const void *config,int heap)
{
    u16 pos[4],pos2[4];
    void *archive;
    int i;
    func_02082BCC(p,0,0xa8);
    func_0204A48C((const struct Cfg *)d_020A1448,(unsigned int)config,heap);
    p[0]=func_0204B100(128,0,heap);
    func_0204B270(p[0]);
    func_020434DC(16,1); func_02043598(16,1);
    archive=func_020490F4(0x5e,heap);
    p[1]=func_0204ABF0(archive,12,0,0,heap);
    p[2]=func_0204A6C8(archive,11,0,0,heap);
    p[3]=(void *)func_0204AF28(archive,10,9,heap);
    func_02049238(archive);
    func_02082BCC(pos,0,8);
    for(i=0;i<3;++i) p[4+i]=func_0204B294(p[0],p[2],p[1],p[3],pos,0,heap);
    func_02082BCC(pos2,0,8);
    pos2[0]=128; pos2[1]=96;
    p[41]=func_0204B294(p[0],p[2],p[1],p[3],pos2,0,heap);
    func_0204B3DC(p[41],0); func_0204B84C(p[41],0); func_0204B800(p[41],0);
    func_0204B92C(p[41],1); func_0204B878(p[41],11);
    for(i=0;i<3;++i) {
        func_0204B3DC(p[4+i],0); func_0204B84C(p[4+i],0); func_0204B800(p[4+i],0);
    }
}

void func_021B7BC0(void **p) {
 int i;
 for(i=0;i<38;i++) if(p[i+4]) func_0204B3B4(p[i+4]);
 func_0204ADA4((u32)p[1]); func_0204A8D4((u32)p[2]); func_0204AFD8((u32)p[3]);
 func_0204B1CC(p[0]); func_0204A5AC(); func_02082BCC(p,0,0xa8);
}

void func_021B7C04(void *a0) { func_0204A600(); }

void func_021B7C0C(void) { func_0204A648(); }


u32 func_021B7C14(u8 *p, int i)
{
    return *(u32 *)(p + i * 4 + 0x10);
}


u32 func_021B7C1C(u32 *p)
{
    return *p;
}

void func_021B7C20(u32 *p, int flag, int heap) {
 func_02082BCC(p, 0, 0x10);
 func_0201DD60();
 if (flag == 0) {
  p[0] = (u32)func_0201D7EC(0x17, 0, 0, 0, heap);
 }
 p[2] = func_0201C440((void *)heap);
 p[1] = (u32)func_02045B38(0, 2, 0x33, heap);
 p[3] = (u32)func_0201EC64(heap);
}

void func_021B7C6C(unsigned char *p) { func_0201ED04(*(struct WordSet * *)&((struct Obj07989 *)p)->fC); func_02045C04(*(struct Rec * *)&((struct Obj07989 *)p)->f4); func_0201C4C0(*(struct PrintSys * *)&((struct Obj07989 *)p)->f8); func_0201D83C(((struct Obj07989 *)p)->f0); func_02082BCC(p,0,16); }

u32 func_021B7C94(u8 *p) { return func_0201C4E4((struct PrintSys *)(((struct Obj22243 *)p)->f8)); }


/*
 * four int getters at +0, +8, +4, +c.
 */
int func_021B7CA0(void *p)
{
    return ((struct Obj22244 *)p)->f0;
}


int func_021B7CA4(void *p)
{
    return ((struct Obj22245 *)p)->f8;
}


int func_021B7CA8(void *p)
{
    return ((struct Obj22246 *)p)->f4;
}


int func_021B7CAC(void *p)
{
    return ((struct Obj22247 *)p)->fC;
}

void func_021B7CB0(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g)
{
    int q;
    func_02082BCC(p, 0, 20);
    p->f10 = 15;
    p->f0 = func_020450F0(a, b, c, d, e, f, 1);
    p->fC = (u32)func_020457B0(255, g);
    p->f4 = p->f0;
    p->f8 = 0;
    func_02043B5C(func_02045770((struct Descriptor *)p->f0), p->f10);
    q = p->f0;
    func_02045334((void *)q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730((struct Descriptor *)q));
}
