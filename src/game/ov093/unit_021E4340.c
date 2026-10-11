/*
 * file:     unit_021E4340.c
 * unit:     yes
 * function: func_021E4340, func_021E4408, func_021E448C, func_021E4564, func_021E45C0, func_021E45CC, func_021E467C, func_021E4688, func_021E4748
 * address:  0x021E4340
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
 *   func_0689C8AC  0x0689C8AC  thumb
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F2D20 0x021F2D20 data a4
 *   d_021F2888 0x021F2888 data a4
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021D62C4   0x021D62C4  thumb ov093
 *   func_021D5B48   0x021D5B48  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021D7D78 0x021D7D78 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F278C 0x021F278C data a4
 *   func_021D67B0  0x021D67B0  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021D7A9C  0x021D7A9C  thumb  ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_02082D44  0x02082D44  arm
 *   func_021E8CF0  0x021E8CF0  thumb  ov093
 *   d_021F2784     0x021F2784  data   ov093  a4
 *   func_021D67B8  0x021D67B8  thumb  ov093
 *   func_021D55A0  0x021D55A0  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021E896C  0x021E896C  thumb  ov093
 *   d_021F25E4     0x021F25E4  data   ov093  a4
 *   d_021F2774     0x021F2774  data   ov093  a4
 */
#include "../../matched/include/Obj06271.h"
#include "../../matched/include/Obj02433.h"
#include "../../matched/include/Obj13520.h"

struct Unk021D62A8;
struct S;
struct QM;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed char    s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

typedef enum { K_0 } KType;

struct Rec { u32 f0; u32 f4; Word f8; u8 fc; u8 fd; u8 fe; u8 ff; };

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 func_021D78AC(u32);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
int func_021D76BC(int key, u32 val);
int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5B48(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern Word func_021D7D78(int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
extern u8 func_021D67B0(struct QM *p);
extern u8 *func_021C8120(u8 *s, int k);
extern u8 func_021D7A9C(int a, u8 *out);
extern int func_021D5814(void *p, int k);
extern void func_02082D44(u8 *src, u8 *dst, u32 n);
extern int func_021E8CF0(int a);
extern u16 func_021D67B8(u8 *q);
extern int func_0689C8AC(int w);
extern int func_021D55A0(struct UtilWork *p, int id);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern Word func_021E896C(int a, int b);
void func_021E4340(int unused, void *s, int k);
int *func_021E43FC(int *p);
void func_021E4408(void *a, int b, int c);
void func_021E448C(int unused, void *s, int k);
int *func_021E4558(int *p);
void func_021E4564(int a0, u8 *s, int k);
int *func_021E45C0(int *p);
void func_021E45CC(int a0, u8 *s, int k);
int *func_021E467C(int *p);
void func_021E4688(int a0, u8 *s, int k);
int *func_021E4748(int *p);
extern const u32 d_021F2D20[];
extern int d_021F2888[];
extern int d_021F278C[];
extern int d_021F2784[];
extern int d_021F25E4[];
extern int d_021F2774[];


/*
 * Lever: chained n = i = 0 initializes the index first; a fresh byte
 * pick for the random selection keeps the second loop's count in r4.
 * Reusing n for that selection swaps the second loop's r4/r5 allocation.
 */
void func_021E4340(int unused, void *s, int k)
{
    u8 v;
    void *q;
    u8 n;
    u8 i;
    u8 *p;
    u8 pick;
    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4(s, v);
        n = i = 0;
        for (; i < 7; i++) {
            if (func_021D5D14(q, d_021F2D20[i], 2) != 0)
                n++;
        }
        if (n != 0) {
            pick = func_021D78AC(n);
            for (i = 0; i < 7; i++) {
                if (func_021D5D14(q, d_021F2D20[i], 2) != 0) {
                    if (pick == 0) {
                        p = func_021C88A4(s, 14, k);
                        p[16] = v;
                        p[15] = 1;
                        ((struct Obj06271 *)p)->f4 = d_021F2D20[i];
                        p[12] = 2;
                        p[14] = 0;
                        func_021C88C8(s, p);
                        return;
                    }
                    pick--;
                }
            }
        }
    }
}


int *func_021E43FC(int *p)
{
    *p = 2;
    return d_021F2888;
}


/*
 * Two-key gate on func_021D775C(2) / func_021D775C(0x22), then classify the
 * func_021C7CF4(b, c) record: the first matching predicate decides which
 * func_021D76BC(0x22, code) event fires, and only the fall-through case
 * looks at the 16-bit func_021D59B4(u, 0x11) result.
 */
void func_021E4408(void *a, int b, int c)
{
    u16 v;
    void *u;

    if (c != func_021D775C(2))
        return;
    if (func_021D775C(0x22) != 0)
        return;
    u = func_021C7CF4((int *)b, c);
    if (func_021D62C4(u, 2) != 0) {
        func_021D76BC(0x22, 0x1a);
        return;
    }
    if (func_021D62C4(u, 0xf) != 0) {
        func_021D76BC(0x22, 0xd);
        return;
    }
    if (func_021D5B48(u) != 0) {
        func_021D76BC(0x22, 0xe);
        return;
    }
    v = func_021D59B4(u, 0x11);
    if (v == 0xf || v == 0x48)
        func_021D76BC(0x22, 0xf);
}


void func_021E448C(int unused, void *s, int k)
{
    void *q;
    u8 *p;
    u32 n;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(s, k);
        if (func_021D5B48(q) == 0) {
            p = func_021C88A4(s, 12, k);
            p[15] = k;
            ((struct Obj02433 *)p)->f4 = 2;
            *(Word *)(p + 8) = func_021D7D78(3);
            p[12] = 1;
            p[16] = 1;
            p[14] = 1;
            func_021C8838(p + 20, 2, 638);
            func_021C8860((struct S *)(p + 20), k);
            func_021C88C8(s, p);
            p = func_021C88A4(s, 5, k);
            p[6] = k;
            n = func_021D59B4(q, 14);
            *(u16 *)&((struct Obj02433 *)p)->f4 = n - func_021D59B4(q, 13);
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            func_021C88C8(s, p);
            p = func_021C88A4(s, 33, k);
            p[4] = k;
            ((struct Obj02433 *)p)->f8 = 3;
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            func_021C88C8(s, p);
            func_021D76BC(81, 0);
        }
    }
}


int *func_021E4558(int *p)
{
    *p = 1;
    return d_021F278C;
}


void func_021E4564(int a0, u8 *s, int k)
{
    u8 *a;
    u8 *b;
    u8 x;
    u8 y;

    if (k == func_021D775C(3)) {
        a = func_021C7CF4((int *)s, k);
        b = func_021C7CF4((int *)s, (u8)func_021D775C(4));
        x = func_021D59B4(a, 0x12);
        y = func_021D59B4(b, 0x12);
        if (x == 2 || y == 2 || x == y)
            func_021D76BC(0x40, 1);
    }
}


int *func_021E45C0(int *p)
{
    *p = 1;
    return d_021F2784;
}


void func_021E45CC(int a0, u8 *s, int k)
{
    int t;
    u8 *p;
    u32 n;
    u8 *q;
    u32 i;
    int c;
    u8 *e;

    if (k == func_021D775C(3)) {
        t = func_021D67B0((struct QM *)func_021C7CF4((int *)s, (u8)func_021D775C(6)));
        if (t != 0x11) {
            p = func_021C8120(s, 0x11);
            n = func_021D7A9C(t, p);
            if (n != 0) {
                q = func_021C7CF4((int *)s, k);
                i = 0;
                while (i < n) {
                    if (func_021D5814(q, p[i]) != 0) {
                        if ((int)(n - 1 - i) > 0)
                            func_02082D44(p + (i + 1), p + i, n - 1 - i);
                        n--;
                    } else {
                        i++;
                    }
                }
                if (n != 0) {
                    c = p[func_021D78AC(n)];
                    e = func_021C88A4((char *)s, 0x14, k);
                    ((struct Obj13520 *)e)->f4 = func_021E8CF0(c);
                    e[6] = k;
                    func_021C88C8(s, e);
                }
            }
        }
    }
}


int *func_021E467C(int *p)
{
    *p = 1;
    return d_021F25E4;
}


void func_021E4688(int a0, u8 *s, int k)
{
    KType c = 3;
    u8 v;
    u8 *q;
    int w;
    struct Rec *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4((int *)s, v);
        w = func_021D67B8(q);
        if (func_021D62C4((struct Unk021D62A8 *)q, 0x17) == 0 && func_0689C8AC(w) == 0 && func_021D55A0((struct UtilWork *)q, w) != 0) {
            if (func_021D5BB0((struct UtilWork *)q, 1) != 0)
                c = (u8)(c + 1);
            e = (struct Rec *)func_021C88A4((char *)s, 12, k);
            e->f4 = 0x17;
            e->f8 = func_021E896C(c, w);
            e->ff = v;
            e->fc = 0;
            func_021C8838((u8 *)e + 0x14, 2, 559);
            func_021C8860((struct S *)((u8 *)e + 0x14), v);
            func_021C88C8(s, (u8 *)e);
        }
    }
}


int *func_021E4748(int *p)
{
    *p = 1;
    return d_021F2774;
}
