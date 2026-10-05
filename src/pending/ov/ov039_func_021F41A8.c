/*
 * function: func_021F41A8
 * address:  0x021F41A8
 * packet:   pkt_ov039_021F41A8
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     2026-10-04 wave D3 lane 04: complete draft, same size (1128 bytes); the only
 *           residue is two swapped instructions in case 5 (+01B2): the original stores
 *           s->hold = c (strb r6,[r4,#7]) right after the func_021BE674 call and then sets
 *           r1 = 1; the draft sets r1 = 1 first. Tried: the store before the call (it lands
 *           before the call), a comma expression inside the argument, a fresh u8 * local
 *           for the call result. Levers that closed other residues here: q declared before j
 *           (stack slots 8/0xc), f2 declared before k (r4/r5), u8 vol, a u8 index local in
 *           case 6, the range test written (u8)(s->sel + 0xFE) <= 3.
 *           2026-10-05 wave D4 lane 12: still the same 4 bytes. Tried: hold as u8 instead of s8
 *           (worse, recolours r4/r6 from +0x86). The store and the movs r1,#1 are independent;
 *           the original keeps source order there. Also tried a static inline helper that
 *           does the 674 call and the store and returns p (same 4 bytes).
 *           2026-10-05 wave D5 lane 13: still 4 bytes. Tried: the store as a comma
 *           expression on either argument of func_021BE6B0 (same 4), the whole call nested
 *           with the comma on the second argument (20), s->hold = j (688), u8/u32/short as
 *           the func_021BE6B0 second parameter (same 4).
 *           2026-10-05 wave D6 lane 15: still 4 bytes. Tried: volatile s8 hold (same 4),
 *           the 1 held in a local n set after the store (same 4), c as u32 (same 4), c as u8 (882),
 *           c as s8 (1024). The scheduler always puts movs r1,#1 above the strb.
 *           2026-10-05 wave D7 lane 13: still 4 bytes. Tried: n = 1 set before the
 *           func_021BE674 call and passed as the argument (same 4), the store through a raw
 *           `*(s8 *)((u8 *)s + 7) = c` (same 4), the whole case-5 pair as one nested call with
 *           the comma on the second argument and p assigned in the first (20). Callee heads
 *           read no extra argument registers. The residue is only the order of two independent
 *           instructions after the bl; no source shape tried so far moves it.
 *           2026-10-05 wave D8 lane 02: still 4 bytes. Checked: no branch targets the movs r1,#1
 *           at +01B4 (021F435C), so the strb and the movs are in one scheduled block; the residue
 *           is the scheduler tie-break only. Tried: func_021BE6B0 unprototyped (K&R call), same 4.
 *           2026-10-05 wave D9 lane 15: still 4 bytes. Tried: s->hold = s->sel >> 1 (689, the shift is not
 *           CSE'd with c), s->hold = j (688). No source form tried so far moves the strb above the movs.
 *
 *           2026-10-05 wave D9r lane 17: still 4 bytes. Fresh reading: both the strb and the movs r1,#1 feed
 *           only the bl, so a list scheduler with equal heights keeps IR order; ours must see the 1 before the
 *           store. Tried: sel/hold as u32 bitfields (sel:8, pad:16, signed hold:8) to change the store node:
 *           1092 (read-modify-write stores). No new source form found; left DIFF.
 *           2026-10-05 wave D9r lane 31: still 4 bytes. Tried: a static inline Pick(s, p, c) that does
 *           `s->hold = c; func_021BE6B0(p, 1);` (c as int and as s8 parameter): same 4, movs r1,#1 still above
 *           the strb. Left DIFF.
 *           2026-10-05 wave D9r lane 37: still 4 bytes. Tried: the store as `((u8 *)s)[7] = c` (the
 *           matched caller ov039 021F404C writes s[7] = c on a u8 pointer): same 4; a label (and a goto to
 *           it) between the store and the call, to test a block split: same 4 (mwcc merges the blocks).
 *           Searched matched code for a twin with the same case-5 sequence (as ov177 021E5A30 closed from
 *           its ov068 twin): ov039 021F4610 and 021F3A34 are siblings, but neither has this pair. Left DIFF.
 *           2026-10-05 wave D9r lane 60: still 4 bytes. Reduced the residue to a 10-line test function
 *           (call; s->hold = c; leaf(p, 1)): mwcc puts the argument setup above an independent register
 *           strb in every form tried: a literal, a register argument, an enum or s8 or const callee
 *           parameter, a function-pointer call, p typed u8 *, the callee returning u64, a pointer local
 *           to the field, the store to a global. A computed value (c + 1) puts the store first only
 *           because r1 is the temp. Full-function tries: a separate local for the 021A3074 result (same
 *           4), k = s->sel + 1 assigned in case 5 and passed (same 4), the store before a nested
 *           leaf(674(...), 1) (20). No real source form found; left DIFF.
 *           2026-10-05 wave D9r lane 91: still 4 bytes. Checked callee prototypes against the matched
 *           definitions: func_021BE674 and func_021BE6B0 agree with ov021 (void *, void). func_021F3DE4 is
 *           really (void *, u8, u16); with that prototype the call site needs (u8)(s->sel + 1) (the
 *           original truncates to 8 bits), now used here; same 4 bytes. func_021BE4C4 returning int:
 *           same 4. New reading: mwcc never moves an independent store above the argument setup when
 *           the store and the call are in one block (micro tests: __restrict s, stack object, global,
 *           (u8)/(s8)/& 0xFF value, int-returning callee: all movs first). A game-wide scan found
 *           store-before-argument only with a register dependence (ov091 021B62A2 base r1, ov021
 *           021AD040 adds r1,r0) or when the call sits in a cross-jumped join block (matched ov135
 *           021F9FF0: m->cur = r; f(m->cursor, 6) in an else arm). Case 5 has no branch into
 *           +01B4/+01B6, so the original block structure here is still unexplained. Left DIFF.
 *           2026-10-05 wave D9r lane 117: still 4 bytes. Micro tests (real compiles) of block shapes
 *           that could split the strb and the movs into two scheduling blocks without a visible branch:
 *           do { } while (0), for (;;) { break; }, switch (1), switch with only default, if (c >= 0),
 *           if (c == x) and if (c != x) return with c = x (late folding), a goto from dead code after a
 *           return, a one-trip for loop, an inline helper returning p used nested as the argument, an
 *           inline helper with an early return (adds a cmp), an inline that only stores. All give movs
 *           first: mwcc folds them before scheduling. Only a REAL join reorders: a case label that
 *           falls through (switch case 1: ...; s->hold = c; case 2: f(p, 1)) gives strb, movs. Full
 *           function with a goto from case 7 to a label before func_021BE6B0(p, 1) (fake path, p = o)
 *           gives the target strb r6 / movs r1,#1 at +01B2 but adds 16 bytes (792 differ). The original
 *           has no branch or jump table entry at 021F435C/435E (all branch targets checked), so the join
 *           predecessor, if any, is gone from the final code. No real source form found; left DIFF.
 *           2026-10-05 wave D9r lane 132: still 4 bytes. Checked every possible second path into a join at
 *           +01B4: the case table has 10 distinct entries (none at 021F435C/435E), no branch targets them,
 *           and the block before +01B4 is case 5's own head, so no case label, goto or fall-through can
 *           reach it. A path removed after scheduling would need its own trace (a table entry or a branch)
 *           to vanish too; cross-jumping only redirects such a path to 021F4348, which only the case 5
 *           entry reaches. mwcc also keeps source block order (case 5 head moved after case 9 with a goto
 *           back to the tail: no reordering, 697 differ). Tried: an inline helper whose body starts with
 *           func_021BE6B0(p, 1) (same 4); the argument written as c == j, s->hold == c, s->hold >= 0 to
 *           fold late (all fold early into a 1 held across the function, 1148 bytes); func_021BE6B0
 *           declared variadic (same 4). Left DIFF.
 *           2026-10-05 wave D9r lane 145: still 4 bytes. Rechecked every block against the listing: all other
 *           bytes match, so no logic or type error is visible elsewhere. Full-function tries: c as u16 and as
 *           short (same 4). Micro tests (real compiles) show why one block can not give strb first: the
 *           scheduler sinks an independent store to the last slot before the next call, even below a second
 *           store that precedes it in source (s->hold = c; s->sel = 5; f(p, 1) gives the sel store, movs r1,
 *           the hold store, bl), and it sinks an independent multiply below a call. Only a dependence (a temp
 *           in r1, an anti-dependence on a reused register) or a block boundary keeps the store first. No
 *           real form made a boundary: identical if/else arms around the call or the store (collapsed),
 *           for (;;) / while (1) / do-while (0) / switch default bodies with break (folded), an unused label,
 *           an empty inline call, an inline with return. A dependence through a value folded late also
 *           failed: static const int / const local fold early (movs first); a static const u8 table or a
 *           static int stays a load (ldr, extra bytes); c == (u8)c, c < 0x100, c >= 0, s->hold == c stay
 *           real compares with a 0/1 register. Left DIFF.
 *           2026-10-05 wave D9r lane 168: still 4 bytes. Read the callee definitions: ov021 func_021BE6B0 is
 *           `p[0] = v` (u8 *, int) and func_021BE674 returns void * (char *, int, unsigned, int), both as declared.
 *           Micro tests (real compiles), all give movs r1 first: an empty if with the store in its condition
 *           (`if (s->hold = c) {}`, `!= 0`), an empty if/else after the store, `while ((s->hold = c), 0)`, the
 *           store guarded by a switch-value test inside its own case (`if (st == 5)`, kept as a real cmp/bne)
 *           or by `c == c` (folded), the second argument from a live register (c or a parameter: the `adds r1`
 *           copy still goes above the strb), the constant 1 used five more times in the block
 *           (no callee-saved constant, each use rematerialised), a store to another field (str sinks the same
 *           way), and hold as a char bitfield (`s8 hold:8`, u8 container: read-modify-write in r1, which puts
 *           the strb first by anti-dependence but adds 7 instructions). No live register holds 1 at +01B2
 *           (r4 = s, r5 = a1, r6 = c, r7 = 0x6DB). Left DIFF.
 *           2026-10-05 wave D9r lane 177: still 4 bytes. Re-derived case 5 from the listing: it is entered only
 *           by its table entry (021F4348), the head (args for 674, bl, strb, movs r1,#1, bl 6b0) is one straight
 *           line with the same head shape as cases 3 and 9, and r6 (c) dies at the strb (r6 is reused for p at
 *           +0240), so no other case, join or live register explains the order. The micro-test pattern of lane 145
 *           (a source-earlier store is placed last, after the movs) shows the scheduler is bottom-up with the
 *           store picked first from the bottom; the original needs the movs picked first. The only matched join
 *           form with a store ahead of the argument setup (ov135 021F9FF0, store in one arm, call after the join)
 *           needs a real conditional here, which the original lacks. Compared with matched ov039/ov135 code: no
 *           twin has this pair. No new compile beyond the listed ones changed the 4 bytes. Left DIFF.
 *           2026-10-05 wave D9r lane 179: still 4 bytes. Idiom research first (store sinks, store between arg
 *           setup and call, call-in-each-arm, list-scheduler tie, local at first use). New real compiles: the
 *           pair in a block-local `void *p2` (same 4), `s->hold = (s8)c` (same 4), the second argument written
 *           `(s->hold == c)` (1148 bytes), the store as a comma inside the first argument of f6b0 (20). Left DIFF.
 *           2026-10-05 wave D9r lane 185: still 4 bytes. Idioms read (new ones): a-store-between-arg-setup-and-the-call-
 *           names-the-second-argument, a-returned-pointer-copied-to-r1-before-byte-stores-is-a-later-call-argument,
 *           a-dead-store-between-a-temp-and-its-use-blocks-copy-propagation, compute-a-stores-operands-before-the-store,
 *           signed-and-unsigned-byte-fields-do-not-share-a-truncation, a-load-scheduled-above-an-unrelated-store-reads-
 *           through-a-const-pointer: none applies (the stored value r6 is not r0 and nothing is a second argument).
 *           Corpus scan of every raw and text overlay and arm9 listing for `bl; strb; movs r1,#1; bl` (and strb then
 *           movs r1,#imm then bl): only this site. Nearest twin is ov093 021E4F18 (matched ov093_func_021E4EC4: p = f(s,15,k);
 *           p[4] = k; g(b,1)): there the store comes first, but r0 for the call is a reload (ldr r0,[sp,#4]) and the store base
 *           is a copy of the call result, so it is not the same block. New compiles: func_021BE6B0 second parameter as s8 and
 *           as _Bool: same 1128 bytes, same 4 differ. Left DIFF.
 *           2026-10-05 wave D9r lane 190: still 4 bytes. Studied the ov093 021E4EC4 twin with real compiles of the
 *           twin itself: its `p[4] = k; p[5] = g(b, 1);` puts strb before movs r1,#1 only because the call
 *           result is stored right after the call (discarded result, `g(); p[5] = 0`, `p[5] = g() + 1`: movs first;
 *           store through another base, or the result via a local that is stored: strb first). New idiom file
 *           docs/idioms/a-store-stays-above-the-argument-constant-only-when-the-call-result-is-stored.md.
 *           Case 5 passes f6b0 (void, r0 = p straight from the 674 call) with no store of its result, so this
 *           does not apply. Tried in the full function: f6b0 returning int with the result in a dead local n
 *           (movs first), the 674 result bound to a u8 * local pp (same 4), micro twin shapes with
 *           `p[4] = c; p[5] = fB(b, 1)` and `s->hold = c; s->sel = fB(p, 1)` (movs first, no spill reload).
 *           Left DIFF.
 *           2026-10-05 wave D9r lane 200: still 4 bytes. Checked the neighbours: cases 3 and 9 do not have
 *           this pair. Their listings (021F42C6, 021F43AA area) call 674 then 6b0(.,0) with no store between,
 *           and their hold store (`s->hold = -1`) comes later, after the timer and slot stores, so there is
 *           no matched twin to diff against. Callee check: the bl at +01B6 really calls func_021BE6B0
 *           (ov021 021BE6B0 = `strb r1,[r0]; bx lr`, 4 bytes, an out-of-line leaf, not an inlined
 *           p[0] = 1), so there is no second call hidden behind it. r0 is the 674 result untouched
 *           through the strb. Read the idiom a-store-stays-above-the-argument-constant-only-when-the-call-
 *           result-is-stored and an-instruction-the-scheduler-will-not-hoist-sits-after-a-cross-jumped-join:
 *           neither applies (void callee, no join). No new compile changed the 4 bytes. Left DIFF.
 *           2026-10-05 wave D9r lane 203: still 4 bytes. Idioms read: a-ternary-flag-is-materialised-first-a-relational-
 *           one-is-folded-into-the-call, an-inline-call-argument-is-scheduled-per-site-a-local-is-not, struct-field-stores-
 *           keep-source-order-raw-offsets-do-not, a-pool-word-order-residue-is-a-list-scheduler-tie, a-one-initialised-
 *           return-flag-preserves-one-in-the-upper-saved-register: none applies. Register-liveness hypothesis (c dies at the
 *           strb, so the scheduler defers the store) tested the other way: c made live after the strb (used in the
 *           func_020061E4 argument, then as s->timer[c] = 0): order unchanged, movs first; liveness of r6 does not
 *           steer the pair. New compiles (all same 4 bytes unless noted): the store through a different typed pointer
 *           (struct { u8 pad[7]; s8 hold; } cast, direct and as a block-local pointer); hold declared char; func_021BE6B0
 *           first parameter s8 * / Work *; second parameter u8 with (u8)1; a block-local c recomputed in case 5
 *           (1136 bytes, 689 differ); the store through a second func_021897BC(sys, 1) result (1144, 643); second
 *           argument c >= 0 (1144, 1027). Matched-C scan for `p = f(..); store; g(p, const)` (31 hits over src/matched):
 *           no site has a store between the two calls with a register-sourced value and a constant second argument
 *           (ov093 021E05B0 / 021E0850 store a constant into the result and pass it on; ov021 021C1318 `k = 1;
 *           g(o, 1)` has no store). Left DIFF.
 *           2026-10-05 wave D9r lane 211: still 4 bytes. Whole-function comparison: every other store in the
 *           original that precedes argument setup has a register dependence (case 0 `str r0,[r4,#0x18]; ldr r0,..`
 *           stores the call result in r0; case 3 `strb r0,[r4,#7]; adds r1,r7,#0; ... ldr r0` reuses r0), and our
 *           output matches all of them. Case 5 is the only store with no dependence. Tried with c assigned
 *           between the 674 call and the store: `c = j; s->hold = c;` (1132 bytes), `s->hold = j` (1132),
 *           and the store after f6b0 (15 differ). Idioms re-read: none new. Left DIFF.
 *           2026-10-05 wave D9r lane S4 (final pass): still 4 bytes, code unchanged from HEAD (a stopped lane had only
 *           added notes). Read inspiredrobot/mwcc docs/SCHEDULER.md and Scheduler.c: the repo models only the GC
 *           PowerPC scheduler (forward list scheduler, calls are barrier nodes with edges to and from every other
 *           node, pick scans textually and a later node wins only by strict urgency, release count, height, then
 *           descriptor byte; stores add wildcard memory edges only to other pointer-based memory ops). It has no ARM
 *           model, so the store-versus-li latency and descriptor rows of dsi/1.1p1 are unknown. Transferable result:
 *           within one barrier-free run the strb and movs r1 are independent siblings of the bl, so the order is set
 *           by height or descriptor rank, never by source order, which agrees with lanes 145 and 177. Only a successor
 *           that becomes ready when the strb issues (release count) could raise it, and no such node exists before the
 *           bl in case 5. New real compile: the store as a comma in the second argument,
 *           func_021BE6B0(p, (s->hold = c, 1)): same 4 bytes. Left DIFF.
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02006148 0x02006148 thumb
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_021BE4C4 0x021BE4C4 thumb ov021
 *   func_021BE748 0x021BE748 thumb ov021
 *   func_021F3E04 0x021F3E04 thumb ov039
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 *   func_021F48C0 0x021F48C0 thumb ov039
 *   func_02011428 0x02011428 thumb
 *   func_02011558 0x02011558 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_02006138 0x02006138 thumb
 *   func_02006210 0x02006210 thumb
 *   func_02028A7C 0x02028A7C thumb
 *   func_02028B18 0x02028B18 thumb
 *   func_02028B50 0x02028B50 thumb
 *   func_02072F34 0x02072F34 arm
 *   func_0203630C 0x0203630C arm
 *   func_02047790 0x02047790 arm
 *   func_02047674 0x02047674 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_02158780 0x02158780 thumb ov010
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_021A3044 0x021A3044 thumb ov021
 *   func_0216DAC8 0x0216DAC8 thumb
 *   func_0216D5E0 0x0216D5E0 thumb
 *   d_021F4C38    0x021F4C38 data a4
 *   d_021F4C58    0x021F4C58 data ov039 a4
 *   d_021F4CF4    0x021F4CF4 data ov039 a4
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u16 x;
    u16 z;
} Cell;

typedef struct {
    u8 pad0[4];
    u8 sel;
    u8 pad5[2];
    s8 hold;
    int timer[4];
    u32 anim;
    u8 f1c[0x21E4 - 0x1C];
    int active;
    u8 req[4];
    u8 cur[4];
    s8 slot[4];
} Work;

typedef struct {
    u8 pad0[8];
    u8 *mdl;
} Res;

struct Ctx;
struct Obj;
struct Big;
struct BigObj;
struct IcaAnime;
struct SoundSys2;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern Work *func_021897BC(void *p, int idx);
extern u32 func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_0200B3A4(unsigned int, unsigned int);
extern u32 func_02012A30(const struct BigObj *a);
extern int func_02006148(u32 a);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);
extern void *func_021BE4C4(void *p, u32 i, int delta);
extern int func_021BE748(void *p);
extern void func_021F3E04(void *p, u8 delta, u16 i, int frame);
extern int func_021F3DE4(void *p, u8 delta, u16 i);
extern void func_021F48C0(u8 *a, int idx, int x, Vec *out);
extern u32 func_02011428(u32 heap, u32 a1, u16 a2, void *a3, u32 a4);
extern void func_02011558(struct IcaAnime *p);
extern void func_020061E4(u32 a);
extern void func_020061F8(int i);
extern u32 *func_02006138(int i);
extern void func_02006210(void);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern void func_02028B18(struct SoundSys2 *s, u32 id, u32 who);
extern void func_02028B50(u8 *p, int a0);
extern void func_02072F34(void *o, u8 v);
extern unsigned int func_0203630C(void);
extern void *func_02047790(void *h, u16 i);
extern Res *func_02047674(void *p);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *a);
extern int func_02158780(void *p, int b, int c, int d, u16 e);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_021A3044(void *q, Vec *v);
extern void func_0216DAC8(void *o, u32 v);
extern void func_0216D5E0(void *o, u32 v);

extern u32 d_021F4C38[];
extern Cell d_021F4C58[];
extern Vec d_021F4CF4;

int func_021F41A8(void *a0, int *a1)
{
    void *sys;
    int h;
    Work *s;
    u32 w;
    int snd;
    int c;
    void *q;
    u8 j;
    void *o;
    void *p;
    void *m;
    Res *r;
    int f2;
    u8 k;
    int f;
    int n;
    int d;
    u8 vol;
    Vec t;
    Vec a;
    Vec b;
    Vec e;

    sys = func_0201210C(func_020124E4(a0));
    h = func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    w = func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)func_02188C80(sys)));
    snd = func_02006148(0x6DB);
    c = (u8)(s->sel >> 1);
    j = c;
    o = func_021BE674((char *)h, 0, j, 0);
    func_0200B3A4((unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)func_02188C80(sys))), 2);
    switch (*a1) {
    case 0:
        s->anim = func_02011428(0x8015, 0x6b, d_021F4C38[s->sel], s->f1c, 0x21C0);
        func_021F3E04((void *)h, j, 0, 0);
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021F3DE4((void *)h, j, 0) < 0xF000) {
            break;
        }
        func_021BE6B0(o, 1);
        func_02158780(a0, 0xD, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 2:
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 3:
        if (func_021BE6BC(o) == 0) {
            break;
        }
        func_0216DAC8(func_021A3074(func_02188CB4(sys)), 1);
        func_021BE6B0(o, 1);
        func_021BE6B0(func_021BE674((char *)h, 0, j, (u8)(s->sel + 1)), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        s->hold = -1;
        func_02028A7C((struct SoundSys2 *)w, 0x68A);
        func_020061E4(0x6DB);
        func_02072F34(func_02006138(snd), 0);
        func_02028B18((struct SoundSys2 *)w, 0x68A, 0x7f);
        s->active = 1;
        *a1 = *a1 + 1;
        break;
    case 4:
        if (s->slot[c] == -1) {
            break;
        }
        if (func_0203630C() & 0x80) {
            *a1 = *a1 + 1;
        }
        break;
    case 5:
        p = func_021BE674((char *)h, 0, j, (u8)(s->sel + 1));
        s->hold = c;
        func_021BE6B0(p, 1);
        func_021F3E04((void *)h, j, 0, 0);
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        p = func_021A3074(func_02188CB4(sys));
        func_0216D5E0(p, 1);
        func_0216DAC8(p, 0);
        *a1 = *a1 + 1;
        break;
    case 6:
        if (func_021F3DE4((void *)h, j, 0) < 0xF000) {
            break;
        }
        func_021BE6B0(o, 1);
        m = func_02188CB4(sys);
        t = d_021F4CF4;
        k = s->slot[c];
        t.x = (d_021F4C58[k].x << 16) + 0x8000;
        t.z = ((d_021F4C58[k].z - 2) << 16) + 0x8000;
        func_021A3044(m, &t);
        s->active = 0;
        *a1 = *a1 + 1;
        break;
    case 7:
        func_02158780(a0, 0xE, 0, 0, 0x8015);
        *a1 = *a1 + 1;
        break;
    case 8:
        func_021BE6B0(o, 0);
        func_020061E4(0x687);
        *a1 = *a1 + 1;
        break;
    case 9:
        if (func_021BE6BC(o) == 0) {
            break;
        }
        func_021BE6B0(o, 1);
        func_021BE6B0(func_021BE674((char *)h, 0, j, (u8)(s->sel + 1)), 0);
        s->timer[c] = 0;
        s->slot[c] = -1;
        func_02011558((struct IcaAnime *)s->anim);
        s->hold = -1;
        s->sel = 0xff;
        func_02028A7C((struct SoundSys2 *)w, 0x68A);
        func_02028B18((struct SoundSys2 *)w, 0x68A, 0);
        func_020061F8(snd);
        return 1;
    }
    if ((u8)(s->sel + 0xFE) <= 3) {
        f = func_021F3DE4((void *)h, j, (u8)(s->sel + 1));
        switch (s->sel) {
        case 2:
            if (f == 0xBF000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x68B);
            } else if (f == 0xEB000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
            } else if (f == 0xFF000) {
                func_020061E4(0x68C);
            }
            break;
        case 3:
            if (f == 0x108000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x68B);
            } else if (f == 0x131000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
            } else if (f == 0x148000) {
                func_020061E4(0x68C);
            }
            break;
        case 4:
            if (f == 0xB1000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x6D2);
            }
            break;
        case 5:
            if (f == 0xB6000) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
                func_020061E4(0x6D2);
            }
            break;
        }
    }
    q = func_021BE4C4((void *)h, 0, j);
    k = s->sel + 1;
    n = func_021BE748(func_021BE674((char *)h, 0, j, k));
    f = func_021F3DE4((void *)h, j, k);
    f2 = f + 0x1000;
    if (f2 >= n) {
        f2 = 0;
    }
    r = func_02047674(func_02047790(q, k));
    vol = 0;
    func_021F48C0(r->mdl, 0, f, &a);
    func_021F48C0(r->mdl, 0, f2, &b);
    func_0207CA00(&a, &b, &e);
    d = func_0207CBD0(&e);
    if (d >= 0x20000) {
        vol = 0x7f;
    } else if (d >= 0x18000) {
        vol = 0x5a;
    } else if (d >= 0x10000) {
        vol = 0x3c;
    } else if (d >= 0x8000) {
        vol = 0x1e;
    }
    func_02072F34(func_02006138(snd), vol);
    return 0;
}
