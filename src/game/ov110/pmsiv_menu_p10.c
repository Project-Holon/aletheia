/*
 * file:     pmsiv_menu_p10.c
 * unit:     yes
 * function: func_021BCF70, func_021BCF7C, func_021BCFBC, func_021BCFF0, func_021BD000, func_021BD028, func_021BD044, func_021BD0D4, func_021BD0F8, func_021BD114, func_021BD174, func_021BD194, func_021BD248, func_021BD264, func_021BD2F0, func_021BD344, func_021BD348, func_021BD448, func_021BD470, func_021BD484, func_021BD534, func_021BD578, func_021BD5A0, func_021BD5C4, func_021BD690, func_021BD6B4, func_021BD6F8, func_021BD740
 * address:  0x021BCF70
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCE48  0x021BCE48  thumb  ov110
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028230 0x02028230 thumb
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   d_021C38DF 0x021C38DF data a1
 *   d_021C38D9 0x021C38D9 data a1
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BAC40 0x021BAC40 thumb ov110
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027FEC 0x02027FEC thumb
 *   func_020282AC 0x020282AC thumb
 *   func_021BCD80 0x021BCD80 thumb ov110
 *   func_020409B4 0x020409B4 arm
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BABE8 0x021BABE8 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_0203D34C 0x0203D34C arm
 *   func_02030D28 0x02030D28 arm
 *   d_00000043 0x00000043 data a1
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_0203633C 0x0203633C arm
 *   func_02051C88 0x02051C88 arm
 *   func_021BD764 0x021BD764 thumb ov110
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   func_0203159C 0x0203159C arm
 *   func_02024144 0x02024144 thumb
 *   func_0202421C 0x0202421C thumb
 *   func_02024168 0x02024168 thumb
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_021B95A0 0x021B95A0 thumb ov110
 *   func_021B9A50 0x021B9A50 thumb ov110
 *   func_02051B84 0x02051B84 arm
 *   func_021BAEDC 0x021BAEDC thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF508 0x021BF508 thumb ov110
 *   d_021C3908 0x021C3908 data a1
 *   d_021C3C78 0x021C3C78 data a1
 *   func_0202452C 0x0202452C thumb
 *   func_02024584 0x02024584 thumb
 *   func_02024530 0x02024530 thumb
 *   func_02024598 0x02024598 thumb
 */
#include "../../matched/include/Obj08004.h"
#include "../../matched/include/Obj13786.h"
#include "../../matched/include/Obj01249.h"
#include "../../matched/include/Obj13787.h"
#include "../../matched/include/Obj02462.h"
#include "../../matched/include/Obj10279.h"
#include "../../matched/include/Obj22376.h"
#include "../../matched/include/Obj22377.h"
#include "../../matched/include/Obj22378.h"
#include "../../matched/include/Obj03242.h"
#include "../../matched/include/Obj05294.h"
#include "../../matched/include/Obj10281.h"
#include "../../matched/include/Obj05295.h"

#define F (*(int *)(p + 0xB8))
struct Obj;
struct MsgBank;
struct T;
struct Ctx;
struct Obj0203159C;
struct Input;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021BCF70;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021BCF70;

typedef short s16_021BD028;

typedef short s16_021BD044;

typedef struct { void *root; u8 pad[0x6c]; void *items[8]; } Object_021BD044;

typedef signed int     s32_021BD044;

typedef short s16_021BD0D4;

typedef short s16_021BD0F8;

typedef struct { void *root; u8 pad[0x8c]; void *items[2]; } Object_021BD114;

typedef short s16_021BD174;

typedef struct { u16 x,y,z; u8 a,b; } Params;

typedef signed int     s32_021BD194;

typedef short s16_021BD248;

typedef struct { void *s; u16 x,pad; int flag; } Record;

typedef struct { u8 pad[0x30]; void *bank; void *a[3]; Record records[3]; void *windows[3]; } Object_021BD264;

typedef short s16_021BD344;

typedef int s32_021BD344;

typedef signed short s16_021BD348;

typedef signed int     s32_021BD348;

typedef short s16_021BD448;

typedef short s16_021BD470;

typedef signed int     s32_021BD484;

typedef signed int     s32_021BD534;

typedef short s16_021BD5A0;

typedef short s16_021BD690;

typedef short s16_021BD6B4;

typedef struct { s16_021BD6B4 a; s8 b; s8 c; } State_021BD6B4;

typedef short s16_021BD6F8;

typedef struct { s16_021BD6F8 a; s8 b,c; } State_021BD6F8;

typedef short s16_021BD740;

extern void func_021BCE48(void *, int, int);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_0202822C(char *,int);
extern u32 func_02028230(u8 *);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021BAC64(void *,void *,int,int);
extern s32_021BD044 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32_021BD044 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void func_02049238(void *);
extern struct Obj *func_021BAC78(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern unsigned int func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32_021BD194 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_021BAC40(u8 *p);
extern struct Obj *func_0204B294(void *owner,u32 i,u32 j,u32 k,const void *position,u16 space,u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void func_020282AC(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4);
extern void func_021BCD80(u8 *p);
extern void func_020409B4(u32 index);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, unsigned int);
extern u32 func_020307B0(void *p);
extern s32_021BD348 func_02061CA4(void *p, u32 a, u32 b, s32_021BD348 size);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_02034AC4(s32_021BD484 handle);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void func_021B9BEC(u8 *p, int id);
extern int func_021B9C74(unsigned int a);
extern int func_021BABE8(u8 *p);
extern void func_021BD7A0(u8 *,int (*)(u8 *,void *));
extern int func_021BD894(u8 *,void *);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02030D28(struct Ctx *c);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern unsigned int func_0203633C(void);
extern s32_021BD534 func_02051C88(struct Ctx *c);
extern void func_021BD764(u8 *,void *);
extern void func_020306F0(u32);
extern void func_02034A5C(int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern u32 func_02024144(const u8 *);
extern u32 func_0202421C(void *);
extern void func_02024168(const struct Input *p, u16 *a, u16 *b);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32,struct Ctx *);
extern void *func_021B95A0(u32,void *);
extern void *func_021B9A50(u8 *,void *);
extern void *func_02051B84(u8 *,int,int,int);
extern u8 *func_021BAEDC(void *,void *,u16);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF508(u8 *p, int *q);
extern int func_0202452C(const u16 *p);
extern u8 func_02024584(u32 i);
extern unsigned int func_02024530(const u16 *p);
extern void func_02024598(void *, int, int);
void func_021BCF70(void *p, int i, int j);
void func_021BCF7C(u8 *p, int n, int v);
void func_021BCFBC(char *p,u32 index,int value);
u32 func_021BCFF0(char *p,u32 index);
int func_021BD000(char *p);
int func_021BD028(u8 *p);
void func_021BD044(Object_021BD044 *p);
void func_021BD0D4(u8 *p);
void func_021BD0F8(u8 *p,int i,int flag);
void func_021BD114(Object_021BD114 *p);
void func_021BD174(u8 *p);
void func_021BD194(u8 *p);
void func_021BD248(u8 *p);
void func_021BD264(Object_021BD264 *p);
void func_021BD2F0(u8 *p);
void func_021BD344(u8 *a0);
void func_021BD348(char *p);
void func_021BD448(u8 *p,int i);
void func_021BD470(u8 *p,int i);
int func_021BD484(void *a,int *state,int c,void *p);
int func_021BD534(void *a,int b,int c,u8 *p);
void func_021BD578(int value,unsigned int which,u8 *p);
int func_021BD5A0(void *a,int b,int c,u8 *p);
u8 *func_021BD5C4(struct Obj0203159C *owner,u8 *input);
void func_021BD690(u8 *p, u16 *out);
void func_021BD6B4(State_021BD6B4 *p, void *out);
void func_021BD6F8(State_021BD6F8 *p,void *out);
void func_021BD740(u8 *p,void *out,int v);
extern const u8 d_021C38DF[];
extern const u8 d_021C38D9[];
extern s16_021BD348 tbl_020A1B38[];
extern const u8 d_00000043[];
extern char ov067_id[];
extern const u8 d_021C3908[];
extern const char d_021C3C78[];

void func_021BCF70(void *p, int i, int j) { if (i == 1) { func_021BCE48(p, i, j); } }

/*
 * extent: two zero padding bytes at 0x021BCFBA.
 */
void func_021BCF7C(u8 *p, int n, int v) {
    int i;
    void **a = (void **)(p + 0x64);
    if (a[n]) {
        for (i = 0; i < 3; i++) {
            if (*(void **)(p + 0x64 + i * 4)) func_02028218(*(void **)(p + 0x64 + i * 4), 0);
        }
        func_02028218(a[n], v);
    }
}

void func_021BCFBC(char *p,u32 index,int value) { int i; for(i=0;i<3;i++) { if (*(void **)((u32)p+(u32)i*4+0x64)) func_02028218(*(void **)((u32)p+(u32)i*4+0x64),0); } if (*(void **)((u32)p+index*4+0x64)) func_0202822C(*(char **)((u32)p+index*4+0x64),value); }

u32 func_021BCFF0(char *p,u32 index) { return func_02028230(*(u8 **)((u32)p+index*4+0x64)); }

/*
 * Extent ends in two-byte alignment padding at 0x021BD026.
 */
int func_021BD000(char *p) { if (func_0204B3F4(((struct Obj08004 *)p)->f28) && ((struct Obj08004 *)p)->f2C==0) { func_0204B878(((struct Obj08004 *)p)->f28,9); ((struct Obj08004 *)p)->f2C=1; return 1; } return 0; }

int func_021BD028(u8 *p)
{
    if(func_0204B3F4(((struct Obj13786 *)p)->f28) && ((struct Obj13786 *)p)->f2C!=3) return 0;
    return 1;
}

void func_021BD044(Object_021BD044 *p) {
    void *h;
    int i;
    s16_021BD044 x;
    h=func_020490F4(43,42);
    func_021BAC64(p->root,(u8 *)p+0x10,0,0);
    ((struct Obj01249 *)p)->f14=(void *)func_0204A6C8(h,13,0,0,42);
    ((struct Obj01249 *)p)->f18=(void *)func_0204AF28(h,35,41,42);
    func_02049238(h);
    for(i=0;i<8;i++) {
        x=24*i;
        if(i==7) x=0;
        p->items[i]=func_021BAC78(p->root,(unsigned int *)((u8 *)p+0x10),x,168,0,1);
        func_021BD0F8((u8 *)p,i,0);
        func_0204B3DC(p->items[i],0);
    }
}

void func_021BD0D4(u8 *p)
{
    int i;
    for(i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x70));
    func_0204A8D4(((struct Obj13787 *)p)->f14);
    func_0204AFD8(((struct Obj13787 *)p)->f18);
}

/*
 * lever: integer table-base arithmetic forms table+i*2 before adding flag;
 * d_021C38DF[i*2+flag] combined the two indices first (11 concrete bytes differed).
 */
void func_021BD0F8(u8 *p,int i,int flag)
{
    func_0204B878(*(void **)(p+i*4+0x70),*(u8 *)((u32)d_021C38DF+i*2+flag));
}

void func_021BD114(Object_021BD114 *p) {
    u8 i;
    for(i=0;i<2;i++) {
        p->items[i]=func_021BAC78(p->root,(unsigned int *)((u8 *)p+0x10),d_021C38D9[3*i],d_021C38D9[3*i+1],0,1);
        func_0204B878(p->items[i],d_021C38D9[3*i+2]);
        func_0204B3DC(p->items[i],0);
    }
}

void func_021BD174(u8 *p)
{
    u8 i;
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x90));
}

void func_021BD194(u8 *p) {
    void *h;
    int a;
    Params t;
    h=func_020490F4(func_020275E4(),42);
    ((struct Obj02462 *)p)->f1C=(void *)func_0204AC18(h,func_02027614(),0,384,0,3,42);
    ((struct Obj02462 *)p)->f20=(void *)func_0204A6C8(h,func_02027618(),0,0,42);
    a=func_0202761C(1);
    ((struct Obj02462 *)p)->f24=(void *)func_0204AF28(h,a,func_02027620(1),42);
    func_02049238(h);
    func_02082BCC(&t,0,8);
    t.x=232; t.y=168; t.z=1; t.a=0; t.b=3;
    ((struct Obj02462 *)p)->f28=func_0204B294((void *)func_021BAC40(((struct Obj02462 *)p)->f0),(u32)((struct Obj02462 *)p)->f20,(u32)((struct Obj02462 *)p)->f1C,(u32)((struct Obj02462 *)p)->f24,&t,0,42);
    func_0204B92C(((struct Obj02462 *)p)->f28,1);
    func_0204B3DC(((struct Obj02462 *)p)->f28,0);
    ((struct Obj02462 *)p)->f2C=0;
}

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void func_021BD248(u8 *p)
{
    func_0204B3DC(((struct Obj10279 *)p)->f28,1);
    func_0204B878(((struct Obj10279 *)p)->f28,1);
    ((struct Obj10279 *)p)->f2C=0;
}

void func_021BD264(Object_021BD264 *p) {
    int i;
    for(i=0;i<3;i++) {
        p->records[i].s=func_02045EC0(p->bank,i+18);
        p->records[i].x=0x39e3;
        p->records[i].flag=i==2;
        p->windows[i]=(void *)func_02027FEC((u32)p->a[i],(u32)(&p->records[i]),(u8)(5+9*i),(int)21,9,42);
        func_020282AC(p->windows[i],p->a[i],8,0x3545,0x7b2c);
    }
    func_021BCD80((u8 *)p);
    func_020409B4(0);
}

/*
 * extent: two zero padding bytes at 0x021BD342.
 */
void func_021BD2F0(u8 *p) {
    void *obj;
    void *handle;
    u8 *data;
    handle = func_02049F34(43, 7, (u32)(&obj), 42);
    data = *(u8 * *)&((struct Obj22377 *)obj)->fC;
    func_02082D44(data + 0x96, p + 0x98, 10);
    func_02082D44(data + 0x76, p + 0xa2, 10);
    func_020307B0(handle);
    func_02082D44(p + 0x98, p + 0xac, 10);
    ((struct Obj22376 *)p)->fB8 = 0;
}


void func_021BD344(u8 *a0) { }

static inline void lerp(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}

/*
 * lever: the RGB555 lerp is a static inline helper (u16 colour params, as ov105 func_021B8734)
 */
void func_021BD348(char *p)
{
    int j;
    s16_021BD348 t;
    u8 i;
    if (F + 0x400 >= 0x10000)
        F = F - 0xFC00;
    else
        F = F + 0x400;
    j = F >> 4;
    t = (tbl_020A1B38[j * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        lerp((u16 *)(p + i * 2 + 0xAC), t, *(u16 *)(p + i * 2 + 0x98), *(u16 *)(p + i * 2 + 0xA2));
    }
    func_02061CA4((void *)14, 0x56, (u32)(p + 0xAC), 10);
}

void func_021BD448(u8 *p,int i)
{
    func_0204B6F4(*(void **)(p+i*4+0x70),2,1);
    func_02082D44(p+0x98,p+0xac,10);
    ((struct Obj22378 *)p)->fB8=0;
}

void func_021BD470(u8 *p,int i)
{
    func_0204B6F4(*(void **)(p+i*4+0x70),6,1);
}

int func_021BD484(void *a,int *state,int c,void *p) {
    u8 *obj;
    switch(*state) {
    case 0:
        func_02034AC4((int)d_00000043);
        func_0203064C(1,41,0x18000);
        func_0203064C(1,42,0x32000);
        obj=func_021BD5C4(a,(u8 *)c);
        func_021B9BEC(((struct Obj03242 *)obj)->f14,0);
        ++*state;
        break;
    case 1:
        obj=p;
        if(func_021B9C74((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            if(((struct Obj03242 *)obj)->f4==2) obj[0x68]=func_021BABE8(((struct Obj03242 *)obj)->f14);
            else obj[0x68]=0;
            func_021B9BEC(((struct Obj03242 *)obj)->f14,4);
            ++*state;
        }
        break;
    case 2:
        obj=p;
        if(func_021B9C74((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            func_021BD7A0(obj,func_021BD894);
            func_0203D34C(1,42);
            return 1;
        }
        break;
    }
    func_02030D28(((struct Obj03242 *)obj)->f7C);
    return 0;
}

/*
 * extent: unlabelled substantial switch leaf at 0x021BD578, excluded.
 */
int func_021BD534(void *a,int b,int c,u8 *p) {
    int result;
    int x;
    x=func_020362DC(); ((struct Obj05294 *)p)->f34=x;
    x=func_0203630C(); ((struct Obj05294 *)p)->f36=x;
    x=func_0203633C(); ((struct Obj05294 *)p)->f38=x;
    func_02051C88(((struct Obj05294 *)p)->f44);
    if (*(void (**)(u8 *,void *))(p+0x30)) {
        (*(void (**)(u8 *,void *))(p+0x30))(p,p+0x2c);
        result=0;
    } else result=(*(int (**)(u8 *,void *))(p+0x24))(p,p+0x20);
    func_02030D28(((struct Obj05294 *)p)->f7C);
    return result;
}

/*
 * extent: independent switch leaf following func_021BD534; all registers
 * are incoming arguments; each arm returns through bx lr.
 */
void func_021BD578(int value,unsigned int which,u8 *p) {
    switch(which) {
    case 0: ((struct Obj10281 *)p)->f3C=value; break;
    case 1:
    case 3: ((struct Obj10281 *)p)->f3C=1; break;
    case 2: break;
    default: ((struct Obj10281 *)p)->f3C=1; break;
    }
}

int func_021BD5A0(void *a,int b,int c,u8 *p)
{
    func_021BD764(p,a);
    func_020306F0(41);
    func_020306F0(42);
    func_02034A5C((int)ov067_id);
    return 1;
}

u8 *func_021BD5C4(struct Obj0203159C *owner,u8 *input)
{
    u8 *p;
    struct Ctx *q;
    p=func_0203159C(owner,128,41);
    *(u8 **)p=input;
    *(u32 *)(p+4)=func_02024144(input);
    *(u32 *)(p+0x70)=func_0202421C(*(u8 **)p);
    func_02024168((const struct Input *)(*(u8 **)p),(u16 *)(p+0x10),(u16 *)(p+8));
    if(*(u32 *)(p+4)==2) func_021BD690(p+0x64,(u16 *)(p+8));
    q=func_02030734(41,func_02030CB0(5),0,d_021C3C78,579);
    *(struct Ctx **)(p+0x78)=q;
    *(struct Ctx **)(p+0x7c)=func_02030CBC(5,q);
    *(void **)(p+0x18)=func_021B95A0(41,*(void **)p);
    *(void **)(p+0x14)=func_021B9A50(p,*(void **)(p+0x18));
    *(void **)(p+0x44)=func_02051B84((u8 *)d_021C3908,(int)func_021BD578,(int)p,41);
    p[0x69]=0;
    *(u32 *)(p+0x30)=0;
    *(u32 *)(p+0x2c)=0;
    *(u16 *)(p+0x4a)=0;
    *(u16 *)(p+0x48)=0;
    *(u32 *)(p+0x3c)=1;
    *(void **)(p+0x1c)=func_021BAEDC(p,*(void **)(p+0x18),41);
    func_021BF4F8(p,(u32)func_021BF508);
    return p;
}

/*
 * No witness outside this caller; tu --suggest-split leaves it out.
 * Scratch one verdict EXACT (4 bytes), fixed compiler/flags, no region:
 * typedef unsigned short u16;
 * unsigned int func_02024530(const u16 *p) { return p[1]; }
 * Extent remainder: two-byte zero alignment padding.
 */
void func_021BD690(u8 *p, u16 *out)
{
    *(s16_021BD690 *)p=func_0202452C(out);
    p[3]=func_02024584(*(s16_021BD690 *)p);
    p[2]=func_02024530(out);
}

void func_021BD6B4(State_021BD6B4 *p, void *out) {
    p->b++;
    if (p->b >= p->c) {
        p->b = 0;
        p->a++;
        if (p->a >= 5) p->a = 0;
        p->c = func_02024584(p->a);
    }
    func_02024598(out, p->a, p->b);
}

void func_021BD6F8(State_021BD6F8 *p,void *out) {
 p->b--;
 if(p->b<0) { p->a--; if(p->a<0) p->a=4; p->c=func_02024584(p->a); p->b=p->c-1; }
 func_02024598(out,p->a,p->b);
}

void func_021BD740(u8 *p,void *out,int v)
{
    p[2]=0;
    ((struct Obj05295 *)p)->f0=v;
    p[3]=func_02024584(((struct Obj05295 *)p)->f0);
    func_02024598(out,((struct Obj05295 *)p)->f0,*(s8 *)&((struct Obj05295 *)p)->f2);
}
