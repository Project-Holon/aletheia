/*
 * file:     ctvt_comm_p12.c
 * unit:     yes
 * function: func_021B9580, func_021B97AC, func_021B99B4, func_021B99F4, func_021B9AB8, func_021B9B88, func_021B9C1C, func_021B9C9C, func_021B9D04, func_021B9DF8, func_021B9E3C
 * address:  0x021B9580
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021B7B3C 0x021B7B3C thumb ov172
 *   func_021BA270 0x021BA270 thumb ov172
 *   func_021B8B5C 0x021B8B5C thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021B9F4C 0x021B9F4C thumb ov172
 *   func_021BE0B8 0x021BE0B8 thumb ov172
 *   func_021BE0A4 0x021BE0A4 thumb ov172
 *   func_021B77B4 0x021B77B4 thumb ov172
 *   func_021BE08C 0x021BE08C thumb ov172
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021C6F83 0x021C6F83 data a1
 *   d_021C6F77 0x021C6F77 data a1
 *   func_021BA0BC 0x021BA0BC thumb ov172
 *   func_021B69E0 0x021B69E0 thumb ov172
 *   func_0203630C 0x0203630C arm
 *   func_021BA120 0x021BA120 thumb ov172
 *   func_021BA158 0x021BA158 thumb ov172
 *   func_021BA170 0x021BA170 thumb ov172
 *   func_021BA15C 0x021BA15C thumb ov172
 *   func_021B9E5C 0x021B9E5C thumb ov172
 *   func_021B8C34 0x021B8C34 thumb ov172
 *   func_021B8B74 0x021B8B74 thumb ov172
 *   func_021BA174 0x021BA174 thumb ov172
 *   func_021B891C 0x021B891C thumb ov172
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_0200616C 0x0200616C thumb
 *   func_02006268 0x02006268 thumb
 *   d_021C6F8F 0x021C6F8F data a1
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C95C 0x0209C95C arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   d_021C6FA0 0x021C6FA0 data a2
 *   d_021C6F66 0x021C6F66 data a2
 *   func_021BE034 0x021BE034 thumb ov172
 *   func_021BE03C 0x021BE03C thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_021B80E4 0x021B80E4 thumb ov172
 *   func_021BE11C 0x021BE11C thumb ov172
 *   func_0204B98C 0x0204B98C arm
 *   func_02027858  0x02027858  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7B80  0x021B7B80  thumb  ov172
 *   func_021BE0B0  0x021BE0B0  thumb  ov172
 *   func_021BE0D0  0x021BE0D0  thumb  ov172
 */
#include "../../matched/include/Obj06561.h"
#include "../../matched/include/Obj00998.h"
#include "../../matched/include/Obj05446.h"
#include "../../matched/include/Obj08259.h"
#include "../../matched/include/Obj10664.h"

struct Obj;
struct CharBuf;
struct Descriptor;
struct Cfg;
struct MsgBank;
struct PrintSys;
struct U16Vec;
struct Actor;
struct TaskMenu;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Rec {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct St {
    u32 state;
    u32 sub;
    u8 pad08[5];
    u8 b0d;
    u8 pad0e[2];
    u32 *f10;
    u32 f14;
    u8 b18;
    u8 pad19[7];
    struct Rec *f20;
    void *f24;
    u8 pad28[4];
    void *f2c;
    u8 pad30[0x74];
    u32 fa4;
};

typedef short s16;

typedef signed int     s32;

extern u32 func_021BDFE4(void *);
extern u8 func_021BE054(void *p);
extern u32 func_021BE0B4(void *);
extern u32 func_021BDFDC(void *);
extern void func_021B7B3C(int x, int y, int z);
extern int func_021BA270(void *p);
extern u32 func_021B8B5C(void *, u32);
extern u8 func_021B8B68(int unused, char *p);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern int func_021B9F4C(int a, int b, int mode);
extern void func_021BE0B8(void *);
extern u32 func_021BE0A4(void *);
extern u32 func_021B77B4(int unused, void *p);
extern void func_021BE08C(void *);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32);
extern void func_0204B878(struct Obj *, u16);
extern void func_0204B92C(struct Obj *, u32);
extern int func_021BA0BC(u32 *p);
extern void func_021B69E0(void);
extern u32 func_0203630C(void);
extern int func_021BA120(u32 *p);
extern u32 func_021BA158(u32 *p);
extern u32 func_021BA170(u32 *p);
extern u32 func_021BA15C(u32 *p);
extern void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
extern u32 func_021B8C34(void *ctx, u8 *rec);
extern int func_021B8B74(void *ctx, u8 *rec);
extern int func_021BA174(int unused, void *a, void *buf, unsigned n);
extern int func_021B891C(void *a, char *q, u16 *p);
extern int func_021BDFEC(void *ctx);
extern u32 func_021BA244(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern int func_02035BA4(const void *);
extern void func_0200616C(void *, int);
extern void func_02006268(int i, u32 a, u32 b, u32 c);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0209C0A4(int a, int b);
extern u32 func_021BE034(void *);
extern u32 func_021BE03C(void *);
extern u32 func_021BE044(void *);
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_021B80E4(int, char *);
extern u32 func_021BE11C(u8 *p);
extern u32 func_0204B98C(struct Actor *);
extern void func_02027858(struct TaskMenu *m);
extern void func_02027974(void *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern void func_021BE0B0(void *p, u32 v);
extern u32 func_021BE0D0(void *p);
void func_021B9580(u8 *c, u8 *q);
void func_021B97AC(void *ctx, struct St *st);
void func_021B99B4(void *a0, char *a1);
void func_021B99F4(void *unused, u8 *q);
void func_021B9AB8(int a0, int a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value);
void func_021B9B88(u8 *p, u8 x, u8 y, u8 value);
void func_021B9C1C(void *p, char *q, int id);
void func_021B9C9C(void *p, char *q);
void func_021B9D04(int self, int *q);
int func_021B9DF8(void *p, int *out);
void func_021B9E3C(void *p, char *q);
extern const u8 d_021C6F83[];
extern const u8 d_021C6F77[];
extern const u8 d_021C6F8F[];
extern const u16 d_021C6FA0[4], d_021C6F66[4];


/*
 * note 2026-10-05 wD4 lane03: EXACT. The 0xa4 store is written in each arm (= 2, = 2, = 0)
 *   instead of a local x stored once; tail merging then keeps the later x=2 copy and the first
 *   arm becomes the b stub, as in the listing.
 */
void func_021B9580(u8 *c, u8 *q)
{
    u32 a = func_021BDFE4(c);
    u32 b = func_021BE054(c);
    int r6;

    if (func_021B9DF8(c, (int *)q) == 1)
        return;
    if (*(int *)q <= 8 && func_021BE0B4(c) == 0) {
        u32 s = func_021BDFDC(c);
        if (func_020362DC() & 0x40) func_021B7B3C((int)c, s, 0);
        if (func_020362DC() & 0x10) func_021B7B3C((int)c, s, 5);
        if (func_020362DC() & 0x80) func_021B7B3C((int)c, s, 1);
        if (func_020362DC() & 0x20) func_021B7B3C((int)c, s, 3);
    }
    if (b == 1 || func_021BA270((void *)(*(u32 *)(q + 0x10))) == 0) {
        *(int *)(q + 0xa4) = 2;
    } else {
        u32 t = func_021B8B5C(c, a);
        u32 u = func_021B8B68((int)c, (char *)a);
        if (u != 0xff) {
            if (u == t) {
                u32 k = q[0xc];
                if (k) {
                    k--;
                    q[0xc] = k;
                } else if (func_021B8740((int)c, a, 9, 0) == 1) {
                    q[0xc] = 8;
                }
            }
            *(int *)(q + 0xa4) = 2;
        } else {
            u32 r = func_021B9F4C((int)c, (int)q, 0);
            if ((func_020362DC() & 0x101) || r == 1) {
                *(int *)q = 6;
                func_020061E4(0x66C);
                *(int *)(q + 0x34) = 1;
                q[0x38] = 0;
            }
            *(int *)(q + 0xa4) = 0;
        }
    }
    if (*(int *)q == 5) {
        if ((func_020362DC() & 0x400) || (func_020362DC() & 0x400) || func_02035C08(d_021C6F83) != -1) {
            *(int *)q = 3;
            *(int *)(q + 4) = 6;
            func_0204B878(*(struct Obj **)(q + 0x9c), 0x14);
            func_0204B92C(*(struct Obj **)(q + 0x9c), 1);
            func_020061E4(0x66C);
        }
    }
    if (*(int *)q == 5) {
        r6 = func_02035C08(d_021C6F77);
        if (r6 == 0 || (func_020362DC() & 2)) {
            if (r6 == 0) func_020355D8(1); else func_020355D8(0);
            *(int *)q = 9;
            func_020061E4(0x551);
            func_0204B878(*(struct Obj **)(q + 0x98), 9);
        } else if (r6 == 1 || (func_020362DC() & 0xc)) {
            func_021BE0B8(c);
            func_020061E4(0x66F);
            if (func_021BE0B4(c) == 1)
                func_0204B878(*(struct Obj **)(q + 0x94), 0x15);
            else
                func_0204B878(*(struct Obj **)(q + 0x94), 0x16);
        }
    }
    if (func_021BE0A4(c) == 0 && (func_020362DC() & 0x200)) {
        if (func_021B77B4((int)c, (void *)func_021BDFDC(c)) == 0) {
            func_021BE08C(c);
            func_020061E4(0x66C);
        }
    }
    func_021B99F4(c, q);
}


#pragma opt_propagation off

void func_021B97AC(void *ctx, struct St *st)
{
    int mode = func_021B9F4C((int)ctx, (int)st, 1);
    u32 id;
    u32 pos;
    int busy;
    u32 v;
    u32 off;

    if (func_021B9DF8(ctx, (int *)st) == 1)
        return;
    switch (st->sub) {
    case 0:
        if (func_021BA0BC(st->f10) == 1) {
            st->fa4 = 1;
            st->sub = 1;
            st->b18 = 0;
            st->f14 = 0;
            func_021B69E0();
            func_021B9E3C(ctx, (char *)st);
            return;
        }
        break;
    case 1:
        if (mode != 1 && (func_0203630C() & 0x101) == 0)
            func_021BA120(st->f10);
        if (func_021BA158(st->f10) == 0) {
            st->sub = 2;
            st->fa4 = 2;
        }
        v = func_021BA170(st->f10);
        pos = func_021BA15C(st->f10);
        off = 0x800;
        func_021B9E5C((int)ctx, (char *)st, (s16 *)(v + off), 9, pos, 0xC000);
    case 2:
        id = func_021BDFE4(ctx);
        if (func_021B8C34(ctx, (u8 *)id) != 1)
            break;
        busy = func_021B8B74(ctx, (u8 *)id);
        pos = func_021BA15C(st->f10);
        if (st->f14 == 0 && busy == 0) {
            if (pos >= (u32)(st->b18 + 1) << 11 || st->sub == 2) {
                int n = func_021BA174((int)st->f10, (u8 *)func_021BA170(st->f10) + (st->b18 << 11), st->f24, 0x800);
                st->f20->b5 = st->b18;
                st->f20->h0 = n;
                st->f20->h2 = pos;
                st->f20->b6 = st->b0d;
                st->f20->b4 = (st->sub == 2 && pos <= (u32)(st->b18 + 1) << 11) ? 1 : 0;
                st->f14 = 1;
            }
        }
        if (st->f14 == 1) {
            if (func_021B891C(ctx, (char *)id, (u16 *)st->f20) == 1) {
                st->b18++;
                st->f14 = 0;
                if (st->f20->b4 == 1) {
                    st->sub = 3;
                    return;
                }
            }
        }
        break;
    case 3:
        id = func_021BDFE4(ctx);
        if (func_021B8B74(ctx, (u8 *)id) != 0)
            break;
        if (func_021B8740((int)ctx, id, 7, 0) == 1) {
            st->sub = 4;
            func_02043B5C(func_02045770(st->f2c), 0);
            func_02045334(st->f2c);
            return;
        }
        break;
    case 4:
        if (st->f20->h2 > 0x20) {
            if (func_021BA244((void *)func_021BDFEC(ctx)) == 1) {
                st->sub = 5;
                return;
            }
        } else {
            st->state = 5;
            return;
        }
        break;
    case 5:
        id = func_021BDFE4(ctx);
        if (func_021BA244((void *)func_021BDFEC(ctx)) == 0) {
            if (func_021B8740((int)ctx, id, 8, 0) == 1)
                st->state = 5;
        }
        break;
    }
}


#pragma opt_propagation reset


/*
 * Translates the +0xa4 state into a +0xa0 buffer code, doing nothing when the
 * state already equals the +0xa8 one.
 *
 * Addresses are Black-image addresses.
 */
void func_021B99B4(void *a0, char *a1)
{
    u32 v = ((struct Obj06561 *)a1)->fA4;
    u32 w = ((struct Obj06561 *)a1)->fA8;

    if (v == w)
        return;
    if (v == 1) {
        func_0204B878(((struct Obj06561 *)a1)->fA0, 0x17);
        return;
    }
    if (v == 2) {
        func_0204B878(((struct Obj06561 *)a1)->fA0, 0x23);
        return;
    }
    func_0204B878(((struct Obj06561 *)a1)->fA0, 0x18);
}

void func_021B99F4(void *unused, u8 *q)
{
    u32 a = func_02035C08(d_021C6F8F);
    u32 b = func_02035BA4(d_021C6F8F);
    int flag = -1;
    int changed = 0;
    if (a != -1) {
        q[15] = 0;
        if (a <= 1) { q[14] = 0; flag = 0; }
        else { q[14] = 1; flag = 1; }
    } else if (b != -1) {
        int agree = 0;
        if (b <= 1) { if (q[14] == 0) agree = 1; }
        else { if (q[14] == 1) agree = 1; }
        if (agree == 1) {
            q[15]++;
            if (*(volatile u8 *)&((struct Obj00998 *)q)->fF >= 25) {
                flag = q[14];
                q[15] = 10;
            }
        } else q[14] = 255;
    } else q[14] = 255;
    if (flag == 0) {
        if (q[13] < 8) {
            changed = 1; q[13]++;
            func_0204B878(*(struct Obj * *)&((struct Obj00998 *)q)->f90, (u16)(*(volatile u8 *)&((struct Obj00998 *)q)->fD + 25));
        }
    } else if (flag == 1) {
        if (q[13] > 0) {
            changed = 1; q[13]--;
            func_0204B878(*(struct Obj * *)&((struct Obj00998 *)q)->f90, (u16)(*(volatile u8 *)&((struct Obj00998 *)q)->fD + 25));
        }
    }
    if (changed == 1) {
        int angle;
        angle = (q[13] - 4) * 64;
        func_0200616C((void *)1644, 1);
        func_02006268(1, -1, angle, -1);
    }
}


static inline int Abs(int a)
{
    return a < 0 ? -a : a;
}


/*
 * note: Draws a line from (x0, y0) to (x1, y1) into a 4bpp tile buffer with func_021B9B88, in
 *   n = max(|dx|, |dy|) + 1 fixed-point steps (step = round(d << 12) / n).
 * lever (2026-10-05, wD9r lane157): value is a narrow parameter (u8 colour index) passed straight
 *   to a u8 callee parameter. With int value the stack-argument copy came first at entry; the narrow
 *   type puts the x0 spill store first (str r3; ldr value; str r2; str value), as in ov127 021C5C8C.
 *   Earlier levers kept: u8 x0 (reloaded at each use), Abs as a static inline ternary, y1/y0 copied
 *   into locals after the dx abs, the y0 read `*(u8 *)&y0` before the loop in an explicit
 *   `if (n > 0)` do/while, stepy declared before stepx.
 */
void func_021B9AB8(int a0, int a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value)
{
    int stepx, stepy;
    int dx = Abs(x0 - x1);
    int dy;
    int n, i;
    int accx, accy;
    int d, r;
    int ay; int by; int yb;
    by = y1; ay = y0; dy = Abs(ay - by);
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepx = func_0209C0A4(func_0209C494(r), n);
    d = by - ay;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepy = func_0209C0A4(func_0209C494(r), n);
    accx = 0;
    accy = 0;
    i = 0;
    if (n > 0) {
        yb = *(u8 *)&y0;
        do {
            func_021B9B88(p, x0 + (accx >> 12), yb + (accy >> 12), value);
            accx += stepx;
            accy += stepy;
            i++;
        } while (i < n);
    }
}

/*
 * lever: Explicit weights pointer retains the array base in r1 and cell in r3.
 */
void func_021B9B88(u8 *p, u8 x, u8 y, u8 value)
{
    u8 subx = x % 8;
    u8 shift = subx % 4;
    u16 *cell = (u16 *)(p + (u16)((u32)x / 8 + (u32)y / 8 * 16) * 32 + (subx / 4 + (u8)(y % 8) * 2) * 2);
    u16 weights[4];
    u16 *w = weights;
    weights[0] = d_021C6FA0[0];
    weights[1] = d_021C6FA0[1];
    weights[2] = d_021C6FA0[2];
    weights[3] = d_021C6FA0[3];
    if ((u8 *)cell < p + 4096 && (u8 *)cell >= p)
        *cell = (*cell & d_021C6F66[shift]) + w[shift] * value;
}

void func_021B9C1C(void *p, char *q, int id)
{
    u32 font = func_021BE034(p);
    u32 msgs = func_021BE03C(p);
    u32 sys = func_021BE044(p);
    u32 text;
    func_0201C6EC((struct PrintSys *)sys);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj05446 *)q)->f7C)), 15);
    text = (u32)func_02045EC0((struct MsgBank *)msgs, id);
    func_0201C724((void *)sys, (u32)func_02045770((struct Descriptor *)((struct Obj05446 *)q)->f7C), 0, 0, text, font, 1088);
    func_02045808((struct U16Vec *)text);
    func_02045334((struct Descriptor *)((struct Obj05446 *)q)->f7C);
    func_02045374((struct Cfg *)(((struct Obj05446 *)q)->f7C));
    func_0201F73C((void *)(((struct Obj05446 *)q)->f7C), 1, 320, 9);
    ((struct Obj05446 *)q)->f28 = 1;
}

void func_021B9C9C(void *p, char *q)
{
    if (func_021B80E4((int)p, (char *)func_021BDFE4(p)) == 5) {
        func_021B9C1C(p, q, 32);
    } else if (func_021BE0A4(p) == 0 && func_021BE054(p) > 1) {
        func_021B9C1C(p, q, 33);
    } else {
        func_021B9C1C(p, q, 32);
    }
    ((struct Obj08259 *)q)->f80 = (void *)func_021BE11C(p);
    ((struct Obj08259 *)q)->f0 = 10;
    if (func_0204B98C(((struct Obj08259 *)q)->f98) == 0)
        func_0204B878(((struct Obj08259 *)q)->f98, 15);
}


void func_021B9D04(int self, int *q)
{
    int r6;
    u32 r7;

    if (func_021B9DF8((void *)self, q) == 1) {
        func_02027858((void *)q[0x20]);
        q[0x20] = 0;
        return;
    }
    func_02027974((void *)q[0x20]);
    if (func_020279E8((void *)q[0x20]) != 1)
        return;
    if (func_02027A04((const u8 *)q[0x20]) == 0) {
        if (func_021B80E4(self, (char *)func_021BDFE4((void *)self)) == 5) {
            q[0] = 0xF;
            q[0x21] = 1;
            func_021B9C1C((void *)self, (char *)q, 0x2A);
        } else if (func_021BE0A4((void *)self) == 0 && func_021BE054((void *)self) > 1) {
            q[0] = 0xB;
        } else {
            q[1] = 7;
            q[0] = 3;
            r6 = 1;
            func_021BE0B0((void *)self, 1);
            r7 = func_021BDFDC((void *)self);
            func_021B7578(self, (char *)r7);
            func_021B7B80(self, (char *)r7);
            q[2] = r6;
        }
    } else {
        q[0] = 5;
        func_0201F7A8((void *)q[0x1F], 1);
        func_020456F8((struct Descriptor *)q[0x1F]);
        func_02045374((struct Cfg *)q[0xB]);
        func_020409B4(4);
        func_0204B878((struct Obj *)q[0x26], 1);
    }
    func_02027858((void *)q[0x20]);
    q[0x20] = 0;
}


/*
 * Maps the +4 state to an output code through the two ARM9 probes.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9DF8(void *p, int *out)
{
    if (func_021BE0D0(p) == 1) {
        int v = func_021B80E4((int)p, (char *)func_021BDFE4(p));

        *out = (v == 5) ? 0x10 : 0xd;
        return 1;
    }
    if (func_021BE054(p) <= 1) {
        *out = 0x14;
        return 1;
    }
    return 0;
}


void func_021B9E3C(void *p, char *q)
{
    q[0x30] = 3;
    q[0x31] = 0x20;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj10664 *)q)->f2C)), 0);
}
