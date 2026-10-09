/*
 * file:     fldmmdl_blact_p09.c
 * unit:     yes
 * function: func_0219E354, func_0219E370, func_0219E398, func_0219E418, func_0219E424, func_0219E498, func_0219E570, func_0219E634, func_0219E664, func_0219E6C8, func_0219E764
 * address:  0x0219E354
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_0219EA78  0x0219EA78  thumb  ov021
 *   func_0219E938  0x0219E938  thumb  ov021
 *   func_0219E940  0x0219E940  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_021BB3C4  0x021BB3C4  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_021B7E60  0x021B7E60  thumb  ov021
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_021B8040  0x021B8040  thumb  ov021
 *   func_021B8038  0x021B8038  thumb  ov021
 *   func_021B7ED4  0x021B7ED4  thumb  ov021
 *   func_021B83B0  0x021B83B0  thumb  ov021
 *   func_0219E334  0x0219E334  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7C90  0x021B7C90  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0219E784  0x0219E784  thumb  ov021
 */
#include "../../matched/include/Obj17975.h"

struct Sub;
struct Ctx;
struct Rec;
struct Mgr;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

extern void *func_0216D69C(void *p);
extern void func_021B810C(struct Sub *o);
extern u32 func_0219EA78(u32 *p, u32 a1);
extern u32 func_0219E938(int a0);
extern u32 func_0219E940(int x);
extern void func_021B80E0(void *p, u32 a, u32 b);
extern void *func_0216D67C(void *a0);
extern void *func_0216D530(void *p);
extern int func_021B7DE0();
extern int func_0216DCB4(void *a0);
extern u32 func_021BB3C4(u8 *p, char *a1);
extern u16 func_021AB0F8(u32 attr);
extern u16 func_0216D5F8(void *p);
extern void *func_021BB480(void *p);
extern u32 func_021B7DC0();
extern int func_021B7E60();
extern int func_021B7CD8();
extern void func_021B7D38();
extern int func_021B7C38(u8 *o);
extern u32 func_0207C768(u32 a, u32 b);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D55C(int a0, int a1);
extern void *func_0219E348(void *a);
extern u8 func_021B8040(u8 *p);
extern u8 func_021B8038(u8 *p);
extern void func_021B7ED4();
extern int func_021B83B0(const s32 *a, const s32 *b, s32 r);
extern int func_0219E334(u32 a, u32 b);
extern void func_0219E2F4(void *o, void *out);
extern u8 func_0201441C(int i);
extern int func_021B7C90(struct Mgr *m, void *r, void *key, void *q);
extern int func_0216D83C(void *p);
extern void func_0216D80C();
extern int func_0216D854(void *p);
extern void func_0216D818();
extern int func_0216D86C(void *p);
extern void func_0216D824();
extern void func_0216D844(void *p, short v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern u32 func_0219E784(u32, u32, u32);
void func_0219E354(u32 a);
void func_0219E370(u32 a, u32 b, u32 c);
u32 func_0219E398(u32 o, u32 a, char *b, u32 *out);
int func_0219E418(u32 a, u32 b);
int func_0219E424(u32 o, u32 k, u32 x);
int func_0219E498(u32 o, u32 k);
u32 func_0219E570(u32 o, u32 k, u32 flag);
int func_0219E634(void *a, u32 b);
int func_0219E664(void *o, u32 k, void *buf);
void func_0219E6C8(u32 o, u16 id);
int func_0219E764(u32 a, u32 b);




/*
 * Addresses are Black-image addresses.
 */
void func_0219E354(u32 a)
{
    u32 *p = func_0216D69C((void *)a);
    func_021B810C((void *)*p);
    func_0219EA78(p, a);
}




void func_0219E370(u32 a, u32 b, u32 c)
{
    u32 *p = func_0216D69C((void *)a);
    u32 x = func_0219E938(b);
    func_021B80E0((void *)*p, func_0219E940(c), x);
}




u32 func_0219E398(u32 o, u32 a, char *b, u32 *out)
{
    u32 r;
    u32 **p;
    u32 v;

    r = 0;
    p = func_0216D69C((void *)o);
    v = (u32)func_0216D530(func_0216D67C((void *)o));
    if (!func_021B7DE0(*p, a)) {
        r |= 1;
    }
    if (!func_021B7DE0(*p, b)) {
        r |= 1;
    }
    if (!func_0216DCB4((void *)o)) {
        p = (u32 **)func_021BB3C4((u8 *)v, b);
        if (func_021AB0F8((u32)p) & 1) {
            r |= 2;
        }
        if (out) {
            *out = (u32)p;
        }
    }
    if (func_0219E498(o, (u32)b)) {
        r |= 4;
    }
    return r;
}




/*
 * Tail-call thunk: pins the third argument to 0.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E418(u32 a, u32 b)
{
    return func_0219E424(a, b, 0);
}




int func_0219E424(u32 o, u32 k, u32 x)
{
    u32 v;
    u32 **p;
    u32 a[2];
    u32 b[2];
    int r;
    u32 t;

    v = (u32)func_021BB480(func_0216D530(func_0216D67C((void *)o)));
    p = func_0216D69C((void *)o);
    func_021B7DC0(*p, a);
    t = func_0216D5F8((void *)o);
    if (t == k) {
        r = func_021B7E60(*p, func_0219E938(k), b, 0);
    } else {
        r = func_021B7CD8(v, a, func_0219E938(k), b);
    }
    if (r) {
        return func_0219E398(o, (u32)a, (char *)b, (u32 *)x);
    }
    return 1;
}




/*
 * Addresses are Black-image addresses.
 * EXACT* is the 2-byte alignment pad after the last pop.
 */
int func_0219E498(u32 o, u32 k)
{
    u32 t;
    u32 h;
    u32 m;
    u8 rec[12];
    u8 tA[12];
    u32 cur;
    u32 st;
    u32 lim;
    u32 s;
    int z;

    s = (u32)func_0216D67C((void *)o);
    h = (u32)func_021BB480(func_0216D530((void *)s));
    st = 0;
    func_021B7D38(h, k, rec);
    m = func_0207C768(func_021B7C38((u8 *)h), 0x4000);
    while (func_0216DD1C((struct Ctx *)s, (struct Rec **)(&cur), &st) == 1) {
        lim = 0x4000 >> 1;
        if (cur == o) {
            continue;
        }
        if (func_0216D55C(cur, 0x80) != 0) {
            continue;
        }
        z = (func_0216D55C(cur, lim) == 0);
        if (!z) {
            t = (u32)func_0219E348((void *)cur);
            if (func_021B8040((u8 *)t)) {
                func_021B7E60(t, func_021B8038((u8 *)t), 0, tA);
                if (func_021B83B0((const s32 *)rec, (const s32 *)tA, m)) {
                    return 1;
                }
            }
            func_021B7ED4(t, tA);
            if (func_021B83B0((const s32 *)rec, (const s32 *)tA, m)) {
                return 1;
            }
        }
    }
    return 0;
}




u32 func_0219E570(u32 o, u32 k, u32 flag)
{
    u32 h;
    u32 m;
    u8 rec[12];
    u8 buf[12];
    u32 st;
    u32 cur;
    u8 tB[8];
    u8 tA[8];
    u32 lim;
    int z;

    st = 0;
    h = (u32)func_021BB480(func_0216D530((void *)o));
    func_021B7D38(h, k, rec);
    m = func_0207C768(func_021B7C38((u8 *)h), 0x4000);
    while (func_0216DD1C((struct Ctx *)o, (struct Rec **)(&cur), &st) == 1) {
        lim = 0x4000 >> 1;
        z = (func_0216D55C(cur, lim) == 0);
        if (!z) {
            if (flag) {
                func_0219E334(cur, (u32)tB);
                func_021B7D38(h, tB, buf);
                if (func_021B83B0((const s32 *)rec, (const s32 *)buf, m)) {
                    return cur;
                }
            }
            func_0219E2F4((void *)cur, tA);
            func_021B7D38(h, tA, buf);
            if (func_021B83B0((const s32 *)rec, (const s32 *)buf, m)) {
                return cur;
            }
        }
    }
    return 0;
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E634(void *a, u32 b)
{
(u32)func_0216D530((void *)((u32)func_0216D67C((void *)a)));
return func_021B7E60(((struct Obj17975 *)((u8 *)(func_0216D69C((void *)a))))->f0, func_0201441C(func_0216D5F8((void *)a)), b, 0);
}




/*
 * Addresses are Black-image addresses.
 */
int func_0219E664(void *o, u32 k, void *buf)
{
    void *h;
    u32 t;
    void **p;

    h = func_021BB480(func_0216D530(func_0216D67C(o)));
    t = func_0216D5F8(o);
    p = func_0216D69C(o);
    if (t != k) {
        func_0219E2F4(o, buf);
        return func_021B7CD8(h, buf, func_0201441C(k), buf);
    }
    return func_021B7E60(*p, func_0201441C(k), buf, 0);
}




void func_0219E6C8(u32 o, u16 id)
{
    u32 h;
    s32 v[3];
    u32 a[2];

    h = (u32)func_021BB480(func_0216D530(func_0216D67C((void *)o)));
    func_0219E2F4((void *)o, a);
    func_021B7C90((struct Mgr *)h, a, (void *)func_0201441C(id), v);
    func_0216D80C(o, func_0216D83C((void *)o));
    func_0216D818(o, func_0216D854((void *)o));
    func_0216D824(o, func_0216D86C((void *)o));
    func_0216D844((void *)o, (v[0] >> 4) / 4096);
    func_0216D85C((void *)o, (s16)((v[1] >> 4) / 4096));
    func_0216D874((u32)o, (s16)((v[2] >> 4) / 4096));
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219E764(u32 a, u32 b)
{
func_0219E348((void *)a);
return func_0219E784(a, (((u32)func_0216D5F8((void *)a) << 16) >> 16), b);
}
