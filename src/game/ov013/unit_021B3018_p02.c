/*
 * file:     unit_021B3018_p02.c
 * unit:     yes
 * function: func_021B3250, func_021B3278, func_021B3364, func_021B33E0, func_021B33F8, func_021B3604, func_021B3624, func_021B370C, func_021B3844, func_021B386C, func_021B38B0, func_021B3924
 * address:  0x021B3250
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B3C50     0x021B3C50  data a4
 *   func_021B3018  0x021B3018  arm ov013
 *   d_021B4C48     0x021B4C48  data ov013
 *   d_021B3C60     0x021B3C60  data a2
 *   d_021B50CC     0x021B50CC  data a2
 *   d_021B4C74     0x021B4C74  data a4
 *   d_021B4C5C     0x021B4C5C  data a4
 *   MIi_CpuCopyFast 0x02082B0C  arm
 *   d_021B4C8C     0x021B4C8C  data a4
 *   func_02004EB0  0x02004EB0  arm
 *   d_02005108     0x02005108  data
 *   func_02082BCC  0x02082BCC  arm
 *   d_021B60CC     0x021B60CC  data ov013
 *   d_021B60D8     0x021B60D8  data ov013
 *   func_021B0508  0x021B0508  arm ov013
 *   func_021B22B4  0x021B22B4  arm ov013
 *   func_021B23C8  0x021B23C8  arm ov013
 *   func_021B2ED8  0x021B2ED8  arm ov013
 *   func_021B2F98  0x021B2F98  arm ov013
 *   func_021B0600  0x021B0600  arm ov013
 *   func_021B23E0  0x021B23E0  arm ov013
 *   func_021B11E8  0x021B11E8  arm ov013
 *   func_021B111C  0x021B111C  arm ov013
 *   func_021B3924  0x021B3924  arm ov013
 */
#include "unit_021B3018_types.h"

#define reg_CP_DIVCNT       (*(volatile u16 *)0x04000280)
#define reg_CP_DIV_NUMER    (*(u64 *)0x04000290)
#define reg_CP_DIV_DENOM    (*(u64 *)0x04000298)
#define reg_CP_DIV_RESULT_L (*(volatile u32 *)0x040002A0)
#define reg_CP_SQRTCNT      (*(volatile u16 *)0x040002B0)
#define reg_CP_SQRT_RESULT  (*(volatile u32 *)0x040002B4)
#define reg_CP_SQRT_PARAM   (*(u32 *)0x040002B8)
typedef enum { CountZero } Count;

struct Config;
struct E;

typedef struct {
    int f0;
    int f4;
    int f8;
    u8  fc;
    u8  fd, fe, ff;
    int f10;
    int f14;
    int f18;
    int f1c;
} Param;

extern void func_021B3018(void);
extern void MIi_CpuCopyFast(void *src, void *dst, u32 n);
extern void func_02004EB0(const void *symbol);
extern void func_02082BCC(void *dst, int c, int n);
extern int  func_021B0508(void);
extern int func_021B22B4(struct Config *cfg);
extern void func_021B23C8(void);
extern int func_021B2ED8(struct E *a, u32 b);
extern void func_021B2F98(void);
extern void func_021B0600(void);
extern void func_021B23E0(void);
extern int func_021B11E8(void);
extern int func_021B111C(void);
extern unsigned long long func_020870D0(void);
typedef struct {
    unsigned int magic;
    unsigned char type;
} Hdr_021B3924;

extern int func_021B0F38(int a0, Hdr_021B3924 *h, int a2, unsigned long long t);
extern int func_021B2488(int a, unsigned char *p, int len, int x);
int func_021B3924(int a0, Hdr_021B3924 *h, int a2, int *a3);
void func_021B3250(void);
s32 func_021B3278(s16 *x, u32 len);
void func_021B3364(void);
void func_021B33E0(void *a, u32 b);
void func_021B3604(short *a, unsigned int b, unsigned int c);
void func_021B3624(s16 *a, s16 *b, s16 *d, u32 len);
int func_021B370C(Param *p);
void func_021B3844(void);
void func_021B386C(void);
int func_021B38B0(int a, int b, int c);

extern VadCfg d_021B3C50;
extern struct G_021B4C48 d_021B4C48;
extern s16 d_021B3C60[];
extern s16 d_021B50CC[];
extern int d_021B4C74[];
extern int d_021B4C5C[];
extern short d_021B4C8C[];
extern char d_02005108[];
extern struct G_021B60CC d_021B60CC;
extern u8   d_021B60D8[];


/*
 * lever: enum count cast to short preserves the smulbb; short local folded 15*68.
 */
void func_021B3250(void)
{
    Count n=15;
    short stride=68;
    d_021B3C50.f8=n;
    d_021B3C50.fC=(short)n*stride;
    func_021B3018();
}



static inline void CP_SetDiv64_32(u64 numer, u32 denom)
{
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = numer;
    reg_CP_DIV_DENOM = denom;
}



static inline void CP_WaitDiv(void)
{
    while (reg_CP_DIVCNT & 0x8000) {
    }
}



s32 func_021B3278(s16 *x, u32 len)
{
    s32 prev;
    u32 i;
    s64 e;
    s32 y;
    s32 t;

    t = x[0] * 0xE9F;
    y = (t + d_021B4C48.hp_prev + d_021B4C48.hp_y * 0xD3E) >> 12;
    d_021B4C48.hp_y = y;
    d_021B4C48.hp_prev = prev = -t;
    e = y * y;
    len >>= 1;
    i = 1;
    if (len > 1) {
        do {
            t = x[i] * 0xE9F;
            x[i - 1] = y;
            y = (t + prev + y * 0xD3E) >> 12;
            e += y * y;
            prev = -t;
        } while (++i < len);
        d_021B4C48.hp_prev = prev;
        d_021B4C48.hp_y = y;
    }
    (x + len)[-1] = y;
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = e;
    reg_CP_DIV_DENOM = len;
    CP_WaitDiv();
    return reg_CP_DIV_RESULT_L;
}



void func_021B3364(void)
{
    int i;
    s16 *src;

    src = d_021B3C60;
    d_021B4C48.wr = 0;
    d_021B4C48.rd = 0x19D;
    for (i = 0; i < 0x800; i++)
        d_021B50CC[i] = 0;
    for (i = 0; i < 6; i++) {
        d_021B4C74[i] = 0;
        d_021B4C5C[i] = src[i];
    }
}



void func_021B33E0(void *a, u32 b)
{
    MIi_CpuCopyFast(a, d_021B4C8C, b);
}


static inline void CP_SetSqrt32(u32 param)
{
    reg_CP_SQRTCNT = 0;
    reg_CP_SQRT_PARAM = param;
}




#pragma opt_common_subs off



/*
 * note 2026-10-05 (integrator): EXACT. The tail guard tests the counter, `i = 0; if (i < n) { sh = att; do ... while (i < n); }`, which gives the unsigned `ls` exit; `n != 0` gave `eq` (2 B).
 *
 * note (2026-10-05, wave P4 lane S4, pengy share, approved for this function):
 *   Semantics recovered from the listing: a 6-tap FIR over the state at
 *   d_021B4C48 (ring index [2],[3] masked 0x7FF, coefficients [5..10], delay line
 *   [11..16]) that filters b[], leaves b[i] = a[i], sums squares into an s64, then
 *   divides by n/2 (DIVCNT mode 1), takes the hardware sqrt, and scales a[] by an
 *   attenuation shift kept in the halfword at state[0] (0 when 3*rms < 2*thr,
 *   4 when thr < rms, else +1 up to 4).
 *   Residue: 472 bytes against 524. The original keeps the s64 sum e at
 *   [sp+8..0xc], the ring index w at [sp], and a dead store of the delay value at
 *   [sp+4] (frame 0x10, no fp); every spelling here keeps e in fp and r4 instead
 *   and spills the coefficient c4 to [sp]. Same code with the same bytes (472) for:
 *   explicit tap statements, a rolled loop (444, wrong), delay chain in a temp,
 *   tap locals d0..d5 with d5 = d4, u64 e, opt_dead_assignments off (with and
 *   without a dead local), a u32 base local for the ring buffer, and an inline
 *   FIR-step helper. All taps up front as locals gives 564. Tried 14 compiles.
 *   Idea left: e, w and the dead word look like memory-resident locals (address
 *   taken by an inline helper with out parameters).
 *
 * note (2026-10-05, wave P4 lane S4b, pengy share):
 *   Now 512 bytes against 524 (was 472). Two source changes found:
 *   (1) the ring write index is read once into a local (v = state[3]) and reused
 *   for the ring store and for state[3] = (v + 1) & 0x7FF; the original keeps it
 *   in r7 across the whole tap chain and never re-reads it. That alone puts e in
 *   [sp] memory (a spill) and removes fp.
 *   (2) the sqrt start is an inline helper CP_SetSqrt32(u32 param) called with
 *   reg_CP_DIV_RESULT_L as the argument, so the result load comes before the
 *   SQRTCNT store and the pool word is 0x040002A0 as in the original. The whole
 *   tail after the loop now matches except for register numbers.
 *   Residue: the original spills three webs (e at sp+8, w=state[2] at sp, the
 *   delay value d4 at sp+4, never reloaded; frame 0x10, no fp, state in ip, mask
 *   in lr, i in r8). Ours spills e plus one coefficient and keeps w in a register
 *   (frame 0xc plus an r3 pad). The original therefore has about three more live
 *   values in the tap chain than ours; none found.
 *   Tried (17 compiles, none better than 512): struct local for e/w/d5 (scalar
 *   replaced, same bytes), inline AddSq(&e) helper (inlined, same bytes), the six
 *   per-function pragmas on the 512 form (opt_lifetimes, opt_propagation,
 *   opt_common_subs, opt_dead_assignments, scheduling, peephole: all >= 508 and
 *   worse), declaration order of v/w (first, last), u32 v/w, pointer locals
 *   c = state + 5 and d = state + 11 (552, worse: pointers stay live).
 *
 * final push 2026-10-05 G9L10 (40 compiles, 3 rounds): now 2 bytes off of 524 (was 417). Only the
 *   tail guard differs: original `cmp r2,#0; addls; popls` before a loop-invariant `ldrsh r4,[r1]`
 *   (att hoisted into the preheader after the guard); ours gives `addeq` because the explicit
 *   `if (n != 0) { sh = att; do ... }` form is the only one that put the load after the guard.
 *   Causes found: (1) the state and the ring buffer are ONE object: a struct with s16 buf[] at +0x484
 *   and a local `ring = d_021B4C48.buf` (pool word sym+0x484 reloaded per use, w load after the ring
 *   store, w spilled at its definition, frame 0x10, push list and slots as the original). Separate
 *   externs let the scheduler hoist the w load above the ring store and raised the pressure.
 *   (2) first tap written `d5 * c10 + d4 * c9` (mwcc fuses the left product into mla). (3) per-function
 *   `#pragma opt_common_subs off` makes d4 (not c10) the spilled web with the original load order;
 *   without it 53 B off. (4) declaration order v then i gives i=r8, v=r7. (5) tail shift amount read
 *   once into a local before the loop. Tried without effect: opt_propagation off do-while, struct
 *   local {w,d,e} (scalar replaced), dead local + opt_dead_assignments off (vanishes), scheduling
 *   pragma (no-op on ARM), pointer locals for state/ring, named products, store before the taps,
 *   in-loop shift read under common_subs off (18 B).
 */
void func_021B33F8(s16 *a, s16 *b, u32 n, u32 thr)
{
    s16 *ring = d_021B4C48.buf;
    s64 e;
    u32 rms;
    s32 acc;
    s32 w;
    s32 v;
    u32 i;
    s32 r;
    s32 sh;
    s32 d0, d1, d2, d3, d4, d5;

    e = 0;
    n >>= 1;
    for (i = 0; i < n; i++) {
        v = d_021B4C48.wr;
        ring[v] = b[i];
        w = d_021B4C48.rd;
        d_021B4C48.x[0] = ring[w];
        d5 = d_021B4C48.x[5];
        acc = d5 * d_021B4C48.c[5] + d_021B4C48.x[4] * d_021B4C48.c[4];
        d_021B4C48.x[5] = d_021B4C48.x[4];
        d3 = d_021B4C48.x[3];
        acc += d3 * d_021B4C48.c[3];
        d_021B4C48.x[4] = d3;
        d2 = d_021B4C48.x[2];
        acc += d2 * d_021B4C48.c[2];
        d_021B4C48.x[3] = d2;
        d1 = d_021B4C48.x[1];
        acc += d1 * d_021B4C48.c[1];
        d_021B4C48.x[2] = d1;
        d0 = d_021B4C48.x[0];
        acc += d0 * d_021B4C48.c[0];
        d_021B4C48.x[1] = d0;
        if (acc > 0x3FFF8000)
            acc = 0x3FFF8000;
        else if (acc < (s32)0xC0000000)
            acc = (s32)0xC0000000;
        d_021B4C48.wr = (v + 1) & (0x3FFF8000 >> 19);
        d_021B4C48.rd = (w + 1) & (0x3FFF8000 >> 19);
        b[i] = acc >> 15;
        r = b[i];
        b[i] = a[i];
        e += r * r;
    }
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = e;
    reg_CP_DIV_DENOM = n;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    CP_SetSqrt32(reg_CP_DIV_RESULT_L);
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    rms = reg_CP_SQRT_RESULT;
    if (rms * 3 < thr * 2) {
        d_021B4C48.att = 0;
        return;
    }
    if (thr < rms)
        d_021B4C48.att = 4;
    if (d_021B4C48.att < 4)
        d_021B4C48.att = d_021B4C48.att + 1;
    i = 0;
    if (i < n) {
        sh = d_021B4C48.att;
        do {
            a[i] >>= sh;
            i++;
        } while (i < n);
    }
}



#pragma opt_common_subs reset



void func_021B3604(short *a, unsigned int b, unsigned int c)
{
    func_021B33F8(a,d_021B4C8C,b,c);
}




void func_021B3624(s16 *a, s16 *b, s16 *d, u32 len)
{
    u32 i;
    u32 n;
    s32 v;

    n = len >> 1;
    for (i = 0; i < n; i += 4) {
        v = a[i] + b[i];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i] = v;
        v = a[i + 1] + b[i + 1];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i + 1] = v;
        v = a[i + 2] + b[i + 2];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i + 2] = v;
        v = a[i + 3] + b[i + 3];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i + 3] = v;
    }
}




int func_021B370C(Param *p)
{
    func_02004EB0(d_02005108);
    if (p == 0)
        return 0;
    if (d_021B60CC.f8 != 0)
        return 1;
    if (p->f8 != 1 && p->f8 != 2 && p->f8 != 3)
        return 0;
    if (p->f18 == 0)
        return 0;
    if (p->f10 == 0 || p->f14 == 0)
        return 0;
    if (p->f10 % 32 != 0)
        return 0;
    func_02082BCC(d_021B60D8, 0, 0x18);
    d_021B60CC.fn = (void (*)(int, int, int, int))p->f18;
    d_021B60CC.arg = p->f1c;
    d_021B60CC.f1C = p->f8;
    d_021B60CC.f18 = 0;
    if (p->fc >= 0x20)
        return 0;
    d_021B60CC.fC = p->fc;
    if (func_021B2ED8((struct E *)p->f10, p->f14) == 0) {
        func_021B2F98();
        return 0;
    }
    if (func_021B22B4((struct Config *)p) == 0) {
        func_021B2F98();
        return 0;
    }
    if (func_021B0508() != 0) {
        d_021B60CC.f8 = 1;
        return 1;
    }
    func_021B23C8();
    func_021B2F98();
    return 0;
}




void func_021B3844(void)
{
    func_021B0600();
    func_021B23C8();
    func_021B2F98();
    d_021B60CC.f1C = 0;
    d_021B60CC.f8 = 0;
}


void func_021B386C(void)
{
    if (d_021B60CC.f8 == 0)
        return;
    d_021B60CC.f0++;
    if ((d_021B60CC.f0 & 0xf) == 0)
        func_021B23E0();
    if (func_021B11E8())
        func_021B111C();
}


int func_021B38B0(int a, int b, int c)
{
    int out[2];

    switch (func_021B3924(a, (Hdr_021B3924 *)b, c, out)) {
    case 0:
        break;
    case 1:
        d_021B60CC.fn(a, out[0], out[1], d_021B60CC.arg);
        return 1;
    case 2:
        return 0;
    }
    return 1;
}

#pragma opt_common_subs off
extern unsigned long long func_020870D0(void);
extern int func_021B0F38(int a0, Hdr_021B3924 *h, int a2, unsigned long long t);
extern int func_021B2488(int a, unsigned char *p, int len, int x);

int func_021B3924(int a0, Hdr_021B3924 *h, int a2, int *a3)
{
    unsigned long long t;

    if (h == 0)
        return 0;
    if (h->magic != 0x5F564354)
        return 2;
    if (d_021B60CC.f1C == 0 || d_021B60CC.f8 == 0)
        return 0;
    a3[0] = 0;
    a3[1] = 0;
    t = func_020870D0();
    if ((h->type & 0xf0) == 0x40) {
        d_021B60CC.f4++;
        func_021B0F38(a0, h, a2, t);
        return 0;
    }
    if (h->type == 0 || h->type == 0xff)
        return func_021B2488(a0, (unsigned char *)h, a2, (int)a3) != 0;
    return 0;
}
#pragma opt_common_subs reset
