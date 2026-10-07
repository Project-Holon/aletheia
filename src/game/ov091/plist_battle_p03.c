/*
 * file:     plist_battle_p03.c
 * unit:     yes
 * function: func_021BA624, func_021BA65C, func_021BA670, func_021BA688, func_021BA6A0, func_021BA81C, func_021BA890, func_021BA8CC, func_021BA954, func_021BAA50
 * address:  0x021BA624
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
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   func_02030734 0x02030734 arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204B09C 0x0204B09C arm
 *   func_020450F0 0x020450F0 arm
 *   func_021BB46C 0x021BB46C thumb ov091
 *   func_021B9A84 0x021B9A84 thumb ov091
 *   func_021BAFA0 0x021BAFA0 thumb ov091
 *   func_021BAAE4 0x021BAAE4 thumb ov091
 *   d_021BED18 0x021BED18 data ov091 a1
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 *   d_021BEC6C 0x021BEC6C data ov091 a1
 *   d_021BEC6D 0x021BEC6D data ov091 a1
 *   func_02041B6C  0x02041B6C  arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02017F90  0x02017F90  thumb
 *   func_021BB56C  0x021BB56C  thumb  ov091
 *   func_0204B8F4  0x0204B8F4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020490F4  0x020490F4  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_02049238  0x02049238  arm
 *   func_0201BBE8  0x0201BBE8  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 */
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj20870.h"
#include "../../matched/include/Obj20871.h"
#include "../../matched/include/Obj20872.h"
#include "../../matched/include/Obj13247.h"
#include "../../matched/include/Obj03678.h"
#include "../../matched/include/Obj20873.h"
#include "../../matched/include/Obj07731.h"
#include "../../matched/include/Obj05169.h"
#include "../../matched/include/Obj05170.h"

#define W(k) (*(u32 *)(s+(k)))
#define P(k) (*(int *)(p+(k)))
#define S(k) (*(int *)(s+(k)))
struct Bank;
struct Obj;
struct Descriptor;
struct Cfg;
struct PrintSys;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { short x,y; u16 a,b,c,d; int e,f; } Rect;

typedef struct {
    int w0;
    u8 b4;
    u8 pad5[15];
    int w14;
    int pad18;
    int w1c;
} S44;

typedef short s16;

typedef struct {
    int w0;
    u16 pad4;
    u16 h6;
    int pad8[2];
    int w10;
    int w14;
    int w18;
    int pad1c;
    u32 w20;
    int pad24[3];
    int w30;
} S;

typedef struct {u16 a,b,c;u8 d,e;} R_021BA954;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R_021BAA50;

typedef signed int     s32;

extern u32 func_02017E1C(void *,u32,u32);
extern void func_02017E40(void *,u32,u32);
extern u32 func_02007FB8(u8 *, u16, u16);
extern u32 func_02007F1C(u8 *, u16, u16, u16);
extern u32 func_02007E50(u8 *, u16, u16, u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_0204B09C(void *,u32,Rect *);
extern void *func_020450F0(int,u8,int,int,u8,u8,u8);
extern void func_021BB46C(u8 *p, u32 *q);
extern int func_021B9A84(u32 p);
extern void func_021BAFA0(u8 *,u8 *,int);
extern void func_021BAAE4(u8 *,u8 *,int);
extern void func_02041B6C(u32 id);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B084(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A8D4(u32);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_02017F90(void *p);
extern void func_021BB56C(u32 p, int x, int y, u16 *out);
extern u32 func_0204B8F4(struct Obj *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *a);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021BA624(u8 *p, void *q, u16 id);
u32 func_021BA65C(u8 *p, u16 id);
u32 func_021BA670(u8 *p, u16 id);
u32 func_021BA688(u8 *p, u16 id);
u8 *func_021BA6A0(u8 *p, int k, void *mon);
S44 *func_021BA81C(u8 *a, int k);
void func_021BA890(void *ignored,u8 *p);
void func_021BA8CC(u32 a, S *s);
void func_021BA954(u8 *p,u8 *s);
void func_021BAA50(u8 *a, u8 *s);
extern const char d_021BED18[];
extern const u8 d_021BEC74[], d_021BEC75[], d_021BEC6C[], d_021BEC6D[];
extern const u8 d_021BEC74[];
extern const u8 d_021BEC75[];

void func_021BA624(u8 *p, void *q, u16 id) { u32 old=func_02017E1C(q,6,0); if(old) func_021BA688(p,old); func_02017E40(q,6,id); if(id) func_021BA670(p,id); }

u32 func_021BA65C(u8 *p, u16 id) { return func_02007FB8(*(u8 * *)&((struct Obj20870 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4, id, ((struct Obj00009 *)p)->f0); }

u32 func_021BA670(u8 *p, u16 id) { return func_02007F1C(*(u8 * *)&((struct Obj20871 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4,id,1,((struct Obj00009 *)p)->f0); }

u32 func_021BA688(u8 *p, u16 id) { return func_02007E50(*(u8 * *)&((struct Obj20872 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f4,id,1,((struct Obj00009 *)p)->f0); }

u8 *func_021BA6A0(u8 *p, int k, void *mon)
{
    u8 x = d_021BEC74[k*2];
    u8 y = d_021BEC75[k*2];
    u8 i;
    u8 *s;
    int t;
    int zero = 0;
    enum Selector { SEL_ZERO, SEL_ONE } selector;
    Rect r;
    s = func_02030734(*(u16 *)p,0x44,0,d_021BED18,0x9f);
    s[4] = k;
    W(0) = (u32)mon;
    W(0x14) = 0;
    W(0x10) = 0;
    W(0x18) = 0;
    *(u16 *)(s+6) = func_02017E1C(mon,0xa0,0);
    *(u16 *)(s+8) = *(u16 *)(s+6);
    if (k != 0) zero = 1;
    selector = k != 0;
    t = x + 0x10;
    func_020410D0(2,(u8)t,y,0x10,6,(u32)(*(u8 **)(p+0x15c)+0xc),
                 d_021BEC6C[selector*2],d_021BEC6D[zero*2],0x20,0x20);
    W(0xc) = func_02017E1C((void *)W(0),0x4c,0);
    r.a = 0;
    r.b = 0;
    r.c = 0x100;
    r.d = 0xc0;
    r.e = 0;
    r.f = 0;
    W(0x24) = (u32)func_0204B034((u8 *)(&r.a),1,*(u16 *)p);
    W(0x28) = (u32)func_0204B100(6,0,*(u16 *)p);
    func_0204B258((void *)W(0x28),(void *)W(0x24));
    func_021BA954(p,s);
    func_021BAA50(p,s);
    r.x = -x*8;
    r.y = -y*8;
    func_0204B09C((void *)W(0x24),0,&r);
    W(0x20) = (u32)func_020450F0(1,t,y,0x10,6,0xd,1);
    func_021BB46C(p,(u32 *)s);
    if (func_021B9A84((u32)p) == 1) {
        for (i = 0; i < 6; i++) {
            if (s[4] + 1 == *(u8 *)(*(u8 **)(p+0x280)+i+0x49)) W(0x1c) = i;
        }
    }
    func_021BAFA0(p,s,0);
    func_021BAAE4(p,s,0);
    return s;
}


S44 *func_021BA81C(u8 *a, int k)
{
    S44 *p = func_02030734(((struct Obj13247 *)a)->f0, 0x44, 0, d_021BED18, 0xea);
    u8 *q = *(u8 * *)&((struct Obj13247 *)a)->f15C + 0xc;

    func_020410D0(2, (u8)(d_021BEC74[k * 2] + 0x10), d_021BEC75[k * 2], 0x10, 6,
                  (u32)q, 0, 0x13, 0x20, 0x20);
    p->b4 = k;
    p->w0 = 0;
    p->w14 = 1;
    p->w1c = 8;
    func_02041B6C(2);
    return p;
}

void func_021BA890(void *ignored,u8 *p) { if (!((struct Obj03678 *)p)->f14) { func_020452E8(((struct Obj03678 *)p)->f20); func_0204B3B4(((struct Obj03678 *)p)->f30); func_0204B3B4(((struct Obj03678 *)p)->f34); func_0204B3B4(((struct Obj03678 *)p)->f38); func_0204B084(((struct Obj03678 *)p)->f24); func_0204B1CC(((struct Obj03678 *)p)->f28); func_0204A8D4(((struct Obj03678 *)p)->f2C); } func_020307B0(p); }


void func_021BA8CC(u32 a, S *s)
{
    s16 buf[2];

    if (s->w14 != 0)
        return;
    if (s->w18 == 1) {
        u32 t = (u32)func_02045770((struct Descriptor *)s->w20);

        if (func_0201C6C4((struct PrintSys *)(((struct Obj20873 *)a)->f140), (void *)t) == 0) {
            a = s->w20;
            s->w18 = 0;
            func_02045334((struct Descriptor *)a);
            func_02045374((struct Cfg *)a);
            func_02041B6C(func_02045730((struct Descriptor *)a));
        }
    }
    if (s->w10 == 1 && func_02017F90((void *)s->w0) == 0 && s->h6 != 0) {
        func_021BB56C((u32)s, 0x1a, 0x13, (u16 *)buf);
        if (func_0204B8F4((struct Obj *)s->w30) == 1)
            buf[1] = buf[1] - 6;
        func_0204B404((struct Obj *)s->w30, (const struct Vec2 *)buf, 0);
    }
}

void func_021BA954(u8 *p,u8 *s)
{
    R_021BA954 a;
    R_021BA954 b;
    R_021BA954 c;
    R_021BA954 d;
    int x;
    a.a=16;a.b=16;a.c=0;a.d=1;a.e=2;
    x=(int)func_0204B294((void *)S(0x28),P(0x19c),P(0x178),P(0x1b8),&a,0,((struct Obj07731 *)p)->f0);
    S(0x34)=x;
    func_0204B92C((struct Obj *)x,1);
    b.a=0x54;b.b=0x1c;b.c=0;b.d=0;b.e=2;
    S(0x38)=(int)func_0204B294((void *)S(0x28),P(0x1b0),P(0x18c),P(0x1cc),&b,0,((struct Obj07731 *)p)->f0);
    c.a=32;c.b=24;c.c=0;c.d=0;c.e=2;
    x=(int)func_0204B294((void *)S(0x28),P(0x1a4),P(0x180),P(0x1c0),&c,0,((struct Obj07731 *)p)->f0);
    S(0x3c)=x;
    func_0204B3DC((struct Obj *)x,0);
    d.a=32;d.b=42;d.c=0;d.d=0;d.e=2;
    x=(int)func_0204B294((void *)S(0x28),P(0x1ac),P(0x188),P(0x1c8),&d,0,((struct Obj07731 *)p)->f0);
    S(0x40)=x;
    func_0204B3DC((struct Obj *)x,0);
}


void func_021BAA50(u8 *a, u8 *s)
{
    void *h;
    int t;
    int r;
    R_021BAA50 rc;

    h = func_020490F4(7, ((struct Obj05169 *)a)->f0);
    t = (int)func_020185F4(func_0201AB28(**(void ** *)&((struct Obj05169 *)a)->f280, s[4]));
    ((struct Obj05170 *)s)->f2C = func_0204A6C8(h, func_0201BA68((void *)t), 0, 0, ((struct Obj05169 *)a)->f0);
    func_02049238(h);
    r = func_0201BBE8((void *)t);
    rc.a = 0x18;
    rc.b = 0x10;
    rc.c = 1;
    rc.d = 0;
    rc.e = 2;
    {
        int x = (int)func_0204B294((void *)((struct Obj05170 *)s)->f28, ((struct Obj05170 *)s)->f2C, ((struct Obj05169 *)a)->f190,
                              ((struct Obj05169 *)a)->f1D0, &rc, 0, ((struct Obj05169 *)a)->f0);
        ((struct Obj05170 *)s)->f30 = x;
        func_0204B6F4((struct Obj *)x, r, 1);
    }
    func_0204B92C((struct Obj *)((struct Obj05170 *)s)->f30, 1);
}
