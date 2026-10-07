/*
 * file:     beacon_view_p01.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFF7C, func_021F0050, func_021F0078, func_021F00C8, func_021F0114, func_021F0140, func_021F0208, func_021F028C, func_021F029C, func_021F02C4, func_021F03EC, func_021F0438, func_021F055C, func_021F05E8, func_021F0668
 * address:  0x021EFEC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02021EE4  0x02021EE4  thumb
 *   func_021F0AC0  0x021F0AC0  thumb  ov032
 *   func_021F0B10  0x021F0B10  thumb  ov032
 *   func_02165AC4  0x02165AC4  thumb  ov010
 *   func_021659F0  0x021659F0  thumb  ov010
 *   func_021F0F44  0x021F0F44  thumb  ov032
 *   func_021F0F30  0x021F0F30  thumb  ov032
 *   func_021F1144  0x021F1144  thumb  ov032
 *   func_021F0EA4  0x021F0EA4  thumb  ov032
 *   func_021F0E24  0x021F0E24  thumb  ov032
 *   func_021F0E7C  0x021F0E7C  thumb  ov032
 *   func_021F0DF4  0x021F0DF4  thumb  ov032
 *   func_0203D34C  0x0203D34C  arm
 *   func_02035D20  0x02035D20  arm
 *   func_021F0A18  0x021F0A18  thumb  ov032
 *   func_021F253C  0x021F253C  thumb  ov032
 *   func_021F08E4  0x021F08E4  thumb  ov032
 *   func_02165C10  0x02165C10  thumb  ov010
 *   func_021F1F00  0x021F1F00  thumb  ov032
 *   func_021F096C  0x021F096C  thumb  ov032
 *   func_021F1340  0x021F1340  thumb  ov032
 *   func_02035CB8 0x02035CB8 arm
 *   func_021585E0  0x021585E0  thumb  ov010
 *   func_02012204  0x02012204  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_020275D0  0x020275D0  thumb
 *   func_020275C4  0x020275C4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021F18C4  0x021F18C4  thumb  ov032
 *   func_021F07D4 0x021F07D4 thumb ov032
 *   sub_02010EA0 0x02010EA0 thumb
 *   func_021F1A18 0x021F1A18 thumb ov032
 *   func_021658D4  0x021658D4  thumb  ov010
 *   func_021F1268  0x021F1268  thumb  ov032
 *   func_02165B5C  0x02165B5C  thumb  ov010
 *   func_02165A10  0x02165A10  thumb  ov010
 *   func_0200C1E0  0x0200C1E0  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_021D3294  0x021D3294  thumb  ov021
 *   func_021F12B8 0x021F12B8 thumb ov032
 *   func_0201C4DC 0x0201C4DC thumb
 *   func_021F180C  0x021F180C  thumb  ov032
 *   func_021F0DD8  0x021F0DD8  thumb  ov032
 *   func_021F06E0  0x021F06E0  thumb  ov032
 *   func_021F13A0  0x021F13A0  thumb  ov032
 *   func_021F1A08  0x021F1A08  thumb  ov032
 *   func_021657E8  0x021657E8  thumb  ov010
 *   func_0204B98C 0x0204B98C arm
 */
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj00188.h"
#include "../../matched/include/Obj09794.h"
#include "../../matched/include/Obj05120.h"
#include "../../matched/include/Obj20414.h"
#include "../../matched/include/Obj20415.h"
#include "../../matched/include/Obj20416.h"
#include "../../matched/include/Obj09795.h"

struct Obj02021EE4;
struct Queue;
struct Rec;
struct Ctx;
struct WordSet;
struct Blk34;
struct Chan02021FD8;
struct PrintSys;
struct Actor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct { u32 x, y; } Pair;

extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_021F0AC0(char *p);
extern void func_021F0B10(char *p, int a, int b);
extern int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern int func_021659F0(u8 *q, int delta);
extern u8 *func_021F0F44(u8 *p, int a);
extern void func_021F0F30(char *p, int a, int b);
extern void func_021F1144(u8 *p, u8 *q, void *r, int mode, int skip, int t);
extern void func_021F0EA4(char *p, unsigned a);
extern void func_021F0E24(char *p);
extern void func_021F0E7C(char *p);
extern void func_021F0DF4(void *p, unsigned short v);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021F253C(char *p, int v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021F0A18(u8 *p, u32 *v);
extern int func_021F08E4(u8 *p, void *pt);
extern int func_02165C10(u8 *p);
extern void func_021F1F00(char *p, int a);
extern int func_021F096C(u8 *p, void *pt);
extern void func_021F1340(char *this, int a, u8 b);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_021585E0(int);
extern u32 func_02012204(const struct Ctx *p);
extern u32 func_0201058C(void *key);
extern void *func_020275D0(char *p);
extern int func_020275C4(void *p);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_021F18C4(char *p, int b);
extern unsigned func_021F07D4(u8 *);
extern u8 sub_02010EA0(int,u8 *);
extern void func_021F1A18(char *p, int b);
extern int func_021658D4(struct Queue *q, struct Rec *out, u16 *tag);
extern void func_021F1268(char *this);
extern int func_02165B5C(struct Rec *r);
extern int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag);
extern u32 func_0200C1E0(struct Blk34 *p);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void func_021D3294(u32 p, u32 a, u32 b, u32 c, u32 d);
extern void func_021F12B8(unsigned char *, int);
extern void func_0201C4DC(struct PrintSys *p, u32 lo, u32 hi);
extern int func_021F180C(char *this, int x, int flag);
extern void func_021F0DD8(unsigned int a);
extern void func_021F06E0(u8 *p, u32 x, int y);
extern void func_021F13A0(char *this, int a, int b, int c, int s);
extern void func_021F1A08(char *p);
extern void func_021657E8(void *a, u16 b);
extern u32 func_0204B98C(struct Actor *);
void func_021EFEC0(u8 *o);
int func_021EFF7C(u8 *p);
int func_021F0050(unsigned char *p);
int func_021F0078(char *p);
int func_021F00C8(char *p);
int func_021F0114(u8 *p);
int func_021F0140(u8 *p);
void func_021F0208(u8 *p, int flag);
void func_021F028C(unsigned char *p);
void func_021F029C(char *p,int flag);
int func_021F02C4(u8 *p);
int func_021F03EC(u8 *p);
int func_021F0438(u8 *p);
int func_021F055C(u8 *p);
void func_021F05E8(u8 *p, int a, u32 b);
int func_021F0668(char *p, int i);


void func_021EFEC0(u8 *o)
{
    int i;
    u8 *q;
    u8 *e;
    int s;
    int t;

    func_02021EE4((struct Obj02021EE4 *)(*(int *)&((struct Obj00007 *)o)->fAC), 1);
    func_021F0AC0((char *)o);
    func_021F0B10((char *)o, 1, 0);
    for (i = 0; i < o[0x7D]; i++) {
        q = o + 0x48;
        t = o[0x7C];
        func_02165AC4((struct Queue *)(((struct Obj00007 *)o)->f3C), (struct Rec *)(((struct Obj00007 *)o)->f40), (u16 *)q, t + i);
        s = func_021659F0((u8 *)(((struct Obj00007 *)o)->f3C), t + i);
        e = func_021F0F44(o, 0xFF);
        func_021F0F30((char *)e, (u8)s, (u8)(i + 1));
        func_021F1144(o, e, (void *)(((struct Obj00007 *)o)->f40), 2, 0, 0);
        func_021F0EA4((char *)e, (int)1);
    }
    func_021F0E24((char *)o);
    func_021F0E7C((char *)o);
    if (((struct Obj00007 *)o)->f28 == 0x30)
        func_021F0DF4((void *)(*(int *)&((struct Obj00007 *)o)->f2BC), 3);
    func_0203D34C(0, ((struct Obj00007 *)o)->f96);
}


int func_021EFF7C(u8 *p)
{
    Pair v;
    int r;
    int s;

    if (func_02035D20(&v.x, &v.y) == 0)
        return 0;
    r = func_021F0A18(p, (u32 *)(&v));
    if (r != -1) {
        switch (r) {
        case 0:
            return 4;
        case 1:
            func_021F253C((char *)p, 8);
            break;
        case 2:
            return 5;
        case 3:
            func_021F253C((char *)p, 1);
            break;
        }
        return 0;
    }
    r = func_021F08E4(p, &v);
    if (r != -1) {
        func_02165AC4((struct Queue *)(((struct Obj00188 *)p)->f3C), (struct Rec *)(((struct Obj00188 *)p)->f40), (u16 *)(p + 0x48), p[0x7C] + r);
        if (func_02165C10((u8 *)(((struct Obj00188 *)p)->f40)) != 0)
            return 0;
        p[0x7E] = r;
        func_021F1F00((char *)p, (u8)r);
        func_021F253C((char *)p, 4);
        return 0;
    }
    s = func_021F096C(p, &v);
    if (s != -1) {
        func_021F1340((char *)p, s, (int)0);
        return 3;
    }
    return 0;
}

int func_021F0050(unsigned char *p) { u32 pt[2]; if(func_02035CB8(pt,pt+1)) return func_021F096C(p,pt); return -1; }


int func_021F0078(char *p)
{
    int r;

    r = func_021585E0(((struct Obj09794 *)p)->f1C);
    if (func_02012204((const struct Ctx *)(((struct Obj09794 *)p)->f0)) != 0) {
        func_021F253C(p, 1);
        return 1;
    }
    if (r == 2) {
        func_021F253C(p, 2);
        return 1;
    }
    if (func_0201058C((void *)(((struct Obj09794 *)p)->f20)) & 8) {
        func_021F253C(p, 3);
        return 1;
    }
    return 0;
}


int func_021F00C8(char *p)
{
    u16 *f;

    f = func_020275D0((char *)(*(int *)(p + 0x34)));
    if (*f == 0)
        return 0;
    *f = 0;
    func_0201EE0C(*(void **)(p + 0x110), 0, (void *)func_020275C4((void *)(*(int *)(p + 0x34))),
                  *(u8 *)(p + 0x30), 1, 2);
    func_021F18C4(p, 0xB);
    return 1;
}

int func_021F0114(u8 *p) { unsigned n; n=func_021F07D4(p); if(n==0x30) return 0; if(n==sub_02010EA0(n,*(u8 * *)&((struct Obj05120 *)p)->f24)) return 0; func_021F1A18((char *)p,n); return 1; }


int func_021F0140(u8 *p)
{
    u8 t;

    if (func_021658D4((struct Queue *)(((struct Obj00188 *)p)->f38), (struct Rec *)(((struct Obj00188 *)p)->f4C), (u16 *)(p + 0x4A)) == 0) {
        func_021F1268((char *)p);
        return 0;
    }
    if (func_02165B5C((struct Rec *)(((struct Obj00188 *)p)->f4C)) != 0)
        return 0;
    p[0x54] = func_02165A10((struct Queue *)(((struct Obj00188 *)p)->f3C), (struct Rec *)(((struct Obj00188 *)p)->f4C), ((struct Obj00188 *)p)->f4A, (int *)(p + 0x5C));
    p[0x55] = func_021659F0((u8 *)(((struct Obj00188 *)p)->f3C), p[0x54]);
    if (((struct Obj00188 *)p)->f5C == 0) {
        *(u8 * *)&((struct Obj00188 *)p)->f50 = func_021F0F44(p, p[0x55]);
    } else {
        *(u8 * *)&((struct Obj00188 *)p)->f50 = 0;
        ((struct Obj00188 *)p)->f2D4 = func_0200C1E0((struct Blk34 *)(((struct Obj00188 *)p)->f14));
    }
    if (*(u8 * *)&((struct Obj00188 *)p)->f50 != 0 && ((struct Obj20414 *)(*(u8 * *)&((struct Obj00188 *)p)->f50))->f2C != 0)
        ((struct Obj00188 *)p)->f6C = 0;
    else
        ((struct Obj00188 *)p)->f6C = 1;
    t = p[0x7B];
    p[0x57] = t;
    if (t < 0x1E) {
        p[0x7B] += (u8)((struct Obj00188 *)p)->f5C;
        if (p[0x7B] <= 4)
            p[0x7D] = p[0x7B];
    }
    return 1;
}


void func_021F0208(u8 *p, int flag)
{
    if (flag) {
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 1, 0, 0xe0, 6, 0);
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 3, 0, 0xe0, 6, 0);
        func_021D3294(((struct Obj00007 *)p)->f10, 5, 0x1e, 0xa, 6);
    } else {
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 1, 0, 0xe0, 0, 0);
        func_02021FD8((struct Chan02021FD8 *)(((struct Obj00007 *)p)->fAC), 3, 0, 0xe0, 0, 0);
        func_021D3294(((struct Obj00007 *)p)->f10, 4, 0x1e, 0xd, 3);
    }
}

void func_021F028C(unsigned char *p) { func_021F12B8(p, ((struct Obj20415 *)p)->f84); }

void func_021F029C(char *p,int flag) { if(flag) func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4),2000,0); else func_0201C4DC((struct PrintSys *)(((struct Obj00007 *)p)->fB4),500,0); }


int func_021F02C4(u8 *p)
{
    int r;

    switch (((struct Obj00007 *)p)->f6C) {
    case 0:
        if (((struct Obj20416 *)(*(u8 * *)&((struct Obj00007 *)p)->f50))->f2C != 0)
            break;
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 1:
        r = func_021F180C((char *)p, ((struct Obj00007 *)p)->f4C, ((struct Obj00007 *)p)->f5C);
        if (((struct Obj00007 *)p)->f5C == 0) {
            if (r != 0) {
                func_021F05E8(p, 4, 2);
                func_021F0DD8(0x549);
            }
            if (*(u8 * *)&((struct Obj00007 *)p)->f50 != 0) {
                func_021F1144(p, *(u8 * *)&((struct Obj00007 *)p)->f50, (void *)(((struct Obj00007 *)p)->f4C), 0, r == 0, 0);
                func_021F0EA4((char *)(*(u8 * *)&((struct Obj00007 *)p)->f50), 1);
            }
            return 1;
        }
        func_021F05E8(p, 4, 2);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 2:
        func_021F0AC0((char *)p);
        func_021F0B10((char *)p, 1, (int)(p + 0xA8));
        func_021F06E0(p, ((struct Obj00007 *)p)->f4C, p[0x57]);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 3:
        if (p[0x7C] != 0) {
            p[0x54] = p[0x7C];
            func_02165AC4((struct Queue *)(((struct Obj00007 *)p)->f3C), (struct Rec *)(((struct Obj00007 *)p)->f4C), (u16 *)(p + 0x4A), p[0x54]);
            p[0x55] = func_021659F0((u8 *)(((struct Obj00007 *)p)->f3C), p[0x54]);
        }
        func_021F13A0((char *)p, ((struct Obj00007 *)p)->f4C, p[0x55], 1, (p[0x7C] != 0 ? 1 : 0) + 1);
        p[0x7C] = p[0x54];
        func_021F0DD8(0x64A);
        return 1;
    }
    return 0;
}


int func_021F03EC(u8 *p)
{
    int s = ((struct Obj00007 *)p)->f6C;

    switch (s) {
    case 0:
        func_021F05E8(p, 0, 1);
        func_021F029C((char *)p, 1);
        func_021F1A08((char *)p);
        ((struct Obj00007 *)p)->f6C = ((struct Obj00007 *)p)->f6C + 1;
        break;
    case 1:
        if (((struct Obj00007 *)p)->fA8 == 0) {
            func_021F029C((char *)p, 0);
            ((struct Obj00007 *)p)->f6C = 0;
            return 1;
        }
        break;
    }
    return 0;
}


int func_021F0438(u8 *p)
{
    u8 *e;
    u8 s;

    if (((struct Obj00007 *)p)->fA8 != 0)
        return 5;
    switch (((struct Obj00007 *)p)->f6C) {
    case 0:
        func_021F05E8(p, 2, 1);
        func_021F0B10((char *)p, 2, (int)(p + 0xA8));
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 1:
        if (func_021F0668((char *)p, 2) != 0)
            break;
        func_021F05E8(p, 0, 2);
        func_021F05E8(p, 1, 2);
        func_021F05E8(p, 3, 2);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 2:
        ((struct Obj00007 *)p)->f6C = func_021F055C(p);
        if (((struct Obj00007 *)p)->f6C == 3)
            return 3;
        break;
    case 4:
        s = func_021659F0((u8 *)(((struct Obj00007 *)p)->f3C), p[0x7E] + p[0x7C]);
        e = func_021F0F44(p, s);
        func_0201EE0C(((struct Obj00007 *)p)->f110, 0, ((struct Obj09795 *)e)->f24, e[4], 1, 2);
        func_021F029C((char *)p, 1);
        func_021F18C4((char *)p, 3);
        func_021657E8((void *)(*(int *)&((struct Obj00007 *)p)->f4), ((struct Obj09795 *)e)->f6);
        ((struct Obj00007 *)p)->f6C = 5;
        break;
    case 5:
        func_021F029C((char *)p, 0);
        ((struct Obj00007 *)p)->f6C = 6;
        break;
    case 3:
        func_021F05E8(p, 2, 0);
        ((struct Obj00007 *)p)->f6C = 2;
        break;
    case 6:
        func_021F05E8(p, 4, 0);
        func_021F0B10((char *)p, 1, (int)(p + 0xA8));
        ((struct Obj00007 *)p)->f6C = 7;
        break;
    case 7:
        ((struct Obj00007 *)p)->f6C = 0;
        return 0;
    }
    return 5;
}


int func_021F055C(u8 *p)
{
    Pair v;
    int r;
    int s;

    if (func_02012204((const struct Ctx *)(((struct Obj00188 *)p)->f0)) != 0) {
        func_021F253C((char *)p, 1);
        return 6;
    }
    if (func_02035D20(&v.x, &v.y) == 0)
        return 2;
    if (func_021F0A18(p, (u32 *)(&v)) == 2)
        return 6;
    r = func_021F08E4(p, &v);
    if (r != -1) {
        p[0x7e] = r;
        func_021F1F00((char *)p, (u8)r);
        return 4;
    }
    s = func_021F096C(p, &v);
    if (s != -1) {
        func_021F1340((char *)p, s, (int)5);
        return 3;
    }
    return 2;
}


void func_021F05E8(u8 *p, int a, u32 b)
{
    u8 m;

    if (a == 4)
        m = 0xf;
    else
        m = 1 << a;
    if ((1 & m) && ((struct Obj00007 *)p)->f28 != 0x30)
        func_021F0DF4((void *)(*(u32 *)&((struct Obj00007 *)p)->f2BC), (u8)(b + 1));
    if (2 & m)
        func_021F0DF4((void *)(((struct Obj00007 *)p)->f2C0), (u8)(b + 4));
    if ((4 & m) && p[0x7b] != 0)
        func_021F0DF4((void *)(*(u32 *)&((struct Obj00007 *)p)->f2C4), (u8)(b + 7));
    if (8 & m)
        func_021F0DF4((void *)(((struct Obj00007 *)p)->f2C8), (u8)(b + 10));
}

int func_021F0668(char *p, int i) { return func_0204B98C(*(struct Actor **)(p + i * 4 + 0x2bc)); }
