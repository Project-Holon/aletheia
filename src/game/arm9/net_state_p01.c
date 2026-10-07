/*
 * file:     net_state_p01.c
 * unit:     yes
 * function: func_0203568C, func_020356A0, func_02035750, func_02035760, func_02035780, func_020357A0, func_020357C0, func_020357E0, func_020358A0, func_02035A60, func_02035A70, func_02035AA4, func_02035ADC, func_02035B58, func_02035BA4, func_02035BBC, func_02035C08, func_02035C20, func_02035C38, func_02035C48, func_02035C60, func_02035C70, func_02035CB8, func_02035CD8, func_02035D20, func_02035D40, func_02035D5C, func_02035D98, func_02035DC8, func_02035DD8, func_02035E08, func_02035E18, func_02035E54, func_02035E84, func_02035EB0, func_02035ECC, func_02035EE8, func_02035F38
 * address:  0x0203568C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469BC     0x021469BC  data
 *   func_020363B8  0x020363B8  arm
 *   func_020363D4  0x020363D4  arm
 *   func_020363F0  0x020363F0  arm
 *   func_02035E84  0x02035E84  arm
 *   func_02035EB0  0x02035EB0  arm
 *   str_020A798C   0x020A798C  data
 *   g_021469C4     0x021469C4  data
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   TP_Init              0x0208A924  arm
 *   TP_GetUserInfo       0x0208A998  arm
 *   TP_SetCalibrateParam 0x0208AA2C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208AB1C  0x0208AB1C  arm
 *   func_0208ABB8  0x0208ABB8  arm
 *   func_0208ADB4  0x0208ADB4  arm
 *   func_0208B104  0x0208B104  arm
 *   func_02035224  0x02035224  arm
 *   func_020358A0  0x020358A0  arm
 *   func_020357A0 0x020357A0  arm
 *   func_02035760 0x02035760  arm
 *   func_02035780 0x02035780  arm
 *   func_02035ADC 0x02035ADC  arm
 *   func_020357C0  0x020357C0  arm
 *   func_02035C48  0x02035C48  arm
 *   func_0208AC0C  0x0208AC0C  arm
 *   func_0208AD14  0x0208AD14  arm
 *   func_0208B220  0x0208B220  arm
 *   func_0208B238  0x0208B238  arm
 *   g_020A799C    0x020A799C  data
 *   func_0203521C  0x0203521C  arm
 *   func_020360B8  0x020360B8  arm
 */
#include "../../matched/include/Obj11334.h"
#include "../../matched/include/Obj11335.h"
#include "../../matched/include/Obj11336.h"
#include "../../matched/include/Obj11337.h"
#include "../../matched/include/Obj07103.h"
#include "../../matched/include/Obj06933.h"
#include "../../matched/include/Obj11338.h"
#include "../../matched/include/Obj11339.h"

struct TPData;
struct UiCtx;
struct Tp;
struct Kind;
struct R;
struct Ctx02035C48;
struct Ctx;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u8  f0A;
    u8  f0B;
} S12;

typedef struct {
    u32 f00;
    int (*f04)(S12 *dst, S12 *src);
} Desc;

struct Kind {
    u8 pad00[0x3D];
    u8 unk3D;
};

typedef signed int     s32;

struct Tp {
    u8  pad00[0x3e];
    u8  f3e;
};

struct Work {
    u8  pad00[0x5c];
    u16 f5c;
    u16 f5e;
    u16 f60;
    u16 f62;
    u16 f64;
    u16 f66;
    u16 f68;
    u16 f6a;
    u16 f6c;
    u16 f6e;
    u16 f70;
    u16 f72;
    u8  f74;
};

struct Samp {
    u16 x;
    u16 y;
    u16 v;
    u16 t;
};

struct R {
    u8 t;
    u8 a;
    u8 b;
    u8 c;
};

struct Sio_02035D5C {
    u8 pad_00[0x0c];
    u8 buf[0x4c];
    u16 unk58;
    u16 unk5a;
    u8 pad_5c[0x19];
    u8 unk75;
};

struct Sio_02035E54 {
    u8 pad_00[0x64];
    u16 unk64;
    u16 unk66;
    u16 unk68;
    u16 unk6a;
    u16 unk6c;
    u16 unk6e;
    u16 unk70;
    u16 unk72;
};

typedef struct {
    u8  pad[0x40];
    u32 f40;
    u32 f44;
} T;

typedef volatile u16   vu16;

struct Key {
    u8  pad00[0x0c];
    u32 cont;           /* 0x0c */
    u32 trg;            /* 0x10 */
    u32 rpt;            /* 0x14 */
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
    s32 wait;           /* 0x3c */
    s32 speed;          /* 0x40 */
    s32 delay;          /* 0x44 */
};

struct Ctx {
    u8 pad00[0x3e];
    u8 f3e;
};

extern int func_020363B8(int a0, int a1, int a2);
extern int func_020363D4(int a0, int a1, int a2);
extern int func_020363F0(int a0, int a1, int a2);
extern void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d);
extern int func_02035EB0(int a0, int a1, int a2);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  TP_Init(void);
extern int   TP_GetUserInfo(u16 *info);
extern void  TP_SetCalibrateParam(u16 *info);
extern void func_02082BCC(void *dst, u32 val, u32 size);
extern void func_0208AB1C(void);
extern u32 func_0208ABB8(struct TPData *result);
extern void func_0208ADB4(struct TPData *result);
extern void func_0208B104(struct TPData *disp, const struct TPData *raw);
extern struct UiCtx *func_02035224(void);
extern void func_020358A0(struct Tp *ctx);
extern int func_020357A0(struct Kind *p);
extern u16 func_02035760(struct Kind *p);
extern u16 func_02035780(struct Kind *p);
extern int func_02035ADC(struct R *p, u32 x, u32 y);
void *sub_020357E0(u32 id);
void func_02035A60(void);
u32 func_02035A70(u8 *p, s32 x, s32 y);
u32 func_02035AA4(u8 *p, u32 a, u32 b);
int func_02035B58(u32 a, u32 b);
int func_02035BA4(const void *p);
extern u16 func_020357C0(struct Kind *p);
extern struct UiCtx *sub_02035224(void);
extern int sub_02035C20(const void *p);
extern u16 func_02035C48(struct Ctx02035C48 *ctx);
u32 sub_02035C70(struct Ctx *ctx, u32 *outA, u32 *outB);
u32 sub_02035CD8(struct Ctx *ctx, u32 *outA, u32 *outB);
extern void func_0208AC0C(u32 a, u32 b, void *c, u32 d);
extern void func_0208AD14(void);
extern void func_0208B220(u32 slot);
extern u32 func_0208B238(u32 slot);
u32 sub_02035D5C(struct Sio_02035D5C *p);
u32 sub_02035E18(struct Sio_02035D5C *p);
void sub_02035D98(struct Sio_02035D5C *p);
void sub_02035DD8(struct Sio_02035D5C *p);
extern u32 func_0203521C(u32 *p);
extern void func_020360B8(struct Obj *o);
int func_0203568C(void);
void func_020356A0(int a0);
int func_02035750(void);
int func_02035BBC(void *ctx, void *param);
int func_02035C08(const void *p);
int func_02035C20(const void *p);
int sub_02035C38(void);
u16 func_02035C48(struct Ctx02035C48 *ctx);
int func_02035ECC(int a0, int a1, int a2);
T *func_02035EE8(u32 a);
extern Desc g_021469BC;
extern const char str_020A798C[];
extern void *g_021469C4;
extern u8 g_020A799C[];


int func_0203568C(void){ return *(unsigned char *)((*(int *)(0x21469BC) + 63)); }



/*
 * A descriptor fan-out: the global at 0x021469BC carries a callback at +4
 * which fills two twelve-byte records on the stack, and the seven
 * accessors below push each pair into the object in a0.
 */
void func_020356A0(int a0)
{
    S12 b;
    S12 a;

    if (g_021469BC.f04 == 0) {
        return;
    }
    if (g_021469BC.f04(&b, &a) == 0) {
        return;
    }
    func_020363B8(a0, b.f00, a.f00);
    func_020363D4(a0, b.f02, a.f02);
    func_020363F0(a0, b.f04, a.f04);
    func_02035E84((void *)a0, b.f06, b.f08, a.f06, a.f08);
    func_02035EB0(a0, b.f0A, a.f0A);
    func_02035ECC(a0, b.f0B, a.f0B);
}


int func_02035750(void){ return *(int *)(0x21469C4); }



/*
 * A one-liner over the object at 0x021469C4: when the kind byte at +0x3D is
 * 0x1E (30) the halfword at +0x64 is reported, otherwise the one at +0x5C.
 * The kind test is on the *argument*, the two halfwords on the object the
 * accessor func_02035750 returns, which is why the argument is kept in r4
 * across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035760.c \
 *       --func func_02035760 --addr 0x02035760 --cc 1.1p1 --arm
 */
u16 func_02035760(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11334 *)q)->f64;
    return ((struct Obj11334 *)q)->f5C;
}


/*
 * The second halfword pair of the same accessor family as
 * src/matched/func_02035760.c: kind byte +0x3D == 0x1E selects +0x66, else
 * +0x5E.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035780.c \
 *       --func func_02035780 --addr 0x02035780 --cc 1.1p1 --arm
 */
u16 func_02035780(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11335 *)q)->f66;
    return ((struct Obj11335 *)q)->f5E;
}


/*
 * Third of the family in src/matched/func_02035760.c: kind byte +0x3D == 0x1E
 * selects +0x6A, else +0x62.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357A0.c \
 *       --func func_020357A0 --addr 0x020357A0 --cc 1.1p1 --arm
 */
int func_020357A0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11336 *)q)->f6A;
    return ((struct Obj11336 *)q)->f62;
}


/*
 * Fourth of the family in src/matched/func_02035760.c: kind byte +0x3D ==
 * 0x1E selects +0x68, else +0x60.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020357C0.c \
 *       --func func_020357C0 --addr 0x020357C0 --cc 1.1p1 --arm
 */
u16 func_020357C0(struct Kind *p)
{
    u8 *q;

    q = (u8 *)func_02035750();
    if (p->unk3D == 0x1E)
        return ((struct Obj11337 *)q)->f68;
    return ((struct Obj11337 *)q)->f60;
}


/*
 * Allocates the touched-icon work object (0x7c bytes), clears it, brings
 * the touch panel up and stores the calibration handed back by
 * TP_GetUserInfo.  When the user has no stored calibration (the call does
 * not answer 1) the four halfwords are filled with the firmware defaults
 * 0x2ae / 0x58c / 0xe25 / 0x1208; 0x58c is materialised as
 * `0x510 + 0x7c` because the size constant is still live in r6.  The
 * object pointer is published at 0x021469C4 and returned.
 *
 * The two bytes at +0x75/+0x76 are the state and the blinking flag of the
 * icon driver; the u16 pair at +0x58 is cleared before the panel is up.
 */
void *sub_020357E0(u32 id)
{
    u16 info[4];
    void *p = func_02030734(id, 0x7c, 0, str_020A798C, 0x83);

    MI_CpuFill8(p, 0, 0x7c);
    ((struct Obj07103 *)p)->f58 = 0;
    ((struct Obj07103 *)p)->f5A = 0;
    TP_Init();
    if (TP_GetUserInfo(info) == 1) {
        TP_SetCalibrateParam(info);
    } else {
        info[0] = 0x2ae;
        info[1] = 0x58c;
        info[2] = 0xe25;
        info[3] = 0x1208;
        TP_SetCalibrateParam(info);
    }
    ((struct Obj07103 *)p)->f75 = 4;
    ((struct Obj07103 *)p)->f76 = 0;
    g_021469C4 = p;
    return p;
}


/*
 * The touch-panel sampling pass of the touchpanel.c family: it resolves the
 * work object, refuses to run with the lid closed, samples the panel (with a
 * bounded debounce retry), converts the raw sample, and then does the edge /
 * latch bookkeeping over the halfword block at +0x5c..+0x72.
 *
 * Bit 15 of the halfword at 0x02FFFFA8 is the lid-closed flag, the same
 * hardware address src/matched/sub_0203545C.c reads; it is a cast constant,
 * not a relocation (docs/idioms/volatile-reread-needs-two-locals.md).  When
 * it is set the whole 0x7c-byte object is cleared and the pass returns.
 *
 * Three declaration facts carry the register allocation, and none of them is
 * visible in the control flow:
 *
 *   - The two sample buffers are laid out `raw` first and `cal` second, but
 *     the ORIGINAL passes sp+8 to the sampler and sp+0 to the converter, so
 *     `cal` is the sp+0 object: the dispatch code the function tests is
 *     `cal.t` at [sp,#6] and the state word it latches is `cal.v` at [sp,#4].
 *     Getting those two fields the wrong way round moves every stack offset
 *     in the tail.
 *   - `struct Samp` is x, y, v, t: the `v`/`t` order is what puts the tested
 *     halfword at +6 rather than +4.
 *   - The resolver's result is bound to its own local `sio` DECLARED LAST and
 *     copied into `w`.  Initialising `w` from the call directly, or declaring
 *     `sio` before `w`, swaps r4 and r5 through the whole body; the extra
 *     copy is what splits the live range so that the loop counter keeps r4.
 *     The permuter found this as `temp(tmp=func_02035750(ctx))`.
 *
 * The `% 2 == 0` tail test compiles to the lsr/rsb/adds triple at +0x168,
 * the signed-remainder-by-two idiom on a signed char field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020358A0.c \
 *       --func func_020358A0 --addr 0x020358A0 --cc 1.1p1 --arm
 */
void func_020358A0(struct Tp *ctx)
{
    struct Samp raw;
    struct Samp cal;
    struct Work *w;
    u32 done = 0;
    u32 n;
    struct Work *sio = (struct Work *)func_02035750();

    w = sio;
    if (w == 0) {
        return;
    }
    if ((s32)(*(u16 *)0x02FFFFA8 & 0x8000) >> 15 != 0) {
        func_02082BCC(w, 0, 0x7c);
        return;
    }
    if (w->f74 == 0) {
        n = 0;
        func_0208AB1C();
        if (func_0208ABB8((struct TPData *)(&raw)) != 0) {
            do {
                n = (n + 1) & 0xff;
                if (n >= 0x20) {
                    cal.t = 3;
                    done = 1;
                    break;
                }
                func_0208AB1C();
            } while (func_0208ABB8((struct TPData *)(&raw)) != 0);
        }
    } else {
        func_0208ADB4((struct TPData *)(&raw));
    }
    if (done == 0) {
        func_0208B104((struct TPData *)(&cal), (const struct TPData *)(&raw));
    }
    if (cal.t == 0) {
        w->f5c = cal.x;
        w->f5e = cal.y;
    } else if (w->f62 != 0) {
        if (cal.t != 1) {
            if (cal.t == 2) {
                w->f5c = cal.x;
            }
        } else {
            w->f5e = cal.y;
        }
    } else {
        cal.v = 0;
    }
    w->f60 = cal.v & (cal.v ^ w->f62);
    w->f62 = cal.v;
    w->f70 = w->f70 | w->f60;
    w->f72 = w->f72 | w->f62;
    if (w->f5e != 0) {
        w->f6e = w->f5e;
    }
    if (w->f5c != 0) {
        w->f6c = w->f5c;
    }
    if (ctx->f3e % 2 == 0) {
        w->f64 = w->f6c;
        w->f66 = w->f6e;
        w->f68 = w->f70;
        w->f6a = w->f72;
        w->f6c = 0;
        w->f6e = 0;
        w->f70 = 0;
        w->f72 = 0;
    }
}


/*
 * Previously parked at MATCH: the `bl` to 0x020358A0 had no outside witness.
 * Closed 2026-09-22 (family wave 5) when 0x020358A0 was itself decompiled to
 * EXACT in src/matched/func_020358A0.c; that manifest entry is now the
 * witness and the site resolves on class `matched`.
 *
 * Two calls in a row: the first one's result is the second one's argument,
 * handed over in r0 with nothing in between.  Nothing else: no stack frame,
 * no locals.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035A60.c \
 *       --func func_02035A60 --addr 0x02035A60 --cc 1.1p1 --arm
 */
void func_02035A60(void)
{
    func_020358A0((struct Tp *)func_02035224());
}


/*
 * The radius test of a packed four-byte record: (x - p[1])^2 + (y - p[2])^2 is
 * compared against p[3]^2, and the answer is 1 when it is strictly smaller.
 * The two differences are the second and third arguments, which is why the
 * argument registers r1 and r2 are subtracted from p[1] and p[2] rather than
 * the other way round.
 *
 * Two tells worth keeping.  The squared radius is computed with `smulbb`,
 * a 16x16 multiply, because p[3] is a `u8` and mwcc knows both factors fit in
 * sixteen bits; the two distance squares need the full 32-bit `mul`/`mla`
 * because their operands are `int` differences.  And the comparison is
 * unsigned (`movcc`/`movcs`), which is free here: both sides are sums of
 * squares and therefore non-negative, so mwcc may pick either.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035A70.c \
 *       --func func_02035A70 --addr 0x02035A70 --cc 1.1p1 --arm
 */
u32 func_02035A70(u8 *p, s32 x, s32 y)
{
    s32 dx = p[1] - x;
    s32 dy = p[2] - y;
    u32 r = p[3];

    return (u32)(dx * dx + dy * dy) < r * r;
}


/*
 * The rectangular counterpart of src/matched/func_02035A70.c, on the same
 * packed four-byte record: a point (a, b) is inside when both distances from
 * the low corner fit in the record's width and height, each spelled as the
 * one-sided range test `v - lo <= hi - lo`.
 *
 * Written as `if (c1 && c2) return 1; return 0;`, the whole body compiles to
 * a single chain of conditionally executed instructions - the second pair of
 * loads, the two subtractions and the comparison all carry the LS condition
 * of the first comparison, and the two `movls`/`movhi` are the boolean - and
 * that chain is exactly the original.  A bare `return c1 && c2;` instead
 * presets a zero register and branches, which is 4 bytes longer and does not
 * match; the `return`-in-`if` spelling is what this source needs, the same
 * shape docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md
 * describes for the disjunction.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035AA4.c \
 *       --func func_02035AA4 --addr 0x02035AA4 --cc 1.1p1 --arm
 */
u32 func_02035AA4(u8 *p, u32 a, u32 b)
{
    if (a - p[2] <= (u32)(p[3] - p[2]) && b - p[0] <= (u32)(p[1] - p[0]))
        return 1;
    return 0;
}


/*
 * The hit-test table walk of the touchpanel.c family.  It scans an array of
 * four-byte records for the first one the point (x, y) falls inside, and
 * returns that record's index, or -1 when the table runs out.  Byte 0 of a
 * record is the shape tag: 0xFF ends the table, 0xFD skips the entry, 0xFE
 * selects the circle test at func_02035A70 and anything else the rectangle
 * test at func_02035AA4.
 *
 * THE DECLARATION IS THE WHOLE FUNCTION.  Written with a `u8 *` parameter
 * and the record address spelled `p + i * 4` (any of: a `rec` local at any
 * scope, `&p[i*4]`, a `u32 *` base with a cast, or the expression written
 * out at each call site), the body compiles to a 21-byte residue in the head
 * that no amount of statement shuffling moves.  The original computes the
 * record address with `add r0, r7, r4, lsl #2` AFTER both argument moves,
 * keeping the tag byte in r0 across the two compares; every pointer-arithmetic
 * spelling hoists the address above the compares instead, which pushes the
 * tag into r1 and rotates the rest.
 *
 * Declaring the record as a struct and indexing the array (`p[i].t`, with
 * `&p[i]` cast for the calls) is what reproduces it: the address becomes an
 * addressing-mode computation the scheduler is free to sink below the
 * compares rather than a value that has to be live across them.  This is the
 * "residue the permuter cannot move at all is usually in the declarations"
 * case: tools/permuter.py plateaus at 8 bytes out from every pointer-spelled
 * start (its best single mutation, `temp(tmp=p + (i * 4))`, is a loop-invariant
 * hoist that is not value-preserving here), and the struct declaration is
 * EXACT with no mutation at all.
 *
 * Supersedes the near miss recorded in docs/notes/pkt_02035ADC.c.txt, which
 * tried four pointer spellings and reached the same 21-byte head.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035ADC.c \
 *       --func func_02035ADC --addr 0x02035ADC --cc 1.1p1 --arm
 */
int func_02035ADC(struct R *p, u32 x, u32 y)
{
    int i = 0;

    while (p[i].t != 0xff) {
        if (p[i].t != 0xfd) {
            if (p[i].t == 0xfe) {
                if (func_02035A70((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            } else {
                if (func_02035AA4((u8 *)&p[i], x, y) != 0) {
                    return i;
                }
            }
        }
        i++;
    }
    return -1;
}


int func_02035B58(u32 a, u32 b)
{
    u32 x;
    u32 y;

    func_02035750();
    if (func_020357A0((struct Kind *)a) == 0) {
        return -1;
    }
    x = func_02035760((struct Kind *)a);
    y = func_02035780((struct Kind *)a);
    return func_02035ADC((struct R *)b, x, y);
}


int func_02035BA4(const void *p)
{
    return func_02035B58((u32)func_02035224(), (u32)p);
}



int func_02035BBC(void *ctx, void *param)
{
    void *a;
    void *b;

    func_02035750();
    if (func_020357C0(ctx) == 0) {
        return -1;
    }

    a = (void *)func_02035760(ctx);
    b = (void *)func_02035780(ctx);

    return func_02035ADC(param, (u32)a, (u32)b);
}



int func_02035C08(const void *p)
{
    return func_02035BBC((void *)((int)func_02035224()), (void *)p);
}



int func_02035C20(const void *p)
{
    func_02035750();
    return func_020357A0((struct Kind *)p);
}



/*
 * A two-call forwarder in the ARM SDK-style block at 0x02035000..0x02038000:
 * "push {r3, lr}; bl sub_02035224; bl sub_02035C20; pop {r3, pc}", sixteen
 * bytes, no register setup between the calls: the first call's result is
 * still in r0 as the second call's argument, and the second call's result
 * is returned.
 *
 * Byte-correct.  sub_02035224 resolves on the `label` class (58 branches to
 * it image-wide, e.g. 0x02035460).  sub_02035C20 does not: this call is its
 * only reference anywhere in the image, so that site stays wildcarded and
 * caps the file at MATCH.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035C38.c \
 *       --func sub_02035C38 --addr 0x02035C38 --cc 1.1p1 --arm
 */
int sub_02035C38(void)
{
    return sub_02035C20(sub_02035224());
}



/*
 * Hands the same context to both halves of the teardown pair.  The
 * argument is kept in a callee-saved register across the first call
 * rather than reloaded, which is what says it is one parameter passed
 * twice and not two different values.
 *
 * Decompiled to unstick src/pending/sub_02035C60.c, whose only blocking
 * relocation was this address: 0x02035C48 is reached by exactly one
 * branch image-wide (the `bl` at 0x02035C68 inside that caller), so class
 * `label` was unavailable and only an EXACT entry here could attest it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035C48.c \
 *       --func func_02035C48 --addr 0x02035C48 --cc 1.1p1 --arm
 */
u16 func_02035C48(struct Ctx02035C48 *ctx)
{
    func_02035750();
    return func_020357C0((struct Kind *)ctx);
}


/*
 * Forward to func_02035C48 with the context func_02035224 supplies, same
 * "no context argument" shape as the block in unit_02035C70.c.
 *
 * func_02035C48's only call site anywhere in the image is the one right
 * here, inside this 16-byte function, so the `label` class has no witness
 * outside the range under test and --suggest-split cannot help (the
 * function is atomic; there is nothing to cut).  The site resolves on
 * class `matched` against src/matched/func_02035C48.c, decompiled for
 * exactly this purpose.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035C60.c \
 *       --func sub_02035C60 --addr 0x02035C60 --cc 1.1p1 --arm
 */
int sub_02035C60(void)
{
    return func_02035C48((struct Ctx02035C48 *)func_02035224());
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02035D40
 *
 * The singleton-facing half of the 0x02035000 block: every entry point here
 * is the "no context argument" spelling of a worker that lives a little
 * earlier in the file, with func_02035224() supplying the context.
 *
 * sub_02035C70 and sub_02035CD8 are the two two-output readers; they differ
 * only in which predicate gates them (0x020357A0 versus 0x020357C0).  Each
 * is called from exactly one place, its own wrapper in this same file, so
 * the two pairs have to live in one unit for those sites to close as
 * `local` (same shape as src/matched/unit_020362BC.c).
 *
 * sub_02035D40 has no label of its own in the listing: it is an unlabelled
 * follower of sub_02035D20 (its prologue saves nothing).  It is the u16
 * narrowing shim in front of func_02035ADC, and it is the pool-word-and-bx
 * tail call idiom, one section per function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035C70.c \
 *       --addr 0x02035C70 --arm
 */
u32 sub_02035C70(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    func_02035750();
    if (func_020357A0((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = func_02035760((struct Kind *)ctx);
    *outB = func_02035780((struct Kind *)ctx);
    return 1;
}

u32 sub_02035CB8(u32 *outA, u32 *outB)
{
    return sub_02035C70((struct Ctx *)func_02035224(), outA, outB);
}

u32 sub_02035CD8(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    func_02035750();
    if (func_020357C0((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = func_02035760((struct Kind *)ctx);
    *outB = func_02035780((struct Kind *)ctx);
    return 1;
}

u32 sub_02035D20(u32 *outA, u32 *outB)
{
    return sub_02035CD8((struct Ctx *)func_02035224(), outA, outB);
}

u32 sub_02035D40(struct Ctx *ctx, u32 a, u32 b)
{
    return (u32)func_02035ADC((struct R *)ctx, (u16)a, (u16)b);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02035E08, sub_02035E18
 *
 * The open/close pair of the 0x02035000 block's link layer, plus their
 * no-context wrappers.  sub_02035DD8 brings the link up (state word at +0x5a
 * goes to 1) and sub_02035D98 takes it down (state word goes back to 0);
 * both refuse to act unless the handle at +0x58 is live and the state is not
 * already where they would leave it.
 *
 * The four workers are kept in one unit deliberately: sub_02035D5C,
 * sub_02035D98, sub_02035DD8 and sub_02035E18 are each reached by exactly
 * one branch in the image, the one in this same file, so as separate files
 * every wrapper would cap at MATCH.  Inside one range each site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035D5C.c \
 *       --addr 0x02035D5C --arm
 */
u32 sub_02035D5C(struct Sio_02035D5C *p)
{
    if (p->unk58 == 0) {
        return 1;
    }
    func_0208AD14();
    func_0208B220(4);
    if (func_0208B238(4) != 0) {
        return 2;
    }
    return 1;
}

void sub_02035D98(struct Sio_02035D5C *p)
{
    struct Sio_02035D5C *sio = (struct Sio_02035D5C *)func_02035750();

    if (sio != 0 && sio->unk5a != 0 && sio->unk58 != 0) {
        sub_02035E18(sio);
        sio->unk5a = 0;
    }
}

void sub_02035DC8(void)
{
    sub_02035D98((struct Sio_02035D5C *)func_02035224());
}

void sub_02035DD8(struct Sio_02035D5C *p)
{
    struct Sio_02035D5C *sio = (struct Sio_02035D5C *)func_02035750();

    if (sio != 0 && sio->unk5a != 1 && sio->unk58 != 0) {
        sub_02035D5C(sio);
        sio->unk5a = 1;
    }
}

void sub_02035E08(void)
{
    sub_02035DD8((struct Sio_02035D5C *)func_02035224());
}

u32 sub_02035E18(struct Sio_02035D5C *p)
{
    u32 ret;

    func_0208AC0C(0, p->unk75, p->buf, 9);
    ret = 2;
    func_0208B220(2);
    if (func_0208B238(2) == 0) {
        ret = 1;
    }
    return ret;
}


/*
 * Zeroes the eight-halfword counter block at +0x64 of the record
 * func_02035750 resolves its argument to.  One of the two follow-up passes
 * that src/pending/sub_02035660.c runs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035E54.c \
 *       --func sub_02035E54 --addr 0x02035E54 --cc 1.1p1 --arm
 */
void sub_02035E54(struct Sio_02035E54 *p)
{
    struct Sio_02035E54 *sio = (struct Sio_02035E54 *)func_02035750();

    sio->unk64 = 0;
    sio->unk66 = 0;
    sio->unk68 = 0;
    sio->unk6a = 0;
    sio->unk6c = 0;
    sio->unk6e = 0;
    sio->unk70 = 0;
    sio->unk72 = 0;
}


/*
 * The setter that mirrors the four accessors of src/matched/func_02035760.c:
 * four halfword stores into the object func_02035750 returns, at +0x64 and
 * +0x66 from the third and fifth arguments and at +0x6C and +0x6E from the
 * second and fourth.  The fifth argument is a stack argument, which is why
 * `ldrh r1, [sp, #0x10]` sits second - the argument area is above the pushed
 * {r4,r5,r6,lr}.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02035E84.c \
 *       --func func_02035E84 --addr 0x02035E84 --cc 1.1p1 --arm
 */
void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d)
{
    u8 *q;

    q = (u8 *)func_02035750();
    ((struct Obj06933 *)q)->f64 = c;
    ((struct Obj06933 *)q)->f66 = d;
    ((struct Obj06933 *)q)->f5C = a;
    ((struct Obj06933 *)q)->f5E = b;
}


int func_02035EB0(int a0, int a1, int a2){ int t0; t0 = func_02035750(); ((struct Obj11338 *)((char *)(t0)))->f68 = (unsigned short)a2; ((struct Obj11338 *)((char *)(t0)))->f60 = (unsigned short)a1; return t0; }



int func_02035ECC(int a0, int a1, int a2){ int t0; t0 = func_02035750(); ((struct Obj11339 *)((char *)(t0)))->f6A = (unsigned short)a2; ((struct Obj11339 *)((char *)(t0)))->f62 = (unsigned short)a1; return t0; }



T *func_02035EE8(u32 a)
{
    T *p = (T *)func_02030734(a, 0x4c, 0, (const char *)g_020A799C, 0x44);

    func_02082BCC(p, 0, 0x4c);
    p->f40 = 8;
    p->f44 = 0xf;
    return p;
}



#define HW_BUTTON_XY_BUF    0x02FFFFA8


#define REG_KEYINPUT        0x04000130


#define PAD_ALL_MASK        0x2FFF



static inline s32 PAD_DetectFold(void)
{
    return (s32)((*(vu16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15);
}



static inline u16 PAD_Read(void)
{
    return (u16)(((*(vu16 *)REG_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF) ^ PAD_ALL_MASK) & PAD_ALL_MASK);
}



/*
 * key.c.  The per-frame pad update: with the lid closed (PAD_DetectFold) the
 * six edge words are cleared; otherwise the pad is read (PAD_Read, the SDK
 * inline: KEYINPUT | the ARM7 XY buffer, ^ and & 0x2FFF, so the 0x2FFF mask
 * is the 0x02FFFFA8 pool word shifted right by 12, not a pool word of its
 * own), UP cancels DOWN and LEFT cancels RIGHT, trigger and repeat are
 * derived from the previous hold word at +0x0C, the repeat counter at +0x3C
 * reloads from +0x40 (speed) or +0x44 (delay), and func_020360B8 then remaps
 * the three published words before they are accumulated into +0x30..+0x38
 * and latched into +0x24..+0x2C on every other frame (ctx->f3e, a SIGNED
 * modulo-2 test on a u8 byte).  Both hardware addresses are cast constants, not
 * relocations.  Written from the SDK inline shapes (NitroSDK pad.h, library
 * function shapes only); EXACT on the first transcription.
 */
void func_02035F38(struct Ctx *ctx)
{
    struct Key *k = (struct Key *)func_0203521C((u32 *)ctx);
    u16 key;

    if (PAD_DetectFold()) {
        k->f1c = 0;
        k->f18 = 0;
        k->f20 = 0;
        k->f28 = 0;
        k->f24 = 0;
        k->f2c = 0;
        return;
    }

    key = PAD_Read();
    key = key & ~((key & 0x40) << 1) & ~((key & 0x20) >> 1);

    k->trg = key & (key ^ k->cont);
    k->rpt = key & (key ^ k->cont);
    if (key != 0 && k->cont == key) {
        if (--k->wait == 0) {
            k->rpt = key;
            k->wait = k->speed;
        }
    } else {
        k->wait = k->delay;
    }
    k->cont = key;
    k->f1c = k->trg;
    k->f18 = key;
    k->f20 = k->rpt;
    func_020360B8((struct Obj *)k);
    k->f34 |= k->f1c;
    k->f30 |= k->f18;
    k->f38 |= k->f20;
    if (ctx->f3e % 2 != 0) {
        return;
    }
    k->f28 = k->f34;
    k->f24 = k->f30;
    k->f2c = k->f38;
    k->f34 = 0;
    k->f30 = 0;
    k->f38 = 0;
}
