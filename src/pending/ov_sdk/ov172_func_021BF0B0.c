/*
 * function: func_021BF0B0
 * address:  0x021BF0B0
 * packet:   pkt_ov172_021BF0B0
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
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
 * | ours `movs r4, r3`.
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
