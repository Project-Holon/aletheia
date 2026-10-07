/*
 * file:     unit_021F39C0_p05.c
 * unit:     yes
 * function: func_021F4388, func_021F43D8, func_021F4430, func_021F4458, func_021F4474, func_021F4510, func_021F4530, func_021F4574, func_021F459C
 * address:  0x021F4388
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_021F45A4 0x021F45A4 thumb ov055
 *   func_02045C04 0x02045C04 arm
 *   func_02189A38  0x02189A38  thumb  ov021
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   d_021F45E0 0x021F45E0 data a1
 *   d_021F45D0 0x021F45D0 data a1
 *   func_02191870  0x02191870  thumb  ov021
 *   func_0219196C  0x0219196C  thumb  ov021
 */
#include "../../matched/include/Obj07667.h"
#include "../../matched/include/Obj20580.h"
#include "../../matched/include/Obj05138.h"

struct MsgBank;
struct S;
struct Rec;
struct Fx;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct S {
    u16 a;
    u8 b;
    u8 c;
    u16 d;
    u16 e;
} S;

extern u32 func_020056EC(u32 v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021F45A4(unsigned short *,unsigned int);
extern u32 func_02045C04(struct Rec *rec);
extern int func_02189A38(int a);
extern int func_02189A2C(int *a);
extern void func_02191870(struct Fx *a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h);
extern void func_0219196C(u32 a, u32 b);
int func_021F4388(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir);
void func_021F43D8(u32 *a, u32 b, s16 *c, u32 d, u16 e);
void func_021F4430(unsigned char *p);
void func_021F4458(unsigned char *p);
void func_021F4474(s16 *a, s16 *b, int *c);
void func_021F4510(S *p, int i);
void func_021F4530(u16 *p, u32 a, u32 b, u32 c, u32 d);
void func_021F4574(u16 *p, u32 x);
void func_021F459C(void *p);
extern const u8 d_021F45E0[];
extern const u8 d_021F45D0[];


int func_021F4388(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir)
{
    int x, y;

    switch (dir) {
    case 0:
        x = b - d;
        y = a - c;
        break;
    case 1:
        x = d - b;
        y = a - c;
        break;
    case 2:
        x = a - c;
        y = b - d;
        break;
    case 3:
        x = c - a;
        y = b - d;
        break;
    }
    if (x <= hi && x >= lo && y == 0) {
        return 1;
    }
    return 0;
}


void func_021F43D8(u32 *a, u32 b, s16 *c, u32 d, u16 e)
{
    int i;
    u32 t;
    s16 m;
    u16 *h = (u16 *)a;
    u8 *q;

    i = 0;
    t = func_020056EC(0);
    m = c[d];
    h[0] = i;
    h[1] = 0x10 + t % m;
    a[2] = (u32)func_02045B38(0, 3, 0x9f, e);
    a[3] = b;
    a[1] = t & 0xf;
    q = (u8 *)a + 0x10;
    for (i = 0; i < 16; i++) {
        func_021F4510((struct S *)(q + i * 8), (u16)i);
    }
}

void func_021F4430(unsigned char *p) { int i; for (i=0;i<16;i++) func_021F45A4((unsigned short *)(p+16+i*8),((struct Obj07667 *)p)->fC); ((struct Obj07667 *)p)->fC=0; func_02045C04(((struct Obj07667 *)p)->f8); ((struct Obj07667 *)p)->f8=0; }

void func_021F4458(unsigned char *p) { int i; for (i=0;i<16;i++) func_021F45A4((unsigned short *)(p+16+i*8),((struct Obj20580 *)p)->fC); }


void func_021F4474(s16 *a, s16 *b, int *c)
{
    int i;
    u32 rnd;
    int x;
    u8 *q;

    i = 0;
    rnd = func_020056EC(0);
    x = func_02189A38((int)c);
    if (func_02189A2C(c) == 0) {
        a[0] = a[0] + 1;
        if (a[0] >= a[1]) {
            func_021F4530((u16 *)((u8 *)a + 0x10 + ((u32 *)a)[1] * 8), ((u32 *)a)[3], ((u32 *)a)[2],
                          ((u8 *)b)[0x16], ((u8 *)b)[0x17]);
            a[0] = i;
            ((u32 *)a)[1] = (((u32 *)a)[1] + 1) & 0xf;
            a[1] = 0x10 + rnd % b[x];
        }
        i = 0;
        q = (u8 *)a + 0x10;
        for (; i < 16; i++) {
            func_021F4574((u16 *)(q + i * 8), ((u32 *)a)[3]);
        }
    } else {
        q = (u8 *)a + 0x10;
        for (i = 0; i < 16; i++) {
            func_021F45A4((u16 *)(q + i * 8), ((u32 *)a)[3]);
        }
    }
}

void func_021F4510(S *p, int i)
{
    p->a = 0;
    p->b = d_021F45E0[i];
    p->c = d_021F45D0[i];
    p->d = i;
    p->e = 0;
}


void func_021F4530(u16 *p, u32 a, u32 b, u32 c, u32 d)
{
    u32 r = func_020056EC(0);

    p[0] = 1;
    p[3] = 0;
    func_02191870((struct Fx *)a, b, c + r % d, p[2], ((u8 *)p)[2], ((u8 *)p)[3], 8, 2);
}


/*
 * Unlabelled leaf callee of func_021F4474.
 */
void func_021F4574(u16 *p, u32 x)
{
    if (p[0] != 0) {
        s16 *c = (s16 *)p + 3;

        *c = *c + 1;
        if (*c >= 0x10) {
            func_0219196C(x, p[2]);
            func_021F459C(p);
        }
    }
}


/*
 * Clear the two halfwords at 0x6 and 0x0.
 */
void func_021F459C(void *p)
{
    ((struct Obj05138 *)p)->f6 = 0;
    ((struct Obj05138 *)p)->f0 = 0;
}
