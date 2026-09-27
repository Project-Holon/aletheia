/*
 * function: func_021FAD04
 * address:  0x021FAD04
 * packet:   pkt_021FAD04
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * BLOCKER: 2 bytes, r3 vs r1.  The original loads p[0] into r3 before the
 * test; this compiler always picks r1 for the dead comparison temporary in
 * every spelling tried (named local, inline ternary, pointer type, volatile).
 * The rest of the function is byte-correct.
 *
 * Re-verified (DIFF fixer): tried `if (p[0])`, a `p[0] != 0 ? ... : 0`
 * ternary, and the reversed `if (p[0] == 0) return 0;`; all still land the
 * dead load in r1 (`ldr r1,[r0]; cmp r1,#0`).
 *
 * symbols:
 *   func_021FB4CC  0x021FB4CC  thumb  ov186
 */

extern int func_021FB4CC(int);

int func_021FAD04(int *p)
{
    if (p[0] != 0)
        return func_021FB4CC(p[2]);
    return 0;
}
