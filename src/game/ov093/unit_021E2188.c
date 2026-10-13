/*
 * file:     unit_021E2188.c
 * unit:     yes
 * function: func_021E2188, func_021E21E8, func_021E21F4, func_021E2268, func_021E231C, func_021E2370, func_021E237C, func_021E249C, func_021E24D4, func_021E2574, func_021E25DC, func_021E25F0, func_021E25FC, func_021E2678, func_021E269C, func_021E26C8, func_021E2700, func_021E2768, func_021E278C, func_021E27A4, func_021E27B0, func_021E2810
 * address:  0x021E2188
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 *   d_021F2C90     0x021F2C90  data   ov093  a4
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2E78     0x021F2E78  data   ov093  a4
 *   func_021E03F8  0x021E03F8  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   d_021F29C8     0x021F29C8  data   ov093  a4
 *   d_021F2EA0     0x021F2EA0  data   ov093  a4
 *   func_021C81C8  0x021C81C8  thumb  ov093
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F2474     0x021F2474  data   ov093  a4
 *   d_021F248C     0x021F248C  data   ov093  a4
 */
#include "../../matched/include/Obj10073.h"
#include "../../matched/include/Obj10075.h"
#include "../../matched/include/Obj05221.h"
#include "../../matched/include/Obj10076.h"
#include "../../matched/include/Obj05222.h"
#include "../../matched/include/Obj13508.h"
#include "../../matched/include/Obj10078.h"
#include "../../matched/include/Obj10080.h"

struct Unk021D62A8;
struct S;
struct QQ;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

struct Cnt { u32 n; int max; };

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTLV_CORE_MakeSlotKind1Empty(void);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
extern u32 BTL_CALC_Random(u32 range);
extern Word BTLV_CORE_MakeSlotKind2(int a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_CALC_MakeSickContFromKind(int a, void *b, void *c);
extern void func_021E03D8(u8 *a, int b);
extern int func_021C7D00(u8 *p, int b);
extern u8 *func_021C8120(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern int BTL_EVENT_OverwriteVar(int key, unsigned v);
extern void func_021E03F8(int a, int b);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void BTLV_CORE_EventScaleDamage(int n);
extern u16 func_021C81C8(u8 *p, u8 *x, int flag);
void func_021E2188(int u, int a, int b);
int *func_021E21E8(int *p);
void func_021E21F4(void *u, int a, int b, int *p);
void func_021E2268(void *u, int a, int b, int *p);
void func_021E231C(void *u, int a, int b);
int *func_021E2370(int *p);
void func_021E237C(void *a, void *b, u8 c, u8 *d);
void func_021E249C(int u, int a, int b);
void func_021E24D4(void *a, void *b, int c, int *d);
void func_021E2574(int a, void *b, int c, int *d);
void func_021E25DC(int u, int a, int b, int *p);
int *func_021E25F0(int *p);
void func_021E25FC(void *a, void *b, int c, int *d);
void func_021E2678(void *u, int a, int b, int *p);
void func_021E269C(void *u, int a, int b, int *p);
void func_021E26C8(void *u, int a, int b, int *p);
void func_021E2700(void *a, void *b, int c, struct Cnt *d);
int *func_021E275C(int *p);
void func_021E2768(int u, int a, int b, int *p);
void func_021E278C(int a, int b, int c);
int *func_021E27A4(int *p);
void func_021E27B0(int a, void *b, int c);
int *func_021E2810(int *p);
extern int d_021F2C90[];
/*
 * lever: Word return from BTLV_CORE_MakeSlotKind2 reserves the unused aggregate slot;
 * u8 c schedules its stack reload after the zero store at 021E23CE.
 */
extern int d_021F2E78[];
extern int d_021F29C8[];
extern int d_021F2EA0[];
extern int d_021F2474[];
extern int d_021F248C[];




void func_021E2188(int u, int a, int b)
{
    u8 *r;

    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_HasSick(func_021C7CF4((int *)a, b), 0x23) == 0) {
            r = func_021C88A4((char *)a, 0xc, b);
            ((struct Obj10073 *)r)->f4 = 0x23;
            ((struct Obj10073 *)r)->f8 = BTLV_CORE_MakeSlotKind1Empty();
            r[0xf] = b;
            func_021C8838(r + 0x14, 2, 0x259);
            func_021C8860((struct S *)(r + 0x14), b);
            func_021C88C8((void *)a, r);
        }
    }
}




int *func_021E21E8(int *p)
{
    *p = 3;
    return d_021F2C90;
}




/*
 * Lever: BTLV_CORE_MakeSlotKind2 returns a one-word struct (Word), which reserves the
 * third frame word (`sub sp, #0xc` with push {r4-r7, lr}); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 */
void func_021E21F4(void *u, int a, int b, int *p)
{
    u8 *r;
    u8 t;

    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_HasSick(func_021C7CF4((int *)a, b), 0x19) == 0 && p[6] == 0) {
            t = BTL_CALC_Random(2) + 2;
            r = func_021C88A4((char *)a, 0xc, b);
            ((struct Obj10075 *)r)->f4 = 0x19;
            *(Word *)(r + 8) = BTLV_CORE_MakeSlotKind2(t, BTL_EVENT_GetFactorKey(u));
            r[0xc] = 0;
            r[0xf] = b;
            func_021C88C8((void *)a, r);
            p[6] = 1;
            p[0] = t;
        }
    }
}






void func_021E2268(void *u, int a, int b, int *p)
{
    void *q;
    u8 *r;
    int f;

    if (b == BTL_EVENT_GetVar(2)) {
        q = func_021C7CF4((int *)a, b);
        if (p[6] != 0) {
            f = 0;
            if (p[0] != 0)
                p[0] = p[0] - 1;
            if (BTL_EVENT_GetVar(0x51) == 0) {
                r = func_021C88A4((char *)a, 0xb, b);
                ((struct Obj05221 *)r)->f4 = 0x19;
                f = 1;
                r[0x14] = 1;
                r[8] = b;
                func_021C88C8((void *)a, r);
            }
            if (p[0] == 0) {
                r = func_021C88A4((char *)a, 0xc, b);
                ((struct Obj05221 *)r)->f4 = 6;
                BTL_CALC_MakeSickContFromKind(6, q, r + 8);
                f = 1;
                r[0xd] = 1;
                r[0xf] = b;
                func_021C8838(r + 0x14, 2, 0x168);
                func_021C8860((struct S *)(r + 0x14), b);
                func_021C88C8((void *)a, r);
            }
            if (f != 0)
                func_021E03D8(q, BTL_EVENT_GetFactorKey(u));
        }
    }
}






void func_021E231C(void *u, int a, int b)
{
    void *q;
    u8 *r;

    if (b == BTL_EVENT_GetVar(2)) {
        q = func_021C7CF4((int *)a, b);
        if (BTL_POKEPARAM_HasSick(q, 2) != 0) {
            r = func_021C88A4((char *)a, 0xb, b);
            ((struct Obj10076 *)r)->f4 = 0x19;
            r[0x14] = 1;
            r[8] = b;
            func_021C88C8((void *)a, r);
            func_021E03D8(q, BTL_EVENT_GetFactorKey(u));
        }
    }
}



int *func_021E2370(int *p)
{
    *p = 5;
    return d_021F2E78;
}



void func_021E237C(void *a, void *b, u8 c, u8 *d)
{
    u8 *p;
    u8 *buf;
    u32 flags;
    unsigned i;
    u8 *entry;
    if (c != BTL_EVENT_GetVar(3)) return;
    if (BTL_POKEPARAM_HasSick(func_021C7CF4(b, c), 25) != 0) return;
    if (((struct Obj13508 *)d)->f18 != 0) return;
    p = func_021C88A4(b, 12, c);
    ((struct Obj05222 *)p)->f4 = 25;
    *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2(3, BTL_EVENT_GetFactorKey(a));
    p[12] = 0;
    p[15] = c;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 703);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8(b, p);
    flags = func_021C7D00(b, c);
    buf = func_021C8120(b, 7);
    buf[0] = func_021C7F68(b, (u16)(flags | 0x800), buf + 1);
    for (i = 0; i < buf[0]; i++) {
        entry = buf + i;
        if (BTL_POKEPARAM_HasSick(func_021C7CF4(b, entry[1]), 2) != 0) {
            p = func_021C88A4(b, 11, c);
            ((struct Obj05222 *)p)->f4 = 2;
            p[20] = 1;
            p[8] = entry[1];
            func_021C8838(p + 24, 2, 706);
            func_021C8860((struct S *)(p + 24), entry[1]);
            func_021C88C8(b, p);
        }
    }
    ((struct Obj13508 *)d)->f18 = 1;
}





void func_021E249C(int u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_GetVar(0x51) == 0) {
            s = func_021C88A4((char *)a, 0xb, b);
            ((struct Obj10078 *)s)->f4 = 0x19;
            s[0x14] = 1;
            s[8] = b;
            func_021C88C8((void *)a, s);
        }
    }
}





void func_021E24D4(void *a, void *b, int c, int *d)
{
    void *v;
    char *p;

    if (c == BTL_EVENT_GetVar(2) && d[6] != 0) {
        v = func_021C7CF4(b, c);
        if (BTL_POKEPARAM_IsFainted(v) == 0) {
            if (BTL_POKEPARAM_HasSick(v, 0x19) == 0) {
                p = func_021C88A4(b, 4, c);
                func_021C8838(p + 4, 2, 0x2CE);
                func_021C8860((struct S *)(p + 4), c);
                func_021C88C8(b, p);
                func_021E03D8(v, BTL_EVENT_GetFactorKey(a));
            } else {
                p = func_021C88A4(b, 4, c);
                func_021C8838(p + 4, 2, 0x2CB);
                func_021C8860((struct S *)(p + 4), c);
                func_021C88C8(b, p);
            }
        }
    }
}





void func_021E2574(int a, void *b, int c, int *d)
{
    char *p;
    u8 u;

    if (d[6] != 0 && BTL_EVENT_GetVar(0x1D) == 2 && BTL_EVENT_OverwriteVar(0x41, 1) != 0) {
        p = func_021C88A4(b, 4, c);
        u = BTL_EVENT_GetVar(4);
        func_021C8838(p + 4, 2, (u16)(u == c ? 0x2C8 : 0x2C5));
        func_021C8860((struct S *)(p + 4), u);
        func_021C88C8(b, p);
    }
}




void func_021E25DC(int u, int a, int b, int *p)
{
    if (p[6] != 0)
        BTL_EVENT_OverwriteVar(0x41, 1);
}



int *func_021E25F0(int *p)
{
    *p = 5;
    return d_021F2EA0;
}



void func_021E25FC(void *a, void *b, int c, int *d)
{
    void *v;
    int *p;

    if (c == BTL_EVENT_GetVar(2)) {
        v = func_021C7CF4(b, c);
        if (BTL_POKEPARAM_HasSick(v, 0x19) == 0 && BTL_POKEPARAM_HasSick(v, 2) == 0 && d[6] == 0) {
            p = func_021C88A4(b, 12, c);
            p[1] = 0x19;
            *(Word *)(p + 2) = BTLV_CORE_MakeSlotKind2(5, BTL_EVENT_GetFactorKey(a));
            ((u8 *)p)[12] = 0;
            ((u8 *)p)[15] = c;
            func_021C88C8(b, p);
            d[0] = 0;
            d[1] = 5;
            d[6] = 1;
        }
    }
}








void func_021E2678(void *u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2))
        func_021E26C8(u, a, b, p);
}








void func_021E269C(void *u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_EVENT_GetVar(0x51) == 0)
            func_021E26C8(u, a, b, p);
    }
}







void func_021E26C8(void *u, int a, int b, int *p)
{
    u8 *s;

    s = func_021C88A4((char *)a, 0xb, b);
    s[8] = b;
    s[0x14] = 1;
    ((struct Obj10080 *)s)->f4 = 0x19;
    func_021C88C8((void *)a, s);
    p[6] = 0;
    func_021E03F8(b, BTL_EVENT_GetFactorKey(u));
}







void func_021E2700(void *a, void *b, int c, struct Cnt *d)
{
    void *v;
    u32 i;
    int k;

    if (c == BTL_EVENT_GetVar(3)) {
        v = func_021C7CF4(b, c);
        k = 1;
        for (i = 0; i < d->n; i++)
            k <<= 1;
        if (BTL_POKEPARAM_TestContFlag(v, 7))
            k <<= 1;
        BTLV_CORE_EventScaleDamage(k);
        d->n++;
        if ((int)d->n >= d->max)
            func_021E03F8(c, BTL_EVENT_GetFactorKey(a));
    }
}







int *func_021E275C(int *p)
{
    *p = 2;
    return d_021F29C8;
}





void func_021E2768(int u, int a, int b, int *p)
{
    int n;

    if (b == BTL_EVENT_GetVar(3)) {
        n = *p + 1;
        *p = n;
        BTL_EVENT_OverwriteVar(0x30, n * 10);
    }
}




/* 021E278C  shape F1: gate on BTL_EVENT_GetVar(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl BTL_EVENT_GetVar; cmp r4, r0; bne loc_021E27A2; movs r0, #0x42; movs r1, #1; bl BTL_EVENT_OverwriteVar; pop {r4, pc}.
 */
void func_021E278C(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x42, 1);
}



int *func_021E27A4(int *p)
{
    *p = 1;
    return d_021F248C;
}



void func_021E27B0(int a, void *b, int c)
{
    void *x;
    void *y;
    int p;
    int q;
    u32 r;

    if (c == BTL_EVENT_GetVar(3)) {
        x = func_021C7CF4(b, c);
        y = func_021C7CF4(b, (u8)BTL_EVENT_GetVar(4));
        p = func_021C81C8(b, x, 0);
        q = func_021C81C8(b, y, 0);
        r = q * 25 / p + 1;
        if (r > 0x96)
            r = 0x96;
        BTL_EVENT_OverwriteVar(0x30, r);
    }
}



int *func_021E2810(int *p)
{
    *p = 1;
    return d_021F2474;
}
