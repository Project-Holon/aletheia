/*
 * file:     btlv_core_p01.c
 * unit:     yes
 * function: func_021E869C, func_021E86C8, func_021E86E8, func_021E8744, func_021E8798, func_021E8804, func_021E8860, func_021E8878, func_021E889C, func_021E88CC, func_021E88F8, func_021E8918, func_021E8928, func_021E8940, func_021E896C, func_021E899C, func_021E89C0, func_021E89D4, func_021E89F8, func_021E8A28, func_021E8A58, func_021E8A78
 * address:  0x021E869C
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021E8638  0x021E8638  thumb  ov093
 *   func_021C8168  0x021C8168  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8434  0x021C8434  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   OS_GetConsoleType  0x02085CBC  arm
 *   sub_02034AC4  0x02034AC4  arm
 *   d_021F6380  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 *   sub_02034A5C  0x02034A5C  arm
 */
#include "../../matched/include/Obj12160.h"

struct QF;
struct QI;
struct UtilWork;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

struct S_021E8940 { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };

struct S_021E896C { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };

struct S_021E899C { unsigned a:3; unsigned b:6; unsigned c:23; };

struct S_021E89C0 { unsigned a:3; unsigned b:29; };

struct S_021E89D4 { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };

struct S_021E89F8 { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };

struct S_021E8A28 { unsigned a:3; unsigned b:6; unsigned c:6; unsigned d:17; };

struct S_021E8A58 { unsigned a:3; unsigned b:6; unsigned c:23; };

extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern u16 func_021D5B40(struct QI *p);
extern int func_021E8638(int a, int b);
extern int func_021C8168(void *p);
extern u8 func_021B8DDC(u32 x);
extern int func_021D775C(int key);
extern int func_021B9A24(u32 a, u32 b);
extern u32 sub_0201C1BC(u16 move);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021D76BC(int key, u32 val);
extern void func_021C8434(u8 *p, int a, int b);
extern int func_021D5C30(struct UtilWork *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern u32 OS_GetConsoleType(void);
extern int sub_02034AC4(signed int handle);
extern void sub_02034A5C(int handle);
int func_021E869C(void *a, int b);
int func_021E86C8(void *a, int b);
int func_021E86E8(void *a, int b, int c);
void func_021E8744(int u, void *a, int b, int d);
void func_021E8798(int u, void *a, int b, int d);
void func_021E8804(int u, void *a, int b, int d);
void func_021E8860(int n);
void func_021E8878(int a, int b, int c);
int func_021E889C(int a, int b, int c);
void func_021E88CC(void);
void func_021E88F8(void);
u32 func_021E8918(void);
int func_021E8928(union Slot s);
int func_021E8940(u32 a);
int func_021E896C(u32 a, u32 b);
int func_021E899C(u32 a);
int func_021E89C0(void);
int func_021E89D4(u32 a);
int func_021E89F8(u32 a, u32 b);
int func_021E8A28(u32 a, u32 b);
int func_021E8A58(void);
int func_021E8A78(union Slot s);
extern u8 ov140_id[];
extern int d_021F6380;


int func_021E869C(void *a, int b)
{
    void *r;
    int t;
    u16 s;

    r = func_021C7CF4(a, b);
    t = func_021D5444(r);
    s = (int)func_021D5B40(r);
    if (func_021E8638(t, s) != 0)
        return 1;
    return 0;
}


/*
 * 2026-10-03: the `cmp r0,#1; beq; bne` pair is a disjunction of two tests that both
 * compare against 1 (likely two constants with the same value); the compiler keeps
 * one branch per operand.
 */
int func_021E86C8(void *a, int b)
{
    int r;

    if (func_021C8168(a) == 0) {
        r = func_021B8DDC(b);
        if (r == 1 || r == 1)
            return 1;
    }
    return 0;
}


int func_021E86E8(void *a, int b, int c)
{
    void *x;
    void *y;
    int t;
    u16 h;

    if (func_021E86C8(a, b) != 0)
        return 1;
    if (func_021E869C(a, c) != 0)
        return 1;
    x = func_021C7CF4(a, b);
    y = func_021C7CF4(a, c);
    t = func_021D5444(x);
    h = (int)func_021D5B40(y);
    if (func_021E8638(t, h) != 0)
        return 1;
    return 0;
}


void func_021E8744(int u, void *a, int b, int d)
{
    u8 k;
    u16 m;

    k = func_021D775C(2);
    if (func_021B9A24(k, b) == 0) {
        m = func_021D775C(0x12);
        if (sub_0201C1BC(m) == 0xb) {
            if (func_0201BEB8(m, 4) != 0) {
                if (func_021D76BC(0x22, 0x19) != 0)
                    func_021C8434(a, b, k);
            }
        }
    }
}


void func_021E8798(int u, void *a, int b, int d)
{
    u8 k;
    u16 m;
    int z;

    z = 4;
    if (b == func_021D775C(4)) {
        if (func_021D775C(0x4e) == 0) {
            if (func_021D5C30(func_021C7CF4(a, b)) == 0) {
                m = func_021D775C(0x12);
                if (func_0201BEB8(m, z) != 0) {
                    z = 1;
                    if (func_021D76BC(0x40, 1) != 0) {
                        k = func_021D775C(3);
                        func_021C8434(a, b, k);
                        func_021D76BC(0x51, z);
                    }
                }
            }
        }
    }
}


void func_021E8804(int u, void *a, int b, int d)
{
    u8 *p;
    int z;

    z = 2;
    if (b == func_021D775C(2)) {
        if (func_021D5C30(func_021C7CF4(a, b)) == 0) {
            p = func_021C88A4(a, 4, b);
            func_021C8838(p + 4, z, 0x2fc);
            func_021C8860((struct S *)(p + 4), b);
            func_021C8860((struct S *)(p + 4), func_021D775C(0x12));
            func_021C88C8(a, p);
        }
    }
}


void func_021E8860(int n)
{
    n *= func_021D775C(0x30);
    func_021D76BC(0x30, n);
}


void func_021E8878(int a, int b, int c)
{
    if (func_021B9A24((u8)func_021D775C(2), c) != 0)
        func_021D76BC(0x51, 1);
}


int func_021E889C(int a, int b, int c)
{
    if (func_021B9A24((u8)func_021D775C(2), c) != 0) {
        if (func_021D76BC(0x51, 1) != 0)
            return 1;
    }
    return 0;
}


void func_021E88CC(void)
{
    if (OS_GetConsoleType() & 0x02000000) {
        sub_02034AC4((int)ov140_id);
        d_021F6380 = 1;
    } else {
        d_021F6380 = 0;
    }
}


void func_021E88F8(void)
{
    if (d_021F6380 != 0) {
        sub_02034A5C((int)ov140_id);
        d_021F6380 = 0;
    }
}


/*
 * Returns 0 with a 4-byte frame that nothing ever stores to.  Taking the address of a local array forces the slot, and the optimizer then removes both the store and the reload (nothing outside can alias it), so the frame and the register-resident value both survive.  A scalar `u32 v = 0; v &= ~7u;` folds to 4 bytes, which is why O28's residue could not reach this; the address-taken local is the missing form.
 */
u32 func_021E8918(void) { u8 b[4]; ((struct Obj12160 *)b)->f0 = 0; return ((struct Obj12160 *)b)->f0 & ~7u; }


int func_021E8928(union Slot s)
{
    if (s.s.kind == 0)
        return 1;
    return 0;
}


/*
 * 2026-10-03 EXACT (wave B3, lane 21): the second pool word is 0xFE0001FF, not
 * 0x000001FF. It is the c:16 clear mask of the func_021E896C struct, so this is
 * func_021E896C with c = 0 and d left zero from the initialiser.
 */
int func_021E8940(u32 a)
{
    struct S_021E8940 s = {0};

    s.a = 2;
    s.b = a & 0x3f;
    s.c = 0;
    return *(int *)&s;
}


int func_021E896C(u32 a, u32 b)
{
    struct S_021E896C s = {0};

    s.a = 2;
    s.b = a & 0x3f;
    s.c = b;
    return *(int *)&s;
}


/*
 * Recursive MATCH unblocker: named callee of the parked ov093 func_021DF0C4
 * (+0080, `func_021E899C(c)` stored at record +8).  Packs a 3-bit constant
 * (3) with the low six bits of the argument shifted left by three, as a
 * bitfield union read back as a word; the empty frame is the compiler's
 * storage for the union local, and `= {0}` is what emits `movs r2,#0`
 * instead of reading the uninitialised slot back.
 *
 * Addresses are Black-image addresses.
 */
int func_021E899C(u32 a)
{
    struct S_021E899C s = {0};

    s.a = 3;
    s.b = a & 0x3f;
    return *(int *)&s;
}


int func_021E89C0(void)
{
    struct S_021E89C0 s = {0};

    s.a = 1;
    return *(int *)&s;
}

int func_021E89D4(u32 a)
{
    struct S_021E89D4 s = {0};
    s.a = 1;
    s.c = a;
    return *(int *)&s;
}

/*
 * Unlabelled leaf, the only blocker of func_021D7C70's MATCH (case 1 of its
 * kind switch).  Sibling of func_021E899C: packs kind 1, a 6-bit field and a
 * 16-bit field into a one-word bitfield.
 */
int func_021E89F8(u32 a, u32 b)
{
    struct S_021E89F8 s = {0};
    s.a = 1;
    s.b = a & 0x3f;
    s.c = b;
    return *(int *)&s;
}


int func_021E8A28(u32 a, u32 b)
{
    struct S_021E8A28 s = {0};

    s.a = 4;
    s.b = b & 0x3f;
    s.c = a & 0x3f;
    return *(int *)&s;
}


int func_021E8A58(void)
{
    struct S_021E8A58 s = {0};

    s.a = 1;
    s.b = 0xf;
    return *(int *)&s;
}


int func_021E8A78(union Slot s)
{
    if (s.s.kind == 1 && s.s.lo == 0xf)
        return 1;
    return 0;
}
