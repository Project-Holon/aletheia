/*
 * function: FullRulesPresent
 * address:  0x021A0440
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NTSLengthSB  0x0219F978  arm  ov009
 *
 * Walk a length-bounded string, two decode steps per turn: NTSLengthSB
 * reports how many bytes one unit occupies and a negative answer is a hard
 * failure (0).  Each successful step consumes that many bytes from the
 * pointer and the remaining count, in the order the image shows (the count
 * first on the first step, the pointer first on the second).  Leaving with
 * the count exhausted answers 0, leaving on a terminator answers 1.
 */

typedef signed char s8;

int FullRulesPresent(const char *p, int n)
{
    int k;

    while (n > 0 && *p != 0) {
        k = NTSLengthSB(p, n);
        if (k < 0)
            return 0;
        n -= k;
        p += k;
        k = NTSLengthSB(p, n);
        if (k < 0)
            return 0;
        p += k;
        n -= k;
    }
    if (n == 0)
        return 0;
    return *p == 0;
}
