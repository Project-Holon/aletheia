/*
 * file:     pokelist_p02.c
 * unit:     yes
 * function: func_021B6818, func_021B68F0, func_021B6B24, func_021B6D64
 * address:  0x021B6818
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BBE44  0x021BBE44  thumb  ov091
 *   func_021BBAE0  0x021BBAE0  thumb  ov091
 *   func_021BB5FC  0x021BB5FC  thumb  ov091
 *   func_020452E8  0x020452E8  arm
 *   func_021BA890  0x021BA890  thumb  ov091
 *   func_02027FD8  0x02027FD8  thumb
 *   func_021B7268  0x021B7268  thumb  ov091
 *   func_021BCD80  0x021BCD80  thumb  ov091
 *   func_021B71B0  0x021B71B0  thumb  ov091
 *   func_021B7624  0x021B7624  thumb  ov091
 *   func_021B6FEC  0x021B6FEC  thumb  ov091
 *   func_020355D8  0x020355D8  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021B83D8  0x021B83D8  thumb  ov091
 *   func_021B981C  0x021B981C  thumb  ov091
 *   func_021B9020  0x021B9020  thumb  ov091
 *   func_021B9750  0x021B9750  thumb  ov091
 *   func_021B97D4  0x021B97D4  thumb  ov091
 *   func_021BB30C  0x021BB30C  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB358  0x021BB358  thumb  ov091
 *   func_021B6184  0x021B6184  thumb  ov090
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BBA68  0x021BBA68  thumb  ov091
 *   func_021BC6CC  0x021BC6CC  thumb  ov091
 *   func_021BD8B0  0x021BD8B0  thumb  ov091
 *   func_021BD9C8  0x021BD9C8  thumb  ov091
 *   func_021BD8E4  0x021BD8E4  thumb  ov091
 *   func_021B61E8  0x021B61E8  thumb  ov090
 *   func_021B61FC  0x021B61FC  thumb  ov090
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BA8CC  0x021BA8CC  thumb  ov091
 *   func_021BB644  0x021BB644  thumb  ov091
 *   func_021BCDE8  0x021BCDE8  thumb  ov091
 *   func_021BBE50  0x021BBE50  thumb  ov091
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021BEBFC     0x021BEBFC  data  a1
 *   d_021BEC04     0x021BEC04  data  a1
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0204A648  0x0204A648  arm
 */
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj20854.h"

#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)
struct Descriptor;
struct Node;
struct TaskMenuState;
struct Actor;
struct PrintSys;
struct S;
struct Pal;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef void (*Fn)(u8 *p);

typedef signed char s8;

typedef short s16;

struct C3 { u16 v[3]; };

struct Pal {
    u8 pad0[0x10];
    u32 mode;
    u8 pad1[0x2c];
    u16 src[3][16];
    u16 dst[3][16];
    u8 step;
    u8 pad2;
    u16 phase;
};

typedef signed int     s32;

extern void func_02030EAC(struct Node *n);
extern int func_021B9A84(u32 p);
extern void func_021BBE44(int x);
extern void func_021BBAE0(int a, unsigned char *b);
extern void func_021BB5FC(void *a, int *s);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021BA890(void *ignored, u8 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021B7268(unsigned p);
extern void func_021BCD80(char *a);
extern void func_021B71B0(unsigned p);
extern void func_021B7624(char *p);
extern void func_021B6FEC(int a);
extern void func_020355D8(int a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_021B83D8(u8 *p);
extern void func_021B981C(u8 *p);
extern void func_021B9020(u8 *p);
extern void func_021B9750(unsigned p);
extern void func_021B97D4(u8 *p);
extern void func_021BB30C(u8 *p, int s);
extern void func_020061E4(u32 id);
extern int func_021BB358(u8 *p, struct S *s);
extern u32 func_021B6184(u8 *p, u8 b, u16 a);
extern void func_021BB714(void *a, u32 *s, u32 k);
extern void func_021BB7E8(u8 *a, u32 *s, u32 x);
extern void func_021BBA68(u8 *p, u8 *s);
extern void func_021BC6CC(u8 *p);
extern void func_021BD8B0(char *p);
extern void func_021BD9C8(u8 *p);
extern void func_021BD8E4(u8 *p);
extern void func_021B61E8(void *a, int b);
extern int func_021B61FC(int w, int a);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021BA8CC(u8 *p, int s);
extern void func_021BB644(u8 *p, u8 *s);
extern void func_021BCDE8(char *a);
extern void func_021BBE50(int x);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02082A60(void *src, void *dst, u32 size);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_0204A648(void);
int func_021B6818(u8 *p);
int func_021B68F0(u8 *p);
void func_021B6B24(struct Pal *p);
void func_021B6D64(void *tcb, u8 *p);
extern const struct C3 d_021BEBFC;
extern const struct C3 d_021BEC04;
extern s16 d_020A1B38[];


int func_021B6818(u8 *p)
{
    u8 i;

    func_02030EAC((struct Node *)W(4));
    if (func_021B9A84((u32)p) == 1) {
        func_021BBE44(W(0x108));
        func_021BBE44(W(0x10c));
        W(0x108) = 0;
        W(0x10c) = 0;
    }
    func_021BBAE0((int)p, (unsigned char *)W(0x154));
    func_021BB5FC(p, (int *)W(0x150));
    if (W(0x130) != 0)
        func_020452E8((struct Descriptor *)W(0x130));
    for (i = 0; i < 6; i++)
        func_021BA890(p, (u8 *)(((int *)(p + 0x160))[i]));
    func_02027FD8((struct TaskMenuState *)W(0x254));
    func_021B7268((unsigned int)p);
    if (func_021B9A84((u32)p) == 1)
        func_021BCD80((char *)p);
    func_021B71B0((unsigned int)p);
    func_021B7624((char *)p);
    func_021B6FEC((int)p);
    if (W(0x18) == 1)
        *(int *)(W(0x280) + 0x34) = 0x18;
    if (W(0x1c) == 1)
        *(int *)(W(0x280) + 0x34) = 0x19;
    if (W(0x20) == 1)
        *(int *)(W(0x280) + 0x34) = 0x1a;
    func_020355D8(W(8));
    return 1;
}


/*
 * Case 20 is written before case 19: case 19's fallback repeats case 20's
 * body and mwcc tail-merges it into the earlier copy, which puts case 20's
 * code first in the original.
 */
int func_021B68F0(u8 *p)
{
    u8 i;
    Fn fn;

    switch (p[0xc]) {
    case 0:
        func_0202208C((void *)2, 1, 1, 0, 6, 1, H(0));
        p[0xc] = 1;
        break;
    case 1:
        if (func_020221A4() == 1)
            p[0xc] = p[0xd];
        break;
    case 2:
    case 3:
    case 4:
        func_021B83D8(p);
        break;
    case 5:
        func_021B981C(p);
        break;
    case 6:
        func_021B9020(p);
        break;
    case 7:
        func_021B9750((unsigned int)p);
        break;
    case 9:
        func_021B97D4(p);
        break;
    case 10:
        func_021BB30C(p, *(int *)(p + W(0x2c) * 4 + 0x160));
        if (W(0x24) == 1) {
            W(0x24) = 0;
            func_020061E4(0x56f);
        }
        p[0xc] = 0xb;
    case 11:
        if (func_021BB358(p, (struct S *)(*(int *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            fn = *(Fn *)&((struct Obj00009 *)p)->f120;
            if (fn != 0)
                fn(p);
            else
                p[0xc] = 0x15;
        }
        break;
    case 12:
        p[0x114]++;
        if (p[0x114] > 0x10) {
            if (W(0x20) == 1) {
                if (func_021B6184((u8 *)W(0x280), 0, 0) == 1) {
                    p[0xc] = 0x11;
                    func_021BBE44(W(0x108));
                    func_021BBE44(W(0x10c));
                    W(0x108) = 0;
                    W(0x10c) = 0;
                    func_021BB714(p, (u32 *)W(0x150), 0);
                    func_021BB7E8(p, (u32 *)W(0x150), 0xb0);
                    func_021BBA68(p, (u8 *)W(0x150));
                }
            } else {
                p[0xc] = 0x13;
            }
        }
        break;
    case 13:
        func_021BC6CC(p);
        break;
    case 14:
        func_021BD8B0((char *)p);
        break;
    case 15:
        func_021BD9C8(p);
        break;
    case 16:
        func_021BD8E4(p);
        break;
    case 17:
        func_021B61E8((void *)W(0x280), 2);
        p[0xc] = 0x12;
        break;
    case 18:
        if (func_021B61FC(W(0x280), 2) == 1)
            p[0xc] = 0x13;
        break;
    case 20:
        func_0202208C(0, 0, 0, 0, 6, 1, H(0));
        p[0xc] = 0x15;
        break;
    case 19:
        if (W(0x1e8) == 0 || func_0204B98C((struct Actor *)W(0x1e8)) == 0) {
            func_0202208C(0, 0, 0, 0, 6, 1, H(0));
            p[0xc] = 0x15;
        }
        break;
    case 21:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    for (i = 0; i < 6; i++)
        func_021BA8CC(p, ((int *)(p + 0x160))[i]);
    func_021BB644(p, (u8 *)W(0x150));
    func_021B6B24((struct Pal *)p);
    if (func_021B9A84((u32)p) == 1) {
        func_021BCDE8((char *)p);
        func_021BBE50(W(0x108));
        func_021BBE50(W(0x10c));
    }
    func_0201C4E4((struct PrintSys *)W(0x140));
    func_0204A600();
    return 0;
}


/*
 * Palette fade (u8 step countdown at +0x100, brighten src[3][16] into dst, skipping
 * columns 2..4, then a sine blend of dst[i][2..4] between two 3-colour tables, then
 * func_02061CA4(15, 0xc0, dst, 0x60)).
 * note: final push 2026-10-05 G9L1, EXACT in c99 and c. Four source facts closed the draft
 * (182 B off): (1) the phase update stores in each if/else arm (p->phase = p->phase - 0xfc00
 * or p->phase = t), so the 0x102 offset stays live in r1 and v sits in r3; (2) each blended
 * channel is clamped into a shared int t (`...; r = t;`) and assigned to a u8 local, which
 * puts the byte truncation at the join as in the image; (3) the blend deltas are written
 * red first (ar, br, dr, then green, then blue); the scheduler still emits green first, but
 * the red values are born first and take the registers the image shows; (4) f is declared
 * after the counters, and b is u16 while a is int. Earlier notes: hi and lo are two struct C3
 * locals, each delta is read three times (clamp), tried-and-failed forms in git history.
 * Callee 02061CA4 matches its 4-parameter definition.
 */
void func_021B6B24(struct Pal *p)
{
    u8 i;
    u8 i2;
    u8 j;
    u8 j2;
    u8 k;
    int f;
    struct C3 hi;
    struct C3 lo;

    func_02082A60(p->src, p->dst, 0x60);
    if (p->step != 0) {
        p->step--;
        k = p->step;
        if (k > 6) {
            k = 12 - k;
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 16; j++) {
                if (j >= 2 && j <= 4) {
                    continue;
                }
                {
                    u16 c = p->src[i][j];
                    u8 g = (c & 0x3e0) >> 5;
                    u8 b = (c & 0x7c00) >> 10;
                    u8 r = c & 0x1f;
                    int t;
                    t = r + k * 2;
                    if (t > 31) t = 31;
                    r = t;
                    t = g + k * 2;
                    if (t > 31) t = 31;
                    g = t;
                    t = b + k * 2;
                    if (t > 31) t = 31;
                    b = t;
                    p->dst[i][j] = r | (g << 5) | (b << 10);
                }
            }
        }
    }
    hi = d_021BEBFC;
    lo = d_021BEC04;
    if (p->mode == 0) {
        int t = p->phase + 0x400;
        if (t >= 0x10000) {
            p->phase = p->phase - 0xfc00;
        } else {
            p->phase = t;
        }
    } else {
        p->phase = 0xc000;
    }
    f = (d_020A1B38[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i2 = 0; i2 < 3; i2++) {
        for (j2 = 0; j2 < 3; j2++) {
            int a = hi.v[j2];
            u16 b = lo.v[j2];
            u8 ar = a & 0x1f;
            u8 br = b & 0x1f;
            s8 dr = ((br - ar) * f) >> 12;
            u8 ag = (a & 0x3e0) >> 5;
            u8 bg = (b & 0x3e0) >> 5;
            s8 dg = ((bg - ag) * f) >> 12;
            u8 ab = (a & 0x7c00) >> 10;
            u8 bb = (b & 0x7c00) >> 10;
            s8 db = ((bb - ab) * f) >> 12;
            u8 r, g, bl;
            int t;
            if (ar + dr > 31) t = 31; else if (ar + dr < 0) t = 0; else t = ar + dr;
            r = t;
            if (ag + dg > 31) t = 31; else if (ag + dg < 0) t = 0; else t = ag + dg;
            g = t;
            if (ab + db > 31) t = 31; else if (ab + db < 0) t = 0; else t = ab + db;
            bl = t;
            p->dst[i2][j2 + 2] = r | (g << 5) | (bl << 10);
        }
    }
    func_02061CA4((void *)15, 0xc0, (u32)p->dst, 0x60);
}


static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}


void func_021B6D64(void *tcb, u8 *p)
{
    if (((struct Obj20854 *)p)->f10 == 1)
        GX_SetVisibleWnd(1);
    else
        GX_SetVisibleWnd(0);
    func_0204A648();
}
