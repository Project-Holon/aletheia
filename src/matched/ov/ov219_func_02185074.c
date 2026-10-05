/*
 * function: func_02185074
 * address: 0x02185074
 * packet: pkt_ov219_02185074
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (user decision): the two spellings of one table read (accessor for one argument, direct index for the other) are accepted as a real source quirk.
 * 2026-10-05 (wD9r lane130): still DIFF 17 bytes, source unchanged. New tries, all compiled: (1) a walking
 *   pointer `e = d; for (...; i++, e++) f(.., *e, *e, h)`: 43 (needs a register the image does not have; the image
 *   rematerialises the pool word and scales i every iteration, so there is no walking pointer); (2) a copy
 *   counter `j = i; f(.., d[i], d[j], h)`: 17 (copy propagation runs before the early CSE); (3) `d[i]` and
 *   `i[d]`: 17; (4) a volatile read for the fifth argument: 17 (no barrier for the CSE); (5) an assignment in
 *   the fifth argument `h = (u16)*p`: 17; (6) sized table with a sizeof bound: 46 (loop shape lost);
 *   (7) `((u32 *)d)[i]` for one argument: 61 (two loads survive). Diagnostic: with one table read and a
 *   literal fourth argument the h load comes first (10 bytes, schedule only), which confirms that the two
 *   reads are merged by the early CSE in every same-tree spelling. No real source form found.
 * 2026-10-05 (wD9r lane122): still DIFF 17 bytes, source unchanged. Data check: d_02185F7C is one u32
 *   array of 0x82 message ids (0x01..0xE3, two out of order), followed by the overlay .sinit; no pair table, no
 *   second symbol (one pool word), so both arguments really are one element. New tries: (1) pointer-typed callee
 *   parameters (void * for the index or the tag, with the table as u32 or void *const): the early CSE ignores
 *   the conversion, 17; (2) the table as a union of two same-typed members (msg/tag, also nested struct and
 *   one-element array members), one member per argument: 17 (same tree); (3) a union {u32 msg; unsigned long
 *   tag;} (or int/long), one member per argument: 4 bytes (only the lsls r3,r4,#2 / lsls r0,r0,#16 pair is
 *   swapped); a union {u32; int;} gives 61 (two loads). Finding: the early CSE keys on the element type and
 *   the address tree; any source that splits them is two spellings of one read (the D8 byte-offset form is
 *   EXACT, the u32/unsigned long view is 4 bytes). Not filed under the stand-in rule.
 * 2026-10-05 (wD9r lane113): still DIFF 17 bytes, source unchanged. New tries, all compiled: (1) loop body as a
 *   static inline taking the index, `AddOne(p, t, i)` and `AddOne(p, t, tbl, i)` reading tbl[i] twice inside (17);
 *   (2) the whole loop as a static inline `AddList(p, t, ids, n)` called with (d_02185F7C, 0x82): ternary bound 17,
 *   plain int or unsigned bound 46; (3) inline `Add(l, t, i, h)` / `Add(h, l, t, i)` / `Add(l, t, tbl, i, h)` with
 *   the table read inside the helper after the h parameter (u16 and u32 h): 17 (inline parameters are propagated, so
 *   the helper is transparent to the early CSE); (4) inline `Add(p, t, const u32 *e)` called with `d + i` and
 *   `&d[i]`, reading *e twice: 17; (5) one-word struct element copy `E e = tbl[i]; f(.., e.id, e.id, ..)`: 21;
 *   (6) loop shapes: goto loop with bottom test 46, while(1)/break 30, do-while 46, call in the for increment
 *   as a comma expression 17, `(void)` call and `if (1)` wrapper 17; (7) function-local static table
 *   (const and non-const): 17. Diagnostic only: a struct-cast read for one argument and d[i] for the other gives
 *   4 bytes (another two-spellings stand-in, not filed).
 * 2026-10-05 (wD9r lane66): still DIFF 17 bytes, source unchanged. Tried: (1) the table as a file
 *   static `static const u32 d_02185F7C[130]` defined in this unit: same CSE temp (and the data word
 *   has no witness); (2) the full shape of the matched twin ov219 021850EC (unsigned i, `(unsigned)bank`
 *   argument, prototype (Slot *, unsigned, unsigned, unsigned, u16)): the twin itself has the CSE temp
 *   form (ids load first), so the copy also gives it, plus a plain loop; (3) this function as the twin's
 *   body in a static inline Build(p, a, b, c, const u32 *ids, int count) called with (d_02185F7C, 0x82):
 *   46 bytes, CSE temp still first and the loop loses its branch to the bottom test.
 * 2026-10-05 (wD8 lane10): EXACT found but parked as DIFF under the stand-in rule. Writing the two table
 *   arguments in two different forms, `func_0201F878(..., t, d_02185F7C[i], tb(i), (u16)*(u32 *)p)` (or tb(i)
 *   third and d_02185F7C[i] fourth), gives EXACT 120 bytes: the early CSE no longer merges the two reads, so the
 *   stack argument is computed first and the late CSE shares the load. `d[i]` with `*(d + i)` does not (same
 *   tree), and tb as `return d[i]` does not. The two-form trick only exists to defeat CSE, so the integrator or
 *   the user must decide if it is acceptable. Source below is unchanged (17 bytes).
 * 2026-10-05 (wD7 lane14): still DIFF 17 bytes. Reading: the image computes the table address in r2/r3 because h (r0) and t (r1) are
 *   already live, so the table chain comes after the h load in the IR; ours computes the CSE'd table value first (temps r0/r1), so
 *   the scheduler cannot interleave. Tried: non-const extern table (same), u16 h local before the call (same, propagated),
 *   f(q, t, v, v = tb(i), h) (same), static inline Add(q, t, i, u16 h / int h) (same). The arm9 callee func_0201F878 reads only
 *   four arguments (the fifth is a dead stack argument, kept as in the matched sibling 02184EC0).
 * 2026-10-05 (wD6 lane16): still DIFF 17 bytes. Tried: static inline wrappers W(a, t, v, h) and W(h, a, t, v) calling
 *   f(a, t, v, v, h); Add(p, t, id) reading p inside; `v = d[i]` as the third argument with v as the fourth; a block
 *   with u16 h then u32 v locals. All keep the table load (CSE temp) before the stack argument.
 * 2026-10-05 (wD4 lane19): still DIFF 17 bytes, no new hypothesis beyond the 2026-10-04 notes closed it.
 * note 2026-10-04: DIFF, 17 bytes, loop body only. Original loads the u16 stack argument ((u16)*p) first,
 *   then the table pool address into r2 and indexes in r2; here the table base goes to r0 and the table
 *   load comes before the *p load. Everything else matches (u32 param c with (u16) casts in the call, loop
 *   as (i < 0x82) ? 1 : 0). Tried: locals k/w in both orders, static inline table reader, byte-offset read.
 *   2026-10-04 (D2): also tried plain d_02185F7C[i] twice, k local, callee last param u16 with u32 arg, local
 *   table pointer (59 bytes worse: hoists the pool load). Still 17 bytes: u16 stack arg must load before the table pool word.
 * 2026-10-05 (wD5 lane20): no new hypothesis closed it; the 17 byte residue is unchanged.
 * 2026-10-05 (wD9 lane11): still DIFF 17 bytes. Tried: callee prototype with mixed int/u32 index and tag
 *   parameters (int,u32 / u32,int / int,int) so the two table arguments carry different conversions; the early CSE
 *   still merges them (17 bytes, unchanged). Matched sibling 02184EC0 (same overlay) passes entries[i].bank /
 *   entries[i].id to the same callee, so a struct-table reading does not apply here (one load feeds both).
 * 2026-10-05 (wD9r lane03): still DIFF 17 bytes. Tried: the fifth argument through a static inline getter
 *   `u16 Hid(u8 *p)` (with plain d[i] twice, and with tb(i) twice): unchanged; `f(q, t, v = d[i], v, h)`
 *   (assignment in the third argument; the fourth-argument form was tried before): unchanged. The early
 *   CSE still places the table read before the stack argument.
 * 2026-10-05 (wD9r lane24): still DIFF 17 bytes. Tried an unprototyped callee `extern void func_0201F878();`
 *   (default argument promotions): unchanged. Reading kept: the image order (h load, table load, C050 load)
 *   is right-to-left argument evaluation, so in the original the two table reads were not one CSE candidate
 *   at the early stage; only the two-form D8 source reproduces that so far.
 * 2026-10-05 (wD9r lane40): still DIFF 17 bytes, source unchanged. Tried: a real struct for p (heap at 0,
 *   msg at 0xC018, list at 0xC050, as the matched sibling 02184EC0) with implicit u16 conversion of w->heap and
 *   plain d[i] twice: unchanged; an element pointer local `e = &d[i]; f(.., *e, *e, h)`: unchanged. Reading kept:
 *   the image has no statement-level CSE temp (table read after the h load, before the C050 load, i.e. in
 *   argument position); every single-tree spelling gets the temp.
 * 2026-10-05 (wD9r lane101): still DIFF 17 bytes, source unchanged. Rechecked every block against the
 *   listing: prologue, the three setup calls, the 0xC018/0xC050 offsets and the tail are byte-identical;
 *   the loop body has the same operands (q at p+0xC050, t, d[i] twice, (u16)p[0]), so no logic error.
 *   New tries, all with plain d[i] twice: sized extern `d[0x82]` (17); table as a global struct with
 *   one `ids[0x82]` member (17); `d[i], d[i++]` in the arguments (79); a bound local `n = 0x82` used in all
 *   three places, and a file-scope `const int` bound (46: the first test folds, the loop loses its branch
 *   to the bottom test); `i = 0` hoisted above the calls with a plain for (46 to 69); variadic callee
 *   prototypes `(void *, void *, u32, u32, ...)`, `(void *, void *, ...)`, `(void *, ...)` (17); a static
 *   inline 5-parameter pass-through `Add(l, m, s, v, h)` called with d[i] twice (17 with u16 h, 59 with
 *   u32 h). Diagnostic only (not filed): the plain `i < 0x82` loop at -O2,p is also 17 bytes, so the early
 *   CSE of the two table reads is present at -O2 too. Reading: the image has no early CSE temp and no
 *   loop rotation; both are global-optimizer effects, so the original may contain something that
 *   restricted that optimizer for this function. No real source form found.
 * symbols:
 *   d_02185F7C 0x02185F7C data a4
 *   func_02184968 0x02184968 thumb ov219
 *   func_02045B38 0x02045B38 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02184FC8 0x02184FC8 thumb ov219
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_02185F7C[];
static inline u32 tb(int i) { return *(const u32 *)((const u8 *)d_02185F7C + i * 4); }
extern u32 func_02184968(const u8 *, int);
extern void *func_02045B38(u32, u32, u16, u16);
extern void *func_0201F81C(u32, u32);
extern void func_0201F878(void *, void *, u32, u32, u16);
extern void func_02045C04(void *);
extern void func_02184FC8(u8 *, u32, u32);

static inline u32 GetMsg(u32 idx) { return d_02185F7C[idx]; }
void func_02185074(u8 *p, const u8 *a, u32 b, u32 c)
{
    void *t;
    int i;
    *(u32 *)(p + 0xC018) = func_02184968(a, 1);
    t = func_02045B38(0, 2, (u16)c, (u16)*(u32 *)p);
    *(void **)(p + 0xC050) = func_0201F81C(0x82, *(u32 *)p);
    for (i = 0; (i < 0x82) ? 1 : 0; i++) {
        func_0201F878(*(void **)(p + 0xC050), t, GetMsg(i), d_02185F7C[i], (u16)*(u32 *)p);
    }
    func_02045C04(t);
    func_02184FC8(p, b, 0x82);
}
