/*
 * function: func_021B97AC
 * address: 0x021B97AC
 * packet: pkt_ov172_021B97AC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04 wD2 lane01: still 10 bytes (order of `movs r2,#2` before `str r0,[sp]` in the func_021B9E5C call). Also tried: v as u8* pointer with (u32)(vp+0x800); `3 << 14` and `v + (2 << 10)` constant spellings. No change.
 * note (2026-10-04): 520 bytes, 10 differing bytes, scheduling only. Residue: in the func_021B9E5C call (case 1) the
 *   original emits `movs r2,#2; str r0,[sp]; movs r0,#3; lsls r2; lsls r0; str r0,[sp,#4]`; mine emits
 *   `str r0,[sp]; movs r0,#3; movs r2,#2; lsls r0; lsls r2; str r0,[sp,#4]` (same instructions, order of the two
 *   constant loads differs). Tried: local for the func_021BA15C result, local for func_021BA170 + 0x800, 0x800 + v,
 *   inline call arguments. Levers that mattered: failure paths `break` (switch default becomes `bhi island`),
 *   success paths `return` (inline epilogue), entry test as `if (r == 1) return;`, and
 *   `(u8 *)func_021BA170() + (b18 << 11)` for the add operand order in case 2.
 * note 2026-10-05 wD4 lane03: still 10 bytes, same residue. Tried: constant locals (off = 0x800 for
 *   the add, off = 0xC000 for the last argument, both propagated, no change); the callee's real
 *   prototype from ov172_func_021B9E5C.c (s16 *tbl, int idx, u16 v) with (s16 *)v + 0x400,
 *   (s16 *)(v + 0x800), an s16 * local v; (u16 *)v + 0x400, (u32 *)v + 0x200; the func_021BA15C
 *   result in a local before the call. func_021BA15C is a leaf: (*p > 0x800) ? *p - 0x800 : 0.
 * note 2026-10-05 (wD9r lane44): still 10 bytes, same residue. Tried: a static inline Wave(ctx, st, base, pos)
 *   whose body adds 0x800 (10); the same inline with (pos, base) parameter order and both calls nested as its
 *   arguments, so the right-to-left inline argument order calls 170 before 15C (10, same residue). Reading of
 *   the scheduler order: the image IR has `movs r2,#2; lsls r2` before `str r0,[sp]`, ours after the 0xC000
 *   store; no inline or argument form moves the 0x800 load without also moving the add.
 * note 2026-10-05 (wD9r lane17): still 10 bytes, same residue. New tries: func_021BA15C declared returning u16
 *   (10, same), u16 return plus the callee's 5th/6th parameters u16 (10, same), callee 4th parameter u8 (10),
 *   callee unprototyped (10), callee 5th/6th u16 with u32 15C (349). Reading: in the image `movs r2,#2` has the
 *   longer path to the bl, so the image IR has the 0x800 before the stack stores; ours has it after the 0xC000.
 * note 2026-10-05 (wD9r lane31): still 10 bytes, same residue. Tried: the fifth argument as a one-field struct
 *   by value (`typedef struct { u32 v; } W;` callee parameter W, `w.v = func_021BA15C(...)` in a block local): 24
 *   (frame grows to 0x10, push r3; the constant order is unchanged). Left DIFF.
 * note 2026-10-05 (wD9r lane123): still 10 bytes, same residue. New try: a static inline
 *   Draw(ctx, st, u32 base) whose body is the whole 9E5C call (base + 0x800, 15C call inside), called as
 *   Draw(ctx, st, func_021BA170(st->f10)) so 170 is an inline argument and 15C stays in the body: 10, same.
 *   Reading of the image case 2 (func_021BA174 call): there the 0x800 register argument is built early
 *   (`movs r3,#2` right after the 170 bl, lsls later), so the scheduler does lift a register-argument
 *   constant when nothing ties it; in case 1 our DAG ranks `str r0,[sp]` above `movs r2,#2` (the WAR on r0
 *   with the 0xC000 build gives the store the longer path). The image must have the same DAG with a
 *   different tie, or the 0xC000 in another register before allocation. Not found in source.
 * note 2026-10-05 (wD9r lane141): still 10 bytes, same residue. New try: the sixth argument as an inline getter
 *   `static inline u32 Mask(void) { return 0xC000; }` (an inline call in another argument, with the 170 result
 *   in v from its own statement and 15C nested as the fifth): 10, same order. An inline call in the sixth
 *   argument does not switch the argument lowering to the whole-expression right-to-left order.
 * note 2026-10-05 (wD9r lane148): still 10 bytes, same residue. New try: func_021BA170 declared with a real
 *   pointer return `s16 *func_021BA170(u32 *)`, v an s16 * local, the call as `v + 0x400` into an s16 * third
 *   parameter (pointer arithmetic in the IR, no u32 cast): 10, same order. Checked: 15C/170 bodies (u32 leafs in
 *   ov172_func_021BA120.c) and the 9E5C prototype match the draft; no logic or width difference found.
 * note 2026-10-05 (wD9r lane159): still 10 bytes, same residue. New tries from the narrow-local idiom: the 0x800
 *   offset as a narrow u16 parameter of a static inline Wave(ctx, st, u32 base, u16 off) that holds the 9E5C
 *   call (10, same); a block-local `u16 off = 0x800` added to v at the argument (10, propagated). A narrow
 *   operand does not move the 0x800 build above the stack stores.
 * note 2026-10-05 (wD9r lane173): still 10 bytes, same residue. New try from the narrow pass-through idiom
 *   (021B9AB8 closed with a narrow stack parameter): in func_021B9E5C the fourth parameter a3 only passes through to
 *   021B9AB8's last (now u8) parameter. Narrowed a3 to u8 in a scratch copy of ov172_func_021B9E5C.c with the
 *   021B9AB8 prototype's last parameter u8: 9E5C stays EXACT (not filed, no gain here). With the 9E5C prototype
 *   here (u32, u8, u32, u32), (u32, u8, int, u16) and (short *, u8, int, u16): 10, same order. Also
 *   `v = func_021BA170(f10) + 0x800;` as a plain statement: 16 (0x800 built before the 15C call, as the inline).
 * note 2026-10-05 (wD9r lane182): still 10 bytes, same residue. Prototype now the real definition's
 *   (int, char *, s16 *tbl, u8 a3, int idx, u16 v) per the integrator, with (s16 *)(v + 0x800) and
 *   (s16 *)v + 0x400: 10, same. New tries from idioms: const u32 * on f10 and all callee prototypes taking it
 *   (const-record-pointer idiom): 10; func_021BA15C as u16 with a u16 local p5 assigned before the call
 *   (u16-accessor idiom), also 170 as u16: 10. Idioms read, no fit: scalar-halfword stack argument, live
 *   tail-call argument, inline-wrapper argument binding, inline-call per site.
 * note 2026-10-05 (wD9r lane188): still 10 bytes, same residue. New directions, no source change. Scanned every
 *   overlay and arm9 listing in asm/ for a bl followed by `movs r1..r3,#N` then `str r0,[sp,#k]` (call result stored
 *   as a stack argument after a register-argument constant): this function is the only hit in the game, so there is no
 *   matched twin. The nearest 6-argument shape (ov175 021D51BC case 2, `movs r2,#2` before `str r0,[sp]`) has r0 from a
 *   load, not a call, and its C is plain (`f(p30, 1, 2, q8[1], q2c, q12 == 2)`), so it gives no lever. Idioms read:
 *   a-const-record-pointer-moves-the-outgoing-stack-store-below-the-register-copies (const done by lane182),
 *   a-flag-argument-written-as-a-ternary-statement-keeps-left-to-right-argument-loads,
 *   an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register (pos = 15C() inside the fifth
 *   argument done by lane103). No new compile: every form they give is already in the notes above.
 * note 2026-10-05 (wD9r lane201): still 10 bytes, same residue. New tries: 9E5C declared returning int (10), result kept
 *   in a local (u32, 10), sixth parameter int instead of u16 (10). Checked: 3 is a real literal (0xC000 = `movs r0,#3;
 *   lsls r0,#0xe`, a u16 argument), so there is no variable to break the WAR chain on r0 with, and the argument roles
 *   match the 9E5C definition (ctx, st, tbl, 9, 15C result, 0xC000). Reading of the scheduler: after the bl, the ready set
 *   is {str r0,[sp]; movs r2,#2}; with the WAR edge on r0 the str has the longest path (5 against 4), so any source that
 *   leaves 0xC000 in r0 gives our order; the image needs the pre-schedule IR order `movs r2` before the str, which
 *   only a third argument lowered before the stack stores gives, and that form also moves the 170/15C call order.
 *   Idioms read: a-live-tail-call-argument-moves-the-offset-constant-to-r2 (hidden live argument: none here, r1 is
 *   the live st), a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it (no shared literal
 *   2 in this block), a-sentinel-assigned-before-the-calls-keeps-a-mask-constant-in-a-scratch-register (statement order
 *   of the 9 sentinel: already after), a-pos-accumulation (not applicable). No fit.
 * note 2026-10-05 (wD9r lane208): still 10 bytes, same residue. New tries on the sixth argument (0xC000 = movs r0,#3; lsls r0,#0xe):
 *   `(u16)-0x4000`, `(short)0xC000`, `-0x4000` (u16 parameter), `0x3 << 14`, an anonymous enum constant, a file-scope
 *   `static const u16` (propagated), a block-local `u16 m = 0xC000`: all 10, same order. The parameter as s16 with -0x4000:
 *   524 B (sign-extension added, wrong). The matched caller ov172_func_021B9044 passes its sixth argument as `w` (a
 *   variable, u16 parameter), so 0xC000 here is the only literal sixth argument seen. The fifth argument in a block
 *   local before the call: 10. The constant spelling does not change the front end's folded value.
 * note 2026-10-05 (wD9r laneS9): still 10 bytes, same residue. Start check: the draft left by the stopped lane has only the
 *   real 9E5C prototype (int, char *, s16 *, u8, int, u16) and casts; it compiles to 10 bytes, the same as the committed
 *   version, so it was kept. Image order: movs r2,#2; str r0,[sp]; movs r0,#3; lsls r2,#0xa; lsls r0,#0xe; str r0,[sp,#4].
 *   Source check: github.com/inspiredrobot/mwcc is a PowerPC (Melee) allocator reference only; it has no ARM/Thumb
 *   argument lowering or scheduler code, so it gives no lever for this order. New try: a function-scope `int sz = 0x800;`
 *   shared by the 9E5C third argument (v + sz) and the case 2 174 call (sz): propagated, 10, same order. Left DIFF.
 * symbols:
 *   func_021B9F4C 0x021B9F4C thumb ov172
 *   func_021B9DF8 0x021B9DF8 thumb ov172
 *   func_021BA0BC 0x021BA0BC thumb ov172
 *   func_021B69E0 0x021B69E0 thumb ov172
 *   func_021B9E3C 0x021B9E3C thumb ov172
 *   func_0203630C 0x0203630C arm
 *   func_021BA120 0x021BA120 thumb ov172
 *   func_021BA158 0x021BA158 thumb ov172
 *   func_021BA170 0x021BA170 thumb ov172
 *   func_021BA15C 0x021BA15C thumb ov172
 *   func_021B9E5C 0x021B9E5C thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021B8C34 0x021B8C34 thumb ov172
 *   func_021B8B74 0x021B8B74 thumb ov172
 *   func_021BA174 0x021BA174 thumb ov172
 *   func_021B891C 0x021B891C thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 * note 2026-10-05 wD5 lane07: still 10 bytes, same residue (0x800 built before the str r0,[sp] of the
 *   func_021BA15C result). Re-read: the callee's real prototype is (int, char *, s16 *tbl, int, int idx, u16 v);
 *   the IR order puts the third argument's constant before the fifth argument's stack store. Not retried:
 *   forms listed above. Untested idea: the 0x800 offset belongs to an inline helper returning the table pointer.
 * note 2026-10-05 (wD6 lane06): still 10 bytes, same residue. Tried: pos and the +0x800 sum as two locals assigned after the func_021BA15C call (`pos = 15C(); v = v + 0x800;` then the call); the 3rd argument as `(short *)((char *)func_021BA170(f10) + 0x800)` inline with the callee prototype (short *, int, int, unsigned short) as in ov172_func_021B9044.c; a static inline wrapper `DrawWave(ctx, st, v + 0x800, func_021BA15C(f10))` holding the 9 and 0xC000. None moves `movs r2,#2` above `str r0,[sp]`.
 * note 2026-10-05 (wD7 lane03): still 10 bytes, same residue. Tried: a static inline Wave(ctx, st, base, off, pos)
 *   with 0x800 passed as an inline parameter (unchanged; with the 170 call nested in the Wave call: 350 bytes);
 *   the 170 call nested in the third argument with the 15C call as the fifth (unchanged); pos assigned in its own
 *   statement before the call (unchanged). Reading: the image evaluates the third argument's constant before the
 *   stack arguments, ours evaluates the stack arguments (5, 6) first; no source form tried so far moves it.
 * note 2026-10-05 (wD8 lane06): still 10 bytes, same residue. Tried: the third argument as the address of a struct
 *   field at +0x800 (`((struct { u8 a[0x800]; u8 b[0x800]; } *)v)->b`, also `&...->c` of a word field, also with the
 *   170 call nested). All unchanged. The matched caller ov172_func_021B9044 builds its table pointer as
 *   `(short *)(f() + 0x800)` in a local before other calls; that form was already tried here.
 * note 2026-10-05 (wD9 lane15): still 10 bytes, same residue. Tried the untested wD5 idea: an inline helper
 *   `static inline u32 WaveTable(u32 *f) { return func_021BA170(f) + 0x800; }`, both nested as the third
 *   argument and assigned to v before the call: 16 bytes, the 0x800 is then built BEFORE the func_021BA15C call
 *   (in r7, kept across it). This shows the IR position of the constant decides the order: the image has it after
 *   the 15C call but before the fifth argument's stack store. Also tried: a block local `u32 half = 0x800`
 *   (propagated, 10), `3 << 14` for the last argument (10), the 15C result in pos before the call (10).
 * note 2026-10-05 (wD9r lane62): still 10 bytes, same residue. New tries: an add-only inline
 *   `static inline u32 WaveTbl(u32 v) { return v + 0x800; }` as the third argument with v and pos both
 *   assigned in statements before the call (10, same: the inline add is placed with the register arguments,
 *   after the stack stores); a file-scope `static const u32 sHalf = 0x800` for the offset (10, propagated).
 *   Reading of the diff: ours materialises 0xC000 (r0) before 0x800 (r2), the image the reverse, so the
 *   0x800 load sits ahead of both stack arguments in the image IR, not only ahead of the fifth.
 * note 2026-10-05 (wD9r lane77): still 10 bytes, same residue. New tries: the D3 constant-local lever for the
 *   offset (`pos = 15C(); h = 2;` then `v + (h << 10)`, h an int local assigned after the call): 10, h is
 *   propagated, the movs stays after the 0xC000; the table as `&blk[1]` of a `struct { u8 d[0x800]; } *`
 *   from the 170 result: 10, same. Reading: the dependence graph is the same in both, so the image's
 *   pick of `movs r2,#2` before `str r0,[sp]` comes from the IR order, which no tried source form changes.
 * note 2026-10-05 (wD9r lane89): still 10 bytes, same residue. New tries: the 170 call and the 9E5C call written
 *   in each arm of the func_021BA158 test (377, the arms are not tail merged); the real prototype widths
 *   (int fifth, u16 sixth, (int)/(u16) at the call; also int v with a short * third parameter): 10. Probes (wrong
 *   logic, not kept): sixth argument 0x40, 0xC000 + v, fourth 0x900, third a plain 0x800: in every form the
 *   15C result store `str r0,[sp]` is the first instruction after the bl, so this build always puts the
 *   stack store of a call-result argument ahead of every other argument constant. The image does not.
 * note 2026-10-05 (wD9r lane103): still 10 bytes, same residue. New tries: the callee declared varargs
 *   (10); a const block local for the 170 result (10); both results in block locals (10); a (u16) cast on the
 *   0xC000 (10); `v += 0x800` as the argument (10); an inline Pos() for the 15C call with v + 0x800, Add(v) or
 *   Id(v) + 0x800 as the third argument (10); `pos = 15C()` inside the fifth argument (10). Findings from probes
 *   (wrong logic, not kept): a register argument without a call is always lowered after the stack stores (a
 *   plain 0x800 third argument too). The image has the 0x800 between the 15C bl and the stack stores, the shape
 *   this build gives only for a third argument that CONTAINS a call when another argument has a side effect or
 *   an inline call (`(v = 170()) + 0x800`, or 170 nested with `pos = 15C()` as the fifth): then the arguments
 *   are evaluated right to left as whole expressions and the 15C call comes before the 170 call (350). So the
 *   image needs the 170 call before 15C and the third argument evaluated as a whole after 15C; no source form
 *   found gives both.
 * note 2026-10-05 (wD9r lane134): still 10 bytes, same residue. New tries: the 170 result in a reused
 *   multi-definition local instead of a fresh one (mode, pos, id; mode shares r6 in the image): 10, same.
 *   Witnesses: the three unresolved callees are real ov172 function starts (after a `bx lr` or a pool):
 *   021B69E0 (clear +4 h / +6 b of d_021C88E4), 021B8B74 (word at +0x194), 021B8C34 (word at +0x3C8).
 *   Filed EXACT as src/matched/ov/ov172_func_021B69E0.c, ov172_func_021B8B74.c, ov172_func_021B8C34.c.
 *   They resolve here once the integrator adds them to the manifest (match.py reads layout/matched).
 */
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

extern int func_021B9F4C(void *ctx, struct St *st, int mode);
extern int func_021B9DF8(void *ctx, struct St *st);
extern int func_021BA0BC(u32 *p);
extern void func_021B69E0(void);
extern void func_021B9E3C(void *ctx, struct St *st);
extern u32 func_0203630C(void);
extern int func_021BA120(u32 *p);
extern u32 func_021BA158(u32 *p);
extern u32 func_021BA170(u32 *p);
extern u32 func_021BA15C(u32 *p);
typedef short s16;
extern void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
extern u32 func_021BDFE4(void *ctx);
extern int func_021B8C34(void *ctx, u32 id);
extern int func_021B8B74(void *ctx, u32 id);
extern int func_021BA174(u32 *a, u8 *b, void *c, u32 n);
extern int func_021B891C(void *ctx, u32 id, struct Rec *r);
extern int func_021B8740(void *ctx, u32 id, u8 c, u32 d);
extern int func_021BDFEC(void *ctx);
extern u32 func_021BA244(u32 v);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *p, int v);
extern void func_02045334(void *p);

void func_021B97AC(void *ctx, struct St *st)
{
    int mode = func_021B9F4C(ctx, st, 1);
    u32 id;
    u32 pos;
    int busy;
    u32 v;

    if (func_021B9DF8(ctx, st) == 1)
        return;
    switch (st->sub) {
    case 0:
        if (func_021BA0BC(st->f10) == 1) {
            st->fa4 = 1;
            st->sub = 1;
            st->b18 = 0;
            st->f14 = 0;
            func_021B69E0();
            func_021B9E3C(ctx, st);
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
        func_021B9E5C((int)ctx, (char *)st, (s16 *)(v + 0x800), 9, func_021BA15C(st->f10), 0xC000);
    case 2:
        id = func_021BDFE4(ctx);
        if (func_021B8C34(ctx, id) != 1)
            break;
        busy = func_021B8B74(ctx, id);
        pos = func_021BA15C(st->f10);
        if (st->f14 == 0 && busy == 0) {
            if (pos >= (u32)(st->b18 + 1) << 11 || st->sub == 2) {
                int n = func_021BA174(st->f10, (u8 *)func_021BA170(st->f10) + (st->b18 << 11), st->f24, 0x800);
                st->f20->b5 = st->b18;
                st->f20->h0 = n;
                st->f20->h2 = pos;
                st->f20->b6 = st->b0d;
                st->f20->b4 = (st->sub == 2 && pos <= (u32)(st->b18 + 1) << 11) ? 1 : 0;
                st->f14 = 1;
            }
        }
        if (st->f14 == 1) {
            if (func_021B891C(ctx, id, st->f20) == 1) {
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
        if (func_021B8B74(ctx, id) != 0)
            break;
        if (func_021B8740(ctx, id, 7, 0) == 1) {
            st->sub = 4;
            func_02043B5C(func_02045770(st->f2c), 0);
            func_02045334(st->f2c);
            return;
        }
        break;
    case 4:
        if (st->f20->h2 > 0x20) {
            if (func_021BA244(func_021BDFEC(ctx)) == 1) {
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
        if (func_021BA244(func_021BDFEC(ctx)) == 0) {
            if (func_021B8740(ctx, id, 8, 0) == 1)
                st->state = 5;
        }
        break;
    }
}
