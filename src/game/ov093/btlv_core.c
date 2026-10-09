/*
 * file:     btlv_core.c
 * unit:     yes
 * function: func_021E869C, func_021E86C8, func_021E86E8, func_021E8744, func_021E8798, func_021E8804, func_021E8860, func_021E8878, func_021E889C, func_021E88CC, func_021E88F8, func_021E8918, func_021E8928, func_021E8940, func_021E896C, func_021E899C, func_021E89C0, func_021E89D4, func_021E89F8, func_021E8A28, func_021E8A58, func_021E8A78, func_021E8A98, func_021E8AC8, func_021E8AFC, func_021E8B28, func_021E8B80, func_021E8BD0, func_021E8C24, func_021E8C50, func_021E8C9C, func_021E8CE0, func_021E8CF0, func_021E8CFC, func_021E8D04, func_021E8D0C, func_021E8D24, func_021E8D48, func_021E8DA8, func_021E8DC4, func_021E8DF8, func_021E8E28, func_021E8E38, func_021E8F08, func_021E8F20
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
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_0208068C  0x0208068C  arm
 *   func_0203D29C  0x0203D29C  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   d_021F387C 0x021F387C data a4
 *   d_021F3850 0x021F3850 data a4
 *   d_021F3860 0x021F3860 data a4
 *   func_021F7808  0x021F7808  thumb  ov094
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02046788  0x02046788  arm
 *   func_02030734 0x02030734 arm
 *   func_021D3D70 0x021D3D70 thumb ov093
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_021EAF7C 0x021EAF7C thumb ov093
 *   func_021E9024 0x021E9024 thumb ov093
 *   func_021EEC78 0x021EEC78 thumb ov093
 *   d_021F3AC4 0x021F3AC4 data a4
 */
#include "../../matched/include/Obj12160.h"

#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
struct QF;
struct QI;
struct UtilWork;
struct S;
struct DispConfig;
struct DispVram;
struct Cfg;
struct GfFont;
struct Tcbl;
struct U16Vec;
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

union Slot_021E8A98 {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

union Slot_021E8AC8 {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

union Slot_021E8AFC {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};

union U_021E869C {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

union Unk021E8B80 {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

union U_021E8BD0 {
    struct { u32 kind : 3; u32 pad : 22; u32 f : 1; u32 rest : 6; } a;
    struct { u32 kind : 3; u32 pad : 28; u32 f : 1; } b;
};

union U {
    struct { u32 kind : 3; u32 f : 6; u32 rest : 23; } a;
};

struct Scene {
    void *a, *b;
    u32 c;
    u8 index, pad0d[3];
    int state, f14, f18;
    u8 pad1c[0x90];
    void *buffer, *font0, *font2;
    u8 padb8[0xbc];
    u8 flag, pad175[3];
    void *ctx, *view, *other;
    u16 heap;
    u8 pad186[2];
};

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
extern int func_02034AC4(int id);
extern void func_0208068C(unsigned int v);
extern u32 func_0203D29C(void);
extern void func_02034A5C(int id);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02046440(u32, u32, u32, u32, u16, u16, void (*)(void));
extern void func_02046BE0(u32, u32);
extern void func_0207DC44(int, int, int, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_021F7808(void);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02046788(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 func_021D3D70(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *func_021EAF7C(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u8 e2, int heap);
extern void *func_021E9024(struct Scene *, void *, u32, void *, void *, void *, int, u16);
extern void func_021EEC78(u32, u32, u32, u32);
int func_021E869C(void *a, int b);
int func_021E86C8(void *a, int b);
int func_021E86E8(void *a, int b, int c);
void func_021E8744(int u, void *a, int b, int d);
void func_021E8798(int u, void *a, int b, int d);
void func_021E8804(int u, void *a, int b, int d);
void func_021E8860(int n);
void func_021E8878(int a, int b, int c, int d);
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
u8 func_021E8A98(union Slot_021E8A98 s);
void func_021E8AC8(union Slot_021E8AC8 *p, u8 v);
u8 func_021E8AFC(union Slot_021E8AFC s);
void func_021E8B28(union U_021E869C *p, u16 v);
u16 func_021E8B80(union Unk021E8B80 v);
void func_021E8BD0(union U_021E8BD0 *p, int v);
u32 func_021E8C24(union U_021E8BD0 v);
void func_021E8C50(union U *p, u32 v);
void func_021E8C9C(union U *p, int v);
u16 func_021E8CE0(u32 a, u32 b);
int func_021E8CF0(int a);
u8 func_021E8CFC(s32 v);
int func_021E8D04(int x);
void func_021E8D0C(int x, unsigned char *a, unsigned char *b);
int func_021E8D24(int x, int k);
int func_021E8D48(int a, int b);
int func_021E8DA8(int x);
void func_021E8DC4(unsigned short heap);
void func_021E8DF8(void);
void func_021E8E28(u16 heap);
void func_021E8E38(u16 heap);
void func_021E8F08(void);
struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern u8 ov140_id[];
extern int d_021F6380;
extern char ov094_id[], ov095_id[], ov096_id[];
extern const u32 d_021F387C[], d_021F3850[], d_021F3860[];
extern const char d_021F3AC4[];





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





void func_021E8878(int a, int b, int c, int d)
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





u8 func_021E8A98(union Slot_021E8A98 s)
{
    if (s.s.kind == 3)
        return s.s.lo;
    if (s.s.kind == 4)
        return s.s.hi;
    return 0x1f;
}





void func_021E8AC8(union Slot_021E8AC8 *p, u8 v)
{
    if (p->s.kind == 3)
        p->s.lo = v;
    else if (p->s.kind == 4)
        p->s.hi = v;
}




u8 func_021E8AFC(union Slot_021E8AFC s)
{
    if (s.s.kind == 2) return s.s.lo;
    if (s.s.kind == 4) return s.s.lo;
    return 0;
}




void func_021E8B28(union U_021E869C *p, u16 v)
{
    if (p->a.kind == 1) p->a.id = v;
    else if (p->a.kind == 3) p->a.id = v;
    else if (p->a.kind == 4) p->b.id = v;
    else if (p->a.kind == 2) p->a.id = v;
}





u16 func_021E8B80(union Unk021E8B80 v)
{
    if (v.a.kind == 1) return v.a.id;
    if (v.a.kind == 3) return v.a.id;
    if (v.a.kind == 4) return v.b.id;
    if (v.a.kind == 2) return v.a.id;
    return 0;
}


void func_021E8BD0(union U_021E8BD0 *p, int v)
{
    if (p->a.kind == 1) p->a.f = v;
    else if (p->a.kind == 3) p->a.f = v;
    else if (p->a.kind == 4) p->b.f = v;
    else if (p->a.kind == 2) p->a.f = v;
}



u32 func_021E8C24(union U_021E8BD0 v)
{
    if (v.a.kind == 1) return v.a.f;
    if (v.a.kind == 3) return v.a.f;
    if (v.a.kind == 4) return v.b.f;
    if (v.a.kind == 2) return v.a.f;
    return 0;
}







void func_021E8C50(union U *p, u32 v)
{
    if (p->a.kind == 2 && p->a.f < 8) p->a.f = p->a.f + v;
    if (p->a.kind == 4 && p->a.f < 8) p->a.f = p->a.f + v;
}







void func_021E8C9C(union U *p, int v)
{
    if (p->a.kind == 2 && p->a.f < 8) p->a.f = v;
    if (p->a.kind == 4 && p->a.f < 8) p->a.f = v;
}








/* 021E8CE0  ((a & 0xff) << 8) | (b & 0xff) as u16 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: lsls r0, r0, #0x18; lsrs r2, r0, #0x10; lsls r0, r1, #0x18; lsrs r0, r0, #0x18; orrs r0, r2; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 func_021E8CE0(u32 a, u32 b) { return (u16)(((a & 0xff) << 8) | (b & 0xff)); }








int func_021E8CF0(int a)
{
    return func_021E8CE0(a, a);
}








/* 021E8CFC  asrs r0,r0,#8; lsls #0x18; lsrs #0x18 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: asrs r0, r0, #8; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 func_021E8CFC(s32 v) { return (u8)(v >> 8); }






int func_021E8D04(int x)
{
    return (unsigned char)x;
}







void func_021E8D0C(int x, unsigned char *a, unsigned char *b)
{
    *a = func_021E8CFC(x);
    *b = func_021E8D04(x);
}







int func_021E8D24(int x, int k)
{
    if (k == func_021E8CFC(x)) {
        return 1;
    }
    if (k == func_021E8D04(x)) {
        return 1;
    }
    return 0;
}







int func_021E8D48(int a, int b)
{
    if (func_021E8CFC(a) == func_021E8CFC(b)) return 1;
    if (func_021E8CFC(a) == func_021E8D04(b)) return 1;
    if (func_021E8D04(a) == func_021E8CFC(b)) return 1;
    if (func_021E8D04(a) == func_021E8D04(b)) return 1;
    return 0;
}







int func_021E8DA8(int x)
{
    if (func_021E8CFC(x) == func_021E8D04(x)) {
        return 1;
    }
    return 0;
}





void func_021E8DC4(unsigned short heap)
{
    func_021E8E38(heap);
    func_02034AC4((int)ov094_id);
    func_0208068C(0x80);
    func_02034AC4((int)ov095_id);
    if (func_0203D29C() == 0) {
        func_02034AC4((int)ov096_id);
    }
}





void func_021E8DF8(void)
{
    func_021E8F08();
    func_02034A5C((int)ov094_id);
    func_02034A5C((int)ov095_id);
    if (func_0203D29C() == 0) {
        func_02034A5C((int)ov096_id);
    }
}





/*
 * wrapper over func_021E8F08, func_021E8E38
 */
void func_021E8E28(u16 heap)
{
    func_021E8F08();
    func_021E8E38(heap);
}



/*
 * lever: the POWCNT read/OR/write is spelled as assignment, not compound assignment.
 * volatile: 021E8E60 POWCNT; 021E8E8E,021E8E9C,021E8EA4 DISP3DCNT; 021E8EBE BG0CNT.
 */
void func_021E8E38(u16 heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021F387C);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28((struct DispConfig *)d_021F3850);
    func_02046440(0, 1, 0, 1, 0, heap, 0);
    func_02046BE0(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    func_0207DC44(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0207D63C((void *)0x04000050, 2, 0x3d, 0x1f, 3);
    func_0204A48C((const struct Cfg *)d_021F3860, (u32)d_021F387C, heap);
}




void func_021E8F08(void)
{
    func_021F7808();
    func_0204A5AC();
    func_020450C8();
    func_0203F9B4();
    func_02046788();
}



struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap)
{
    struct Scene *p;
    p = func_02030734(heap, 0x188, 0, d_021F3AC4, 0x12d);
    p->a = a;
    p->b = b;
    p->c = c;
    p->index = func_021D3D70(b);
    p->state = 4;
    p->heap = heap;
    p->buffer = func_020457B0(0x200, heap);
    p->font0 = func_0201D7EC(0x17, 0, 0, 0, heap);
    p->font2 = func_0201D7EC(0x17, 2, 0, 0, heap);
    p->ctx = func_0203101C(heap, heap, 0x40, 0x80);
    p->view = func_021EAF7C((u32)p, (u32)p->a, c, (u32)p->ctx, (u32)p->font0, (u32)p->font2, p->index, heap);
    p->other = func_021E9024(p, p->a, c, p->ctx, p->font0, p->b, d, heap);
    p->f14 = 0;
    p->f18 = 0;
    p->flag = 0;
    func_021EEC78((u32)a, p->index, c, heap);
    return p;
}
