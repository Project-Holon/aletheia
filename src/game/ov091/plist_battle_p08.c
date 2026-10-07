/*
 * file:     plist_battle_p08.c
 * unit:     yes
 * function: func_021BB2E0, func_021BB30C, func_021BB358, func_021BB3C4, func_021BB3D4, func_021BB3FC, func_021BB43C, func_021BB440, func_021BB464, func_021BB468, func_021BB46C, func_021BB4A0, func_021BB554, func_021BB56C, func_021BB594, func_021BB5FC, func_021BB644, func_021BB714, func_021BB7A4, func_021BB7D8
 * address:  0x021BB2E0
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
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_021BAAE4 0x021BAAE4 thumb ov091
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021BB050  0x021BB050  thumb  ov091
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021B9A84 0x021B9A84 thumb ov091
 *   func_02019DA4 0x02019DA4 thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_0204B0C8 0x0204B0C8 arm
 *   func_02030734  0x02030734  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   sub_0203101C   0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   d_021BED28     0x021BED28  data  ov091  a1
 *   func_0202F038  0x0202F038  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202865C 0x0202865C thumb
 *   func_02045334 0x02045334 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_020450F0  0x020450F0  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021BBA28  0x021BBA28  thumb  ov091
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 */
#include "../../matched/include/Obj20879.h"
#include "../../matched/include/Obj20880.h"
#include "../../matched/include/Obj13251.h"
#include "../../matched/include/Obj20884.h"
#include "../../matched/include/Obj03680.h"
#include "../../matched/include/Obj20885.h"
#include "../../matched/include/Obj20886.h"
#include "../../matched/include/Obj20887.h"

#define W(o) (*(u32 *)(s+(o)))
struct Descriptor;
struct Bmp;
struct Owner;
struct Pt;
struct Tcbl;
struct PrintSys;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Blk;
struct Cfg;
struct Ctx;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef struct {
    int obj;
    u16 pad4;
    u16 lo;
    u16 hi;
} S_021BB30C;

typedef signed short s16;

typedef struct S_021BB358 {
    u8 pad[6];
    u16 a;
    u16 b;
} S_021BB358;

typedef struct { short x,y; } Pair;

typedef signed int     s32;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_021BAAE4(u8 *,u8 *,int);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_021BB050(int unused, u8 *s, int k);
extern void func_021BB2C0(u8 *a, u8 *s);
extern int func_021B9A84(u32 p);
extern int func_02019DA4(void *a, void *b);
extern int func_0202D034(u32 a, u32 b);
extern void func_0204B0C8(struct Owner *owner, u32 index, struct Pt *out);
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct Tcbl *sub_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(int a, int b, int c, u16 d);
extern u32 func_0201C440(void *p);
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern u32 func_020307B0(void *p);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32);
extern void func_0202865C(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021BBA28(int a, int b);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
void func_021BB2E0(u8 *a,u8 *s);
void func_021BB30C(u8 *a, S_021BB30C *s);
int func_021BB358(u8 *p, S_021BB358 *s);
int func_021BB3C4(void *unused, u32 p);
void func_021BB3D4(void *a,u8 *s,u16 *out);
void func_021BB3FC(int unused, u8 *s, u8 *out);
int func_021BB43C(int *p);
void func_021BB440(u8 *p, u32 *q, int v);
unsigned short func_021BB464(int unused, unsigned short *p);
int func_021BB468(int unused, int *p);
void func_021BB46C(u8 *p, u32 *q);
int func_021BB4A0(u8 *p, int *s);
int func_021BB554(u32 p);
void func_021BB56C(u32 p,int x,int y,u16 *out);
u32 *func_021BB594(u16 *h);
void func_021BB5FC(void *a, int *s);
void func_021BB644(u8 *p,u8 *s);
void func_021BB714(void *a, u32 *s, u32 k);
void func_021BB7A4(void *p,u32 *s);
int func_021BB7D8(void *unused, u32 p);
extern u8 d_021BEC74[];
extern u8 d_021BEC75[];
extern u8 d_021BED28[];

void func_021BB2E0(u8 *a,u8 *s) {func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj20879 *)s)->f20)),0,26,128,22,0);func_021BAAE4(a,s,1);}


void func_021BB30C(u8 *a, S_021BB30C *s)
{
    s->hi = func_02017E1C((void *)s->obj, 0xa0, 0);
    ((s8 *)a)[0x11e] = (s->hi - s->lo) / 100;
    if (s->hi > s->lo)
        ((s8 *)a)[0x11e] = ((s8 *)a)[0x11e] + 1;
    else
        ((s8 *)a)[0x11e] = ((s8 *)a)[0x11e] - 1;
}


int func_021BB358(u8 *p, S_021BB358 *s)
{
    if (s->a < s->b) {
        if (s->a == 0) {
            func_021BB050((int)p, (u8 *)s, 6);
        }
        {
            u16 cur = s->a;
            signed char st = p[0x11E];
            u16 lim = s->b;
            if (cur + st > lim) {
                s->a = lim;
            } else {
                s->a = cur + (u16)st;
            }
        }
        func_021BB2E0(p, (u8 *)s);
        return 0;
    }
    if (s->a > s->b) {
        signed char st = p[0x11E];
        if (s->a + st < s->b) {
            s->a = s->b;
        } else {
            s->a = s->a + (u16)st;
        }
        func_021BB2E0(p, (u8 *)s);
        return 0;
    }
    return 1;
}

int func_021BB3C4(void *unused, u32 p) { if (((struct Obj20880 *)p)->f14 != 1) return 1; return 0; }

void func_021BB3D4(void *a,u8 *s,u16 *out) { out[0]=(d_021BEC74[s[4]*2]+8)<<3; out[1]=(d_021BEC75[s[4]*2]+3)<<3; }


void func_021BB3FC(int unused, u8 *s, u8 *out)
{
    out[2] = d_021BEC74[s[4] * 2] << 3;
    out[0] = d_021BEC75[s[4] * 2] << 3;
    out[3] = (d_021BEC74[s[4] * 2] + 16) << 3;
    out[1] = (d_021BEC75[s[4] * 2] + 6) << 3;
}

int func_021BB43C(int *p)
{
    return p[7];
}

void func_021BB440(u8 *p, u32 *q, int v)
{
    if (q[7] != v) {
        if (v < 6) {
            q[7] = v;
        } else {
            func_021BB46C(p, (u32 *)q);
        }
        func_021BB2C0(p, (u8 *)q);
    }
}

unsigned short func_021BB464(int unused, unsigned short *p)
{
    (void)unused;
    return p[3];
}

int func_021BB468(int unused, int *p)
{
    (void)unused;
    return p[3];
}

void func_021BB46C(u8 *p, u32 *q)
{
    if (func_021B9A84((u32)p) == 0) {
        q[7] = 8;
        return;
    }
    if (func_02019DA4(*(void **)(*(u8 **)(p + 0x280) + 0x14), (void *)q[0]) == 0) {
        q[7] = 6;
        return;
    }
    q[7] = 7;
}


int func_021BB4A0(u8 *p, int *s)
{
    int a;
    int b;
    u8 *q;
    u8 i;

    if (s[7] != 6) {
        return 1;
    }
    i = 0;
    a = func_02017E1C((void *)s[0], 5, 0);
    b = func_02017E1C((void *)s[0], 6, 0);
    q = *(u8 * *)&((struct Obj20884 *)(*(u8 * *)&((struct Obj13251 *)p)->f280))->f14;
    do {
        u8 v;
        v = (*(u8 **)(p + 0x280))[i + 0x49];
        if (v >= 1) {
            void *e = **(void ***)(p + 0x15C + v * 4);
            int x = func_02017E1C(e, 5, 0);
            int y = func_02017E1C(e, 6, 0);
            if (a == x && q[8] == 0) {
                return 2;
            }
            if (b == y && b != 0 && q[9] == 0) {
                return 3;
            }
        }
        i = i + 1;
    } while (i < 6);
    if (p[0x105] == q[3]) {
        return 4;
    }
    return 0;
}

int func_021BB554(u32 p) { return func_0202D034(((struct Obj03680 *)p)->f6,func_02017E1C(((struct Obj03680 *)p)->f0,0xa1,0)); }

void func_021BB56C(u32 p,int x,int y,u16 *out) { Pair pos; func_0204B0C8((struct Owner *)(((struct Obj20885 *)p)->f24),0,(struct Pt *)(&pos)); out[0]=x-pos.x; out[1]=y-pos.y; }


u32 *func_021BB594(u16 *h)
{
    u32 *r;
    u32 z;

    r = func_02030734(*h, 0x38, 0, (const char *)d_021BED28, 0x64);
    z = 0;
    func_0201F5BC(0, 1, 0xc, 0, *h);
    r[2] = (u32)sub_0203101C(*h, *h, 1, 0);
    r[3] = z;
    r[0] = 4;
    r[9] = z;
    r[8] = z;
    r[11] = z;
    r[13] = z;
    r[12] = z;
    r[5] = func_02028590(0xf, 1, 1, *h);
    r[10] = func_0201C440((void *)(*h));
    return r;
}


void func_021BB5FC(void *a, int *s)
{
    if (s[0] != 4) {
        func_021BB7A4(a, (u32 *)s);
    }
    if (s[13] != 0) {
        func_0202F038((u8 *)s[13]);
    }
    if (s[3] != 0) {
        func_0201CE48((struct Rec3 *)s[3]);
        func_02045808((struct U16Vec *)s[4]);
    }
    func_0201C6EC((struct PrintSys *)s[10]);
    func_0201C4C0((struct PrintSys *)s[10]);
    func_02028604(s[5]);
    func_02031140((struct S02031140 *)s[2]);
    func_020307B0(s);
}

void func_021BB644(u8 *p,u8 *s)
{
    func_020310C4((struct Tcbl *)W(8));
    if (W(0xc) != 0) {
        func_020286C4((struct Ctx *)W(0x14),(void *)W(0xc),(void *)W(4));
        if (func_02028484((struct Blk *)(s+0x18),(void *)W(0xc)) == 1) {
            if (W(0x20) == 0 || (func_020362DC() & 3) != 0 || func_02035C60() == 1) {
                if (W(0x20) == 1) func_020061E4(0x547);
                func_0201CE48((struct Rec3 *)W(0xc));
                W(0xc)=0;
                func_02045808((struct U16Vec *)W(0x10));
            } else {
                func_0202865C((struct Ctx *)W(0x14),(const struct Bmp *)((u32)func_02045770((struct Descriptor *)W(4))),15);
                func_02045334((struct Descriptor *)W(4));
            }
        }
    }
    if (W(0x24) == 1 && func_0201C6C4((struct PrintSys *)W(0x28),(void *)((u32)func_02045770((struct Descriptor *)W(4)))) == 0) {
        u32 t=W(4);
        W(0x24)=0;
        func_02045334((struct Descriptor *)t);
        func_02045374((struct Cfg *)t);
        func_02041B6C(func_02045730((struct Descriptor *)t));
        if (W(0x30) == 1) {
            W(0x30)=0;
            W(0x34)=(u32)func_0202EE8C(W(8),(void *)W(4),15,16,((struct Obj20886 *)p)->f0);
        }
    }
    func_0201C4E4((struct PrintSys *)W(0x28));
}


void func_021BB714(void *a, u32 *s, u32 k)
{
    s[0] = k;
    switch (k) {
    case 0:
        s[1] = func_020450F0(0, 1, 0x15, 0x15, 2, 0xe, 1);
        break;
    case 1:
        s[1] = func_020450F0(0, 1, 0x15, 0x14, 2, 0xe, 1);
        break;
    case 2:
        s[1] = func_020450F0(0, 2, 0x13, 0xe, 4, 0xe, 1);
        break;
    case 3:
        s[1] = func_020450F0(0, 2, 0x13, 0x1c, 4, 0xe, 1);
        break;
    }
    func_0201F73C((void *)s[1], 1, 1, 0xc);
    func_021BBA28((int)a, (int)s);
}

void func_021BB7A4(void *p,u32 *s) { if(s[0]!=4) { if(s[13]!=0) {func_0202F038((u8 *)s[13]);s[13]=0;} func_0201F7A8((void *)s[1],1); func_020452E8((struct Descriptor *)s[1]); func_0201C6EC((struct PrintSys *)s[10]); s[0]=4; } }

int func_021BB7D8(void *unused, u32 p) { if (((struct Obj20887 *)p)->f0 != 4) return 1; return 0; }
