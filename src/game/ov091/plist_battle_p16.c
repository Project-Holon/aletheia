/*
 * file:     plist_battle_p16.c
 * unit:     yes
 * function: func_021BD218, func_021BD454, func_021BD480, func_021BD4EC, func_021BD504
 * address:  0x021BD218
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_020490F4 0x020490F4 arm
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202136C 0x0202136C thumb
 *   func_0204B878 0x0204B878 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021B9C1C 0x021B9C1C thumb ov091
 *   func_02018430 0x02018430 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021B9D58 0x021B9D58 thumb ov091
 *   func_0201ED04 0x0201ED04 thumb
 *   d_021BED48 0x021BED48 data ov091 a1
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021BB7D8  0x021BB7D8  thumb  ov091
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BBA0C  0x021BBA0C  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_02045808  0x02045808  arm
 */
#include "../../matched/include/Obj02771.h"
#include "../../matched/include/Obj06214.h"
#include "../../matched/include/Obj09934.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj20921.h"
#include "../../matched/include/Obj20922.h"
#include "../../matched/include/Obj20923.h"
#include "../../matched/include/Obj20924.h"
#include "../../matched/include/Obj20925.h"
#include "../../matched/include/Obj20926.h"

#define P(k) (*(u32 *)(p+(k)))
struct Obj;
struct WordSet;
struct Descriptor;
struct PrintSys;
struct Cfg;
struct Strbuf;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef struct {u16 a,b,c;u8 d,e;} R;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02017E1C(void *,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *);
extern int func_0201BBE8(void *a0);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B92C(struct Obj *p,u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32 func_0202136C(u16);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_020450F0(int,u8,u8,int,u8,u8,u8);
extern void func_021B9C1C(u8 *p, u32 win, u32 id, int x, s16 y, u16 color);
extern u32 func_02018430(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_021B9D58(u8 *p, u32 win, void *set, u32 idx, s16 x, s16 y, u16 color);
extern u32 func_0201ED04(struct WordSet *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *);
extern void func_0204A8D4(unsigned int);
extern u32 func_020307B0(void *p);
extern unsigned int func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern int func_021BB7D8(void *unused, u32 p);
extern void func_021BB714(void *a, u32 *s, u32 k);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BBA0C(int a, int b, int c, const void *d, int e);
extern void func_021BB7E8(u8 *a, u32 *s, u32 x);
extern void func_021BB98C(void *p, u32 s);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045808(struct U16Vec *vec);
u32 *func_021BD218(u8 *p,void *mon,s16 x,u16 y);
void func_021BD454(char *unused,char *p);
void func_021BD480(char *a, int *b);
void func_021BD4EC(char *p);
void func_021BD504(char *a);
extern const char d_021BED48[];

/*
 * lever: u16 y pins x's front spill; declare the u8 offset before gx to restore r7/r6 allocation.
 */
u32 *func_021BD218(u8 *p,void *mon,s16 x,u16 y)
{
    R a;
    R b;
    u32 *s;
    void *h;
    int species;
    int frame;
    u32 gender;
    u32 special;
    int level;
    int egg;
    int rem;
    u8 z;
    int gx;
    u32 gy;
    u32 text;
    s=func_02030734(((struct Obj02771 *)p)->f0,24,0,d_021BED48,0x199);
    egg=func_02017E1C(mon,0x4c,0);
    h=func_020490F4(7,((struct Obj02771 *)p)->f0);
    species=(int)func_020185F4(mon);
    s[3]=func_0204A6C8(h,func_0201BA68((void *)species),0,1,((struct Obj02771 *)p)->f0);
    func_02049238(h);
    frame=func_0201BBE8((void *)species);
    a.a=x+16;a.b=y+8;a.c=1;a.d=16;a.e=2;
    {
        int obj=(int)func_0204B294((void *)P(0x1ec),s[3],P(0x194),P(0x1d0),&a,1,((struct Obj02771 *)p)->f0);
        s[4]=obj;
        func_0204B6F4((struct Obj *)obj,frame,1);
    }
    func_0204B92C((struct Obj *)s[4],1);
    gender=func_02017E1C(mon,6,0);
    b.a=x+32;b.b=y+16;b.c=0;b.d=8;b.e=2;
    s[5]=(u32)func_0204B294((void *)P(0x1ec),P(0x1a8),P(0x184),P(0x1c4),&b,1,((struct Obj02771 *)p)->f0);
    if(gender!=0) {
        func_0204B3DC((struct Obj *)s[5],1);
        if(func_0202136C(gender)==1) func_0204B878((struct Obj *)s[5],1);
        else func_0204B878((struct Obj *)s[5],0);
    } else func_0204B3DC((struct Obj *)s[5],0);
    special=func_02017E1C(mon,0x6e,0);
    rem=x%8;
    z=rem;
    gy=(u32)y>>3;
    gx=(u32)x>>3;
    s[1]=func_020450F0(4,(u8)gx+3,gy,3,2,13,1);
    if(egg==0) {
        if(special==0) func_021B9C1C(p,s[1],7,(u16)(z+4),0,0x14c0);
        else if(special==1) func_021B9C1C(p,s[1],8,(u16)(z+4),0,0xc80);
    }
    level=func_02018430((void *)((int)mon));
    z=rem;
    s[2]=func_020450F0(4,(u8)gx,(u8)gy+3,6,1,14,1);
    if(egg==0) {
        text=(u32)func_0201EC64(((struct Obj02771 *)p)->f0);
        func_0201EFA4((struct WordSet *)text,0,level,3,0,1);
        func_021B9D58(p,s[2],(void *)text,2,z,0,0x3c40);
        func_0201ED04((struct WordSet *)text);
    }
    s[0]=1;
    return s;
}

void func_021BD454(char *unused,char *p) { func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f4); func_020452E8(*(struct Descriptor * *)&((struct Obj06214 *)p)->f8); func_0204B3B4(*(struct Obj * *)&((struct Obj06214 *)p)->f14); func_0204B3B4(*(struct Obj * *)&((struct Obj06214 *)p)->f10); func_0204A8D4(((struct Obj06214 *)p)->fC); func_020307B0(p); }


void func_021BD480(char *a, int *b)
{
    int q;
    if (b[0] == 1
        && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[1])) == 0
        && func_0201C6C4((struct PrintSys *)(((struct Obj09934 *)a)->f140), (void *)func_02045770((struct Descriptor *)b[2])) == 0) {
        q = b[1];
        b[0] = 0;
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
        q = b[2];
        func_02045334((struct Descriptor *)q);
        func_02045374((struct Cfg *)q);
        func_02041B6C(func_02045730((struct Descriptor *)q));
    }
}

void func_021BD4EC(char *p) { func_021BD504(p); ((struct Obj00009 *)p)->f20C=((struct Obj20921 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f94; }


void func_021BD504(char *a)
{
    int t;
    if (((struct Obj20922 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 == 0)
        return;
    if (func_021BB7D8(a, *(int *)&((struct Obj00009 *)a)->f150) == 0)
        func_021BB714(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), 1);
    if (((struct Obj20923 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f64 == 1) {
        t = (int)func_020457B0(0x10, ((struct Obj00009 *)a)->f0);
        func_02045924((struct Strbuf *)t, (const u16 *)(((struct Obj20924 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f78));
        func_021BB97C((u16 *)a, *(int *)&((struct Obj00009 *)a)->f150);
        func_021BBA0C((int)a, *(int *)&((struct Obj00009 *)a)->f150, 0, (const void *)t, ((struct Obj20925 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f7C);
        func_021BB7E8((u8 *)a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), 0xA9);
        func_021BB98C(a, *(int *)&((struct Obj00009 *)a)->f150);
        func_02045808((struct U16Vec *)t);
    } else {
        func_021BB7E8((u8 *)a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), ((struct Obj20926 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 + 0xA9);
    }
}
