/*
 * function: func_021BF0B0
 * address:  0x021BF0B0
 * packet:   pkt_ov172_021BF0B0
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * wave7 (lane02): re-measured live: 172 B, 10 concrete bytes DIFF, not MATCH.  The residue is a
 *        single cx<->i register swap (image cx=r6/i=r4; ours cx=r4/i=r6) with dx=r5 and all
 *        instruction shapes identical.  gem-dec.o .comment is 4.0.0.1024 = dsi/1.1p1, so the pin
 *        is right and the object is the ROM, but all nine dsi front ends at -O4,p, every flag
 *        set, and ~120 body spellings (decl order/scope/init, for/while/do, unsigned, param
 *        copies, guards, operand order) compile to `movs r4, r3`; the image's `movs r6, r3`
 *        cannot be produced from this tree.  -O4/-O3/-O2 change size (168 B) so the pin -O4,p
 *        is correct.  Blocker: front-end register-allocation order (parameter coloured before
 *        its locals); no source lever found.  See docs/notes/lane_t9_ov172_sdk_rows.md.
 *
 * sdk:      get_matrix_sub (jpegdec.o)
 *
 * Lane U18 (2026-09-30): `int dx;` before `int i;` is a live lever, 14 -> 10 concrete
 * bytes: dx lands in r5 and i in r6 as the image wants (`mov r5, #0` / `mov r4, #0`).
 * Residue is a cx/i 2-cycle: image `movs r6, r3` | ours `movs r4, r3` (and +0x0044
 * `lsleq r0, r0, r6` | `r4`, +0x0050 `sub r6, r6, #1` | `sub r4`, +0x0058, +0x005C
 * `mov r4, #0` | `mov r6, #0`, +0x008C `add r4, r4, #1` | `add r6`, +0x0090
 * `cmp r4, r6` | `cmp r6, r4`). The allocator colours the parameter cx first (r4, then
 * the locals r5/r6); the image colours the locals first and the parameter last
 * (i r4, dx r5, cx r6), which matches the DWARF (dx r5, i r4). Invariant over: both
 * declaration orders, block scope for i, `for (int i...)`, an early-return guard,
 * unsigned cx / i / dx, one-line declarations, `i = i;` / `dx = dx;` / `cx = cx;` /
 * `ax = ax;` self-assignments and six renames (names are inert). Next lever: permuter.
 *
 * Lane U38 (2026-09-30): ten further shapes measured, none below the current 10
 * (`int i; int dx;` 14, `int i, dx;` 14, `int dx, i;` 10, while-loop for the
 * second loop 10, `i = 0;` hoisted in front of the `if` 10, `dx = 0;` hoisted
 * in front of the `if` 32, `int i = 0;` + `for (;` 69, `unsigned int i;` first
 * 80, `unsigned int cx` 80, all-unsigned 80).  The residue is exactly the
 * two-cycle cx<->i: image colours the locals first (i r4, dx r5) and the
 * modified parameter last (cx r6); every spelling that keeps cx as a live
 * parameter gives cx r4 / i r6.  First divergence +0004 image `movs r6, r3`
 *  | ours `movs r4, r3`.
 *
 * Lane wave8 (2026-09-30): re-measured live at the pin: 172 B, 10 concrete bytes, all
 *        five sites are the one cx<->i 2-cycle.  Confirmed from the vendor object (sdkobj +
 *        its DWARF): image colours locals first (i r4, dx r5) and the parameter last
 *        (cx r6) -- reverse of our first-definition order.  New levers measured, all still
 *        10: self-assignments `cx = cx;` / `dx = dx;` / `i = i;` at their live-range
 *        boundaries (the `a-no-code-self-assignment-reorders-the-register-colouring`
 *        lever) are inert here; `int i = 0; int dx = 0;` / `i = 0; dx = 0;` before the
 *        guard emit the zeroes early (83 B, not sunk); `cx = cx - 1` / `i = i + 1` spelled
 *        out are inert; declaring `func_021BF610` in the same TU (matching the vendor's
 *        object context) is inert.  Blocker: mwcc 1.1p1 colours the entry-tested parameter
 *        before the later locals; no source lever among ~220 measured spellings moves it.
 *
 * Lane wave8 (2) 2026-10-01: extracted the exact vendor object (Release libssp.TWL.HYB.a
 *        jpegdec.o, .comment 4.0.0.1024) and confirmed get_matrix_sub is byte-identical to the
 *        image; its DWARF homes s r9, p r8, ax r7, cx r6, dx r5, i r4 (decl_line 1819 params,
 *        1821 locals).  The allocator colours the whole {cx,dx,i} group with the entry-tested
 *        parameter first (cx r4) then locals ascending (dx r5, i r6); the vendor colours the
 *        group in first-definition order to *descending* registers (cx r6, dx r5, i r4).
 *        Tested live at the pin, all still 10 B: `int i, dx;` (14), param-copy `int cx; cx=n;`
 *        with decl idcx/IdxCx/cxdi/cxid (10-14), no-mutation bound `for(i=0;i<cx-1;i++)` (10),
 *        `n=cx-1` (11), while/do i=0 before/after cx-- (10), `cx>i` (10).  Byte-typed counter
 *        `unsigned char/signed char/short i` overshoots (38-56 B).  Blocker unchanged and
 *        matches docs/idioms/a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md
 *        and vendor-front-end-parameter-register-set-cannot-be-forced.md: the 1.1p1 front end
 *        homes the entry-tested parameter at r4; no source spelling rotates the group.
 *
 * symbols:
 *   func_021BF610  0x021BF610  arm  ov172
 *   g_021C88F0     0x021C88F0  data
 */

extern unsigned int g_021C88F0[];
extern int func_021BF610(unsigned char *b, int *p);

int func_021BF0B0(unsigned char *s, int *p, int ax, int cx)
{
    int dx;
    int i;

    if (cx != 0) {
        dx = 0;
        if ((unsigned int)(*p + 1) >= g_021C88F0[2])
            return dx;
        if (func_021BF610(s, p) == 0) {
            dx = (1 << cx) - 1;
        } else {
            ax = (ax << 1) | 1;
        }
        cx--;
        for (i = 0; i < cx; i++) {
            if ((unsigned int)(*p + 1) >= g_021C88F0[2])
                return 0;
            ax = (ax << 1) | func_021BF610(s, p);
        }
        ax -= dx;
    }
    return ax;
}
