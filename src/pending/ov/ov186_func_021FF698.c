/*
 * function: func_021FF698
 * address:  0x021FF698
 * packet:   pkt_021FF698
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * BLOCKER: 5 bytes, a pure r4/r5 swap.  The original keeps the out pointer
 * in r4 and the field value in r5; every spelling tried (named pointer copy,
 * reversed declarations, int index, inline re-read) makes this compiler put
 * the field value in r4 and the pointer in r5, because the loaded value is
 *   the first live temporary while the pointer (arg r2) is spilled to the
 *   highest callee-saved register.  `cmp`-style naming does not move it.
 *   Re-verified (DIFF fixer): declaration order v-then-o, assignment o-then-v,
 *   and dropping the `o` alias to store through `out` directly all still swap
 *   r4/r5 the same way.
 *
 * symbols:
 *   func_021D74D8  0x021D74D8  thumb  ov125
 */

extern int func_021D74D8(void *, int, int);

int func_021FF698(char *p, int a1, int *out)
{
    int *o = out;
    int v = *(int *)(p + 0x5c4);

    if (v != 0)
        *o = func_021D74D8(p, a1, 0x5c4);
    return v;
}
