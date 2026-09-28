/*
 * function: func_021BA690
 * address:  0x021BA690
 * packet:   pkt_ov114_021BA690
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF  (parked; register allocation)
 *
 * Substring search: if len1 < len2 return -1; scan hay for needle.  On a
 * first-char match, compare the remaining len2-1 chars; a full match returns
 * 0, else -1.
 *
 * BLOCKER (codegen, register allocation): the body and control flow are
 * right and the compiled function is exactly 132 bytes (matching the
 * original), but the compiler assigns ip to `needle[0]`'s comparison temp
 * and r6 to the pointer `p`, where the original uses ip for `p` (r6) and r8
 * for the match count.  The original also keeps needle[0] in r7 and does the
 * primer comparison inline; this front end hoists `add r8, r0, r4` (the
 * pointer) ahead of the primer compare.  Tried: pointer local vs repeated
 * `hay[i+j]` indexing, permuting the i/j/n/p declarations, testing
 * `needle[0] != hay[i]` reversed, an explicit char local, and for-loop vs
 * while-loop forms; the `p`/`ip` assignment is the only remaining mismatch
 * (23 bytes).  Left parked as a documented near miss.
 */

int func_021BA690(signed char *hay, int len1, signed char *needle, int len2)
{
    int i;
    int j;
    int n;
    signed char *p;

    if (len1 < len2) return -1;
    n = len1 - len2 + 1;
    for (i = 0; i < n; i++) {
        if (hay[i] != needle[0]) continue;
        p = hay + i;
        for (j = 1; j < len2; j++) {
            if (p[j] != needle[j]) break;
        }
        if (j == len2) return 0;
    }
    return -1;
}