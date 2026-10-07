/*
 * file:     btl_server_p52.c
 * unit:     yes
 * function: func_021C1D60, func_021C1DCC, func_021C1E14, func_021C1E74, func_021C2048, func_021C20BC, func_021C20D0
 * address:  0x021C1D60
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
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021C76F4  0x021C76F4  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C7780  0x021C7780  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D7B3C  0x021D7B3C  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021C78F4  0x021C78F4  thumb  ov093
 *   func_021C3370  0x021C3370  thumb  ov093
 *   func_021C334C  0x021C334C  thumb  ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D7674 0x021D7674 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021C728C 0x021C728C thumb ov093
 *   func_021C7374 0x021C7374 thumb ov093
 *   func_021C7474 0x021C7474 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D7A44 0x021D7A44 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021D7C38 0x021D7C38 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021C75EC 0x021C75EC thumb ov093
 *   func_021D7A6C 0x021D7A6C thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C6CAC  0x021C6CAC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7330 0x021C7330 thumb ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 *   func_021C4F64  0x021C4F64  thumb  ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 */
#include "../../matched/include/Obj09967.h"

struct UtilWork;
struct Unk021D62A8;
struct S;
struct Msg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern int func_021C76F4(u8 *p, u8 *q, u32 n);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C7780(u8 *p, u8 *q);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u32 sub_0201C1BC(u16 move);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 func_021D7B3C(u32 a, u32 b);
extern void func_021C5D88(u8 *p, u8 *a, int b);
extern u16 func_021C78F4(u8 *p, u8 *a, u8 *b, u32 s);
extern int func_021C3370(u8 *p, void *q);
extern int func_021C334C(u8 *p, u8 *q, int a, int b);
extern int func_0201C1E8(int a);
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *);
extern void func_021D75EC(int, u32);
extern void func_021D75A8(int, u32);
extern void func_021D7674(int, u32, u32, u32);
extern void func_021D70F0(void *a, int id);
extern u32 func_021D775C(int);
extern void func_021D7540(int);
extern u16 func_021C728C(u8 *, u8 *, u8 *, u8 *);
extern u16 func_021C7374(u8 *p, u8 *a, u8 *b, u8 *c, int flag);
extern u16 func_021C7474(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag);
extern int func_021D59B4(u8 *, int);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D7B10(u32, u32);
extern int func_021C2AB0(u8 *);
extern u32 func_021D7C38(int a, int b);
extern int func_021B911C(void *, int);
extern u32 func_021D78AC(u32);
extern int func_021C75EC(u8 *, u8 *, int);
extern u32 func_021D7A6C(u32, u32);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D5B68(void *p);
extern int func_021C6CAC(u8 *p, u8 *a, u32 b, u32 c, int *out);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern int func_021C7330(u8 *, u8 *);
extern void func_021C5B74(u8 *p, u8 *a, int c, int k);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C8810(u8 *l);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern int func_021C4F64(u8 *p, u8 *a);
extern int func_021BC2B0(u8 *p);
int func_021C1D60(u8 *p, u8 *q, u32 n);
void func_021C1DCC(u8 *p, u8 *q, u32 a, u8 *b, u32 s);
int func_021C1E14(u8 *p, u8 *q, u32 a, u32 b);
int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);
void func_021C2048(u8 *p, u8 *a, u32 b, u32 c);
int func_021C20BC(u8 *p, u8 *a, int r);
int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);


int func_021C1D60(u8 *p, u8 *q, u32 n)
{
    if (func_021D5BB0((struct UtilWork *)q, 5)) {
        func_021D5FC0((struct UtilWork *)q, 6);
        return 1;
    }
    if (func_021C76F4(p, q, n)) {
        func_021D5FC0((struct UtilWork *)q, 4);
        return 1;
    }
    if (n >= 100) {
        u32 s = func_021CC8D8(p + 0x1D74, 7085);
        func_021C7780(p, q);
        func_021CC95C((u32 *)(p + 0x1D74), s, 7087);
    }
    return 0;
}


void func_021C1DCC(u8 *p, u8 *q, u32 a, u8 *b, u32 s)
{
    if (sub_0201C1BC(((struct Obj09967 *)q)->f0) == 8) {
        if (func_021C1E14(p, (u8 *)a, (u32)b, (u16)func_021D7B3C(s, sub_0201BD28(((struct Obj09967 *)q)->f0, 0x19)))) {
            func_021C5D88(p, b, 0x383);
        }
    }
}


int func_021C1E14(u8 *p, u8 *q, u32 a, u32 b)
{
    u32 s = func_021CC8D8(p + 0x1D74, 7154);
    int r = 0;
    u8 *t = (u8 *)func_021C78F4(p, q, (u8 *)a, b);
    if (t) {
        if (func_021C3370(p, q) == 0) {
            r = func_021C334C(p, q, (int)t, 1);
        }
    }
    func_021CC95C((u32 *)(p + 0x1D74), s, 7168);
    return r;
}

/*
 *   Call +0x10 has no witness outside 021C1E74..021C2048; all concrete
 *   bytes match, and the other 39 relocation sites resolve.
 *   Verified one --thumb, no --region, dsi/1.1p1 -O4,p: EXACT, 12 bytes.
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 sub_0201BD28(u16, u32);
 * lever: a separately narrowed u8 level local avoids the extra r0-to-r2
 *   copy from narrowing an inline call argument. value * scale selects
 *   the original multiplication destination; scale * value adds a copy.
 */
int func_021C1E74(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out)
{
    int category = func_0201C1E8(*(u16 *)c);
    int flag = 0;
    u32 result;
    u32 x;
    u32 y;
    u32 value;
    u32 factor;
    u16 scale;
    u8 level;
    func_021D74F8(0x1c21);
    func_021D75EC(0x38, d);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x45, f);
    func_021D75EC(0x16, c[6]);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x1a, category);
    func_021D75A8(0x37, 0);
    func_021D70F0(p, 0x46);
    result = func_021D775C(0x37);
    if (result) {
        flag = 1;
    } else {
        x = func_021C728C(p, a, b, c);
        y = func_021C7374(p, a, b, c, f);
        value = func_021C7474(p, a, b, c, f);
        level = func_021D59B4(a, 15);
        value = func_021D7A44(x, y, level, value);
        if (e != 0x1000) value = func_021D7B10(value, e);
        factor = func_021D7C38(func_021C2AB0(p), c[6]);
        if (factor != 0x1000) value = func_021D7B10(value, factor);
        if (f) value *= 2;
        if (!func_021B911C(*(void **)(p + 4), 7)) {
            if (g) scale = 85;
            else scale = 100 - func_021D78AC(16);
            value = (u32)(value * scale) / 100u;
        }
        if (c[6] != 17) value = func_021D7B10(value, func_021C75EC(p, a, c[6]));
        value = func_021D7A6C(value, d);
        if (category == 1 && func_021D62A8((struct Unk021D62A8 *)a) == 4 && func_021D59B4(a, 17) != 62) {
            value = (u32)(50u * value) / 100u;
        }
        if (!value) value = 1;
        func_021D7674(0x35, 0x1000, 0x29, 0x20000);
        func_021D75A8(0x32, value);
        func_021D70F0(p, 0x47);
        factor = func_021D775C(0x35);
        result = func_021D7B10(func_021D775C(0x32), factor);
    }
    func_021D70F0(p, 0x48);
    func_021D7540(0x1c8d);
    *out = result;
    return flag;
}


void func_021C2048(u8 *p, u8 *a, u32 b, u32 c)
{
    int loc;
    int r;
    if (func_021D5B68(a) != 0)
        return;
    r = func_021C6CAC(p, a, b, c, &loc);
    if (r == 0)
        return;
    func_021C8838(p + 0x1AE4, 2, 378);
    func_021C8860((struct S *)(p + 0x1AE4), func_021D5440(a));
    if (loc == 0 && func_021C20BC(p, a, r) == 0)
        return;
    func_021C20D0(p, a, r, p + 0x1AE4);
}

/*
 * extent: two zero alignment bytes follow the return at 0x021C20CE.
 */
int func_021C20BC(u8 *p, u8 *a, int r)
{
    if (func_021C7330(p, a))
        return 1;
    return 0;
}


int func_021C20D0(u8 *p, u8 *a, int c, u8 *l)
{
    int r;
    c = -c;
    if (c != 0) {
        func_021C5B74(p, a, c, 1);
        func_021D5FC0((struct UtilWork *)a, 2);
        if (l != 0) {
            func_021C99A0(p, (const struct Msg *)l);
            func_021C8810(l);
        }
        r = 1;
        func_021C195C(p, a, 1);
        if (func_021C4F64(p, a) != 0) {
            func_021BC2B0(p);
            return r;
        }
        return r;
    }
    return 0;
}
