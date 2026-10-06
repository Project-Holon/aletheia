/*
 * file:     wipe_sub_p11.c
 * unit:     yes
 * function: func_0202350C, func_02023568, func_020235F0, func_0202363C, func_0202368C, func_02023768, func_020237B8
 * address:  0x0202350C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02022940  0x02022940  thumb
 *   func_02022E20  0x02022E20  thumb
 *   func_0202291C  0x0202291C  thumb
 *   func_02023D60  0x02023D60  thumb
 *   func_02030734  0x02030734  arm
 *   g_dat          0x020A7450  data
 *   func_02022D70   0x02022D70  thumb
 *   func_02022DCC   0x02022DCC  thumb
 *   func_020307B0   0x020307B0  arm
 *   func_02022D98  0x02022D98  thumb
 *   func_02022AD0  0x02022AD0  thumb
 *   func_0202384C  0x0202384C  thumb
 *   sub_020056A0   0x020056A0  thumb
 *   func_02022568  0x02022568  thumb
 *   _ll_mul   0x0209C054  arm
 *   FX_Sqrt   0x0207C7B4  arm
 */
struct Quad;
struct Ctx;
struct Par;
struct Wipe;
struct Container;
struct ctl;
struct Obj;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Obj_0202350C {
    u32 f00;
    u8  pad04[0x0c];
    u32 f10;       /* 0x10 */
    u8  pad14[0x0c];
    u32 f20;       /* 0x20 */
    u8  pad24[0x0c];
    u32 f30;       /* 0x30 */
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
};

typedef signed int     s32_0202350C;

typedef enum { Z0 } E;

typedef int          s32_02023568;

struct Obj_02023568 {
    s32_02023568 x;       /* 0x00 */
    s32_02023568 y;       /* 0x04 */
    s32_02023568 z;       /* 0x08 */
    s32_02023568 w;       /* 0x0c */
    u32 pad10[4];
    u32 f20;     /* 0x20 */
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    s32_02023568 steps;   /* 0x38 */
    s32_02023568 period;  /* 0x3c */
    s32_02023568 tick;    /* 0x40 */
    u32 f44;
    u32 f48;     /* 0x48 */
};

typedef unsigned short u16;

typedef signed char    s8;

struct S {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    void *f14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

struct Rec {
    u8  pad0[0xc];
    u32 mode;      /* +0xc */
    u32 f10;       /* +0x10 */
    void *entry;   /* +0x14 */
};

struct Entry {
    u8  pad0[0x2c];
    u32 f2c;       /* +0x2c */
    u32 f30;       /* +0x30 */
};

typedef signed short s16;

typedef int s32_0;

typedef struct Par {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
} Par;

typedef struct Ctx {
    u32 pad0[3];
    u32 c;
    u32 h10;
    u32 h14;
    u32 h18;
    u32 h1c;
    u32 h20;
    u32 h24;
    u32 h28;
    u32 h2c;
    u32 h30;
    u32 h34;
} Ctx;

typedef signed int   s32_1;

struct Wipe {
    u32 f00;
    u32 f04;
    u32 f08;
    s32_1 f0c;          /* 0x0c  running offset */
    u32 f10;
    u32 f14;
    s32_1 f18;          /* 0x18  stride */
    s32_1 left;         /* 0x1c  countdown */
    s32_1 frame_limit;  /* 0x20 */
    s32_1 frame;        /* 0x24 */
    u32 f28;          /* 0x28 */
    u32 f2c;
    u32 f30;
    u32 f34;          /* 0x34 */
};

typedef signed long long s64;

extern void func_02022940(struct Quad *cur, struct Quad *end, struct Quad *step, const u8 *from, const u8 *to, s32_0202350C frames);
extern void func_02022E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6, u32 a7, u32 a8, u32 a9);
extern void func_0202291C(struct Quad *dst, struct Quad *src);
extern void func_02023D60(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_02023768(struct Wipe *w);
extern void func_02022DCC(u32 a0, void *a1, u32 a2);
extern void func_02022D70(void *a0);
extern u32 func_020307B0(void *p);
extern s32_0 func_0202290C(s32_0 a, s32_0 b, s32_0 c);
extern void func_02022CEC(u32 *a0, u32 a1, u32 a2, u32 a3);
extern void func_0202384C(struct Wipe *w);
extern void func_020056A0(void *cb, Ctx *ctx, u32 v);
extern void *func_02022D88(struct Obj *obj, u32 idx);
extern void func_02022D98(void *p, struct Container *c);
extern int func_02022E88(int a0, int a1, int a2, int a3);
extern void func_02022AD0(struct ctl *ctl);
extern void func_02022518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_0202368C(Ctx *ctx, const Par *par, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7, u32 s8);
extern void *sub_020056A0(void *fn, void *arg, u32 prio);
extern void  func_02022568(u32 a0, u32 a1, u32 a2);
extern s32_1 FX_Sqrt(s32_1 x);
void func_020237B8(s32_1 a0, s32_1 a1, s32_1 a2, s32_1 a3, s32_1 *out0, s32_1 *out1);



/*
 * wipe_sub.  Closed 2026-09-24 (wave 21, lane E2) from the DIFF 2 recorded
 * in docs/notes/func_0202350C.c.txt.  Two matching levers carry it:
 *   - the zero is an enum-typed local (docs/idioms/an-enum-typed-zero-keeps-
 *     its-own-web-where-a-u32-zero-is-folded.md), read in image order k8, z,
 *     kb;
 *   - a5 is read through a volatile access placed after the f40 store and
 *     before the f44 store.  That puts a5's load (r0, the call's first
 *     argument) inside kb's live range, so kb can no longer take r0 and the
 *     zero does, while the f48 store stays last.  A plain copy of a5 is
 *     propagated back to the f48 store and does nothing (12 out).
 */
void func_0202350C(struct Obj_0202350C *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 k8;
    u32 kb;
    E z;
    u32 v5;
    func_02022940((struct Quad *)obj, (struct Quad *)(&obj->f20), (struct Quad *)(&obj->f10), cfg, cfg + 4, a2);
    k8 = cfg[8];
    z = Z0;
    kb = cfg[0x0b];
    obj->f30 = a4;
    obj->f40 = z;
    v5 = *(volatile u32 *)&a5;
    obj->f44 = kb;
    obj->f34 = k8;
    obj->f38 = a2;
    obj->f3c = a3;
    obj->f48 = v5;
    func_02022E20(v5, cfg[9], cfg[0x0a], cfg[8], a4, cfg[0], cfg[1],
                  cfg[2], cfg[3], obj->f44);
}


/*
 * One tick of the wipe object.  +0x40 is a frame counter compared against
 * the step length at +0x3c: until it reaches the step, nothing happens
 * and the answer is 0.  On a step boundary the counter resets and the
 * remaining-step count at +0x38 is decremented; while steps remain the
 * interpolator at +0x10 is advanced (func_0202291C) and the current
 * position is pushed to func_02023D60 with each of the three 1/128
 * fixed-point coordinates at +0x00, +0x04, +0x08 rounded toward zero
 * (`(v + (v >> 6 >> 25)) >> 7`, the compiler's signed /128), plus the
 * 1/128 scalar at +0x0c.  When the last step is used up the object jumps
 * straight to its final values (+0x2c, +0x20, +0x24, +0x28) and answers
 * 1, which is what func_020234C0 waits for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023568.c \
 *       --func func_02023568 --addr 0x02023568 --cc 1.1p1 --thumb
 */
u32 func_02023568(struct Obj_02023568 *o)
{
    s32_02023568 n;

    n = o->tick + 1;
    o->tick = n;
    if (n >= o->period) {
        o->tick = 0;
        n = o->steps - 1;
        if (n > 0) {
            o->steps = n;
            func_0202291C((struct Quad *)o, (struct Quad *)((char *)o + 0x10));
            goto step;
        }

        func_02023D60((u8 *)o->f48, o->f20, o->f24, o->f28, o->f2c, o->f34,
                      o->f30);
        return 1;

    step:
        func_02023D60((u8 *)o->f48, o->x / 128, o->y / 128, o->z / 128,
                      o->w / 128, o->f34, o->f30);
    }

    return 0;
}



/*
 * cap: the call at +0036 to func_0202368C (0x0202368C) is the only reference
 *      to that address outside its own body, and it is inside this range, so
 *      the `label` class refuses it.  All 76 bytes and the other relocation
 *      site (func_02030734) reproduce exactly.  Promotes to EXACT the moment
 *      func_0202368C has its own manifest entry.
 */
void func_020235F0(struct S *p, u32 a1)
{
    p->f14 = func_02030734((u16)p->f20, 0x38, 0, (const char *)0x020A7450, 0x0D63);
    func_0202368C(p->f14, (const struct Par *)a1, p->f04, p->f08, p->f10, p->f18, p->f1C, p->f20);
    p->f0C = p->f0C + 1;
}


/*
 *           reproduces (verified with match.py one), the sole unresolved
 *           relocation is the THM_CALL to func_02023768 (0202363C..0202368C
 *           has no outside witness for it). func_02023768 itself is a real
 *           DIFF near miss (see docs/notes/func_02023768.c.txt), not an
 *           EXACT/MATCH file, so it cannot supply a "matched" witness and
 *           the two cannot be folded into one tu unit yet.
 *
 * Dispatch on the +0xc mode word of a record: mode 1 closes the record's
 * +0x14 entry (via func_02023768) and, once it reports the entry now empty,
 * frees the pair at entry+0x2c/entry+0x30 through func_02022DCC (with the
 * record's own +0x10 as the third argument) and bumps +0xc, returning 0;
 * mode 2 tears the +0x14 entry down through func_02022D70/func_020307B0,
 * clears +0x14, bumps +0xc and falls into the same "return 1" tail as mode
 * 3 (mode 3 alone has no other side effect); anything else, and mode 1
 * without the entry becoming empty, returns 0.
 */
u32 func_0202363C(struct Rec *r)
{
    void *entry = r->entry;
    u32 result = 0;

    switch (r->mode) {
    case 1:
        if (func_02023768(entry) == 1) {
            struct Entry *e = (struct Entry *)entry;
            func_02022DCC(e->f2c, (void *)e->f30, r->f10);
            r->mode = r->mode + 1;
        }
        break;
    case 2:
        func_02022D70(entry);
        func_020307B0(r->entry);
        r->mode = r->mode + 1;
        r->entry = 0;
        result = 1;
        break;
    case 3:
        result = 1;
        break;
    default:
        break;
    }

    return result;
}


void func_0202368C(Ctx *ctx, const Par *par, u32 a2, u32 a3,
                   u32 s5, u32 s6, u32 s7, u32 s8)
{
    u32 t;
    s16 *base;
    u32 off;
    s32_0 w;
    s32_0 h;

    t = func_0202290C(par->f0, par->f2, a2);
    func_02022CEC((u32 *)ctx, par->f8, s5, s8);
    ctx->c = par->f0 << 7;
    ctx->h30 = s6;
    ctx->h10 = par->f4;
    ctx->h14 = par->f6;
    ctx->h18 = t;
    ctx->h1c = a2;
    ctx->h20 = a3;
    ctx->h24 = 0;
    ctx->h34 = s7;
    ctx->h28 = s8;
    ctx->h2c = par->fb;
    func_0202384C((struct Wipe *)ctx);
    off = 0x3ff;
    func_020056A0(func_02022D98, ctx, off);
    base = func_02022D88((struct Obj *)ctx, 0);
    w = *(s16 *)((char *)base + (off - 0xff));
    off += 0x81;
    h = *(s16 *)((char *)base + off);
    func_02022E20(s6, par->f9, par->fa, par->f8,
                  s5, w, 0, h, 0xc0, ctx->h2c);
    if (par->f8 == 0) {
        func_02022E88(s6, 1, s5, ctx->h2c);
    } else {
        func_02022E88(s6, 2, s5, ctx->h2c);
    }
    func_02022518(ctx->h34, (u32)ctx, (u32)func_02022AD0, s5, s8);
}



/*
 * The per-frame poll of the wipe object built at 0x02023464, and the near
 * twin of func_02023A50 at the other end of the family: tick the frame
 * counter at +0x24 against the limit at +0x20, and on expiry step the
 * countdown at +0x1c.  A countdown still above zero advances the running
 * offset at +0x0c by the stride at +0x18, redraws through func_0202384C
 * and re-arms the callback func_02022D98 at priority 0x3FF; a countdown
 * that has reached zero finishes through func_02022568 and is the only
 * path that answers 1.
 *
 * The countdown is decremented into a LOCAL and only stored back on the
 * arm that keeps going: `n = w->left - 1; if (n > 0) { w->left = n; ... }`.
 * Written as a compound `w->left -= 1` followed by a test of the field the
 * store lands before the branch and the `ldr`/`subs`/`cmp` triple at
 * +0x1c..+0x22 becomes four instructions
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md).
 *
 * Like func_02023A50 this has exactly two exits sharing one `movs r0, #0;
 * pop {r4, pc}` tail, which is what the single trailing `return 0` after
 * the whole nest buys; a `return 0` in each arm duplicates the epilogue
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02023768.c \
 *       --func func_02023768 --addr 0x02023768 --cc 1.1p1 --thumb
 */
u32 func_02023768(struct Wipe *w)
{
    s32_1 f;
    s32_1 n;

    f = w->frame + 1;
    w->frame = f;
    if (f >= w->frame_limit) {
        w->frame = 0;
        n = w->left - 1;
        if (n > 0) {
            w->left = n;
            w->f0c = w->f0c + w->f18;
            func_0202384C(w);
            sub_020056A0((void *)func_02022D98, w, 0x3FF);
        } else {
            func_02022568(w->f34, w->f08, w->f28);
            return 1;
        }
    }

    return 0;
}


/*
 * Compiled to 146 bytes; the listing's inferred 148-byte extent (to
 * 0x0202384C, the next labelled function) runs 2 bytes past what the
 * compiler actually emits here, never a byte difference: EXACT*.
 *
 * Fixed-point vertical-band test: a0/128 (signed division, the classic
 * sign-spread rounding-toward-zero idiom) is a limit compared against the
 * absolute difference of two row indices a2/a3. If the row distance
 * reaches or exceeds the limit, both outputs are zeroed and the function
 * returns immediately (void; the original never sets a return value on
 * either path). If the row distance is inside the limit, the function
 * computes
 * sqrt(round(limit'^2) - round(dist'^2)) where limit' = limit<<12 and
 * dist' = |a3-a2|<<12, each square taken in 64 bit through the compiler's
 * signed multiply helper _ll_mul (contract r0:r1 * r2:r3 -> r0:r1, see
 * docs/idioms/consecutive-ll-udiv-calls-are-one-chained-64-bit-expression.md)
 * and each rounded by +0x800 before its own >>12 splice. FX_Sqrt of the
 * difference gives a radius r (already >>12'd back to a plain s32 by the
 * asrs after the call); *out0 = a1 - r (clamped to 0) and
 * *out1 = *out0 + 2*r (clamped to 0xff).
 */
void func_020237B8(s32_1 a0, s32_1 a1, s32_1 a2, s32_1 a3, s32_1 *out0, s32_1 *out1)
{
    s32_1 limit = a0 / 128;
    s32_1 dist = a3 - a2;
    s32_1 r;

    if (dist < 0) {
        dist = -dist;
    }

    if (dist >= limit) {
        *out0 = 0;
        *out1 = 0;
        return;
    }

    {
        s64 sq_limit = (s64)(limit << 12) * (s64)(limit << 12);
        s64 sq_dist  = (s64)(dist  << 12) * (s64)(dist  << 12);
        s32_1 t0 = (s32_1)((sq_limit + 0x800) >> 12);
        s32_1 t1 = (s32_1)((sq_dist  + 0x800) >> 12);

        r = FX_Sqrt(t0 - t1) >> 12;
    }

    *out0 = a1 - r;
    if (*out0 < 0) {
        *out0 = 0;
    }
    *out1 = *out0 + r * 2;
    if (*out1 > 0xff) {
        *out1 = 0xff;
    }
}
