/*
 * file:     tr_ai_p15.c
 * unit:     yes
 * function: func_02189AC0, func_02189B78, func_02189BFC, func_02189C8C
 * address:  0x02189AC0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_0218A390  0x0218A390  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021C7DAC  0x021C7DAC  thumb  ov093
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021C7E14  0x021C7E14  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_0218A58C     0x0218A58C  data   ov096  a4
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj06344.h"

struct Cursor;
struct Cur;
struct Q1;
struct QG;
struct QL;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4; char *fb8; u8 *fbc, *fc0; int fc4; } Obj_02189AC0;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4, fb8; u8 *fbc, *fc0; int fc4; } Obj_02189B78;

typedef struct { int v[7]; } Seven;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x88]; int fc4; } Obj_02189C8C;

extern u32 func_0201134C(struct Cursor *p);
extern void func_020113B0(struct Cur *c, u32 v);
extern u8 *func_0218A308(void *, u32);
extern u32 func_0218A390(u8 *a, u8 *b, u8 *c, int d);
extern u8 func_021B8DE4(char *p, int i);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021D5440(u8 *p);
extern int func_021D5B68(void *);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern int func_021C7DAC(u8 *p, int a, int b, int c);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021C7E14(u8 *p, int a, int b, u32 c, int e0, int e1);
extern int func_021D59B4(u8 *p, int k);
int func_02189AC0(struct Cursor *a, Obj_02189AC0 *b);
int func_02189B78(struct Cursor *a, Obj_02189B78 *b);
int func_02189BFC(struct Cursor *a, int b);
int func_02189C8C(struct Cursor *a, Obj_02189C8C *b);
extern const Seven d_0218A58C;


/*
 * Lever: the second parameter is a struct pointer (see 02189B78).
 */
int func_02189AC0(struct Cursor *a, Obj_02189AC0 *b) {
    int c;
    int x;
    int r4;
    char *r7;
    u8 *r6;
    u32 base;
    c = func_0201134C(a);
    x = func_0201134C(a);
    r4 = func_021B8DE4((char *)b->fb0, b->f94);
    r7 = func_021B9AF8(b->fb8, r4);
    r4 = func_021B99B8((void *)b->fb0, r4);
    base = func_0218A390((u8 *)((int)b), b->fbc, b->fc0, c);
    for (; r4 < func_021B9B94((struct Q1 *)r7); r4++) {
        r6 = func_0218A308(r7, (u8)r4);
        func_021D5440(r6);
        if (func_021D5B68(r6) == 0) {
            if (func_0218A390((u8 *)((int)b), r6, b->fc0, c) > base) {
                func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + x);
                break;
            }
        }
    }
    return b->fc4;
}


/*
 * Lever: the second parameter is a struct pointer; with an int base the
 * loop-invariant b+0xbc/b+0xc0 addresses were hoisted and b spilled.
 */
int func_02189B78(struct Cursor *a, Obj_02189B78 *b) {
    int r;
    int i;
    int c6;
    int c7;
    int c2;
    r = func_0201134C(a);
    for (i = 0; i < func_021D5448((struct QG *)b->fbc); i++) {
        c6 = func_021D54C0(b->fbc, (u8)i);
        c7 = func_021D5440(b->fbc);
        c2 = func_021D5440(b->fc0);
        if ((u32)(func_021C7DAC((u8 *)b->fb4, c7, c2, c6) - 4) <= 1) {
            func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r);
            break;
        }
    }
    return b->fc4;
}


int func_02189BFC(struct Cursor *a, int b)
{
    int t0;
    int t1;
    int t2;
    u8 *v;
    unsigned int w;
    int x;
    int y;
    int z;
    unsigned int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    v = func_0218A2FC((u8 *)b, func_0218A160((u8 *)b, t0));
    w = func_0218A390((u8 *)b, *(u8 * *)&((struct Obj06344 *)b)->fBC, *(u8 * *)&((struct Obj06344 *)b)->fC0, t1);
    x = func_021D67A8((struct QL *)v);
    y = func_021D5440(v);
    z = func_021D5440(*(u8 * *)&((struct Obj06344 *)b)->fC0);
    r = func_021C7E14((u8 *)(((struct Obj06344 *)b)->fB4), y, z, x, 1, t1);
    if (w < r)
        func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + t2);
    return ((struct Obj06344 *)b)->fC4;
}


/*
 * Lever: the second parameter is a struct pointer (fields at 0x38, 0xc4);
 * with an int base and a local `int *p = b + 0x38` the store/adds order and
 * the r4/r5 roles were wrong.
 */
int func_02189C8C(struct Cursor *a, Obj_02189C8C *b) {
    u8 s;
    int v;
    u32 i;
    Seven t;
    s = func_0218A160((u8 *)b, func_0201134C(a));
    t = d_0218A58C;
    i = 0;
    b->f38 = 0;
    for (; i < 7; i++) {
        v = func_021D59B4(func_0218A2FC((u8 *)b, s), t.v[i]);
        if (v > 6) {
            b->f38 += v - 6;
        }
    }
    return b->fc4;
}
