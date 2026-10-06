/*
 * function: func_0217F640
 * address:  0x0217F640
 * packet:   pkt_ov019_0217F640
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * checks: 1 own current callee witnesses confirm arities, third 02191674 arg u16 from caller truncation; 2 fresh 0217F5E0 no matching loop twin; 3 short index 336/107, u8 flag 332/99; 4 draw-pair inline and unshifted palette wrapper both 332/99; 5 fresh unfiltered idiom listing/matched neighbours, no stack aggregate in residue.
 * Final retry R14: 4 runs; old best C 332 bytes / DIFF99 retained.
 * All previously owner-blocked ov021 callees have current EXACT witnesses.
 * Renewed pass R23: 6 runs; safe best DIFF99, compiled332/original340.
 * Palette remains wide: matched callee has u16 fifth arg, but original
 * passes pal<<6 without truncation; narrow prototype/local adds shift pair.
 * No new permuter: earlier note records a consumed 300-candidate search.
 *
 * DIFF note (lane B6, 8 runs + one 300-compile permuter pass that only
 * found semantics-changing reorders). Everything through the
 * func_0219161C call matches except the frame; the loop differs only in
 * register allocation:
 *   original: push {r3-r7,lr}; sub sp,#0x20. In the loop i=r4, self=r5,
 *     pal (0x41/0x11, then <<6) = r7, i*4 spilled to sp+0x10,
 *     y=(i*2+4)*8 spilled to sp+0x1C, r6 only a temp for self->f3530.
 *   this C:   push {r4-r7,lr}; sub sp,#0x1c. y in r6, i*4 in r7,
 *     pal spilled to sp+0x10.
 * The original's allocation is the worse one (two spills, r6 unused
 * across the calls), so some source construct forces y and i*4 out of
 * registers. Tried with no change: named y/pal locals (both declaration
 * orders), pal inline in each call, if/else pal, byte-offset
 * `*(u32 *)((u8 *)t + i * 4 + 4)` indexing, and moving the pal
 * declaration to the top.
 * The prologue needs `flag = 1; if (mode != 1) flag = 0;` written before
 * the func_02191558 call (fixed; `mode == 1` inline lands after it).
 *
 * 2026-10-05 (wave P7 lane V5, 13 compiles): new form: the second call of
 * the pair reads the two fields through pointer locals (`pw = &self->f2818;
 * pt = &self->f3530;` set before the loop, used as `*pw`, `(*pt)->b[i]`),
 * the first call reads them directly. This reproduces the original's two
 * hoisted stack pointers (sp+0x18, sp+0x14) and the direct/indirect split
 * between the two calls. Still 332 B vs 340 B, DIFF 99. Residue: pal in
 * r7 with y and i*4 spilled (original) vs y in r6, i*4 in r7, pal spilled
 * (here); frame 0x20 vs 0x1c. The six per-function pragmas
 * (lifetimes, propagation, common_subs, dead_assignments, scheduling,
 * peephole) give 99, 126, 104, 99, 99, 99. int/long/u32 i and int/u32 pal
 * change nothing. Idioms read: a-scaled-record-base-pointer-spills-the-wrong-loop-value,
 * a-loop-invariant-buffer-read-through-the-field-colours-below-the-named-locals,
 * a-cast-row-argument-keeps-struct-plus-offset-as-the-loop-invariant (no fit).
 *
 * recoup 2026-10-05 (lane R8, 13 compiles): the 8 missing bytes are not a
 * statement: the original has two extra spill pairs (str/ldr of i*4 at sp+0x10
 * and y at sp+0x1c, reloaded for both calls), frame 0x20 vs 0x1c. Twin search:
 * grep -l func_02191674 src/matched/ov (only its own definition), plus
 * 02191674/0201A4D4/0219161C by address (hits: ov019 0217F5E0, ov099
 * 021BBEB4 sibling, which uses if/else flags, `flags <<= 6`, p->f1344[i+1]).
 * Tried, all DIFF 99..121: if/else pal then <<=6 (99); u16/u8 pal (112);
 * u16 y local (121); named y/off/pal in block with byte-offset reads (106),
 * three statement orders (118, 113, 99 with pal declared first); named tile
 * pointer locals per call (106); function-level declaration order y,pw,pt,off
 * (106). Finding: the first-declared of y/off/pal is the value that gets
 * spilled, but only one of them is ever spilled (the tile temp then lands in
 * r3, not r6). The original needs two spilled and r6 as the tile temp; no
 * source form tried makes the allocator spill both y and i*4.
 *
 *
 * final push 2026-10-05 G8L4 (40 compiles, 3 rounds): the loop now matches the listing except
 * register colours (340 B, 34 B off, no size or instruction difference). Loop form (as in
 * ov099 021BBEB4): `int pal; if (mask & (1 << i)) pal = 0x41; else pal = 0x11; pal <<= 6;`
 * inside the loop, calls read self->f2818 / self->f3530 directly (pw/pt locals are not needed:
 * mwcc hoists the two field addresses itself and keeps them in sp+0x18/sp+0x14).
 * Residue: original self r5, h r7, flag r6, pal r7; here self r7, h r6, flag r5, pal r5.
 * From mwcc Coloring.c: self is pushed first (lowest spill_cost/degree), so it gets r7; the
 * original has pal lowest. Any change that spills pal (ternary pal, `pal << 6` at each call,
 * u32/long/u16 pal, pal as a1 or h-as-u32, tile_pal inline, do-while) gives prologue colours
 * identical to the original but 332 B / DIFF 99 (pal spilled, y r6, off r7). With `int h`
 * shared with pal it equals this file. Also no change: i int/u32, u8 flag, int mask, pal at
 * function top (40), pal as flag (34), as msg (321), mode (39), i as mode (45), named y (121),
 * declaration order, default-then-override pal (144), six pragmas (34,168,102,34,34,34),
 * opt_lifetimes off with shared h (48). Left DIFF.
 *
 * pass 2 2026-10-06 P2L43 (40 compiles, 3 rounds): no change, still 34 B (colours only).
 * Self's colour follows how many callee-saved webs the loop keeps: base (y, off spilled,
 * pal kept) self r7; named y (y spilled, off kept) self r6; pal spilled (shared with h, or
 * function-scope u32 flags as in the ov099 021BBEB4 twin) self r5 with an EXACT prologue but
 * 332 B. The original keeps the base spill set and still has self r5. All 34 B: void* param
 * plus `Self *self = work` (also under opt_propagation off), u32 *f3530 with [i+1]/[i+7],
 * `mode = (mode == 1) ? 1 : 0`, staged call-argument locals (also under propagation off),
 * call results staged in locals, inline helpers for the loop body, the setup part and one
 * call, named tile pointer, block-scoped s, `for (long i ...)`, u8 mask, `register` self,
 * opt_propagation off with do-while, opt_strength_reduction / opt_loop_invariants /
 * opt_findoffsets off (no code change). Worse: `a1 = func_02188C54(a1)` (298), h as loop
 * counter (40), y shared with h (43), y in a call argument (126), named y and off (126),
 * `int flag = 1` at declaration (84), msg as loop counter (321).
 *
 * pass 3 2026-10-06 P3L17 (40 compiles, 3 rounds): no change, still 34 B (colours only).
 * The prologue colours follow the loop pop order: original pops i, self, tile temp, pal; here
 * i, pal, tile temp, self. Every form that adds loop pressure gives an EXACT prologue but
 * spills pal or changes the y/off code: `c = 0x41/0x11; pal = c << 6` (332/99), inner column
 * loop (324), int prototype with (u16) cast (328), h reused as pal (332/99). All 34 B: u8 mode,
 * u16 a1, u16 h with u16 callee types, ternary or if/else flag, register pal/h, two more
 * declaration orders, staged w/t call locals, named tile pointer, asserts as inline helper,
 * scheduling off, opt_lifetimes off, if/else id for the msg call. Worse: whole body as inline
 * helper (40), pal declared first (40), mode as pal (39), mode as counter (45), explicit pw/pt
 * (47), named y or one/two-word struct y (126), u8/u16 i (87), inverted mask test (37).
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_02191558  0x02191558  thumb  ov021
 *   func_0201A4D4  0x0201A4D4  thumb
 *   func_0217EE90  0x0217EE90  thumb  ov019
 *   func_0200AE3C  0x0200AE3C  thumb
 *   func_02191648  0x02191648  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0219161C  0x0219161C  thumb  ov021
 *   func_02191674  0x02191674  thumb  ov021
 *   d_021807F8     0x021807F8  data  ov019  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Tiles {
    u32 f0;
    u32 a[6];
    u32 b[6];
} Tiles;

typedef struct Self {
    u8     pad0[0x2804];
    void  *win2804;
    void  *msg2808;
    u8     pad280C[0xc];
    void  *f2818;
    u8     pad281C[0xd10];
    void  *f352C;
    Tiles *f3530;
} Self;

extern u32   func_02188C54(u32 a);
extern void  func_02034714(const char *a, u32 b, const char *c);
extern void *func_02191558(u32 h, void *msg, int a, int b, int c, int d, int e);
extern Tiles *func_0201A4D4(void *a, void *b, int c, int d);
extern void  func_0217EE90(Self *self);
extern void *func_0200AE3C(void *a, int b);
extern void  func_02191648(void *a, int b, int c, void *d);
extern void  func_02045808(void *s);
extern void  func_0219161C(void *a, int b, int c, int d);
extern void  func_02191674(void *a, int b, u16 c, u32 d, int e);
extern u32 d_021807F8[];

void func_0217F640(Self *self, u32 a1, u32 mask, int mode, int msg)
{
    u32 h = func_02188C54(a1);
    void *s;
    long i;
    int flag;

    if (self->win2804 == 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f2818 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f3530 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);

    flag = 1;
    if (mode != 1)
        flag = 0;
    self->f2818 = func_02191558(h, self->msg2808, 0, 1, 1, 0x1a, 0x10);
    self->f3530 = func_0201A4D4(self->f352C, self->win2804, 0x41, flag);
    func_0217EE90(self);

    if (msg == 0) {
        s = func_0200AE3C(self->f352C, 0x41);
        func_02191648(self->f2818, 0, 0, s);
        func_02045808(s);
    } else {
        func_0219161C(self->f2818, 0, 0, msg == 1 ? 0x14f : 0x150);
    }

    for (i = 0; i < 6; i++) {
        int pal;
        if (mask & (1 << i)) pal = 0x41; else pal = 0x11;
        pal <<= 6;
        func_02191674(self->f2818, 0, (i * 2 + 4) * 8, self->f3530->a[i], pal);
        func_02191674(self->f2818, 0x70, (i * 2 + 4) * 8, self->f3530->b[i], pal);
    }
}
