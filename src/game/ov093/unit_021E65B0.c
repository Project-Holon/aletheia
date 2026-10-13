/*
 * file:     unit_021E65B0.c
 * unit:     yes
 * function: func_021E65B0, func_021E6654, func_021E666C, func_021E66A8, func_021E66C0, func_021E66CC, func_021E6710, func_021E6728, func_021E67F4, func_021E6800, func_021E6840, func_021E6918, func_021E6924, func_021E6950, func_021E695C, func_021E6988
 * address:  0x021E65B0
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
 *   func_0689C8CC  0x0689C8CC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   PALANM_IsColorCodeKnown  0x020213C0  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2B28     0x021F2B28  data   ov093  a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   BTL_EVENT_MarkFactorDead  0x021D7090  thumb  ov093
 *   d_021F2B40     0x021F2B40  data   ov093  a4
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   d_021F2B58     0x021F2B58  data   ov093  a4
 *   d_021F276C     0x021F276C  data   ov093  a4
 *   d_021F2754     0x021F2754  data   ov093  a4
 *   d_021F255C     0x021F255C  data   ov093  a4
 */
#include "../../matched/include/Obj06277.h"
#include "../../matched/include/Obj13536.h"
#include "../../matched/include/Obj13537.h"

struct QI;
struct S;
struct Node;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int PALANM_IsColorCodeKnown(u32 a);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int func_0689C8CC();
extern int func_021B9A24(u32 a, u32 b);
extern void BTL_EVENT_MarkFactorDead(u8 *p);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
void func_021E65B0(int u, void *a, u32 b);
int *func_021E6648(int *p);
void func_021E6654(int a, int b, int c);
void func_021E666C(int a, void *b, int c);
void func_021E66A8(int a, int b, int c);
int *func_021E66C0(int *p);
void func_021E66CC(int u, void *a, u32 b, u32 *q);
void func_021E6710(struct Node *a, int b, int c);
void func_021E6728(int m, void *a, u32 b);
int *func_021E67F4(int *p);
void func_021E6800(int u, void *a, u32 b, u32 *q);
void func_021E6840(void *x, void *a, int c);
int *func_021E6918(int *p);
void func_021E6924(int a, void *b, int c);
int *func_021E6950(int *p);
void func_021E695C(int a, void *b, int c);
int *func_021E6988(int *p);
extern int d_021F2B28[];
extern int d_021F2B40[];
extern int d_021F2B58[];
extern int d_021F276C[];
extern int d_021F2754[];
extern int d_021F255C[];


void func_021E65B0(int u, void *a, u32 b)
{
    u8 *e;
    u8 k;
    u16 t;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        t = (int)BTL_POKEPARAM_GetItem(func_021C7CF4(a, k));
        if (PALANM_IsColorCodeKnown(t) != 0) {
            e = func_021C88A4(a, 0x20, b);
            e[6] = k;
            ((struct Obj06277 *)e)->f4 = 0;
            func_021C8838(e + 0xc, 2, 0x308);
            func_021C8860((struct S *)(e + 0xc), b);
            func_021C8860((struct S *)(e + 0xc), t);
            func_021C88C8(a, e);
            e = func_021C88A4(a, 0x22, b);
            ((struct Obj06277 *)e)->f0 |= 2 << 23;
            ((struct Obj06277 *)e)->f6 = t;
            e[4] = b;
            func_021C88C8(a, e);
        }
    }
}


int *func_021E6648(int *p)
{
    *p = 3;
    return d_021F2B28;
}


/* 021E6654  shape F1: gate on BTL_EVENT_GetVar(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E666A; movs r0, #0x51; movs r1, #1; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
void func_021E6654(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x51, 1);
}


void func_021E666C(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 2, 0x344);
        func_021C8860((struct S *)(m + 4), c);
        func_021C88C8(b, m);
    }
}


/* 021E66A8  shape F1: gate on BTL_EVENT_GetVar(2) */
void func_021E66A8(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_OverwriteVar(0x4b, 1);
}


int *func_021E66C0(int *p)
{
    *p = 3;
    return d_021F2B40;
}


void func_021E66CC(int u, void *a, u32 b, u32 *q)
{
    u8 *e;

    if (b == BTL_EVENT_GetVar(3)) {
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x272);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
        q[6] = 1;
    }
}


/* 021E6710  shape F3: gate on BTL_EVENT_GetVar(2) then BTL_EVENT_RemoveFactor */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E6726; adds r0, r5, #0; bl BTL_EVENT_RemoveFactor; pop {r3, r4, r5, pc}.
 */
void func_021E6710(struct Node *a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_EVENT_RemoveFactor(a);
}


void func_021E6728(int m, void *a, u32 b)
{
    u8 *e;
    void *x;
    u8 k;

    if (b == BTL_EVENT_GetVar(4)) {
        if (BTL_POKEPARAM_IsFainted(func_021C7CF4(a, b)) != 0) {
            if (func_0689C8CC((u16)BTL_EVENT_GetVar(0x12)) == 0) {
                k = BTL_EVENT_GetVar(3);
                x = func_021C7CF4(a, k);
                if (func_021B9A24(b, k) == 0 && BTL_POKEPARAM_IsFainted(x) == 0) {
                    BTL_EVENT_MarkFactorDead((u8 *)m);
                    e = func_021C88A4(a, 0x13, b);
                    e[4] = b;
                    e[5] = 1;
                    func_021C88C8(a, e);
                    e = func_021C88A4(a, 0x13, b);
                    e[4] = BTL_EVENT_GetVar(3);
                    func_021C8838(e + 8, 2, 0x275);
                    func_021C8860((struct S *)(e + 8), b);
                    func_021C88C8(a, e);
                }
            }
            BTL_EVENT_RemoveFactor((struct Node *)m);
        }
    }
}


int *func_021E67F4(int *p)
{
    *p = 3;
    return d_021F2B58;
}


void func_021E6800(int u, void *a, u32 b, u32 *q)
{
    u8 *e;

    if (b == BTL_EVENT_GetVar(3)) {
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x278);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
        q[6] = 1;
    }
}


/*
 * lever: Callback kind 10 is reused as the multiplier, then decreased by 11;
 * this retains the live constant and reproduces the spill frame and muls.
 */
void func_021E6840(void *x, void *a, int c)
{
    u8 k;
    void *m;
    u16 id;
    int i;
    u8 *p;
    int multiplier;
    if (c == BTL_EVENT_GetVar(4)) {
        if (func_0689C8CC((u16)BTL_EVENT_GetVar(18)) == 0) {
            if (BTL_POKEPARAM_IsFainted(func_021C7CF4(a, c)) != 0) {
                k = BTL_EVENT_GetVar(3);
                m = func_021C7CF4(a, k);
                id = BTL_EVENT_GetVar(20);
                i = BTL_POKEPARAM_FindMoveSlot(m, id);
                if (i != 4) {
                    multiplier = 10;
                    p = func_021C88A4(a, multiplier, c);
                    p[5] = k;
                    p[6] = i;
                    multiplier -= 11;
                    p[4] = BTL_POKEPARAM_GetMovePPChecked(m, (u8)i) * multiplier;
                    p[7] |= 2;
                    func_021C8838(p + 8, 2, 0x27b);
                    func_021C8860((struct S *)(p + 8), k);
                    func_021C8860((struct S *)(p + 8), id);
                    func_021C88C8(a, p);
                }
                BTL_EVENT_RemoveFactor(x);
            }
        }
    }
}


int *func_021E6918(int *p)
{
    *p = 1;
    return d_021F276C;
}


void func_021E6924(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(2)) {
        m = (u8 *)func_021C88A4(b, 0x17, c);
        m[8] = c;
        ((struct Obj13536 *)m)->f4 = 8;
        func_021C88C8(b, m);
    }
}


int *func_021E6950(int *p)
{
    *p = 1;
    return d_021F2754;
}


void func_021E695C(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(2)) {
        m = (u8 *)func_021C88A4(b, 0x17, c);
        m[8] = c;
        ((struct Obj13537 *)m)->f4 = 7;
        func_021C88C8(b, m);
    }
}


int *func_021E6988(int *p)
{
    *p = 1;
    return d_021F255C;
}
