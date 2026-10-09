/*
 * file:     btl_server_p11.c
 * unit:     yes
 * function: func_021BD2B4, func_021BD338, func_021BD34C, func_021BD3E8, func_021BD43C
 * address:  0x021BD2B4
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
 *   func_021BB878  0x021BB878  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021BD4E4  0x021BD4E4  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021BD4D4  0x021BD4D4  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 */
#include "../../matched/include/Obj13305.h"
#include "../../matched/include/Obj13306.h"

struct S2;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

extern u8 *func_021BB878(u8 *p, u32 i);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *p);
extern u32 func_021B8588(void **p);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern char *func_021B9AEC(char *p, int i);
extern int func_021B9C98(u8 *p, u32 v);
extern void func_021C5D88(Server *p, u8 *a, int b);
extern void func_021BD4E4(Server *p, int i, u8 a, u8 b);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern void func_021BD4D4(u8 *p, int a, int b);
extern void func_021B9C10(u32 *p, int a, int b);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
void func_021BD2B4(u8 *p, u8 **q);
void func_021BD338(u8 *p, Server *q);
int func_021BD34C(u8 *p, u8 **q, u8 **out);
void func_021BD3E8(Server *p, u8 *a);
void func_021BD43C(Server *p, int i, u8 a, u8 b, int c);



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
