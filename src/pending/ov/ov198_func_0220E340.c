/*
 * function: func_0220E340
 * address:  0x0220E340
 * packet:   pkt_ov198_0220E340
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-05 (wD9r lane102): still DIFF 9 bytes (arc r6 / arr r7), no code change. Logic rechecked block by block
 *   against the listing: no wrong helper, reload, field or operand order. New probes: passing 0 for arc in ACEC
 *   AND AF28 flips arc to r7 (either one alone, or the close call alone, does not), so arc outranks arr by two
 *   post-loop uses' worth. Tried (all 9 B unless noted): the ov209 021BD9B4 twin shape (struct with a[26]/b[6]/c[6],
 *   arr = p->a, pb = &p->b[0], pc = &p->c[0] before the loop: 192 B, pb/pc offsets spilled); one pointer
 *   q = p + 0x250C with q[0]/q[6] (56 B); `i = 0;` before the arr assignment; `void *const arc` and `int *const arr`
 *   C99 initialised; a u16 n = 6 loop bound; block-scoped int a/b temps for the AF28 arguments (ov097 twin shape);
 *   the ov097 double definition `arr = (int *)p; arr = p + 0x24A4` (dead store dropped, 9 B; a stand-in anyway).
 * 2026-10-05 (wD9r lane75): still DIFF 9 bytes (arc r6 / arr r7). No twin: ov097 021F6F88, ov209 021BD9B4 and
 *   ov021 021CC8DC run the same open/icon-loop/close sequence but at different pressure (spills, hoisted 0x6b/0x71).
 *   Tried (all 9 B, swap unchanged): p, arr and arc as u32 integers (ov097 shape); x as u16 with u16 callees; a
 *   second parameter holding arc or arr (numbering probe: no effect, so not a tie on vreg order); copies of arc
 *   (h = arc before or after the loop); the A6C8 call in each arm with one `arr[i] = r` after the join (the ov041
 *   idiom shape); x selection alone in a static inline (if/return and if-set forms); i or x reused as the 0x250C
 *   offset (`i = 0x250C; ... i += 0x18`); a u16 heap local and x/y locals for the post-loop calls. `off = 0x24A4`
 *   with `p + off + i*4` (three spellings) folds to the 180 B raw form. Probes: dropping only the final close call
 *   or the ACEC arc use does not move arc. The weight gap needs a real extra arr use in the loop; none found.
 * 2026-10-05 (wD9r lane36): still DIFF 9 bytes (arc r6 / arr r7 swap), no code change. Tried: `do { } while (++i < 6)`
 *   and `while (i < 6) { ...; i++; }` (9 B); a Ctx struct with `Rec recs[6]` at +4 and `int a[26]` at 0x24A4 used
 *   inline (180 B: mwcc never hoists p + 0x24A4 itself, only the 0x4C constant, so arr must be a named pointer);
 *   `arr = (int *)p; arr += 0x929;` (180 B); call and store in each if/else arm with x kept (9 B); a function-scope
 *   record pointer e in each of the 5 declaration slots, and a loop-scoped `for (u16 i = 0; ...)` (all 9 B).
 *   The ov041 021F3884 close (stores repeated in each arm raise a block value's rank) has no analogue here: no
 *   store follows the x if/else except arr[i], and that adds equal uses to arc and arr.
 * 2026-10-05 (wD9r lane29): still DIFF 9 bytes (arc r6 / arr r7). New probes: the colour follows a use-count
 *   priority. arc not used in the loop, or arr given one more use in the loop, or four more uses of arr before the
 *   loop, or all three post-loop arc uses removed: each gives arc r7 / arr r6 as in the image. One to three extra arr
 *   uses do not. (The wD7 probe that one removed post-loop line moves arc does not reproduce on this draft.) So the
 *   image source has arr weighted at least as high as arc. Tried with no change (9 B): the record pointer inline
 *   (`p + i * 0x4C + 8/+4`, a CSE temp), arr from a static inline accessor Arr(p), the store in a static inline
 *   Store(arr, i, v), x as a separate temp stored after the call, i declared first, `for (i = 0, arr = ...)` with
 *   arr[i]. Worse: post-loop stores as arr[26]/arr[32] (172 B, 39), arr assigned inside the loop (143), dead
 *   stores to arr[i] (stand-ins anyway). No real source found that adds an arr use without code.
 * 2026-10-05 (wD9r lane05): still DIFF 9 bytes (arc r6 / arr r7 swap). Tried: the open call in a static inline
 *   OpenArc(p, 7); the three post-loop lines in a static inline Finish(p, arc); arr as a u32 integer
 *   (`arr = (u32)p + 0x24A4`, and `arr = 0x24A4; arr = (u32)(p + arr)`, the reuse form that closed ov197 0220BA2C);
 *   the loop's x local reused for the BC78 result (all 9 B); i reused for it (51 B). Probe: an extra arr use after
 *   the loop does not move arc, so arc's colour is not set by arr's use count.
 * 2026-10-05 (wD9 lane06): still DIFF 9 bytes (same arc/arr r6/r7 swap). Tried: the loop body as a per-iteration
 *   static inline `arr[i] = LoadOne(p, arc, i)` (record pointer, x selection and the A6C8 call inside), and arr as a
 *   pointer to an `int[6]` array with C99 initialised declarations (arc first). Both 9 bytes, swap unchanged.
 * 2026-10-05 (wD8 lane05): still DIFF 9 bytes (arc r6 / arr r7, image arc r7 / arr r6). Tried: x declared in the loop
 *   block, the if/else arms swapped (`== 0` first, 32 B), raw `*(int *)(p + 0x24A4 + i * 4)` with a real Rec struct
 *   array for the records (180 B: LICM then hoists 0x4C into r7, not p + 0x24A4). Reading: arc gets r7 when its
 *   interference degree drops (see wD7 probe), so the image likely has one fewer value live across the post-loop calls.
 * note 2026-10-05 (wD5 lane18): tried arr only at the use site (`((int *)(p+0x24A4))[i]`, 180 B, 143 differ), arr assigned inside the loop, and `for (i = 0, arr = ...)` with `*arr++` (176 B, 75 differ). The r6/r7 swap of arc and arr stays only in the 9-byte form.
 * 2026-10-05 (wD4 lane16): also tried arr = (int *)p + 0x929, int loop counter (much worse), arc/arr/x declaration orders, and a temp for the call result before arr[i]: all 9 bytes, r6/r7 swap unchanged.
 * 2026-10-05 (wD6 lane07): still 9 bytes (arc/arr r6/r7 swap). Tried: the 0204A6C8 call and arr[i] store written in
 *   each if/else arm (rule 2 of the register-order idiom), a real Rec struct array for the p + i*0x4C records (closed
 *   0220D884), and a Ctx struct with int arr[6] at 0x24A4 (180 bytes, worse). No callee reads a missing argument.
 * 2026-10-05 (wD7 lane13): still 9 bytes (arc r6 / arr r7, the original has arc r7 / arr r6). Probes: with the
 *   final func_02049238(arc) removed, or either post-loop line removed, arc goes to r7 as in the original, so
 *   arc's later uses push it to the lower register; the BC78 hold (j3) does not matter. No real source moved it:
 *   the x selection and the A6C8 call in a static inline, a Heap(p) inline accessor, the loop in a static inline
 *   (p, arc) and (p, arc, arr) (arr param 180 B), the ACEC/AF28 lines in a static inline, arr in an inner block,
 *   x as a ternary or nested in the call, temps for the BC78/BCEC/BC3C results, an off = 0x250C local (+0x18 or
 *   off += 0x18), a Ctx struct with a[26]/b[6]/c[6] at 0x24A4/0x250C/0x2524 (the arrays that siblings 0220E2F8
 *   and 0220E684 use) with arr = p->a, arc as u32, arr as u32 *, int *const / register arr, one u32 local reused
 *   for arr and the BC78 result, arr assigned before the open call (35 B). Raw `p + i * 4 + 0x24A4` (sibling form)
 *   gives 180 B with 0x4C hoisted into r7 instead.
 * symbols:
 *   func_0220E340  0x0220E340  thumb  ov198
 *   func_020490F4  0x020490F4  arm
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 */
/*
 * 2026-10-04 (wave D2 lane03): DIFF, unchanged (9 bytes, pure r6/r7 swap of arc and arr). Also tried:
 * arr as a u8 * base with `*(int *)(arr + i*4)`, and `register void *arc`: still 9 bytes.
 * In the original the BC78 result is held in r6 (arr's register) across the BCEC call, same as mine in r7.
 */
/*
 * 2026-10-04 (wave D1 lane07): DIFF, same size (176), logic matches. Residue: r6/r7 swapped
 * everywhere: the original has arc in r7 and the p+0x24A4 array base in r6, mine the reverse.
 * Tried: declaration order arc/arr, arr computed before the arc call (hoists everything, worse),
 * no arr local with raw *(int *)(p + 0x24A4 + i * 4) (worse).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);

void func_0220E340(u8 *p)
{
    int *arr;
    void *arc;
    u16 i;
    u32 x;

    arc = func_020490F4(7, (*(u16 *)(*(u8 **)p + 0x10) & 0x7FFF) | 0x8000);
    arr = (int *)(p + 0x24A4);
    for (i = 0; i < 6; i++) {
        u8 *e = p + i * 0x4C;
        if (*(u16 *)(e + 8) != 0) {
            x = func_0201BA68(func_020185F4(*(void **)(e + 4)));
        } else {
            x = func_0201BABC(0, 0, 0, 0);
        }
        arr[i] = func_0204A6C8(arc, x, 0, 1, *(u16 *)(*(u8 **)p + 0x10));
    }
    *(int *)(p + 0x250C) = func_0204ACEC(arc, func_0201BC3C(), 1, 0, *(u16 *)(*(u8 **)p + 0x10));
    *(s32 *)(p + 0x2524) = func_0204AF28(arc, func_0201BC78(), func_0201BCEC(), *(u16 *)(*(u8 **)p + 0x10));
    func_02049238(arc);
}
