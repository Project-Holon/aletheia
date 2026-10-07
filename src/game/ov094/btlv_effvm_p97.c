/*
 * file:     btlv_effvm_p97.c
 * unit:     yes
 * function: func_02204C98, func_02204CC0, func_022050F0, func_02205340
 * address:  0x02204C98
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220A5B0  0x0220A5B0  data
 *   d_0220A5D0  0x0220A5D0  data
 *   d_0220A5F0  0x0220A5F0  data
 *   d_0220A392  0x0220A392  data
 *   d_0220A3C4  0x0220A3C4  data
 *   d_0220A4AC  0x0220A4AC  data
 *   func_02205768  0x02205768  thumb  ov094
 *   func_0201DE00  0x0201DE00  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02049F34  0x02049F34  arm
 *   func_020215BC  0x020215BC  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_0220A7FC     0x0220A7FC  data
 *   d_0220A94C     0x0220A94C  data
 *   func_020498F4  0x020498F4  arm
 */
#include "../../matched/include/Obj21781.h"
#include "../../matched/include/Obj21782.h"
#include "../../matched/include/Obj01909.h"

struct StrObj;
struct Bank;
struct MsgBank;
struct Obj;
struct U16Vec;
struct WordSet;
struct PalAnmSlot;
struct Struct36;
struct Vec2;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_02204CC0;

typedef struct Point { s16_02204CC0 x, y; } Point;

typedef struct Pos { int x, y; } Pos;

typedef struct PosTab { Pos v[4]; } PosTab;

typedef struct { int w[9]; } Struct36;

typedef struct Slots {
    u16 id[4];
    u8 a[4];
    u8 b[4];
} Slots;

typedef struct Work {
    char pad0[0x50];
    int mode;           /* 0x50 */
    char pad54[0x5c - 0x54];
    void *msgdata;      /* 0x5c */
    char pad60[0x64 - 0x60];
    void *bg;           /* 0x64 */
    char pad68[0x1e0 - 0x68];
    u32 res[4];         /* 0x1e0 */
    u32 r1f0;           /* 0x1f0 */
    u32 r1f4;           /* 0x1f4 */
    void *sys;          /* 0x1f8 */
    void *obj[4];       /* 0x1fc */
    char pad20c[0x224 - 0x20c];
    void *fnt;          /* 0x224 */
    char pad228[0x22c - 0x228];
    void *win;          /* 0x22c */
    char pad230[0x240 - 0x230];
    u16 heap;           /* 0x240 */
    char pad242[0x25a - 0x242];
    u8 f25a[8];         /* 0x25a */
    u8 f262[4];         /* 0x262 */
} Work;

typedef struct Entry {
    u8 kind : 2;
    u8 flag : 1;
    u8 pad0 : 5;
    u8 pad1[3];
    short show;
    short pad6;
    void *text;
} Entry;

typedef struct Info {
    Entry e[6];
    u8 b48;
    u8 b49;
} Info;

typedef struct Bits6C {
    u32 lo : 2;
    u32 x : 8;
    u32 hi : 22;
} Bits6C;

typedef struct Out {
    u32 pad[3];
    int fc;
} Out;

typedef struct Res {
    u32 pad[3];
    u16 *fc;
} Res;

typedef signed short   s16_022050F0;

typedef short s16_02205340;

typedef struct Main {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x224 - 0x4C];
    int o224;
    unsigned char pad228[0x22c - 0x228];
    int o22c;
    unsigned char pad230[0x240 - 0x230];
    u16 h240;
    unsigned char pad242[0x25a - 0x242];
    u8 b25a;
    u8 b25b;
} Main;

extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern int func_0207C994(int n, int d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern u32 func_0201BD28(u16 id, u32 field);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 func_020275E4(void);
extern u32 func_020275F8(u32 a);
extern u8 func_020275EC(int i);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_02082A60(const void *, void *, int);
extern u32 func_020307B0(void *p);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *, s16_02204CC0, s16_02204CC0, void *, void *);
extern int func_02205768(int a, int b);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void func_02204C98(struct StrObj *a, int b, int *outn, int *outq);
void func_02204CC0(Work *p, const Slots *q);
void func_022050F0(char *s, Out *out, const Info *p);
void func_02205340(Main *m, const int *c);
extern const PosTab d_0220A5B0;
extern const PosTab d_0220A5D0;
extern const int d_0220A5F0[];
extern const u16 d_0220A392[];
extern const Point d_0220A3C4[];
extern const Pos d_0220A4AC[];
extern const int d_0220A7FC[2][6][2];
extern const int d_0220A94C[2][3][15];


void func_02204C98(struct StrObj *a, int b, int *outn, int *outq)
{
    int n = func_0201D304(a, b, 0);
    int q = n / 8;
    if (func_0207C994(n, 8) != 0)
        q++;
    *outn = n;
    *outq = q;
}



#pragma opt_common_subs off

#pragma opt_propagation off

/*
 * note (2026-10-01): DIFF. Control flow, call order, argument values, hoisted
 *   offset constants and the address-taken frame block (t1 0xf8, t2 0xd8, buf 0xb4,
 *   w/h, cd/pd, c) all line up; the loop needs the (i < 4) ? 1 : 0 test to keep the
 *   branch-to-bottom entry, and the shared heap local keeps (heap & 0x7fff) | 0x8000
 *   ahead of func_020275E4. Left: register allocation. The image keeps q in r6 and
 *   recomputes p + i*4, q + i*2 and q + i after every call (only i*8 lives in r7, k
 *   and font are spilled, font at sp+0x9c just under c); 1.1p1 CSEs those sums
 *   across the calls, so q spills, k takes r7 and every slot shifts. Breaking the
 *   CSEs with (u32)i / (s32)(u32)i casts per call group plus a temporary for the
 *   func_0204B294 result (so the store address is formed after the call) gets the
 *   p/i registers and the per-call recompute, but q still lands in r7 and k in r6.
 *   Also open: func_0201DD78's colour arguments are evaluated r2, r1, r0 in the
 *   image (col kept in r0), ours evaluates r0 first and copies col to r3.
 * note (2026-10-02, lane A2-06): source now has the casts per call group (the
 *   recompute pattern of every p/q/i sum matches the image), the obj temporary,
 *   a Work struct for p, and (&tbl[i].x)[1] for the three y arguments: plain
 *   .y makes 1.1p1 form tbl + i*8 at the head of the call and spill it (sibling
 *   022050F0 does that, this image does not); the (&x)[1] spelling reproduces
 *   the image's x-load, w/2, late y-address order (checked in a loop probe).
 *   Measured inert for the allocator: block-scoped k/arc/chr/obj, heap inline,
 *   if/else inverted, x in a local, u8 locals or u8/u32 prototype for the
 *   colour call, font as a pointer, u32, long or u16, the cast spelling set itself, a
 *   q copy local, dead q uses. Still open, all allocator: q r7 (image r6), k
 *   and pltt take r6 (image spills both, k at sp+0x30, pltt at sp+0x3c), the
 *   second w/2 temp lands in r6 (image spills it to sp+0x68), frame 0x10c vs
 *   0x118, and the image's t1 call copies i*8 (adds r2, r7, #0). Slot order in
 *   the image is reverse declaration with font last (sp+0x9c); ours spills font
 *   right after file. volatile font declared last puts font just under c but
 *   flips p/i (image p r4, i r5); a 4-byte struct Font gets frame 0x118.
 *   Witness gaps once bytes match: func_020275F8, func_020275EC (arm, no caller
 *   outside this body) and the six d_0220Axxx tables are unresolved relocations.
 * note (2026-10-02, lane A2 follow-up): cause found, not closable under the
 *   lane rules. The image is this body compiled with global CSE off: with
 *   `#pragma opt_common_subs off` above the function, the natural spelling
 *   (no index casts, no obj temporary, plain tbl[i].y) gives 1072 bytes, frame
 *   0x118, p r4 / i r5, font at sp+0x9c and every spill and hoist slot of the
 *   image's prologue, and only 308 bytes differ. The casts, obj and (&x)[1]
 *   in this draft are stand-ins that emulate CSE-off. The `(i < 4) ? 1 : 0`
 *   condition is still needed (CSE-off alone still rotates a plain loop: 547).
 *   Left with the pragma: q r7 / i*8 r6 (image q r6 / i*8 r7), the slot order
 *   of the 0x224/0x22c hoisted constants (first print group lowest, image
 *   highest), the w/2 sign temp spilled in the first print (image: third), the
 *   colour call channels evaluated r0 first (image r2 first; u8 r/g/b locals
 *   are copy-propagated, inert), and 0x06600000 + buf operand order.
 *   Measured as NOT disabling the CSE (probes and full body): int/u8/u16/s16/
 *   u32/long/enum counter, register on params/counter, volatile Slots, void *
 *   params cast per use, static inline accessor, raw `char *` offsets in every
 *   form ((s + i * 4) + K, s + (i * 4 + K), ((T *)(s + K))[i]), up to 100
 *   extra locals, 3000 extra statements, 1500 extra branches, switch, static
 *   local, function pointer, struct copy/return, varargs, bit-field, float,
 *   division, long long. `asm { nop }` disables it but also constant
 *   propagation (offsets go to the pool), so not that either. The pragma is
 *   user-approved 2026-10-02.
 * note (2026-10-02, lane A2 pragma): neighbour check. The CSE-off pattern is
 *   per-function, not per-file: the EXACT next function func_022050F0 (same
 *   Work struct, same print callees, normal settings) keeps i*12 at sp+0x14
 *   and p+i*12 at sp+0x10 and reuses both after calls (ldr r2,[sp,#0x10] at
 *   0x022051B4 after blx 0x02045EC0; ldr r0,[sp,#0x14] at 0x02205212 after
 *   blx 0x02045808), which CSE off cannot produce. So the pragma is scoped
 *   to this function (opt_common_subs off ... reset).
 *   Result: CSE off alone leaves 309 bytes. The image also needs
 *   `#pragma opt_propagation off` (user-approved 2026-10-02). `#pragma
 *   opt_dead_assignments off` in its place gives byte-identical output, so
 *   which of the two the original used cannot be recovered. Both are scoped
 *   to this function with reset after it: the neighbour evidence above
 *   (022050F0 compiled with normal settings) shows the settings are
 *   per-function.
 *   What closes the rest once both pragmas are on: (1) the colour channels
 *   as u8 locals assigned b, g, r and passed r, g, b (keeps col in r0, the
 *   image's r2-first order, and with it q r6 / i*8 r7, the 0x224/0x22c hoist
 *   slot order and the w/2 spill in the third print); (2) `const Slots *q`
 *   (q + i formed before the stack-argument stores of both func_0201EFA4
 *   calls); (3) the enum VRAM_BASE local of the EXACT sibling func_02205F88
 *   for the 0x06600000 + buf operand order. Measured inert or worse:
 *   opt_lifetimes off (alone 713, with CSE off no change), optimization_level
 *   0..3, global_optimizer off, optimize_for_size, opt_dead_code off,
 *   opt_strength_reduction off, scheduling off, declaration order of every
 *   register local, colour/EFA4/02049F34 prototypes (incl. unprototyped),
 *   the EFA4 third-argument spelling, inline heap/arc, loop-condition forms.
 *   The last relocation, func_020275EC, resolved once arm9 0x020275EC was
 *   seeded as a Thumb leaf (src/matched/arm9/func_020275EC.c, EXACT).
 */
void func_02204CC0(Work *p, const Slots *q)
{
    PosTab t1 = d_0220A5B0;
    PosTab t2 = d_0220A5D0;
    int font;
    void *pltt;
    void *chr;
    u32 arc;
    int k;
    int file;
    void *str1;
    void *m0;
    void *str2;
    void *m2;
    void *m1;
    u16 heap;
    int i;
    Struct36 buf;
    int w;
    int h;
    void *cd;
    void *pd;
    u8 c[3];
    int col;
    u8 cr, cg, cb;
    enum { VRAM_BASE = 0x06600000 } vram;

    str1 = func_020457B0(0x10, p->heap);
    m0 = func_02045EC0(p->msgdata, 0);
    m1 = func_02045EC0(p->msgdata, 1);
    font = (int)func_0201EC64(p->heap);
    str2 = func_020457B0(0x10, p->heap);
    m2 = func_02045EC0(p->msgdata, 2);
    func_0204B22C(p->sys, 0);
    for (i = 0; (i < 4) ? 1 : 0; i++) {
        if (q->id[i] != 0) {
            k = func_0201BD28(q->id[i], 0);
            file = d_0220A5F0[k];
            p->obj[i] = func_0204B294(p->sys, p->res[i], p->r1f0, p->r1f4, d_0220A392, 1, p->heap);
            func_0204B404(p->obj[i], (const struct Vec2 *)(&d_0220A3C4[i]), (int)1);
            heap = (p->heap & 0x7fff) | 0x8000;
            arc = func_020275E4();
            chr = func_02049E34(arc, func_020275F8((u8)k), 0, (u32)(&cd), heap);
            func_0204B6F4(p->obj[i], func_020275EC((u8)k), 1);
            func_0204B7C8(p->obj[i], (struct Struct36 *)(&buf));
            vram = VRAM_BASE;
            func_02082A60(((struct Obj21781 *)cd)->f14, (void *)(vram + buf.w[2]), 0x100);
            func_020307B0(chr);
            func_0201DE00(&c[2], &c[1], &c[0]);
            func_0201DD78(1, 2, 0);
            func_0201EF34((struct WordSet *)font, 0, q->id[i]);
            func_0201F250((struct WordSet *)font, str1, m0);
            func_02204C98(str1, (int)p->fnt, &w, &h);
            func_0201C7A4(p->win, d_0220A4AC[i].x - w / 2, d_0220A4AC[i].y, str1, p->fnt);
            func_0201EFA4((struct WordSet *)font, 0, q->a[i], 2, 1, 1);
            func_0201EFA4((struct WordSet *)font, 1, q->b[i], 2, 1, 1);
            func_0201F250((struct WordSet *)font, str2, m2);
            col = func_02205768(q->a[i], q->b[i]);
            cb = (u8)(col & 0x1f);
            cg = (u8)((col >> 5) & 0x1f);
            cr = (u8)((col >> 10) & 0x1f);
            func_0201DD78(cr, cg, cb);
            func_0201C7A4(p->win, t1.v[i].x, t1.v[i].y, m1, p->fnt);
            func_02204C98(str2, (int)p->fnt, &w, &h);
            func_0201C7A4(p->win, t2.v[i].x - w / 2, t2.v[i].y, str2, p->fnt);
            func_0201DD78(c[2], c[1], c[0]);
            p->f25a[i] = q->a[i] != 0;
            p->f262[i] = q->id[i] != 0;
        } else {
            file = 0xc1;
        }
        heap = (p->heap & 0x7fff) | 0x8000;
        pltt = func_02049F34(0xb, file, (u32)(&pd), heap);
        func_020215BC(p->bg, ((struct Obj21782 *)pd)->fC, (int)1, (u16)(i * 16 + 0x90), 0x20);
        func_020307B0(pltt);
    }
    p->f25a[i] = 1;
    if (p->mode == 2) {
        p->f25a[i + 1] = 1;
    }
    func_0201ED04((struct WordSet *)font);
    func_02045808(str1);
    func_02045808(m1);
    func_02045808(m0);
    func_02045808(m2);
    func_02045808(str2);
}

#pragma opt_propagation reset

#pragma opt_common_subs reset


void func_022050F0(char *s, Out *out, const Info *p)
{
    int n;
    int k;
    int i;
    int m;
    int idx;
    void *v;
    int h;
    void *w;
    void *r;
    int ww;
    int hh;
    Res *res;
    u8 c[3];

    n = (((struct Obj01909 *)s)->f50 == 2) ? 6 : 4;
    k = (((struct Obj01909 *)s)->f50 == 2) ? 1 : 0;
    func_0201DE00(&c[2], &c[1], &c[0]);
    v = func_020457B0(12, (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    h = (int)func_0201EC64((u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    func_0201DD78(1, 2, 0);
    for (i = 0; i < n; i++) {
        if (p->e[i].show != 0) {
            w = func_02045EC0(((struct Obj01909 *)s)->f5C, p->e[i].kind + 3);
            func_0201EEF4((void *)h, 0, p->e[i].text);
            func_0201F250((struct WordSet *)h, v, w);
            func_02204C98((struct StrObj *)v, ((struct Obj01909 *)s)->f224, &ww, &hh);
            func_0201C7A4((void *)(((struct Obj01909 *)s)->f22C), d_0220A7FC[k][i][0] - ww / 2, d_0220A7FC[k][i][1], v, (void *)(((struct Obj01909 *)s)->f224));
            func_02045808(w);
        }
        (s + i)[0x25a] = p->e[i].flag;
    }
    (s + i)[0x25a] = 1;
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    func_02045808(v);
    idx = (p->b48 - 2) / 2;
    ((Bits6C *)(s + 0x6c))->x = p->b49;
    out->fc = d_0220A94C[k][idx][p->b49];
    m = 3;
    if (((struct Obj01909 *)s)->f50 != 2)
        m = 2;
    for (i = 0; i < m; i++) {
        r = func_02049F34(11, 0xd3, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        func_020215BC((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
    for (m *= 2; i < m; i++) {
        r = func_02049F34(11, 0xd4, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        func_020215BC((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
}


void func_02205340(Main *m, const int *c)
{
    int w;
    int h;

    func_0201DD78(1, 2, 0);
    func_02204C98((struct StrObj *)c[0], m->o224, &w, &h);
    func_0201C7A4((void *)m->o22c, 0x80 - w / 2, 0x10, (void *)c[0], (void *)m->o224);
    func_02204C98((struct StrObj *)c[1], m->o224, &w, &h);
    func_0201C7A4((void *)m->o22c, 0x80 - w / 2, 0x40, (void *)c[1], (void *)m->o224);
    m->b25a = 1;
    m->b25b = 1;
    func_020498F4((void *)m->f48, 0x6b, 5, 0, 0, 0, m->h240);
}
