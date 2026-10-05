/*
 * function: func_021D8444
 * address: 0x021D8444
 * packet: pkt_ov125_021D8444
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * 2026-10-06 (pass 2 2026-10-06 P2L29): DIFF, 14 bytes unchanged (dst ip, image r5). Mechanism: the Data copy
 *   counter `mov #0x13` is scheduled pre-RA into the latency slot of the trailing ldrb, before the trailing strb,
 *   so it interferes with the Sav dst and dst cannot take r5. Any extra filler there moves the counter below the
 *   strb and gives the image colours: `ok = 1;` between the copies (ok then lives in r6, 175 B) and
 *   `*(Data *)... = *(Data *)g` (visible mov lr, r4, 178 B). The image needs a filler that leaves no code (a
 *   coalesced copy); not found. Also 14 B: t = t, *(t = ...), t reassigned to &d, one u8 *p for both copies,
 *   named Data *s / const Data *s / h-then-s copy chain, const Sav source, Sav *const t, 0x258 load through g,
 *   pragmas scheduling / dead_assignments / strength_reduction / unroll_loops off, a preceding function.
 *   Worse: inline Pub for the Data copy (20), user quad loop (344 B), optimize_for_size (276 B).
 * 2026-10-05 (final push G5L6): DIFF, 14 bytes (was 18). Found the lever: a named destination pointer under
 *   `#pragma opt_propagation off` (the pragma alone, and every other per-function pragma alone, stay 18 B):
 *   `Sav *t = &d_021D9E40.sav; *t = *(Sav *)(buf + 0x45);` keeps t as a user vreg older than the struct-copy
 *   source temp, so the source gets r3 as in the image (confirms the later-born-gets-lower-register idiom). With
 *   propagation on, t is folded and the order is the old one. Remaining residue: the destination colours ip
 *   instead of r5 (so 14 B: ldr/strb x3 registers, and mov r5,#0x13 stays above the trailing strb). Diagnostic:
 *   the Data copy's loop counter (mov r5,#0x13) is defined above the trailing strb in the compiled order, so the
 *   destination (live to that strb) cannot take r5; with the Data copy shortened to an unrolled 24 or 40 bytes (no
 *   counter) the destination does take r5. In the image the counter is defined after the strb. Tried on top of
 *   the named t, all 14 B or worse: t named with a named const Sav *u (same), u declared before t (18, colours
 *   revert), t declared at function top (14), t as char * g + 6 (320 B), t as u32 or register (14), t inside
 *   an inline Put (18, params fold), the Data copy through named Data pointers (ds loaded early, 20 B), a named dp
 *   after the first copy (dst lr, 20 B), d_021D9E46 as a separate extern object (14), the second copy as an inline
 *   Publish (18), opt_lifetimes / opt_common_subs / peephole / opt_loop_invariants off on top (14), t defined in the
 *   call block (47 B, r6 appears), the second copy as a user do-while over 16-byte quads (344 B, wrong code), `if
 *   (t != 0)` (image colours but cmp/beq, 24 B shifted). Matched-assembly search for the 2-byte unrolled copy
 *   (`ldrb r,[rA,#1]; ldrb r,[rA],#2; subs; strb [rB,#1]`): ov016, ov009, ov114, ov175 (021DD2A0, 021E06A8),
 *   arm9 0205A090/0205A0C0, all in SDK or unmatched code, no matched twin to read.
 * 2026-10-05 (wD9r laneS5): DIFF, 18 bytes unchanged (src r5 / dst r3). The tree held lane174's note and code only (no
 *   code edit left behind; verdict re-checked, 18 B). Model from the mwcc reference (src/backend/Coloring.c, read
 *   2026-10-05; PowerPC build, same allocator shape): nodes are simplified in ascending vreg index and pushed on a
 *   stack, so the HIGHEST-index low-degree node is coloured first and takes the lowest free register (r3 here,
 *   after the byte temps took r0 to r2); the next node gets r5 (r4 holds g). Degree cannot decide it: src and dst
 *   have only a handful of neighbours, far below the colour count, so both go in the first pass. The colour swap is
 *   therefore a vreg-index order: the image has idx(src) > idx(dst), ours has idx(dst) > idx(src), which matches
 *   lane108's finding that the struct-assignment expansion creates the source temp first. Only a destination vreg
 *   created before the expansion (loaded pointer, phi, loop-header def) gives the image order, and each of those
 *   adds code or hoists. New probe (18): one-field wrapper struct around Sav (`typedef struct { Sav0 s; } Sav`), a
 *   nested aggregate copy; the expansion is unchanged. No source form with an older, code-less destination found.
 * 2026-10-05 (wD9r lane174): DIFF, 18 bytes unchanged (src r5 / dst r3). Control flow re-derived from the
 *   listing: header (bl 02168040; cmp #3; bne) falls into the copy block, the 4, 5 and poll arms follow in
 *   source order, the back edge goes to the call, the 1 is hoisted into r5, the dead epilogue at +0x130 is
 *   the fall-off after for (;;). The draft already has this exact block layout. CF probes, all real compiles:
 *   r != 3 arms first with the copy as the final else (316 B, layout follows source); switch with case 3 first
 *   (332 B, compare chain); break out of the loop with the copy after it (316 B, copy laid out last); do { }
 *   while (1) (18, same); def block and copy block split by `if (r == 3) t = ...; else { others; continue; }`
 *   with t alone and with t and s (316 B, the def block is if-converted to ldreq and the copy goes last);
 *   `r == 3 && (t = &d.sav) != 0` and `r == 3 ? (t = ...) != 0 : 0` (extra cmp, 332/364 B);
 *   `(t = ..., 1)` in the && (folded, 18). Mechanism check: a redundant second `if (r == 3)` around the copy
 *   gives the image colours (dst r5, src r3) plus a cmp/bne: mwcc keeps the branch (no jump threading), so
 *   any surviving block boundary between the dst def and the copy flips the colours, but no natural source
 *   form leaves a boundary with no code. Other probes (18): inline Dst() returning &d.sav into a local,
 *   inline Put with an inner pointer local, `Sav *const` block local, struct-returning inline GetSav (also
 *   with a named temp), a one-iteration index loop (folded). The struct-copy expansion builds the source
 *   address first in every form (also with a Sav local or a second global as the other operand). All
 *   mwcc versions 1.1 to 1.6sp2 give the same 18 bytes, so this is not a compiler-version residue.
 * 2026-10-05 (wD9r lane165): DIFF, 18 bytes unchanged (src r5 / dst r3). Twin search again: only the
 *   ov114 SDK DWC_SVLProcess caller (021C5724, different token handling) and the ov125 siblings, which use
 *   raw u32 arrays for d_021D9E40 (no token type). New probes, all 18 unless stated: the matched
 *   prototype func_02167FA8(char *, void *) with a non-const d_021D8D30; `static Sav *const` file
 *   pointer (not folded: extra ldr, 214 B); `*(t = &d.sav) = tok` and `*t++ = tok` (LHS side effects do
 *   not change the order); one char *p reused as both copy destinations; `*(Sav *)&buf[0x45]` and
 *   `(&d.sav)[0] = ((Sav *)...)[0]`; __builtin__copy/__copy/__builtin_memcpy (calls, 201 B); the
 *   Data copy source as `(u8 *)t - 6` (t not propagated, but the copy takes a `mov r3, ip` temp, dst
 *   still r3, 225 B); a while ((r = f()) != 3) loop with the copy after it (221 B). Finding: copy
 *   propagation is block-local. `if (r == 3) t = &d.sav; else { others; continue; } *t = tok;` keeps t
 *   in a register from another block and the copy then colours src r3 as the image, but the copy block
 *   is laid out after the else part (ldreq lr; beq, 211 B). With the copy written next to the def
 *   (goto other / goto join forms) the blocks merge first and t is propagated again (18). So the image
 *   needs a destination value from an earlier block that is laid out directly before the copy; no
 *   source form found that gives that without extra code.
 * 2026-10-05 (wD9r lane142): DIFF, 18 bytes unchanged (src r5 / dst r3). New probes in the real function:
 *   `Sav *t = &d_021D9E40.sav; if (t != 0) *t = tok;` (and the same null test inside an inline Put) gives
 *   EXACTLY the image colours (ldr r5 dst, add r3 src) but adds cmp r5,#0 / beq: so the image needs the
 *   destination as a register value made in an earlier block. Splits that fold away do not keep it:
 *   `if (ok)` with `int ok = 1`, do { } while (0), an inline null test on the stack source, t with a
 *   second dead definition (r == 5 block or at entry), register t, a Work struct pointer for all
 *   accesses (dst becomes r4 + 6). Also 18: buf as u32[], buf as a DWCSvlResult-like struct with
 *   svltoken, file-static Data, the source pointer defined in the loop header (53 B, not hoisted), an
 *   unrelated byte struct copy in another block or after the Data copy (no flip in the real function).
 *   Hand index loops are not unrolled by 2 (50 B and more). switch (r) changes the layout (221 B).
 * 2026-10-05 (wD9r lane93): DIFF, 18 bytes unchanged (src r5 / dst r3). Twin search: no game twin.
 *   ov115 021D4B80/021D4BC4 call the same SVL pair but copy nothing; the other ARM byte-copy loops in
 *   src/matched (ov016 021C519C, ov114 021C6704, arm9 02059FA8 strcpy) are SDK or local inits.
 *   Probes (synthetic, same compiler): a plain struct assignment colours dst first (dst r3); the memcpy
 *   intrinsic (house string.h) and the strcpy-literal expansion colour src first (src r3, as the image),
 *   but memcpy inlines only for n <= 31 (301 is a call). A struct assignment also gets src r3 when a
 *   second BYTE copy follows it (`G2 = D.sav = tok`, two T25/T22 inits); a following ldm/stm copy does
 *   not. Tried in the draft: a for-loop byte copy and a while(n--) copy (209/214 B, mwcc does not form
 *   the 2-byte unrolled loop), the r != 3 paths first with `continue` (copy last in source, src r5),
 *   a different buffer for func_02167FA8 (src r5), func_021D8438 argument 0 or removed (src r5).
 * 2026-10-05 (wD9r lane25): DIFF, 18 bytes unchanged. Tried: the 301-byte destination as its own extern
 *   `extern Sav d_021D9E46;` (data symbol at d_021D9E40 + 6) while the 312-byte copy keeps Data d_021D9E40:
 *   same pool word, same colours (src r5, dst r3).
 * 2026-10-05 (wD9r lane09): DIFF, 18 bytes unchanged (src r5 / dst r3; image dst r5 / src r3). Tried: a block
 *   temporary `Sav t = src; d_021D9E40.sav = t;`, block-local pointer pairs `Sav *d = ...; Sav *s = ...; *d = *s;`
 *   in both assignment orders, the whole r == 3 store as a static inline Store(const u8 *buf) and as
 *   Store(const Sav *src) (the source arrives as an inline parameter). All 18 bytes, same colours.
 * 2026-10-05 (wD9r lane108): DIFF, 18 bytes unchanged (src r5 / dst r3). Mechanism found by synthetic
 *   compiles: mwcc colours the HIGHER-numbered pointer temp first (it gets r3). A struct assignment makes the
 *   source address temp before the destination temp, so dst wins r3 in every spelling (25 synthetic forms:
 *   member/array/inline/by-value/volatile/const/comma/u32 casts, all dst r3). The image order appears only
 *   when the destination is an older value: a loaded pointer (`*Gp = tok`), a pointer local with two
 *   definitions (phi), or a pointer local defined in the loop header (`t = &d_021D9E40.sav;` after the
 *   02168040 call, then `*t = tok` in the r == 3 block): that gives src r3 / dst r5 exactly, but loop
 *   invariant motion hoists the pool load out of the loop (pointer held in r5, the 1 moves to r6, 47 B).
 *   Also tried (all 18 or worse): memcpy for n = 32..512 (always a call, only n <= 31 inlines), dst via
 *   `(u32)&d + 6` and a char * local, a goto label between the def and the copy (propagated), a goto loop
 *   instead of for (same hoist), the copy after the loop via break (218 B), an inline GetToken(r, dst, res)
 *   wrapper (321 B), the copy chained into the Data copy by a comma. Following byte copies flip the colours
 *   (`G = tok; H1 = H2;`), word copies do not. Open: a source form whose destination temp is older than the
 *   source temp but is loaded in the r == 3 block.
 * 2026-10-05 (wD9r lane47): DIFF, 18 bytes unchanged. Tried: the `g + 0x138 = 1` store written before the
 *   two copies (222 bytes, the store stays above the copies, so the original stores it last), and `int r`
 *   declared first (18, same colours: src r5, dst r3).
 *
 * 2026-10-04 (wave D2 lane 14): DIFF, 23 bytes, structure right. Sav and Big are the two struct
 * copies (301 bytes by byte loop, 312 bytes by ldm/stm; Big must be a u32 array). Residue: in the
 * 301-byte copy the original puts the global destination in r5 and the stack source in r3; this
 * build swaps them (r3 destination, r5 source), which shifts the next block. The a/b stack order
 * is fixed by declaring b first. Tried: pointer locals for src/dst in both orders, typed extern
 * destination, struct-typed buf. The 312-byte copy source/destination go through d_021D9E40
 * directly (the original reloads the pool word into lr).
 *
 * 2026-10-05 (wD9r lane64): DIFF, 18 bytes unchanged (src r5 / dst r3). Tried: a by-value inline
 *   Put(Sav s) for the store, a by-value struct return GetSav(buf) as the source, a block pointer local
 *   `Sav *d = &d_021D9E40.sav; *d = ...`, __builtin_memcpy (real call, 201 bytes). Diagnostic: with the
 *   312-byte Data copy deleted the 301-byte loop keeps the same colours, so the swap is local to the
 *   first copy and not driven by the second loop's r5 counter.
 * 2026-10-05 (wD9r lane197): DIFF, 18 bytes unchanged (src r5 / dst r3). Copy-form probes, all 18 B:
 *   both sides as one-element array subscripts `((Sav *)(g + 6))[0] = ((Sav *)(buf + 0x45))[0]`; buf as a
 *   stack struct { int st; u8 host[65]; Sav tok; } whose address goes to func_02167FA8, copy `d.sav = buf.tok`;
 *   a block pointer to Data (`dd->sav = ...`); Sav spelled as u8[7][43], two members (150 + 151), u8 + u8[300],
 *   char[301] (the loop expansion and colours do not depend on the element layout); an inline Save(Data *g,
 *   const Res *res) holding both copies (res a struct with a token member, g = &d_021D9E40); an inline
 *   Save2(Data *g, const Sav *s) for the first copy only. Idioms read: struct-assignment-copy-is-ldm-stm-with-
 *   spilled-pointers, const-source-pointer-schedules-the-block-load-first (only reorders ldm vs address, no
 *   effect on this byte loop), a-twelve-byte-aggregate-copy-pins-the-destination-first (struct form already
 *   used), hoisted-stack-address-is-a-block-local-byte-pointer (hand byte copies are not the 2-byte unrolled
 *   struct expansion). Reading: the unrolled loop is mwcc's own struct-copy expansion, so the swap is the
 *   temp creation order (source temp first), not a source spelling of the copy itself.
 * symbols:
 *   func_02167FA8 0x02167FA8 arm ov009
 *   func_02168040 0x02168040 arm ov009
 *   func_02059E38 0x02059E38 arm
 *   func_021D7CAC 0x021D7CAC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021D8D30 0x021D8D30 data a4
 */

/*
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged 23 bytes. Re-read: the 301-byte copy uses r5 (the register that holds the constant 1 for func_021D8438(1)) for the destination d_021D9E46 and r3 for the stack source; the build swaps them, and the trailing byte schedules ldr lr first. No new form found beyond the earlier list; next idea: write the Big copy and the Sav copy through one struct type whose field order puts Sav first, or derive the 1 for func_021D8438 from a local.
 */
/*
 * 2026-10-05 (wave D5 lane09): DIFF, 23 bytes (21 with the g + 6 form). Tried: destination written as
 *   `*(Sav *)(g + 6)` (pool word folds to r4 + 6: no; but the trailing ldrb then schedules before the
 *   Big copy as in the original), memcpy through the house string.h (real call, no), the copy in a
 *   static inline cp(Sav *d, const Sav *s) helper (identical). Finding: the source pointer gets r5 in
 *   every form, whichever operand is computed first; the original gives r5 to the destination.
 */
/*
 * 2026-10-05 (wave D6 lane02): DIFF, 18 bytes (was 23). New form: d_021D9E40 is one struct Data
 *   (312 bytes: u32, u16, Sav at +6, 5 tail bytes) and the copies are "d_021D9E40.sav = ..." and
 *   "*(Data *)(ptr + 8) = d_021D9E40". The pool word 021D9E46 is now &d_021D9E40.sav (no extra
 *   symbol) and the trailing byte of the 301-byte copy now schedules before the Big copy, as in the
 *   original. Residue: only the r3/r5 swap (original dst r5, src r3) and the "mov r5,#0x13" that
 *   follows from it. Tried with no effect: Buf struct local with a Sav member at 0x45, the copy in
 *   an inline cp(src, dst) helper, pointer locals for dst/src in both declaration orders, the
 *   r == 3 path as "break" with the copies after the loop (worse). All callees checked: no hidden
 *   arguments (021D7CAC/021D7CC0/021D8438 are thunks that load their own r0).
 */
/*
 * 2026-10-05 (wave D7 lane15): DIFF, 18 bytes, unchanged. Residue: the 301-byte byte-copy loop has the
 *   destination (&d_021D9E40.sav) in r3 and the stack source in r5; the original has dst r5, src r3, then
 *   `mov r5,#0x13` after the trailing strb. Checked callees again: 02168040 and 02167FA8 take no hidden
 *   arguments, 021D8438 is a veneer to 0x02085A38. No value merges at a join in the r == 3 block. Tried:
 *   the r chain as a switch on the call result (332 bytes, worse), `int one = 1` for the 021D8438 argument
 *   (same 18), static inline accessors for the source (SavOf(buf)) and for the destination (DstOf()), both
 *   same 18. Open: what makes mwcc colour the struct-copy source before the destination.
 */
/*
 * 2026-10-05 (wave D8 lane08): DIFF, 18 bytes unchanged. Tried (all 18): `const Sav *` source cast; buf as a
 *  struct { u8 pre[0x45]; Sav sav; ... } local with `d_021D9E40.sav = buf.sav`; destination as
 *  `*(Sav *)((u8 *)&d_021D9E40 + 6)` (pool word unchanged); destination and source through Data-typed member access
 *  (`(&d_021D9E40)->sav = ((Data *)(buf + 0x3f))->sav`). The struct-copy expansion colours src r5 / dst r3 in every
 *  spelling; the image has dst r5 / src r3.
 */
/*
 * 2026-10-05 (wave D9 lane 13): DIFF, 18 bytes unchanged. Tried: the destination as a pointer local
 *   `Sav *dst = &d_021D9E40.sav` set at entry, and the source as `Sav *src = buf + 0x45` set at entry
 *   (both keep the value live across the loop: push {r3-r6}, worse). Instruction order of the copy is
 *   already the image's (dst pool load, then src add); only the colour of the two differs.
 */
/*
 * 2026-10-05 (wD9r lane78): DIFF, 18 bytes unchanged (src r5 / dst r3). Checked every callee's return type
 *   and prototype in src/matched: 02167FA8, 02168040, 02059E38 return int (as declared); 021D7CAC, 021D7CC0
 *   are void in all ov125 matched callers; 021D8438 is matched as void(u32). So the void-getter lever does
 *   not apply. Tried: func_021D8438(u32) (its real parameter type, 18); the whole function through one real
 *   global struct (Data at 0, f138, f250, f258 pointer, f268; `d_021D9E40.d.sav = ...`, no g char pointer,
 *   18, identical code). Reading: buf is a DWCSvlResult (int status, svlhost[65], svltoken[301], 0x174 B),
 *   so the 301-byte copy is the svl token.
 */
/*
 * 2026-10-05 (wD9r lane207): DIFF, 18 bytes unchanged (src r5 / dst r3). Listing store map: the only stores to
 *   d_021D9E40 are +0x250 (arms), the sav copy, the Data copy to *(d+0x258)+8 and +0x138 last; none sits before
 *   the sav copy, so no real earlier dst value exists. Probes: a dead store before the copy (`.sav.b[0] = 0`,
 *   `.tail[0] = 0`: not removed, 336 B, frame changes), `.w0 = .w0` (folded, 18), a named `const Sav *src` in
 *   the block (propagated, 18), `Sav *dst` plus `const Sav *src` locals (18), sav as `Sav sav[1]` with `*d.sav =`
 *   (18), a static inline cp(Sav *__restrict, const Sav *__restrict) (18), the Data-copy destination pointer
 *   `dp` loaded before the sav copy (328 B, 211 differ). Idioms read: a-dead-store-between-a-temp-and-its-use-
 *   blocks-copy-propagation (only blocks propagation of a temp; here it keeps the store, wrong frame),
 *   a-two-word-struct-copy-from-a-returned-record-recolours-the-destination-pointer (needs a value from a call),
 *   a-two-word-copy-between-different-bases-is-a-struct-assignment (struct form already used).
 */
/*
 * 2026-10-05 (wD9r lane212): DIFF, 18 bytes unchanged (src r5 / dst r3). Whole-function check against the
 *   listing: every instruction outside the copy block is byte-identical (same value use counts, same operands,
 *   same sp offsets: buf at sp+8, a at sp, b at sp+4, frame 0x17c), so no source operation is missing or extra
 *   and no local has a different type or size. The diff is only the two colours and the later mov r5,#0x13 /
 *   strb order that follows from them. New probe: 300-byte struct copy plus a separate trailing byte
 *   statement (`sav = *(Sav *)(buf+0x45); last = buf[0x45+300];`): the trailing byte is no longer the
 *   post-incremented pointer (ldrb [sp,#0x179], strb [lr,#0x132]), 20 B differ, colours still swapped.
 *   Idioms read: a-word-copy-loop-that-loads-the-destination-base-first-is-a-one-word-struct-assignment (a
 *   Thumb word loop; here the copy is already a struct assignment, no change), big-struct-assignment-is-an-
 *   ldm-stm-loop (byte loop = align-1 type, already used), an-eight-byte-pair-copy-loads-both-words-first
 *   (word pair, n/a), a-const-source-pointer-hoists-the-last-load... (const source tried by earlier lanes).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[301]; } Sav;
typedef struct { u32 w0; u16 h4; Sav sav; u8 tail[5]; } Data;
extern int func_02167FA8(const char *, void *);
extern int func_02168040(void);
extern int func_02059E38(int *, int *);
extern void func_021D7CAC(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
extern Data d_021D9E40;
extern const char d_021D8D30[];

#pragma opt_propagation off
int func_021D8444(void)
{
    char *g = (char *)&d_021D9E40;
    u8 buf[0x174];
    int b, a;
    int r;

    if (*(int *)(g + 0x138) == 1)
        return 1;
    if (func_02167FA8(d_021D8D30, buf) == 0) {
        *(int *)(g + 0x250) = 0xE;
        return 0;
    }
    for (;;) {
        r = func_02168040();
        if (r == 3) {
            Sav *t = &d_021D9E40.sav;
            *t = *(Sav *)(buf + 0x45);
            *(Data *)(*(char **)((char *)&d_021D9E40 + 0x258) + 8) = d_021D9E40;
            *(int *)(g + 0x138) = 1;
            return 1;
        }
        if (r == 4) {
            func_02059E38(&a, &b);
            *(int *)(g + 0x250) = 0xE;
            return 0;
        }
        if (r == 5) {
            *(int *)(g + 0x250) = 0xE;
            return 0;
        }
        func_021D7CAC();
        if (*(int *)(g + 0x268) == 1) {
            *(int *)(g + 0x250) = 0xD;
            func_021D7CC0();
            return 0;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
}
#pragma opt_propagation reset
