/*
 * function: func_02096DF0
 * address:  0x02096DF0
 * packet:   pkt_02096990
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:  none -- the function has no relocation at all
 *
 * The ordering sibling of func_02096D10: same length-prefixed string object
 * (byte +5 terminator flag, s16 key at +2, byte length at +4, payload from +5)
 * but it returns 1 when a sorts before b and 0 otherwise, so the payload loop
 * is a two-sided compare instead of a single inequality.  When the common
 * prefix is exactly a's payload, b's tail must hold terminators only, and a
 * non-terminator there means a is a proper prefix and sorts first (return 1);
 * the s16 keys break the tie when they differ.
 *
 * Levers, all measured:
 *   - `volatile u8 f04` again: the tail loop re-reads b's length every
 *     iteration (`ldrb r0, [r1, #4]` under the payload test) rather than
 *     hoisting it, so a plain field comes out four bytes short.
 *   - the tail is a do/while guarded by the second `&&`: `if (n == la && i <
 *     lb) { do {...} while (i < b->f04); }`.  The entry test compares against
 *     the cached lb (r4) while the back edge re-reads b->f04, which is what
 *     distinguishes this shape from `for (; i < lb; i++)` (whose back edge
 *     would use the cached value and lose the volatile read).
 *   - `if (a->f02 != b->f02) goto keycmp; ... keycmp: return a->f02 < b->f02;`
 *     -- the s16 tie-break sits out of line after the final `return 0`, as a
 *     single `if (...) return ...;` the front end if-converts it inline and
 *     the whole tail shifts.
 *   - `int lb, la;`: declaration order decides which of the two lengths gets
 *     r4 and which r5; the `la, lb` order swaps them and costs seven bytes.
 */

typedef unsigned char u8;
typedef signed short  s16;

typedef struct {
    u8  pad00[2];
    s16 f02;
    volatile u8 f04;
    u8  f05[];
} Str;

int func_02096DF0(Str *a, Str *b)
{
    int i, n;
    int lb, la;

    if (a->f05[0] == 0)
        return b->f05[0] != 0;
    if (b->f05[0] == 0)
        return 0;
    if (a->f02 != b->f02)
        goto keycmp;
    i = 0;
    la = a->f04;
    lb = b->f04;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->f05[i] < b->f05[i])
            return 1;
        if (b->f05[i] < a->f05[i])
            return 0;
    }
    if (n == la && i < lb) {
        do {
            if (b->f05[i] != 0)
                return 1;
            i++;
        } while (i < b->f04);
    }
    return 0;
keycmp:
    return a->f02 < b->f02;
}
