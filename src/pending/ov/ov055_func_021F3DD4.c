/*
 * function: func_021F3DD4
 * address:  0x021F3DD4
 * packet:   pkt_ov055_021F3DD4
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD9r lane89): still DIFF 26 bytes (p/a swap). New tries: int t0 and a with the u32 prototypes (27);
 *   the final stores as ((u16 *)p)[10] / [11] (26); a third local d for the first-part result with a = d before
 *   the rect test, and with `else a = d` in each arm (26, both). Probes (stand-ins, not kept): `p = p;` at entry,
 *   after the first call, before the 41E8 sum, before the D410 call and at the end, and `a = a;` at the end: all
 *   26, so no definition point of p or a moves the colour order here.
 * 2026-10-05 (wD9r lane77): still DIFF 26 bytes (p/a swap). New tries: `register` on the p parameter (26);
 *   `register` on a (26); the bound test operands swapped (`p[3] == t0 || func_021642A4(t0) == p[3]`, 26, same
 *   code). The ov055 callers (021F4174, 021F41F0) pass (a, loc) with loc from func_021F42AC, so x is an
 *   object pointer as lane44 read; no twin of this routine exists in src/matched.
 * 2026-10-05 (wD9r lane62): still DIFF 26 bytes (p/a swap, the only diff). New tries: C99 declarations at
 *   first use with initialisers (t0, xx, y0 initialised from their calls, a/yy/r declared after them): 26,
 *   same; `a == 0 || a == 1` for the bound test (26, compiles identically); `a < 2` (28). Model test: with
 *   func_0216D5F8(0) instead of (x) the swap stays, so the x parameter web plays no part in it.
 * 2026-10-05 (wD9r lane44): still DIFF 26 bytes (p/a swap). Read: func_0216D5F8 is `ldrh r0,[r0,#0x18]`
 *   (x is an object pointer; t0/a is a direction), 41E8/41F8 are dx/dy tables, 42A4 the reverse direction.
 *   Tried: one variable a for t0 and a with `a = (u16)(a + 2)` in each rand arm (26, same; with the +2
 *   hoisted above the rand test: 168 B, layout breaks); D410 and both stores written in each out-of-range
 *   arm with return (226 B, tails not merged, swap stays); parameter x reused as a (178 B, x homed r4);
 *   x reused as xx or y0 (178 B, x copied to a callee-saved register at entry). Every form keeps p r5.
 * 2026-10-05 (wD9r lane34): still DIFF 26 bytes (p/a swap). Tried (all 26): p as a real struct
 *   pointer (fields b3, ha, obj, rect, active, cur); x as a u16 parameter; the matched prototypes
 *   (u16 func_0216D5F8(void *), u16 func_021642A4(u16), 021641E8/F8(u16), 0216D410(void *, u16)) with
 *   u16 t0/a (u32/int locals give 184 B); the final call and two stores as a static inline SetCur(p, a);
 *   p as a local copy of an int or void * parameter, assigned before or after the first call. Reading:
 *   the ov021 sibling 0219A8C0 gives the call result r4 and the parameters r5/r6 (reverse order), the
 *   same rule as this build; the image gives p r4, so p behaves like the first-defined local there.
 * 2026-10-05 (wD9r lane07): still DIFF 26 bytes (p/a swap). Tried: s16 nx/ny as new locals for the
 *   41E8/41F8 sums (26, same); the a <= 1 test as switch (a) {case 0: case 1: ... default:} (182 B, worse);
 *   int return with `return 1` (r0 = 1 at the exit in the image; 26, same); 0x14/0x16 as one struct copy
 *   (186 B, worse). Model tests (one call, then D410 and the two stores): p/a swap is present in every
 *   reduced form (no first part, no rect test, no xx/y0); in the reduced model only a LAST use of p after
 *   the last use of a (store a first, then 0x14 = 1) gives p r4, but in the full function that order is
 *   inert (still 26) and emits the stores in the wrong order.
 * 2026-10-05 (wD9 lane07): still DIFF 26 bytes (p/a swap). Tried: xx, yy, y0 as s16 with func_0216D83C/86C
 *   returning s16 (same 26); the rect test as a static inline Outside() returning 0/1 with one
 *   `if (Outside(..)) a = func_021642A4(a)` (77, the bool is not folded, swap stays).
 * 2026-10-05 (wD7 lane14): still DIFF 26 bytes. Tried: the second part (from the 021641E8 call to the end) as a static inline
 *   Fin(p, a, xx, y0) (same 26, p/a swap stays). Same residue shape as ov020 02186470 (parameter copied first gets r5, first
 *   long-lived call result gets r4).
 * 2026-10-05 (wave D6 lane 19): still DIFF, 26 bytes, p/a swap. Callee listings checked
 *   (rule 1): all six ov010 callees read r0 only, no hidden argument. Tried: the first part as a
 *   static inline returning a (same 26); the a <= 1 bound test as one ternary condition (worse, 188
 *   bytes); `goto out` with the tail written in both paths (79, swap stays); x reused as t0/a (167).
 * note (2026-10-05, wD5 lane01): now 26 bytes: r is loaded inside each arm of the a <= 1 test
 *   (the compiler hoists both loads to just after the cmp, as in the image). Residue: p/a colour
 *   swap only (image p r4, a r5; ours p r5, a r4). Tried, all inert: store order 0x16/0x14, u16
 *   returns for func_0216D5F8/func_021642A4 with u16 t0 and a, x0/xx and y0/yy split or merged,
 *   r as inline expression or two locals, declaration order of all locals (two orders), a copy of p.
 *   Worse: x reused as t0/a (167), the whole tail repeated per first-part arm (385), a join
 *   argument local for the shared func_021642A4 call (108). Model tests show that extra
 *   callee-saved locals (xx, y0) move p from r4 to r5 even when the first part matches, so the
 *   swap comes from the long-lived local set, not from the first part.
 * note (2026-10-05, wD4 lane17): still DIFF, 28 bytes, register names only (p r5/a r4 vs original p r4/a r5). New tries: t0 and a merged into one local (no change); `r` loaded inside each arm (moves the ldr after the cmp as in the original, 26 bytes left, not applied here); if-else inverted on the 0x14 test (74 bytes, block order breaks). The remaining residue is the colour of p versus the first call result.
 *
 * 2026-10-05 (wD8 lane09): still DIFF 26 bytes. Tried: x reassigned as t0 (`x = func_0216D5F8(x)`) with a
 *   separate a: worse (88 bytes, x takes r4 and p r5, the parameter copy order changes). The a-web gets the
 *   lower register in every form so far.
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 */

/*
 * 2026-10-04 (wave D2 lane05): DIFF, 176 bytes, same size, all calls resolve, 28 bytes differ and every one is a register name: the original keeps p in r4 and the cursor value in r5, this build swaps them (p r5, a r4). Tried: local declaration order (3 orders), int vs u32 x, splitting the pre-branch value into a second local. Body logic is believed correct (cursor stepping with bounds test on a 4-halfword rect at p+0x10).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct R { u16 h0, h2, h4, h6; };
extern u32 func_0216D5F8(u32);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern u32 func_021642A4(u32);
extern int func_021641E8(u32);
extern int func_021641F8(u32);
extern void func_0216D410(void *, u32);
extern u32 func_020056EC(u32);
void func_021F3DD4(u8 *p, u32 x)
{
    u32 a;
    u32 t0;
    int xx;
    int yy;
    int y0;
    struct R *r;
    t0 = func_0216D5F8(x);
    xx = func_0216D83C(*(void **)(p + 0xc));
    y0 = func_0216D86C(*(void **)(p + 0xc));
    if (*(u16 *)(p + 0x14) != 0) {
        a = *(u16 *)(p + 0x16);
    } else {
        if (t0 == p[3] || p[3] == func_021642A4(t0)) {
            if (func_020056EC(2) == 0) {
                a = (u16)(t0 + 2);
            } else {
                a = func_021642A4((u16)(t0 + 2));
            }
        } else {
            a = func_021642A4(t0);
        }
    }
    xx = (s16)(xx + func_021641E8(a));
    yy = (s16)(y0 + func_021641F8(a));
    if (a <= 1) {
        r = *(struct R **)(p + 0x10);
        if (yy < r->h0 || yy > r->h2) {
            a = func_021642A4(a);
        }
    } else {
        r = *(struct R **)(p + 0x10);
        if (xx < r->h4 || xx > r->h6) {
            a = func_021642A4(a);
        }
    }
    func_0216D410(*(void **)(p + 0xc), (u16)(*(u16 *)(p + 0xa) + a));
    *(u16 *)(p + 0x14) = 1;
    *(u16 *)(p + 0x16) = a;
}
