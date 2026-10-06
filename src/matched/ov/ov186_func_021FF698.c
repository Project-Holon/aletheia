/*
 * function: func_021FF698
 * address:  0x021FF698
 * packet:   pkt_ov186_021FF698
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Earlier blocker (closed): 5 bytes, a pure r4/r5 swap.  The original keeps the out pointer
 * in r4 and the field value in r5; every spelling tried (named pointer copy,
 * reversed declarations, int index, inline re-read) makes this compiler put
 * the field value in r4 and the pointer in r5, because the loaded value is
 *   the first live temporary while the pointer (arg r2) is spilled to the
 *   highest callee-saved register.  `cmp`-style naming does not move it.
 *   Re-verified (DIFF fixer): declaration order v-then-o, assignment o-then-v,
 *   and dropping the `o` alias to store through `out` directly all still swap
 *   r4/r5 the same way.
 *
 * 2026-10-05: tried a local k=0x5c4 reused as the call argument, pointer-typed value, u32 types, struct field access, early return for v==0, static inline getter, out alias inside the if. All still give out in r5 and value in r4 (original: out r4, value r5). Residue unchanged: 5 bytes, pure r4/r5 swap.
 *
 * 2026-10-05 (D9-14): closed. The swap was a wrong callee arity: func_021D74D8
 *   (matched in ov125) takes two arguments; the 0x5c4 in r2 at the call is only the
 *   leftover offset register. Two-argument call, no alias local: EXACT.
 *
 * symbols:
 *   func_021D74D8  0x021D74D8  thumb  ov125
 */

extern int func_021D74D8(void *unused, char **out);

int func_021FF698(char *p, int a1, int *out)
{
    int v = *(int *)(p + 0x5c4);

    if (v != 0)
        *out = func_021D74D8(p, (char **)a1);
    return v;
}
