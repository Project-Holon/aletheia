/*
 * file:     plist_battle_p09.c
 * unit:     yes
 * function: func_021BB7E8, func_021BB860, func_021BB8FC, func_021BB910, func_021BB97C, func_021BB98C, func_021BB99C, func_021BB9AC, func_021BB9CC, func_021BB9DC, func_021BB9EC, func_021BBA0C, func_021BBA28, func_021BBA54, func_021BBA68, func_021BBA70, func_021BBA8C, func_021BBAE0, func_021BBAF8, func_021BBB40
 * address:  0x021BB7E8
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
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028470  0x02028470  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02006238  0x02006238  thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF4C 0x0201EF4C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F140 0x0201F140 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02028618 0x02028618 thumb
 *   func_02030734  0x02030734  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02049DB4  0x02049DB4  arm
 *   d_021BED38     0x021BED38  data  ov091  a1
 *   func_020307B0 0x020307B0 arm
 *   func_021BBC04  0x021BBC04  thumb  ov091
 *   func_020355D8  0x020355D8  arm
 *   func_02027778  0x02027778  thumb
 *   d_021BEC80     0x021BEC80  data  a4
 */
#include "../../matched/include/Obj09930.h"
#include "../../matched/include/Obj06213.h"
#include "../../matched/include/Obj13252.h"
#include "../../matched/include/Obj20889.h"
#include "../../matched/include/Obj13253.h"
#include "../../matched/include/Obj20890.h"
#include "../../matched/include/Obj20891.h"
#include "../../matched/include/Obj20892.h"
#include "../../matched/include/Obj20893.h"
#include "../../matched/include/Obj20894.h"
#include "../../matched/include/Obj20895.h"
#include "../../matched/include/Obj20896.h"
#include "../../matched/include/Obj03681.h"
#include "../../matched/include/Obj20898.h"
#include "../../matched/include/Obj09931.h"
#include "../../matched/include/Obj20900.h"
#include "../../matched/include/Obj09933.h"
#include "../../matched/include/Obj13254.h"
#include "../../matched/include/Obj07734.h"
#include "../../matched/include/Obj13255.h"

struct MsgBank;
struct PrintSys;
struct U16Vec;
struct WordSet;
struct Descriptor;
struct Rec;
struct Rec3;
struct Cfg;
struct CharBuf;
struct Bmp;
struct Ctx;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed int     s32;

typedef struct Req {
    u32 heap;
    u8 v;
    u8 *p;
    u32 one;
    u8 c[4];
} Req;

typedef struct Tbl {
    u32 a;
    u32 b;
    u32 c;
} Tbl;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02028470(u8 *p, u32 v);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int a, int b);
extern void func_020061E4(u32 a);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern int func_02006238(void);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF4C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F140(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern u32 func_020275E4(void);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 func_020307B0(void *p);
extern void func_021BBC04(u8 *a, u8 *b, int *items);
extern void func_020355D8(u32 a);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
void func_021BB7E8(u8 *a, u32 *s, u32 x);
void func_021BB860(u8 *a, u32 *s, u32 x, u32 y);
int func_021BB8FC(void *unused, u32 p);
int func_021BB910(int k);
void func_021BB97C(u16 *p,u32 s);
void func_021BB98C(void *p,u32 s);
void func_021BB99C(int a,int b,int c,int d);
void func_021BB9AC(int a,int b,int c,int d);
void func_021BB9BC(int a, u32 b, u32 c, int d);
void func_021BB9CC(int a,int b,int c,int d);
void func_021BB9DC(int a,int b,int c,int d);
void func_021BB9EC(int a,int b,int c,int d,unsigned char e);
void func_021BBA0C(int a,int b,int c,const void *d,int e);
void func_021BBA28(int a,int b);
void func_021BBA54(unsigned short *a, u32 b);
void func_021BBA68(u8 *p, u8 *s);
void func_021BBA70(int a,int b);
u32 *func_021BBA8C(u16 *h);
void func_021BBAE0(int a,unsigned char *b);
void func_021BBAF8(u8 *a, u8 *b, int *items);
void func_021BBB40(u8 *a, u8 *b);
extern u8 d_021BED38[];
extern Tbl d_021BEC80;


void func_021BB7E8(u8 *a, u32 *s, u32 x)
{
    u32 t;
    u32 n;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj09930 *)a)->f134), x);
    if (s[11] != 0) {
        n = (u32)func_020457B0(0x100, ((struct Obj09930 *)a)->f0);
        func_0201F250((struct WordSet *)s[11], (void *)n, (void *)t);
        func_02045808((struct U16Vec *)t);
        t = n;
    }
    func_021BBA28((int)a, (int)s);
    func_0201C6EC((struct PrintSys *)s[10]);
    func_0201C724((void *)s[10], (u32)func_02045770((struct Descriptor *)s[1]), 1, 1, t, ((struct Obj09930 *)a)->f138, 0x440);
    s[9] = 1;
    func_02045808((struct U16Vec *)t);
}


void func_021BB860(u8 *a, u32 *s, u32 x, u32 y)
{
    u32 t;
    u32 n;

    t = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06213 *)a)->f134), x);
    if (s[11] != 0) {
        n = (u32)func_020457B0(0x100, ((struct Obj06213 *)a)->f0);
        func_0201F250((struct WordSet *)s[11], (void *)n, (void *)t);
        func_02045808((struct U16Vec *)t);
        t = n;
    }
    func_021BBA28((int)a, (int)s);
    if (s[3] != 0) {
        func_0201CE48((struct Rec3 *)s[3]);
        func_02045808((struct U16Vec *)s[4]);
    }
    s[8] = y;
    s[4] = t;
    func_02028470((u8 *)(s + 6), 6);
    s[3] = (u32)func_0201CD10(s[1], 0, 0, s[4], ((struct Obj06213 *)a)->f138, func_02012FFC(), s[2], 0,
                         ((struct Obj06213 *)a)->f0, 0xf, (u32)func_021BB910);
}

int func_021BB8FC(void *unused, u32 p) { if (((struct Obj13252 *)p)->fC==0 && ((struct Obj13252 *)p)->f24==0) return 1; return 0; }


int func_021BB910(int k)
{
    switch (k) {
    case 2:
        func_02005DE4((void *)1);
        func_02005E64();
        func_02005D90(0x515, 0xffff);
        break;
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
            return 0;
        }
        return 1;
    case 6:
        return func_02006238();
    }
    return 0;
}

void func_021BB97C(u16 *p,u32 s) { ((struct Obj20889 *)s)->f2C=(u32)func_0201EC64(*p); }

void func_021BB98C(void *p,u32 s) { func_0201ED04((struct WordSet *)(((struct Obj13253 *)s)->f2C)); ((struct Obj13253 *)s)->f2C=0; }

void func_021BB99C(int a,int b,int c,int d) {func_0201EEF4(((struct Obj20890 *)b)->f2C,c,(void *)d);}

void func_021BB9AC(int a,int b,int c,int d) {func_0201EF40((struct WordSet *)(((struct Obj20891 *)b)->f2C),c,d);}

void func_021BB9BC(int a, u32 b, u32 c, int d) {func_0201EF4C((struct WordSet *)(((struct Obj20892 *)b)->f2C),c,d);}

void func_021BB9CC(int a,int b,int c,int d) {func_0201EF34((struct WordSet *)(((struct Obj20893 *)b)->f2C),c,d);}

void func_021BB9DC(int a,int b,int c,int d) {func_0201F140((struct WordSet *)(((struct Obj20894 *)b)->f2C),c,(unsigned char)d);}

void func_021BB9EC(int a,int b,int c,int d,unsigned char e) {func_0201EFA4((struct WordSet *)(((struct Obj20895 *)b)->f2C),c,d,e,0,1);}

void func_021BBA0C(int a,int b,int c,const void *d,int e) {func_0201EE0C((struct WordSet *)(((struct Obj20896 *)b)->f2C),c,d,e,1,2);}

void func_021BBA28(int a,int b) {unsigned int q; func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03681 *)b)->f4)),15); q=((struct Obj03681 *)b)->f4; func_02045334((struct Descriptor *)q);func_02045374((struct Cfg *)q);func_02041B6C(func_02045730((struct Descriptor *)q));}

void func_021BBA54(unsigned short *a, u32 b) {func_0201F5BC(0,1,12,0,*a);}


/*
 * Unlabelled store-and-return leaf (listed as .word at 0x021BBA68) called
 * from func_021B68F0 with (p, *(p + 0x150)).
 */
void func_021BBA68(u8 *p, u8 *s)
{
    ((struct Obj20898 *)s)->f30 = 1;
}

void func_021BBA70(int a,int b) {func_02028618((struct Ctx *)(((struct Obj09931 *)b)->f14),(const struct Bmp *)((unsigned int)func_02045770((struct Descriptor *)((struct Obj09931 *)b)->f4)),15);func_02045334((struct Descriptor *)((struct Obj09931 *)b)->f4);}


u32 *func_021BBA8C(u16 *h)
{
    u32 *r;

    r = func_02030734(*h, 0x84, 0, (const char *)d_021BED38, 0x63);
    func_02049B40(func_020275E4(), 0x1f, 0, 0x20, 0x40, *h);
    r[0x20] = (u32)func_02049DB4(func_020275E4(), 0x20, 0, (u32)((void **)&r[0x1f]), *h);
    return r;
}

void func_021BBAE0(int a,unsigned char *b) {func_020307B0(((struct Obj20900 *)b)->f80);func_020307B0(b);}


void func_021BBAF8(u8 *a, u8 *b, int *items)
{
    Req r;

    func_021BBC04(a, b, items);
    r.heap = ((struct Obj09933 *)a)->f0;
    r.v = b[0];
    r.p = b + 0x14;
    r.one = 1;
    r.c[0] = 0x20;
    r.c[1] = 0x18;
    r.c[2] = 0xd;
    r.c[3] = 3;
    func_020355D8(((struct Obj09933 *)a)->f8);
    ((struct Obj13254 *)b)->f74 = (int)func_02027778((struct TaskMenuTmpl *)(&r), (void *)(((struct Obj09933 *)a)->f254));
}


void func_021BBB40(u8 *a, u8 *b)
{
    Req r;
    Tbl t = d_021BEC80;

    func_021BBC04(a, b, (int *)(&t));
    r.heap = ((struct Obj07734 *)a)->f0;
    r.v = b[0];
    r.p = b + 0x14;
    r.one = 1;
    r.c[0] = 0x20;
    r.c[1] = 0x12;
    r.c[2] = 8;
    r.c[3] = 3;
    func_020355D8(((struct Obj07734 *)a)->f8);
    ((struct Obj13255 *)b)->f74 = (int)func_02027778((struct TaskMenuTmpl *)(&r), (void *)(((struct Obj07734 *)a)->f254));
}
