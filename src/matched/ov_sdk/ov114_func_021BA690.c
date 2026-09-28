/*
 * function: func_021BA690
 * address:  0x021BA690
 * packet:   pkt_ov114_021BA690
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Substring search: if len1 < len2 return -1; scan hay for needle.  On a
 * first-char match, compare the remaining len2-1 chars; a full match returns
 * 0, else -1.
 *
 * Closed 2026-09-28: the residue was two register-allocation/scheduling
 * effects.  Inlining the loop bound as `(len1 - len2) + 1` (the now-dead
 * `n = ...` store stays, it is what reserves r8 for the bound) and spelling
 * the pointer as `p = hay; p = p + i;` instead of `p = hay + i;` makes this
 * front end put the bound in r8 and the pointer in r6 and compute the pointer
 * after the primer compare instead of hoisting `add r8, r0, r4` above it.
 * Found with permuter.py (`split-assign(p); expand(n)`); the two levers are
 * the declaration/allocation-order family of
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 */

int func_021BA690(signed char *hay, int len1, signed char *needle, int len2)
{
    int i;
    int j;
    int n;
    signed char *p;

    if (len1 < len2) return -1;
    n = len1 - len2 + 1;
    for (i = 0; i < (len1 - len2 + 1); i++) {
        if (hay[i] != needle[0]) continue;
        p = hay;
        p = p + i;
        for (j = 1; j < len2; j++) {
            if (p[j] != needle[j]) break;
        }
        if (j == len2) return 0;
    }
    return -1;
}
