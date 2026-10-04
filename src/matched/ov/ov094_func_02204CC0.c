/*
 * function: func_02204CC0
 * address:  0x02204CC0
 * packet:   pkt_ov094_02204CC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 * symbols:
 *   d_0220A5B0  0x0220A5B0  data
 *   d_0220A5D0  0x0220A5D0  data
 *   d_0220A5F0  0x0220A5F0  data
 *   d_0220A392  0x0220A392  data
 *   d_0220A3C4  0x0220A3C4  data
 *   d_0220A4AC  0x0220A4AC  data
 *   func_02204C98  0x02204C98  thumb  ov094
 *   func_02205768  0x02205768  thumb  ov094
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct Pos { int x, y; } Pos;
typedef struct PosTab { Pos v[4]; } PosTab;
typedef struct { int w[9]; } Struct36;
typedef struct Slots {
    u16 id[4];
    u8 a[4];
    u8 b[4];
} Slots;

extern const PosTab d_0220A5B0;
extern const PosTab d_0220A5D0;
extern const int d_0220A5F0[];
extern const u16 d_0220A392[];
extern const Point d_0220A3C4[];
extern const Pos d_0220A4AC[];

struct Bank;
struct MsgBank;
struct Obj;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_0201EC64(int);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern u32 func_0201BD28(u16 id, u32 field);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B404(void *, const Point *, int);
extern u32 func_020275E4(void);
extern u32 func_020275F8(u8);
extern u8 func_020275EC(u8 i);
extern void *func_02049E34(u32 arc, u32 file, u32 comp, void **out, u16 heap);
extern void *func_02049F34(u32 arc, u32 file, void **out, u16 heap);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B7C8(void *, Struct36 *);
extern void func_02082A60(const void *, void *, int);
extern void func_020307B0(void *);
extern void func_0201DE00(u8 *, u8 *, u8 *);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201EF34(int, int, int);
extern void func_0201EFA4(int, int, int, int, int, int);
extern void func_0201F250(int, void *, void *);
extern void func_02204C98(void *a, void *b, int *w, int *h);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern int func_02205768(int a, int b);
extern void func_020215BC(void *, void *, int, u16, u16);
extern void func_0201ED04(int);
extern void func_02045808(struct U16Vec *vec);

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


#pragma opt_common_subs off
#pragma opt_propagation off
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
    font = func_0201EC64(p->heap);
    str2 = func_020457B0(0x10, p->heap);
    m2 = func_02045EC0(p->msgdata, 2);
    func_0204B22C(p->sys, 0);
    for (i = 0; (i < 4) ? 1 : 0; i++) {
        if (q->id[i] != 0) {
            k = func_0201BD28(q->id[i], 0);
            file = d_0220A5F0[k];
            p->obj[i] = func_0204B294(p->sys, p->res[i], p->r1f0, p->r1f4, d_0220A392, 1, p->heap);
            func_0204B404(p->obj[i], &d_0220A3C4[i], 1);
            heap = (p->heap & 0x7fff) | 0x8000;
            arc = func_020275E4();
            chr = func_02049E34(arc, func_020275F8(k), 0, &cd, heap);
            func_0204B6F4(p->obj[i], func_020275EC(k), 1);
            func_0204B7C8(p->obj[i], &buf);
            vram = VRAM_BASE;
            func_02082A60(*(void **)((char *)cd + 0x14), (void *)(vram + buf.w[2]), 0x100);
            func_020307B0(chr);
            func_0201DE00(&c[2], &c[1], &c[0]);
            func_0201DD78(1, 2, 0);
            func_0201EF34(font, 0, q->id[i]);
            func_0201F250(font, str1, m0);
            func_02204C98(str1, p->fnt, &w, &h);
            func_0201C7A4(p->win, d_0220A4AC[i].x - w / 2, d_0220A4AC[i].y, str1, p->fnt);
            func_0201EFA4(font, 0, q->a[i], 2, 1, 1);
            func_0201EFA4(font, 1, q->b[i], 2, 1, 1);
            func_0201F250(font, str2, m2);
            col = func_02205768(q->a[i], q->b[i]);
            cb = (u8)(col & 0x1f);
            cg = (u8)((col >> 5) & 0x1f);
            cr = (u8)((col >> 10) & 0x1f);
            func_0201DD78(cr, cg, cb);
            func_0201C7A4(p->win, t1.v[i].x, t1.v[i].y, m1, p->fnt);
            func_02204C98(str2, p->fnt, &w, &h);
            func_0201C7A4(p->win, t2.v[i].x - w / 2, t2.v[i].y, str2, p->fnt);
            func_0201DD78(c[2], c[1], c[0]);
            p->f25a[i] = q->a[i] != 0;
            p->f262[i] = q->id[i] != 0;
        } else {
            file = 0xc1;
        }
        heap = (p->heap & 0x7fff) | 0x8000;
        pltt = func_02049F34(0xb, file, &pd, heap);
        func_020215BC(p->bg, *(void **)((char *)pd + 0xc), 1, i * 16 + 0x90, 0x20);
        func_020307B0(pltt);
    }
    p->f25a[i] = 1;
    if (p->mode == 2) {
        p->f25a[i + 1] = 1;
    }
    func_0201ED04(font);
    func_02045808(str1);
    func_02045808(m1);
    func_02045808(m0);
    func_02045808(m2);
    func_02045808(str2);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
