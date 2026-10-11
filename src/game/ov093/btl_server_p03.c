/*
 * file:     btl_server_p03.c
 * unit:     yes
 * function: func_021BC418, func_021BC4DC, func_021BC550, func_021BC55C, func_021BC568, func_021BC610, func_021BC874, func_021BC8EC, func_021BC948, func_021BCA08, func_021BCA50, func_021BCAAC, func_021BCB14, func_021BCB68, func_021BCB98, func_021BCC50, func_021BCCE0, func_021BCEFC, func_021BCF34, func_021BCF70, func_021BCFAC, func_021BD080, func_021BD0C0, func_021BD148, func_021BD170, func_021BD1B0, func_021BD1D0, func_021BD1E0, func_021BD200, func_021BD2B4, func_021BD338, func_021BD34C, func_021BD3E8, func_021BD43C, func_021BD4E4, func_021BD518, func_021BD554, func_021BD584, func_021BD60C, func_021BD6B8, func_021BD708, func_021BD850, func_021BD8AC, func_021BD8F0, func_021BD9D4, func_021BDA00
 * address:  0x021BC418
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021B9C50  0x021B9C50  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C5108  0x021C5108  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021D8548  0x021D8548  thumb  ov093
 *   func_021DCFB4  0x021DCFB4  thumb  ov093
 *   func_021BC4CC  0x021BC4CC  thumb  ov093
 *   func_021BC540  0x021BC540  thumb  ov093
 *   func_021BB930  0x021BB930  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E02DC  0x021E02DC  thumb  ov093
 *   func_021C6394  0x021C6394  thumb  ov093
 *   func_021E0394  0x021E0394  thumb  ov093
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021BB8A8  0x021BB8A8  thumb  ov093
 *   func_021BB8B0  0x021BB8B0  thumb  ov093
 *   func_021D83E0  0x021D83E0  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021C6350  0x021C6350  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021D8340  0x021D8340  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C859C 0x021C859C thumb ov093
 *   func_021BCEEC 0x021BCEEC thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021BDE98 0x021BDE98 thumb ov093
 *   func_021CB730 0x021CB730 thumb ov093
 *   func_021BDC98 0x021BDC98 thumb ov093
 *   func_021C54BC 0x021C54BC thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021C85B8 0x021C85B8 thumb ov093
 *   func_02018480 0x02018480 thumb
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021B85A0 0x021B85A0 thumb ov093
 *   func_02018488 0x02018488 thumb
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021BDE48  0x021BDE48  thumb  ov093
 *   func_021BD138  0x021BD138  thumb  ov093
 *   func_021D82FC  0x021D82FC  thumb  ov093
 *   func_021BD264  0x021BD264  thumb  ov093
 *   func_021BD274  0x021BD274  thumb  ov093
 *   func_021BD284  0x021BD284  thumb  ov093
 *   func_021BD294  0x021BD294  thumb  ov093
 *   func_021BD2A4  0x021BD2A4  thumb  ov093
 *   func_021BB878  0x021BB878  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021BD4D4  0x021BD4D4  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021B902C 0x021B902C thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021D8244 0x021D8244 thumb ov093
 *   func_021BD89C  0x021BD89C  thumb  ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021B8750 0x021B8750 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021DCF5C 0x021DCF5C thumb ov093
 *   func_021D63EC 0x021D63EC thumb ov093
 *   func_021D6580 0x021D6580 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021BD9C4 0x021BD9C4 thumb ov093
 *   func_021BDB28 0x021BDB28 thumb ov093
 *   func_021BDB38 0x021BDB38 thumb ov093
 *   func_021BDB48 0x021BDB48 thumb ov093
 *   func_021BDBEC 0x021BDBEC thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021BDB58 0x021BDB58 thumb ov093
 *   func_021BDB68 0x021BDB68 thumb ov093
 *   func_021BDB88 0x021BDB88 thumb ov093
 *   func_021BDB78 0x021BDB78 thumb ov093
 *   func_021BDC0C 0x021BDC0C thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21043.h"
#include "../../matched/include/Obj13305.h"
#include "../../matched/include/Obj13306.h"

struct Unk021D62A8;
struct S2;
struct UtilWork;
struct Unk021BDE48;
struct Unk021D82FC;
struct B;
struct Arr;
typedef unsigned char u8;

typedef unsigned int u32;

struct Slot {
    u32 kind : 3;
    u32 rest : 29;
};

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    struct { u32 type:4, select:3, move:3, rest:22; } small;
} Action;

typedef struct {
    u8 *a;      /* 0x0 */
    Action b;   /* 0x4 */
    u32 c;      /* 0x8 */
    u8 d;       /* 0xc */
    u8 done;    /* 0xd */
    u8 f;       /* 0xe */
    u8 pad;     /* 0xf */
} Entry;

/* Same layout as Entry. Reading e[l].b through this second type keeps mwcc from reusing r->b; the bytes need that reload. */
typedef struct { u8 *a; Action b; u32 c; u8 d; u8 done; u8 f; u8 pad; } EntryAlt;

typedef struct {
    u8 *f0;                         /* 0x000 */
    void *f4;                       /* 0x004 */
    void *f8;                       /* 0x008 */
    void *fC;                       /* 0x00c */
    u32 f10;                        /* 0x010 */
    u32 f14;                        /* 0x014 */
    u8 pad18[0x4b8 - 0x18];
    u8 w4b8[0x782 - 0x4b8];         /* 0x4b8 */
    u8 n;                           /* 0x782 */
    u8 pad783;
    u8 f784;                        /* 0x784 */
    u8 pad785;
    u8 f786;                        /* 0x786 */
    u8 pad787[3];
    union {
        u8 raw;
        struct { u8 b0:1, b1:1, b2:1, rest:5; } bits;
    } f78a;                         /* 0x78a */
    u8 f78b[0x7c1 - 0x78b];         /* 0x78b */
    u8 flags[0x7e0 - 0x7c1];        /* 0x7c1 */
    Entry e[6];                     /* 0x7e0 */
    Entry t;                        /* 0x840 */
    u8 pad850[0x1ab8 - 0x850];
    u8 w1ab8[0x1d74 - 0x1ab8];      /* 0x1ab8 */
    u32 lock;                       /* 0x1d74 */
    u8 pad1d78[0x1f78 - 0x1d78];
    int f1f78;                      /* 0x1f78 */
    u8 pad1f7c[0x1fe8 - 0x1f7c];
    u8 f1fe8;                       /* 0x1fe8 */
} Server;

typedef struct { u32 x; void *m; } Q;

struct Unk021BD1E0 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Unk021BD200 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Cursor { u8 a, b, c, d; };

enum Offset { queue = 0x1a68 };

extern char *func_021B9AEC(char *p, int i);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021B9C50(u8 **p, int k, u8 **o1, u8 **o2);
extern int func_021D5B68(void *p);
extern void func_021C5108(u8 *p, u8 *a, int b);
extern int func_021EF948(int k);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021D8548(void *p);
extern void func_021DCFB4(void *p);
extern void func_021BC4CC(u8 *p, int a, int b, u8 *c, u8 *d);
extern u8 func_021BC540(u8 *p, u8 i, u8 *buf);
extern void func_021BB930(u8 *p, u32 value);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
extern void func_021C6394(Server *p, u8 *a, unsigned int n);
extern void func_021E0394(u8 *a, int b);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern u8 func_021BB8A8(u8 *p, u8 i);
extern Action func_021BB8B0(u8 *p, u8 i, u8 j);
extern int func_021D83E0(Action *p);
extern u32 func_021D8454(Action *);
extern u8 func_021B9AB0(u8 k);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern void *func_021B86B8(void ***p);
extern u8 func_021C6350(Server *p, u8 *a);
extern u32 func_021D78AC(u32 range);
extern u32 func_0201BD28(u32 v, u32 n);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern u32 func_021D7B10(u32 a, u32 b);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u32 func_021D8340(Action *m);
extern int func_021B9A24(u32 a, u32 b);
extern void func_021C859C(Server *);
extern int func_021BCEEC(void *, u8);
extern int func_021B86E4(unsigned int **p);
extern u8 func_021D69AC(u8 *, int);
extern void func_021C0780(Server *, u8 *, int, u8);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern u32 func_021B8588(void **p);
extern void func_021BDE98(Server *, u8 *, Action *, u32);
extern int func_021CB730(Server *, u8 *, u16, u8, u8);
extern void func_021BDC98(Server *p, u8 *a, u8 v);
extern void func_021C54BC(Server *, u8 *);
extern void func_021C60EC(Server *p, u8 *a, u32 n);
extern void func_021C85B8(Server *);
extern u8 func_021B8DDC(u32);
extern u8 func_021B8FF4(u8 *);
extern void *func_021D5844(void *);
extern int func_021B871C(char *);
extern int func_02018480(void *, int);
extern u8 func_021B85A0(u8 **p);
extern void func_021D7630(int key, u32 val);
extern u16 func_021BDE48(void *p, Action *m);
extern int func_021BD138(u8 *p, u32 k);
extern void func_021D82FC(Action *p, int sub);
extern int func_021BD264(int t);
extern u8 func_021BD274(u8 *p, u8 x);
extern int func_021BD284(int t);
extern u8 *func_021BD294(int t, int k);
extern u8 func_021BD2A4(u8 *p, u8 x);
extern u8 *func_021BB878(u8 *p, u32 i);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021B9C98(u8 *p, u32 v);
extern void func_021C5D88(Server *p, u8 *a, int b);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern void func_021BD4D4(u8 *p, int a, int b);
extern void func_021B9C10(u32 *p, int a, int b);
extern void func_021BA1B4(char **p, int i);
extern void func_021CD64C(void *w, u8 id, ...);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern int func_021D58A8(u8 *p, int k);
extern int func_021B902C(int, int);
extern u8 func_021B86C0(u8 **p);
extern void func_021D8244(struct B *p, int n);
extern void func_021BD89C(Server *p, u8 *a);
extern void func_021B9D10(char *a, struct Arr *arr, int k);
extern void func_021B8750(char *p, unsigned char k, void *m);
extern void *func_021D8484(void *a);
extern void *func_021DCF5C(void *p);
extern void func_021D63EC(u8 *p, u16 n);
extern void func_021D6580(void *);
extern int func_021B99B8(void *pp, unsigned int b);
extern void func_021BD9C4(void *, int, u8, void *);
extern void func_021BDB28(void *);
extern void func_021BDB38(void *, u8 *);
extern void func_021BDB48(void *, u8 *);
extern void func_021BDBEC(u8 *);
extern int func_021C88E4(u8 *);
extern void func_021BDB58(void *);
extern u8 *func_021BDB68(void *);
extern void func_021BDB88(u8 *, u8 *);
extern u8 *func_021BDB78(void *);
extern void func_021BDC0C(u8 *);
void func_021BC418(u8 *p, int a, int b);
int func_021BC4DC(u8 *p, u8 *out);
u8 *func_021BC550(Server *p);
u8 func_021BC55C(Server *p);
void func_021BC568(Server *p);
u8 func_021BC610(Server *p, u8 *o, Entry *e);
void func_021BC874(Entry *p, u32 n);
int func_021BC8EC(Server *p, u32 x, u8 *a);
u16 func_021BC948(Server *p, u8 *x, int flag);
Entry *func_021BCA08(Server *p, u8 x);
Entry *func_021BCA50(Server *p, Entry *cur, u32 x);
Entry *func_021BCAAC(Server *p, u8 x, u32 i);
Entry *func_021BCB14(Server *p, u8 x, u32 y);
int func_021BCB68(Server *p, Entry *cur);
int func_021BCB98(Server *p, Entry *cur, int start);
void func_021BCC50(Server *p, Entry *cur);
u32 func_021BCCE0(Server *p, Entry *e);
void func_021BCEFC(Server *p, u8 *a, u32 k);
void func_021BCF34(Server *p, u8 *a, u32 k);
void func_021BCF70(Server *p, u8 *a, u32 k);
int func_021BCFAC(Server *p, u8 *a);
int func_021BD080(Server *p, u8 *a);
int func_021BD0C0(Server *p, u8 x, u32 y);
int func_021BD148(Server *p, u8 x);
int func_021BD170(Server *p, u8 x);
int func_021BD1B0(Server *p, u8 x);
void func_021BD1D0(Server *p, u8 n);
void func_021BD1E0(struct Unk021BD1E0 *p);
void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t);
void func_021BD2B4(u8 *p, u8 **q);
void func_021BD338(u8 *p, Server *q);
int func_021BD34C(u8 *p, u8 **q, u8 **out);
void func_021BD3E8(Server *p, u8 *a);
void func_021BD43C(Server *p, int i, u8 a, u8 b, int c);
void func_021BD4E4(Server *p, int i, u8 a, u8 b);
void func_021BD518(Server *p, u8 *m);
void func_021BD554(Server *p, u8 *m);
int func_021BD584(Server *p, u8 *a);
int func_021BD60C(Server *p, u8 *a, u8 flag);
int func_021BD6B8(Server *p, u8 *a);
int func_021BD708(Server *p, u8 *a, int r, int z);
int func_021BD850(Server *p, u8 *a);
int func_021BD8AC(Server *p, u8 *a);
void func_021BD8F0(Server *p, u8 i, u8 a, u8 b);
void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
int func_021BDA00(u8 *p);









void func_021BC418(u8 *p, int a, int b)
{
    u8 *t;
    u8 *v1;
    u8 *v2;
    int k;

    if (b == 1)
        return;
    if (b == 0)
        return;
    t = (u8 *)func_021B9AEC((char *)(*(u8 * *)&((struct Obj00003 *)p)->f8), a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x48, a, b);
    func_021B9C50((u8 **)t, b, &v1, &v2);
    if (func_021D5B68(v1) == 0)
        func_021C5108(p, v1, 1);
    if (func_021D5B68(v2) == 0) {
        if (func_021EF948(2) != 0) {
            k = 0x20;
            if (func_021D62C4((struct Unk021D62A8 *)v2, k) != 0)
                func_021C5620(p, v2, k, 0);
            k = 0x1e;
            if (func_021D62C4((struct Unk021D62A8 *)v2, k) != 0)
                func_021C5620(p, v2, k, 0);
        }
        func_021D8548(v2);
        func_021DCFB4(v2);
    }
    func_021BC4CC(p + 0x1ab8, b, a, v2, *(u8 * *)&((struct Obj00003 *)p)->f8);
}









int func_021BC4DC(u8 *p, u8 *out)
{
    u8 buf[4];
    u8 i;
    u8 n;
    u8 j;
    int ok = 0;
    *out = 0;
    for (i = 0; i < 4; i++) {
        n = func_021BC540(p + 0x1ab8, i, buf);
        if (n != 0) {
            for (j = 0; j < n; j++)
                func_021BB930(((struct Obj21043 *)p)->f0, buf[j]);
            ok = 1;
            out[(*out)++ + 1] = i;
        }
    }
    return ok;
}









u8 *func_021BC550(Server *p)
{
    return p->w4b8;
}









u8 func_021BC55C(Server *p)
{
    return p->f784;
}









void func_021BC568(Server *p)
{
    u32 lk = func_021CC8D8(&p->lock, 1425);
    u32 i;
    for (i = 0; i < p->n; i++) {
        u16 id;
        u8 *a;
        Entry *e;
        e = &p->e[i];
        if (e->b.full.type == 1)
            id = e->b.full.move;
        else
            id = 0;
        if (id != 0) {
            a = p->e[i].a;
            if (func_021E02DC(a, id, func_021D59B4(a, 12))) {
                func_021C6394(p, a, id);
                func_021E0394(a, id);
            }
        }
    }
    func_021CC95C(&p->lock, lk, 0x5a0);
}









u8 func_021BC610(Server *p, u8 *o, Entry *e)
{
    u8 cnt;
    u32 k;
    u8 *a;
    u32 lock;
    u8 i;
    u8 j;
    u8 n;
    u32 flag;
    u8 l;
    Q *q;
    Entry *r;

    flag = 0;
    for (i = 0, cnt = 0; i < 4; i++) {
        q = (Q *)func_021BB85C(p->f0, i);
        if (q != 0) {
            u8 r5;
            n = func_021BB8A8(o, i);
            r5 = 0;
            for (j = 0; j < n; j++) {
                u32 t;
                r = &e[cnt];
                r->b = func_021BB8B0(o, i, j);
                if (func_021D83E0(&r->b) != 0)
                    break;
                t = func_021D8454(&r->b) & 0xff;
                switch (t) {
                case 6:
                    r5 = func_021B9AB0(r->b.full.select);
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    flag = 1;
                    break;
                case 3:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r->b.full.select);
                    r5++;
                    break;
                default:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    r5++;
                    break;
                }
                r->d = i;
                r->done = 0;
                r->f = 0;
                cnt++;
            }
        }
    }
    for (l = 0; l < cnt; l++) {
        u32 m = 0x1FFF;
        u8 r5;
        u32 sub;
        lock = func_021CC8D8(&p->lock, 0x678 - 0x38);
        r = &e[l];
        a = e[l].a;
        switch (r->b.full.type) {
        case 4:
            if (func_021B86B8((void ***)p->f4) == 0 && r->d == 1) {
                r5 = 0;
            } else {
                r5 = 4;
            }
            break;
        case 3:
            r5 = 3;
            break;
        case 2:
            r5 = 2;
            break;
        case 6:
            r5 = 1;
            break;
        case 7:
            r5 = 0;
            break;
        case 5:
            r5 = 0;
            break;
        case 1:
            r5 = 0;
            break;
        case 0:
            r->c = 0x01002000;
            continue;
        case 8:
            continue;
        default:
            r5 = 0;
            break;
        }
        if (r->b.full.type == 1) {
            u16 id;
            if (((EntryAlt *)e)[l].b.full.type == 1)
                id = ((EntryAlt *)e)[l].b.full.move;
            else
                id = 0;
            sub = func_021BC8EC(p, id, a);
        } else if (r->b.full.type == 5 || r->b.full.type == 7) {
            sub = 7;
        } else {
            sub = 0;
        }
        k = func_021BC948(p, a, 1);
        func_021CC95C(&p->lock, lock, 0x678);
        r->c = (k & m) | ((m + 1) | (((r5 & 7) << 22) | ((sub & 0x3f) << 16)));
    }
    func_021BC874(e, cnt);
    if (flag == 0) {
        for (i = 0; i < cnt; i++) {
            r = &e[i];
            if (r->b.full.type == 1 || r->b.full.type == 5) {
                u32 lock = func_021CC8D8(&p->lock, 0x68A);
                u32 v = func_021C6350(p, r->a);
                r->c = (r->c & 0xFFFF1FFF) | ((v & 7) << 13);
                func_021CC95C(&p->lock, lock, 0x68A + 3);
            }
        }
        func_021BC874(e, cnt);
    }
    return cnt;
}









void func_021BC874(Entry *p, u32 n)
{
    u32 i;
    u32 j;
    Entry *a;
    Entry *b;
    Entry t;
    for (i = 0; i < n; i++) {
        j = i + 1;
        if (j < n) {
            a = &p[i];
            do {
                b = &p[j];
                if (a->c <= b->c && (a->c != b->c || func_021D78AC(2) != 0)) {
                    t = *a;
                    *a = *b;
                    *b = t;
                }
                j++;
            } while (j < n);
        }
    }
}









int func_021BC8EC(Server *p, u32 x, u8 *a)
{
    u8 n = func_0201BD28(x, 6) + 7;
    u8 r;
    func_021D74F8(1735);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, x);
    func_021D75A8(0x18, n);
    func_021D70F0(p, 0x11);
    r = func_021D775C(0x18);
    func_021D7540(1741);
    return r;
}









u16 func_021BC948(Server *p, u8 *x, int flag)
{
    u32 r;
    int k = func_021D59B4(x, 0xc);
    int one;
    func_021D74F8(1760);
    func_021D75EC(2, func_021D5440(x));
    func_021D75EC(0x2f, k);
    one = 1;
    func_021D75A8(0x51, 1);
    func_021D75A8(0x4a, 0);
    func_021D7674(0x35, one << 12, 410, one << 17);
    func_021D70F0(p, 0x13);
    r = func_021D7B10(func_021D775C(0x2f), func_021D775C(0x35));
    if (func_021D62A8((struct Unk021D62A8 *)x) == 1 && func_021D775C(0x51) != 0)
        r = r * 25 / 100;
    if (r > 10000)
        r = 10000;
    if (flag != 0 && func_021D775C(0x4a) != 0)
        r = 10000 - r;
    func_021D7540(1792);
    return r;
}









Entry *func_021BCA08(Server *p, u8 x)
{
    u32 i;
    u32 y = x;
    for (i = 0; i < p->n; i++) {
        if (y == func_021D5440(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}









Entry *func_021BCA50(Server *p, Entry *cur, u32 x)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (&p->e[i] == cur) {
            i++;
            break;
        }
    }
    for (; i < p->n; i++) {
        if (x == func_021D5440(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}









Entry *func_021BCAAC(Server *p, u8 x, u32 i)
{
    for (; i < p->n; i++) {
        if (p->e[i].done == 0 && func_021D8454(&p->e[i].b) == 1 && x == func_021D8340(&p->e[i].b))
            return &p->e[i];
    }
    return 0;
}









Entry *func_021BCB14(Server *p, u8 x, u32 y)
{
    Entry *e = func_021BCAAC(p, x, 0);
    while (e) {
        if (func_021B9A24(y, func_021D5440(e->a)) && func_021D5B68(e->a) == 0)
            return e;
        e = func_021BCAAC(p, x, (u8)(func_021BCB68(p, e) + 1));
    }
    return 0;
}









/*
 * unlabelled leaf (push {r3, r4}); filed as the blocker of func_021BCB14.
 */
int func_021BCB68(Server *p, Entry *cur)
{
    int i;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur)
            return (u8)i;
    }
    return n;
}









int func_021BCB98(Server *p, Entry *cur, int start)
{
    int a = -1;
    int b = -1;
    int i;
    int n = p->n;
    for (i = start; i < n; i++) {
        if (&p->e[i] == cur) {
            a = i;
            break;
        }
    }
    for (; start < n; start++) {
        if (p->e[start].done == 0) {
            b = start;
            break;
        }
    }
    if (a >= 0 && b >= 0 && a > b) {
        p->t = *cur;
        for (i = a; i > b; i--)
            p->e[i] = p->e[i - 1];
        p->e[b] = p->t;
        return b;
    }
    return -1;
}









void func_021BCC50(Server *p, Entry *cur)
{
    int i;
    int idx = -1;
    int n = p->n;
    for (i = 0; i < n; i++) {
        if (&p->e[i] == cur) {
            idx = i;
            break;
        }
    }
    if (idx < 0)
        return;
    p->t = *cur;
    for (i = idx; i < p->n - 1; i++)
        p->e[i] = p->e[i + 1];
    p->e[i] = p->t;
}









/*
 * interface: CC8D8's own matched source returns one-word struct Lock;
 *   this caller treats all r0 bits as a raw u32, copies r0 to r6 at 021BCEA4,
 *   and forwards r6 unchanged in r1 at 021BCEB6 to CC95C (str r1,[r0]).
 *   CC8D8 returns the entire pre-mutation 32-bit word. No bit is interpreted,
 *   narrowed or changed; both line arguments and all arities are preserved.
 *   Matched BD708 uses this same scalar interface. Struct diagnostic run03
 *   adds 8 frame bytes; byte score is not the payload/effect equivalence proof.
 * lever: Union views preserve bits7..22 for the full move field and bits7..9
 *   for case3; arg is bits23..30. Wrapping arithmetic is never signed.
 * semantics: Packed word widths derive from listing shift pairs; all fields
 *   unsigned, no signed arithmetic or asserted external selector bounds.
 */
u32 func_021BCCE0(Server *p, Entry *e)
{
    u8 *a;
    Action b;
    u32 lock;
    if (e->done == 0) {
        a = e->a;
        b = e->b;
        func_021C859C(p);
        e->done = 1;
        if (p->f14 == 5 && b.full.type != 4) goto end;
        if (func_021D5B68(a) != 0) goto end;
        if (b.full.type != 6 && func_021BCEEC(p->w1ab8, func_021D5440(a)) == 0) goto end;
        if (func_021D62C4((struct Unk021D62A8 *)a, 0x21) != 0) {
            if (b.full.type != 4 || func_021B86E4((unsigned int **)p->f4) != 2) {
                if (func_021D69AC(a, 3) != 0) func_021C0780(p, a, 3, 0);
                goto end;
            }
        }
        func_021BCEFC(p, a, e->b.full.type);
        func_021D5FC0((struct UtilWork *)a, 0);
        switch (b.full.type) {
        case 6:
            if (func_021B8588((void **)p->f4) == 3) func_021BC418((u8 *)p, e->d, (u8)b.full.select);
            break;
        case 1:
            if (p->f1fe8 == 0) {
                func_021BC568(p);
                p->f1fe8 = 1;
            }
            p->f1f78 = func_021BCFAC(p, a);
            func_021BDE98(p, a, &b, e->c & 0x3fffff);
            break;
        case 2:
            if (func_021CB730(p, a, (u16)b.full.move, (u8)b.full.arg, (u8)b.full.select) == 1) {
                if (func_021BD708(p, a, 1, 1)) p->f14 = 5;
            }
            break;
        case 3:
            func_021BDC98(p, a, (u8)b.small.move);
            func_021BDA00((u8 *)p);
            break;
        case 4:
            if (func_021BD584(p, a)) p->f14 = 5;
            break;
        case 8:
            p->f14 = 4;
            break;
        case 5:
            func_021BD3E8(p, a);
            break;
        case 7:
            func_021C54BC(p, a);
            break;
        case 0:
        default:
            break;
        }
        if (b.full.type == 1 || b.full.type == 2) {
            func_021D5FC0((struct UtilWork *)a, 1);
            func_021C60EC(p, a, 0);
        }
        lock = func_021CC8D8(&p->lock, 0x83b);
        func_021BCF70(p, a, b.full.type);
        func_021CC95C(&p->lock, lock, 0x83d);
    end:
        func_021C85B8(p);
        return b.full.type;
    }
    return 0;
}








/*
 * interface: func_021CC8D8 returns its four-byte Lock in r0; use the
 * full-word payload spelling of matched caller func_021BC568. The entire
 * func_021CC95C body is str r1,[r0]; bx lr, retaining every payload bit.
 * Aggregate spelling added eight bytes of frame; paired fixed-flag
 * runs were DIFF (60 bytes) and EXACT (56 bytes). Calls and stores agree.
 */
void func_021BCEFC(Server *p, u8 *a, u32 k)
{
    int line = 0x854;
    u32 old = func_021CC8D8(&p->lock, line);
    func_021BCF34(p, a, k);
    func_021CC95C(&p->lock, old, line + 3);
}










void func_021BCF34(Server *p, u8 *a, u32 k)
{
    int line = 0x864;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(12, k);
    func_021D70F0(p, 1);
    func_021D7540(line + 4);
}










void func_021BCF70(Server *p, u8 *a, u32 k)
{
    int line = 0x874;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(12, k);
    func_021D70F0(p, 2);
    func_021D7540(line + 4);
}









/*
 * note 2026-10-05 (wD9r lane04): EXACT* (the trailing 021BD07E halfword is alignment padding). Closed
 *   with `r -= x - y; if (r < x - y) return 3;` in place of the one-expression
 *   `(u16)(r - (u16)(x - y)) < x - y`. The redefinition of r splits its live range, so the first use
 *   reloads the spilled r (`str r0,[sp]; ldr r0,[sp]`). No cast stand-in.
 * note 2026-10-05 (wD9 lane18): still DIFF 55 B (no stand-in). Reading: the first use of r must be an
 *   operation on the spilled r (the u16 to u32 widening node), not the call temp; any plain form forwards r0.
 *   Tried: a static inline u16 rnd(u32) for both random calls; operands reversed (x - y > r) in one and both
 *   compares; an int d = x - y block; r as u32 with (u16) at the def and (int)r at the compare (a real
 *   signedness cast, still forwards r0). All 55 B.
 * note 2026-10-05 (integrator): the source no longer has the (int)(u32)r stand-in cast, so it is DIFF (the plain compare drops the reload of r). With the cast it verifies EXACT*: rejected as a stand-in.
 * note 2026-10-05: witness src/matched/arm9/func_02018480.c filed (EXACT); the wildcard at +0x38 resolves after regeneration. The reload still needs the (int)(u32)r spelling, which is a no-op steering cast (stand-in, not accepted). Tried without it: u16 callee return type for func_021D78AC with plain compares, and an int local fed from the u16 return: both forward r0 and drop the ldr (200 bytes). Parked MATCH* because of the cast; reading: r is spilled for real (p,a,x,y fill r4..r7), so the original defines r with the store at the def and the reload at first use; no stand-in free source found.
 * evidence (older): every concrete byte matched (MATCH*, the trailing 021BD07E
 *   halfword is alignment padding). The one wildcard is +0x38, the bl to the
 *   ARM9 Thumb thunk func_02018480 (ldr r3,[pc]; bx r3; .word 0x02018489),
 *   which has no witness outside this range: label/sole-ref need an arm9
 *   label or a matched entry there. It is an arm9 leaf, Ilias's; its verified
 *   C is below. Once it is filed this caller re-runs to EXACT*.
 *   func_02018480 0x02018480 thumb, arm9; `one --thumb` (no --region): EXACT
 *     extern int func_02018488(void *p, int q);
 *     int func_02018480(void *p, int q)
 *     {
 *         return func_02018488(p, q);
 *     }
 *   (func_02018488 0x02018488 thumb resolves by label; it reads r0 and r1 and
 *   returns the 0/1 in r6.)
 * note: the reload `str r0,[sp]; ldr r0,[sp]` at 021BD046/021BD048 comes only
 *   from spelling the first use of r through a widening cast, `(int)(u32)r`;
 *   plain `r`, `(int)r` and u16/u32/int locals forward r0 into the compare
 *   and drop the ldr (55 bytes out), and `(u32)r` alone reloads but turns
 *   the bge into bhs.
 */
int func_021BCFAC(Server *p, u8 *a)
{
    int k;
    u32 n;
    u16 x, y;
    if ((u32)func_021B86B8((void ***)p->f4) <= 1) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4((u8 *)p->f4)) {
            void *v = func_021D5844(a);
            if (func_02018480(v, func_021B871C((char *)p->f4)) == 0) {
                n = func_021B85A0((u8 **)p->f4);
                if (n < 8) {
                    u16 r;
                    x = (u16)func_021D59B4(a, 15);
                    y = (u16)(10 * (n + 1));
                    if (x <= y) return 0;
                    if ((u16)func_021D78AC(x + y + 1) < y) return 0;
                    if (func_021D62C4((struct Unk021D62A8 *)a, 2) != 0) return 4;
                    r = func_021D78AC(256);
                    if (r < x - y && func_021BD080(p, a) == 0) return 2;
                    r -= x - y;
                    if (r < x - y) return 3;
                    return 4;
                }
            }
        }
    }
    return 0;
}









int func_021BD080(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2256);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0xe);
    r = func_021D775C(0x41);
    func_021D7540(2261);
    return r;
}









int func_021BD0C0(Server *p, u8 x, u32 y)
{
    Entry *e = func_021BCA08(p, x);
    if (e) {
        if (e->done != 0 && func_021D8454(&e->b) == 6) {
            e = func_021BCA50(p, e, x);
        }
        if (e->done == 0) {
            if (func_021BDE48(e->a, &e->b)) return 0;
            if (func_021D8454(&e->b) == 6) return 0;
            func_021D82FC(&e->b, func_021BD138(p->w1ab8, y));
            func_021BCCE0(p, e);
            return 1;
        }
    }
    return 0;
}






int func_021BD148(Server *p, u8 x)
{
    Entry *e = func_021BCA08(p, x);
    if (e && e->done == 0) {
        if (func_021BCB98(p, e, 0) >= 0) return 1;
    }
    return 0;
}






int func_021BD170(Server *p, u8 x)
{
    int i = 0;
    int r;
    Entry *e = func_021BCAAC(p, x, 0);
    r = 0;
    while (e) {
        i = func_021BCB98(p, e, i);
        if (i < 0) break;
        i++;
        e = func_021BCAAC(p, x, (u8)i);
        r = 1;
    }
    return r;
}






int func_021BD1B0(Server *p, u8 x)
{
    Entry *e = func_021BCA08(p, x);
    if (e && e->done == 0) {
        func_021BCC50(p, e);
        return 1;
    }
    return 0;
}






/* 021BD1D0  guard on a callee's pointer result, then set a byte */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl func_021BCA08; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */
void func_021BD1D0(Server *p, u8 n)
{
    Entry *e = func_021BCA08(p, n);
    if (e != 0)
        e->done = 1;
}






void func_021BD1E0(struct Unk021BD1E0 *p)
{
    p->f0 = 0;
    p->f2 = 6;
    p->f3 = 6;
    p->f4 = 0;
    p->b0 = 0;
    p->b1 = 0;
}






void func_021BD200(struct Unk021BD1E0 *p, Server *q, u8 *a, int t)
{
    int r = func_021BD264(t);
    p->f2 = func_021BD274(q->w1ab8, func_021D5440(a));
    p->f3 = 6;
    p->b0 = 0;
    p->b1 = 0;
    if (r == 1 && func_021BD284(t)) {
        p->f3 = func_021BD2A4(q->w1ab8, func_021D5440(func_021BD294(t, 0)));
    }
}







void func_021BD2B4(u8 *p, u8 **q)
{
    u8 i = 0;
    u8 *m;
    u8 j;
    u8 *x;
    int f;
    p[0] = i;
    p[1] = i;
    p[2] = 1;
    p[3] = i;
    for (; i < 4; i++) {
        m = func_021BB878(*q, i);
        if (m == 0) continue;
        for (j = 0; j < m[9]; j++) {
            x = func_021B9C00((struct S2 *)(*(u8 * *)&((struct Obj13305 *)m)->f4), j);
            if (x) f = func_021D5B68(x) == 0;
            else f = 0;
            if (f) {
                p[0] = i;
                p[2] = 0;
                p[1] = j;
                return;
            }
        }
    }
}






void func_021BD338(u8 *p, Server *q)
{
    if (func_021B8588(q->f4) == 3) p[3] = 1;
}







int func_021BD34C(u8 *p, u8 **q, u8 **out)
{
    u8 *m;
    u8 *x;
    u8 n;
    int f;
    if (p[2] != 0) return 0;
    *out = (u8 *)func_021B9BF0((struct S2 *)(*(u8 **)(func_021BB85C(*q, p[0]) + 4)), p[1]);
    p[1]++;
    while (p[0] < 4) {
        m = func_021BB878(*q, p[0]);
        if (m) {
            n = p[3] == 0 ? m[9] : 3;
            for (; p[1] < n; p[1]++) {
                x = (u8 *)func_021B9BF0((struct S2 *)(*(u8 * *)&((struct Obj13306 *)m)->f4), p[1]);
                if (x) f = func_021D5B68(x) == 0;
                else f = 0;
                if (f) return 1;
            }
        }
        p[0]++;
        p[1] = 0;
    }
    p[2] = 1;
    return 1;
}







void func_021BD3E8(Server *p, u8 *a)
{
    int i;
    int r;
    i = func_021B8DDC(func_021D5440(a));
    r = func_021B9C98((u8 *)func_021B9AEC((char *)p->f8, i), (u32)a);
    if (r == 0 || r == 2) {
        func_021BD43C(p, i, r, 1, 0);
        func_021C5D88(p, a, 0xe7);
        func_021BD4E4(p, i, r, 1);
    }
}






void func_021BD43C(Server *p, int i, u8 a, u8 b, int c)
{
    char *s = func_021B9AEC((char *)p->f8, i);
    int x = func_021B8BEC((u8 *)p->f4, i, a);
    int y = func_021B8BEC((u8 *)p->f4, i, b);
    u8 *q;
    u8 *r;
    func_021BD4D4(p->w1ab8, x, y);
    func_021B9C10((u32 *)s, a, b);
    if (c == 0) {
        func_021CD4B0(p->fC, 0x44, i, x, y);
        q = (u8 *)func_021B9BF0((struct S2 *)s, a);
        r = (u8 *)func_021B9BF0((struct S2 *)s, b);
        if (!func_021D5B68(q)) func_021D5FC0((struct UtilWork *)q, 0xc);
        if (!func_021D5B68(r)) func_021D5FC0((struct UtilWork *)r, 0xc);
    }
}







void func_021BD4E4(Server *p, int i, u8 a, u8 b)
{
    u8 *arr;
    u8 *first;
    u8 *second;
    arr = (u8 *)func_021B9AEC((char *)p->f8, i);
    first = func_021B9C00((struct S2 *)arr, a);
    second = func_021B9C00((struct S2 *)arr, b);
    func_021BD518(p, first);
    func_021BD518(p, second);
}







/*
 * return evidence: func_021CC8D8's matched Lock is one full 32-bit word;
 *   021CC8DA loads it, 021CC900 returns that unchanged word in r0.
 *   This caller saves r0 in r4 and passes it unchanged in r1 to restore.
 *   Scalar u32 return follows matched neighbours 021BD708/021BDA00;
 *   union aggregate spelling gave a spurious 8-byte stack frame (run 1).
 */
void func_021BD518(Server *p, u8 *m)
{
    u32 old;
    if (func_021D5B68(m) == 0) {
        old = func_021CC8D8(&p->lock, 2697);
        func_021BD554(p, m);
        func_021CC95C(&p->lock, old, 2699);
    }
}







void func_021BD554(Server *p, u8 *m)
{
    func_021D74F8(2712);
    func_021D75A8(2, func_021D5440(m));
    func_021D70F0(p, 164);
    func_021D7540(2715);
}








int func_021BD584(Server *p, u8 *a)
{
    int k = func_021B8DDC(func_021D5440(a));
    int m = func_021B8FF4((u8 *)p->f4);
    int s = func_021BD60C(p, a, 0);
    if (s) return 1;
    if (k == m) {
        func_021BA1B4((char **)p->f4, 0x4e);
        func_021CD64C(p->fC, 0x5a, 0x49, 0xffff0000);
    } else {
        func_021CD64C(p->fC, 0x5b, 0x36b, func_021D5440(a), 0xffff0000);
    }
    if (k == m) {
        p->f786++;
        if (p->f786 > 0x1e) p->f786 = 0x1e;
    }
    return s;
}








int func_021BD60C(Server *p, u8 *a, u8 flag)
{
    int ret = 0;
    int k;
    u8 *q;
    u16 lo;
    u16 hi;
    int d;
    u32 t;
    if (func_021B86E4((unsigned int **)p->f4) == 0) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4((u8 *)p->f4)) {
            ret = func_021BD6B8(p, a);
            if (ret) flag = 1;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
        ret = 1;
    }
    if (flag == 0) {
        q = func_021B9920(p->f8, 1, 0);
        if (q) {
            lo = func_021D58A8(a, 0xc);
            hi = func_021D58A8(q, 0xc);
            if (lo <= hi) {
                d = (((int)lo << 12) / (int)hi << 7) >> 12;
                t = d + p->f786 * 30;
                if (func_021D78AC(0x100) >= t) return 0;
            }
        }
    }
    return func_021BD708(p, a, ret, 0);
}








int func_021BD6B8(Server *p, u8 *a)
{
    int r;
    if (func_021D5B68(a) == 0) {
        func_021D74F8(2849);
        func_021D75EC(2, func_021D5440(a));
        func_021D7630(0x51, 0);
        func_021D70F0(p, 0xb);
        r = func_021D775C(0x51);
        func_021D7540(2854);
        return r;
    }
    return 0;
}






int func_021BD708(Server *p, u8 *a, int r, int z)
{
    int k = func_021B8DDC(func_021D5440(a));
    u8 f;
    if (func_021B86E4((unsigned int **)p->f4) == 0) {
        f = (u8)(func_021B902C(k, func_021B8FF4((u8 *)p->f4)) == 0 ? 1 : 0);
        if (r == 0 && func_021D5B68(a) == 0) {
            u32 l;
            l = func_021CC8D8(&p->lock, 2888);
            r = func_021BD850(p, a);
            func_021CC95C(&p->lock, l, 2890);
            if (r) return 0;
        }
        if (p->f78a.bits.b2 == 0) {
            if (z == 0) {
                u32 l;
                l = func_021CC8D8(&p->lock, 2904);
                r = func_021BD8AC(p, a);
                func_021CC95C(&p->lock, l, 2906);
            } else {
                r = 0;
            }
            if (r == 0) {
                if (f != 0) {
                    if (func_021B86B8((void ***)p->f4) == 0)
                        func_021CD64C(p->fC, 0x5c, 0x4b, 0x56a, func_021D5440(a), 0xffff0000);
                } else {
                    func_021CD64C(p->fC, 0x5c, 0x48, 0x56a, 0xffff0000);
                }
            }
            p->f78a.raw |= 4;
        }
    } else {
        if (func_021B86C0((u8 **)p->f4) != 0 && p->f78a.bits.b2 == 0) {
            func_021CD64C(p->fC, 0x5a, 0xc6, 0xffff0000);
            p->f78a.raw |= 4;
        }
    }
    func_021D8244((struct B *)(p->w4b8), k);
    return 1;
}





int func_021BD850(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2957);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021BD89C(p, a);
    func_021D70F0(p, 0xc);
    r = func_021D775C(0x41);
    func_021D7540(2963);
    return r;
}




int func_021BD8AC(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2979);
    func_021D75A8(2, func_021D5440(a));
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0xd);
    r = func_021D775C(0x51);
    func_021D7540(2984);
    return r;
}



void func_021BD8F0(Server *p, u8 i, u8 a, u8 b)
{
    char *arr;
    u8 *m;
    u8 id;
    u8 *flags;
    arr = func_021B9AEC((char *)p->f8, i);
    func_021CD4B0(p->fC, 42, i);
    func_021B9D10((char *)p->f4, (struct Arr *)arr, i);
    if (a != b) func_021B9C10((u32 *)arr, a, b);
    m = (u8 *)func_021B9BF0((struct S2 *)arr, a);
    id = func_021D5440(m);
    func_021B8750(p->f4, i, m);
    func_021D8484(m);
    func_021DCF5C(m);
    func_021D63EC(m, p->f10);
    func_021D6580(m);
    flags = p->flags;
    flags[id] = 1;
    if (func_021B8588(p->f4) == 3) {
        if ((u32)func_021B99B8(p->f4, (int)i) <= a) flags[id] = 0;
    }
    func_021CD4B0(p->fC, 18, i, a, b, (u16)p->f10);
    func_021BD9C4(p->w1ab8, func_021B8BEC((u8 *)p->f4, i, a), id, p->f8);
}


/*
 * extent: 42-byte function followed by 2-byte zero alignment padding.
 */
void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c)
{
    func_021BD8F0((Server *)p, i, a, b);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 61, i, a, b, (u8)c);
}


/*
 * lever: enum queue offset declared after the live locals retains r7;
 * cursor declared before out places cursor at sp+8 and out at sp+4.
 */
int func_021BDA00(u8 *p)
{
    int result = 0;
    struct Cursor cursor;
    u8 *out;
    u32 lock;
    u8 *flag;
    enum Offset q = queue;
    func_021BDB28(p + q);
    func_021BD2B4((u8 *)(&cursor), (u8 **)p);
    while (func_021BD34C((u8 *)(&cursor), (u8 **)p, &out) != 0) {
        flag = p + func_021D5440(out);
        if (flag[0x7c1] != 0) {
            func_021BDB38(p + q, out);
            flag[0x7c1] = 0;
        }
    }
    func_021BDB48(p + q, p);
    lock = func_021CC8D8(p + 0x1d74, 3096);
    func_021BDBEC(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 3102);
    func_021BDB58(p + q);
    out = func_021BDB68(p + q);
    while (out != 0) {
        lock = func_021CC8D8(p + 0x1d74, 3108);
        func_021BDB88(p, out);
        if (func_021C88E4(p) != 0) result = 1;
        func_021CC95C((u32 *)(p + 0x1d74), lock, 3114);
        out = func_021BDB78(p + q);
    }
    lock = func_021CC8D8(p + 0x1d74, 3117);
    func_021BDC0C(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 3123);
    return result;
}
